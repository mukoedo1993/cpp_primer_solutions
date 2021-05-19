//Library-defined function objects
//The standar library defines a set of classes that represent the arithmetic, relational,
//and logical operators. Each class defines a call operator that applies the named operation.

//e.g.1: 
//The plus class has a function-call operator that applies + to be pair of operands.
//library strings, ints, ans Sales_data classes.

#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::string;
int main()
{
    std::plus<int>intAdd;//function object that can add two int values.
    std::negate<int>intNegate;//function object that can negate an int value
    
    //use intAdd::operator(int,int) to add 10 and 20
    int sum=intAdd(10,20);//equivalent to sum=30
    std::cout<<sum<<std::endl;
    sum=intNegate(intAdd(10,20));//equivalent to sum=-30
    std::cout<<sum<<std::endl;
    //uses intNegate::operator(int) to generate -10 as the second parameter
    //to intAdd:operator(int,int)
    sum=intAdd(10,intNegate(10));//sum=0
    std::cout<<sum<<std::endl;
    vector<string>svec={"changsha","chang","bump","dche","heng"};
    sort(svec.begin(),svec.end(),std::greater<string>());
    for_each(svec.cbegin(),svec.cend(),[](const string&str){std::cout<<str<<std::endl;});

    //One important aspect of these library function objects is that 
    //the library guarantees that
    //they will work for pointers. Recall that comparing two unrelated pointers is undefined.
    //However, we may want to sort a vector of pointers based on their addresses in memory. 
    //Although it would be undefined for us to do so directly, we can do through one of the libray function objects.
    vector<string*>nameTable;
for_each(svec.begin(),svec.end(),[&nameTable]( string& str){nameTable.push_back(&str);});

//error: the pointers in nameTable are unrelated, so < is undefined.
sort(nameTable.begin(),nameTable.end(),[](string*a,string*b){return a<b;});
std::cout<<"\nin wrong way:\n";
for_each(nameTable.cbegin(),nameTable.cend(),[](string *str){std::cout<<*str<<std::endl;});
std::cout<<"\nin correct way:\n";
//okay: library guarantees that less on pointer is well deined
sort(nameTable.begin(),nameTable.end(),std::greater<string*>());
for_each(nameTable.begin(),nameTable.end(),[](string *str){std::cout<<*str<<std::endl;});
}
