#include"Blob_ex17_3.h"
#include"query_program_classes_ver_ex17_3.h"
int main()
{
	std::ifstream input("ex17_3i.txt");
	if (!input.is_open())exit(-1);
	runQueries(input);
}