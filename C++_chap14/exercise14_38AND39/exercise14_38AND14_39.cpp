#include<iostream>
#include<fstream>
#include<iterator>
class is_in_range{
public: is_in_range(size_t minimum,size_t maximum):lower(minimum),upper(maximum){}
bool operator()(const std::string&s){return (lower<=s.size()&&upper>=s.size());}
private:
size_t lower;
size_t upper;

};
int main()
{
    std::ifstream input("ex14_38i.txt");
    std::istream_iterator<std::string> it1(input),eof;
    is_in_range test1(1,10);
    is_in_range test2(1,11);
    is_in_range test3(1,9);
    int cnt1=0;
    int cnt2=0;int cnt3=0;
    while(it1!=eof)
    {
        if(test1(*it1))
         cnt1++;
         if(test2(*it1))
         cnt2++;
         if(test3(*it1))
         cnt3++;
        it1++;
    }
    std::cout<<"Our result for[1,10] is: "<<cnt1<<" .\n";//3
    std::cout<<"Our result for[1,11] is: "<<cnt2<<" .\n";//4
    std::cout<<"Our result for[1,9] is: "<<cnt3<<" .\n";//2

}