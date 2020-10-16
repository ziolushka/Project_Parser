# Project_Parser

**Task:** As a developer I want to have an application that counts blank lines, comment lines, and physical lines of source code written in C/C++. so that I can have some internal statistic of the project.

**Requirements:**
1.	There are should be a way to specify project root folder 
2.	Only files with *.h, *.hpp, *.c, *.cpp extensions are processed from all subfolders 
3.	The output should contain the total number of processed files, count of blank lines, count of comment lines, count of lines with code and time of execution 
4.	The results should also be saved in file. 

**Implementation:** I came up with the solution to decompose the program for three classes: CodeAnalyzer CodeParser and FileFinder. 
As expected FileFinder is responsible for extracting all of the needed files from the given directory and nested subdirectories. All the file checks are here: check for existence, is_directory check, check for files extensions, etc. It is also available to get the number of accepted files and a particular file path.
CodeParser is responsible for counting all of the types of lines: comment, code, blank, and total amount. All of those are parsed in one function, counted values are stored as class members, which can be accessed through getters. This way of parsing the file in the one function allows me to go through the file only once, rather than a couple of if I were writing separate methods.
And final and the most valuable class which puts is everything together is CodeAnalyzer which creates an instance of CodeParser class and saves results for every file given by FileFinder.
