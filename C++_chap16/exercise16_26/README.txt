The answer is no.
We can use explicit instantiation only for types that can be used with all(including default constructor) 
the members of that template.




https://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co
C++11 introduces a new constructor, vector(size_type n), and "obviously" that constructor can't be instantiated unless the value_type is default-constructible. It was vector(size_type n, const T & = T(), const Allocator& alloc = Allocator()) in C++03, but they changed it to two separate constructors. A similar change was made to resize().

In GCC and as far as I know also per the standard: the vector template can be at least implicitly instantiated without the elements being default constructible. Implicit template class instantiation only instantiates the member functions you use.

In C++03 only the default arguments use default construction. You can explicitly instantiate the template, but you won't be able to call those functions without providing a value for that parameter.

So I'm pretty sure that change is what prevents vector<NoDefault> being explicitly instantiated in C++11 (and I suppose the allocator type needs to be default-constructible too). But I might have missed something. It seems a little odd to make that change given that it introduces this backward incompatibility. There's probably a proposal somewhere that justifies it if you want a deeper reason why this no longer works as opposed to just why this doesn't work :-)
