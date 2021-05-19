It would be an error if a derived class doesn't define a function by itself, but could find it in multiple base classes.
Even the parameters of base classes are not identical, this error could still be reported.
Because, as always, name lookup always happens before type checking. When the compiler finds max_weight in two different scopes,
it generates an error noting that the call is ambiguous.
