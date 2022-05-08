/**
 * @file main.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief Align coronavirus genetic sequences
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * UTIL:
 * http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Needleman-Wunsch
 * https://www.ncbi.nlm.nih.gov/nuccore/?term=sars-cov-2+complete
 * 
 */

//diagonal: coincidencia-sustitucion
//izquierda: insercion
//arriba: delecion

#include "fileManagement.h"
#include "nwAlgorithm.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>     

using namespace std;

int main ( int argc, char **argv )
{
    string file1 = argv[1];
    string file2 = argv[2];

    string cleanFirstFile; 
    string cleanSecondFile;

    //readGenBankFile(file1, cleanFirstFile);
    //readGenBankFile(file2, cleanSecondFile);
    
    cleanFirstFile = "taaaggtttataccttcccaggtaacaaaccaaccaactttcgatctcttgtagatctgttctctaaacgaactttaaaatctgtgtggctgtcactcgg";
    cleanSecondFile = "aaggtttataccttcccaggtaacaaaccaaccaactttcgatctcttgtagatctgttctctaaacgaactttaaaatctgt";
    
    int nwScore = 0;
    int maxlength = max(cleanFirstFile.length(), cleanSecondFile.length());

    //create substrings for more efficient memory usage
    string genseq1;
    string genseq2;

    int diference = cleanFirstFile.length() - cleanSecondFile.length();

    if(diference > 0)
    {
        string saveExtra = cleanFirstFile.substr(cleanSecondFile.length(),cleanFirstFile.length());
        cleanFirstFile.erase(cleanSecondFile.length(),cleanFirstFile.length());
    }
    else if(diference < 0)
    {
        string saveExtra= cleanSecondFile.substr(cleanFirstFile.length(),cleanSecondFile.length());
        cleanSecondFile.erase(cleanFirstFile.length(),cleanSecondFile.length());
    }

    //call the algorithm
    vector<T_Allignment> allignment;

    for(int i = 0; i < maxlength/MAXCHARS + 1; i++)
    {
        if( ((i + 1) * MAXCHARS) < maxlength)
        {
            genseq1 = cleanFirstFile.substr(i * MAXCHARS, (i + 1) * MAXCHARS);
            genseq2 = cleanSecondFile.substr(i * MAXCHARS, (i + 1) * MAXCHARS);
        }
        else
        {
            genseq1 = cleanFirstFile.substr(i * MAXCHARS, cleanFirstFile.length());
            genseq2 = cleanSecondFile.substr(i * MAXCHARS, cleanSecondFile.length());
        }
        nwAlgorithm(genseq1, genseq2, allignment);
        nwScore += printBestAllignment(allignment, genseq1, genseq2);
    }

    

    nwScore += abs(diference) * INDELSCORE;

    cout << nwScore << endl;

    return 0;
}

adjkakdkkja
|||||||||||
ajsdfjkajdh

asdj______ (al string mas corto se le hace un += '-' * diferencia)
||||      
ahsdhfjahd (imprimo lo que habia sobrado concetenado)