/**
 * @file nwAlgorithm.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief File and text management
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fileManagement.h"

void readGenBankFile (string& inputfile, string& outputstring)
{
    ifstream inputFile(inputfile);

    string line;

    while(getline(inputFile, line))
    {
        if(line.find("ORIGIN")!= string::npos)
            break;
    }

    while(getline(inputFile, line)) 
    {
        for(int i = 0; i < line.length(); i++)
        {
            switch(line[i]) 
            {
                case 'a':   /* Fallstrough */
                case 'c':
                case 'g':
                case 't':
                    outputstring += line[i];
                    break;
                default:
                    break;
            }
        }

        if(line.find("ORIGIN")!= string::npos)
            break;    
    }

    inputFile.close(); 
}