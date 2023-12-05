// Alese Florence
// CIS 
// Dec 6 2023

#include <iostream>

using namespace std;

class invalidCharacterException :public::exception
{
public:
	const char* what() const noexcept
		override
	{
		return "Invalid character exception";
	}
};

class invalidRangeException : public::exception
{
public:
	const char* what() const noexcept
		override
	{
		return "Invalid range exception";
	}
};

char character(char start, int offset)
{
	if (!isalpha(start))
	{
		throw invalidCharacterException();
	}
	char result = start + offset;
	if (!isalpha(result))
	{
		throw invalidRangeException();
	}
	return result;
}

int main()
{
	try
	{
		cout << "Character('a', 1): " << character('a', 1) << endl;
		cout << "Character ('a', -1): ";
		cout << character('a', -1) << endl;
		cout << "Character('Z', -1): " << character('Z', -1) << endl;
		cout << "character('?', 5): ";
		cout << character('?', 5) << endl;
		cout << "character('A', 32): ";
		cout << character('A', 32) << endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}