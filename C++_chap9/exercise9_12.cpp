/*Q1: Explain tyhe differences between the constructor that takes a container to copy and the constructor 
*that takes two iterators.
*/

/*A1: (1):The constructor that takes a container to copy requires the container type and the element type
* of the two containers are both match exactly.
*(2): The constructor that takes two iterators requires the element type of the source container must be compatible
*with the element type of the destiny container.
*/

/*Q2&A2:code

*
*/

#include<vector>
#include<list>
using std::vector; using std::list;
struct A {

};

struct B {
	A Ob;
	B(A a):Ob(a){}
};

//A could convert to B
int main()
{
	A Oa, Ob, Oc, Od;
	vector<A>early = { Oa,Ob,Oc,Od };
	vector<A>early1 = early;
	//vector<B>late1 = early;//error
	vector<B>late1_1(early1.begin(), early1.end());//case1:Ok
	list<A>late2(early1.begin(), early1.end());//case2:ok
	//Notice that in case 2, we not only change the type of element, but also the type of the container.
}