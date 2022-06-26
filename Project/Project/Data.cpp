#include "Data.h"
//---------------- Constructors ---------------------
Data::Data()
{
	//Assigning 
	this->Freq = 0;
	this->Symbol = ' ';
}
Data::Data(char Symbol)
{
	//Assigning 
	this->Freq = 1; // Assigned 1 Because Every character Will get Value 1
	this->Symbol = Symbol;
}
//------------------------------------------------
//---------------- Insert Functions ---------------------
void Data::insert(char Symbol)
{
	//Assigning 
	this->Freq = 1;
	this->Symbol = Symbol;
}
//overloaded Function
void Data::insert(char Symbol, int Freq)
{
	//Assigning 
	this->Freq = Freq;
	this->Symbol = Symbol;
}
//------------------------------------------------