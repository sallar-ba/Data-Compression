#pragma once
#include<iostream>
#include<string>
using namespace std;
class Compression
{
private:
	string content;// the string which will read from the file
	int sizeOfData;// Size Of the file 
	char** arrayOfchar;
public:
	Compression();// default constructor 
	void readFromFile(string);// Reading from the file
	void arrayOfCharacters(char);// apply huffman code in this function
};