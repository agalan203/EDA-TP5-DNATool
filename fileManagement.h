/**
 * @file nwAlgorithm.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief File and text management
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Reads and cleans a copy of the GenBank file
 * 
 * @param inputfile the name of the file to analize
 * @param outputstring the clean genetic sequence
 */
void readGenBankFile (string& inputfile, string& outputstring);