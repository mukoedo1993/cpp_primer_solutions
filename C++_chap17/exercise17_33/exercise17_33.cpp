#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<utility>
#include<vector>
#include<random>
#include<ctime>
#include<sstream>
using std::map;
using std::string;
using std::vector;
//We'll start by defining the word-transform function. The important parts
//are the calls to buildMap and transform.
const string&
transform(const string& s, const map<string, vector<string>>& m)
{
	//the actual map work; this part is the heart of the program
	map<string,vector<string>>::const_iterator map_it = m.find(s);
	//return of map::find:
	//An iterator to the element, if an element with specified key is found, or map::end otherwise.
    static std::default_random_engine e(time(0)); 
    std::uniform_int_distribution<unsigned>uid(0,(map_it->second).size()-1);
unsigned indx= uid(e);
	if (map_it != m.cend())
    {
		return (map_it->second)[indx];//use the repalcement word
    }
	else {
        
		return s;
    }
        //otherwise return the original word


}

map<string, vector<string>>buildMap(std::ifstream& map_file)
{
	map<string, vector<string>>trans_map;//holds the transformation
	string key;//a word to transform
	string value;//phrase to use instead
	//read the first word into the key and the rest of the line into value
	while (map_file >> key && getline(map_file, value))
	{	
            if (value.size() > 1)//check that there is a transformation
			{
                std::string mkft2;
                std::string mkft_str = value;//skip leading space
                std::istringstream Ob1(mkft_str);
                while(Ob1>>mkft2)
                {
                (trans_map[key]).push_back(mkft2);
               
                }
            }
		else
			throw std::runtime_error("no rule for " + key);
    }
	return trans_map;
}



void word_transform(std::ifstream& map_file, std::ifstream& input,std::ostream &output)
{
	
	auto trans_map = buildMap(map_file);//store the transformations.
	string text;                        //hold each line from the input
	while (getline(input, text)) {     //read a line of input
		std::istringstream stream(text);//read each word
		string word;
		bool firstword = true;//control whether a space is printed
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				output << " ";//print a space between words
			//transform returns its first argument or its transformation
		output << transform(word, trans_map);//print the output
        
		}
		output<< std::endl;//done with the line of input
	}
}


int main()
{

	std::ifstream input1("sec17_33i1.txt"), input2("sec17_33i2.txt");
	std::ofstream output("sec17_33o.txt",std::ofstream::out | std::ofstream::app);
    output<<"Test made at: "<<__TIME__<<"\nand on:"<<__DATE__<<std::endl;
	 word_transform(input1,input2,output);
     output<<std::endl<<std::endl;
     input1.close();input2.close();output.close();
	 return 0;
}