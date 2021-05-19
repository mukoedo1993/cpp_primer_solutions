Most of algorithm : in algorithm header
Some of algorithm: in the numeric header

Iterators make the algorithms container independent,...
But Algorithms do depend on element_type operations.

With only a few exceptions, the algorithms operate over a range of elements.
We'll refer to this range as the "input range."

Although most algorithms are similar in that they operate over an input range, they differ
in how they use the elements in that range. The most basic way to understand the algorithms is to know whether they
(1): read(_only) elements
(2):write elements
or(3): rearrange elements

Sec10.2.1:
Read-only algorithms
1: find
2: accumulate
3:equal(str1.begin,str1.end,str2.itrtr);

(Review: constant iterators are pointers to constant, which means that they are only low-level const.
Themselves can change, but the values to which iterators point cannot change.)(e.g. cbegin(),cend()).


Ordinarily it is best to use cbegin()and cend() with algorithms that read, but do not write, the elements.
However, if you plan to use the iterator returned by the algorithm to change an element's value, then you 
need to pass begin() and end().

char * -> C_style string

replace_copy:
http://www.cplusplus.com/reference/algorithm/replace_copy/
replace:
http://www.cplusplus.com/reference/algorithm/replace/
copy:
http://www.cplusplus.com/reference/algorithm/copy/
find_if:
http://www.cplusplus.com/reference/algorithm/find_if/
stable_partition:
http://www.cplusplus.com/reference/algorithm/stable_partition/
lambda_expression:
https://en.cppreference.com/w/cpp/language/lambda


One way top ensure that an algorithm has enough elements to hold the element is to use an
insert iterator.
back_inserter takes a reference to a container and returns an insert iterator bound to that container.

a lambda expression:
[capture list](parameter list)->return type{ function body }

1:where capture list is an (often empty)list of local variables defined in the enclosing function; 
2:return type, parameter list, and function body(like a function.)
3: capture list and function body cannot be omitted.
4:Notice that -> cannot be omiited to specify the return type.

implicit captures:
[]
[names]
[&]pass by reference
[=]pass by value
[&,identifier_list]
[=.identifier list]
!!!!!!
[&,=]not allowed.



Mutable Lambdas
By default, a lambda may not change the value of a variable that it copies by value.
If we want to be able to change the value of a captured variable, we must follow the 
parameter list with the keyword mutable. Lambdas that are mutable may not omit the parameter
list.
e.g.:
//auto ex10_21=[=]()mutable->bool {if (k > 0) { k--; return false; } else return true; };



Adaptor:
Essentially, an adaptor is a mechanism for making one thing look act like another.
(e.g. container adapter,iterator adapter and function adapters.)


bind(a function adaptor)
http://www.cplusplus.com/reference/functional/bind/

Iterators:
4 kinds:
1:Insert iterators:
2: Stream iterators:
3:Reverse iterators:
4: Move iterators.

//Insert iterators:
/*
*1: back_inserter: creates an iterator that uses push_back.
*2: front_inserter: creates an iterator that uses push_front.
*3: inserter creates an iterator that uses insert. This function
*takes a second argument, which must be an iterator into the given
*container. Elements are inserted ahead of the element denoted by the 
*given iterator.
*/

inserter always insert element at the front of the same given element in the container by calling c.insert().

iostream iterators:
Even though the iostream types are not containers, there are iterators that can be used with objects of the IO types.
1: An istream_iterator: reads an input stream.
2: An ostream_iterator: writes an output stream.


Reverse Iterators
A reverse iterator is an iterator that trasverses a container backward, from the last element toward the first. A reverse iterator
inverts the meaning of increment (and decrement). Incrementing(++it) a reverse iterator moves the iterator to the previous element,
decrement (--it)moves the iterator to the next element.

The containers, aside from forward_list, all have reverse iterators. 
To obtain it-->by:
(1):rbegin.(2)rend(3)crbegin(4)crend members

Structure of Generic Algorithms
Iterator Categories:
1: input iterator: Read, but not write; 
operators:
single-pass, increment only(== != ++ * the arrow iterator-> is a synonym for(*it)) istream iterator
(*) must be on the right side of an assignment.

2:output iterator: Write, but not read;
operators:
single-pass, increment only(++ * )ostream iterator
(*) must be on the left side of an assignment.

3:forward iterator: Read and write; multi-pass, increment only
All iterators on forward_list are forward iterators.

4 Bidirectional iterator: Read and write; multi-pass, increment and decrement
Aside from forward_list, the library containers supply iterators that meet the requirements for a
bidirectional iterator.

5: Random-access iterator: Read and write; multi-pass, full iterator arithmetic(e.g.: + += - -= < <= > >=)
sort->must be a random-access iterator
Iterators for array, deque, string and vector are random-access iterators, as are pointers when used to access
elements of a built-in array.

6: find
http://www.cplusplus.com/reference/string/string/find/
