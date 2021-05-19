//FUnction-call operator:
/*
*Classes that overload the call operator allow objects of its type
*to be used as if they were a function. Because such classes can also store state, they
*can be flexible than ordinary functions.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
struct absInt{
int operator()(int val)const{
    return val<0?-val:val;
}
};

class PrintString{
    public:
    PrintString(std::ostream&o=std::cout,char c=' ' ):os(o),sep(c){}
    void operator()(const std::string&s)const{os<<s<<sep;}
    private:
    std::ostream &os;//stream on which to write
    char sep;//character to print after each output
};
int main()
{
    int i=-42;
    absInt absObj;//object that has a function-call operator
    int ui=absObj(i);//passes i to absObj.operator()
    std::cout<<"ui is: "<<ui<<std::endl;
    //The function-call operator must be a member function. A class may define multiple
    //versions of the call operator, each of which must differ as to the number or types of their
    //parameters.

    //Function-Object calsses with state
    //Like any other class, a function-object class can have additional members 
    //aside from operator();
    std::string s="SAMPLE";
    PrintString printer;//uses the defaults;
    printer(s);//prints s followed by a space on cout
    PrintString errors(std::cerr,'\n');
    errors(s);//prints s follower by a newline on cerr
    vector<std::string>vs={s,"hehe","howl",s,"CHanghsa"};

    //Function objects are most often used as arguments to the generic algorithms.
    //e.g.1: We can use the library for_each algorithm:
    for_each(vs.begin(),vs.end(),PrintString(std::cerr,'\n'));
    //The thrid argument to for_each is a temporary object of type PrintString that
    //we initailize from cerr and a newline character. 
}