#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<utility>
using std::map;
using std::string;
//We'll start by defining the word-transform function. The important parts
//are the calls to buildMap and transform.
const string&
transform(const string& s, const map<string, string>& m)
{
	//the actual map work; this part is the heart of the program
	map<string,string>::const_iterator map_it = m.find(s);
	//return of map::find:
	//An iterator to the element, if an element with specified key is found, or map::end otherwise.

	if (map_it != m.cend())
		return map_it->second;//use the repalcement word
	else
		return s; //otherwise return the original word

}

map<string, string>buildMap(std::ifstream& map_file)
{
	map<string, string>trans_map;//holds the transformation
	string key;//a word to transform
	string value;//phrase to use instead
	//read the first word into the key and the rest of the line into value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)//check that there is a transformation
			trans_map[key] = value.substr(1);//skip leading space
		else
			throw std::runtime_error("no rule for " + key);
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
	std::ifstream input1("sec11_3_6i1.txt"), input2("sec11_3_6i2.txt");
	std::ofstream output("sec11_3_6o.txt");
	 word_transform(input1,input2,output);
	 return 0;
}
