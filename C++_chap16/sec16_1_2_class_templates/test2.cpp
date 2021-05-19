
#include<iostream>
//sec.16.1.2:
   /*Template Type aliases*/
template<typename T>class Blob{
public: T t_;
};
typedef Blob<std::string>StrBlob1;
class StrBlob{
public:
std::string i1="sjd";
void print(const StrBlob1&orig)
{std::cout<<i1+orig.t_;}
};

//This typedef will lets us run the code we wrote using our template version
//of Blob instantiated with string. Because a template is not a type, we cannnot define
//a typedef that refers to a template
int main()
{
   Blob<std::string> orig_yaju;
   orig_yaju.t_="kimura";
   StrBlob Ob1;
   Ob1.print(orig_yaju);//sjdkimura
}