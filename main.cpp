/**
 * @file main.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief Align coronavirus genetic sequences
 * 
 * @copyright Copyright (c) 2022
 * 
 * Refer to "resultados" for diferent algorithm comparisons and reults
 * 
 */

#include "fileManagement.h"
#include "nwAlgorithm.h"

#include <iostream>

using namespace std;

int main ( int argc, char **argv )
{
    //prepare the files
    string file1 = argv[1];
    string file2 = argv[2];

    string cleanFirstFile; 
    string cleanSecondFile;

    readGenBankFile(file1, cleanFirstFile);
    readGenBankFile(file2, cleanSecondFile);

    //call the algorithm
    vector<T_Allignment> allignment;
    cout << nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) << endl;
	printBestAllignment(allignment, cleanFirstFile, cleanSecondFile);

    return 0;
}