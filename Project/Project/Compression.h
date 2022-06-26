#pragma once
#include<iostream> // Including Input/Output Lib.
#include<string> // Including String Lib.
#include<vector> // Including Vector Lib.
#include"Data.h"
#include"compareNode.h"
#include<queue>
#define Max_Size 100
using namespace std;
//--------------------------------------
class Compression // Compression Class
{
	//Private Data Members
private:
	string content;// the string which will read from the file
	string fileName; // for File Name
	vector<Data> Array;// Modifiable Array to Store Data
	int sizeOfData; // To Store Len. of Data
	float compressionRatio;//  to store compression ratio
public:
	//Public Member Function Prototypes
	Compression();// default constructor 
	Compression(string); // Parameterized Constructor
	void readFromFile();// Reading from the file
			
		// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-
	/*
	Storing Data in Vector (Modifiable Array)
	*/
	void storingInVector(); 
	// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-
/* Function to the Frequency of Each Character Present
   in File, Which is Copied in content Data Member by
   "readFromFile()" Function.
*/
	void calculatingFreq(int);
	//Printing Function
	void PrintCharWithFreq();

	//Function to Splot Arrays
	void splitArray();

	//Single Function to Compress all the Data
	void Compress();

	//Function To Make Huffman Tree
	HuffmanTree* Tree(priority_queue<HuffmanTree*, vector<HuffmanTree*>, compareNode>);

	//Display Function
	void Display(HuffmanTree*, int[], int);

	//Decoding into Huffman
	void Decode(Data[], int);
};
//--------------------------------------
