
I solved both two questions.
The main function called the required constructor on question 40 and called reserve, capacity and resize functions.
Update:(Sep 17th) the original solutions are wrong. Corrected already.
The names of files are, actually strange. Ignore this.

reserve policy:
StrVec::reserve(size_t sz){
if(sz>capacity) reserve 2*sz;
endif
}
