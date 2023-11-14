#pragma once
#include <string>
#include <stdlib.h>

using namespace std;

class StarNameGenerator 
{
public:
	static string GenerateName()
	{
		string result = "";

		int numSyllables = rand() % 4 + 1;

		for (int i = 0; i < numSyllables; i++)
		{
			result += Syllables[rand() % 20];
		}

		int prefixCheck = rand() % 4;

		if (prefixCheck == 3)
		{
			result = Prefixes[rand() % 5] + GetSuperscript() + " " + result;
		}

		return result;
	}

private:
	static string GetSuperscript()
	{
		string result = "";

		int check = rand() % 10;

		if (check == 9)
		{
			int superscript = rand() % 30;

			result += (char)(superscript + 252);
			
		}
		return result;
	}

	static string Syllables[];
	static string Prefixes[];
};

string StarNameGenerator::Syllables[] =
{
	"po",
	"la",
	"ris",
	"cen",
	"tau",
	"ri",
	"cae",
	"li",
	"ce",
	"ti",
	"dra",
	"co",
	"nis",
	"e",
	"ri",
	"da",
	"ni",
	"vo",
	"lan",
	"tis"
};

string StarNameGenerator::Prefixes[] =
{
	"alpha",
	"beta",
	"gamma",
	"delta",
	"epsilon"
};