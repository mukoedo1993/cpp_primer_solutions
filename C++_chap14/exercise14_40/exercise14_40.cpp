#include<algorithm>
#include<vector>
#include<iostream>
#include<fstream>
#include<iterator>
using std::string;using std::vector;
class String{
    public:String(std::ostream &os1=std::cout,char c1=' '):os(os1),c(c1){}
    void operator()(const string &s){os<<s<<c;}
    private: std::ostream &os;char c;
};

void biggies(vector<string> words,vector<string>::size_type sz,std::ostream &os=std::cout,
char c=' ')
{
	auto it = partition(words.begin(), words.end(), [sz](const string& a)
		{
			return a.size() < sz;
		});
	for_each(it, words.end(), String(os,c));

}

int main()
{ 
    std::ifstream input("ex14_38i.txt");
    std::istream_iterator<string>it1(input),eof;
    vector<string>v;
   while(it1!=eof)
   {
        v.push_back(*it1);
       it1++;
   }
   size_t sz1=7;
   biggies(v,7);
}