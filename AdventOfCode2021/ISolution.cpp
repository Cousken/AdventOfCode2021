#include "ISolution.h"

#include <fstream>
#include <string>


std::fstream ISolution::GetFile(const std::string& filePath)
{
	return std::fstream(filePath);
}
