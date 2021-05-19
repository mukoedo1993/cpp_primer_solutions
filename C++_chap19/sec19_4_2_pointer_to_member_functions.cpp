#include<iostream>
class Screen{
    public:
    Screen():cursor(0){}
    Screen(size_t sz):cursor(sz){}
    typedef std::string::size_type pos;
    char get_cursor()const{return contents[cursor];}
    char get()const{return contents[cursor];}
    char get(pos ht,pos wd)const
    {
        std::cout<<"We called char get(pos ht,pos wd)const\n";
        pos row=ht*width;
        return contents[row+wd];
    }
    static const std::string Screen::*data(){
        return &Screen::contents;
    }
  
    std::string contents;
      private:
    pos cursor;
    pos height,width;
    public:
    Screen& home(){std::cout<<"Screen::home()\n";
        return *this;}
    Screen&forward(){std::cout<<"Screen::forward()\n";
        return *this;}
    Screen&back(){std::cout<<"Screen::back()\n";
        return *this;}
    Screen&up(){std::cout<<"Screen::up()\n";
        return *this;}
    Screen&down(){std::cout<<"Screen::down()\n";
        return *this;}
    //Action is a pointer that can be assigned by any of the cursor movement members
    using Action=Screen&(Screen::*)();
    enum Directions{HOME,FORWARD,BACK,UP,DOWN};//HOME=0, FORWARD=1, BACK=2, UP=3,...,
      Screen& move(Directions);
    private: static Action Menu[];//function table
  
};
Screen& Screen::move(Directions cm){
    //run the element indexed by cm on this object
    return (this->*Menu[cm])();//Menu[cm] points to member functions
}
Screen::Action Screen::Menu[]={&Screen::home,
&Screen::forward,
&Screen::back,
&Screen::up,
&Screen::down};


/*Using type aliases for member pointers*/
//Action is a type that can point to a member function of Screen
//that returns a char and takes two pos arguments
using Action=
char(Screen::*)(Screen::pos,Screen::pos)const;
//Action is another name for the type "pointer to a const member function of class 
//Screen taking two parameters of type pos and returning char." Using this alias, we
//can simplify the definition of a pointer to get as follows:
Action get=&Screen::get;//get points to the get (function) member of Screen
Action get1=&Screen::get;

//action takes a reference to a Screen and a pointer to a Screen member function
Screen& action(Screen& orig,Action=&Screen::get)
{
    return orig;
}

int main()
{
    //We can also define a pointer that can point to a member function of a class.

    //pmf is a pointer that can point to a Screen member function that is const
    //that returns a char and takes no arguments.
    auto pmf=&Screen::get_cursor;
     
     
     char(Screen::*pmf2)(Screen::pos,Screen::pos)const;
     pmf2=&Screen::get;
//The parentheses around Screen::* in this declaration are essential due to precedence.
//Without the parentheses, the compiler treats the following as an (invalid) function 
//declaration:

//error: nomember function p cannot have a const qualifier
//char Screen::*p(Screen::pos,Screen::pos)const;

//unlike ordinary function poiners, there is no automatic conversion between a member 
//function and a pointer to that member:
pmf=&Screen::get;//must explicitly use the address-of operator
//pmf=Screen::get;//error: no conversion to pointer for member functions

/*Using* a pointer to member function*/
Screen myScreen1,*pScreen1=&myScreen1;
myScreen1.contents="nimasile!";
char c1=(pScreen1->*pmf)();
std::cout<<c1<<std::endl;//n

char c2=(pScreen1->*pmf2)(0,0);//We called char get(pos ht,pos wd)const
//The calls(myScreen->*pmf)() and(pScreen.*pmf2)(0,0)require the parentheses because 
//the precedence of the call operator is higher than the precedence of the pointer to
//member operator. 
//Without the parentheses,
// myScreen.*pmf()  <=> myScreen.*(pmf())

Screen myScreen_yaju;
//equivalent calls:
action(myScreen_yaju);//uses the default argument
action(myScreen_yaju,get1);//uses the variable get that we previously defined
action(myScreen_yaju,&Screen::get);//passes the address explicitly

myScreen_yaju.move(Screen::HOME);
myScreen_yaju.move(Screen::FORWARD);
myScreen_yaju.move(Screen::BACK);
myScreen_yaju.move(Screen::UP);
myScreen_yaju.move(Screen::DOWN);

}
/*

n
We called char get(pos ht,pos wd)const
Screen::home()
Screen::forward()
Screen::back()
Screen::up()
Screen::down()
*/