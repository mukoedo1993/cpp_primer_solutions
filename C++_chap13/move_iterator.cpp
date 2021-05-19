/*
std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator (which must be at least an LegacyInputIterator or model input_iterator (since C++20)), 
except that dereferencing converts the value returned by the underlying iterator into an rvalue. 
If this iterator is used as an input iterator, 
the effect is that the values are moved from, rather than copied from.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
 
int main()
{
    std::vector<std::string> v{"this", "is", "an", "example"};
 
    std::cout << "Old contents of the vector: ";
    for (auto& s : v)
        std::cout << '"' << s << "\" ";
 
    typedef std::vector<std::string>::iterator iter_t;
    std::string concat = std::accumulate(
                             std::move_iterator<iter_t>(v.begin()),
                             std::move_iterator<iter_t>(v.end()),
                             std::string());  // Can be simplified with std::make_move_iterator
 //After the movement, the value to which move_iterator points is valid but undefined.
    std::cout << "\nConcatenated as string: " << concat << '\n'
              << "New contents of the vector: ";
    for (auto& s : v)
        std::cout << '"' << s << "\" ";
    std::cout << '\n';
}
/*
Old contents of the vector: "this" "is" "an" "example" 
Concatenated as string: thisisanexample
New contents of the vector: "" "" "" "" 
*/