#include<iostream>
#include<sstream>
int main()
{
  std::istringstream in("Happy coding!");
  char c1=in.peek();
  char c2=in.get();
  char c3=in.peek();
  char c4=in.get();
  std::cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<"\n";//H H a a
  
  
}