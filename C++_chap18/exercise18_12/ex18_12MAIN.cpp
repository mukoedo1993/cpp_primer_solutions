#include"Query_support_ver4.h"
int main()
{
    chapter15::Query Ob1("nm"),Ob2("sl"),Ob3("land");
    chapter15::Query q(Ob1|Ob2&Ob3);
    chapter15::Query q1(~q);
    std::cout<<"\nline stamp:"<<__LINE__<<std::endl;
    std::cout<<q<<std::endl;
      std::cout<<"\nline stamp:"<<__LINE__<<std::endl;
    std::cout<<q1<<std::endl;

   
}
//Result:
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
 Query(std::shared_ptr<Query_base>query)

line stamp:7
BinaryQuery::rep()
BinaryQuery::rep()
WordQuery::rep()
WordQuery::rep()
WordQuery::rep()
(nm | (sl & land))

line stamp:9
NotQuery::rep()
BinaryQuery::rep()
BinaryQuery::rep()
WordQuery::rep()
WordQuery::rep()
WordQuery::rep()
~((nm | (sl & land)))
*/