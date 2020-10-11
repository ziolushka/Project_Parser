#include "File_finder.h"
#include <iostream>

void File_finder::findFiles() {

	if (!fs::is_directory(directory_path))
		throw exception("Invalid directory path");

	const regex cpp_extentions("\\.(?:h|hpp|c|cpp)");

	for (auto& entry : fs::recursive_directory_iterator(directory_path))
		if (fs::is_regular_file(entry) && regex_match(entry.path().extension().string(), cpp_extentions)) 
			directory_files_path.push_back(entry.path().string());
			
}
int File_finder::getFileCount()
{
	return directory_files_path.size();
}
string File_finder::getFilePath(size_t file_index)
{
	if (file_index > (directory_files_path.size() - 1))
		throw exception("Out of range file number");

	return directory_files_path[file_index];
}