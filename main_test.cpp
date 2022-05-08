/**
 * @file main_test.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief Test Module
 * 
 * @copyright Copyright (c) 2022
 * 
 * Scores for test comparison got from:
 * http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Needleman-Wunsch
 */

#include "fileManagement.h"
#include "nwAlgorithm.h"

#include <iostream>

using namespace std;

void print(string s)
{
    cout << s;
}

int fail()
{
    cout << "FAIL" << endl;
    return 1;
}

int pass()
{
    cout << "PASS" << endl;
    return 0;
}

int main ()
{
    print("readGenBankFile is able to open a file and extract a clean genetic sequence... ");
    string file = "../testfile.txt";
    string cleanFile;
    readGenBankFile(file, cleanFile);
    if (cleanFile != "acgactacgtacgtacccccacgtacgtaccccaaacgtacgtggggacg")
        return fail();
    pass();

    vector<T_Allignment> allignment;
    string cleanFirstFile = ""; 
    string cleanSecondFile = "";

    print("nwAlgorithm works with two null strings... ");
    if(nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) != 0)
        return fail();
    else pass();

    print("nwAlgorithm works with one null string... ");
    allignment.clear();
    cleanFirstFile = "acgt"; 
    if(nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) != -4)
        return fail();
    else pass();

    print("nwAlgorithm works with two same length strings... ");
    allignment.clear();
    cleanFirstFile = "acgt"; 
    cleanSecondFile = "gcta"; 
    if(nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) != -1)
        return fail();
    else pass();

    print("nwAlgorithm works with two diferent length strings... ");
    allignment.clear();
    cleanFirstFile = "acg"; 
    cleanSecondFile = "gcta"; 
    if(nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) != -2)
        return fail();
    else pass();

    print("nwAlgorithm works with two long strings... ");
    allignment.clear();
    cleanFirstFile = "acgcatagttacggcgccgatctaaagtcatttgacttagagattttcaagaaaactggaacactaaacatagca"; 
    cleanSecondFile = "gatggctaccctcttgagtgattaaagaccttctagcacgtgctggtaaagcttcatgcactttgtccga"; 
    if(nwAlgorithm(cleanFirstFile, cleanSecondFile, allignment) != 4)
        return fail();
    else pass();

    return 0;
}