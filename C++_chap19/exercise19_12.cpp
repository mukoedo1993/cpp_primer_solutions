#include<iostream>
class Screen{
    public:
    Screen():cursor(13){}
    Screen(size_t sz):cursor(sz){}
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
    static const pos Screen::* fcn1(){
        
        return &Screen::cursor;
     }
    std::string contents;
      private:
    pos cursor;
    pos height,width;
};

int main()
{
    Screen myScreen;
    auto ptr_ex19_22=Screen::fcn1();//OK
    //On this step, we only knows that ptr_ex19_22 is a pointer ptr.
    //ptr is a pointer that points a const string,also a pointer that points to a member
    //of Screen.

    //Here, we bind the ptr above to the object myScreen, and dereference the bound pointer.
    std::cout<<myScreen.*ptr_ex19_22;//13
    
}