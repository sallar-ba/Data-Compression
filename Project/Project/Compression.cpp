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
			while (getline(readFile, content))
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
	splitArray();

}
//----------------------------------------------------------
void Compression::splitArray()
{
	int Size = Array.size();
	Data* Huff = new Data[Size];
	for (int i = 0; i < Array.size(); i++)
	{
		Huff[i].insert(Array[i].Symbol, Array[i].Freq);
	}
	/* Passing to the function which encodes huffman(Makes Tree)
	and decodes into optimized codes as well */
	Decode(Huff, Size);
}
//----------------------------------------------------
HuffmanTree* Compression::Tree(priority_queue<HuffmanTree*, vector<HuffmanTree*>, compareNode> PQue)
{
	/* This function makes tree untill the pQue size becomes 1
	which will be the root node of the whole tree */
	while (PQue.size() != 1)// function is used to get size of the priority queue
	{
		// saving the top node in left
		HuffmanTree* Left = PQue.top(); //function is used to reference the top element of the priority queue

		// Poping the top node from Pque
		PQue.pop();

		//saving the second top node in right node
		HuffmanTree* Right = PQue.top(); //function is used to reference the top element of the priority queue

		// poping that from Pque
		PQue.pop();
		Data Check;
		Check.insert('@', Left->Huff.Freq + Right->Huff.Freq);// making new data node 
		HuffmanTree* newNode = new HuffmanTree(Check);
		// initiailizing the new node left and right child with the poped nodes 
		newNode->Left = Left;
		newNode->Right = Right;

		// Pushing the new node into the pQue
		PQue.push(newNode);
	}

	/* at the end the root node will be	returned
	from where we will decode the tree in binary codes */
	return PQue.top();

}
//---------------------------------------------------------------------
void Compression::Display(HuffmanTree* root, int Arr[], int top)
{
	/* If the node have the left element till the symbol initialize the Array[top]
		0 (because according too the huffman algorithm ) */
	if (root->Left) //assign 0 to the left child path
	{
		Arr[top] = 0;
		Display(root->Left, Arr, top + 1);// recursively call with top + 1 till the leaf node
	}
	/* If the node have the Right element till the symbol initialize the Array[top]
		1 (because according too the huffman algorithm ) */
	if (root->Right)// assign 1 to the right child path
	{
		Arr[top] = 1;
		Display(root->Right, Arr, top + 1);// recursively call with top + 1 till the leaf node
	}

	/* if the node doesnot contain leftand right child
	then it will be the leaf node then print the saved codes in Array */
	if (!root->Left && !root->Right)// if the leaf node appear with no left and right child
	{
		int counter = 0;
		cout << root->Huff.Symbol << " ";
		for (int i = 0; i < top; i++)
		{
			cout << Arr[i];
			counter++;// counting the optimised codes per symbols
		}
		for (int i = 0; i < Array.size(); i++)
		{
			// checking for the symbol 
			if (root->Huff.Symbol == Array[i].Symbol)
			{
				compressionRatio += Array[i].Freq * counter;// if found multiply with its frequency and add in compression Ratio
			}
		}
		//cout << " ";
		cout << endl;
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
	cout << "Compression Ratio is " << compressionRatio / Array.size() << endl;// final compression ratio 

}
//----------------------------------------------------------------------