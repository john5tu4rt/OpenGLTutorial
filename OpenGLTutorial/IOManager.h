#pragma once

#include <vector>


class IOManager {
public:
	static bool readFileToBuffer(const std::string& filePath, std::vector<char>& buffer);
};

