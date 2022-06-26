#include"Compression.h"
using namespace std;

int main()
{
	string Name = "Huffman.txt";
	Compression C1(Name);
	C1.Compress(); 

	system("pause>0");
	return 0;
}