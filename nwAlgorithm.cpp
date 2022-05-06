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
    int size = min(genseq1.size(),genseq2.size())
	int allignMtrx [size][size];
	for (int i=0, i < size, i++)
	{
		allignMtrx[i][0] = allignMtrx[0][i] = i * SUBSTSCORE;
	}
	for (int i=1; i < size; i++)
	{
		for(int j=1; j < size;j++)
		{
			int thisScore = genseq1[j] == genseq2[i] ? MATCHSCORE : SUBSTSCORE;
            allignMtrx[i][j] = max(allignMtrx[i-1][j-1] + thisScore, 
							   max(allignMtrx[i-1][j]]+ INDELSCORE, allignMtrx[i][j-1] + INDELSCORE));

		}
	}

    //llamar funcion de alineamiento y devolver eso :)
	
}

/*
[2,3]= 1
[3,3] = 0
.
[5,5]= 3
[6,6] = 2
*/