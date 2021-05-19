#pragma once
//exercise 12_32:
#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<tuple>
#ifndef QUERY_PROGRAM_CLASSES_VER_EX_17_3_H
#define QUERY_PROGRAM_CLASSES_VER_EX_17_3_H
using line_no = std::vector<std::string>::size_type;
typedef  std::tuple<std::string, std::shared_ptr<std::set<line_no>>,std::shared_ptr<StrBlob>>  tuple3D;
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
class TextQuery {
public:

	TextQuery(std::ifstream&);

    
    std::tuple<std::string, std::shared_ptr<std::set<line_no>>,
		std::shared_ptr<StrBlob>>
 query(const std::string&)const;
private:
	std::shared_ptr<StrBlob>file;//input file
	//map of each word to the set of the lines in which the word appears
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};

//The TextQuery Constructor
//The TextQuery constructor takes an ifstream, which it reads a line at a time:

//read the input file and build the map of lines to line numbers
TextQuery::TextQuery(std::ifstream& is) :file(new StrBlob)
{
	std::string text;
	while (getline(is, text))//for each line in the file
	{
		file->push_back(text);//remember this line of text
		unsigned n = file->size() - 1;//the current line number
		std::istringstream line(text);//separate the line into words
		std::string word;
		while (line >> word)//for each word in that line
		{
			//if word isn't already in wm, subscripting adds a new entry
			auto& lines = wm[word];//lines is a shared_ptr
			if (!lines)
				lines.reset(new std::set<line_no>);//allocate a new set
			lines->insert(n);//insert this line number
			//NOTE_1: If word wasn;t in the map, the subscrpt operator adds word to wm. The element associated with
			//word is value initialized, which means that lines will be nullptr if the subscript opeartor added word to wm.
			//NOTE_2: If lines is null, we allocate a new set and call reset to update the shared_ptr to which lines refers to point to this
			//newly allocated set.
			//NOTE_3:Because lines is a reference, the call to insert adds an element to the set in wm.
		}
	}
}

//The QuertResult Class:
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<StrBlob>f) :sought(s), lines(p), file(f) {}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
public:
	std::shared_ptr<StrBlob>file;//input file

	//The constructor's only job is to store its arguments in the corresponding data members, 
	//which it does in the contructor initializer list.
};

  tuple3D
TextQuery::query(const std::string& sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm.
	auto loc = wm.find(sought);

	if (loc == wm.end())
		return tuple3D(sought, nodata, file);//not found
	else
		return tuple3D(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const tuple3D& qr)
{
          auto[sought,lines,file]=qr;//exercise17_3:
	//if the word was found, print the count and all occurences
	os << sought << " occurs " << lines->size() << " "
		<< make_plural(lines->size(), "time", "s") << std::endl;
	//print each line in which the word appeared
	
	for (auto num : *lines)
	{os << "\t(line " << num + 1 << ")"; 
	
	os << (file->data.get())->at(num) << std::endl;
	
	}
	

	return os;
}

void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin>>s)||s=="q")break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}
#endif