1: constexpr Functions:
A constexpr function is a function that can be used in a constant expression.
a: the return type and the type of each parameter in a must be a literal type. And the function body must contain exactly one
return statement.

e.g.1:
constexpr int new_sz(){return 42;}
constexpr int foo=new_sz();//ok: foo is a constant expression.
