
cp: const char*
s2: string

string s(cp,n);
s is a copy of the first n characters in the array to which cp points. 
That array must have at least n characters.

string s(s2,pos2);
s is a copy of the characters in the string s2 starting at the index pos2.
undefined if pos2>s2.size().

string s(s2,pos2,len2);
[s2[pos2],s2[pos2+len2])


s.substr(pos,n)
Return a string containing n characters from  a starting at pos. Pos defaults to 0.
n defaults to a value that causes the library all the characters in a starting from pos.
(Attention! Only trailing omitting is allowed.)
substr(pos,...) or substr(...)
It could throw out a out_of_range error.

