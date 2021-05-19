#include<iostream>
struct A{

};
struct tst1{
    tst1(const A&a1):a(a1){}
    A a;
};
void swap(A a1,A a2)
{
   std::cout<<"swap(A a1,A a2)!\n";
}
void swap(tst1 v1,tst1 v2)
{
    using std::swap;
    swap(v1.a,v2.a );
}
void swap1(tst1 v1,tst1 v2)
{
    std::cout<<"swap1(...)\n";
    std::swap(v1.a,v2.a );
}
int main()
{
    A a1,a2;
    tst1 ob1(a1),ob2(a2);
    swap(ob1,ob2);//It calls the user-defined swap(A,A)
    swap1(ob1,ob2);//It only calls generalized template swap<class A>(A,A)here.
}
//Result:
/*
swap(A a1,A a2)!
swap1(...)
*/