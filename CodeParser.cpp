#include "CodeParser.h"
#include <iostream>

void CodeParser::DoParse(const std::string &file_path) 
{
	m_cpp_file_path = file_path;

	std::ifstream read_file(file_path);
	if (!read_file.is_open())
		throw std::exception((std::string("Can not open file ").append(file_path)).c_str());

	std::stack<int> s; // to count block comment lines
	std::string text;
	std::regex expresion("");
	int comment_block_lenght = 0;

	while (getline(read_file,text)) 
	{
		
		if (text.empty())
			m_blank_lines_count++;
		
		if (regex_search(text, expresion = "\/\/")) //pure linnear comment
		{
			m_comment_lines_count++;
			if (regex_match(text, expresion = "(\\w|\\s|[(),;.])+\/\/(\\w|\\s|[(),;.])*")) //code + linear comment
				m_code_lines_count++;
		}
		
		else if (regex_search(text, expresion = "(\\/\\*)")) //block comment starts
		{
			if ((regex_match(text, expresion = "((\\w|\\s|[;,.=()])+\\/\\*(\\w|\\s|[;,.=()])+)")))//if there is  a code before comment block starts
				m_code_lines_count++;
			s.push(m_physical_lines_count);
		}
		
		if (regex_search(text, expresion = "(\\*\\/)")) //block comment ends
		{
			if (!s.empty())
			{
				comment_block_lenght = m_physical_lines_count + 1 - s.top();
				s.pop();
			}
			if (regex_match(text, expresion = "((\\w|\\s|[;,.=()])+(\\*\\/)(\\w|\\s|[;,.=()])+)")) //if there is a code after comment block ends
				m_code_lines_count++;
			m_comment_lines_count += comment_block_lenght;
			comment_block_lenght = 0;
		}

		m_physical_lines_count++;
	}
	m_code_lines_count += m_physical_lines_count - m_blank_lines_count - m_comment_lines_count;

	read_file.close();
}

void CodeParser::ResetLinesCount()
{
	m_blank_lines_count = 0;
	m_comment_lines_count = 0;
	m_code_lines_count = 0;
	m_physical_lines_count = 0;
}

void  CodeParser::PrintResult() const 
{
	std::cout << "File:" << m_cpp_file_path << std::endl;
	std::cout << "Blank " << m_blank_lines_count << std::endl;
	std::cout << "Comment " << m_comment_lines_count << std::endl;
	std::cout << "Code " << m_code_lines_count << std::endl;
	std::cout << "Total " << m_physical_lines_count << std::endl;
}