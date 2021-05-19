#include<vector>
#include<iostream>
#include"nd.h"
using std::vector;
using std::string;
class NoDefault{
    public:
    NoDefault(const NoDefault&):j(3){}
    NoDefault(int i):j(i){std::cout<<"Ghost_win!\n";}
    NoDefault()=default;
    //delete;
    private:
    int j=3;
};
extern template class vector<NoDefault>;

int main()
{
    NoDefault Ob1(3);
  vector<NoDefault>({Ob1});
}

/*
(base) zcw@mukoedo1993:~/C++chap16$ g++ ex16_26a.cc ex16_26b.cc nd.h
(base) zcw@mukoedo1993:~/C++chap16$ ./a.out
Ghost_win!

*/