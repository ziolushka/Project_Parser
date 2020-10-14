#pragma once
#include <filesystem>
#include <map>
#include <regex>

namespace fs = std::filesystem;

class FileFinder
{
	public:
		FileFinder() : m_directory_path("") {};
		FileFinder(std::string &dir_path) : m_directory_path(dir_path) {};
		void FindFiles();
		std::string get_directory_files_pathes_at(size_t) const;
		int get_file_count() const;

	private:
		std::string m_directory_path;
		std::vector<std::string> m_directory_files_pathes;
};

