#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main()
{
    std::vector<int> v1{1,2,3,4,5,6,7,8};
    std::vector<int> v2{        5,  7,  9,10};
    //std::sort(v1.begin(), v1.end());
    //std::sort(v2.begin(), v2.end());
 
    std::vector<int> v_intersection;
 
    std::set_intersection(v1.cbegin(), v1.cend(),
                          v2.cbegin(), v2.cend(),
                          std::inserter(v_intersection,v_intersection.end()));
    for(int n : v_intersection)
        std::cout << n << ' ';//5 ,7 
}
