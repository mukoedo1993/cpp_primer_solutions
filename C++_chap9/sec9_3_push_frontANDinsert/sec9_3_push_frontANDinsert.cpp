#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<fstream>
#include<sstream>
using std::string; using std::vector;
using std::cin; using std::list;

void print(vector<string> str,std::ofstream&of)
{
	for (vector<string>::iterator it = str.begin(); it != str.end(); it++)
	{
		of << *it << "; ";
	}
	
	of << ";\n";
}

void s_print(list<string> str, std::ofstream& of)
{
	for (list<string>::iterator it = str.begin(); it != str.end(); it++)
	{
		of << *it << "; ";
	}

	of << ";\n";
}


//push_front:ONLY in:
//1: list 2: forward_list 3: deque


int main()
{
	std::ofstream output("sec9_3_o2.txt");
	list<int>ilist;
	//add elements to the start of ilist
	for (size_t ix = 0; ix != 4; ++ix)
		ilist.push_front(ix);

	//insert:
	vector<string>svec = {"114go14"};
	list<string>slist = { "~Kiokio" };
	//equivalent to calling slist.push_front("Hello!");
	slist.insert(slist.begin(), "Hello!");
	
	//no push_front on vector but we can insert before begin()
	//warning: inserting anywhere but at the end of a vector might be slow

	svec.insert(svec.begin(), "hello!");
	output << "Insert hello in the position before the svec.begin():  ";
	output<< svec[0] << "; " << svec[1]<<std::endl<<std::endl;//hello!; 114go14

	//Inserting a range of Elements

	/*The arguments to insert that appear after the initial iterator argument
	* are anagolous to the container constructors that take the same parameters.
	*The version that takes an element count and a value adds the specified number of
	*elements before the given position:
	*/

	//The version that takes an element count and a value adds the specified number of
	//identical elements before the given position:
	svec.insert(svec.end(),10,"Anna");
	output << svec[2] << std::endl;

	vector<string>v = { "quasi","simba","frollo","scar" };
	output << "The v is:";
	print(v, output);
	//insert the last two elements of v at the beginning of slist

	slist.insert(slist.begin(), v.end() - 2, v.end());
	output << "after insert the slist is:";
	s_print(slist, output);


	//run_time error: iterators denoting the range to copy from
	//must not refer to the same container as the one we are changing
	slist.insert(slist.end(), { "these","words","will","go","at","the","end" });
	output << "\nafter insert the slist is:";
	s_print(slist, output);
	//Also, we can use the value returned by insert to repeadtedly insert elements at a spe
	//-cified position in the container:
	list<string>lst;
	auto iter = lst.begin(); string word; string mkft;
	while (std::cin >> word)
	{
		iter=lst.insert(iter, word);
		//returns an element to the element that was added.
		if (word == "END")
		{
			output << "The last one you inter is: "<<mkft<<std::endl;
			break;
		}
		mkft = word;
	}

}