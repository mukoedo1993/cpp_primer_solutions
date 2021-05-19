#pragma once
#pragma once


#ifndef SCREEN_VER3_H
#define SCREEN_VER3_H
// Update friendship between classes, and the Window_mgr class.
#include<iostream>
#include<vector>
class Screen {
	//Window_mgr  members can access the private parts if class Screen
	friend class Window_mgr;
public:
	Screen& display(std::ostream& os) { do_display(os); return *this; }
	Screen display1(std::ostream& os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os)const { do_display(os); return *this; }
	typedef std::string::size_type pos;
	/*
	*alternative way:
	*using pos=std::string::size_type;
	*
	*/
	Screen() = default;//needed because Screen has another constructor
	//cursor initialized to 0 by its n class initializer
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {}
	inline Screen& set(char r) { contents[cursor] = r; return *this; }
	inline Screen set1(char r) { contents[cursor] = r; return *this; }
	inline Screen& set(pos, pos, char);
	char get()const
	{
		return contents[cursor];
	}//implicitly inline
	inline char get(pos ht, pos wd)const;//explicitly inline
	Screen& move(pos r, pos c);//can be made inline later
	Screen move1(pos r, pos c);
	void some_member()const;
	inline
		void print()
	{
		std::cout << contents << std::endl;
	}
	inline
		void cursor_print()
	{
		std::cout << "!!" << cursor << "!! " << std::endl;
	}
private:
	void do_display(std::ostream& os)const {
		os << contents;
	}

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	//mutable data member
	/*
	*A mutable data member is never const, even when its a member of a constant object.
	*/
	mutable size_t access_ctr;//may change even in a const object
};

inline
Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;//move cursor to the column within that row
	return *this;
}

inline
Screen Screen::move1(pos r, pos c)
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



void Screen::some_member()const
{
	++access_ctr;//keep a count of the calls to any member function
	// whatever other work these member needs to do.
}

/*In addition to defining the Screen class,we'll define a window manager class
* that represents a collection of Screens on a given display. This class will have a vector
* of Screens in which each element represents a particular Screen. By default, we'd like
*our Window_mgr class to start up with a single, default-initialized Screen. Under the new
*standard, the best way to specify this default value is as an in-class specifier.
*
*
*/
class Window_mgr {
public://location ID for each Screen on the window
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i);
private:
	//Screens this Window_mgr is tracking
	//by default, a Window_mgr has one standar sized blank Screen
	std::vector<Screen>screens{ Screen(24,80,' ') };
};
void Window_mgr::clear(ScreenIndex i) {
	// s is a reference to the Screen we want to clear
	Screen& s = screens[i];
	//reset the contents of that Screen to all blanks
	s.contents = std::string(s.height * s.width, ' ');
}

#endif