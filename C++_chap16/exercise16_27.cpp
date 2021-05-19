#include<iostream>
template<class T>class Stack{};

void f1(Stack<char>);//No

class Exercise{
    Stack<double>&rsd;//(b)No
    Stack<int>si;//(c)Yes
};

int main()
{
    Stack<char>*sc;//(d)No
    f1(*sc);//(e)Yes
    int iObj=sizeof(Stack<std::string>);//(f)Yes
    std::cout<<iObj;//1
}
//Instantiation: Class or function generated directly from a template
void f1(Stack<char>)
{

}