#include "Code_parser.h"

void Code_parser::doParse(const string file_path) {

	ifstream read_file(file_path);
	if (!read_file.is_open())
		throw exception((string("Can not open file ").append(file_path)).c_str());

	string text;
	regex expresion("");

	std::stack<int> s;
	int comment_block_lenght = 0;

	while (getline(read_file,text)) {
		
		if (text.empty())
			blank_lines_count++;
		//pure linnear comment
		if (regex_search(text, expresion = "//")) {
			comment_lines_count++;
			if (regex_match(text, expresion = "(\\w|\\s|[(),;.])+\/\/(\\w|\\s|[(),;.])*")) //code + linear comment
				code_lines_count++;
		}
		//block comment opening
		else if (regex_search(text, expresion = "(\\/\\*)")) {
			if ((regex_match(text, expresion = "((\\w|\\s|[;,.=()])+\\/\\*(\\w|\\s|[;,.=()])+)")))//if there is  a code before comment block opening
					code_lines_count++;
			s.push(physical_lines_count);
		}
		//block comment ending
		if (regex_search(text, expresion = "(\\*\\/)")) {
			if (!s.empty()) {
				comment_block_lenght = physical_lines_count + 1 - s.top();
				s.pop();
			}
			if (regex_match(text, expresion = "((\\w|\\s|[;,.=()])+(\\*\\/)(\\w|\\s|[;,.=()])+)")) //if there is a code after comment block ending
				code_lines_count++;
			comment_lines_count += comment_block_lenght;
			comment_block_lenght = 0;
		}

		physical_lines_count++;
	}
	code_lines_count = code_lines_count + physical_lines_count - blank_lines_count - comment_lines_count;

	read_file.close();
}
void Code_parser::resetLinesCount(){
	blank_lines_count = 0;
	comment_lines_count = 0; 
	code_lines_count = 0; 
	physical_lines_count = 0;
}