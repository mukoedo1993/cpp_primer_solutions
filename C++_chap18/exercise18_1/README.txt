As we've sxeen, when an exception is thrown, blocks along the call chain are exited until a matching handler is found. When a block
is exited, the memory used by the local objects in the block is freed. As a result, it is almost certainly an error to throw a pointer to
a local object. It is an error for the same reasons that it is an error to return a ptr to a local object from a function. If the pointer
points to an object in a block that is exited before the catch, then that local object will have been destroyed before the catch. 
