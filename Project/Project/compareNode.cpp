#include "compareNode.h"//Including Header
//+-+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-
// overload operator to compare two nodes frequency
bool compareNode::operator()(HuffmanTree* First, HuffmanTree* Second)
{
	/*
	Checking First Frequency to be Greater than the Second
	and returing True else False.
	*/
	return First->Huff.Freq > Second->Huff.Freq;
}
//-+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+-