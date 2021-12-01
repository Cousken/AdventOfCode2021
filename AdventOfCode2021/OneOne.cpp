#include "OneOne.h"
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <fstream>
#include <format>

void OneOne::Run()
{
    std::fstream infile("Inputs/One.txt");

    int previous, next, count = 0;

    infile >> previous;
    while (infile >> next)
    {
        if (previous < next)
            count++;

        previous = next;
    }

    std::cout << std::format("The solution is: {}.", count) << std::endl << "Press enter to exit application.";
}
