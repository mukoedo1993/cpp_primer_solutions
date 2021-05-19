#include<vector>
#include<map>
#include<utility>//pair
#include<set>
#include<iostream>
#include<fstream>
#include<iterator>
using std::vector;
using std::set;
using std::map; using std::string;
using std::pair;
int main()
{

	/*The insert members add one element or a range of elements. Because map and set 
	*(and the corresponding unordered types) contain unique keys, inserting an element
	*that is already present has no effect.
	*/

	/*
	*Adding elements into a map, we must remember that the element type is a pair. 
	*Often, we don't have a pair object we want to insert. Instead, we create a pair 
	*in the argument list to insert.
	*/

	//four ways to add word to word_count.
	map<string, size_t>word_count;
	string word = "nmsl";
	word_count.insert({word,1});
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));
	//As we have seen, under the C++11, the easiest way to create a pair is
	//to use brace initialization inside the argument list.


	//tesing the return from insert
	/*
	* The value returned by insert(or emplace) depends on the container type and
	* the parameters.
	*1: The first member of the pair is an iterator to the element with the given key.
	*2: The second is a bool indicating whether that element was inserted, or was already 
	*there.
	*/
	std::ifstream input("sec11_3_2i.txt");
	std::ofstream output("sec11_3_2o.txt"),output1("sec11_3_2o1.txt");
	if (!input.is_open())exit(-1); 
	word_count.clear();
	 word.clear();
	std::istream_iterator<string> str_int(input),eof;
	
	
	while (str_int != eof)
	{
		word = *str_int;
		//inserts an element with key equal to word and value 1
		//if word is already in word_count, insert does nothing.
		auto ret = word_count.insert({ word,1 });
		if (!ret.second)//word has already in word_count
			++ret.first->second;//increment the counter
		str_int++;
	}
	for (auto it : word_count)
	{
		output << "The word " << it.first << " occurs " << it.second << "time(s).\n";
	}
	output.close();

	//Adding elements to the multiset or multimap;
	std::multimap<string, string>authors;
	//adds the first element with teh key Barth
	authors.insert({ "Barth","Sot-weed" });
	//ok: adds the second element with the key Barth
	authors.insert({ "Barth","Lost in the Funhouse" });
	//For  the containers that allow multiple keys, the insert operation that 
	//takes a single element returns an iterator to the new element.
	for (auto it= authors.begin();it!= authors.end();it++)
	{
		output1 << it->second << std::endl;
	}
}