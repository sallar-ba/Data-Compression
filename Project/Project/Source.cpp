#include"Compression.h"
using namespace std;

struct DataFreq
{
	int Freq;
	char Character;
};


int main()
{
	string Name;
	Compression C1;
	cout << "Enter File Name: ";
	cin >> Name;
	C1.readFromFile(Name);
}