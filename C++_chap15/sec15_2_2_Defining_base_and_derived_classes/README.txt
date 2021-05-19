extra note 1: as a result, derived-class constructors may not directly initialize the members of its base class. The constructor body of a derived constructor 
can assign values to its public or protected base-class members. Although it can assign to those members, it generally should not do so. Like any other user of the
base class, a derived class should respect the interface of its base class by using a constructor to initialize its inherited members.

