#include<functional>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iostream>
//https://en.cppreference.com/w/cpp/language/adl
int main()
{
    std::vector<int>v_i={1,4,3,-5,6,12,-24,109,-2943};
    int v_arr[10]={1,2,3,4,5,6,7,8,9};
     //Its parameters are class type, std::vector, 
     //which will lead to argument_depenedent lookup, in this case, std namespace will 
     //also be searched.
     //So, we could write std::for_each as for_each here.
    for_each(v_i.begin(),v_i.end(),[](int &i){i=2*i;//pass by reference
        std::cout<<i<<" ";});
        std::cout<<std::endl;
         std::for_each(v_i.begin(),v_i.end(),[](int i){//pass by value
        std::cout<<i<<" ";});
        std::cout<<std::endl;
//for_each(std::vector<int>::iterator,.......)


         //Its parameters are not class type, 
         std::for_each(std::begin(v_arr),std::end(v_arr),[](int &i){i=2*i;
        std::cout<<i<<" ";});
        //for_each(int*,int *, a lambda expression...)
}

/*
2 8 6 -10 12 24 -48 218 -5886 
2 8 6 -10 12 24 -48 218 -5886 
2 4 6 8 10 12 14 16 18 0 
*/