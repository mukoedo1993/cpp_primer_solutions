!!!!sec8_3_1 also finished exercise 8.13.

**Please check the backup directory. Some files could only be found here.***


!!!
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch8/8.9.cpp

The IO classes

IO library types and headers

#Header: iostream
Type 1: istream,wistream reads from a stream
Type 2: ostream, wostream writes to a stream
Type 3: iostream, wiostream reads and writes a stream

#Header: fstream: 
Type 1: ifstream, wifstream reads from a file
Type 2: ostream, wofstream writes to a file
Type 3: fstream, wfstream reads and writes a file

#Header: sstream:
Type 1: isstringstream, wistringstream reads from a string
Type 2: ostringstream, wostringstream writes to a string
Type 3: stringstream, wstringstream reads and writes a string



IOclass
condition state::
The IO classes define functions and flags, listed in Table 8-2, that
let us access and manipulate the condition state of a stream. 

The right way to determine the overall state of either good or fail:
s.good()
s.fail()

Attention!!!
s.bad()
s.eof()
only reveal specific errors have occured.
