Yes. There is an error. The print called in derived by the print is it per se, rather than base::print(ostream&) what we actually need.
I used this->base::print(ostream&) to circumvent it, anyway.

Extra notes:
If a derived virtual function that intended to call its base-class version omits the scope operator, the call will be resolved at run time as a call to
the derived version itself, resulting in an infinite recursion. 
