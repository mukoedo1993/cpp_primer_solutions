#include<iostream>
#include<list>
#include<iterator>
using std::list;


int main()
{
	std::ostream_iterator<int> out_it(std::cout," ");
	list<int> listi= {1, 3, 0, 6, -7, 8, 9, 10, 2, 3, 0, 4, 8, 13};
	auto it = find(listi.crbegin(), listi.crend(), 0);

	//Exercise 10_36:
	//part 1:
	std::cout << "Exercise 10_36:\nFirst, print the elements from the last 0 to the last element:\n";
	copy(listi.crbegin(), ++it, out_it);
	std::cout << std::endl << std::endl;

	//part 2:
	std::cout << "Then, print the elements from the last 0 to the first element:\n";
	auto it1 = it.base();
	copy(it1,listi.cend(), out_it);
	std::cout << std::endl << std::endl;
	//Correct!!!


	//Exercise 10_37:
	std::cout << "Exercise 10_37:\n";
	list<int>listi1 = { 1,2,3,4,5,6,7,8,9,10 };
	auto it4 = listi1.crbegin();
	it4++; it4++; it4++;//it4 nows stands for position 7
	auto it5 = it4; it5++; it5++; it5++; it5++; it5++;//it 5 now stands for position 2
	copy(it4, it5, out_it);//print (left-inclusive)

}