#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
    std::cout << "All " << argc << " argument"
        << (argc > 1 ? "s are:" : " is:") << std::endl;
    for (int i = 0; i < argc; ++i)
        //'\t' is a horizontal tab:
        std::cout << i << "\t" << argv[i] << std::endl;
    
    return 0;
}
//Please see the video: 
//www.youtube.com/watch?v=IgbQCRHKV-Y
