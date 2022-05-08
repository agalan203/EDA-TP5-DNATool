/**
 * @file nwAlgorithm.cpp
 * @author Albertina Galan & Sebastian Nahuel Herrera
 * @brief Needleman Wunsch algorithm
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "nwAlgorithm.h"

using namespace std;

void nwAlgorithm(string& genseq1, string& genseq2, vector<T_Allignment>& allignment)
{
	int n = genseq1.size() + 1;
	int m = genseq2.size() + 1;

	int allignMtrx[n][m];

	for (int i = 0 ; i < n; i++) //columnas
	{
		allignMtrx[0][i] = i * SUBSTSCORE;
	}

	for (int i = 0; i < m; i++) //filas
	{
		allignMtrx[i][0] = i * SUBSTSCORE;
	}

	for (int i = 1; i < n; i++) //col
	{
		for(int j = 1; j < m; j++) //fil
		{
			int thisScore = genseq1[j-1] == genseq2[i-1] ? MATCHSCORE : SUBSTSCORE; 
            allignMtrx[i][j] = max(allignMtrx[i-1][j-1] + thisScore, 
							   max(allignMtrx[i-1][j] + INDELSCORE, allignMtrx[i][j-1] + INDELSCORE));
		}
	}

	T_Allignment allignValue;

	int i = n-1, j = m-1;
	
	allignValue.column = i;
	allignValue.row = j;
	allignValue.score = allignMtrx[i][j];

	allignment.push_back(allignValue);
	
	while ( i > 0 && j > 0)
	{
		int maxkey = max(allignMtrx[i-1][j-1], 
					 max(allignMtrx[i-1][j], allignMtrx[i][j-1]));

		if (maxkey == allignMtrx[i-1][j-1])
		{
			i = i-1;
			j = j-1;
		}
		else if (maxkey == allignMtrx[i-1][j])
		{
			i = i-1;
		}	
		else 
		{
			j = j-1;
		}

		allignValue.column = i;
		allignValue.row = j;
		allignValue.score = allignMtrx[i][j];
		
		allignment.push_back(allignValue);
	}
	
	allignValue.column = 0;
	allignValue.row = 0;
	allignValue.score = 0;
	
	allignment.push_back(allignValue);

	reverse(allignment.begin(), allignment.end());
}

void printBestAllignment(vector<T_Allignment>& allignment, string& genseq1, string& genseq2)
{
	string alSeq1;
	string alSeq2;
	string alChars;

	//make the strings
	for(int i = 0; i < allignment.size()-1 ; i++)
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
	int length = 0; 
	int counter = 0;
	int maxlength = max(alSeq1.length(), max(alChars.length(),alSeq2.length()));

	cout << endl;

	while (counter < (maxlength/60) + 1)
	{
		for(int i = counter * 60; i < alSeq2.length(); i++)
		{
			if(length >= 60)
			{
				cout << endl;
				length = 0;
				break;
			}
			cout << alSeq2[i];
			length++;
		}

		cout << endl;

		for(int j = counter * 60; j < alChars.length(); j++)
		{
			if(length >= 60)
			{
				cout << endl;
				length = 0;
				break;
			}
			cout << alChars[j];
			length++;
		}
		
		cout << endl;

		for(int z = counter * 60; z < alSeq1.length(); z++)
		{
			if(length >= 60)
			{
				cout << endl;
				length = 0;
				break;
			}
			cout << alSeq1[z];
			length++;
		}

		cout << endl;

		counter++;
	}
}