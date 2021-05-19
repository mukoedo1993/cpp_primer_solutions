#include<memory>
#include<iostream>
using std::make_shared;
using std::unique_ptr;
using std::string;

struct destination
{
	destination()
	{

	}
	destination(int k) :dest(k)
	{

	}
	int dest = 189;

};

struct connection
{
	std::string connct = "";
	destination* dest_ptr = nullptr;
	connection(destination* dst)
	{
		dest_ptr = new destination(*dst);
	}
	connection()
	{
		connct = "Connected!";
	}

};

connection connect(destination* Ob1)
{
	connection Ob_yaju(Ob1);
	return Ob_yaju;
}

void disconnect(connection& Ob1)
{
	delete Ob1.dest_ptr;
	Ob1.dest_ptr = nullptr;
}

void end_connection(connection* p) { disconnect(*p); }

void f_unique_yaju(destination& d)
{
	connection c = connect(&d);
	unique_ptr<connection, decltype(end_connection)*>
		p(&c, end_connection);
	//use the connection
	//when f exits, even if by an exception, the connection will be properly closed.
}

//Unlike shared_ptr, threr is no library function comparable to make_shared that
//returns a unique_ptr. Instead, when we define a unique_ptr, we bind it to a pointer returned
//by new.



//Passing and Returning unique_ptrs
	//There is one exception to the rule that we cannot copy a unique_ptr: we can copy or assign
	//a unique_ptr that is about to be destroyed. The most common example is when we return a unique_ptr
	//from a function:
/*clone and clone1 are equivalent function:*/
unique_ptr<int> clone(int p)
{
	unique_ptr<int>p1 ( new int(p));
	//We can return a copy of a local object
	return p1;
}

unique_ptr<int> clone1(int p)
{
	return unique_ptr<int>(new int(p));
	//ok:Alternatively, we explicitly create a unique_ptr<int> from int*
}

int main()
{
	unique_ptr<double>p1;//unique_ptr that can point at a double.
	unique_ptr<int>p2(new int(42));//p2 points to int with value 42.

	//Because a unique_ptr owns the object to which it points, unique_ptr deos not
	//support ordinary copy or assignment:
	unique_ptr<string>p3(new string("Stegosaurus"));
	//unique_ptr<string>p4(p3);//error: no copy for unique_ptr
	unique_ptr<string>p5;
	//p5 = p3;//error: no assign for unique_ptr



	//Although we can't copy or assign a unique_ptr, we can transfer ownership from one (nonconst) unique_ptr
	//to another by calling release or reset.

	//u.release()
	//Relinquishes control of the pointer u had held; returns the pointer u had held and makes u null.
	unique_ptr<string>p6(p3.release());//releases makes p3 null
	std::cout << "*p6 is: " << *p6<<std::endl<<std::endl;
	unique_ptr<string>p7(new string("Trex"));



	//transfers ownership from p7 to p6
	p6.reset(p7.release());
	//u.reset(q)
	//Deletes the object to which u pointsl If the built-in pointer q is supplied, makes u point to the object.
	//Otherwise,(i.e. q==nullptr) makes u null.
	//NOTE: 1: release returns a plain pointer p7 had managed.
	//NOTE 2: p6 takes the plain pointer, and points to what p7 had pointed. p7 is now a nullptr.
	std::cout << "Now, *p6 is: " << *p6 << std::endl << std::endl;


	unique_ptr<string>p8(new string (string("coup_de'tat")));
	unique_ptr<string>p9(new string(string("coup_de'tats")));
	//p8.release();//error: p8 won't free the memory and we've lost the pointer
	auto p10 = p8.release();
	std::cout << "*p10 is: " << *p10 << std::endl;//ok, but we must remember to delete (p10)
	
	int* mkft1 = nullptr;
	delete mkft1;

	//Like shared_ptr, by default, unique_ptr uses delete to free the object to which a unique_ptr points.
	//As with shared_ptr points. As with shared_ptr, we can override the default deleter in a unique_ptr.

	//To override it:
	//Template:
	//p points to an object of type objT and uses an object of type delT to free that object.
	//It will call an object named fcn of type delT
	//unique_ptr<objT, delT>p(new objT, fcn);
	//See the new example in f_unique_yaju() above:

	std::cout << std::boolalpha;
	destination Changsha(189), * Hengyang = &Changsha;
	connection connec = connect(Hengyang), * connec1 = &connec;
	
	f_unique_yaju(*Hengyang);//f_taju only destroyed object c inside of class. It doesn't touch the connec object in the main block.


	std::cout << "connec's dest_ptr is deleted? " << (connec.dest_ptr == nullptr) << std::endl;//false
	end_connection(connec1);
	std::cout << "After calling disconnect function, is connec's dest_ptr is deleted? " << (connec.dest_ptr == nullptr) << std::endl;//true
}
