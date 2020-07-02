#include <string>
#include <map>
#include <fstream>

#include "MyUtils.hpp"


// ------------------------------ Read from txt ----------------------------- //

std::map<std::string, std::string> readVairValues(const std::string& relativeFilePath, char separator) {
	std::map<std::string, std::string> res;

	std::ifstream file(relativeFilePath);

	std::string line;

	while (std::getline(file, line))
	{
		int separatorIndex = line.find_first_of(separator);
		std::string key = line.substr(0, separatorIndex);
		std::string value = line.substr(separatorIndex + 1);

		res[trim(key)] = trim(value);
	}

	return res;
}




// --------------------------------- Utils -------------------------------- //
std::string& ltrim(std::string& str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str, const std::string& chars)
{
	return ltrim(rtrim(str, chars), chars);
}

