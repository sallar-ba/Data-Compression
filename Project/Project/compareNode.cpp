#include "compareNode.h"

//+-+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-
// overload operator to compare two nodes frequency
bool compareNode::operator()(HuffmanTree* First, HuffmanTree* Second)
{
	return First->Huff.Freq > Second->Huff.Freq;
}
//-+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+--+-+-+-