#include<memory>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
using std::string;
class TextQuery;
class StrVec {
	friend class TextQuery;
	friend class StrBlobPtr;
	friend class StrBlob;
    friend bool operator==(const StrVec&,const StrVec&);
    friend bool operator!=(const StrVec&,const StrVec&);
    friend bool operator<(const StrVec&,const StrVec&);
    friend bool operator>(const StrVec&,const StrVec&);
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);//copy constructor

	StrVec(StrVec&&)noexcept;
	StrVec(std::istream&);
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);//copy assignment
    StrVec& operator=(std::initializer_list<std::string>);
	~StrVec();//destructor
	void push_back(const std::string&);//copy the element
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	std::string* begin()const { return elements; }
	std::string* end()const { return first_free; }
	void resize(size_t,const string&);
	void reserve(size_t);
    std::string& operator[](std::size_t n)
    {return elements[n];}
    //return *(elements+n);}//It equals *(elements+n);
    const std::string& operator[](std::size_t n)const
    {return elements[n];}

private:
	static std::allocator<std::string>alloc;//allocates the elements
	void chk_n_alloc()//used by functions that add elements to a StrVec
		//allocates the elements
	{
		if (size() == capacity())reallocate();
	}
	void alloc_n_move(size_t sz)
	{
		auto elem = elements;
		auto new_elements = alloc.allocate(sz);
		auto new_first_free = elements + sz;
		auto new_cap = cap + sz;
		for (size_t i = 0; i < sz; i++)
		{
			if (i < size())
				alloc.construct(new_first_free++, std::move(*elem++));
		}
		free();
		elements = new_elements; first_free = new_first_free; cap = new_cap;

	}
public:
	//utilities used by the copy constructor, assignment operator, and destructor.
	std::pair<std::string*, std::string*>alloc_n_copy
	(const std::string*, const std::string*);
	void free();//destroy the elements and free the space
	void reallocate();//get more space and copy the existing elements


    

private:
	std::string* elements;//pointer to the first element in the array.
	std::string* first_free;//pointer to the first free element in the array
	std::string* cap;//pointer to the end of the array
};
#include<algorithm>
using std::allocator;
using std::string;
using std::vector;
allocator<string>StrVec::alloc;
void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, s);
}

std::pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
	//allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);
	//initialize and return a pair constructed from data and 
	//the value returned by uninitialized_copy
	return{ data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;/*empty*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s)
{
	//call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(std::istream& is)
{
	string str; vector<string>v_str;
	while (getline(is, str) && str != "q")
	{
		v_str.push_back(str);
	}
	elements=alloc.allocate(v_str.size());
	cap=first_free=uninitialized_copy(v_str.begin(), v_str.end(), elements);

}
StrVec::StrVec(std::initializer_list<std::string> lst)
{
	elements = alloc.allocate(lst.size());
	cap = first_free = uninitialized_copy(lst.begin(), lst.end(), elements);
}
StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
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
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t sz)
{
	std::cout << "capacity is: " << capacity()<<std::endl;
	if (sz == size())return;
	else if (sz > capacity()) {
		std::cout << "Reserve " << sz << std::endl;
		auto b = alloc.allocate(sz);
		auto e1 = b + sz;
		auto e2=std::uninitialized_copy(elements, first_free, b);
		free();
		elements = b;
		first_free = e2;
		cap = e1;
	}
	else;//null statement
}

void StrVec::resize(size_t sz, const string &str=string()) {
	if (sz < size())
	{
		auto b = alloc.allocate(sz);
		auto e = uninitialized_copy(elements, elements + sz, b);
		free();
		elements = b;
		first_free = cap = e;
	}
	else if (sz == size())return;
	else if (sz > size() && sz < capacity())
	{
		auto b = alloc.allocate(sz); auto e1 = b + capacity();//(...,e1) unfilled part
		auto e2 = uninitialized_copy(elements, elements + size(), b);//copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		first_free = e3; cap = e1;
		while ( e2 != e3)alloc.construct(e2++, str);
	}
	else
	{
		auto b = alloc.allocate(sz); //
		auto e2 = uninitialized_copy(elements, elements + size(), b);//[b,e2)copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		cap=first_free = e3;
		while (e2 != e3)alloc.construct(e2++, str);
	}
	
}
StrVec::StrVec(StrVec&& s)noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}
  StrVec& StrVec::operator=(std::initializer_list<std::string>i1)
  {
     auto data=alloc_n_copy(i1.begin(),i1.end());
     free();//destroy the elements in this object and free the space
     elements=data.first;//update data members to point to the new space
     first_free=cap=data.second;
     return *this;
  }

//For section 14_5:
int main()
{
   StrVec svec({"Changsha","Hunan","Leetcode"});
   const StrVec cvec=svec;//copy elements from svec into cvec
   if(svec.size()&&svec[0].empty()){
   svec[0]="zero";//ok: subscript returns a reference to a string
   //cvec[0]="Zip";
   }
   std::cout<<"cvec.operator[](1) is: "<<cvec.operator[](1)<<std::endl;
}