#include<iostream>
#include<vector>
#include<string>
using std::string; using std::vector;
/*
Although we can use subscripts to access the characters of a string or
the elements in a vector, there is a more general mechanism--known as 
iterators-- that we can use for the same purpose. 
Like pointers, iterators give us indirect access to an object.
*/
int main()
{
	string v;
	auto b = v.begin(), e = v.end();//b and e have the same type
	// b denotes the first element and e denotes one past the last element in v
	string s("some string");
	if(s.begin()!=s.end())
	{
		auto it = s.begin();// it denotes the first element in s
		*it = toupper(*it);//make that character uppercase
		//*it returns a reference to the element denoted by the iterator it.
		std::cout << s << std::endl;
		++it;
		std::cout << *it << std::endl;
	}
	/* 
	  pocess characters in s1 until we run out of characters or we
	  hit a whitespace.
	*/
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
		*it = toupper(*it);
	std::cout << s << std::endl;
	/* 
	  Iterator types
	*/
	vector<int>::iterator it3;//it3 can read and write vector<int> elements
	string::iterator it4;//it4 can read and write characters in a string
	it4 = ++s.begin();
	vector<int>::const_iterator it5;//it5 can read but not write elements
	string::const_iterator it6;//it6 can read but not write characters.
	/*
	  A const_iterator behaves like a pointer to const. Like a pointer 
	  to const, a const_iterator may read but not write the element it
	  denotes; an object of type iterator can both read and write. If a vector 
	  or a string is const, we may use only its const_iterator type.
	  With a nonconst vector or string, we can use either iterator or const_iterator.
	*/
	/*
	If the object is const, then begin and end return a const_iterator; if the object is not 
	const, then return iterator. However, to let us ask 
	*/
	vector<int> va;
	const vector<int> cv;
	vector<string>str_vec118 = {"ahasgsdg"};
	auto it111 = va.begin();//it111 has type vector<int>::iterator
	auto it112 = cv.begin();//it112 has type vector<int>::const_iterator
	auto it113 = va.cbegin();// it113 has type vector<int>::const_iterator
	auto it114 = cv.cbegin();
	vector<string>text = { "12djssjs","dsjd2h23","2jdhe","23udj" };
	auto it114514 = str_vec118.begin();
	if(!it114514->empty())std::cout<<"NMSL\n";
	//print each line in text up to the first blank line
	for (auto it = text.cbegin(); it != text.end() && !it->empty(); ++it)
		std::cout << *it << std::endl;
}