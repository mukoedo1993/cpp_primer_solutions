
//The rand function has several problems: Many, if not most, programs need random
//numbers in a different range from the one produced by rand.

//The random-number library, defined in the random header, solves these problems through
//a set of corperating classes: random-number engines and random number distribution classes.


#include<iostream>
#include<random>
#include <cmath>
#include<ctime>
#include <string>
#include<vector>
//almost surely the wrong wat to generate a vector of random integers
//output from this function will be the same 100 numbers on every call!
std::vector<unsigned>bad_randVec()
{
  std::default_random_engine e;
  std::uniform_int_distribution<unsigned>u(0,9);
  std::vector<unsigned>ret;
  for(size_t i=0;i<100;i++)
  ret.push_back(u(e));
  return ret;
}

std::vector<unsigned>good_randVec()
{
    //because engines and distributions retain state, they usu. should be
    //defined as static so that new numbers are generated on each call.
  static std::default_random_engine e;
  static std::uniform_int_distribution<unsigned>u(0,9);
  std::vector<unsigned>ret;
  for(size_t i=0;i<100;i++)
  ret.push_back(u(e));
  return ret;
  /*
  Because e and u are static, they will hold their state across calls to the function.
  The first call will use the first 100 random numbers from the sequence u(e) generates,
  the second call will get the next 100, and so on.
  */
}



int main()
{
    std::default_random_engine e;//
    for(size_t i=0;i<10;++i)
    {
        std::cout<<e()<<" ";
    }
    std::cout<<"\n";
    /*Distribution Types and Engines*/
    //To get a number in a specified range, we use an object of a distribution type:
    //uniformly distributed from 0 to 9 inclusive
    std::uniform_int_distribution<unsigned>u(0,9);
    std::default_random_engine e1;//geenrate unsigned random integers
    for(size_t i=0;i<10;++i)
    {
        std::cout<<u(e1)<<" ";
    }
    //u uses e as a source of numbers
    //each call returns a uniformly distributed value in the specified range
    //we pass the engine, not the next result of the engine, because some distributions
    //may need to call the engine more than once.

    /*Comparing Random Engines and the rand Function*/
    //range for rand: 0 to RAND_MAX
    std::cout<<"\n"<<"min: "<<e.min()<<"max: "<<e.max()<<std::endl;


    //However, this function will return the same vector every time it is called:
std::vector<unsigned>v1(bad_randVec());
std::vector<unsigned>v2(bad_randVec());
//will print true
std::cout<<std::boolalpha<<(v1==v2);
/*seeding a generator*/
//A seed is a value that an engine in one of two ways: We can provide the seed when
//we create an engine object, or we can call the engine's seed member:
std::default_random_engine e1_;//uses the default 
std::default_random_engine e2_(2147483646);//use the given seed value
//e3 and e4 will generate the same sequence because they use the same seed
std::default_random_engine e3_;//use the default seed value
e3_.seed(32767);//call seed to set a new seed value
std::default_random_engine e4_(32767);//call seed to set a new seed value
for (size_t i=0;i!=100;++i)
{
  if(e1_()==e2_())
  std::cout<<"unseeded match at iteration: "<<i<<std::endl;
  if(e3_()!=e4_())
  std::cout<<"seeded differs at iteration: "<<i<<std::endl;
}

std::default_random_engine e1__(time(0));//a somewhat random seed
}

/*

16807 282475249 1622650073 984943658 1144108930 470211272 101027544 1457850878 1458777923 2007237709 
0 1 7 4 5 2 0 6 6 9 
min: 1max: 2147483646
true

*/