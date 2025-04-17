#pragma once
#pragma once
#include <string>

static void stringToWords(std::string src, std::string* words, int& size)
{
	std::string delimiters = "|";
	std::string tmp = src + " ";
	size = 0;

	size_t pos = tmp.find(delimiters);
	while (pos != std::string::npos)
	{
		pos = tmp.find(delimiters);
		words[size++] = tmp.substr(0, pos);
		tmp.erase(0, pos + 1);
	}
}