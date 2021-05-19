//A pointer to member is a pointer that can point to a nonstatic member of a class. 
//Normally a pointer points to an object, but a pointer to a member identifies a member
//of a class, not an object of that class.
#include<iostream>
class Screen{
    public:
    typedef std::string::size_type pos;
    char get_cursor()const{return contents[cursor];}
    char get()const{return contents[cursor];}
    char get(pos ht,pos wd)const
    {
        pos row=ht*width;
        return contents[row+wd];
    }
    static const std::string Screen::*data(){
        return &Screen::contents;
        //other members as before
    }
  
    std::string contents;
      private:
    pos cursor;
    pos height,width;
};

int main()
{
    //pdata can point to a string member of a const (or nonconst) Screen object
    const std::string Screen::*pdata;
    //declares that padat is a pointer to a member of class Screen that has type
    //type const string.
    pdata=&Screen::contents;
    // Here, we apply the address-of operator not to an object in memory but to 
    //member of the class Screen.

    //Of course, under the new standard, the easiest way to declare a pointer to 
    //member is to member is to use auto or decltype:
    auto pdata1=&Screen::contents;

    /*Using a pointer to data member*/
    Screen myScreen,*pScreen=&myScreen;
    //* dereferences pdata to fetch the contents member from the object myScreen
    auto s=myScreen.*pdata;
     //->*dereferences pdata to fetch contents frm the object to which pScreen points
     s=pScreen->*pdata;
     /*A function returning a pointer to data member*/
     //Because data members are typically private, we normally can't get a pointer to
     //data member directly. Instead, if a class like Screen wants to allow access to its 
     //content member, it would define a function to return a pointer to that member
     const std::string Screen::*pdata2=Screen::data();

     //fetch the contents of the object named myScreen
     auto s1=myScreen.*pdata;//bind the pointer pdata to an object of type Screen
    std::cout<<pdata2<<" "<<s1;
 
}
//1 