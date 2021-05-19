#include"Vec_ex16_16.h"
#include"ex16_16_implementation.h"
#include"sales_data.h"

//Test 1: using library class string:
//Test 2: using built-in type int:
//Test 3: using user-defined type sales_data:
int main()
{
	



    
	


//test 1:
    	std::initializer_list<string>v_st = { "yaju","senpai","teikoku","N","M","S","L" };

	Vec<string> v_str(v_st);

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

	Vec<std::string> getVec(std::cin);
	std::cout << "size is:" << getVec.size() << std::endl;
	for (auto it = getVec.begin(); it != getVec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << getVec.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;


//test 2:
    Vec<int>v_i({2,3,14,20,-16});
	std::cout<<v_i.size()<<std::endl;
	v_i.resize(12,1);
	std::cout<<*(v_i.begin())<<std::endl;
  

  //test 3:
  Sales_data sales(std::string("kimura"),13);
  Vec<Sales_data>v_salesdata(std::initializer_list<Sales_data>{sales});
  std::cout<<*(v_salesdata.begin())<<std::endl;
  v_salesdata.resize(13);
  auto it=v_salesdata.begin();
  it++;
  std::cin>>*it;
  std::cout<<*it<<std::endl;
}


/*


yaju senpai teikoku N M S L yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo 
v_str.capacity(): 13


yaju senpai 
v_str.capacity(): 2


capacity is: 2
Reserve 15
yaju senpai 
v_str.capacity(): 15v_str.size(): 2


capacity is: 15
yaju senpai 
v_str.capacity(): 15yaju senpai dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo 
v_str.capacity(): 28v_str.size(): 28


ni ma si le 
le
q
size is:2
ni ma si le le 
v_str.capacity(): 2


5
2
bookNo is:kimura
 units sold: 13
revenue is: 1053

mikasa 13 1.8
bookNo is:mikasa
 units sold: 13
revenue is: 23.4


*/
