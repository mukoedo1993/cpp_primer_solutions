#include<vector>
#include<iostream>
#include"sales_data.h"
#include<algorithm>
#include<numeric>
#include<tuple>
using std::vector;
//A common use of tuple is to return multiple values from a function.

//each element in files holds transactions for a particular store
std::vector<std::vector<Sales_data>>files;

struct matches{
    std::vector<Sales_data>::size_type ichi;
    std::vector<Sales_data>::const_iterator ni;
    std::vector<Sales_data>::const_iterator san;
};


//files holds the transactions for every store
//findBook returns a vector with an entry for each store that sold the given book.
std::vector<matches>
findBook(const vector<vector<Sales_data>>&files,
const std::string &book)
{
    vector<matches>ret;//initially emepty
    //for each store find the range of matching books, if any
    for(auto it=files.cbegin();it!=files.cend();++it){
        //find the range of Sales_data that have the same ISBN
        auto found=std::equal_range(it->cbegin(),it->cend(),
        book,compareIsbn);
       if(found.first!=found.second)//this stores had sales
       //remember the index of this store and the matching range
       ret.push_back({it-files.cbegin(),found.first,found.second});
       
    }
    return ret;//empty if no matches found
}

/*Using a tuple returned by a function*/
void reportResults(std::istream&in,std::ostream&os,
const vector<vector<Sales_data>>&files)
{
    std::string s;//book to look for
    while(in>>s&&s!="q"){
        auto trans=findBook(files,s);//stores that sold this book
        if(trans.empty()){
            std::cout<<s<<" not found in any stores"<<std::endl;
            continue;//get the next book to look for
        }
        for(const auto &store:trans)//for any store with a sale
          os<<"store"<<store.ichi<<" sales: "
          <<std::accumulate(store.ni,store.san,
          Sales_data(s))
          <<std::endl;
    }
}
int main()
{
    vector<vector<Sales_data>>vS;
    
   
    vector<Sales_data>v_emp;
    
    vS.push_back(v_emp);vS.push_back(v_emp);vS.push_back(v_emp);
 
    
     vS[0].emplace_back("coup",17,29);
     vS[0].emplace_back("str",16,53);
    vS[1].emplace_back("str",15,23);
    vS[1].emplace_back("str",16,87);
    vS[1].emplace_back("str",16,4.3);
    vS[1].emplace_back("str",17,29);
    vS[1].emplace_back("str1",16,27);
     vS[2].emplace_back("zoo",16,8);
    
  reportResults(std::cin,std::cout,vS);

}
//Result:
/*

quit
quit not found in any stores
str
store0 sales: bookNo is:
 units sold: 16
revenue is: 848

store1 sales: bookNo is:
 units sold: 64
revenue is: 2298.8

str1
store1 sales: bookNo is:
 units sold: 16
revenue is: 432

q

*/
