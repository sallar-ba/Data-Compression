#include"Compression.h"
using namespace std;

int main()
{
	string Name;
	int choice;
	cout << "1- File Locatio\n2- File Name" << endl;
	cout << "choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter File Location : ";
		cin >> Name;
		break;
	case 2:
		cout << "Enter File Name : ";
		cin >> Name;
		break;
	default:
		break;
	}
	//cout << "Enter File Location : ";
	//cin >> Name;
	Compression C1(Name);
	C1.Compress();

	system("pause>0");
	return 0;
}