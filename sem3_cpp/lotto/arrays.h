#ifndef ARRAYS_H
#define	ARRAYS_H

#include <iostream>
#include <iomanip>

#include "zufallsgenerator.h"

using namespace std;

class Arrays
{
  public:
    static void initialisiere_int_bereich(int *von, int *bis, int initialwert);
    static void initialisiere_int_array(int *array, int laenge, int initialwert);
    static void initialisiere_int_bereich_zufaellig(int *von, int *bis, int min,  int max);

    static void schreibe_2dim_int_array(int *array, int zeilen, int spalten);
    static void schreibe_long_double_array(long double *array, int laenge, int spaltenbreite);
    static void schreibe_long_double_array(long double *array, int laenge);
    static void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten, int spaltenbreite);
    static void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten);
};
#endif	/* ARRAYS_H */

