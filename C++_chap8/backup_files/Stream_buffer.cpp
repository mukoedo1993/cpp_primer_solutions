//IO operations
//assginment 1: Formatting data--stream class
//assginment 2: communicating data to external devices--streambuffer(a internal module of stream)
#include<iostream>
#include<fstream>
#include<algorithm>
#include<tuple>


int main()
{
	

	std::cout << 34;//cout is responsible for assginment 1.
	std::streambuf* pbuf =std::cout.rdbuf();//pbuf is responsible for assginment 2.
	//rdbuf returns a pointer to the stream buffer object currently associated with the stream.


	//Attention!! ofstream's constructor has been marked as explicit.
	std::ostream myCout(pbuf);//Create another ostream which has the same
	//stream buffer as cout.
	
	myCout << 34;//34 will be printed out in standout

	myCout.setf(std::ios::showpos);//show positive sign
	myCout.width(20);//20 blanks
	myCout << 12 << std::endl;//result:                  +12
	std::cout << 12 << std::endl;//result:12

	std::ofstream of("Mylog.txt");//Create a file named Mylog.txt
	std::streambuf* origBuf = std::cout.rdbuf();
	

	std::cout.rdbuf(of.rdbuf());
	std::cout << "Hello!" << std::endl;//Mylong.txt has Hello!
	//Redirecting

	std::cout.rdbuf(origBuf);
	//sets the object pointed by origBuf as the stream buffer associated with the stream and clears the error state flags.

	std::cout << "Good Bye!" << std::endl;//stdout: Goodbye

	//Stream buffer iterator:
	typedef std::istreambuf_iterator<char> istr_it;
	istr_it i(std::cin);
	typedef std::ostreambuf_iterator<char> istr_ot;
	istr_ot o(std::cout);

	//assignment 3:
	while (*i != 's')
	{
		*o = *i;
		++o;
		++i;
	}

	//alternative way to do assignment 3 except the exit letter for 's'.
	copy(istr_it(std::cin), istr_it(),istr_ot(std::cout));
}