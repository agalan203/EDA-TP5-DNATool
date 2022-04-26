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

/* 
TODO n1: leer e interpretar archivos: 
- abrir 
- find "ORIGIN" 
- remove all not acgt characters 
- write to new file
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
TIPS DE MARTIN:
- 
*/
#include "fileManagement.h"
#include "nwAlgorithm.h"

#include <iostream>

using namespace std;

int main ( int argc, char **argv )
{

    return 0;
}