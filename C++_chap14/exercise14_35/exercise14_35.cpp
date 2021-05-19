#include<iostream>
#include<fstream>
#include<string>
class ptrstring {
    public:
    ptrstring(std::istream&input=std::cin):is(input){
           
    }
    std::string operator()(){
       std::string str;
       if (!getline(is,str))
       {std::cerr<<"read failure! we will export an empty string!\n";
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
    std::ifstream intf("ex14_35i.txt");//empty file
    std::ifstream intf1("ex14_35i1.txt");//2 lines
   ptrstring Ob1(std::cin);
   std::cout<<Ob1()<<std::endl;
   ptrstring Ob2(intf);
   std::cout<<Ob2()<<std::endl;
     ptrstring Ob3(intf1);
   std::cout<<Ob3()<<std::endl;
}