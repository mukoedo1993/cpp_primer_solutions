//Q:
//Which of the following declarations, if any, are incorrect? Explain why.

class Base{/*...*/};
//a:
//class Derived1:public Derived1{/*...*/};
//explaination: Because a base class must be defined before it could be inherited.
//invalid use of incomplete type'class Derived1'

//b: b is correct.
class Derived2:public Base{/*...*/};

//c: declarations of derived classes must appear only when we want to define the derived classes.
//class Derived3:public Base; class Derived3{};

int main(){}
