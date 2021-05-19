#include<iostream>
/*Basic concepts:
1: An overload operator has the same number of parameters as the operator has operands. 
2: A unary operator has one parameter, a binary operator has two. 
3:In a binary operator, the left-hand operand is passed to the first parameter and he right-hand 
operand to the second. Except fpr the overloaded function-call operator operator(),an overloaded
operator may not have default arguments.
*/
//error:cannot redefine the built-in operator for ints
//int operator+(int,int);
//1:This restriction means that we cannot change the meaning of an operator when applied to operands
//of built in type.
//2:We can overload most, but not all, of the operators.
//3:We can overload only existing operators and cannot invent new operator symbols.
//3: e.g. ** ha dame desu
//4:Four symbols(+ - * and&)serve as both unary and binary operators. Either or both of
//these operators can be overloaded. The number of parameters determines which operator is being
//defined.
#include<iostream>
int operator+(std::string x,int y)
{
    size_t sz=x.size();
    return (sz+y);
}

 std::string operator+=(std::string 
 &//We need to show that this parameter is a reference, otherwise we cannot change it.
 x,size_t r) 
{
  auto y=std::string(r,x.at(0));
 x=x+y;
  return x;
}

int main()
{
  size_t data2=13;
  std::string data1="Guam";
  //We could "call" an overloaed operator in two ways:
  //1: like an ordinary function 2: like an operator+
  auto rslt1=data1+data2;
  auto rslt2=operator+(data1,data2);
  std::cout<<"rslt1 is: "<<rslt1<<std::endl;
    std::cout<<"rslt1 is: "<<rslt2<<std::endl;

data1+=data2;
std::cout<<"data1 now is :"<<data1<<std::endl;
operator+=(data1,data2);
std::cout<<"data1 now is :"<<data1<<std::endl;
//1:If the class does IO, define the shift operators to be consistent with how IO is done for
//the built-in types.
//2: inequality<->equality
//3:one single ordering operation->all ordering operations
//4: the return type of an overloaded operator should be compatible with the return
//from the built-in version of the operator.

//Some more rule of thumbs:
//1: The assignment(=),subscript([]),call(()),and member access arrow(->)must be defined as members.
//2:The compound-assignment operators ordinarily ought to be members.
//3: Operators that change the state of their object or that are closely tied to their given type--
//such as increment, decrement, and dereference--usually should be members.
//4: Symmetrix operators--e.g.: arithmetric, equality, relational and bitwise operators--usu. should be
//defined as ordinary nonmember functions.

//e.g.1: + symmertic: int+double or double+int because we can use either type on left-hand operand and right-hand operand
//e.g.2:
std::string s="world";//= is a member function of the class string
//It convertes the const char* "world" into  a library string.

std::string t=s+"!";
std::cout<<"t is: "<<t<<std::endl;
//if + is a member function, then t should be s.operator+("!"),
//But,
std::string t1="!"+t;//would be wrong.
std::cout<<"t1 is: "<<t1<<std::endl;
//It is a contradtiction.
//So, it cannot be a member function.
//Otherwise, we could write it as 
t1=operator+("!",t);
std::cout<<"t1 is: "<<t1<<std::endl;
//So, we cannot add two literal string. Because there is not a overloaed operator+ that support two
//const char* as soon as char* is a built-in type. overloading operator must take at least one parameter in the class type.
t.operator=(t1);
std::cout<<"t is: "<<t<<std::endl;
}
