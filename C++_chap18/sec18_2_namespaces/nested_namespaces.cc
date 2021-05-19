#include<iostream>
#include<vector>
namespace cplusplus_primer{
    struct Query{
       std::string str;
    };
    //first nested namespace: deifnes the Query portion of the library
    namespace QueryLib{
        class Query{/*...*/
        friend Query operator&(const Query&,const Query&)
        {
            std::cout<<"we have called  friend Query operator&(const Query&,const Query&)";
                return Query();
        }
        };
        //...
    }
    //second nested namespace: defines Sales_data a portion of the library
    namespace Bookstore{
        class Quote{/*...*/};
        class Disc_quote:public Quote{/*...*/};
        //...
    }
}

int main()
{
    cplusplus_primer::QueryLib::Query q1,q2;
    q1&q2;//we have called  friend Query operator&(const Query&,const Query&)
    cplusplus_primer::Query str1;
    str1.str="jdsdsj";
}