//erase on a key returns the number of elements removed

//3 ways:
/*1: c.erase(k): removes every element with key k from c. Return size_type
* indicating the number of elements removed.
*
*2:c.erase(p): removes the element denoted by the iterator p from c.
*p must reter to an actual element in c; it must not be equal to c.end().
* Returns an iterator to the element after p or c.end() if p denotes the last 
*elements in c.
*3: c.erase(b,e): removes the elements in the range denoted by the iterator pair b,e.
*Returns e.
*/
#include<map>
using std::map;
#include<iostream>
using std::string;
int main()
{
	map<string, int>word_count;
	word_count["yaju"] = 4;
	word_count["senpai"] = 89;
	word_count["senpai"] = 13;
	word_count["Hunan"] = 86731;
	string str = "Fusiang";
	word_count.insert( make_pair(str, 23));
	string removal_word = "sj";
	string removal_word1 = "Hunan";
	//erase on a key returns the number of elements removed
	if (word_count.erase(removal_word))
		std::cout << "ok: " << removal_word << "removed\n";
	else
		std::cout << "oops: "<<removal_word<<"not found!\n";
	if (word_count.erase(removal_word1))
		std::cout << "ok: " << removal_word1<< " removed\n";
	else
		std::cout << "oops: " << removal_word1 << "not found!\n";

	std::cout << "\nyaju: "<<word_count.at("yaju");
}