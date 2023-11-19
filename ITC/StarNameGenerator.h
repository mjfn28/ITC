#pragma once
#include <string>
#include <stdlib.h>

using namespace std;

class StarNameGenerator 
{
public:
	static string GenerateName();

private:
	static string GetSuperscript();

	static string Syllables[];
	static string Prefixes[];
};