#include"StrVec_SEC_16_4_3.h"

using std::allocator;
using std::string;
using std::vector;
//std::forward<Args>
struct hakusai{
    hakusai(int a,int b,int c){

    }

};

    std::ostream& operator<<(std::ostream&os,const hakusai& ha){
       os<<17;
       return os;
    }

int main()
{
	


	std::initializer_list<string>v_st = { "yaju","senpai","teikoku","N","M","S","L" };

	StrVec v_str(v_st);

	v_str.resize(13, string("yiyiyo"));
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;



	v_str.resize(2,"");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

     

	v_str.reserve(15);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	v_str.reserve(2);
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	
	v_str.resize(28, "dojo");
	for (auto it = v_str.begin(); it != v_str.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << v_str.capacity();
	std::cout << "v_str.size(): " << v_str.size();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;

	StrVec getVec(std::cin);
	std::cout << "size is:" << getVec.size() << std::endl;
	for (auto it = getVec.begin(); it != getVec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "v_str.capacity(): " << getVec.capacity();
	std::cout << std::endl;	std::cout << std::endl;	std::cout << std::endl;


   vector<std::string>yaju__;

    yaju__.emplace_back("djssj");
    std::cout<<yaju__.back();
    
    vector<hakusai>yaju1145141;
    yaju1145141.emplace_back(13,12,15);
    std::cout<<yaju1145141.back();


     //yaju1145141.push_back(13,12,15);
	return 0;
}

//If we keep the push_back function: the error we will get:
/*
djssj17(base) zcw@mukoedo1993:~/C++chap16$ g++ sec16_4_3_forwarding_paraemetr_packsMAIN.cpp sec16_4_3_implementation.cpp StrVec_ver4.h
(base) zcw@mukoedo1993:~/C++chap16$ g++ sec16_4_3_forwarding_paraemetr_packsMAIN.cpp sec16_4_3_implementation.cpp StrVec_ver4.h
sec16_4_3_forwarding_paraemetr_packsMAIN.cpp: In function ‘int main()’:
sec16_4_3_forwarding_paraemetr_packsMAIN.cpp:87:36: error: no matching function for call to ‘std::vector<hakusai>::push_back(int, int, int)’
   87 |      yaju1145141.push_back(13,12,15);
      |                                    ^
In file included from /usr/include/c++/9/vector:67,
                 from StrVec_ver4.h:8:
/usr/include/c++/9/bits/stl_vector.h:1184:7: note: candidate: ‘void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = hakusai; _Alloc = std::allocator<hakusai>; std::vector<_Tp, _Alloc>::value_type = hakusai]’
 1184 |       push_back(const value_type& __x)
      |       ^~~~~~~~~
/usr/include/c++/9/bits/stl_vector.h:1184:7: note:   candidate expects 1 argument, 3 provided
/usr/include/c++/9/bits/stl_vector.h:1200:7: note: candidate: ‘void std::vector<_Tp, _Alloc>::push_back(std::vector<_Tp, _Alloc>::value_type&&) [with _Tp = hakusai; _Alloc = std::allocator<hakusai>; std::vector<_Tp, _Alloc>::value_type = hakusai]’
 1200 |       push_back(value_type&& __x)
      |       ^~~~~~~~~
/usr/include/c++/9/bits/stl_vector.h:1200:7: note:   candidate expects 1 argument, 3 provided
*/




//command on terminal:
/*
(base) zcw@mukoedo1993:~$ cd /home/zcw/C++chap16/
(base) zcw@mukoedo1993:~/C++chap16$ g++ sec16_4_3_forwarding_paraemetr_packsMAIN.cpp sec16_4_3_implementation.cpp StrVec_SEC_16_4_3.h
(base) zcw@mukoedo1993:~/C++chap16$ ./a.out


*/



//Result on terminal:
/*
yaju senpai teikoku N M S L yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo yiyiyo 
v_str.capacity(): 13


yaju senpai 
v_str.capacity(): 2


capacity is: 2
Reserve 15
yaju senpai 
v_str.capacity(): 15v_str.size(): 2


capacity is: 15
yaju senpai 
v_str.capacity(): 15yaju senpai dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo dojo 
v_str.capacity(): 28v_str.size(): 28


quit sjd
qsk ekd
nimasile
q
size is:3
quit sjd qsk ekd nimasile 
v_str.capacity(): 3


djssj17
*/