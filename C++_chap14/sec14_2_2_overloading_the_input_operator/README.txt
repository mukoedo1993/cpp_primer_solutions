Errors during input:
1:A read operation might fail->contains data of an incorrect type. e.g.1: numeric value should appear but data non-numeric data appear, anyway...
2:end-of-file or some other input error on the input system

Putting the object into a valid state is especially importandt if the object might have been partially changed before the error occured.
e.g.1: By leaving the object into a valid state, we somewhat protect a user that ignores the possibility of an input error. The object will be
in a usable state-- its members are all defined. Similarly, the object won't generate misleading result-- its data are internally consistent.


Indicating error: 1: failbit 2: badbit



