#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <stack>

namespace fs = std::filesystem;

class CodeParser
{
	public:
		void DoParse(const std::string &);
		int get_blank_lines_count() const { return m_blank_lines_count; };
		int get_comment_lines_count() const { return m_comment_lines_count; };
		int get_code_lines_count() const { return m_code_lines_count; };
		int get_physical_lines_count() const { return m_physical_lines_count; };
		std::string get_cpp_file_path() const { return m_cpp_file_path;};
		void ResetLinesCount();
		void PrintResult() const;

	private:
		int m_blank_lines_count = 0;
		int m_comment_lines_count = 0;
		int m_code_lines_count = 0;
		int m_physical_lines_count = 0;
		std::string m_cpp_file_path = "";
};

