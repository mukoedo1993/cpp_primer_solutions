#include"n.h"
#include<vector>
#include<iostream>
#include"nd.h"
using std::vector;
using std::string;

extern template class vector<NoDefault>;

int main()
{
    NoDefault Ob1(3);
  vector<NoDefault>({Ob1});
}