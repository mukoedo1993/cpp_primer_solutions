#include<unordered_map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<utility>
using std::unordered_map;
using std::string;
//We'll start by defining the word-transform function. The important parts
//are the calls to buildunordered_map and transform.
const string&
transform(const string& s, const unordered_map<string, string>& m)
{
	//the actual unordered_map work; this part is the heart of the program
	unordered_map<string, string>::const_iterator unordered_map_it = m.find(s);
	//return of unordered_map::find:
	//An iterator to the element, if an element with specified key is found, or unordered_map::end otherwise.

	if (unordered_map_it != m.cend())
		return unordered_map_it->second;//use the repalcement word
	else
		return s; //otherwise return the original word

}

unordered_map<string, string>buildunordered_map(std::ifstream& unordered_map_file)
{
	unordered_map<string, string>trans_unordered_map;//holds the transformation
	string key;//a word to transform
	string value;//phrase to use instead
	//read the first word into the key and the rest of the line into value
	while (unordered_map_file >> key && getline(unordered_map_file, value))
		if (value.size() > 1)//check that there is a transformation
			trans_unordered_map[key] = value.substr(1);//skip leading space
		else
			throw std::runtime_error("no rule for " + key);
	return trans_unordered_map;
}

void word_transform(std::ifstream& unordered_map_file, std::ifstream& input, std::ostream& output)
{

	auto trans_unordered_map = buildunordered_map(unordered_map_file);//store the transformations.
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
			output << transform(word, trans_unordered_map);//print the output
		}
		output << std::endl;//done with the line of input
	}
}

int main()
{
	std::ifstream input1("ex11_38i1.txt"), input2("ex11_38i2.txt");
	if (!input1.is_open())exit(-1); if (!input2.is_open())exit(-1);
	std::ofstream output("ex11_38o.txt");
	word_transform(input1, input2, output);
	input1.close(); input2.close(); output.close();
	return 0;
}