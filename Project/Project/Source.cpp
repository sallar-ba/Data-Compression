#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Node
{
	int Data;
	Node* Left;
	Node* Right;
};

class Compression
{
public:
	Compression();// default constructor 
	void readFromFile(string);// Reading from the file
	void arrayOfCharacters(char);// apply huffman code in this function

private:
	string content;// the string which will read from the file
	int sizeOfData;// Size Of the file 
	char** arrayOfchar;
};

Compression::Compression()
{
	content = "";
	sizeOfData = 0;
}

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

	ifstream in(fileName);
	char c;
	int counter = 0;
	if (in.is_open()) {
		while (in.good()) {// the good function is to check whether the file is good enough to open or not
			in.get(c);// reading character by character
			// Play with the data
			if (counter != sizeOfData)
			{
				//cout << c;
				arrayOfCharacters(c);
				counter++;// the program was printing extra character thats why we use a counter
			}
		}
	}

	if (!in.eof() && in.fail())
		cout << "error reading " << fileName << endl;

	in.close();
}

void Compression::arrayOfCharacters(char character)
{
	for (int i = 0; i < sizeOfData; i++)
	{
		for (int j = 0; j < sizeOfData; j++)
		{
			if (arrayOfchar[i] != "")
			{
				arrayOfchar[i][j] = character;
			}

		}
	}
}

int main()
{
	string Name;
	Compression C1;
	cout << "Enter Name of File : ";
	cin >> Name;
	C1.readFromFile(Name);
}