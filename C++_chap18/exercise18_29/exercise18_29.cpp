#include<iostream>
class Class{
    public: Class(){
        std::cout<<"Class::Class()\n";
    }
};
class Base:public Class{
    public: Base(){
        std::cout<<"Base::Base()\n";
    }
};
class D1:virtual public Base{
    public: D1(){
        std::cout<<"D1::D1()\n";
    }
};
class D2:virtual public Base{
    public: D2(){
        std::cout<<"D2::D2()\n";
    }
};
class MI:public D1,public D2{
      public: MI(){
        std::cout<<"MI::MI()\n";
    }
};
    class Final:public MI,public Class{
        public:Final(){
            std::cout<<"Final::Final()\n";
        }
    };


int main()
{
 Final final;
 //(a):the sequence:
 /*
 Class::Class()
Base::Base()
D1::D1()
D2::D2()
MI::MI()
Class::Class()
Final::Final()
 */
//(b): 1 Base part and 2 Class parts.
//Notice that Class appears twice. First, we need to construct the Base class.
//But the Base class requires a Class to consturt beforehand.

//(c):
Base *pb;Class *pc;MI *pmi;D2 *pd2;
//pb =new Class;//error:invalid conversion from ‘Class*’ to ‘Base*’ [-fpermissive]
//It could be either a direct base class or an indirect base class.


//pc=new Final;//base class "Class" is ambiguous
//‘Class’ is an ambiguous base of ‘Final’

//pmi=pb;//a value of type "Base *" cannot be assigned to an entity of type "MI *"
//cannot convert from pointer to base class ‘Base’ to 
//pointer to derived class ‘MI’ because the base is virtual

pd2=pmi;//OK: not ambiguous


}