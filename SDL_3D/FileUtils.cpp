#include "FileUtils.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

GLchar* FileUtils::ReadFileIntoString(const char* const file) {
	printf("Reading: %s\n", file);
	ifstream inputStream{ file };
	if (!inputStream.good()) {
		cout << "bad input stream";
		return nullptr;
	}
	auto readBuffer = inputStream.rdbuf();
	// Each space counts as two when counting size, but only stored as one (10) in sgetn()
	auto size = readBuffer->pubseekoff(0, inputStream.end);
	long bufferLen = (long)size;
	printf("File Len: %d\n", bufferLen);
	if (bufferLen <= 0) {
		cout << "unable to seek end";
		return nullptr;
	}
	readBuffer->pubseekpos(0, inputStream.beg);
	char* const buffer = new char[bufferLen] { 0 };
	readBuffer->sgetn(&buffer[0], bufferLen);
	printf("File:\n");
	for (int i = 0; i < bufferLen; i++) {
		cout << buffer[i];
	}
	cout << endl;
	inputStream.close();
	return buffer;
}