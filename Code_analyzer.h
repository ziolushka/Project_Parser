#pragma once
#include "Code_parser.h"
#include "File_finder.h"

class Code_analyzer
{
	private:
		int total_lines
			, total_code_lines
			, total_blank_lines
			, total_comment_lines;
		

	public:
		Code_analyzer() : total_lines(0), total_code_lines(0), total_blank_lines(0), total_comment_lines(0){};
		void doAnalyze(const string);
		void saveResult(string) const;
};

