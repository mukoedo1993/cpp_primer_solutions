#include"StrVec_verex19_2.h"
using std::allocator;
using std::string;
using std::vector;
#include<iostream>
#include<cstdlib>
#include<stdexcept>

 void operator delete(void* mem){
	 std::cout<<"called user-defined delete!\n";
        free(mem);
      
    }
    void* operator new(size_t sz){
		std::cout<<"called user-defined new!\n";
        if(void *mem=malloc(sz))
        return mem;
        else
        throw std::bad_alloc();     
    }

int main()
{
	std::initializer_list<string>v_st = { "yaju","senpai","teikoku","N","M","S","L" };

	StrVec v_str(v_st);

	v_str.resize(13, string("yiyiyo"));
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.resize(2,"");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.reserve(15);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	v_str.reserve(2);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	
	v_str.resize(28, "dojo");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	StrVec getVec(std::cin);
	std::cout << "size is:" << getVec.size() << std::endl;
	for (auto it = getVec.begin(); it != getVec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << getVec.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;
	return 0;
}

// g++ ex19_2MAIN.cpp ex19_2_implementation.cpp StrVec_verex19_2.h


//Result:
/*
(base) zcw@mukoedo1993:~/C++chap19$ g++ ex19_2MAIN.cpp ex19_2_implementation.cpp StrVec_verex19_2.h
(base) zcw@mukoedo1993:~/C++chap19$ ./a.out
called user-defined new!
called user-defined new!
yaju senpai teikoku N M S L yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo 
v_str.capacity(): 13


called user-defined new!
yaju senpai 
v_str.capacity(): 2


capacity is: 2
Reserve 15
called user-defined new!
yaju senpai 
v_str.capacity(): 15v_str.size(): 2


capacity is: 15
yaju senpai 
v_str.capacity(): 15called user-defined new!
yaju senpai dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo 
v_str.capacity(): 28v_str.size(): 28


q
called user-defined new!
size is:0

v_str.capacity(): 0


(base) zcw@mukoedo1993:~/C++chap19$ g++ ex19_2MAIN.cpp ex19_2_implementation.cpp StrVec_verex19_2.h
(base) zcw@mukoedo1993:~/C++chap19$ ./a.out
called user-defined new!
called user-defined new!
called user-defined delete!
yaju senpai teikoku N M S L yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo 
v_str.capacity(): 13


called user-defined new!
called user-defined delete!
yaju senpai 
v_str.capacity(): 2


capacity is: 2
Reserve 15
called user-defined new!
called user-defined delete!
yaju senpai 
v_str.capacity(): 15v_str.size(): 2


capacity is: 15
yaju senpai 
v_str.capacity(): 15called user-defined new!
called user-defined delete!
yaju senpai dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo 
v_str.capacity(): 28v_str.size(): 28



called user-defined new!
q
called user-defined new!
called user-defined delete!
size is:1
 
v_str.capacity(): 1


called user-defined delete!
called user-defined delete!
*/