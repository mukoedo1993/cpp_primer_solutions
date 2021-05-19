Q: Explain how the compiler might inline the call the deleter if we used DebugDelete with unique_ptr.

A: In my personal view, 
If we define the constructor within the block of class.
Or, explicitly declare inline.
