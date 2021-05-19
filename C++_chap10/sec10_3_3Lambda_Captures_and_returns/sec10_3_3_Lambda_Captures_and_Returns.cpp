#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"elims_printPAC_ver1_1.h"
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;

//capture by Value:
void fcn1()
{
	size_t v1 = 42;//local variable
	//copies v1 into the callable object named f
	auto f = [v1] {return v1;  };
	v1 = 0;
	auto j = f();//j is 42; f stored a copy of v1 when we created it.
	std::cout << "for fcn1, the result is: " << j << endl; //result: 42
}


//
void fcn2()
{
	size_t v1 = 42;//local variable
	//the object f2 contains a reference to v1
	auto f2 = [&v1] {return v1; };
	v1 = 0;
	auto j = f2();
	std::cout << "for fcn2, the result is: " << j << endl;//result: 0
}

void fcn3()
{
	size_t v1 = 42;//local variable
	//f can change the value of the variables if captures
	auto f = [v1]()
		mutable //If this line is commented, then we will get the error...
		//says that the expression must be a modifiable value.
	{return ++v1; };
	v1 = 0;
	auto j = f();//j is 43.
}

void fcn4()
{
	size_t v1 = 42;//local variable
	//v1 is a reference to a nonconst variable
	//we can change that variable through the reference inside f2
	auto f2 = [&v1] {return ++v1; };
	v1 = 0;
	auto j = f2();//j is 1
}

void biggies(vector<string> words,vector<string>::size_type sz,std::ostream &os=cout,char c=' ')
{

	auto it = partition(words.begin(), words.end(), [sz](const string& a)
		{//if (a.size() > sz)cout << "dame!" << std::endl;
			return a.size() < sz;
		});
	//std::cout <<"first blood" <<*it << endl;
	for_each(it, words.end(), [&os, c](const string& s) {os << s << c; });

}

void biggies_ipct(vector<string> , vector<string>::size_type , std::ostream&, char ); 

//reference captures are sometimes necessary.
int main()
{
	//Part 1:
	fcn1();
	fcn2();

	//Part 2:
	
	std::ifstream input("sec10_3_3i.txt");
	if (!input.is_open())return -1;
	string str; vector<string>vsec;



	std::ofstream output("sec10_3_3o.txt");
	std::ofstream& output1 = output;
	
	

	int cnt = 0;
	int i = 0;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		string str2;
	
		
		
			while (Ob1 >> str2)
			{
				if (cnt == 0)
				{
					i = stoi(str2);
					//cout << "i is: " << i << ".";
					cnt = 1;
					break;
				}
				else
				{
					vsec.push_back(str2);
					//cout << str2 << std::endl;
				}
			}
		
	}
	

	auto vsec1 = vsec;;
	//cout << "i is" << i << endl;
	//cout << vsec.size() << endl;
	output1 << "The words whose length are larger then " << i << " are:\n";
	biggies(vsec, i, output1);
	output1 << "\nRepeat the test for the implicit captured part:\n";
	biggies_ipct(vsec1, i, output1,' ');
	

	//implicit captures:
	/*Rather than explicitly listing the variables we want to use from
	* the enclosing function, we can let the compiler infer which variables we use
	*from the code in the lambda's body.
	*
	*/

	//e.g,1: sz_ipct implicitly captured by value
	auto sz_ipct = 3;
	auto wc = find_if(vsec.begin(), vsec.end(), [=](const string& s) {return s.size() > sz_ipct; });

	


	input.close();
	output.close();
	output1.close();
}



//implicit captured version of biggies:

//If we want to cpature some variables by value and others ,we can mix implicit and explicit captures:
void biggies_ipct(vector<string> words, vector<string>::size_type sz, std::ostream& os , char c)
{

	auto it = partition(words.begin(), words.end(), [sz](const string& a)
		{
			return a.size() < sz;
		});
	
	//other processing as before

	//implicit captured reference &os, explicit value c.
	for_each(it, words.end(), [&, c](const string& s) {os << s << c; });

	//implicit captured reference &os, explicit value c.
	//for_each(it, words.end(), [=, &os](const string& s) {os << s << c; });



}