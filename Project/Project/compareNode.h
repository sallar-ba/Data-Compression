#pragma once
#include"HuffmanTree.h" // including HuffmanTree Class
class compareNode // Class
{
public:
	//Public Member Function
	bool operator()(HuffmanTree*, HuffmanTree*); //Operator overloading
};
//-------------------------------------
