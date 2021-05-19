#include <iostream>
#include <sstream>
 
int main()
{
    char x[20];
    std::istringstream stream("Hello World");
    stream.read(x, sizeof x);//http://www.cplusplus.com/reference/istream/istream/read/
    std::cout << "Characters extracted: " << stream.gcount();//11
    //It returns number of bytes read from the stream is by the last call to an unformatted read 
    //operation.
}