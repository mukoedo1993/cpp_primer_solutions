
#pragma once
//Until Sec. 15.9.3 

#ifndef QUERY_SUPPORT_VER3_H
#define QUERY_SUPPORT_VER3_H

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


class Query_base{
    friend class Query;
    protected: 
    using line_no=TextQuery::line_no;//use in the eval functions
    virtual ~Query_base()=default;
    private:
    //eval returns QueryResult that matches this Query
    //virtual QueryResult eval(const TextQuery&)const=0;
    //rep string representation of the query
    virtual std::string rep()const=0;
};
//Because we don't intend users, or the derived classes, to use Query_base directly,
//Query_base has no public members.

/*The Query class*/
//The Query class provides the interface to (and hides) the Query_base inheritance hierarchy.
//Each Query object will hold a shared_ptr to a corresponding Query_base object. Because Query is
//the only interface to the Query_base classes, Query must define its own versions of eval and rep.

//The &,|, and ~ operators will create AndQuery, OrQuey, and NotQuery objects, respectively.
//These operators will return a Query object bound to its newly generated object. To support these
//operators, Query needs a constructor that takes a shared_ptr to a Query_base and stores its given
//pointer. We'll make the operators freinds.

class Query{
    //////friend class NotQuery;
    //these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    public:
    Query(const std::string&);//builds a new WordQuery
    //interface functions, call the corresponding Query_base operations
    //QueryResult eval(const TextQuery &t)const
    //{return q->eval(t);}
    std::string rep()const {return q->rep();}
    private:
    Query(std::shared_ptr<Query_base>query):q(query){std::cout<<" Query(std::shared_ptr<Query_base>query)\n";}
    //We'll make this constructor private because we don't intend general user code
    //to define Query_base objects. Because this constructor is private, we'll need to
    //make the operators freinds.

    std::shared_ptr<Query_base>q;
};

/*The Query Output operator*/
std::ostream& 
operator<<(std::ostream &os,const Query &query)
{
    //Quer::rep makes a virtual call through its Query_base pointer to rep()
    return os<<query.rep();
}

//When we print a Query, the output operator calls the (public) rep member of class Query.
//That function makes a virtual call through its pointer member to the rep member of the object 
//to which this Query points. That is, when we write
/*
Query andq=Query(sought1)&Query(sought2);
cout<<andq<<endl;
*/
//The output operator calls Query::rep on andq. Query::rep in turns makes a virtual call through
//its Query::base pointer to the Query_base version of rep. Because andq points to an AndQuery
//object, that call will run AndQuery::rep

/*The Derived Classes*/
//However, rather than storing a Query_base pointer, our classes will themselves use
//a Query object. Just as user code is simplified by using the interface class, we can simplify 
//our own class code by using the same class.

//Implement them.
/*The WordQuery Class*/
//A WordQuery looks for a given string. It si the only operation that actually performs a query
//on the given TextQuery object:
class WordQuery: public Query_base{
    friend class Query;//Query uses the WordQuery constructor
    WordQuery(const std::string&s):query_word(s){std::cout<<"WordQuery(const std::string&s)\n";}
    //concrete class: WordQUery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t)const
    {return t.query(query_word);}
    std::string rep()const override{std::cout<<"WordQuery::rep()\n";return query_word;}
    std::string query_word;//word for which to search
};
inline
Query::Query(const std::string&s):q(new WordQuery(s)){std::cout<<"Query(const std::string&)\n";}

class NotQuery: public Query_base{
        friend Query operator~(const Query &);//here we are not the user for Query, so ok.
        NotQuery(const Query&q):query(q){}
        //concrete class: NoteQuery defines all inherited pure virtual functions
        std::string rep()const{std::cout<<"NotQuery::rep()\n";return "~("+query.rep()+")";}
        /*
        It is worth noting that the call to rep in 
        NotQuery's own rpe member ultimately makes
        a virtual call to rep: query.rep() is a nonvirtual 
        call to the rep member of the Query
        class. Query::rep in turn calls q->rep(), 
        which ins a virtual call through its Query_base pointer.
        */

        //QueryResult eval(const TextQuery&)const;
        Query query;
};

//The ~ operator dynamically allocates a new NotQuery object. The return (implicitly)
//uses the Query constructor that takes a shared_ptr<Query_base>. That is, the return statemnet
//is equivalent to 
       /*
       //allocate a new NotQuery object
       //bind athe resulting NotQuery pointer to a shared_ptr<Query_base>
       shared_ptr<Query_base>tmp(new NotQuery (expr));
       return Query(tmp);//use the Query constructor that takes a shared_ptr
       */

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
/*The BinaryQuery CLsass*/
//The BinaryQuery class is an abstract base class that holds the data needed by the query types
//that operate on two operands:
class BinaryQuery: public Query_base{
    protected:
    BinaryQuery(const Query &l,const Query &r,std::string s):
    lhs(l),rhs(r),opSym(s){std::cout<<"BinaryQuery(const Query &l,const Query &r,std::string s)\n";}
    //abstract class: BinaryQuery doesn't define eval
    std::string rep()const{std::cout<<"BinaryQuery::rep()\n";return "("+lhs.rep()+" "
    +opSym+" "
      +rhs.rep()+")"; }
      Query lhs,rhs;//right_ and left_hand operands
      std::string opSym;//name of the operator
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query&left,const Query&right):
    BinaryQuery(left, right,"&"){}
    //concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query&lhs,const Query&rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):
    BinaryQuery(left,right,"|"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
//These classes make the respective operator a friend and define a constructor to
//create their BinaryQuery base part with the appropriate operator. They inherit the 
//BinaryQuery definition of rep, but each overrides the eval function.
//Like  the ~ operator, the & and | operators return a shared_ptr bound to a newly allocated
//object of the corresponding type. The shared_ptr gets converted to Query as part of the return
//statement in each of these operators.
#endif