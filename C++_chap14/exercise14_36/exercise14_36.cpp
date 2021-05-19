#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
class ptrstring {
    public:
    ptrstring(std::istream&input=std::cin):is(input){
           
    }
    std::string operator()(){
       std::string str;
       if (!(is>>str))
       {
         str="";
       }
       return str;
    }
    private:
     std::istream&is;
     std::string str;
};
int main()
{
    std::vector<std::string>v;
    std::ifstream intf("ex14_35i.txt");//empty file
    std::ifstream intf1("ex14_35i1.txt");//2 lines
   ptrstring Ob1(std::cin);
   ptrstring Ob2(intf);
     ptrstring Ob3(intf1);
     v.push_back(Ob1());v.push_back(Ob2());v.push_back(Ob3());
     std::cout<<"To verify:\n";
     for_each(v.cbegin(),v.cend(),[](const std::string&str_){std::cout<<str_<<std::endl;});

}