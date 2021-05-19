#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;

void process(shared_ptr<int>ptr)
{

}

int main()
{
	auto p = new int();
	auto sp = make_shared<int>();

	// part a:
	process(sp);//It will pass.

	//part b:
	//process(new int());//It won't pass.
	//The compiler cannot convert a plain pointer which points to int to a shard_ptr<int>.

	//part c:
	//process(p);//It won't oass.
	//The compiler cannot convert a plain int pointer to a shared_ptr<int>

	//part d:
	process(shared_ptr<int>(p));
	//It is legal but dangerous. The p will become a dangling pointer without the line below: 
	p = nullptr;


}