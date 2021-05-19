/*
The fact that instantiations are generated when a template is used means that the same
instantiation may appear in multiple object files. When two or more separately 
compiled source files use the same template with the same template arguments, there is
an instantiation of that template in each of those files. 
In large systems, the overhead of instantiating the same template in multiple files
can become siginificant. Under the new standard, we can avoid 
*/
#include<set>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<memory>
using std::set;
bool sin_cmp(double lhs,double rhs)
{
    if(sin(lhs)<sin(rhs))return true;
    else return false;
   
}

class deleter{
    public:
   void
    operator()(int *i){delete []i;}
};
void deleter1(int *i){
    delete []i;
}
int main(){
     
    set<double>la={1.3,4.2,5.6,-5.8,1.2,-3.4};
   set<double,bool(*)(double,double)>set1(la.begin(),la.end(),sin_cmp);
   std::for_each(set1.cbegin(),set1.cend(),[](double i){std::cout<<sin(i)<<" ";});
   std::cout<<std::endl;
   int j=0;
   std::unique_ptr<int>u_ptr_i(new int);
   std::shared_ptr<int>s_ptr_i(new int[10],[](int *i){delete []i;});
    std::for_each(s_ptr_i.get(),s_ptr_i.get()+10,[&](int i){i=j;j++;});
  std::shared_ptr<int> it1;
  std::cout<<(it1.use_count())<<" ";//0
  {
   std::shared_ptr<int> it2(it1);
   std::cout<<std::boolalpha<<it2.use_count();//0
  } 
   std::cout<<s_ptr_i.unique()<<" "<<it1.use_count();//true 0
   int *i=nullptr;
   it1.~shared_ptr<int>();
   std::cout<<" "<<it1.use_count();//0
   int j1=14;
   std::unique_ptr<int,deleter>i1(new int[10],deleter());
   std::unique_ptr<int[]>i333();
   std::shared_ptr<int>i222(new int[10],deleter());
   std::shared_ptr<int>i444(new int[10],deleter1);
   std::unique_ptr<int,void(*)(int*)>i555(new int[10],[](int *i){delete []i;});
   std::unique_ptr<int,decltype(deleter1)*>i666(new int[10],[](int *i){delete []i;});
   std::shared_ptr<int>i777(new int(-114),[](int *i){delete []i;});
   *(i555.get())=3;//ok
   
}
/*
-0.871576 -0.631267 0.255541 0.464602 0.932039 0.963558 
0 0true 0 0
*/
