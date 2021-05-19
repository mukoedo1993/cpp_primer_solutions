Q:
In the call to factorial, why did we pass val-1 rather than val--?
/*


int factorial(int val)
{
if(val>1)
return factorial(val-1)*val;
return 1;
}
*/

Soln:
The order of evaluation is undefined for the operator *, thus the expression return factorial(val--) * val make equal to either of the following expressions:

// Version 1
auto tmp = factorial(val) * val;  // evaluate second operand first
--val;
return tmp;

// Version 2
auto tmp = factorial(val);
--val;
return tmp * val;  // evaluate first operand first
