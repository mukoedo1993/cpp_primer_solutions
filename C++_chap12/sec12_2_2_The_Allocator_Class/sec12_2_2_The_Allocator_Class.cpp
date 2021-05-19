#include<iostream>
#include<memory>
#include<fstream>
#include<sstream>
#include<iterator>
#include<vector>
using std::string;
using std::vector;
int main()
{
	std::ifstream input("sec12_2_2i.txt");
	//std::istream_iterator<string>it(input), eof;
	if (!input.is_open())exit(-1);
	std::ofstream output("sec12_2_2o.txt");
	int n = 13;
	string* const p = new string[n];//construct n empty strings
	string s;
	string* q = p;//q points to the first string
	while (getline(input, s)&&q!=p+n)
	{
		*q++ = s;//assign a new value to *q
	}
	const size_t size = q - p;//remember how many strings we read
	delete[]p;


	/*The allocator Class*/
	//The library allocator class, which is defined in the memory header, lets us separate
	//allocation from construction.

	//It provides type-aware allocation of raw, unconstructed, memory.

	//When an allocator object allocates memory, it allocates memory that is approriately sized
	//and aligned to hold objects of the given type:
	unsigned n1 = 14;
	std::allocator<string>alloc;//object that can allocate the strings
	auto const p1 = alloc.allocate(n1);//allocate n unconstructed strings. returns the one past the last constructed objects.

	/*allocators allocate unconstructed memory*/
	string* q1 = p1;//q1 wil point to the one past the last constructed object.
	//Test 1:
	alloc.construct(q1++);//*q1 is the empty string
	output << "Test 1: " << *p1 << std::endl;
	alloc.construct(q1++, 10, 'c');//*q1 is cccccccccc
	alloc.construct(q1++, "hi");//*q1 is hi!
	output << "Test 2: " << *p1 << std::endl;
	auto p1_ = p1 + 1;
	output << "Test 3:" << *p1_ << std::endl;
	auto p1_1 = p1_ + 1;
	output << "Test 4:" << *p1_1 << std::endl << std::endl;

	//output << "Test 5:" << *q1 << std::endl;//error: q points to unconstructed memory
	//When we have finished using the objects, we must destroy the elements we constructed, which we
	//do by calling destroy on each construted element. The destroy function takes a pointer and runs the destructor on the
	//pointed-to object.
	while (q1 != p1)
		alloc.destroy(--q1);//free the memory we actually allocated.
	//Notice that we may destroy only elements that are actually constructed.

	alloc.deallocate(p1, n1);//Deallocates memory that held n objects of type T starting at the address in the T*
	//pointer p; p must be a pointer previously returned by allocate, and n must be the size requested when p was created.
	//The user must run destroy on any objects that were constructed in the memory before calling deallocate.
	//Note:1: the pointer we pass to deallocate cannot be null; it must point to memory allocated by allocate.
	//Note: 2: the size argument passed to deallocate must be the same size as used in the call to allocate that obtained
	// the memory to which the pointer points.

	/*Algorithms to copy and fill unitialized memory*/
	std::allocator<int>alloc1;
	vector<int>vi = {1,2,4,5,7,8,10,13,12,15};
	//allocate twice as many elements as vi holds
	auto p_u = alloc1.allocate(vi.size() * 2);

	auto q_u = std::uninitialized_copy(vi.begin(), vi.end(), p_u);
	//Initilize the remaining elements to 42
	std::uninitialized_fill_n(q_u, vi.size(), 42);

	//free the memory.
	auto p_uclone = p_u-1;
	auto end_u = p_u + 2*vi.size()-1;
	output << "Let's free the memory:\n";
	for (; end_u!=p_uclone;end_u--)
	{
		output << *end_u << " ";
		alloc1.destroy(end_u);
	}
	output<<std::endl;
	alloc1.deallocate(p_u, vi.size() * 2);


}