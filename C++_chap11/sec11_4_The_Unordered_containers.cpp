#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include"Strong_sales_data.h"
using std::unordered_map;
using std::unordered_set;
using std::unordered_multiset;
using std::string;

struct Foo
{
	Foo(int j,string k) :i(j),str(k)
	{

	}
	int i;
	string str;
	 bool operator==( const Foo& b)
		 const//The line 19's content is very very important.
	{
		if (this->str == b.str)
			return true;
		else
			return false;
	}
};

size_t FooHash(const Foo& sd)
{
	return std::hash<string>()(sd.str);
}
//The new standard defines four unordered associative containers.

//Rather than using a comparison to organize their elements, these containers use
//a hash function and key type's == operator

//An unodered container is most useful when we have a key type for which there is no
//obvious ordering relationship among the elements. These containers are also useful for applications
//in which the cost of maintaining the elements in order is prohibitive.


//To use Sales_data as the key, we'll need to supply functions to replace both == operator and to calculate a 
//hash code. We'll start by defining these functions:


size_t hasher(const Sales_data& sd)
{
	//We could use an object of type hash<key_value> to generate the hash code for each element.
	return std::hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() == rhs.isbn();
}

int main()
{
	//The operators we've used on map and set apply to unordered_map and unordered_set as well.
	unordered_map<string, size_t>word_count;
	word_count["containers. "] = 1;
	word_count["use"] = 1;
	word_count["can"] = 1;
	word_count["example"] = 1;
	string word;
	
	for (const auto& w : word_count)//for each element in the map
	{
		//print the results
		std::cout << w.first << "occurs " << w.second
			<< ((w.second > 1) ? "times" : "time") << std::endl;
	}
	//It doesn't follow the alphabetical order.


	//
	//Managing the Buckets
	//1:The unordered containers are organized as a collection of buckets,
	//each of which holds zero or more elements. These containers use a hash
	//function to map elements to buckets.
	
	//2:To access an element, the container first computes the element's hash
	//code, which tells which bucket to search.

	//3:The container puts all of its elements with a given hash value into the same bucket.
	
	//4: As a result, the performance of an unordered container depends on the quality of its
	//hash function and on the number and size of its buckets.

	//5: The hash function must always yield the same result when called with the same argument.

	/*
	*
	*/



	//We can use hasher and eqOp functions to define an unordered_multiset as follows:
	using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	//arguments are the bucket size and pointers to the hash function and equality operator
	SD_multiset bookstore(42, hasher, eqOp);

	
	//Use FooHash to generate the hash code; Foo must have an == operator
	unordered_set<Foo, size_t(*)(const Foo&)>fooSet(10, FooHash);

	//What is not OK is to call a non-const member function on a const object.
}