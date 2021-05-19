#include<iostream>
#include<fstream>

using std::ifstream; using std::ofstream;
using std::string; using std::fstream;

int main()
{
	//file1 is truncated in each of these cases
	ofstream out("file1");//out and trunc are implicit
	ofstream out("file1", ofstream::out);//trunc is impliciy
	ofstream out("file1", ofstream::out|ofstream::trunc);

	//to preserve the file's contecnts, we must explicitly specify app mode
	ofstream app("file2", ofstream::app);//out is implicit
	ofstream app("file2", ofstream::out | ofstream::app);

}