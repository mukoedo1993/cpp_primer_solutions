Question:
By default, the allocator class uses operator new to obtain storage and
operator delete to free it. Recompile and return your StrVec programs using your versions of the functions from the previous exercise.


Note:
Actually, I added a C-style operator new and a operator delete in the main file. The allocator class will automatically search a global new and global
delete and used them if find out. 
