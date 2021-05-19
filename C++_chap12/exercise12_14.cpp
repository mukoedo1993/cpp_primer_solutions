#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;


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

//When we create a shared_ptr, we can pass an optional argument that points to a deleter function:
void f_yaju(destination& d)
{
	connection c = connect(&d);
	shared_ptr<connection>p(&c, end_connection);//end_connection is called to free p.
}

int main()
{
	std::cout << std::boolalpha;
	destination Changsha(189), * Hengyang = &Changsha;
	connection connec = connect(Hengyang),*connec1=&connec;
	f_yaju(*Hengyang);//f_taju only destroyed object c inside of class. It doesn't touch the connec object in the main block.


	std::cout << "connec's dest_ptr is deleted? " << (connec.dest_ptr == nullptr) << std::endl;//false
	end_connection(connec1);
	std::cout << "After calling disconnect function, is connec's dest_ptr is deleted? " << (connec.dest_ptr == nullptr) << std::endl;//true
}