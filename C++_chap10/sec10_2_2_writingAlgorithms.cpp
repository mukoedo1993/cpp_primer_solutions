#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<list>
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;

int main()
{
	/* When we use an algorithm that assigns to elements, we must take care
	* to ensure that the sequence into which the algorithm writes is at least
	*at large as the number of elements we ask the algorithm to write.
	*/

	
	//The algorithm doesn't change the size of a container.
	//A safe example:
	//fill(v.b,v.e,value);
	
	vector<int>vec(10, 3);
	cout << vec.size()<<"; ";
	fill(vec.begin(), vec.end(), 0);//read each element to 0

	//set a subsequence of the container to 10
	fill(vec.begin(), vec.begin() + vec.size() / 2, 10);



	//A much more danger one:
	//fill_n(v.b,length,val);//reset the pointer at v.begin(),up to length, to the value val.

	//Algorithms do not check write operations

	vector<int>vec_10_2_2;
	vec_10_2_2 = { 1,2,3,4,3,56,7,24,6,9,80 };

	fill_n(vec.begin(), vec.size(), 0);//reset all the elements of vec to 0.
	std::cout << *(vec_10_2_2.end() - 1) << std::endl;
	//fill_n(vec.begin(),100, 0);
	//Attention. The code above is a disater:
	//attempts to write to nonexistent elements in vec


	//Introducing back_inserter

	/* One way to ensure that an algorithm has enough elements to hold the
	*output is to use an insert iterator.(e.g. back_inserter
	*/

	//back_inserter takes a reference to a container and returns an insert
	//iterator bound to that container. When we assign through that iterator, the
	//assignment calls push_back to add an element with the given value to
	//that container:


	vector<int>vec_10_2_2a;
	auto it = back_inserter(vec_10_2_2a);//assigning through it adds elements to vec
	*it = 42;//vec now has one elment with value 42.

	//We frequently use back inseerter to create an iterator to use as the destination of
	//an algorithm. e.g.:

	vector<int>vec_10_2_2b;//empty vector
	//ok: back_inserter creates an insert iterator that adds elements to vec.
	fill_n(back_inserter(vec_10_2_2b), 10, 3);
	std::cout << *(vec_10_2_2b.end() - 1) << std::endl;

	int a1[] = { 0,1, 2,3,4,5,6,7,8,9};
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = std::copy(std::begin(a1), std::end(a1), a2);//copy a1 into a2
	std::cout << a1[8] << std::endl;


	//replace any element with the value 0 with 42:
	//replace will not only read the container but also write it.!!!
	list<int>lst = { 1,3,0,4,8 };
	std::replace(lst.begin(), lst.end(), 0, 42);//start at the range [str.b,str.e) and
	//change the value with 0 to 42.
	
		auto it_yaju = lst.begin();
		it_yaju++; it_yaju++;
		vector<int>ivec_alpha;
		std::cout << *it_yaju << std::endl;

		//replace_copy will only read the container.
		list<int>lst1 = { 1,3,0,4,8 };

		 std::replace_copy(lst1.begin(), lst1.end(), back_inserter(ivec_alpha),0, 475);
		 //use back_inserter to grow destination as needed.


		auto it_yaju1 = lst1.end();
		it_yaju1--; it_yaju1--; it_yaju1--;
		auto it_ivec1 = ivec_alpha.end();
		it_ivec1 =it_ivec1- 3;
		std::cout << "The original 0 is still: "<<*it_yaju1 << std::endl;
		std::cout << "While the new one is: " << *it_ivec1 << std::endl;

}