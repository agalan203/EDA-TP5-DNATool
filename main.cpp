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

/*
Deberás escribir un programa que recibe por línea de comando los nombres de dos 
archivos GenBank a ser alineados. El programa deberá imprimir en consola el puntaje
óptimo y un alineamiento óptimo para ambas secuencias, tal como te mostramos en
la sección Alineamiento de secuencias.
*/

/*
coincidencias = '|'
indel = ' '
sustituciones = '*'
SI TE MOVES DENTRO DE LA MISMA FILA O DE LA MISMA COLUMNA VA UN _ en ese string
verticalmente -> string2
*/
#include "fileManagement.h"
#include "nwAlgorithm.h"

#include <fstream>
#include <iostream>

using namespace std;

int main ( int argc, char **argv )
{
    string file1 = argv[1];
    string file2 = argv[2];

    string cleanFirstFile; 
    string cleanSecondFile;

    readGenBankFile(file1, cleanFirstFile);
    readGenBankFile(file2, cleanSecondFile);

    //TODO: just for debug
    //string genseq1 = "taaaggtttataccttcccaggtaacaaaccaaccaactttcgatctcttgtagatctgttctctaaacgaactttaaaatctgtgtggctgtcactcgg";
    //string genseq2 = "aaggtttataccttcccaggtaacaaaccaaccaactttcgatctcttgtagatctgttctctaaacgaactttaaaatctgt";
    
    string genseq1 = "CGATACG";
    string genseq2 = "GATTACAGTAC";

    //call the algorithm
    vector<T_Allignment> allignment;
    nwAlgorithm(genseq1, genseq2, allignment);
	printBestAllignment(allignment, genseq1, genseq2);

    return 0;
}