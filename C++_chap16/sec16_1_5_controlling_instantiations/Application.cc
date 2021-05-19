//Application.cc
#include"Blob_chap16_1_5.h"

//instantion declaration and definition

//extern template class Blob<std::string>;//declaration
//template int compare(const int&,const int&);//definition

//These template types must be instantiated elsewhere in the program
 extern template class Blob<std::string>;//declaration
  extern template bool compare(const int&,const int&);
//We need to define line 9 and line 10's code elsewhere:

   vector<std::string>v1={"sjd","sdkjdfv","sdj"};
  Blob<std::string> sa1(v1.begin(),v1.end()),sa2(v1.begin(),v1.end());//instantiation will appear elsewhere
   Blob<int>a1={1,2,-4,6,-13,23};
  Blob<int>a2(a1);//copy constructor instantiated in this file
const int i=compare(a1[0],a2[0]);


int main()
{
  auto j=i;
  std::cout<<j<<" "<<std::endl;
}

/*
The file Application.o will contain instantiations for Blob<int>, along with the
initializer_list and copy constructors for that class. The compare<int>function and
Blob<std::string>class will not be instantiated in that file.
*/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Ruuning it on the terminal: our results are:
/*
(base) zcw@mukoedo1993:~/C++chap16$ g++ Application.cc templateBuild.cc Blob_chap16_1_5.h
(base) zcw@mukoedo1993:~/C++chap16$ ./a.out
compare!!!
0
*/