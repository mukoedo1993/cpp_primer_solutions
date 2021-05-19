#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;
void f()
{
	shared_ptr<int>sp(new int(42));//allocate a new object
	//code that throws an exception that is not caught inside f
	//shared_ptr freed automatically when the function ends
}

void f1()
{
	int* ip = new int(42);//dynamically allocated a new object
	//code that throws an exception that is not caught inside f
	delete ip;//free the memory before exiting
}
//for f1:
//If an exception happens between the new and the delete, and is not
//caught inside f, then this memory can never be freed. There is no 
//pointer to this memory outside the function f1. Thus, there is
//no way to free this memory.

struct destination
{
	destination()
	{

	}
	destination(int k) :dest(k)
	{

	}
	int dest=189;
	
};

struct connection
{
	std::string connct="";
	destination* dest_ptr=nullptr;
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

void disconnect(connection &Ob1)
{
	delete Ob1.dest_ptr;
	Ob1.dest_ptr = nullptr;
}


void f2(destination& d)//other parameters
{
	//get an connection; must remember to close it when done
	connection c = connect(&d);
	std::cout << "Let's diconnected! Our destination was: " << d.dest << std::endl;
	//use the connection
	//If we forget to call disconnect before exiting f2, there will be no way to close c.
	disconnect(c);

}

void end_connection(connection* p) { disconnect(*p); }

//When we create a shared_ptr, we can pass an optional argument that points to a deleter function:
void f_yaju(destination& d)
{
	connection c = connect(&d);
	shared_ptr<connection>p(&c, end_connection);
}

int main()
{
	std::cout << std::boolalpha;
	f();
	f1();
	destination Changsha(189), *Hengyang=&Changsha;
	destination New_York(839), * LA = &New_York;
	connection connec = connect(Hengyang);
	f2(*Hengyang);
	
	std::cout <<"connec's dest_ptr is deleted? "<< (connec.dest_ptr == nullptr) <<std::endl;//false
	disconnect(connec);
	std::cout << "After calling disconnect function, is connec's dest_ptr is deleted? " << (connec.dest_ptr == nullptr) << std::endl;//true
}