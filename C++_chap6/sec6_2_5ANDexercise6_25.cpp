#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::cout << "All " << argc << " argument"
        << (argc > 1 ? "s are:" : " is:") << std::endl;
    for (int i = 0; i < argc; ++i)
        //'\t' is a horizontal tab:
        std::cout << i << "\t" << argv[i] << std::endl;
    if (argc < 3)  // programname argument1 argument2 0
        return -1;
    std::string args(argv[1]);
    args += argv[2];
    std::cout << args << std::endl;

    return 0;
}
/*
Question: What does int argc, char *argv[] mean?

1: argv and argc are how command line arguments are passed to main() in C and C++.

2: argc will be the number of strings pointed to by argv. 
This will (in practice) be 1 plus the number of arguments, 
as virtually all implementations will prepend the name of the program to the array.

3: The variables are named argc (argument count) and argv (argument vector) by convention, 
but they can be given any valid identifier: int main(int num_args, char** arg_strings) is equally valid.

4: They can also be omitted entirely, yielding int main(), 
if you do not intend to process command line arguments.

*/
//Please see the video: 
//www.youtube.com/watch?v=IgbQCRHKV-Y
