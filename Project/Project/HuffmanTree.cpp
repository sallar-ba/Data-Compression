#include "HuffmanTree.h"
//-------------- Constructor ---------------------
HuffmanTree::HuffmanTree(char Symbol, int Frequency)
{
	//Assigning
	this->Symbol = Symbol;
	this->Frequency = Frequency;
	this->Left = this->Right = NULL;
}
//---------------------------------------------------