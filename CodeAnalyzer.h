#pragma once
#include <mutex>
#include <string>

#include "CodeParser.h"
#include "FileFinder.h"

class CodeAnalyzer
{
	public:
		CodeAnalyzer(const std::string &directory_path) : m_directory_path (directory_path) {};
		void DoAnalyze(const std::string &);
		void SaveResult() const;
		void SaveCurrentResult(const CodeParser& cp) const;

	private:
		int m_total_lines = 0;
		int m_total_code_lines = 0;
		int m_total_blank_lines = 0;
		int m_total_comment_lines = 0;
		std::string m_directory_path;
		std::mutex m_data_mutex;	
};

