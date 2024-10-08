/**
 * @file nwAlgorithm.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief Needleman Wunsch algorithm
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "nwAlgorithm.h"

using namespace std;

int nwAlgorithm(string& genseq1, string& genseq2, vector<T_Allignment>& allignment)
{
	//make the matrix
	int n = genseq1.size() + 1;
    int m = genseq2.size() + 1;
    
    vector<int> allignMtrx;
    allignMtrx.resize(m*n);
    const int newRow = m;
    
    for (int i = 0 ; i < n; i++)
    {
    	allignMtrx[i * newRow] = i * SUBSTSCORE;
    }
    
    for (int j = 0; j < m; j++)
    {
    	allignMtrx[j] = j * SUBSTSCORE;
    }
    
    for (int i = 1; i < n; i++)
    {
    	for(int j = 1; j < m; j++)
    	{
    		int thisScore = genseq1[i-1] == genseq2[j-1] ? MATCHSCORE : SUBSTSCORE; 
            allignMtrx[i * newRow + j] = maxValue(allignMtrx[(i-1) * newRow + (j-1)] + thisScore, 
    											  allignMtrx[(i-1) * newRow + j] + INDELSCORE, 
    											  allignMtrx[i * newRow + (j-1)] + INDELSCORE);
    	}
    }

	//find the best allignment
	T_Allignment allignValue;

	int i = n-1, j = m-1;
	
	allignValue.row = i;
	allignValue.column = j;
	allignValue.score = allignMtrx[i * newRow + j];
	allignment.push_back(allignValue);
	
	while ( i > 0 && j > 0)
	{
		int maxkey = maxValue(allignMtrx[(i-1) * newRow + (j-1)], 
							  allignMtrx[(i-1) * newRow + j], 
							  allignMtrx[i * newRow + (j-1)]);

		if (maxkey == allignMtrx[(i-1) * newRow + (j-1)])
		{
			i = i-1;
			j = j-1;
		}
		else if (maxkey == allignMtrx[(i-1) * newRow + j])
		{
			i = i-1;
		}	
		else 
		{
			j = j-1;
		}

		allignValue.row = i;
		allignValue.column = j;
		allignValue.score = allignMtrx[i * newRow + j];
		allignment.push_back(allignValue);
	}
	
	if(genseq1[0] != genseq2[0])
	{
		allignValue.row = 0;
		allignValue.column = 0;
		allignValue.score = 0;
		allignment.push_back(allignValue);
	}

	reverse(allignment.begin(), allignment.end());

	return allignMtrx[(n-1) * newRow + (m-1)];
}

void printBestAllignment(vector<T_Allignment>& allignment, string& genseq1, string& genseq2)
{
	string alSeq1;
	string alSeq2;
	string alChars;

	//make the strings
	for(long int i = 0; i < allignment.size()-1 ; i++)
	{
		int diference =  allignment.at(i).score - allignment.at(i+1).score;

		if(allignment.at(i).column == allignment.at(i+1).column)
		{
			alSeq1 += genseq1[allignment.at(i).row];
			alSeq2 += '-';
			alChars += ' ';
		}
		else if(allignment.at(i).row == allignment.at(i+1).row)
		{
			alSeq1 += '-';
			alSeq2 += genseq2[allignment.at(i).column];
			alChars += ' ';
		}
		else
		{
			alSeq1 += genseq1[allignment.at(i).row];
			alSeq2 += genseq2[allignment.at(i).column];
			
			if(diference < 0)
				alChars += '|';
			else
				alChars += '*';
		}	
	}

	//print the strings
	long int length = 0; 
	long int counter = 0;
	long int maxlength = alChars.length();

	cout << endl;

	while (counter < (maxlength/60) + 1)
	{
		printString(alSeq1,counter);
		printString(alChars,counter);
		printString(alSeq2,counter);

		counter++;
	}
}

int maxValue(int a, int b, int c)
{
    return max(a, max(b,c));
}

void printString(string& line, long int counter)
{
	int length = 0;

	for(long int i = counter * 60; i < line.length(); i++)
		{
			if(length >= 60)
			{
				cout << endl;
				length = 0;
				break;
			}
			cout << line[i];
			length++;
		}

	if(length != 0)
		cout << endl;
}