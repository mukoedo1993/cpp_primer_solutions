#include<iostream>


//The type of a static data member can be const, reference, array,
//class type, and so forth.

//The static members of a class exist outside any object. Objects do not contain 
//data asscociated with static data members.


class Account {
public: 
	void calculate() { amount += amount * interestRate; }
	  static double rate() { return interestRate; }
	  static void rate(double);

	  /*
	  We might not use a nonstatic data member as a default argument because its
	  value is part of the object of which it is a member.
	  However, as we could see below, using a nonstatic data member as a default provides no object from which
	  to obtain the member's value and so is an error.
	  */

	  static constexpr 
		  double test1 = 12.3;

	  double test_fun1(int a = test1)
	  {
		  return a;
	  }
	  
private:
	std::string owner;
	double amount;
	static double interestRate;
	//remaining members as before
	static double initRate();

public: static constexpr int period1 = 30;//period is a constant expression
	  static constexpr int period = 30;
private: double daily_tbl[period1];
	   double daily_tbl_1[period];
};

 constexpr int Account::period1;

void Account::rate(double l)
{
	
}
double Account::initRate()
{
	return 31.45;
}
//define and initialize a static class member
double Account::interestRate = initRate();

/* The statement defines the object named interestRate that
*is a static member of class Account and has type double. 
*Once the class name is seen, the remainder of the definition 
* is in the scope of the class. As a result, we can use initRate
* without qualification as the initializer for interestRate.
*/
void itt(const int& a)
{
	std::cout << a << std::endl;
}


int main()
{
	//We can access a static member directly through the scope member:
	double r, r1;
	r = Account::rate();//access a static member using the scope operator


	Account ac1;
	Account* ac2 = &ac1;
	//equivalent ways to call the static member rate function

	r = ac1.rate();//through an account object or reference

	r1 = ac2->rate();//through a pointer to an Account object
	itt(Account::period1);//case ichi
	itt(ac1.period1);//case ni
	itt(ac2->period1);//case sann
	itt(Account::period);//case yon
	itt(ac1.period);//case go
	itt(ac2->period);//case roku
	//It seems that yon to roku should stick in error. Howver, each one works well.

	std::cout << ac1.test_fun1() << std::endl << ac2->test_fun1(11.4);

}



	//Even though static members are not part of the objects of its class, we can use an object,
	//a reference, or pointer of the class type to access a static member.
	
	/*In-class initialization of static data members
	*1: Ordinarily, class static members may not be initialized in the class body. 

	*2: However, we can provide in-class initializers for static members that have const integral
	*type and must do so for static members that are constexprs of literal type.
	
	*3:The initializers must be constant expressions.

	*4: Such members are themselves constant expressions; they can be used where a constant expression is
	required.
	
	*e.g.:(see above)
	
	*5: If the member is used only in contexts where the compiler can substitute the member's value, then
	 an initialized const or constexpr static need not be separately defined. However, if we use the member
	 in a context in which the value cannot be substituted, then there must be a definition for that member.

	 For example, if the body only use we make of period to define the dimension of daily_tb1, there is no
	 need to define period outside of Account. However, if we omit the definition, it is possible that even 
	 seemingly trivial changes to the program might cause the program to fail to compile because of the missing
	 definition. For example, if we pass Account::period to a function that takes a const int&, then period must
	 be defined.

	 If an initializer is provided inside the class, the member's definition must not specify an initial value.
	
	
	
	
	
	
	
	*/

