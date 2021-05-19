#include<iostream>
#include<random>
#include<vector>
#include<cmath>


int main()
{
    /*Generating Random Real Numbers*/
    //Programs often need a source of random floating-point values.
    //In particular, programs frequently need random numbers between 
    //zero and one.

    std::default_random_engine e;//generate unsigned random integers
    std::uniform_real_distribution<double>U(0,1);
    for(size_t i=0;i<10;++i)
    std::cout<<U(e)<<" ";

    /*Using the Distribution's Default Result Type*/
    //empty <> signify we want to use the default result type
    std::uniform_real_distribution<> u1(0,1);//generates double by default

    /*Generating numbers that are not uniformly distributed*/
    //Because normal distribution generates floating point numbers, our program will use
    //the lround function to round each result to its nearest integer.
    //No. 200, mean 4,std. 1.5.
    std::default_random_engine e2;//generates random integers
    std::normal_distribution<> n(4,1.5);
    std::vector<unsigned>vals(9);//nine elements each 0
    for(size_t i=0;i!=200;++i){
        unsigned v=lround(n(e2));//round to the nearest integer
        if(v<vals.size())//if this result is in range
        ++vals[v];//count how often each number 
    }
    for(size_t j=0;j!=vals.size();++j)
    {
        std::cout<<j<<": "<<std::string(vals[j],'*')<<std::endl;
    }

    /*The bernoulli_distribution class*/

    std::string resp;
    std::default_random_engine e_yaju;//e has state, so it must be outside the loop
    std::bernoulli_distribution b;//50/50 odds by default
    do{
        bool first=b(e_yaju);//if true, the program will go first
        std::cout<<(first?"We go first":"You get to go first")<<std::endl;
        //play the game passing the indicator of who goes first
        std::cout<<(first?"sorry, you lost"
        :"congrats, you won")<<std::endl;
         std::cout<<"play again? ENter 'yes' or 'no' "<<std::endl;
    }while(std::cin>>resp&&resp[0]=='y');
   std::bernoulli_distribution b_kimura(.55);//give the house a slight edge
   //If we use this definition for b, then the program has 55/45 odds of going first.
}
/*

0.131538 0.45865 0.218959 0.678865 0.934693 0.519416 0.0345721 0.5297 0.00769819 0.0668422 0: ***
1: ********
2: ********************
3: **************************************
4: **********************************************************
5: ******************************************
6: ***********************
7: *******
8: *
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
You get to go first
congrats, you won
play again? ENter 'yes' or 'no' 
y
You get to go first
congrats, you won
play again? ENter 'yes' or 'no' 
y
You get to go first
congrats, you won
play again? ENter 'yes' or 'no' 
y
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
You get to go first
congrats, you won
play again? ENter 'yes' or 'no' 
y
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
We go first
sorry, you lost
play again? ENter 'yes' or 'no' 
y
You get to go first
congrats, you won
play again? ENter 'yes' or 'no' 


*/