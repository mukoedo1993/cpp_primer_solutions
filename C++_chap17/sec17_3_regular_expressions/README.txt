A regular expression is a way of describing a sequence of characters. Regular expressions are a stunningly 
powerful computational device. However, describing the languages used to define regular expressions is well beyond the
scope of the Primer. Instead, we'll focus on how to use the C++ regular-expression library (RE library), which is part
of the new library. The RE library, which is defined in the regex header, involves several components.
The regex class represents a regular expression. Aside from initialization and assignment, regex has few operations.
The function regex_match and regex_search determine whether a given character sequence matches a given regex.

The regex_match returns true if there is a substring in the input sequence that matches. There is also a regex_replace function.
The argument to the regex functions.
These functions return a bool and are overloaded: One version takes an additional argument of type smatch. If present, these
functions store additional information about a successful match in the given smatch object.
