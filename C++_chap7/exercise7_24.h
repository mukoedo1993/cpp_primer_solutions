#pragma once

#ifndef EXERCISE7_24_H
#define EXERCISE7_24_H
#include<iostream>
#include<vector>
class Screen {
	
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
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
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
		std::cout << "!!"<<cursor <<"!! "<< std::endl;
	}
private:
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
private:
	//Screens this Window_mgr is tracking
	//by default, a Window_mgr has one standar sized blank Screen
	std::vector<Screen>screens{ Screen(24,80,' ') };
};
#endif