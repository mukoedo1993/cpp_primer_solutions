//When we write a lambda, the compiler translates that expression into an unnamed object of an
//unnamed class. The classes generated from a lambda contain an overloaded function-call operator.
//e.g.1: stable_sort()
#include<iostream>
#include<algorithm>
#include<iterator>
#include<fstream>
#include<vector>
using std::string;using std::vector;
class ShorterString{
    public:
    bool operator()(const string&s1,const string&s2)
    {return s1.size()<s2.size();}
};

//Classes representing lambdas with captures
//As we've seen, when a lambda captures a variable by reference, it is up to the program to 
//ensure that the variable to which the reference refers to exists when the lambda is executed.
//Therefore the compiler is permitted to use the reference directly without storing the reference
//as a data member in the generated class.

//In contrast, variables that are captured by value are copied into the lambda. As a result,
//classes generated from lambdas that capture variables by value have data members corresponding
//to each such variable. These classes also have a constructor to initialize these data members
//from the value of the captured variables.

class SizeComp{
  public:
  SizeComp(size_t n):sz(n){}//parameter for each captured variable
  //call operator with the same return type, parameters, and body as the lambda.
  bool operator()(const string&s)const{return s.size()>=sz;}
  private:
  size_t sz;//a data member for each variable captured by value
};

int main()
{
    std::ifstream input("sec14_8_1i.txt");std::ofstream output1("sec14_8_1o1.txt");
    std::ofstream output2("sec14_8_1o2.txt");vector<string>words1;
    std::istream_iterator<string>input1(input),eof;
    std::ostream_iterator<string>out1(output1,"\n"),out2(output2,"\n");
     while(input1!=eof){
       words1.push_back(*input1);
       input1++;
     }
       auto words2=words1;auto words3=words1;auto words4=words1;
    //sort words by size, but maintain alphabetical order for words of the same size.
    std::stable_sort(words1.begin(),words1.end(),
    [](const string&a,const string&b){return a.size()<b.size();});

      //We can rewrite the call to stable_sort to use the class 
      //instead of the lambda expression:
    std::stable_sort(words2.begin(),words2.end(),ShorterString());
    //The thrid argument is a newly constructed ShorterString object. The code in stable_sort
    //will "call" this object each time it compares two strings. 
    copy(words1.cbegin(),words1.cend(),out1);
    copy(words2.cbegin(),words2.cend(),out2);


    size_t sz=11;
    vector<string>words_x={"sjd","dsj","djshsdffddfgdfsdsfd","dilutiondilutiondfahsfjsdjsf"};
    auto wc=find_if(words_x.cbegin(),words_x.cend(),[sz](const string &a){return a.size()>sz;});
    
    //Unlike our ShorterString class, this class has a data member  and a constructor to initialize
    //that member. This synthesized class does not have a default constructor; to use
    //the class, we must pass an argument:
    auto wc1=find_if(words_x.cbegin(),words_x.cend(),SizeComp(sz));
    std::cout<<"\n"<<*wc<<" "<<*wc1<<"\n";
}