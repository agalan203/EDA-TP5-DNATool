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

int nwAlgorithm(string& genseq1, string& genseq2)
{
	int n = genseq1.size();
	int m = genseq2.size();
	int allignMtrx[n][m];
	for (int i=0; i < n; i++) //columnas
	{
		allignMtrx[0][i] = i * SUBSTSCORE;
	}
	for (int i = 0; i < m; i++) //filas
	{
		allignMtrx[i][0] = i * SUBSTSCORE;
	}
	for (int i=1; i < n; i++) //todas col
	{
		for(int j=1; j < m;j++) //todas fil
		{
			int thisScore = genseq1[j] == genseq2[i] ? MATCHSCORE : SUBSTSCORE; 
            allignMtrx[i][j] = max(allignMtrx[i-1][j-1] + thisScore, 
							   max(allignMtrx[i-1][j] + INDELSCORE, allignMtrx[i][j-1] + INDELSCORE));
		}
	}


	//pseudo funcion de alineamiento

	int i = n, j = m;
	std::vector<char> seq1, seq2;

	while (i != 0 && j != 0)
	{
		if (i == 0)
		{
			j--;
			seq1.push_back('_');
			seq2.push_back(genseq2[j]);
		}
		else if (j == 0)
		{
			i--;
			seq2.push_back('_');
			seq1.push_back(genseq2[i]);
		}
		else 
		{
			//necesito tres casos, si viene en diagonal si viene arriba o abajo
			int tryScore = genseq1[i-1] == genseq2[j-1] ? MATCHSCORE : SUBSTSCORE;
			switch(allignMtrx[i][j])
			{
			case allignMtrx[i-1][j-1]+tryScore:
				seq1.push_back(genseq1[i - 1]);
				seq2.push_back(genseq2[j - 1]);
				i--;	//si me muevo en los dos altero los dos "iteradores"
				j--;
				break;
			case allignMtrx[i][j-1]+INDELSCORE:
				i--; //me estoy moviendo en la misma columna
				seq1.push_back(genseq1[i]);
				seq2.push_back('_');
			default:
				j--; //me estoy moviendo en la misma fila
				seq2.push_back(genseq1[j]);
				seq1.push_back('_');
			}

		}

	}

	reverse(seq1.begin(), seq1.end());
	reverse(seq2.begin(), seq2.end());


	return 0; //no clue what to do here
	
}

