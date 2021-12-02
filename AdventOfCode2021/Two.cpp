#include "Two.h"

#include <fstream>
#include <string>
#include <assert.h>
#include <iostream>
#include <format>

void Two::Run()
{
	std::ifstream infile("Inputs/Two.txt");

	int x = 0, y = 0, value, result;

	std::string input;
	while (std::getline(infile, input))
	{
		value = input[input.length() - 1] - 48; // char to int conversion

		switch (input[0])
		{
		case 'f':
			x += value;
			break;

		case 'd':
			y -= value;
			break;

		case 'u':
			y += value;
			break;

		default:
			assert(false);
			break;
		}
	}

	result = x * y;

	std::cout << std::format("The answer is {}.", result);

}
