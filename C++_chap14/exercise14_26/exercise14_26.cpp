#include"String.h"//line 22 to line 32 for this question
#include"StrBlob_StrBlobPtr.h"
int main()
{
char S1[7]="object";
char S2[8]="another";
String Str1(S1);
 String Str1_(S2);

 const String Str2=Str1_;
  
StrBlob Blb1({"hehe","chao"});const StrBlob cBlb2({"ni","masland"});
 StrBlob Blb2({"ni","masland"});
StrBlobPtr ptr1(Blb1);const StrBlobPtr cptr2(Blb2);
 
std::cout<<"Str1[1] is: "<<Str1[1]<<"\n";
std::cout<<"Str2[1] is: "<<Str2[1]<<"\n";
std::cout<<"Blb1[1] is: "<<Blb1[1]<<"\n";
std::cout<<"cBlb2[1] is: "<<cBlb2[1]<<"\n";
std::cout<<"ptr1[1] is: "<<ptr1[1]<<"\n";
std::cout<<"cptr2[1] is: "<<cptr2[1]<<"\n";


}