#include"Compression.h" // Adding Header
using namespace std;
int main()
{
	/*
	Styling
	*/
	int MAX_Row = 7, Max_Col = 15; // Defining Max Row and Col
	cout << endl; // End line
	for (int Row = 1; Row <= MAX_Row; Row++)  // For-Loop
	{
		cout << " ";//printing Space
		for (int Col = 1; Col <= Max_Col; Col++)//For-Loop
		{
			//For Printing the Box
			if (Row == 1 || Row == MAX_Row || Col == 1 || Col == Max_Col)
			{
				//Avoiding an Extra * At Printing Data Compression
				if (Row == 4 && Col == Max_Col)
				{
					cout << " "; //Printing Nothing
				}
				else
				{
					//Printing *
					cout << " * ";
				}
			}
			//For Printing Data Compression
			else if (Row == 4 && Col == 3)
			{
				//Printing Data Compression
				cout << "         Data Compression" << "\t    *"; // Last *
			}
			else
			{
				cout << "   ";//Printing Spaces
			}
		}
		cout << "\n";//Next Line
	}
	cout << endl << endl;
	//------------------ Styling Complete -----------------------------
	cout << " Press 1 for Default File\n Press 2 To Enter File" << endl;
	int choice = 0;//Declaring Variable
	while (choice != 1 && choice != 2)
	{
		cout << "\n Choice: "; cin >> choice;;//Input
		if (choice == 1)
		{
			Compression C; // Creating a Default Object
			C.Compress(); // Compressing
		}
		else if (choice == 2)
		{
			string fileName = " ";
			cout << "\n Enter File Name: "; cin >> fileName; // Input
			Compression C(fileName); // Creating Object with Input File Name
			C.Compress();//Compressing File
		}
	}

	system("pause>0");
	return 0;
}