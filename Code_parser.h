#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <stack>

namespace fs = std::filesystem;
using namespace std;

class Code_parser
{
	private:
		int blank_lines_count
			, comment_lines_count
			, code_lines_count
			, physical_lines_count;

	public:
		Code_parser() :blank_lines_count(0), comment_lines_count(0), code_lines_count(0), physical_lines_count(0){};
		void doParse(const string);
		int getBlankLinesCount() const { return blank_lines_count; };
		int getCommentLinesCount() const { return comment_lines_count; };
		int getCodeLinesCount() const { return code_lines_count; };
		int getPhysicalLinesCount() const { return physical_lines_count; };
		void resetLinesCount();


};

