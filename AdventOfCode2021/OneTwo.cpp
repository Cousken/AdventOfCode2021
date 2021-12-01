#include <fstream>
#include <iostream>
#include <format>

#include "OneTwo.h"

void OneTwo::Run()
{
	std::fstream infile("Inputs/One.txt");

	int first, second, third, fourth, count = 0;

	infile >> first >> second >> third;
	while (infile >> fourth)
	{
		int sumOne = first + second + third;
		int sumTwo = second + third + fourth;

		if (sumOne < sumTwo)
			count++;

		first = second;
		second = third;
		third = fourth;
	}

	std::cout << std::format("The solution is: {}.", count) << std::endl << "Press enter to exit application.";
}
