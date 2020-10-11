#pragma once
#include <filesystem>
#include <map>
#include <regex>

namespace fs = std::filesystem;
using namespace std;

class File_finder
{
	private:
		string directory_path;
		vector<string> directory_files_path;
	public:
		File_finder() : directory_path("") {};
		File_finder(string dir_path) : directory_path(dir_path) {};
		int getFileCount();
		string getFilePath(size_t);
		void findFiles();



};

