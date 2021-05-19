1 cpp file and 1 header file.
Although I rewrite the for-loop of the void free() function, I add a vector to store pointers between the [elements, first_free).
Anyway, for_each needs to take two iterators rather than two pointers.
I hope that in the future I could find a better solution.
