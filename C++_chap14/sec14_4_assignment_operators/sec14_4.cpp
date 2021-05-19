//We made relation operators in this main file.
#include"StrBlob_StrBlobPtr.h"
#include"StrVec_ver4.h"
#include"String.h"
#include<algorithm>
bool operator==(const StrBlob&lhs, const StrBlob&rhs)
{
    vector<string>v1=*(lhs.data.get());
    vector<string>v2=*(rhs.data.get());
    return(v1==v2);
}

bool operator!=(const StrBlob&lhs, const StrBlob&rhs)
{
    return !(lhs==rhs);
}

bool operator<(const StrBlob&lhs, const StrBlob&rhs)
{
    if(lhs==rhs)return false;
    vector<string>v1=*(lhs.data.get());
    vector<string>v2=*(rhs.data.get());
    return(v1.size()<v2.size());
}

bool operator>(const StrBlob&lhs, const StrBlob&rhs){
    if(lhs<rhs)return false;
    return !(lhs==rhs);}



bool operator==(const StrBlobPtr&lhs, const StrBlobPtr&rhs)
{
    vector<string>lhs1=*(lhs.wptr.lock().get());
    vector<string>rhs1=*(rhs.wptr.lock().get());
    for_each(lhs1.cbegin(),lhs1.cend(),[](string str)->void{std::cout<<str<<" ";});
    std::cout<<std::endl;
    for_each(rhs1.cbegin(),rhs1.cend(),[](string str)->void{std::cout<<str<<" ";});
    return (lhs1==rhs1);
}

bool operator!=(const StrBlobPtr&lhs, const StrBlobPtr&rhs)
{
    return !(lhs==rhs);
}

bool operator<(const StrBlobPtr&lhs, const StrBlobPtr&rhs)
{
    vector<string>lhs1=*(lhs.wptr.lock().get());
    vector<string>rhs1=*(rhs.wptr.lock().get());
    if(lhs1.size()<rhs1.size())return true;
    return false;
}

bool operator>(const StrBlobPtr&lhs, const StrBlobPtr&rhs)
{
     vector<string>lhs1=*(lhs.wptr.lock().get());
    vector<string>rhs1=*(rhs.wptr.lock().get());
    if(lhs1.size()>rhs1.size())return true;
    return false;
}
bool operator==(const StrVec&lhs,const StrVec&rhs)
{
   if(lhs.capacity()!=rhs.capacity())return false;
   if(lhs.size()!=rhs.size())return false;
   auto it=lhs.begin(),it1=rhs.begin();
   while(it!=lhs.end())
   {
       if(*it!=*it1)return false;
       it++;it1++;
   }
   return true;
}

bool operator>(const StrVec&lhs,const StrVec&rhs)
{
   if(lhs.size()>rhs.size())return true;
   return false;
}

bool operator<(const StrVec&lhs,const StrVec&rhs)
{
   if(lhs.size()<rhs.size())return true;
   return false;
}

bool operator!=(const StrVec&lhs, const StrVec&rhs)
{
    return !(lhs==rhs);
}

bool operator==(const String&lhs,const String&rhs)
{
    if(lhs.size()!=rhs.size())return false;
    auto it=lhs.elements,it1=rhs.elements;
    while(*it!='\0'){
        if(*it!=*it1)return false;
        it++;it1++;
    }
    return true;
}

bool operator<(const String&lhs,const String&rhs)
{
    if(lhs.size()<rhs.size())return true;
    return false;
}
bool operator>(const String&lhs,const String&rhs)
{
    if(lhs.size()>rhs.size())return true;
    return false;
}
bool operator!=(const String&lhs,const String&rhs){return !(lhs==rhs);}

int main()
{
    std::cout<<std::boolalpha;
  std::initializer_list<string>lhs1={"killer","bird","lol","crucial"},rhs1={"killer","bird"}
  ,rhs2={"chi","ren","n","k","l","p"};
  StrBlob Blb1(lhs1),Blb2(rhs1),Blb3(rhs2);
  StrBlobPtr Blbptr1(Blb1),Blbptr2(Blb2);StrBlobPtr Blbptr3(Blb3);
  StrVec Sv1(lhs1),Sv2(rhs1),Sv3(rhs2);
  Sv2=Sv3;
  std::cout<<(Sv2==Sv3);//true
  char cr1[]="yes",cr2[]="yeah",cr3[]="notebook";
  String S1(cr1),S2(cr2),S3(cr3);

}
