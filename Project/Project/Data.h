#pragma once
// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-
class Data // data class
{
public:
	//Public Data Members
	int Freq; // For Storing Frequency
	char Symbol;	// For Storing Symbol or Character

	// ----- Constructors ----
	Data();
	Data(char);

	/////////// PUBLIC MEMBER FUNCTIONS /////////
	// Functions
	void insert(char);
	void insert(char, int); //Overloaded Function
};
// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-