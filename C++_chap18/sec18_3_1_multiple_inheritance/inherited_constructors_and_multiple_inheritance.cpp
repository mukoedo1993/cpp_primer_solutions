#include<iostream>
#include<memory>
//Under the new standard, a derived class can inherit its constructors from one or more
//of its base classes. It is an error to inherit the same constructor from more than one
//base class.
struct Base1{
    Base1()=default;
    Base1(const std::string&){
        std::cout<<"    Base1(const std::string&)\n";
    }
    Base1(std::shared_ptr<int>){
        
    }
};
struct Base2{
    Base2()=default;
    Base2(const std::string&){
         std::cout<<"    Base2(const std::string&)\n";
    }
    Base2(std::shared_ptr<int>){
        
    }
};
//error: D1 attempts to inherit D1::D1(const string&)from both base classes
struct D1:Base1,Base2{
    using Base1::Base1;//inherit constructors from Base1
    using Base2::Base2;//inherit constructors from Base2
};
struct D2:Base1,Base2{
    using Base1::Base1;//inherit constructors from Base1
    using Base2::Base2;//inherit constructors from Base2
    //D2 must define its own construtco that takes a string
    D2(const std::string&s):Base1(s),Base2(s){}
    D2()=default;
};


int main()
{
   
    //D1 D("STRD");//call of overloaded ‘D1(const char [5])’ is ambiguous
    //D1 D2(std::string("shd"),std::string("dhdhs"));//no matching function for call to ‘D1::D1(std::string, std::string)’

    D2 d1("std");//ok
    
}

/*

    Base1(const std::string&)
    Base2(const std::string&)
*/