#include<iostream>
//As an example, the IO library istream and ostream classes each inherit from a
//common abstract base class named basic_ios. That class holds the stream's buffer
//and manages the stream's condition state. The class iostream, which can both read and write
//to a stream, inherits directly from both istream and ostream. Because both types
//inherit from basic_ios, iostream inherits that basic class twice, once through istream
//and once through ostream.

//By default, a derived object contains a separate subpart corresponding to each class
//in its derivation chain. If the same base class appears more than once in the derivation, 
//then the derived object will have more than one subobject of that type.

//This default doesn't work for a class such as iostream. An iostream object wants to use
//ths same buffer for both reading and writing, and it wants its condition state to reflect
//both input and output operations. If an iostream has two copies of its basic_ios class, 
//this sharing isn't possible.


//e.g.
//Base class->Derived class
//ZooAnimal->Bear
//ZooAnimal->Raccoon
//Bear->Panda
//Raccoon->Panda
//Endangered->Panda
/*Using a virtual Base Class*/
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
class Raccoon:public virtual ZooAnimal{/*...*/};
class Bear:virtual public ZooAnimal{
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
    class Panda:public Bear,
    public Raccoon,public Endangered{
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
    };
    double Panda::max_weight()
{
    return std::max(ZooAnimal::max_weight(),Endangered::max_weight());
}
    void dance(const Bear&)
    {
        std::cout<<"dance(const Bear&)\n";
    }
    void rummage(const Raccoon&)
    {
        std::cout<<"rummage(const Raccoon&)\n";
    }
    std::ostream& operator<<(std::ostream& os,const ZooAnimal&)
    {
        std::cout<<"operator<<(std::ostream&,const ZooAnimal&)\n";
        return os;
    }
int main()
{
//Panda inherits ZooAnimal through both its Raccoon and Bear base classes. 
//However, because those classes inherited virtually from ZooAnimal, Panda has only one
//ZooAnimal base subobject.
Panda ying_yang;
dance(ying_yang);//ok: passes Panda object as a Bear
rummage(ying_yang);//ok: passes Panda object as a Raccoon
std::cout<<ying_yang;//ok: paases Panda object as a ZooAnimal

}