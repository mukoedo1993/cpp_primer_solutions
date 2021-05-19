
#include<iterator>
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<fstream>

using std::list; using std::vector;
//using std::iterator; 
 using std::endl;
/*
*1: It is important to understand that we we call inserter(c,iter),
*we get an iterator that, when we used successively, inserts elements
*ahead of the element originally denoted by iter.
*/

/*
//inserter(c,iter)
*1: it=c.insert(it,val);//it points to the newly added element
*2: ++it;//increment it so that it denotes the same element as before.
*
*/

int main()
{
	std::ofstream output("sec10_4_1ANDex10_27o.txt");
	list<int>lst = { 1,2,3,4 };
	list<int>lst2, lst3;
	output << "list=== { 1,2,3,4 }:\n";
	//after copy completes, lst2 =={4,3,2,1}
	copy(lst.begin(), lst.end(), front_inserter(lst2));//similar to push_front one by one
	output << "lst2: by by one:\n"; auto it = lst2.begin();
	while (it!=lst2.end())
	{
		output << *it << "; ";
		it++;
	}
	output << endl << endl;
	//after copy completes, lst3 =={1,2,3,4}
	copy(lst.begin(), lst.end(), inserter(lst3,lst3.begin()));//similar to insert
	
	output << "lst3: by by one:\n"; auto it1 = lst3.begin();
	while (it1 != lst3.end())
	{
		output << *it1 << "; ";
		it1++;
	}

	//exercise 10_27:
	//http://www.cplusplus.com/reference/algorithm/unique_copy/
	vector<int>veci = { 1,4,4,4,8,7,8,16,13,15,15,8,16 };
	list<int>lsti;

	 
	 output << "\n\nexercise10_27:\n";
	 output << "The original elements are:\n";

      for (auto it__ : veci)
	 {
		  output << it__ << "; ";
	 }

	unique_copy(veci.begin(), veci.end(), back_inserter( lsti));
	 auto iti = lsti.begin();
	 output << "YThe new list is:\n";
	while (iti != lsti.end())
	{
		output<< *iti << "; ";
		iti++;
	}
	output << endl;
	output.close();
}
