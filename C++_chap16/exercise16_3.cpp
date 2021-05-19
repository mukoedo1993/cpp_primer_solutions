#include<iostream>
#include<functional>
#include"sales_data.h"

template<typename T>int compare(const T &lhs,const T&rhs)
{
    
    if(std::greater<T>()(lhs,rhs))return 1;
    if(std::greater<T>()(rhs,lhs))return -1;
    return 0;
}

int main()
{
    Sales_data Ob1,Ob2;
    
    compare(Ob1,Ob2);
}

/*
sr/include/c++/9/tuple:1451:5: note:   template argument deduction/substitution failed:
                                                                                       In file included from /usr/include/c++/9/string:48,
                                             from /usr/include/c++/9/bits/locale_classes.h:40,
                                                                                                               from /usr/include/c++/9/bits/ios_base.h:41,
                                                             from /usr/include/c++/9/ios:42,
                                                                                                             from /usr/include/c++/9/ostream:38,
                                                   from /usr/include/c++/9/iostream:39,
                                                                                                        from /home/zcw/C++chap16/exercise16_3.cpp:1:
                                      /usr/include/c++/9/bits/stl_function.h:376:20: note:   ‘const Sales_data’ is not derived from ‘const std::tuple<_Tps ...>’
                                                    376 |       { return __x > __y; }
                                                                                           |                ~~~~^~~~~

       The terminal process failed to launch (exit code: -1).

Terminal will be reused by tasks, press any key to close it.
*/