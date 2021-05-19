#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<iterator>
bool is_lrgr(int bnch)
{
    int bnch1=1024;
    std::greater<int>gg;
   if(gg(bnch,bnch1))return true;
   return false;
}
bool is_not(const std::string&str)
{
    std::equal_to<std::string>eq;
    //if(str=="pooh")
    if(eq(str,"pooh"))
    return false;
    else return true;
}

void m_by_2(int &i)
{
    std::multiplies<int> m;
    i=m(i,2);
}

int main()
{
    std::vector<int>v_a={111,243,1025,189,10934,-20394};
    std::cout<<"part a: "<<std::count_if(v_a.cbegin(),v_a.cend(),is_lrgr);//2

    std::vector<std::string>v_str={"pooh","hack","pooh","dada"};
    std::cout<<"\npart b:"<<*(find_if(v_str.begin(),v_str.end(),is_not))<<std::endl;
   
   std::cout<<"part c: ";
   std::ostream_iterator<int>it1(std::cout," ");
   for_each(v_a.begin(),v_a.end(),m_by_2);
   copy(v_a.cbegin(),v_a.cend(),it1);

}