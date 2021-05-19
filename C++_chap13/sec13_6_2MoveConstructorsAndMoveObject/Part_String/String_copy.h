#pragma once
#ifndef STRING_COPY_H__
#define STRING_COPY_H__

#include <memory>

class String {
public:
	String() : String("") { }//delegate constructor
	String(const char*);
	String(const String&);
	String(String&&);
	String& operator=( String&&)noexcept;
	~String();

	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }
private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
	char* elements;
	char* end;
	std::allocator<char>alloc;
};


#endif