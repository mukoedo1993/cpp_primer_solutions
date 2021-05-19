#pragma once
#ifndef ELIMS_PRINTPAC_VER_1_1_H
#define ELIMS_PRINTPAC_VER_1_1_H

#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;
//print all strings from a vector:
//elimDups(in textbook)
//elimDups(for exercise)
//isshorter
//make_plural
//isShorter

string make_plural(size_t ctr, const string& word,
	const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream& print(const vector<string>& words, std::ostream& os)
{
	for (auto it = words.begin(); it < words.end(); it++)
	{
		os << *it << "; ";
	}
	os << endl;
	return os;
}

void elimDups(vector<string>& words)
{
	//sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());
	//unique reorders the input range so that eachword appears once
	//in the front portion of the range returns a iterator one past the unique range
	auto end_unique = unique(words.begin(), words.end());
	//erase uses a vector operation to remove the nonunique elements
	words.erase(end_unique, words.end());
}


void elimDups(vector<string>& words, std::ostream& os)
{

	sort(words.begin(), words.end());
	os << "The sorted words are:\n";
	print(words, os);

	auto end_unique = unique(words.begin(), words.end());
	os << "After put all repeated words at the end:\n";
	print(words, os);

	words.erase(end_unique, words.end());
	os << "Then,delete all repeated words:\n";
	print(words, os);
}
bool isShorter(const string &s1,const string&s2)
	{
	return s1.size() < s2.size();
	}

#endif
