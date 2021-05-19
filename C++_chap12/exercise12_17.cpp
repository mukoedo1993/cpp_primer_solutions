#include<memory>
#include<iostream>

int main()
{
	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
	typedef std::unique_ptr<int>IntP;

	//part a:
	//IntP po(ix); error: ix is an int, not a pointer.

	//part b:
	//IntP p1(pi);
	//error: pi doesn't point to a dynamic object...

	//part c:
	IntP p2(pi2);
	//Warning: pi2 might become a dangling pointer.

	//part d:
	//IntP p3(&ix);
	//error: &ix doesn't hold the address of a dynamic object.

	//part e:
	IntP p4(new int(2048));

	//part f:
	//IntP p5(p2.get());
	//error: p5 and p2 points to the same object. And this object will be deleted twice.

	//In order to prevent a dangling pointer, I suggest that: 
	pi2 = nullptr;

}