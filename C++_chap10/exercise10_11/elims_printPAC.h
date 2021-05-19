#pragma once
#ifndef ELIMS_PRINTPAC_H
#define ELIMS_PRINTPAC_H

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

std::ostream& print(const vector<string>& words, std::ostream& os)
{
	for (auto it = words.begin(); it < words.end(); it++)
	{
		os << *it << "; ";
	}
	os << endl;
	return os;
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


#endif
