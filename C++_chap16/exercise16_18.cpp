/*
(a)to(d) are all illgeal.
The only one that is legal is (e).
*/

//(a):template<typename T,U,typename V>void f1(T,U,V);//error
template<typename T,class U,typename V>void f1(T,U,V);

//(b):
//template<class T>T f2(int &T);
template<class T>T f2(int &T_);

//(c);
template<class T>inline T foo(T,unsigned int*);

//(d):
//template<typename T>f4(T,T);
template<typename T>void f4(T,T);

//(e):
typedef char Ctype;
template<typename Ctype>Ctype f5(Ctype a);//only legal one
int main(){
    
}