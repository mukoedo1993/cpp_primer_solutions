

#include"StrVec_ver2.h"
#include"SterVec_implementation.h"
#include"Query_program.h"
	int main()
	{
		std::ifstream input("ex13_42i.txt");
		std::ofstream output;
		output.open("ex13_42o.txt", std::ofstream::out | std::ofstream::app);
		if (!input.is_open())exit(-1);
		TextQuery Ob1(input);
		string str;
		std::cout << "Warning! All data you checked are recorded!If you don't want to continue, press q: ";
		while(std::cin>>str)
		{
			if (str == "q") { std::cout << "\nEXIT!"; 
			output << "END OF SEARCHING AT THIS TIME!\n\n\n"; break;
			}
			print(std::cout, Ob1.query(str));
			print(output, Ob1.query(str));
			std::cout << "\n\nPlease enter next item: ";
		}
		input.close(); output.close();
	}
