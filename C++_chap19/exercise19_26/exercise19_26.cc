extern "C"{
    #include"ex19_26.h"
}

int main(){}

/*
(base) zcw@mukoedo1993:~/cpp_primer_solutions/C++_chap19/exercise19_26$ g++ ex19_26.h exercise19_26.cc
In file included from exercise19_26.cc:2:
ex19_26.h:8:12: error: conflicting declaration of C function ‘double compute(double*, double)’
    8 |     double compute(double*,double){
      |            ^~~~~~~
ex19_26.h:4:5: note: previous declaration ‘int compute(int*, int)’
    4 | int compute(int*,int){
      |     ^~~~~~~

*/
