#include<iostream>
#include<memory>
#include<string>

class String {
public:String(char* c_string) { c_str = std::string(c_string); }
	  String() { c_str = "\0"; }//default constructor
	  std::string print()
	  {
		  return c_str;
	  }
	  size_t size()
	  {
		  return c_str.size();
	  }
private: std::string c_str;

};

int main()
{
	char k[5]  ="dojo";
	String Ob1,Ob2(k);
	std::allocator<String>alloc;
	auto it=alloc.allocate(2);
	auto it1 = it+1;
	alloc.construct(it, Ob1);
	alloc.construct(it1, Ob2);
	std::cout << it->print() <<" "<<it->size()<< std::endl;//null 0
	std::cout << it1->print() << " " << it1->size() << std::endl;//dojo 4
	alloc.destroy(it);
	alloc.destroy(it1);
	alloc.deallocate(it, 2);
}