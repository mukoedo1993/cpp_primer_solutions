#include<iostream>
#include<cmath>
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
    virtual double max_weight()
    {
            return 114.514;
    }
    virtual double max_weight1(double)
    {
            return 114.514;
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
    virtual double max_weight()
    {
            return 119.810;
    }
     virtual double max_weight1(int)
    {
            return 119.810;
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
    double max_weight();
    // double max_weight1(int)override{return std::max(ZooAnimal::max_weight(),Endangered::max_weight());}
    };
   
    //The best way to avoid potential ambiguities is to define a version of the 
    //function in the derived class that resolves the ambiguity. E.g, we should give
    //our panda a max_weight function that resolves the ambiguity:
double Panda::max_weight()
{
    return std::max(ZooAnimal::max_weight(),Endangered::max_weight());
}







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
       
      // double d=ying_yang.max_weight();//"Panda::max_weight" is ambiguous
      //...if we comment the declaration and definition of  max_weight in panda
      double d=ying_yang.max_weight();
      std::cout<<std::endl<<d<<"\n";
      // double d1=ying_yang.max_weight1(17);
       //If we comment line 97 but don;t comment line
       // 135: request for member ‘max_weight1’ is ambiguous
    }
//Result:
    /* 
call line!48ying_yang
call line 14: 
call line 69!

119.81
~Endangered triggered!
~ZooAnimal triggered!
    
    */