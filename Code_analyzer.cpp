#include "Code_analyzer.h"

void Code_analyzer::saveResult(string directory_path) const{

    string result_info;

    result_info.append("File: " + directory_path + '\n'
        + "Physical lines count " + to_string(total_lines) + '\n'
        + "Code lines count " + to_string(total_code_lines) + '\n'
        + "Comment lines count " + to_string(total_blank_lines) + '\n'
        + "Blank lines count " + to_string(total_comment_lines) + '\n');

    ofstream output(directory_path + "Result.txt");
    if (!output.is_open())
        throw exception("can't open/create file");
    output << result_info;

    output.close();
}
void Code_analyzer::doAnalyze(string current_file) {

    Code_parser cp;
    cp.doParse(current_file);

    total_lines += cp.getPhysicalLinesCount();
    total_code_lines += cp.getCodeLinesCount();
    total_blank_lines += cp.getBlankLinesCount();
    total_comment_lines += cp.getCommentLinesCount();

    cp.resetLinesCount();
 }