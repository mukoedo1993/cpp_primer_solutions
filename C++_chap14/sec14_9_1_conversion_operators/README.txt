Caveat:
The problem is that there is no single one-to-one mapping between an object of type Date and a value of type int. In such cases, it is bettwe not to
define the conversion operator. Instead, the class ought to define one or more ordinary members to extract the information in these various forms.

Under earlier versions of the standard, classes that wanted to define a conversion to bool faced a problem: because bool is an arithmetic type, a class-type 
object that is converted to bool can be used in any context where an arithmetic type is expected. Such conversions can happen in surprsing ways.
e.g.:
int i=42;
std::cin<<i;//this code would be legal if the conversion to bool were not explicit.
