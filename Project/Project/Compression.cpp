#include "Compression.h"
#include<fstream>
//------------------------------------------------------------------------------
Compression::Compression()	//Default Constructor
{
	content = "";
	sizeOfData = 0;
}
//-----------------------------------------------------------------------------------------------------
void Compression::arrayOfCharacters(char character)
{
	for (int i = 0; i < sizeOfData; i++)
	{
		for (int j = 0; j < sizeOfData; j++)
		{
			if (arrayOfchar[i] != "")
			{
				arrayOfchar[i][j] = character; //Ask Huzaifa About This*********
			}

		}
	}
}
//-----------------------------------------------------------------------------
void Compression::readFromFile(string fileName)
{
	ifstream Read(fileName, ios::in);
	while (!Read.eof())
	{
		while (getline(Read, content))// saving in one string 
		{
			sizeOfData = content.length();// getting the whole text file size 
			arrayOfchar = new char* [sizeOfData];
		}
	}

	ifstream inFile(fileName);
	char c = ' ';
	int counter = 0;
	if (inFile.is_open()) {
		while (inFile.good()) {// the good function is to check whether the file is good enough to open or not
			inFile.get(c);// reading character by character
			// Play with the data
			if (counter != sizeOfData)
			{
				//cout << c;
				arrayOfCharacters(c);
				counter++;// the program was printing extra character thats why we use a counter
			}
		}
	}

	if (!inFile.eof() && inFile.fail())
		cout << "Error Reading: " << fileName << endl;

	inFile.close();
}

//------------------------------------------------------------------------------------------------------
int Compression::CountingFreq(char c)
{

}

//void Compression::Storing(char C)
//{
//	
//}