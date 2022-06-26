#pragma once
#include<iostream>
#include"Data.h"
using namespace std;
class HuffmanTree
{
public:
	/*char Symbol;
	int Frequency;*/
	Data Huff;
	HuffmanTree* Left;
	HuffmanTree* Right;

	//Constructor
	//HuffmanTree(char, int);
	HuffmanTree(Data);
};

