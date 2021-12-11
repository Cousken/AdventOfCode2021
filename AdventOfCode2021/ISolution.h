#pragma once

#include <fstream>
#include <string>

class ISolution
{
public:
	virtual void Run() = 0;
	std::fstream GetFile(const std::string& filePath);
};

