Associative containers:
In general, two main types.
(1):map
(2):set


(1)map:
The map type is often referred to as an associative array. An associative array is like a "normal"
array except that its subscripts don't have to be integers. Values in a map are found by a key
rather than by their position.
e.g. use a person's name as a subscript to fetch that person's phone number.


(2)set:A set is simply a collection of keys.
e.g. a set of names of people who issued bad checks.

Note:
set::find:
http://www.cplusplus.com/reference/set/set/find/
Return value:
An iterator to the element, if val is found, or set::end otherwise.

map vs set:
A map is a collection of key-value pairs. When we want a container acting like dictionary, we should choose map.
A set is a collection of keys. When we want to check if some values are present, we can choose set

List v.s. Set
List:
Searching (linear time).
Inserting, deleting, moving (takes constant time).
Elements may be ordered.
Elements may be sorted.
Elements may be duplicate.

Set:
Searching (logarithmic in size).
Insert and delete (logarithimic in general).
Elements are un-ordered.
Elements are always sorted from lower to higher.
Elements are unique.



sort:
Sorts the elements in the range [first,last) into ascending order.

sort(first,last,comp)

first, last
Random-access iterators to the initial and final positions of the sequence to be sorted. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
RandomAccessIterator shall point to a type for which swap is properly defined and which is both move-constructible and move-assignable.
comp
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

hash:
Special library template that the unordered containers use to manage the position
of their elements.

set_ranking_by_sine.cpp
I use the set to rank by sine value.
