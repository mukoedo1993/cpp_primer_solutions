#include<vector>
#include<iterator>
using std::vector;
#include<set>
using std::set;
using std::multiset;
using std::string;
#include<algorithm>
#include<functional>
int main()
{
	vector<string>v = {"ttk","lmn"};
	multiset<string>c = {"ttlk","rbqsl"};
	
	//part 1:
	copy(v.begin(), v.end(), inserter(c, c.end()));
	//build succeed, everything is ok.

	//part 2:
	//copy(v.begin(), v.end(), back_inserter(c));
	//push_back is not a member of multiset<string>
	//So we cannot use it.

	//part 3:
	copy(c.begin(), c.end(), inserter(v, v.end()));
	//OK.
	//We can use an algorithm(i.e., copy) to read element of a multiset.
	//We could insert sth into a vector.

	//part 4:
	copy(c.begin(), c.end(), back_inserter(v));
	//OK.
	//Vector has the member function push_back().
}