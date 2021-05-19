//Until Sec. 18.2

#ifndef QUERY_SUPPORT_VER4_H
#define QUERY_SUPPORT_VER4_H

#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>

using line_no = std::vector<std::string>::size_type;
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
namespace chapter10{
class TextQuery {
public:

	using line_no = std::vector<std::string>::size_type;//I have to add this line.
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;//input file
	//map of each word to the set of the lines in which the word appears
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
}
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
	std::shared_ptr<std::vector<std::string>>file;//input file
};

QueryResult
chapter10::TextQuery::query(const std::string& sought)const
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
	//if the word was found, print the count and all occurences
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines)//for every element in the set
		//don't confound the user with text lines starting at 0
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin()+num)<<std::endl;
	return os;
}
namespace chapter15{
class Query;
}

class Query_base{
    friend class chapter15::Query;
    protected: 
    using line_no=chapter10::TextQuery::line_no;//use in the eval functions
    virtual ~Query_base()=default;
    private:
   public:
    virtual std::string rep()const=0;
};
class WordQuery;
namespace chapter15{
class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    public:
    Query(const std::string&s);
    //:q(new WordQuery(s)){std::cout<<"Query(const std::string&)\n";}
    std::string rep()const {return q->rep();}
    Query(std::shared_ptr<Query_base>query):q(query){std::cout<<" Query(std::shared_ptr<Query_base>query)\n";}
      private:
    std::shared_ptr<Query_base>q;
};
}
std::ostream& 
operator<<(std::ostream &os,const chapter15::Query &query)
{
    //Quer::rep makes a virtual call through its Query_base pointer to rep()
    return os<<query.rep();
}


class WordQuery: public Query_base{
    friend class chapter15::Query;//Query uses the WordQuery constructor
    WordQuery(const std::string&s):query_word(s){std::cout<<"WordQuery(const std::string&s)\n";}
    //concrete class: WordQUery defines all inherited pure virtual functions
    QueryResult eval(const chapter10::TextQuery &t)const
    {return t.query(query_word);}
    std::string rep()const override{std::cout<<"WordQuery::rep()\n";return query_word;}
    std::string query_word;//word for which to search
};

namespace chapter15{

 Query::Query(const std::string&s):q(new WordQuery(s)){std::cout<<"Query(const std::string&)\n";}
}

class NotQuery: public Query_base{
        friend chapter15::Query 
        chapter15::operator~(const chapter15::Query &);//here we are not the user for Query, so ok.
        NotQuery(const chapter15::Query&q):query(q){}
        //concrete class: NoteQuery defines all inherited pure virtual functions
        std::string rep()const{std::cout<<"NotQuery::rep()\n";return "~("+query.rep()+")";}
 
        chapter15::Query query;
};
namespace chapter15{
inline chapter15::Query operator~(const chapter15::Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
}
class BinaryQuery: public Query_base{
    protected:
    BinaryQuery(const chapter15::Query &l,const chapter15::Query &r,std::string s):
    lhs(l),rhs(r),opSym(s){std::cout<<"BinaryQuery(const Query &l,const Query &r,std::string s)\n";}
    //abstract class: BinaryQuery doesn't define eval
    std::string rep()const{std::cout<<"BinaryQuery::rep()\n";return "("+lhs.rep()+" "
    +opSym+" "
      +rhs.rep()+")"; }
      chapter15::Query lhs,rhs;//right_ and left_hand operands
      std::string opSym;//name of the operator
};

class AndQuery:public BinaryQuery{
    friend chapter15::Query chapter15::operator&(const chapter15::Query&,const chapter15::Query&);
    AndQuery(const chapter15::Query&left,const chapter15::Query&right):
    BinaryQuery(left, right,"&"){}
    //concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const chapter10::TextQuery&)const;
};

namespace chapter15{
inline Query operator&(const Query&lhs,const Query&rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}
}
class OrQuery: public BinaryQuery{
    friend chapter15::Query chapter15::operator|(const chapter15::Query&,const chapter15::Query&);
    OrQuery(const chapter15::Query &left,const chapter15::Query &right):
    BinaryQuery(left,right,"|"){}
    QueryResult eval(const chapter10::TextQuery&)const;
};

 namespace chapter15{
inline chapter15::Query operator|(const chapter15::Query &lhs,const chapter15::Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
 }
#endif
