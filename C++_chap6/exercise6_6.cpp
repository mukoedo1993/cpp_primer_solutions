/*
A:
A local variable is a variable defined inside a function scope.
The scope of a variable is the function body.

The lifetime of the ordinary variable (non static) stats when control passes through the
variable's definition, and ends when control passes through the end of the block in which the
variable is defined.
It is initialized if its definition contains an initiailizer, otherwise, it is default initialized.

B:
A parameter is also a local variable, but the definition is in the parameter list of the function.
  The scope of a parameter is the same as local variable, which is the function body.
  The lifetime of the parameter starts when the function begins, and ends when the function terminates.

C:A local static variable is a local variable that defined with static keyword. It has a lifetime much longer than usual local variable.

The scope of a local static variable is the same as local variable, which is the function body.
The lifetime of the local static varible starts when the first time control passes through the variable's definition, and ends when the program terminates.
It is initialized if its definition contains an initializer, otherwise, it is value initialized.
*/
#include<iostream>

    int foo(int param) {
        int lv;
        static int lsv = 1;
        lv = param + lsv;
        ++lsv;
        std::cout << lsv<<std::endl;
        return lv;
    }
    int main()
    {
        int k1 = 20;
        for (int i = 0; i < 20; i++)
            std::cout<<foo(i)<<std::endl;
    }