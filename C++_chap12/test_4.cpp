#include<memory>
#include<iostream>
using std::shared_ptr;

int main()
{ int i[10]={1,2,3,4,5,6,7,8,9,10};
    shared_ptr<int>s1(new int(i[10]),[](int *p){delete []p;});
    shared_ptr<int>s2(new int(i[10]),std::default_delete<int[]>());
    s2.reset();
    std::cout<<s1.use_count()<<std::endl;//1
}