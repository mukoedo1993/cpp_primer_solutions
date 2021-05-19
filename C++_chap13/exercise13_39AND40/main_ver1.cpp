#include"StrVec_ver4.h"
using std::allocator;
using std::string;
using std::vector;


int main()
{
	


	std::initializer_list<string>v_st = { "yaju","senpai","teikoku","N","M","S","L" };

	StrVec v_str(v_st);

	v_str.resize(13, string("yiyiyo"));
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.resize(2,"");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.reserve(15);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	v_str.reserve(2);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	
	v_str.resize(28, "dojo");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	StrVec getVec(std::cin);
	std::cout << "size is:" << getVec.size() << std::endl;
	for (auto it = getVec.begin(); it != getVec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << getVec.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;




	return 0;
}