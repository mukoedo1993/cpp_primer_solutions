/*Each output stream manages a buffer, which it uses to hold the data that
*the program reads and writes.
*
*/

/*Wrting data
*
*
*/


#include<iostream>
using std::cin; using std::cout;
int main()
{
	std::cout << "hi!" << std::endl;//writes hi and a newline, then flushes the buffer
std::cout << "hi!" << std::flush;//writes hi, then flushes the buffer; adds no data
std::cout << "hi!" << std::ends//write hi and a null. then flushes the buffer
<< "i.";


//If we want to flush after every output,we can use the unitbuf manipulator. This manipulator 
//tells the stream to do a flush after evry subsequent write.

std::cout << std::unitbuf;//all writes will be flushed immediately
//any output is flushed immediately, no buffering
std::cout << std::nounitbuf;//returns to normal buffering

/*There are two overloaded versions of tie.
*One version: takes no argument and returns a pointer to the output stream, if any, to which this
* object is currently tied.
*
*Second version: takes a pointer to an ostream and ties itself to that ostream. That is, x.tie(&o)
*ties the stream x to the output stream o.
*We can tie either an istream or an ostream object to another ostream.
*
*/


//We can tie either an istream or an ostream object to another ostream:
cin.tie(&cout);//illustration only; the library ties cin and cout for us.

//old_tie points to the stream (if any) currently tied to cin
std::ostream* old_tie = cin.tie(nullptr);

//ties cin and cerr; not a good idea because cin should be tied to cout
cin.tie(&std::cerr);

cin.tie(old_tie);//reestablish normal tie between cin and cout.

}
