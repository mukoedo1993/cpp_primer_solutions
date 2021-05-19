//Conversion operator:
//A conversion operator is a special kind of member function that converts a value
//of a class type to a value of some other type. A conversion function typically has
//the general form
//operator type() const;

//Defining a Class with a Conversion Operator:
#include<stdexcept>
#include<iostream>
#include <string>
#include <typeinfo>

class SmallInt1{
    public:
    SmallInt1(int i=0):val(i)
    {
        if(i<0||i>255)
        throw std::out_of_range("Bad SmallInt value");
    }
    //operator int()const{return val;}
    int operator ()(){return val;}
    private:
    std::size_t val;
};

class SmallInt{
    public:
    SmallInt(int i=0):val(i)
    {
        if(i<0||i>255)
        throw std::out_of_range("Bad SmallInt value");
    }
    operator int()const{return val;}
 
    private:
    std::size_t val;
};

class SmallInt2{
public://the compiler won't automatically apply this conversion
SmallInt2(int i=0):val(i){
    if(i<0||i>255)
    throw std::out_of_range("Bad Smallest value");
}
explicit operator int()const {return val;}
private:
int val;
};

int main()
{
    SmallInt1 i(14);
    std::cout<<i()<<std::endl;

    SmallInt si;
   
    si=4;// implicitly converts 4 to smallInt then calls SmallInt::operator=
    si+3;//implicitly converts si to int followed by integer addition.
    std::cout<<typeid(si).name()<<std::endl;
    //Although the compiler will apply only one user-defined conversion at a time,
    //an implicit user-defined conversion can be preceded or followed by a standard (built-in)
    //function.
      SmallInt si1=3.14;
       std::cout<<typeid(si1).name()<<std::endl;
    //the double argument is converted to int using the built-in conversion
     si1=si1+3.14;//calls the SmallInt(int) constructor
    std::cout<<typeid(si1).name()<<std::endl;
    std::cout<<si1;

    /*Attention!*/
    //The conversion doesn't work. They are still ints.

    //In general, the existence of the conversion works...
    //However, there is one important exception: it is not uncommon for classes to
    //define conversion to bool.
   
   /*
Under earlier versions of the standard, classes that wanted to define a conversion to bool faced a problem: because bool is an arithmetic type, a class-type 
object that is converted to bool can be used in any context where an arithmetic type is expected. Such conversions can happen in surprsing ways.
e.g.:
int i=42;
std::cin<<i;//this code would be legal if the conversion to bool were not explicit.
   */
  
  //explicit conversion operators:
  SmallInt2 si2=3;//ok: the SmallInt constructor is not explicit
  //si2+3;//error: implicit is conversion required, but operator int is explicit
  static_cast<int>(si)+3;//ok: explicit request the conversion
  std::cout<<typeid(si2).name()<<std::endl;

  //The exception is that the compiler will apply an explicit conversion to an expression
  //used as a condition. That is, an explicit conversion will be used implicitly to convert an expression used as
  //The condition of an if,while, or do statement.
  //The condition in a for statement header
  //an operand to the logical NOT(!),OR(|),or AND(&&)operators.
  //The condition expression in a conditioanl (&:)operator.


  //while(cin>>value)
  //the iostream operator bool converison function works.
  //The function returns true if the condition state of cin is good, and false if otherwise.
}