//For example, if we delete a pointer of type Quote*, that pointer might at a Bulk_quote object. If
//the pointer points at Bulk_quote the compiler has to know that it should run the Bulk_quote destructor.
//As with any other function, we arrange to run the proper destructor by defining the destructor as 
//virtual in the base class.
#include<iostream>
class Quote{
    public:
    //virtual destructor needed if a base pointer pointing to a derived object is deleted
    virtual ~Quote(){std::cout<<"Quote::~Quote()is called!\n";}
};

class Bulk_quote:public Quote{
    virtual ~Bulk_quote()override final{std::cout<<"Bulk_quote::~Bulk_quote()is called!\n";}
};
int main()
{
    Quote *itemP=new Quote;//same static and dynamic type
    std::cout<<"@@@@@\n";
    delete itemP;//destructor for Quote called
     std::cout<<".....\n";
    itemP=new Bulk_quote;//static and dynamic types differ
     std::cout<<",,,,\n";
    delete itemP;// destructor for Bulk_quote called
       //analysis: itemP, now, takes Bulk_quote as its dynamic type, Quote as its static type.
    //Quote::~Quote does exist, virtual, and we obviously call it through a pointer.
    //So we consider the dynamic type, Quote_bulk::~Quote_bulk. It calls this at first. Then, the
    //subobject, Quote within Bulk_quote also call its destructor. Then, everything will be set.

    std::cout<<"~~~~~\n";
    //caveat:
    //Executing delete on a pointer to base that points to a derived object has undefined behavior
    //if the base's destructor is not virtual
}
//Important exception for our rule of thumb
//Destructors for base classes are an important exception to the rule of thumb that if a class needs a destructor
//, it also needs copy and assignment. A base class almost always needs a destructor, so that it can make
//the destructor virtual. If a base class has an empty destructor in order to make it virtual, then the
//fact that the class has a destructor does not indicate that the assignment operator or copy operator is also
//needed.

//Virtual destructors turns off the synthesized move, even if given in =default.
