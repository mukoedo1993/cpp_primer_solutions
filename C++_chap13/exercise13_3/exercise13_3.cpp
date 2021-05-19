#include"StrBlob_StrBlobPtr.h"

int main()
{
	std::initializer_list<string> str_lst = {"sskr","kdkfj","union"};
	StrBlob StrBlobOb1(str_lst);
	StrBlob StrBlobOb2(StrBlobOb1);//copy element one by one
	StrBlobPtr StrBlobPtrOb1(StrBlobOb1);
	StrBlobPtr StrBlobPtrOb2(StrBlobPtrOb1);
}