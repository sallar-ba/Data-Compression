#include "Compression.h"
#include<fstream>
//---------------------------------------- Constructors ---------------------------------------------
//Default Constructor
Compression::Compression()	
{
	// Giving a Default File
	fileName = "Huffman.txt"; 
}
// Parameterized Constructor
Compression::Compression(string fileName) 
{
	//Assigning
	this->fileName = fileName;
}
//-----------------------------------------------------------------------------------------------------
void Compression::readFromFile()
{
	// Creating an Object
	ifstream inFile(fileName); 

	// If File is Not Present
	if (!inFile) 
	{
		// Printing Error 
		cout << "File Does Not Exist..." << endl; 
		// Exiting
		exit(1); 
	}
	else
	{
		// Creating an Object
		ifstream readFile(fileName, ios::in); 
		// Run Till End of File
		while (!readFile.eof()) 
		{
			// Copy Data From readFile to Content String
			while (getline(readFile, content) )
			{
				// getting the whole text file size 
				sizeOfData = content.length();
			}
		}
		//Closing the File
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
		//Ending The Function
		return;
	}
	else
	{
		//Nesting For Loop
		for (int i = 0; i < Array.size() - 1; i++)
		{
			//For-Loop
			for (int j = i + 1; j < Array.size(); j++)
			{
				//Finding Duplicate Symbol
				if (Array[i].Symbol == Array[j].Symbol)
				{
					/*
					* Swapping the Found Symbol with the Last Element
					*/ 
					char Temp = Array[j].Symbol;
					Array[j].Symbol = Array[Array.size() - 1].Symbol;
					Array[Array.size() - 1].Symbol = Temp;
					//Incrementing Freq
					Array[i].Freq = Array[i].Freq + 1;
					// Removing Last
					Array.pop_back(); 
				}
			}
		}
		calculatingFreq(i - 1); //Calling The Function
	}


	
}
//----------------------------------------------------------
void Compression::PrintCharWithFreq()
{
	//Telling That Printing Symbols
	cout << "Symbols:   ";
	//For-Loop
	for (int i = 0; i < Array.size(); i++) 
	{
		// Printing Symbols
		cout << "\'" << Array[i].Symbol << "\'\t";
	}
	//Telling That Printing Frequency
	cout << "\n\nFrequency: ";
	for (int i = 0; i < Array.size(); i++) 
	{
		// Printing Frequency
		cout  << " " << Array[i].Freq << " \t";
	}
	//End Lines
	cout << endl << endl;
}
//----------------------------------------------------------
void Compression::Compress()
{
	//Function Call to Read Content From File
	readFromFile();
	//Function Call to Store Content Into Vector (Array)
	storingInVector();
	//Function Call To Calculate Frequency
	calculatingFreq();
	//Function Call To Print Characters With Frequency
	PrintCharWithFreq();
	//Splitting Array
	createArray();

}
//----------------------------------------------------------
void Compression::createArray()
{
	//Creating an Array of Data Object of Size of Vector
	Data* Huff = new Data[Array.size()];
	//For-Loop
	for (int i = 0; i < Array.size(); i++)
	{
		//Storing Data i.e Symbol and Frequency in Data Array
		Huff[i].insert(Array[i].Symbol, Array[i].Freq);
	}
	//Calling Function to Decode
	Decode(Huff, Array.size());
}
//----------------------------------------------------
HuffmanTree* Compression::Tree(priority_queue<HuffmanTree*, vector<HuffmanTree*>, compareNode> PQue)
{
	while (PQue.size() != 1)// function is used to get size of the priority queue
	{
		HuffmanTree* Left = PQue.top(); //function is used to reference the top element of the priority queue

		PQue.pop();

		HuffmanTree* Right = PQue.top(); //function is used to reference the top element of the priority queue

		PQue.pop();
		Data Check;
		Check.insert('@', Left->Huff.Freq + Right->Huff.Freq);
		HuffmanTree* newNode = new HuffmanTree(Check);// Assigning random character after addition
		newNode->Left = Left;
		newNode->Right = Right;

		PQue.push(newNode);
	}

	return PQue.top();

}
//---------------------------------------------------------------------
void Compression::Display(HuffmanTree* root, int Array[], int top)
{
	if (root->Left) //assign 0 to the left child path
	{
		Array[top] = 0;
		Display(root->Left, Array, top + 1);
	}
	if (root->Right)// assign 1 to the right child path
	{
		Array[top] = 1;
		Display(root->Right, Array, top + 1);
	}
	if (!root->Left && !root->Right)// if the leaf node appear with no left and right child
	{
		//cout << root->Symbol << " ";
		for (int i = 0; i < top; i++)
		{
			cout << Array[i];
		}
		cout << " ";
		//cout << endl;
	}
}
//----------------------------------------------------------------
void Compression::Decode(Data Huff[], int size)
{
	priority_queue<HuffmanTree*, vector<HuffmanTree*>, compareNode>Pq;// priority Queue object

	for (int i = 0; i < size; i++)
	{
		HuffmanTree* newNode = new HuffmanTree(Huff[i]);
		Pq.push(newNode);// pushing into the queue
	}
	HuffmanTree* root = Tree(Pq);// making huffman encoding tree
	int arr[Max_Size], top = 0;
	Display(root, arr, top);// print the optimized codes
}
//----------------------------------------------------------------------