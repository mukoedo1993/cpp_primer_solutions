#include<iostream>
static 
int i=4;
//if we comment static above, we will get:

/*
/usr/bin/ld: /tmp/ccODoLHs.o:(.data+0x0): multiple definition of `i'; /tmp/ccUTgWLp.o:(.data+0x0): first defined here
collect2: error: ld returned 1 exit status
*/
//static global object works similarly as the way 
static int fcn1()
{
    std::cout<<"ichi.cpp";
    return 14;
}
int fcn();
int main()
{
    fcn1();
    std::cout<<i<<std::endl;
    fcn();
}


//final result:
/*
(base) zcw@mukoedo1993:~/C++chap18$ g++ ichi.cpp ni.cpp
(base) zcw@mukoedo1993:~/C++chap18$ ./a.out
ichi.cpp4
ni.cpp
13
*/