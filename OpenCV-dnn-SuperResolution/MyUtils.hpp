#pragma once

#include <string>

// ------------------------------ Read from txt ----------------------------- //

std::map<std::string, std::string> readVairValues(const std::string& relativeFilePath, char separator);


// --------------------------------- String --------------------------------- //
std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
