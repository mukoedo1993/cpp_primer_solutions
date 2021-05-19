#include<iostream>
#include<vector>
using std::string;
int main()
{
	std::vector<int> vec1;
	int word;
	while (std::cin >> word)
	{
		if (word == 500)break;
		vec1.push_back(word);
	}
	std::cout <<"SCP-500, cure all!"<< vec1[5]<<std::endl;
	std::vector<string> vec2;
	string word1;
	while (std::cin >> word1)
	{
		if (word1 == "SCP_500")break;
		vec1.push_back(word);
	}
	std::cout << "SCP-500, Cure all!" << vec1[5] << std::endl;
}