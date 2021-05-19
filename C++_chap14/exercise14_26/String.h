#include <memory>
#include <algorithm>
#include <iostream>

class String {
public:
friend bool operator==(const String&,const String&);
friend bool operator!=(const String&,const String&);

friend bool operator>(const String&,const String&);
friend bool operator<(const String&,const String&);
	String() : String("") { }//delegate constructor
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

    char& operator[](size_t sz)
    {
        if(sz>length())exit(-1);
        return elements[sz];
    }

       const char& operator[](size_t sz)const
    {
        if(sz>length())exit(-1);
        return elements[sz];
    }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
	char* elements;
	char* end;
	std::allocator<char>alloc;
};

std::pair<char*, char*>
String::alloc_n_copy(const char* b, const char* e)
{
    auto str = alloc.allocate(e - b);
    return{ str, std::uninitialized_copy(b, e, str) };
}
//std::uninitialized_copy: Return value
//Iterator to the element past the last element copied.
//b and e are not necessarily iterators. pointers are ok for char*.


//range_initializer takes two const char*, and use both as range to initialize elements and end.
void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char* s)
{
    char* sl = const_cast<char*>(s);//cast a const char* into a char*
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}



String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end,
            [this]
        (char& c) { alloc.destroy(&c); });//the enclosing function 'this' cannot be referenced until it is in the capture list.
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator = (const String& rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

#include<iostream>
#include<memory>
#include<string>
#include<vector>
using std::vector;
#include <algorithm>


std::ostream& operator<<(std::ostream &os, const String&Str)
{
	std::for_each(Str.c_str(),Str.c_str()+Str.length(),[&](char c)->void{os<<c;});
	
	return os;
}