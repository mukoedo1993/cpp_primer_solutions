//a syms b
//a.operatorsym (b) //a has operatorsym as a member function
//operatorsym(a,b)//operatorsym is an ordianry function
//Unlike ordinary function calls, we cannot use the form of the call to distinguish whether
//we are calling a nonmember or member function.

//Candidates: ordinary nonmember versions of that operator, as-well-as the built-in versions
//of that operator.

//call a named function: member and nonmember do not overload one another
//call througha an object of a class type, ok: only the class member functions are considered
//in a expression: NOT OK
#include<iostream>
class SmallInt{
    friend
    SmallInt operator+(const SmallInt&,const SmallInt&){SmallInt smlt;return smlt;}
    public:
    SmallInt(int i=0){val=i;}//conversion from int
    operator int()const{return val;}//conversion to int
    size_t print(){return val;}
    private: std::size_t val;
}
;

int main()
{
    SmallInt s1,s2;
    SmallInt s3=s1+s2;//uses overloaded operator +
    //int i=s3+0;//error: ambiguous//either SmallInt(0) or s3.operator()
   int i1=s1,i2=s2,i3=s3;
   std::cout<<i1<<" "<<i2<<" "<<i3<<"\n";//0 0 0

}