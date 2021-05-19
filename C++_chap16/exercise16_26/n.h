#include<vector>
#include<iostream>
using std::vector;
using std::string;
class NoDefault{
    public:
    NoDefault(const NoDefault&):j(3){}
    NoDefault(int i):j(i){std::cout<<"Ghost_win!\n";}
    NoDefault()=delete;
    //delete;
    private:
    int j=3;
};

/*
(base) zcw@mukoedo1993:~/C++chap16$ g++ 16_26.cc 16_22a.cc n.h
In file included from /usr/include/c++/9/vector:65,
                 from 16_22a.cc:1:
/usr/include/c++/9/bits/stl_construct.h: In instantiation of ‘void std::_Construct(_T1*, _Args&& ...) [with _T1 = NoDefault; _Args = {}]’:
/usr/include/c++/9/bits/stl_uninitialized.h:545:18:   required from ‘static _ForwardIterator std::__uninitialized_default_n_1<_TrivialValueType>::__uninit_default_n(_ForwardIterator, _Size) [with _ForwardIterator = NoDefault*; _Size = long unsigned int; bool _TrivialValueType = false]’
/usr/include/c++/9/bits/stl_uninitialized.h:601:20:   required from ‘_ForwardIterator std::__uninitialized_default_n(_ForwardIterator, _Size) [with _ForwardIterator = NoDefault*; _Size = long unsigned int]’
/usr/include/c++/9/bits/stl_uninitialized.h:663:44:   required from ‘_ForwardIterator std::__uninitialized_default_n_a(_ForwardIterator, _Size, std::allocator<_Tp>&) [with _ForwardIterator = NoDefault*; _Size = long unsigned int; _Tp = NoDefault]’
/usr/include/c++/9/bits/stl_vector.h:1603:36:   required from ‘void std::vector<_Tp, _Alloc>::_M_default_initialize(std::vector<_Tp, _Alloc>::size_type) [with _Tp = NoDefault; _Alloc = std::allocator<NoDefault>; std::vector<_Tp, _Alloc>::size_type = long unsigned int]’
16_22a.cc:3:21:   required from here
/usr/include/c++/9/bits/stl_construct.h:75:7: error: use of deleted function ‘NoDefault::NoDefault()’
   75 |     { ::new(static_cast<void*>(__p)) _T1(std::forward<_Args>(__args)...); }
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from 16_22a.cc:2:
n.h:9:5: note: declared here
    9 |     NoDefault()=delete;
      |     ^~~~~~~~~
*/