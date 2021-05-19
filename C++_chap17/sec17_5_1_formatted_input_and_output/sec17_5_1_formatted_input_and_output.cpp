#include<iostream>
#include<cmath>
int main()
{
    /*Controlling the format of boolean values*/
    bool b=true;
    std::cout<<std::boolalpha<<true<<" "<<false<<std::endl;//true false
    std::cout<<std::noboolalpha<<true<<" "<<false<<std::endl;//1 0

    /*Specifying the Base for integral values*/
    std::cout<<"default: "<<20<<" "<<1024<<std::endl;//20 1024
    std::cout<<"octal: "<<std::oct<<20<<" "<<1024<<std::endl;//24 2000
std::cout<<"hex: "<<std::hex<<20<<" "<<1024<<std::endl;//14 400
std::cout<<"decimal: "<<std::dec<<20<<" "<<1024<<std::endl;//20 1024
/*Indicating Base on the Output*/
//The showcase manipulator:
std::cout<<std::showbase;
std::cout<<"default:"<<20<<" "<<1024<<std::endl;//20 1024
std::cout<<"in octal:"<<std::oct<<20<<" "<<1024<<std::endl;//024 02000
std::cout<<"in hex: "<<std::hex<<20<<" "<<1024<<std::endl;//0x14 0x400
std::cout<<"in decimal: "<<std::dec<<20<<" "<<1024<<std::endl;//20 1024
std::cout<<std::noshowbase;

std::cout<<std::uppercase<<std::showbase<<std::hex
<<"printed in hexadecimal: "<<20<<" "<<1024
<<std::nouppercase<<std::noshowbase<<std::dec<<std::endl;//0X14 0X400

/*Controlling the format of floating-point values*/
//1: How many digits of precision are printed.
//2: Whether the number is printed in hexadecimal, fixed decimal, or scientific
//notation
//3: Whether a decimal point is printed for floating-point values that are whole numbers
/*Specifying how much precision to print*/

//cout.precision reports the current precision value
std::cout<<"Precision: "<<std::cout.precision()
<<", Value: "<<sqrt(2.0)<<std::endl;//1.41421
//cout.precision(12) asks that 12 digits of precision be printed
std::cout.precision(12);
std::cout<<"Precision: "<<std::cout.precision()
<<", Value: "<<std::sqrt(2.0)<<std::endl;//1.41421356237
//alternative way to set precision using the setprecision manipulator
std::cout<<std::cout.precision(3);
std::cout<<"Precision: "<<std::cout.precision()
<<", Value: "<<sqrt(2.0)<<std::endl;//1.41
std::cout.precision();
/*Specifying the Notation of floating-point numbers*/
//We can force a stream to use scientific, fixed, or hexadecimal notation
//by using the appropriate manipulator. 
std::cout<<"default format: "<<100*sqrt(2.0)<<'\n'//141
<<"scientific "<<std::scientific<<100*sqrt(2.0)<<'\n'//1.414e+02
<<"fixed decimal"<<std::fixed<<100*sqrt(2.0)<<'\n'//141.421
<<"hexadecimal "<<std::hexfloat<<100*sqrt(2.0)<<'\n'//0x1.1ad7bc01366b8p+7
<<"use defaults: "<<std::defaultfloat<<100*sqrt(2.0)//141
<<"\n\n";
//printing the decimal point
std::cout<<10.0<<std::endl;//prints 10
std::cout<<std::showpoint<<10.0//prints 10.0
<<std::noshowpoint<<std::endl;//revert to default format for the decimal point
}