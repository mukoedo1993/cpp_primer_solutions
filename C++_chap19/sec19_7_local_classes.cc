//A class can be defined inside a function body. Such a class is called a local class.
//A local class defines a type that is visible only in the scope in which it is defined.
//Unlike nested classes, the members of a local class are severely restricted.

/*Local classes may not use variables from the function's type*/
//a local class could only access: 1: a  type name 2: a static variable 3: enumerator
//of its enclosing function.
//private local class member are still invisible for the enclosing function unless it 
//befriends the function.
//Name lookup: same rules for the function. Must use local_class_name::...
#include<iostream>
int a,val;
void foo(int val){
    static int si;
    enum Loc{a=1024,b};
    //Bar is local to foo
    struct Bar{
        Loc locVal;//ok: uses a local type name
        int barVal;
     void yaju(){}//All members must be completely defined inside the class body, for 
     //local class.
    void fooBar(Loc l=a)
    {
        //barVal=val;//error: val is local to foo
        barVal=::val;//ok: uses a global object
        barVal=si;//ok: uses a static local object
        locVal=b;//ok: uses an enumerator
    }
       };
       //...void Bar::yaju(){}error here.
       std::cout<<"foo(int)has been run smoothly!\n";
      
}
/*Nested local class*/
void foo(int val,int){

    //Bar is local to foo
    class Bar{
       public: class Nested;;//declared class Nested
 
       };
       //definition of Nested
       class Bar::Nested{
       //...
       };
        std::cout<<"foo(int,int)has been run smoothly!\n";
}
//As usual, when we define a member outside a class, we must indicate the scope
//of the name. Hence, we defined Bar::Nested, which says that Nested is a class 
//defined in the scope of Bar.
//A class nested in a local class is itself a local class, with all the attendant restrictions.
//All members
int main(){
    foo(13,-20);
    foo(17);
}

/*

foo(int,int)has been run smoothly!
foo(int)has been run smoothly!
*/