#pragma once

namespace Utils
{
bool ReadFromFile(const std::string& fileName, std::string& readString);
bool ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings);
} // !namespace Utils