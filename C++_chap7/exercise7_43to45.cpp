#include<iostream>
#include<vector>
using std::vector;
class NoDefault {
public:
	int t;
	mutable int k;
	NoDefault(int a) :t(a),k(a) { std::cout << "NoDefault class has been called.\n"; }
	//Notice that when members of class type uses the synthesized default constructor.

};

class C {
public:
	 NoDefault Ob1;
	C(NoDefault &Ob_in) :Ob1(Ob_in) { std::cout << "Class C has been called.\n"; }
	 NoDefault& printout() 
		//const
	{
		std::cout << Ob1.t;
		return Ob1;//Without commenting the const above, we will find that:
		//Qualifier dropped in binding reference of type "NoDefault &" to initializer of type
		//const NoDefault
	}
};

int main()
{
	//exercise 7.43:
	NoDefault OB1(13);
	C OB2(OB1);
	

	//exercise 7.44:
	vector<NoDefault>vec(10,NoDefault(1));//It means we use ten empty elements to initialize it.
	//However, it is not allowed. 

	//exercise7.45:
	vector<C>vec1(10,  C( OB1));
	vec1[2].printout();

	const NoDefault OB114(197);
	OB114.k += 1;
	std::cout << OB114.k << std::endl;
	 //const C OB514(OB114);
	//error: cannot convert const NoDefault to NoDefault &

}