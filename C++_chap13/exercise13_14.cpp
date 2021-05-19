#include<iostream>
#include<math.h>
#include <time.h>   
#include <stdlib.h>
class numbered {

public:numbered() {
	
	mysn = rand() % 100;
}
	  int mysn;
};

void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}
int main()
{
	srand(time(NULL));
	numbered a, b = a, c = b;
	f(a); f(b); f(c);//every time we make a test, the same result is given.
}
