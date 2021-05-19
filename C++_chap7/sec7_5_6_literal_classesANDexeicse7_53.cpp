#include<iostream>

/*
*1: A constantexpr constructor MUST initialize every data member.
*2: The initializers must either use a constexpr constructor or
*be a constant expression.
*3: A constexpr constructor is used to generate objects that are
*are constexpr and for parameters or return types in constexpr functions.
*/

// For the sake of finishing exercise 7.53, I rewrite the codes totally:

class Debug {
public: 
	constexpr Debug(bool b=true):hw(b),io(b),other(b){}
	constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
	Debug(int flag1,int flag2,int flag3) :hw(false),io(false),other(false){ 
		switch (flag1)
		{
		case 1:
			hw = true; 
			std::cout << "hw is:" << hw << std::endl;
			break;
		case 0:
			std::cout << "hw is:" << hw << std::endl;
			break;
		default:
			
			std::cout << "No false detected for hw!" << std::endl;

			break;
		}
		switch (flag2)
		{
		case 1:
			io = true; 
			std::cout << "io is:" << io << std::endl;
			break;
		case 0:
			std::cout << "io is:" <<io << std::endl;
			break;
		default:
			std::cout << "No false detected for io!" << std::endl;
			break;
		}
		switch (flag3)
		{
		case 1:
			other = true; 
			std::cout << "other is:" << other << std::endl;
			break;
		case 0:
			std::cout << "other is:" << other << std::endl;
			break;

		default:
			std::cout << "No false for other!" << std::endl;
			break;
		}
	}
	constexpr bool any ()
	const
	{ return hw || io || other; }
	//Attention, since C++14, without const above, we will see that we cannot convert
	//'this' pointer from 'const Debug'to'Debug &'.(See case alpha and case beta)
	// A const object can only call const member functions and/or variables.
	 bool any()
		
	{
		return hw || io || other;
	}

	void set_io(bool b1) { io = b1; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;
	bool io;
	bool other;
};
int main()
{
	std::cout << std::boolalpha;
	constexpr Debug io_sub(false, true, false);//debugging IO
	if ( io_sub.any())// case alpha
		std::cerr << "print approriate error messages!" << std::endl;
	//io_sub.set_io(true); error:


	constexpr Debug prod(false);//no debugging during production
	if (prod.any())//case beta
		std::cerr << "Print an error message" << std::endl;


	//In order to use set_... functions, I modify the code above...
	//and made a non-constexpr constructor:
	//We make use of the type difference: (int)

	//TEST! TEST!
	Debug io_sub1(1,2,3);
	std::cout << io_sub1.any();

	Debug io_sub2(0, 0, 0);
	std::cout << io_sub1.any();



}
