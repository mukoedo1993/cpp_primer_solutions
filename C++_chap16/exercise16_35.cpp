template<class T>T calc(T a,int)
{
    return a;
}
template<class T>T fcn(T a,T)
{
    return a;
}

double d;float f;char c;

int main()
{
   calc(c,'c');//ok in g++ 
   calc(d,f);//ok 
   fcn(c,'c');//ok
   //fcn(d,f);//error: no matching function for call to ‘fcn(double&, float&)’
}


/*
~$ g++ --version
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/