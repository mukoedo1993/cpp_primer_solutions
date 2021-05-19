#include<iostream>
#include"Sales_data_Delegating_constructors.h"

int main()
{
	Sales_data Ob2;//first run non, then 1st delegate
	string str_1 = "keke";//first run non, then 2nd delegate
	Sales_data Ob1(str_1);
	
	Sales_data Ob3(std::cin);//first run non, then 1st delegeate, then 
	//3rd delegate

}