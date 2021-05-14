#pragma once

#include <string>

#ifdef WIN32
#define NOMINMAX
#include <windows.h>
#endif

class FileMemMap
{
public:

	FileMemMap() {}

	// map file to memory
	char* mapfile(const std::string& filename);

	// release file and mapped resource
	void release();

private:
	// file path
	std::string filename;

#ifdef WIN32
	// file handle
	HANDLE hFile;

	// mapped file handle
	HANDLE hFileMap;

	// file view address
	LPVOID lpMapAddress;
#else
	// file handle linux
	int fd;
#endif

};