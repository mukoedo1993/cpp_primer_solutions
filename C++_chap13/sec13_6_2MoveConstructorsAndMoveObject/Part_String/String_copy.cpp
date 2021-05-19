#include "String_copy.h"
#include <algorithm>
#include <iostream>

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

String::String(String&& rhs):elements(rhs.elements),end(rhs.end)
{
    rhs.elements = rhs.end = nullptr;
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

String& String::operator = (String&& rhs)noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
        std::cout << "copy-assignment" << std::endl;
    }
    return *this;
}