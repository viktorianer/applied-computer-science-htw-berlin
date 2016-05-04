#ifndef ARRAYS_H
#define	ARRAYS_H

#include <iostream>
#include <iomanip>

using namespace std;

void schreibe_2dim_int_array(int *array, int zeilen, int spalten);

void schreibe_long_double_array(long double *array, int laenge, int spaltenbreite);
void schreibe_long_double_array(long double *array, int laenge);
void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten, int spaltenbreite);
void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten);

long double *liefere_max_long_double_array(long double array[], int laenge);
double *liefere_max_double_array(double array[], int laenge);

#endif	/* ARRAYS_H */

