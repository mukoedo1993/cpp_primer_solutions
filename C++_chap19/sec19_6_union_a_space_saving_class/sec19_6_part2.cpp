#include<iostream>
/*unions with members of class type*/

//When a union has members of built-in type, we 
//can use ordinary assignment to change the value
//that the union holds. Not so for unions that have
//members of nontrivial class types.

//When a union has members of built-in type, the compiler will
//synthesize the memberwise versions of the default constructor
//or copy-control members.  The same is not true for unions that have 
//members of a class type that defines its pwm default constructor 
//or one or more of the copy-control members. If a union member's
//type defines one of these members, the compiler synthesizes the corresponding
//member as deleted.
//For example, the string class defines all five copy-control members and the
//default constructor. If a union contains a string and does not define its own
//default constructor or one of the copy-control members.
#include<iostream>
class A{};
union A1{
    A a;
};
union A2{
    std::string str;//library string has defined all five copy-control members and the 
    //default constructor.
    //But A2 doesn't give a definition. So, we cannot call any one of a big five of A2.
};
class A2_{
    ~A2_(){}
};
union A3_{
     A2_ str;
};
class A_ya{
    virtual void fcn(){}//non-trivial
};
class A_ya1:A_ya{};

union Anima{
    A_ya str;
};
union Anima1{
    A_ya1 str;
};
//http://www.cplusplus.com/reference/type_traits/is_trivial/
int main(){
    //A's all copy control members are synthesized. Also, A doesn't have a virtual member,
    //and doesn't inherit from a non-trivial class.
    //So,
    A1 yaju;
    yaju.~A1();//ok
    A1 yaju1={};//OK


//All these unions includes non-trivial classes:
    //A2 yaju1;//error:
      //
     // A3_ a3;//Also error:
    // Anima nimasi;//also error:
   // Anima1 nimasi1;//also error:
}