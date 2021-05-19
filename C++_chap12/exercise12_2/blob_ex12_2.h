#pragma once
#ifndef BLOB_EX12_2_H
#define BLOB_EX12_2_H
#include<vector>
#include<iostream>
#include<initializer_list>
#include<memory>
#include<stdexcept>
using std::vector; using std::cout; using std::string;
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<string>i1);
	size_type size()const { return data->size(); }
	//add and remove elements
	void push_back(const string& t) { data->push_back(t); }
	void pop_back();
	//element access
	string& front()const;
	string& back()const;
	string& front();
	string& back();
private:
	std::shared_ptr<vector<string>>data;
	//throws msg if data[i] isn't valid
	void check(size_type i, const string& msg)const;
};

//Starblob constructors
//Each constructor uses its constructor initializer list
StrBlob::StrBlob() :data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string>i1) : data(std::make_shared<vector<string>>(i1)) {}

//Element Access Members
void StrBlob::check(size_type i, const string& msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}


string& StrBlob::front()const
{
	//if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	std::cout << "Const front called\n";
	return data->front();
}

string& StrBlob::front()
{
	//if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	std::cout << "Ordinary front called\n";//printed out as I expected
	return data->front();
}

string& StrBlob::back()const
{
	check(0, "back on empty StrBlob");
	std::cout << "const back called\n";//printed out as I expected
	return data->back();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	std::cout << "Ordinary back called\n";//printed out as I expected
	return data->back();
}


void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");//printed out as I expected
	data->pop_back();
}


#endif