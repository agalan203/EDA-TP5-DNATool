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

#define INDELSCORE -1
#define SUBSTSCORE -1
#define MATCHSCORE +1

/**
 * @brief Makes the matrix to find the best alignment
 * 
 * @param genseq1 the first genetic sequence (columnas)
 * @param genseq2 the second genetic sequence (filas)
 * @return int the best score
 */
int nwAlgorithm(string& genseq1, string& genseq2);