#include<iostream>
void prntt()
{
	std::cout << "Let's print!" << std::endl;
}
size_t multiply(int a, int b)
{
	prntt();
	return (a * b);//If the semicolon is preserved, it is a linking error.
	//Otherwise, it is a compiling error.
	// But remember, the function's entry point doesn't have to be main, it could
	//be literally everything!

}
// Without the codes below:

/*

int main()
{
	//cin.get(string_name, size);// Input:Geeks for Geeks
	char name[25];
	std::cin.get(name, 25);
	std::cout << name;//Output:Geeks for Geeks

	return 0;
}

*/
//inline v.s. static