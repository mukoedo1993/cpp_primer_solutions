placement new opeartor:
https://www.geeksforgeeks.org/placement-new-operator-cpp/
Also, see:
tst2.cpp

Caveat: it would cause segment error if we want to delete a object located at non-dynamic memory.
In order to destroy an object in this situation, we need to explicitly call its destructor.

Attention!
https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap19/exercise19_19_ver2.cpp
exercise19_19.cpp is my solution of first edition. It is flawed because I actually used two functions.
However, the 2nd version is actually still flawed as I used two lambda expressions here, actually.
But, anyway, there is only a function visible in the global scope. Sigh. 

https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap19/exercise19_19_ver3.cpp
I modified the ex19_19 function,again...

.........................
mem_fn.cpp
This file discusses some unaproached details of mem_fn, in the case the No. of parameters of the variadic arguments is more than zero.
