A pointer or reference to a base class could be bound to its derived class. However, we wwant to use it to call the virtual function, we always have to call
use base::function(...). Otherwise, we always call the derived::function(...)
