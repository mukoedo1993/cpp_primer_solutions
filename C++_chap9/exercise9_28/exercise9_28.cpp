#include<forward_list>

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using std::string; using std::forward_list;
int main()
{
	string flag1,flag2;
	forward_list<string>flst = {"Useless_string"};//This is just a initializer.
	auto it = flst.begin();

	//Step 1:Input data from input txt file to the forward_list.
	string str;

	std::ifstream input("ex9_28i.txt");
	
	std::ofstream output("ex9_28o.txt");
	getline(input, str);
	std::stringstream Ob1(str);

	Ob1 >> flag1; Ob1 >> flag2;
	if (flag1 == "" || flag2 == ""||!input.is_open())
	{
		std::cerr << "Please enter correct paramter!" << std::endl;
		return 0;
	}
	string mkft;
		while (Ob1>> mkft)
		{
			
			it = flst.insert_after(it, mkft);
		}
		flst.pop_front();

	//Step 2: restructure our forward_list:

	auto now_ = flst.begin(); int flg_int = 0;
	 for (auto curr = flst.before_begin(); now_ != flst.end(); now_++)
	 {
		 if (*now_ == flag1&&flg_int==0)
		 {
			now_=flst.insert_after( now_,flag2);
			flg_int = 1; 
			output << "We find a first string." << std::endl;
			curr++;
		 }
		 curr++;
	 }
	 if (flg_int == 0)
	 {
		 output << "We didn't find a first string." << std::endl;
		 flst.insert_after(now_, flag2);
	 }

	 //step 3: print_out:
	 output << "first parameter: " << flag1 << std::endl << "Second parameter: " << flag2
		 << std::endl;
	 output << "Our results are:" << std::endl;
	 for (auto it_p = flst.begin(); it_p != flst.end(); it_p++)
	 {
		 output << *it_p << "  ";
	 }
	 
}
