#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
class Is_Equal{
    public:
    Is_Equal(int x){a=x;}
    bool operator()(int b){return (a==b);}
    int a;
};

std::ostream_iterator<int>osit(std::cout," ");

int main()
{
  const int a=13;
  const int new_int=114;
  std::vector<int>vint={12,10,19,17,13,12,15,16,13};
  copy(vint.cbegin(),vint.cend(),osit);std::cout<<std::endl;
    std::replace_if(vint.begin(),vint.end(),Is_Equal(a),new_int);
    copy(vint.cbegin(),vint.cend(),osit);
}