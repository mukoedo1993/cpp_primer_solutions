#include<iostream>

struct T{
 std::string mem1;
 int m2;

};

void swap(T v1,T v2)
{
    using std::swap;
    swap(v1.mem1,v2.mem1);
}


int main()
{
    //exercise18_18:
   //It calls the std::swap(int,int) if mem1 is an int type member.
   //It calls the std::swap(string,string), if mem1 is an string type member.
}
//exercise18_19:
//What if the call to swap was std::swap(v1.mem1,v2.mem1)?
//Soln: it will restrain the swap we might choose. We will not be able to use the 
//user_defined version, which might be better. Otherwise, we could only use std::swap<class T> type
//when system doesn't offer a special institation here...