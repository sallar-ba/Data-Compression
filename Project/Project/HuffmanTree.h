#pragma once
#include<iostream> // inclusing I/O Lib.
#include"Data.h" // including Data Class
using namespace std;
//-------------------------------
class HuffmanTree //class
{
public:
	/*char Symbol;
	int Frequency;*/
	Data Huff; //Object
	//-----------------------
	HuffmanTree* Left;
	HuffmanTree* Right;
	//-----------------------
	//Constructor
	HuffmanTree(Data); //Parameterized
};
//-------------------------------------