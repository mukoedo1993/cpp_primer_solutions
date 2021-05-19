#include<iterator>
#include<iostream>
#include<algorithm>
#include<iterator>

int main()
{
    std::ostream_iterator<char> it1(std::cout," ");
    std::string line="first,middle,last";
    auto comma=find(line.cbegin(),line.cend(),',');
    std::string line1(line.cbegin(),comma);
    copy(line.cbegin(),comma,it1);//f i r s t
    std::cout<<std::endl<<*(line.crend()-1);//f
    auto rcomma=find(line.crbegin(),line.crend(),',');
    copy(line.crbegin(),rcomma,it1);//t s a l
    std::cout<<std::endl;
    auto rcomma_base=rcomma.base();
    std::cout<<*rcomma_base;//l
    std::cout<<std::endl;
    copy(line.cbegin(),rcomma_base,it1);//f i r s t , m i d d l e ,
    std::cout<<std::endl;
    std::cout<<std::boolalpha;
    std::cout<<(line.crbegin().base()==line.cend())<<std::endl;//true
    std::cout<<(line.crend().base()==line.cbegin())<<std::endl;//true
    std::cout<<*(line.crend()-1);//f
    //But, we could dereference both line.crend() and line.cend(), 
    //although a null char will be given.
    std::cout<<*(line.crend());
    std::cout<<*(line.cend());
}