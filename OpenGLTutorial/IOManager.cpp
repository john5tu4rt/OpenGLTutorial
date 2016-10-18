#include "IOManager.h"

#include <fstream>

bool IOManager::readFileToBuffer(const std::string & filePath, std::vector<unsigned char>& buffer) {

	// file path and type to load
	std::ifstream file(filePath, std::ios::binary);
	if (file.fail()) {
		perror(filePath.c_str());
	}

	//Determine filesize
	//Seek to end
	file.seekg(0, std::ios::end);

	auto fileSize = file.tellg(); //returns bytes before location

	//seek to beginning (reset)
	file.seekg(0, std::ios::beg);

	//Ignore header data - maybe not necessary
	fileSize -= file.tellg();

	//Resize the buffer to correct size
	buffer.resize(fileSize);
	
	//read data into buffer
	file.read((char *)&(buffer[0]), fileSize);

	file.close();
	return true;
}
