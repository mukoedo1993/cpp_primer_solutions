#include"StrVec_ver2.h"
using std::allocator;
using std::string;
using std::vector;
allocator<string>StrVec::alloc;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The push_back function calls chk_n_alloc to ensure that there is room for an element.
//When chk_n_alloc returns, push_back knows that there is room for the new element. It asks alloc
//member to construct a new last element:
void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, s);
}

//The alloc_n_copy member will allocate enough storage to hold its given range of elements, and
//will copy those elements into the newly allocated space. This function returns a pair of pointers, pointing
//to the beginning of the new space and just past the last element it copied.
std::pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
	//allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);
	//initialize and return a pair constructed from data and 
	//the value returned by uninitialized_copy
	return{ data, uninitialized_copy(b, e, data) };
}

/*The free member*/
//The free member must destroy the elements and then deallocate the space this StrVec allocated.
void StrVec::free()
{
	//may not pass deallocate a 0 pointer; if elements is 0, there's no work to do.
	if (elements) {
		//destroy the old elements in reverse order
		for (auto p = first_free; p != elements;/*empty*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

//copy_control members
//Given our alloc_n_memory and free members, the copy-control members of our class are straightforward.
//The copy constructor calls alloc_n_copy:
StrVec::StrVec(const StrVec& s)
{
	//call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

//The destructor calls free:
StrVec::~StrVec() { free(); }

//The copy assignment operator calls alloc_n_copy before freeing its existing elements. By doing so it protects self_assignment:
StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
//Like the copy constructor, the copy-assignment operator uses the values returned from alloc_n_copy to initialize its pointers.

//Moving, Not Copying, Elements during Reallocation
//Before we write the reallocate member, we should think a bit about what it must do.
//This function will:
//1: allocate memory for a new, larger array of strings
//2: construct the first part of that space to hold the existing elements
//3: Destroy the elements in the existing memory and dellocate that memory.
void StrVec::reallocate()
{
	//we'll allocate space for twice as many elements as the current size
	auto newcapacity = size() ? 2 * size() : 1;
	//allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	//move the data from the old memory to the new
	auto dest = newdata;//points to the next free position in the new array
	auto elem = elements;//points to the enxt element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();//free the old space once we've moved the elements
	//update our data structure to point to the new elements
	//After moving the elements, we call free to destroy the old elements and free the memory that
	//this StrVec was using before the call to reallocate. The strings themselves no longer manage the memory
	//to which they had pointed; responsibility for their data has been moved to the elements in the new StrVec memory.
	//We don't know what value the strings in the old StrVec memory have, but we are guaranteed that it is safe to run the string
	//destructor on these objects.
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

//exercise 13_39:
void StrVec::reserve(size_t i)
{
	if (i < (cap - elements))return;
		alloc_n_move(i);
}

size_t StrVec::capacity()
{
	return(cap - elements);
}

void StrVec::resize(size_t i,string *s=nullptr)
{
	if (i == capacity())return;
	alloc_n_move(i);
	//deal with the element at and after the first_free:
	for (auto it = first_free; it != cap; it++)
		it = s;
}
//exercise 13_40: 
StrVec::StrVec(std::initializer_list<std::string> lst)
{
	auto length = lst.size();
	elements = alloc.allocate(length); cap = first_free = elements + length;
	auto str_ptr = lst.begin();
	for (auto it = elements; it != first_free; it++)
		alloc.construct(it++,*str_ptr++);
}

int main()
{
	vector<string>v_str = {"yaju","senpai","teikoku","N","M","S","L"};



	v_str.resize(13, string("yiyiyo"));
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout<<"v_str.capacity(): "<<v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.resize(3);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity(); 
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;


	v_str.reserve(15);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	v_str.reserve(2);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	return 0;
}