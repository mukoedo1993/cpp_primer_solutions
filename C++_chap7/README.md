The fundamental ideas behind classed are data abstraction and encapsulation.

#data abstraction
Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation. The interface of a class consists
of the operations that users of the class can execute. The implementation includes the class' data members, the body of the functions that constitute the interface, and
any functions needed to define the class that are not intended for general use.

#Encapsulation
Encapsulation enforces the separation of a class' interface and implementation.
A class that is encapsulated hides its implementation-- users of the class can use the interface but have no access to the implementation.

A class that uses data abstraction and encapsulation defines an abstract data type. In an abstract data type, the class designer worries about how the class is implemented. 
Programmers who use the class need not know how the type works. They can instead think abstractly about what the type does.



The interface to Sales+data consists of the following operations:

1: An isbn member function to return the object's ISBN.
2:A combine member function to add one Sales_data object into another.
3: A function named add to add two Sales_data objects.
4:A read function to read data from an istream into a Sales_data object
5:A print function to print the value of a Sales_data object on an ostream.


#Const Member functions:
Objects that are const, and references or pointers to const objects, may call
only const member functions. 
In general, this is a const pointer that points to nonconst objects.
By using const, this will point to a const object.


It is important to understand that friendship is not transitive.


Order of member initialization: 
Members are initialized in the order in which they appear in the CLASS DEFINITION.
The first member is initialized first, then the next, and so on.


delegate constructor 如果有嵌套的话，都是由里往外运行block里面的内容，respectively.

Chap 7.5.3:

The default constructor is used automatically whenever an object is default or value
initialized. Default initialization happens.

1: When we define nonstatic variables or arrays at block scope without initializers.
2:When a class that itself has members of class type uses the synthesized default constructor.
3: When members of class type are not explicitly initialized in a constructor initializer list.

#Value initialization happens:
1: During array initialization when we provide fewer initializers than the size of the array.
2: When we define a local static object without an initializer.
(Each local static object is initialized before the first time execution passes through the object's
definition. )

3: When we explicitly request value initialization by writing an expressions of
the form T() where T is the name of a type (The vector constructor that takes a single argument
to specify the vector's size uses an argument of this kind to value initialize its element initializer.)

When must initialize but not assign:
1: Members that are const or references must be initialized
2: Members that are of a class type that does not define a default constructor must be initialized.



Attention:!!
Exercise 7.46 part_c should be false. 
If so, the class should provide an IMPLICIT default constructor.

Attention: !!
The code on page 295 is wrong.
I correct the function of combine in the header file Sales_data_ver3.h.

The type of an unprefixed string literal is const char[N], 
where N is the size of the string in code units of the execution narrow encoding, including the null terminator.


Chap 7.5.4:
Classes can be called with a single argument defines an implicit conversion to a class type.
Such constructors are sometimes referred to as converting constructors.

Library Classes with explicit constructors.

Attention:
On page 295, it says that class-type more than one time is not allowed.
But, visual studio give me different results.
It seems that this conclusion is IDE-dependent.


exercise 7_49:
  
(a) Sales_data &combine(Sales_data); The code works correct. It will first convert s to Sales_data, then copy that temporary into the parameter of combine.

(b) Sales_data &combine(Sales_data&); The code is wrong. It will first convert s to Sales_data, then pass the reference to that temporary into the parameter of combine, but passing a reference to a temporary is error.

(c) Sales_data &combine(const Sales_data&) const; The code could not compile, because it should not be a const member function. It will first convert s to Sales_data, then pass the const reference to that temporary into the parameter of combine.



Attention:!!
On page 300, the first line, the function needs a extra const added after the 'any()' since the C++!4.
Check:
sec7_5_6_literal_classesANDexeicse7_53.cpp
And, notice that set_ series cannot be called by constant object io_sub and prod.

Attention:!!
On page 303, whether or not we give the period definition outside the class, it works well even if we pass it as a const int& parameter to another function.

