// Code_analyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include <iostream>
#include "Code_analyzer.h"


int main()
{
    string directory_path = "C:/Users/Ziolushka/Documents/";
    auto start_timer = chrono::high_resolution_clock::now();
    vector<thread> vector_threads;

    File_finder ff(directory_path);
    ff.findFiles();

    Code_analyzer ca;

    for (int i = 0; i < ff.getFileCount(); ++i) {
        string current_file = ff.getFilePath(i);
        vector_threads.emplace_back(thread(&Code_analyzer::doAnalyze, ref(ca), current_file)); //paralel
        //ca.doAnalyze(current_file); 
    }

    for (auto& th : vector_threads)
        if (th.joinable())
            th.join();

    auto stop_timer = chrono::high_resolution_clock::now();
    auto time_of_execution = chrono::duration_cast<chrono::microseconds>(stop_timer - start_timer); //milliseconds

    cout << "Time of execution " << to_string(time_of_execution.count()) << endl
        << "Number of processed files "<< ff.getFileCount() << endl;
    
    ca.saveResult(directory_path);
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
