//Exception Handling: It allows independently developed parts of a
//program to communicate about and handle problems that arise at run
//time. 

//In C++, an exception is raised by throwing an expression. The type of
//the thrown expression, together with the current call chain, determines
//which handler will deal with the exception. The selected handler is the 
//one nearest in the call chain that matches the type of the thrown object.


//stack unwinding...: 

//All objects created during the stack unwinding will be destroyed properly...
//Even if the object is only partially constructed, we are guranteed that the 
//constructed members will be properly destroyed.
/*Destructors and Exceptions*/
//All of the std library types guarantee that their destructors will not raise an exception.

int main()
{}