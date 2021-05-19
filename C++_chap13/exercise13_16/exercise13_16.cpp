#include<iostream>
#include<math.h>
#include<fstream>
#include <time.h>   
#include <stdlib.h>
class numbered {

public:numbered() {

	mysn = rand() % 100;
}
	  //a copy constructor
	  numbered(numbered& orig)
	  {

		  mysn = rand() % 100;
	  }
	  int mysn;
};

class numbered1 {

public:numbered1() {

	mysn = rand() % 100;
}
	  //synthesized copy constructor
	  int mysn;
};

void f(const numbered& s,std::ostream &os)
{
	os << s.mysn << std::endl;
}

void f1(const numbered1& s, std::ostream& os)
{
	os << s.mysn << std::endl;
}
int main()
{
	std::ofstream os("ex13_16o.txt");
	srand(time(NULL));
	numbered a, b = a, c = b;
	f(a,os); f(b,os); f(c,os);//
	os << "We use the synthesized copy constructor on the below part, the defined copy constructor on the above part.\n\n";
	srand(time(NULL));
	numbered1 a1, b1 = a1, c1 = b1;
	f1(a1,os); f1(b1,os); f1(c1,os);//
}
