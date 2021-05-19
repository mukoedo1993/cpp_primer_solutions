#include<iostream>
class ZooAnimal{
    public:
  ZooAnimal()=default;
  ZooAnimal(const std::string&str1,bool exhibit,const std::string&str2)
  {

  }
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
class Raccoon:public virtual ZooAnimal{/*...*/
public:Raccoon()=default;
Raccoon(std::string,bool);
};
Raccoon::Raccoon(std::string name,bool onExhibit):
ZooAnimal(name,onExhibit,"Bear"){}

class Bear:virtual public ZooAnimal{
      public:
      Bear():name("An Annonymous Animal"){}
    Bear(const std::string& str1):name(str1){std::cout<<"call line!"<<__LINE__<<str1<<"\n";}
    Bear(const std::string&str,bool bl):name(str){}
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
    
    Panda(const char* str):Bear(str),Endangered(false){std::cout<<"call line " <<__LINE__<<"!\n";}
    //It synthesizes Panda(std::string str):ZooAnimal(std::string),Endangered(){}
    Panda(std::string name,bool onExhibit):
    ZooAnimal(name,onExhibit,"Panda"),
    Bear(name,onExhibit),
    Raccoon(name,onExhibit),
    Endangered(Endangered::critical),
    sleeping_flag(false){}
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
    bool sleeping_flag;
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
   Panda pd;
}