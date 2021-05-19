chapter 9 for C++ primer 5th edi.

1:A container holds a collection of objects of a specified type. 

2:A sequential containers let the programmer control the order in which the elements are stored and accessed.

3:order
The order corresponds to the position at which elements are put into the container.

4:By contrast, the ordered and unordered associative containers, store their elements on the value of a key.


5:
(1): vector:
Flexible-size array. Supports fast random access.

(2):deque:
Double-ended queue. Supports fast random access.
Fast insert/delete at front or back.

(3)list:
Doubly linked list. Supports only bidirectional sequential access.
Fast insert/delete at any point in the list.

(4)forward_list:
Singly linked list. Supports only sequential access in one direction.
Fast insert/delete at any point in the list.

(5)array:
Fixed-size array. Supports fast-random access.
Cannot add or remove elements.

(6)string:
A specialized container, similar to vector, that contains characters. Fast random access.
Fast insert/delete at the back.

(あ):list and forward_list:
Pros:we can effectively add or delete any element at any position.
Cons: random access not allowed. Interating through the container is a must-do.
&: overhead memory substantial

(い)：deque:
Pros:supports fast random access.
Cons: adding or removing elements is expensive if not at the begin or end( but cheap if)

(う)：forward_list and array:
Like built-in arrays , array has fixed size.
Forward_list doesn't have size() while all others have.


Chap. 9.2
As with the containers, iterators have a common interface. If an iterator provides an operation, 
then the operation is supported in the same way for each iterator that supplies that operation.


With one exception, all container iterators are supported.

forward_list doesn't support the decrement(--) operator.


(1):An iterator range:[begin,end)

Container Type Members:
iteraor
const_iterator
size_type
differnce_type
value_type
reference(=value_type&)
const_reference(=const value_type&)

(2)
copy to initialize a container:
list initializer: exact-match container type,element type
:() initializer: convertable needed

!!!Attention:BUG:
!!!ON page 338, we could let a2={0} hold in the newest VS c++ version.(Line 6)

(3):
seq.assign(...) PAGE.338

Chap.9.3 Sequential Container Operation

(1):push_back and emplace_back are not valid for forward_list.

(2):push_front and emplace_front not valid for vector or string.

exercise9_22:
https://github.com/pezy/CppPrimer/blob/master/ch09/ex9_22.cpp

(4):
Page 349 Table 9.7:
erase(etc.) operations change the size of the container and so are not supported by array, forward_list has a 
special version of erase.
pop-back not valid for forward_list.  pop_front not for vector and string.


string::erase:
http://www.cplusplus.com/reference/string/string/erase/


string::insert
http://www.cplusplus.com/reference/string/string/insert/

//Container adaptors
1:stack:试管式存取，读取，删除数据。

2:queue:first-in, first-out storage and retrival policy.(e.g. a restaurant)

3:priority queue: lets us etablish a priority among the elements held in the queue.
(e.g. a restaurant that seats people according to their reservation time, regardless of
when they arrive, is an example of a priority queue)
