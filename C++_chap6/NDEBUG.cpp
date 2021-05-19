#include<iostream>
#define NDEBUG//It will disable the assert(expr); latter!
//www.oreilly.com/library/view/c-in-a/059600298X/re171.html
#include<cassert>
void print(const int ia[], size_t size)
{
#ifndef NDEBUG
	//__func__ is a local static defined by the compiler that holds the 
	//function's name
	std::cerr << __func__ << ": array size is " << size << std::endl;
#endif
	//...
	//__FILE__: the name of the file
	//__LINE__: the current line number
	//__TIME__: string literal: the time the file was compiled
	//__DATE__: string literal:the date the file was compiled
}
int main()
{
	std::string word = "sfdsdffshehe";
	int threshold;
	std::cin >> threshold;
	/*
	*/
	assert(threshold > 0);
	if (word.size() > threshold)
		(std::cout << "NMSL!");
	else(std::cout << "gougou!");
}