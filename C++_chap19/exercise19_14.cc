#include<iostream>
class Screen{
    public:
    Screen():cursor(0){}
    Screen(size_t sz):cursor(sz){}
    typedef std::string::size_type pos;
    char get_cursor()const{return contents[cursor];}
    char get()const{
        std::cout<<"Screen::get()const\n";
        return contents[cursor];}
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
    auto pmf=&Screen::get_cursor;
    auto pm=&Screen::contents;
    char (Screen::*pmf1)(Screen::pos,Screen::pos)const;
    pmf1=&Screen::get;
    pmf=&Screen::get;
    Screen y,*yaju=&y;
    (yaju->*pmf)();//The  precedence of call operator is prior to the * and . operators.
    //Screen::get()const
    //Solution of ex19_44:
    //It calls the Screen::get()const
}