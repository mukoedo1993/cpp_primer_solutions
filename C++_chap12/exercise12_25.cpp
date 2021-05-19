#include<iostream>
int main()
{
	int* pa = new int[10];
	delete[]pa;
	pa = nullptr;//preventing pa from becoming a dangling pointer.
}