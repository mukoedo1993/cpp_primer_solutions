#include<iostream>
#include<list>
#include<deque>
#include<vector>
using std::vector;

class tst1 {
public: double t ;
	  tst1( double &k);
};

tst1::tst1( double &k):t(k){}
class noDefault {
public:
	tst1 Ob1;
	//explicit 
	
	double k;
	
	
		noDefault(tst1&OB,const double &tt):Ob1(OB),k(tt){}
		//A parameter passed by real value' change will not survive out of the function.
};

int main()
{
	//Assume noDefault is a type without a default constructor
	double para1 = 12.;
	tst1 Ob1(para1);
	double para2 = 1.3;
	noDefault init(Ob1,para2);
	
	vector<noDefault>v1(10, init);
	std::cout << v1[2].Ob1.t <<"! "<<v1[2].k<< std::endl;

	//vector<noDefault>v2(10);//error!

	//exercise9_2:
	typedef  std::deque<int> ex9_2;
	std::list<ex9_2> mylist = { {21,3},{5,8,9} };
	
	
}