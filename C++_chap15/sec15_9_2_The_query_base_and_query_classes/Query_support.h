#pragma once
//Sec. 15.9 

#ifndef QUERY_SUPPORT_H
#define QUERY_SUPPORT_H
#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>

using line_no = std::vector<std::string>::size_type;
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
class TextQuery {
public:

	using line_no = std::vector<std::string>::size_type;//I have to add this line.
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;//input file
	//map of each word to the set of the lines in which the word appears
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};
TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
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
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
	std::shared_ptr<std::vector<std::string>>file;//input file
};

QueryResult
TextQuery::query(const std::string& sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm.
	auto loc = wm.find(sought);

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);//not found
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	//if the word was found, print the count and all occurences
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines)//for every element in the set
		//don't confound the user with text lines starting at 0
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin()+num)<<std::endl;
	return os;
}
#endif