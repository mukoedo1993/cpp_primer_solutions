#include<iostream>
/*
Each class defines how objects of its type can be initialized.
Classes control object initialization by defining one or more special member
functions known as constructors.

The job of a constructor:
To initialize the data members of a class object.
A constructor is run whenever an object of class type is created.


1: Constructors have the same name as the class.
2: Unlike other functions, constructors have no return type. Like other functions,
constructors have a (possibly empty)parameter list and a (possibly empty) function body.
 Like other functions,
 3: A class can have multiple constructors.
 Like any other overloaded function,
 4: the constructors must differ from each other
 in the number or types of their parameters.
 Unlike other member functions,
 5: constructors may not be declared as const. When we create a const object of a class type,
the object does not assume its "constness" until after the constructor completes the object's initialization.
5_1: Thus, constructors can write to const objects during their construction.

6: If we did not supply an initializer for these objects, the compiler will implicitly define the default constructor
for us:
-->synthesized default constructor
*/


/*
Some classes cannot rely on the synthesized default constructors
1: The most common reason that a class must define its own default constructor is that the compiler generates the
default for us only if we do not define any other constructors for the class.
2:A second reason to define the default constructor is that for some classes, the synthesized default constructor does
the wrong thing. Remember that objects of built-in or compound type(e.g. arrays amd pointers) that are defined inside block
have undefined value when they are default initialized.
3: A third reason that some classes must define their own default their own default constructor is that sometimes
the compiler is unable to synthesize one. For example, if a class has a member that has a class type, and that class doesn't have a
default constructor, then the compiler can't initialize that member.
*/



//Defining the Sales_data Constructors
struct Sales_data {
    //constructors added
    Sales_data() = default;
    Sales_data(const std::string& s) :bookNo(s) {}//case a
    Sales_data(const std::string& s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p* n) {}//case b
    Sales_data(std::istream& is)
    {
        read(is);
    }
    //other members as before
    std::string isbn()const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double ave_price()const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //What =default Means
    /*
    1: No arguments.
    2:We are defining this constructor only because we want to provide
    other constructors as well as the default constructor.

    3: We want this constructor to do exactly the same work as the synthesized version
    we had been using.

    */
    // Initializer list:
     /*
     When a member is omitted from the constructor initializer list, it is implicitly initialized
     using the same process as is used by the synthesized default constructor.
     //has the same behavior as the case a above:
     Sales_data(const std::string &s):bookNo(s),units_sold(0),revenue(0){}

     */
     // Defining a constructor outside the class body
    std::istream& read(std::istream& is)
    {
        double price = 0;
        std::cout << "Please input bookNo, units_sold and price one by one:\n";
        is >> bookNo >> units_sold >> price;
        if (price <= 0)
        {
            std::cerr << "Error! Price must be a positive integer! We turn all back to default data values!" << std::endl;
            units_sold = 0; price = 0;
        }
        revenue = price * units_sold;
        return is;//!!!!
    }
};




int main()
{

}