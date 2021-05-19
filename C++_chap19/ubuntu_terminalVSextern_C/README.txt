log on Ubuntu terminal:


(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 -c app.cpp
(base) zcw@mukoedo1993:~/C++chap19_externC$ nm app.o
                 U __cxa_atexit
                 U __dso_handle
                 U fcn
                 U _GLOBAL_OFFSET_TABLE_
0000000000000087 t _GLOBAL__sub_I__Z3addi
0000000000000026 T main
0000000000000012 T _Z3addf
0000000000000000 T _Z3addi
000000000000003a t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
0000000000000000 r _ZStL19piecewise_construct
0000000000000000 b _ZStL8__ioinit
(base) zcw@mukoedo1993:~/C++chap19_externC$ #We could see that fcn is just
(base) zcw@mukoedo1993:~/C++chap19_externC$ #literally fcn. Because it is
(base) zcw@mukoedo1993:~/C++chap19_externC$ #treated in the same way as a 
(base) zcw@mukoedo1993:~/C++chap19_externC$ #C-style function.
(base) zcw@mukoedo1993:~/C++chap19_externC$ ls
app.cpp  app.o  cfile.c  cfile.h  cfile.o
(base) zcw@mukoedo1993:~/C++chap19_externC$ nm cfile.o
0000000000000000 T fcn
                 U _GLOBAL_OFFSET_TABLE_
                 U puts
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 app.o cfile.o
(base) zcw@mukoedo1993:~/C++chap19_externC$ ./a.out
I am in Cf ile!
(base) zcw@mukoedo1993:~/C++chap19_externC$ #Then, let's comment extern C part:
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 -c app.cpp
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 app.o cfile.o
/usr/bin/ld: app.o: in function `main':
app.cpp:(.text+0x2f): undefined reference to `fcn()'
collect2: error: ld returned 1 exit status
(base) zcw@mukoedo1993:~/C++chap19_externC$ #We could see here, there are linkagerror, because name mangling between the C function and C++ function.
(base) zcw@mukoedo1993:~/C++chap19_externC$ #decomment...
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 -c app.cpp
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 app.o cfile.o
(base) zcw@mukoedo1993:~/C++chap19_externC$ ./a.out
I am in Cf ile!
(base) zcw@mukoedo1993:~/C++chap19_externC$ #OK!!! One more trail, we will add the argument __cplusplus
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 -c app.cpp
(base) zcw@mukoedo1993:~/C++chap19_externC$ g++-9 app.o cfile.o
(base) zcw@mukoedo1993:~/C++chap19_externC$ ./a.out
I am in Cf ile!
(base) zcw@mukoedo1993:~/C++chap19_externC$ #END of this test

