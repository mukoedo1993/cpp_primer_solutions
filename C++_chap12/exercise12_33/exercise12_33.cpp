#include"Blob_ver5_3.h"
#include"query_program_classes_ver3.h"

int main()
{
	std::ifstream input("ex12_33i.txt");
	if (!input.is_open())exit(-1);
	runQueries(input);
}