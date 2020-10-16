#include "FileFinder.h"
#include <iostream>

void FileFinder::FindFiles() 
{
	if (!fs::exists(m_directory_path))
		throw std::exception("Invalid path");

	if (!fs::is_directory(m_directory_path))
		throw std::exception("Invalid directory path");

	const std::regex cpp_extentions("\\.(?:h|hpp|c|cpp)");

	for (auto& entry : fs::recursive_directory_iterator(m_directory_path))
		if (fs::is_regular_file(entry) && regex_match(entry.path().extension().string(), cpp_extentions))
			m_directory_files_pathes.push_back(entry.path().string());
}

int FileFinder::get_file_count() const
{
	return m_directory_files_pathes.size();
}

std::string FileFinder::get_directory_files_pathes_at(size_t file_index) const
{
	if (file_index > (m_directory_files_pathes.size() - 1))
		throw std::exception("Out of range file number");

	return m_directory_files_pathes[file_index];
}