#include"Query_support_ver3.h"
int main()
{
    Query Ob1("nm"),Ob2("sl"),Ob3("land");
    Query q(Ob1|Ob2&Ob3);
    std::cout<<"\nline stamp:"<<__LINE__<<std::endl;
    std::cout<<q;

   
}

/*
WordQuery(const std::string&s)
Query(const std::string&)
WordQuery(const std::string&s)
Query(const std::string&)
WordQuery(const std::string&s)
Query(const std::string&)
BinaryQuery(const Query &l,const Query &r,std::string s)
 Query(std::shared_ptr<Query_base>query)
BinaryQuery(const Query &l,const Query &r,std::string s)
 Query(std::shared_ptr<Query_base>query)

line stamp:6
BinaryQuery::rep()
BinaryQuery::rep()
WordQuery::rep()
WordQuery::rep()
WordQuery::rep()

*/