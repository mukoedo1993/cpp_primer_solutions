#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>
void exercise(int *b,int *e)
{
    std::vector<int>v(b,e);//This object will be destroyed properly
    int *p=new int[v.size()];//memory leak here
    std::ifstream in("ints");//this object will be destroyed properly
    delete p;
    throw std::invalid_argument("Motherf**ker!");

    //exception occurs here
}

int main()
{
    int coco[5]={1,2,3,4,5};
    int* coco1=const_cast<int*>(coco);

     
     exercise(coco1,coco1+4);

    std::cout<<coco[0]<<coco[4];//15
}