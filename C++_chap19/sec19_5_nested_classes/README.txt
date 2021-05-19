A class can be deifned within another class. Such a class is a nested class, also referred to as a nested type.

Nested classes are independent classes and are largely unrelated to their enclosing class. In particular, objects of
the enclosing and nested classes are independent from each other. An object of the nested type does not have members defined
by the enclosing class. Similarly, an object of the enclosing class does not have members defined by the nested class.

A nested class can have the same kinds of members as a nonnested class. Just like any other class, a nested class controls access
to its own members using access specifiers.
...
A nested clas... in the public part of the enclosing class defines a type that may be used anywhere.

A nested class defined in the protected section defines a type that is accessible only by the enclosing class, its friends, and its derived classes.

A private nested class... accessible only to the members and frineds of the enclosing class.




//Defining a nested class outside of the enclosing class:
When we define a nested class outside its enclosing class, we must qualify the name of the nested class by the name
of its enclosing class:
.....
The only change we made compared to our original class is that we no longer define a line_no member in QueryResult. The 
members of QueryResult can access that name directly from TextQuery, so there is no need to define it again.


//Defing the members of a nested class:
In this version, we did not define the QueryResult constructor inside the class body. To define the constructor, we must
indicate that QueryResult is nested within the scope of TextQuery. We do so by qualifying the nested class name with the
name of its enclosing class.


//Nested-class static member definitions
//must be given outside of enclosing class and nested class.
type member: interchangably visible for enclosing class and nested class.


//The Nested and Enclosing Classes are independent
More concretely, the second return statement in TextQuery::query use data members of the TextQuery object on which query was
run to initialize a QueryResult object. We have to use these members to construct the QueryResult object we return because a 
QueryResult object does not contain the members of its enclosing class.

