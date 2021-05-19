#include<iostream>
/*
Overriding is const and rlvalue(&,&&) sensitive. 
If const and/or & is(are) different, they are
two different functions when it comes to overriding.
*/

/*
Virtual, final and override could only be declared within the class, you MUST
omit them for which definitions are given outside the class.
*/
struct base{
    virtual void fcn()const &;
};

struct d:base{
    virtual void fcn()const & override;
};

struct d1:d{
    void fcn() const & final;
    virtual void fcn()&&{std::cout<<"d1::fcn()&&\n";}
};

struct d2 final: d1 {
       void fcn()const{std::cout<<"d2::fcn()const\n";}
       //OK as soon as const& do not appear
       //at the same time.
       
};


//virtual cannot be declared outside the function
void base::fcn()const &
{
   std::cout<<"base::fcn()const &\n";
}

void d::fcn()const & 
{
}
void d1::fcn()const &
{
   std::cout<<"d1::fcn()const&\n";
}

int main(){
    d1().fcn();
    base *b1,b2;
    d2 d;b1=&d;
    b1->fcn();
    b2.fcn();
    d2().fcn();
    d1 *d11;
    d11=&d;
    d11->fcn();
}

/*

d1::fcn()&&
d1::fcn()const&
base::fcn()const &
d2::fcn()const
d1::fcn()const&
*/