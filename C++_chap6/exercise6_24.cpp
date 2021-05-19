#include<iostream>
/*
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
	{
		std::cout << ia[i] << std::endl;
	}
}
int main()
{
	int ic[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//print(ic[10]);//error: ic[10] cannot be used to initialize const int

}*/
//It should be:
void print( const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
	{
		std::cout << ia[i] << std::endl;
	}
}
int main()
{
	int ic[10] = { 9,8,7,6,5,4,3,2,1,0 };
	print(ic);//error: ic[10] cannot be used to initialize const int

}