#include "Compression.h"
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
			while (getline(readFile, content))
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
	int counter = 0; // Variable for Counting

	if (!inFile) // If File is Not Present
	{
		// Printing Error 
		cout << "File Does Not Exist..." << endl; 
		// Exiting
		exit(1); 
	}
	else
	{
			/* the good function is to check whether
			   the file is good enough
			   to open or not.
			*/
			while (inFile.good())
			{
				// reading character by character
				inFile.get(character); // Getting Character From File
				// Did This Because It Was Printing an Extra Character
				if (counter != sizeOfData) 
				{
					Obj.insert(character);//inserting Character into the Data Obj
					Array.push_back(Obj); // Pushing Data into vectors
					counter++; // Incrementing Counter
				}
			}
		inFile.close();
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
	cout << endl;
	//Telling That Printing Symbols
	cout << " Symbols:\tFrequency:\n" << endl;
	//For-Loop
	for (int i = 0; i < Array.size(); i++) 
	{
		// Printing Symbols & Frequency
		cout << setw(4) << setfill(' ') << "\'" << Array[i].Symbol << "\'\t\t" << setw(5) << setfill(' ') << Array[i].Freq << endl;
	}
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
	//Calling the Decode Function
	Decode(Huff, Array.size());
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
		//Printing Symbol
		cout << setw(3) << setfill(' ') << "\'" << root->Huff.Symbol << "\' " << setw(15) << setfill(' ');
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
	// priority Queue object
	priority_queue<HuffmanTree*, vector<HuffmanTree*>, compareNode>Pq;

	for (int i = 0; i < size; i++)
	{
		HuffmanTree* newNode = new HuffmanTree(Huff[i]);
		Pq.push(newNode);// pushing into the queue
	}
	// making huffman encoding tree
	HuffmanTree* root = Tree(Pq);
	int arr[Max_Size], top = 0;
	// print the optimized codes
	cout << " Symbol:\t    Codes:\n" << endl;
	Display(root, arr, top);
	// Printing final compression ratio 
	cout << "\n  Compression Ratio: " << compressionRatio / Array.size() << endl;

}
//----------------------------------------------------------------------