#include<iostream>
#include<typeinfo>

/*Forward declarations for enumerations*/
enum intValues:unsigned long long;//unscoped, must specify a type
enum class open_modes;//scoped enums can use int by default

///error: declarations and definition must agree whether the enum is scoped
//or unscoped
//enum class intValues;
enum struct intValues1{

};
enum intValues1;//error: intValues previously declared as scoped enum
//enum intValues1:long;//error: intValues previously declared as int

int main(){
intValues1 invl1;
}
/*Specifying the size of an enum*/
enum intValues:unsigned long long{
    charTyp=255,shortTyp=65535,intTyp=65535,
    longTyp=4294967295UL,
    long_longTyp=18446744073709551615ULL
    
};
//type by default: int
//Although each enum defines a unique type, it is represented by one of the
//built-in integral types. Under the new standard, we may specify that type by
//following he enum name with a colon and the name of the type we want to use:
//unscoped enumeration: 
