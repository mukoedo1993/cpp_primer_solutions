#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int find_char(const string& s, char c,string::size_type& ctr)
{
	int t = s.size(); int flag = 1; ctr = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			if (t == s.size())
			{
				t = i;
			}
			ctr++;
			//cout << ctr<<"; ";
		}
	}
	return t;
}
/*
When we use parameters that are const, it is important to remember the discussion
of top-level const from sec_2.4.3. As we saw in that section, a top-level const is
one that applies to the object itself:
*/
void fcn(const int i)
{
	cout << i << endl;
}
void reset(int* i)
{
	i = 0;
}
void reset(int& i)
{
	i = 0;
}
bool is_sentence(const string& s)
{
	//If there's a single period at the end of s, then s is a sentence.
	string::size_type ctr = 0;
	return (find_char(s, '.', ctr) == s.size() - 1 && ctr == 1);
}
int main()
{
	const int ci = 42;//we cannot change ci;const is top-level
	int i1 = ci;//ok: when we copy ci, its top-level const is ignored
	int* const p = &i1;//const is top-level; we can't assign to p
	*p = 0;//ok:changes through p are allowed; i is now 0
	/*
	Just as in any other initialization, when we copy an argument to initialize a parameter,
	top-level consts are ignored. As a result, top-level const on parameters are ignored.
	We can pass either a const or a nonconst object to a parameter that has a top-level const:
	*/
	fcn(i1);//i as a nonconst int, could initialize the parameter of fcn.
	/*
	Pointer or Reference Parameters and const
	Because parameters are initialized in the same way that variables are initialized, it 
	can be helpful to remember the general initialization rules. We can initialize an object
	with a low-level const from a nonconst object but not vice versa, and a plain reference must be initialized
	from an object of the same type.
	*/
	int i = 42;
	const int* cp = &i;//ok: but cp can't change i
	const int& r = i;//ok: but r can't change i
	const int& r2 = 42;//ok:
	//int* p = cp;//error: types of p and cp don't match
	//int& r3 = r;//error: types of r3 and r don't match
	// int &r4=42;//error: can't initialize a plain reference from a literal
	int i3 = 0;string::size_type i4 = 0;
	const int ci3 = 0;
	string::size_type ctr3 = 0;
	reset(&i3);
	//reset(&ci3);//const int cannot be used to initialize an int.
	reset(i3);
	//reset(ci3);
	string s1 = "Russland"; string s_1_1 = "Wir sind verloren.";
	int t=find_char( s1, 's',i4 );
	cout << "It appears at the location: " << t << " at the first time." << endl;
	cout << "it appears " << i4 << "time(s) in total." << endl;

	/*
	It is a somewhat common mistake to define parameters that a function does not change
	as (plain) references. Doing so gives the function's caller the misleading impression that the function
	might change its argument's value.
	*/
	cout << std::boolalpha;
	cout << is_sentence(s1) << endl << is_sentence(s_1_1);
}