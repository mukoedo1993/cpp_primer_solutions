#include<iostream>
//Multiple inheritance:
//It is the ability to derive a class from more than one direct base class.
//A multiply derived calss inherites the properties of all its parents.
class ZooAnimal{
    public:
    ZooAnimal():name("An Annonymous Animal"){}
    ZooAnimal(const std::string& str1):name(str1){std::cout<<"call line!"<<__LINE__<<str1<<"\n";}
    std::string name;
    virtual ~ZooAnimal(){}
};
class Endangered{
    public:
    Endangered(bool crti):critical(crti){std::cout<<"call line 14: "<<std::endl;}
    Endangered():critical(false){std::cout<<"call line 15!"<<std::endl;}
    bool critical;
    virtual ~Endangered(){}
};
class Bear:public ZooAnimal{

};
class Panda:public ZooAnimal,public Endangered{
    using ZooAnimal::ZooAnimal;
    using Endangered::Endangered;
    /*...*/
    public:
    Panda():ZooAnimal(""),Endangered(false){}
    Panda(bool onExhibit):ZooAnimal(""),Endangered(onExhibit){}
      Panda(std::string name1,bool onExhibit):ZooAnimal(name1),Endangered(onExhibit)
      {std::cout<<"call line"<<__LINE__<<std::endl;}
    Panda(const char* str):ZooAnimal(str),Endangered(false){std::cout<<"call line " <<__LINE__<<"!\n";}
    //It synthesizes Panda(std::string str):ZooAnimal(std::string),Endangered(){}

    };
/*
Under multiple inheritance, an object of a derived class contains a subobject for
each of its base classes.


*/
struct tst1
{
    tst1(int,bool bl1):bl(bl1){}
    int i;
        bool bl;
};
int main()
{
    Panda pd("hehe",true);
    std::cout<<__LINE__<<" "<<std::boolalpha<<pd.critical<<" "<<pd.name<<"\n";
    Panda pd2("mother",false);
       std::cout<<__LINE__<<" "<<std::boolalpha<<pd2.critical<<" "<<pd2.name<<"\n";
       std::cout<<"From Line "<<__LINE__<<std::endl;
       Panda ying_yang("ying_yang");
       Panda Ling_ling=ying_yang;//use of copy constructor
  std::cout<<__LINE__<<" "<<std::boolalpha<<ying_yang.critical<<" "<<ying_yang.name<<"\n";
    std::cout<<__LINE__<<" "<<std::boolalpha<<Ling_ling.critical<<" "<<Ling_ling.name<<"\n";

    //The example below will use an synthesized cosntructor...
      Panda ying_yang1(std::string("ying_yang"));
       Panda Ling_ling1=ying_yang1;//use of copy constructor
  std::cout<<__LINE__<<" "<<std::boolalpha<<ying_yang1.critical<<" "<<ying_yang1.name<<"\n";
    std::cout<<__LINE__<<" "<<std::boolalpha<<Ling_ling1.critical<<" "<<Ling_ling1.name<<"\n";
   
}

/*

call line!8hehe
call line 14: 
call line30
50 true hehe
call line!8mother
call line 14: 
call line30
52 false mother
From Line 53
call line!8ying_yang
call line 14: 
call line 31!
56 false ying_yang
57 false ying_yang
call line!8ying_yang
call line 15!
60 false ying_yang
61 false ying_yang
*/