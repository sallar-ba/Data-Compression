#pragma once
#include<iostream>
using namespace std;
class HuffmanTree
{
public:
	char Symbol;
	int Frequency;
	HuffmanTree* Left;
	HuffmanTree* Right;

	//Constructor
	HuffmanTree(char, int);
};

