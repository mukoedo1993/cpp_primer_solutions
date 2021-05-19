Q 16_32:
What happens during template argument deduction?


A 16_32:
Template argument deduction, which determines the template arguments from the function arguments is known as template
argument deduction.








Q16_33:
Name two type conversions allowed on function arguments involved in template argument deduction.


A16_33:
0: top-level consts in either the parameter or the argument are ignored. 
1: const conversions: a function parameter that is a reference to a const can be passed a reference (or pointer)to
a nonconst object.
2: Array- or Function-to-pointer conversions. If the function parameter is not a reference type, then the normal pointer conversion
will be applied to arguments of array or function type. 
# An array argument will be converted to a pointer to its first element. #
Similarly, a function argument wil be converted to a pointer to the function's type.
