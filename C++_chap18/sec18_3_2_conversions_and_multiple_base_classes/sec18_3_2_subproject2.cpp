#include<iostream>
//Multiple inheritance:
//It is the ability to derive a class from more than one direct base class.
//A multiply derived calss inherites the properties of all its parents.
class ZooAnimal{
    public:
  
    virtual ~ZooAnimal(){
        std::cout<<"~ZooAnimal triggered!\n";
    }
    virtual   void print()
    {
        std::cout<<"ZooAnimal::print()\n";
    }
    

};
class Endangered{
    public:
    Endangered(bool crti):critical(crti){std::cout<<"call line 14: "<<std::endl;}
    Endangered():critical(false){std::cout<<"call line 15!"<<std::endl;}
    bool critical;
    virtual ~Endangered(){
        std::cout<<"~Endangered triggered!\n";
    }
     virtual   void print()
    {
        std::cout<<"void Endangered::print()\n";
        std::cout<<"critical value is:"<<std::boolalpha<<critical<<std::endl;
    }
    virtual void highlight()
    {
         std::cout<<"Endangered::highlight()\n";
    }

};
class Bear:public ZooAnimal{
    public:
      Bear():name("An Annonymous Animal"){}
    Bear(const std::string& str1):name(str1){std::cout<<"call line!"<<__LINE__<<str1<<"\n";}
    std::string name;
       virtual   void print()override
    {
        std::cout<<"Bear::print(): And NAME IS:"<<name<<'\n';
    }
    virtual void toes()
    {
        std::cout<<"Bear::toes()\n";
    }
  
};
class Panda:public Bear,public Endangered{
    using Bear::Bear;
    using Endangered::Endangered;
    /*...*/
    public:
    Panda():Bear(""),Endangered(false){}
    Panda(bool onExhibit):Bear(""),Endangered(onExhibit){}
      Panda(std::string name1,bool onExhibit):Bear(name1),Endangered(onExhibit)
      {std::cout<<"call line"<<__LINE__<<std::endl;}
    Panda(const char* str):Bear(str),Endangered(false){std::cout<<"call line " <<__LINE__<<"!\n";}
    //It synthesizes Panda(std::string str):ZooAnimal(std::string),Endangered(){}
  virtual   void print()override
    {
        std::cout<<"void Panda::print()\n";
        std::cout<<"name is: "<<name<<"critical value is: "<<critical<<"\n";
    }
     void highlight()override final
    {
         std::cout<<"Endangered::highlight()\n";
    }
     void toes()override final
    {
        std::cout<<"Panda::toes()\n";
    }
    virtual void cuddle()
    {
          std::cout<<"Panda::cuddle()\n";
    }
    };





      void print(const ZooAnimal&)
    {
        std::cout<<"void print(const ZooAnimal&)\n";
    }
  void print(const Endangered&)
    {
        std::cout<<" void print(const Endangered&)\n";
    }
  
    void print(const Bear&)
    {
        std::cout<<"void print(const Bear&)\n";
    }
    int main()
    {
      Panda ying_yang("ying_yang");
      //print(ying_yang);//error: call of overloaded ‘print(Panda&)’ is ambiguous

      Endangered *pb=new Panda("ying_yang");
      pb->print();//Panda::print()
      //pb->cuddle();//error: not part of the Endangered Interface
      //pb->toes();//error: not part of the Endangered Interface
             pb->highlight();//error:not part of the Endangered Interface
      delete pb;//
      pb=nullptr;//To prevent from a dangling dynamic ptr
    }
    
    /*
call line!40ying_yang
call line 14: 
call line 61!
call line!40ying_yang
call line 14: 
call line 61!
void Panda::print()
name is: ying_yangcritical value is: 0
Endangered::highlight()
~Endangered triggered!
~ZooAnimal triggered!
~Endangered triggered!
~ZooAnimal triggered!
    */