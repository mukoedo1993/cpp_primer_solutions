/*Associative containers additional type aliases
*
*1: key_type: type of the key for this container type
*2:mapped_type: Type associated with each jey: map types only
*3: value_type: for sets, same as the key_type
*For maps, 
*!!!!!!!!!!!!!!!!
*pair<const key_type,mapped_type>
*
*/


//1: Key_type and the value_type are the same for the set types.
//2: The values held in a set are the keys.
//3: As with the sequential containers, we use the scope operator to fetch a type member,
//e.g., map<string,int>::key_type
//4: Only the map types (unordered_map, unordered_multimap, multimap and map) define mapped_type.
#include<string>
#include<set>
#include<map>
#include<iostream>
using std::set; using std::map; using std::string;
int main()
{
	set<string>::value_type v1;//v1 is a string
	set<string>::key_type v2;//v2 is a string
	map<string, int>::value_type v3;//v3 is a pair  v3.second==0
	map<string, int>::key_type v4;//v4 is a string
	map<string, int>::mapped_type v5;//v5 is an int

	map<string, int> word_count;
	word_count["Tom"] = 10;
	word_count["Amily"] = 9;
	word_count["Tojo-"] = 13;
	word_count["kinkisharyo"] = 9;


	// get an iterator to an element in word_count
	auto map_it = word_count.begin();
	//*map_it is a reference to a pair<const string, size_t>object
	std::cout << map_it->first;//prints the key for this element
	//map_it->first = "New Key!";//error: key_values are const!
	++map_it->second;//ok: we can change the value through the iterator

	//Note:
	//1: When we dereference an iterator, we get a reference to a value of the container's
	//value_type.
	//2: Iterators for sets are const
	set<int>iset = { 0,2,4,6,8,10,12,14,16,18 };
	set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end()) {
		set_it++;//it is OKAY, it is NOT top-end const, only low-end.
		std::cout << *set_it<<std::endl;//result: 1 
	}
	//Note:
	//Although the set types define both the iterator and const iterator types,
	//both types of iterators give us read-only access to the elements in the set.


	//Iterating across an Associative Container
	//get an iterator positiosned on the first element
	auto map_it1 = word_count.cbegin();
	//compare the iterator to print the element key--value pairs.
	while (map_it1 != word_count.cend())
	{
		std::cout << map_it1->first << " occurs " <<
			map_it1->second << " times" << std::endl;
		map_it1++;//increment the iterator to denote the next element
	}

	//Associative containers can be used with the algorithms that read elements.
	//However, many of these algorithms search the sequence. Because elements in an 
	//associative container can be found (quickly) by their key, it is almost always
	// a bad idea to use a generic search algorithm.

	//In practice, if we do so at all, we use an associative container with the algorithm 
    //either as the source sequence or as a destination.

	//Similarly, we can call inserter to bind an insert iterator to an associative container.
	//Using inserter, we can use the associative container as a destination for another algorithm.






	//exercise 11.16:
	int intv = 2;
	 string con_str = "ntl";
	 map<string, int>map_i_str;
	
	map_i_str["kkt"] = 23;
	map< string, int>::iterator ex11_16_it = map_i_str.begin();
	ex11_16_it->second = 16;
	std::cout << "\n\nexercise 11.16's result is: " << ex11_16_it->second;
	

}