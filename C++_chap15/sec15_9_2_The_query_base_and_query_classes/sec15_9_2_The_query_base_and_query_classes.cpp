#include"Query_support.h"

class Query_base{
    friend class Query;
    protected: 
    using line_no=TextQuery::line_no;//use in the eval functions
    virtual ~Query_base()=default;
    private:
    //eval returns QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&)const=0;
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
    //these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    public:
    Query(const std::string&);//builds a new WordQuery
    //interface functions, call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t)const
    {return q->eval(t);}
    std::string rep()const {return q->rep();}
    private:
    Query(std::shared_ptr<Query_base>query):q(query){}
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
int main()
{

}