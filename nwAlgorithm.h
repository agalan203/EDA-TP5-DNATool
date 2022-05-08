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

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INDELSCORE -1
#define SUBSTSCORE -1
#define MATCHSCORE +1

/**
 * @brief Defines all parameters of the allignment:
 * 
 * The row and column of the chars involved and its given score
 */
typedef struct Allignment
{
    int row;
    int column;
    int score;

}T_Allignment;

/**
 * @brief Makes the matrix to find the best allignment
 * 
 * @param genseq1 the first genetic sequence
 * @param genseq2 the second genetic sequence
 * @param vector<T_Allignment>& to place the best allignment
 */
void nwAlgorithm(string& genseq1, string& genseq2, vector<T_Allignment>& allignment);

/**
 * @brief Prints the two sequences alligned and the operations involved
 * 
 * @param allignment the parameters of allignment
 * @param genseq1 
 * @param genseq2 
 */
void printBestAllignment(vector<T_Allignment>& allignment, string& genseq1, string& genseq2);

