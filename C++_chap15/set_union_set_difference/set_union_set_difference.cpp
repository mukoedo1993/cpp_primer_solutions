#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using line_no = std::vector<std::string>::size_type;
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
class TextQuery {
public:

	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};
TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text))//for each line in the file
	{
		file->push_back(text);//remember this line of text
		unsigned n = file->size() - 1;//the current line number
		std::istringstream line(text);//separate the line into words
		std::string word;
		while (line >> word)//for each word in that line
		{
			//if word isn't already in wm, subscripting adds a new entry
			auto& lines = wm[word];//lines is a shared_ptr
			if (!lines)
				lines.reset(new std::set<line_no>);//allocate a new set
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
        std::set<line_no>::iterator begin()const{return lines->begin();}
        std::set<line_no>::iterator cbegin()const{return lines->cbegin();}
          std::set<line_no>::iterator end()const{return lines->end();}
        std::set<line_no>::iterator cend()const{return lines->cend();}

        std::shared_ptr<std::vector<std::string>> get_file(){return file;}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
	std::shared_ptr<std::vector<std::string>>file;//input file
};

QueryResult
TextQuery::query(const std::string& sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm.
	auto loc = wm.find(sought);

	if (loc == wm.end())//Iterator to an element with key equivalent to key. 
    //If no such element is found, past-the-end (see end()) iterator is returned.
		return QueryResult(sought, nodata, file);//not found
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin()+num)<<std::endl;
	return os;
}


class Query_base{
    friend class Query;
    protected: 
    using line_no=TextQuery::line_no;//use in the eval functions
    virtual ~Query_base()=default;
    private:
    virtual QueryResult eval(const TextQuery&)const=0;
    virtual std::string rep()const=0;
};
class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t)const
    {return q->eval(t);}
    std::string rep()const {return q->rep();}
    private:
    Query(Query_base *query):q(query){}

    Query_base *q;
};

std::ostream& 
operator<<(std::ostream &os,const Query &query)
{
    return os<<query.rep();
}

class WordQuery: public Query_base{
    friend class Query;//Query uses the WordQuery constructor
    WordQuery(const std::string&s):query_word(s){}
    QueryResult eval(const TextQuery &t)const
    {return t.query(query_word);}
    std::string rep()const override{return query_word;}
    std::string query_word;//word for which to search

};
inline
Query::Query(const std::string&s):q(new WordQuery(s)){}

class NotQuery: public Query_base{
        friend Query operator~(const Query &);//here we are not the user for Query, so ok.
        NotQuery(const Query&q):query(q){}
        std::string rep()const{return "~("+query.rep()+")";}
        QueryResult eval(const TextQuery&)const;
        Query query;
};

inline Query operator~(const Query &operand)
{
    return (new NotQuery(operand));
}
class BinaryQuery: public Query_base{
    protected:
    BinaryQuery(const Query &l,const Query &r,std::string s):
    lhs(l),rhs(r),opSym(s){}
    std::string rep()const{return "("+lhs.rep()+" "
    +opSym+" "
      +rhs.rep()+")"; }
      Query lhs,rhs;//right_ and left_hand operands
      std::string opSym;//name of the operator
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query&left,const Query&right):
    BinaryQuery(left, right,"&"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query&lhs,const Query&rhs)
{
    return (new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):
    BinaryQuery(left,right,"|"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{ 
    return new OrQuery(lhs,rhs);
}

//OrQuery::eval
//A OrQuery represents the union of the results for its two operands, which
//we obtain by calling eval on each of its operands. Because these operands
//are Query objects, calling eval is to call to Query::eval, which in turn makes a 
//virtual call to eval on the underlying Query_base object. Each of these calls yields
//a QueryResult representing the line numbers in which its operand apperas. We'll combine
//this number in a new set:

//returns the union of its operands' result sets
QueryResult
OrQuery::eval(const TextQuery& text)const
{

   //virtual calls through the Query operands to get result sets for the operands
   auto left=lhs.eval(text),right=rhs.eval(text);
   //set to hold the intersection of lfet and right
   auto ret_lines=std::make_shared<std::set<line_no>>();
   //write the intersection of two two ranges to a destination iterator
   set_union(left.begin(),left.end(),
   right.begin(),right.end(),
   inserter(*ret_lines,ret_lines->begin()));
   return QueryResult(rep(),ret_lines,left.get_file());
}



/*AndQuery::eval*/
//The AndQuery version of eval is similar to OrQuery version, excpet it call a library algorithm
//to find the lines in common to both queries.
QueryResult
AndQuery::eval(const TextQuery& text)const
{
   //virtual calls through the Query operands to get result sets for the operands
   auto left=lhs.eval(text),right=rhs.eval(text);
   //set to hold the intersection of lfet and right
   auto ret_lines=std::make_shared<std::set<line_no>>();
   //write the intersection of two two ranges to a destination iterator
   set_intersection(left.begin(),left.end(),
   right.begin(),right.end(),
   inserter(*ret_lines,ret_lines->begin()));
   return QueryResult(rep(),ret_lines,left.get_file());
}

/*NotQuery::eval*/
//NotQuery finds each line of the text within which the operand is not found
//returns the lines not in its operand's result set
QueryResult
NotQuery::eval(const TextQuery& text)const
{
   //virtual call to eval through the Query operand
   auto result=query.eval(text);
   //start out with an empty result set
   
   //we have to iterate through the lines on which our operand appears
   auto beg=result.begin(),end=result.end();
   //for each line in the input file, if that line is not in result,
   //add that line number to ret_lines
   auto sz=result.get_file()->size();
   std::set<line_no>st1;
   for(line_no ln1=0;ln1<sz;ln1++)
   st1.insert(ln1);
   std::set<line_no>st2;
   set_difference(st1.begin(),st1.end(),beg,end,inserter(st2,st2.begin()));
   auto ret_lines=std::make_shared<std::set<line_no>>(st2);
      return QueryResult(rep(),ret_lines,result.get_file());
    }

//exercise 15_41: 
int main(){
    std::ifstream input1("ex15_39i.txt");
    if(!input1.is_open()){std::cerr<<"Error! File not found!\n";exit(-1);}
   
    std::ofstream output1("extra_text_o1.txt",std::ofstream::out| std::ofstream::app);
     output1<<std::endl<<"Our first requirement: "<<std::endl;
    output1<<"Time: "<<__TIME__<<"\nDate: "<<__DATE__<<"\n\n";
    TextQuery Ob1_(input1);
   
      Query Ob1("a"),Ob2("to"),Ob3("is");
    Query q(Ob1&Ob2|~(Ob3));
    Query q1(Ob1&Ob2&(~Ob3));
    QueryResult rslt1=q.eval(Ob1_);
       QueryResult rslt2=q1.eval(Ob1_);
    print(output1,rslt1);
    output1<<std::endl<<"Our second requirement: "<<std::endl;
    print(output1,rslt2);
    
      
}