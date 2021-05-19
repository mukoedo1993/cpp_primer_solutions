
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string

int main () {
  std::cout << "Please, enter a number or a word: ";
  char c = std::cin.get();

  if ( (c >= '0') && (c <= '9') )
  {
    int n;
    std::cin.putback ('4');
    std::cin >> n;
    std::cout << "You entered a number: " << n << '\n';
  }
  else
  {
    std::string str;
    std::cin.putback (c);
    getline (std::cin,str);
    std::cout << "You entered a word: " << str << '\n';
  }
}
//Test 1:
/*
Please, enter a number or a word: 1029345
You entered a number: 4029345
*/
//Test 2:
/*
Please, enter a number or a word: nimasland
You entered a word: nimasland
*/