#include<vector>
#include<string>
#include<iostream>
//https://blog.csdn.net/weiwjacsdn/article/details/79921567?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.edu_weight&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.edu_weight
using std::vector; 
int cnt = 0;
int coins(vector<int> types,int amount)
{
	auto amnt = amount;
	cnt++;
	if (cnt > 1000)return -3;
	std::cout << "cnt is: " << cnt << std::endl;
	if (*(types.end() - 1) < amount)
	{
		std::cout << "we use the coin: " << *(types.end()-1) << std::endl;
		amnt =amnt-*(types.end() - 1);
		std::cout << "the amount left:" << amnt << std::endl<<std::endl;
		return coins(types, amnt);
	}
	else
	{
		for (int i = types.size() - 2; i > -1; i--)
		{
			if (types[i] < amnt)
			{
				std::cout << "we use the coin: " << types[i] << std::endl;
				std::cout << "the amount left:" << amount - types[i] << std::endl << std::endl;
				return coins(types, amount - types[i]);
			}
			if (types[i] == amnt)
			{
				std::cout << "The last coin we use:" <<types[i]<< std::endl;
				return cnt;
			}
			if (types[0] > amnt)
				throw(-3);
			
		}
	}
}
int main()
{
	try {
		vector<int>k = { 2,3,13,17 };
		std::cout << "In total,we use:" << coins(k, 1950) << " times.\n";
	}
	catch (...) { std::cout << "Awful! Failure!"; }
}