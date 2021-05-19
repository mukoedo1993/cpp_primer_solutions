#include<iostream>
#include<fstream>

int main()
{
    char k[20];
    std::ifstream input;
    input.open("ex17_38i_getline.txt");
    std::string str;int ch;
    while(input.getline(k,20,','))
    
          std::cout<<k;
        input.close();
}

/*

chaos sdsdfsfd
kerosene fdeer
dkks fdfd

13372
*/