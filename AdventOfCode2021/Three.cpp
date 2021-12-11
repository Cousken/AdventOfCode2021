#include "Three.h"

#include <algorithm>
#include <utility>
#include <vector>
#include <bitset>
#include <cassert>
#include <iostream>
#include <format>
#include <ranges>

struct Pair
{
	Pair()
	{
		Zero = 0;
		One = 0;
	}

	int Zero;
	int One;
};

void Three::Run()
{
	auto infile = GetFile("Inputs/Three.txt");

	std::string line;
	const int nbrOfColumns = 12;
	int rowCount = 0;
	std::vector<Pair> columns(nbrOfColumns);
	std::vector<std::string> binStrInput;

	while (std::getline(infile, line))
	{
		for (int index = 0; index < nbrOfColumns; index++)
		{
			char c = line[index];
			Pair& value = columns[index];

			if (c == '0')
				value.Zero++;
			else
				value.One++;
		}

		binStrInput.emplace_back(line);

		rowCount++; // for debugging / error checking
	}

#pragma region calculateGamma

	std::bitset<nbrOfColumns> gammaRate(0);

	for (int index = 0; index < nbrOfColumns; index++)
	{
		auto& bitCount = columns[index];
		assert(bitCount.One != bitCount.Zero);
		assert((bitCount.One + bitCount.Zero) == rowCount);

		if (bitCount.One >= bitCount.Zero)
			gammaRate[nbrOfColumns - index - 1] = 1; // bitset has reversed index, correct for binary numbers
	}

	auto epsilonRate = std::bitset<nbrOfColumns>(gammaRate);
	epsilonRate.flip();

#pragma endregion calculateGamma

	std::cout << std::format("GammaRate equals {} binary or {} decimal.", gammaRate.to_string(), gammaRate.to_ulong()) << std::endl;
	std::cout << std::format("EpsilonRate equals {} binary or {} decimal.", epsilonRate.to_string(), epsilonRate.to_ulong()) << std::endl;

	unsigned long powerUse = (gammaRate.to_ulong() * epsilonRate.to_ulong());
	std::cout << std::format("Power Consumption: {}", powerUse) << std::endl << std::endl;

	// 1471406 wrong, too low

	// PART TWO

	std::vector<std::string> current = binStrInput, filtered;
	std::string gammaStr = gammaRate.to_string();
	int finalIndex = -1;

	for (int index = 0; index < nbrOfColumns; index++)
	{
		for (auto str : current)
		{
			if (str[index] == gammaStr[index])
				filtered.emplace_back(str);
		}

		if (filtered.size() <= 1)
		{
			finalIndex = index;
			break;
		}

		current.clear();
		current.swap(filtered);
		filtered.clear();
	}

	std::string oxygenRating = filtered[0].substr(0, finalIndex);
	std::bitset<nbrOfColumns> oxygenBitset(oxygenRating);

	std::cout << std::format("Oxygen Rating: {}", oxygenBitset.to_ulong());

	// THIS IS CORRECT SO FAR 


#pragma region copy_if attempt
	//auto binPointers = std::vector<std::bitset<nbrOfColumns>*>();

	//for (auto& input : binInput)
	//	binPointers.emplace_back(&input);

	//int finalIndex;

	//for (int index = nbrOfColumns - 1; index >= 0; index--)
	//{
	//	auto filteredPointers = std::vector<std::bitset<nbrOfColumns>*>();

	//	std::copy_if(binPointers.begin(), binPointers.end(), std::back_inserter(filteredPointers),
	//		[index, gammaRate](std::bitset<nbrOfColumns>* bit)
	//		{
	//			auto currentBit = (*bit)[index];
	//			auto comparedWith = gammaRate[index];

	//			if ((*bit)[index] == gammaRate[index])
	//				return true;

	//			return false;
	//		}
	//	);

	//	binPointers = filteredPointers;

	//	if (binPointers.size() <= 1)
	//	{
	//		finalIndex = index;
	//		break;
	//	}
	//}

	//std::cout << std::format("Found single bit: {}", binPointers[0]->to_string());
#pragma endregion copy_if attempt


#pragma region region attempt
	//auto gammaString = gammaRate.to_string(), epsilonString = epsilonRate.to_string();
	//auto filteredBinStr = binStrInput | std::views::filter([](std::string) { return true; });

	//for (int index = 0; index < nbrOfColumns; index++)
	//{
	//	auto temp = filteredBinStr | std::views::filter([index, gammaString](std::string input)
	//		{
	//			if (input[index] == gammaString[index])
	//				return true;
	//		});

	//	
	//}


	//auto filteredBinary = binaryInput | std::views::filter([](std::string binStr) { return binStr[0] == '1'; });

	//std::cout << firstPass;
#pragma endregion region attempt

}
