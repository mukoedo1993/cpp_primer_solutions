#include"Blob_ver5_2.h"
#include"query_program_classes_ver2.h"

int main()
{
	std::ifstream input("ex12_32i.txt");
	if (!input.is_open())exit(-1);
	runQueries(input);
}