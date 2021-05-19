#include<vector>
#include<iostream>
#include"nd.h"
using std::vector;
using std::string;

class NoDefault{
    public:
    NoDefault(const NoDefault&):j(3){}
    NoDefault(int i):j(i){std::cout<<"Ghost!\n";}
    NoDefault()=default;
    //delete;
    private:
    int j=3;
};

template class vector<NoDefault>;