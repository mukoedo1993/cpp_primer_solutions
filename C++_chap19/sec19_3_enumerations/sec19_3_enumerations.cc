#include<iostream>
enum class open_modes{input,output,append};


//We define an unscoped enumeration by omitting the class
//(or struct)keyword. The enumeration name is optional in an unscoped enum:
enum color{red,yellow,green};//unscoped enumeration by omitting the class(or struct)
//keyword.

//unnamed, unscoped enum
enum{floatPrec=6,doublePrec =10,double_doublePrec=10};

//enum struct and enum class are euqivalent.
/*
The names of enumerators in a scoped enumeration follow normal
scoping rules and are inaccessible outside of the enumeration. The enumerator names in
an unscoped enumeration are placed into the same scope as the enumeration itself:
*/
//enum stoplight{red,yellow,green};//error: redefines enumerators.
enum class peppers{red,yellow,green};//ok: enumerators are hidden

enum class intTypes{
charTyp=8,shortTyp=16,intTyp=16,
longTyp=32,long_longTyp=64
};

int main()
{

  color eyes=green;//ok: enumerators are in scope for an unscoped enumeration
//peppers p=green;//error: enumerators are not in scope.
color hair=color::red;//ok:we can explicitly access the enumerators
peppers p2=peppers::red;//ok: using red from peppers
std::cout<<eyes<<std::endl;

/*
Enumerators are const, and if initialized, their initializers must be constant
expressions. Consequently, each enumerator is itself a constant expression. Because
the enumerators are constant expressions, we can use them where a constant expression is
required. e.g.: we can define constexpr variables of enumeration type:
*/
constexpr intTypes charbits=intTypes::charTyp;
/*
Similarly, we can use an enum as the expression in a switch statement and use the value
of its enumerators as the case labels. For the same reason, we can also use an enumeration type
as a nontype template parameter, and can initialize class static data members of enumeration
type inside the class definition.
*/
open_modes om
//=2//error: 2 is not of type open-modes
;//error:
om=open_modes::input;//ok: input is an enumerator of open_modes
}