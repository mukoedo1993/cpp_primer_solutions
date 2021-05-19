Q: What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.

A:error code:
Severity	Code	Description	Project	File	Line	Suppression State
Error	C2593	'operator =' is ambiguous	Ptr	D:\C++book\Ptr\main_ver8.cpp	13	


Overloading operators can not distinguish const class& and class. Actually, they are same in operator's eyes.
class&& and  const class& are also interchangable?
