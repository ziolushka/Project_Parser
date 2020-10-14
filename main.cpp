// Code_analyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <thread>
#include <iostream>

#include "CodeAnalyzer.h"

int main()
{
    std::string directory_path = "C:/Users/Ziolushka/Documents/2048/";

    FileFinder ff(directory_path);
    ff.FindFiles();
    CodeAnalyzer ca(directory_path);

    std::vector<std::thread> vector_threads;
    auto start_timer = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < ff.get_file_count(); ++i) 
    {
        std::string current_file = ff.get_directory_files_pathes_at(i);
        vector_threads.emplace_back(std::thread(&CodeAnalyzer::DoAnalyze, std::ref(ca), current_file)); //paralel 
        //ca.DoAnalyze(current_file); //sequential
    }

    for (auto& th : vector_threads)
        if (th.joinable())
            th.join();

    auto stop_timer = std::chrono::high_resolution_clock::now();
    auto time_of_execution = std::chrono::duration_cast<std::chrono::microseconds>(stop_timer - start_timer);

    std::cout << "Time of execution " << std::to_string(time_of_execution.count()) << " microseconds." << std::endl
         << "Number of processed files " << std::to_string(ff.get_file_count()) << "." << std::endl
         << "Results are saved in the directory " << directory_path << ", file \"Result.txt\"." << std::endl;
    ca.SaveResult();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
