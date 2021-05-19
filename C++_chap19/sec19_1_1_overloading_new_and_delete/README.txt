Applications cna define operator new and operator delete functions in the global scope
and/or as member functions. When the compiler sees a new or delete expression, it looks for
the corresponding operator function to call. If the object being allocated (deallocated)has class
type, the compiler first looks in the scope of the class, including any base classes. If the class has a member operator new
,or operator delete, that function is used by the new or delete expression. Otherwise, the compiler looks for a matching function
in the global scope.


void *operator new(size_t,void*);//this version may not be redefined.


When operator delete or operator delete[] is defined as a class member, the function may have a second parameter of type size_t.
If present, the additional parameter is initialized with the size in bytes of the object addressed by the first parameter. The size_t parameter
is used when we delete objects that are part of an inheritance hierarchy.
