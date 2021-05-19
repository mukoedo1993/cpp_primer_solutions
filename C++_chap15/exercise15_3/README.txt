What I have done are: 1: rewrite the print_total function is trailing return form and add a protected member, to_define_bookNo()function on the Quote class, so that
I can define price member inherited by a derived Bulk_quote class. Otherwise, Bulk_quote class could only have empty string forthe bookNo, as soon as the bookNo is
a private member in the Quote class.

extra note: 
 Only class' own members can be initialized in constructor initializer list (You can, OTOH, assign to them in constructor's body). The base subobjects are initialized first.
 
 reference:
 https://stackoverflow.com/questions/17196495/initialise-protected-data-members-from-derived-class-constructor
