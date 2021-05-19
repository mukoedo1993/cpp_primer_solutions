#include<iostream>
class Point {
	Point* heap;
	int x;
public:
	
	Point(int i=3):x(i),heap(nullptr){}
	void print() {
		std::cout << "x is" << x << std::endl;
	}
};

Point foo_bar(Point arg)
{
	Point global(3);
	Point local = arg, * heap = new Point(global);
	*heap = local;
	Point pa[4] = { local,*heap };
	return *heap;

}

int main()
{
	Point Ob1;
	Point Ob2(Ob1);
	Ob2.print();
}