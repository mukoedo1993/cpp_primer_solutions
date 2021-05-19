#include<iostream>
class Screen {
	/*
	We define pos in the public part of Screen because
	 we want users to use that name.
	*/
public:
	typedef std::string::size_type pos;
	/*
	*alternative way:
	*using pos=std::string::size_type; 
	*
	*/
	Screen() = default;//needed because Screen has another constructor
	//cursor initialized to 0 by its n class initializer
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	/*
	It is worth noting that our second contructor implicitly uses the in_class initializer for the
	cursor member.
	
	*/
	char get()const 
	{ return contents[cursor]; }//implicitly inline
	inline char get(pos ht, pos wd)const;//explicitly inline
	Screen& move(pos r, pos c);//can be made inline later

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	
};
inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;//move cursor to the column within that row
	return *this;
}
char Screen::get(pos r, pos c)const
{
	pos row = r * width;//compute row location
	return contents[row + c];
}
int main()
{
	 Screen  myscreen;//default constructor
	char ch = myscreen.get();//call: screen::get()
	ch = myscreen.get(0, 0);//call: screen::get(pos,pos)const
}