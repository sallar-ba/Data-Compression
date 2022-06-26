#include "Compression.h"
#include<fstream>
//-------------------- Constructors ---------------------------------------------
Compression::Compression()	//Default Constructor
{
	fileName = "Huffman.txt"; // Giving a Default File
}
Compression::Compression(string fileName) // Parameterized Constructor
{
	this->fileName = fileName;
}
//-----------------------------------------------------------------------------------------------------
void Compression::readFromFile()
{
	ifstream inFile(fileName); // Creating an Object

	if (!inFile) // If File is Not Present
	{
		cout << "File Does Not Exist..." << endl; // Printing Error 
		exit(1); // Exiting
	}
	else
	{
		ifstream readFile(fileName, ios::in); // Creating an Object
		while (!readFile.eof()) // Run Till End of File
		{
			// Copy Data From readFile to Content String
			while (getline(readFile, content) )
			{
				// getting the whole text file size 
				sizeOfData = content.length();
			}
		}
		readFile.close();
	}

}
//------------------------------------------------------------------------------------------------------
void Compression::storingInVector()
{
	ifstream inFile(fileName); // Creating an Object
	Data Obj; // Creating Object of Data

	// Declaring Variables
	char character = ' ';
	int counter = 0;

	if (!inFile) // If File is Not Present
	{
		cout << "File Does Not Exist..." << endl; // Printing Error 
		exit(1); // Exiting
	}
	else
	{
		if (inFile.is_open())
		{
			/* the good function is to check whether
			   the file is good enough
			   to open or not.
			*/
			while (inFile.good())
			{
				// reading character by character
				inFile.get(character);
				if (counter != sizeOfData)
				{
					Obj.insert(character);
					Array.push_back(Obj);
					counter++;
				}
			}
		}
	}
}
//------------------------------------------------------------
void Compression::calculatingFreq(int i = 2)
{
	//Made Recursive
	if (i == 0)
	{
		return;
	}
	else
	{
		//Nesting For Loop
		for (int i = 0; i < Array.size() - 1; i++)
		{
			for (int j = i + 1; j < Array.size(); j++)
			{
				if (Array[i].Symbol == Array[j].Symbol)
				{
					//Swapping
					char Temp = Array[j].Symbol;
					Array[j].Symbol = Array[Array.size() - 1].Symbol;
					Array[Array.size() - 1].Symbol = Temp;
					//Incrementing Freq
					Array[i].Freq = Array[i].Freq + 1;
					Array.pop_back(); // Removing Last
				}
			}
		}
		calculatingFreq(i - 1); //Calling The Function
	}


	
}
//----------------------------------------------------------
void Compression::PrintCharWithFreq()
{
	cout << "Symbol\tFreq." << endl;
	for (int i = 0; i < Array.size(); i++) //For-Loop
	{
		cout << Array[i].Symbol << "\t" << Array[i].Freq << endl;// Printing
	}
	cout << endl;
}
//----------------------------------------------------------
void Compression::Compress()
{
	readFromFile();
	storingInVector();
	calculatingFreq();
	PrintCharWithFreq();
}

