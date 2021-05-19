#include<iostream>
#include<algorithm>
static const int MMAX = 20;
static const int NMAX = 50000;
static const long int INFITY = 100000000;


int main()
{
	int n, m;//n is amount, m is number of types.

	//Step 0: give values:
	int Coins[NMAX] = {0};
	int Nums[MMAX];
	std::cout << "Please input amount and number of coin types:" << std::endl;
	std::cin >> n >> m;
	std::cout << "Please input value of different coin types, one by one:" << std::endl;
	for (int i1 = 0; i1 < m; i1++)
		std::cin >> Coins[i1];

	//Step 1: Initialize
	for (int i2 = 0; i2 <= n; i2++)
	{
		Nums[i2] = INFITY;
		
	}
	Nums[0] = 0;
	
	//Step 2: Dynamic Programming:
	int i3 ,i4;


	//if (0 < m) { std::cout << std::boolalpha; std::cout << true << std::endl; }
	//if(1+Coins[0]<=n) { std::cout << std::boolalpha; std::cout << true << std::endl; }


	for (i3 = 0; i3 < m; i3++)//i3 is the index of special type of coins
	{
		//std::cout << "We called it!" << std::endl;
		for (i4 = 0; i4 + Coins[i3] <= n; i4++)//i4+Types[i3] is the current amount
		{
			//std::cout << "Test! " << i4 + Coins[i3]<< std::endl;
			Nums[i4 + Coins[i3]] = std::min(Nums[i4 + Coins[i3]], Nums[i4] + 1);
			//std::cout << "Test! " << Nums[i4 + Coins[i3]] << std::endl;

		}
	}
	/*
	*
	*
	*/
	if (Nums[n] == INFITY)
		std::cerr << "Error!\n";
	else
		std::cout << "We need " << Nums[n] << " coins in total!";
}