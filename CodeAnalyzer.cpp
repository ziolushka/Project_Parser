#include "CodeAnalyzer.h"

void CodeAnalyzer::SaveResult() const
{
    std::string result_info;

    result_info.append("Directory " + m_directory_path + '\n'
        + "Physical lines count " + std::to_string(m_total_lines) + '\n'
        + "Code lines count " + std::to_string(m_total_code_lines) + '\n'
        + "Comment lines count " + std::to_string(m_total_blank_lines) + '\n'
        + "Blank lines count " + std::to_string(m_total_comment_lines) + '\n' + '\n');

    std::ofstream result;
    result.open(m_directory_path + "Result.txt", std::fstream::app);
    if (!result.is_open())
        throw std::exception("Ñan't open/create file");
    result << result_info;

    result.close();
}
void CodeAnalyzer::SaveCurrentResult(const CodeParser &cp) const
{
    std::string result_info;

    result_info.append("File: " + cp.get_cpp_file_path() + '\n'
        + "Physical lines count " + std::to_string(cp.get_physical_lines_count()) + '\n'
        + "Code lines count " + std::to_string(cp.get_code_lines_count()) + '\n'
        + "Comment lines count " + std::to_string(cp.get_comment_lines_count()) + '\n'
        + "Blank lines count " + std::to_string(cp.get_blank_lines_count()) + '\n' + '\n');

    std::ofstream result;

    result.open(m_directory_path + "Result.txt", std::fstream::app);
    if (!result.is_open())
        throw std::exception("Ñan't open/create file");
    result << result_info;

    result.close();
}

void CodeAnalyzer::DoAnalyze(const std::string &current_file) 
{
    CodeParser cp;
    cp.DoParse(current_file);

    std::lock_guard<std::mutex> lock(m_data_mutex);

    m_total_lines += cp.get_physical_lines_count();
    m_total_code_lines += cp.get_code_lines_count();
    m_total_blank_lines += cp.get_blank_lines_count();
    m_total_comment_lines += cp.get_comment_lines_count();

    SaveCurrentResult(cp);
    cp.ResetLinesCount();
 }