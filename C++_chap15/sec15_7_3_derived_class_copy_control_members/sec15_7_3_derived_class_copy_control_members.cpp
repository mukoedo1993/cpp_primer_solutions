#include<iostream>

//Unlike the constructors and assignment operators, the destructor is responsible only for
//destroying the resources allocated by the derived class. 
//When a derived class defines a copy or move operation, that operation is responsible for
//copying or moving the entire object, including base-class members.

/*Defining a Derived Copy or Move Constructor*/
class Base{/*...*/
public:
Base()=default;
Base(int i1,int j1):i(i1),j(j1){}
Base(const Base&ori){i=ori.i;j=ori.j;}
Base(Base&&ori){i=std::move(ori).i;j=std::move(ori).j;}
Base& operator=(Base&& orig){i=std::move(orig).i;j=std::move(orig).j;return *this;}
Base& operator=(const Base&ori){Base ret;ret.i=ori.i;ret.j=ori.j;return ret;}
int i;
int j;
virtual ~Base()=default;
};
class D:public Base{
    public:
    //by default, the base class default constructor initializes the base part of an object
    //to use the copy or move constructor, we must explicitly call that
    //constructor in the constructor initializer list
    
    D()=default;
    //probably incorrect definition of the D copy constructor 
    //base-class part is default initialized, not copied
    D(int i1,int j1):Base(i1,j1){}
    D(const D&d):Base(d)//copy the base members
    /*initializers for member D*/{/*...*/}
    D(D&&d):Base(std::move(d))//move the base members
    /*initializers for members of D*/{/*...*/}

    D& operator=(const D&rhs);
    //Base::~Base()invoked automatically
    ~D(){std::cout<<"D::~D()\n";}
};



//It is worth noting that a derived constructor or assignment operator can use its corresponding
//base class operation regardless of whether the base defined its own version of that operator 
//or uses the synthesized version.
//e.g.1: call the Base::operator= using its corresponding base class operation regardless of whether the
//base defined its own version of that operator or uses the synthesized version.
D &D::operator=(const D&rhs)
{
    Base::operator=(rhs);//assigns the base part
    //assign the members in the derived class, as usual,
    //handling self-assignment and freeing existing resources as appropriate
    return *this;
}

int main()
{

     Base *b1;
     D d1;b1=new D(3,8);
     std::cout<<"\n......\n";
     delete b1;
     b1=nullptr;
      std::cout<<"\n......\n";
}