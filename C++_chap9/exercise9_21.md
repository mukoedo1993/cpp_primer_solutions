list<string>lst;
auto iter=lst.begin();
while(cin>>word)
{
iter=lst.insert(iter,word);//same as calling push_front
}

//Original code above

//Q:
/*
Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into
a vector instead.
*/

//A:
/*
The member function insert(p,t) has the same effect on both list and vector containers, but the cost is different. Inserting an
element into a list is cheap, while inserting an element into vector will cause all elements after the newly inserted elements be moved.
Thus every time the while loop body is executed, all elements in the vectorare moved backward, and new element is inserted in the front
of the vector.
*/
