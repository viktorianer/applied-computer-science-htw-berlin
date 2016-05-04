#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "statistik.h"
#include "arrays.h"

/**Liefert die kleinste, ganze Zahl in einem char-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die kleinste, ganze Zahl in einem char-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char *liefere_min_char_array(char array[], int laenge)
{
  char *min = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] < *min)
      min = &array[i];
  return min;
}

/**Liefert die kleinste, ganze Zahl in einem int-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die kleinste, ganze Zahl in einem int-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int *liefere_min_int_array(int array[], int laenge)
{
  int *min = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] < *min)
      min = &array[i];
  return min;
}

/**Liefert die kleinste Gleitkommazahl in einem double-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die kleinste Gleitkommazahl in einem double-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double *liefere_min_double_array(double array[], int laenge)
{
	double *min = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] < *min)
      min = &array[i];
  return min;
}

/**Liefert die groesste, ganze Zahl in einem char-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die groesste, ganze Zahl in einem char-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char *liefere_max_char_array(char array[], int laenge)
{
  char *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}

/**Liefert die groesste, ganze Zahl in einem int-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die groesste, ganze Zahl in einem int-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int *liefere_max_int_array(int array[], int laenge)
{
  int *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}

/**Liefert die groesste Gleitkommazahl in einem double-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die groesste Gleitkommazahl in einem double-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double *liefere_max_double_array(double array[], int laenge)
{
	double *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}

/**Liefert Anzahl der Gleitkommazahlen und deren Indizes in einem double-Array die kleiner als max_wert sind.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param indizes_array   \c Input:  \n Das Array, in dem Indezes gespeichert werden sollen.\n
 *                				\c Output: \n Dasselbe Array, in dem Indezes gespeichert wurden.\n
 * @param max_wert      Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Anzahl der Gleitkommazahlen einem double-Array die kleiner als max_wert sind.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int indizes_kleiner_als_double_array(const double array[], int laenge, int indizes_array[], double max_wert)
{
  int funde = 0;
  for (int i = 0; i < laenge; i++)
  {
		if (array[i] < max_wert)
		{
			indizes_array[funde] = i + 1;
			funde = funde + 1;
		}
  }
	return funde;
}

/**Summiert die Komponenten eines int-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten summiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten summiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Summe der Komponenten des int-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int summiere_int_array(const int array[], int laenge)
{
  int summe = 0;
  for (int i = 0; i < laenge; i++)
    summe += array[i];
  return summe;
}

/**Summiert einen Bereich (bestimmte Anzahl) von Komponenten eines int-Arrays
 * oder im Hauptspeicher hintereinander stehende int-Werte.
 *
 * @param start   \c Input:  \n Die Adresse, an der die erste zu summierende Zahl gespeichert ist.\n
 *                \c Output: \n Die selbe Adresse, an der die erste zu summierende Zahl gespeichert ist.\n
 * @param anzahl        Die Anzahl der Komponenten des Arrays bzw. die Anzahl der int-Werte im Speicher
 * 											die Summiert werden sollen.
 *
 * @return	Die Summe der Komponenten des int-Arrays bzw. im Hauptspeicher hintereinander stehende int-Werte.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int summiere_int_bereich(int *start, int anzahl)
{
  int summe = 0;
  int *p = start;
  for (int i = 0; i < anzahl; i++)
    summe += *(p + i);
  return summe;
}

/**Berechnet Durchschnitt der Komponenten eines int-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten-Durchschnitt berechnet werden soll.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten-Durchschnitt berechnet werden soll.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Berechneter Durchschnitt der Komponenten des int-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double durchschnitt_int_array(const int array[], int laenge)
{
  double summe = 0.0;
  for (int i = 0; i < laenge; i++)
    summe += array[i];
  double durchschnitt = summe / laenge;
  return durchschnitt;
}

/**Berechnet Durchschnitt der Komponenten eines double-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten-Durchschnitt berechnet werden soll.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten-Durchschnitt berechnet werden soll.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Berechneter Durchschnitt der Komponenten des double-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double durchschnitt_double_array(const double array[], int laenge)
{
  double summe = 0.0;
  for (int i = 0; i < laenge; i++)
    summe += array[i];
  double durchschnitt = summe / laenge;
  return durchschnitt;
}

/**Liefert das Minimum, das Maximum, die Summe und den Durchschnitt der Werte eines int-Arrays.
 *
 * @param array         Das Array, das untersucht wird.
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min           \c Input:  \n Die Adresse, an der das
 *                         Minimum des Arrays gespeichert wird.\n
 *                      \c Output: \n Das Minimum des Arrays.
 * @param max           \c Input:  \n Die Adresse, an der das
 *                         Maximum des Arrays gespeichert wird.\n
 *                      \c Output: \n Das Maximum des Arrays.
 * @param summe         \c Input:  \n Die Adresse, an der die Summe
 *                         des Arrays gespeichert wird.\n
 *                      \c Output: \n Die Summe der Werte des
 *                         Arrays.
 * @param durchschnitt  \c Input:  \n Die Adresse, an der der
 *                         Durchschnitt der Werte des Arrays
 *                         gespeichert wird.\n
 *                      \c Output: \n Der Durchschnitt der Werte
 *                         des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_int_array_statistik(const int array[], int laenge, int *min, int *max, int *summe, double *durchschnitt)
{
  *min = array[0];
  *max = array[0];
  *summe = 0;
  for (int i = 0; i < laenge; i++)
  {
    if (array[i] < *min)
      *min = array[i];
    if (array[i] > *max)
      *max = array[i];
    *summe += array[i];
  }
  *durchschnitt = (1.0 * *summe) / laenge;
}

/**Liefert das Minimum, das Maximum, die Summe und den Durchschnitt der Werte eines double-Arrays.
 *
 * @param array         Das Array, das untersucht wird.
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min           \c Input:  \n Die Adresse, an der das
 *                         Minimum des Arrays gespeichert wird.\n
 *                      \c Output: \n Das Minimum des Arrays.
 * @param max           \c Input:  \n Die Adresse, an der das
 *                         Maximum des Arrays gespeichert wird.\n
 *                      \c Output: \n Das Maximum des Arrays.
 * @param summe         \c Input:  \n Die Adresse, an der die Summe
 *                         des Arrays gespeichert wird.\n
 *                      \c Output: \n Die Summe der Werte des
 *                         Arrays.
 * @param durchschnitt  \c Input:  \n Die Adresse, an der der
 *                         Durchschnitt der Werte des Arrays
 *                         gespeichert wird.\n
 *                      \c Output: \n Der Durchschnitt der Werte
 *                         des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_double_array_statistik(const double array[], int laenge,
		double *min, double *max, double *summe, double *durchschnitt)
{
  *min = array[0];
  *max = array[0];
  *summe = 0;
  for (int i = 0; i < laenge; i++)
  {
    if (array[i] < *min)
      *min = array[i];
    if (array[i] > *max)
      *max = array[i];
    *summe += array[i];
  }
  *durchschnitt = (1.0 * *summe) / laenge;
}

/**Liefert den min-Abstand, min-Abstandindex und max-Abstand, max-Abstandindex der Werte eines int-Arrays.
 *
 * @param array         Das Array, das untersucht wird.
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min_abstand   			\c Input:  \n Die Adresse, an der der Wert mit dem min-Abstand zum naechsten Wert
 * 																				gespeichert wird.\n
			 *                      \c Output: \n Der min-Abstand des Arrays.
 * @param min_abstand_index   \c Input:  \n Die Adresse, an der der min-Abstandindex des Arrays gespeichert wird.\n
 *			                      \c Output: \n Der min-Abstandindex des Arrays.
 * @param max_abstand   			\c Input:  \n Die Adresse, an der der Wert mit dem max-Abstand zum naechsten Wert
 * 																				gespeichert wird.\n
			 *                      \c Output: \n Der max-Abstand des Arrays.
 * @param max_abstand_index   \c Input:  \n Die Adresse, an der der max-Abstandindex des Arrays gespeichert wird.\n
 *			                      \c Output: \n Der max-Abstandindex des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_int_array_statistik_2(const int array[], int laenge,
		unsigned int *min_abstand, unsigned int *min_abstand_index,
		unsigned int *max_abstand, unsigned int *max_abstand_index)
{
	int i = 0;
  *min_abstand = (unsigned int)sqrt(pow((array[i] - array[i + 1]), 2));
  *min_abstand_index = 0;
  *max_abstand = *min_abstand;
  *max_abstand_index = 0;
  unsigned int vergleich = 0;

  for (int i = 0; i < laenge; i++)
  {
  	vergleich = (unsigned int)sqrt(pow((array[i] - array[i + 1]), 2));
    if (i + 1 < laenge)
    {
    	if (vergleich < *min_abstand && vergleich > 0)
    	{
    		*min_abstand = vergleich;
    		*min_abstand_index = i;
    	}
    	if (vergleich > *max_abstand && vergleich > 0)
    	{
    		*max_abstand = vergleich;
    		*max_abstand_index = i;
    	}
		}
  }
}

/**Liefert den min-Abstand, min-Abstandindex und max-Abstand, max-Abstandindex der Werte eines double-Arrays.
 *
 * @param array         Das Array, das untersucht wird.
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min_abstand   			\c Input:  \n Die Adresse, an der der Wert mit dem min-Abstand zum naechsten Wert
 * 																				gespeichert wird.\n
			 *                      \c Output: \n Der min-Abstand des Arrays.
 * @param min_abstand_index   \c Input:  \n Die Adresse, an der der min-Abstandindex des Arrays gespeichert wird.\n
 *			                      \c Output: \n Der min-Abstandindex des Arrays.
 * @param max_abstand   			\c Input:  \n Die Adresse, an der der Wert mit dem max-Abstand zum naechsten Wert
 * 																				gespeichert wird.\n
			 *                      \c Output: \n Der max-Abstand des Arrays.
 * @param max_abstand_index   \c Input:  \n Die Adresse, an der der max-Abstandindex des Arrays gespeichert wird.\n
 *			                      \c Output: \n Der max-Abstandindex des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_double_array_statistik_2(const double array[], int laenge,
		double *min_abstand, unsigned int *min_abstand_index,
		double *max_abstand, unsigned int *max_abstand_index)
{
	int i = 0;
  *min_abstand = (double)sqrt(pow((array[i] - array[i + 1]), 2));
  *min_abstand_index = 0;
  *max_abstand = *min_abstand;
  *max_abstand_index = 0;
  double vergleich = 0;

  for (int i = 0; i < laenge; i++)
  {
  	vergleich = (double)sqrt(pow((array[i] - array[i + 1]), 2));
    if (i + 1 < laenge)
    {
    	if (vergleich < *min_abstand && vergleich > 0)
    	{
    		*min_abstand = vergleich;
    		*min_abstand_index = i;
    	}
    	if (vergleich > *max_abstand && vergleich > 0)
    	{
    		*max_abstand = vergleich;
    		*max_abstand_index = i;
    	}
		}
  }
}

/**Median der Komponenten eines int-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Median der Komponenten eines int-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double median_int_array(const int array[], int laenge)
{
	double median = 0.0;

	if (laenge < 1)
		median = 0.0;
	else
	{
		if (laenge % 2)
		{
			median = array[(laenge - 1) / 2];
		}
		else
		{
			median = (array[(laenge / 2) - 1] + array[(laenge / 2)]) / 2.0;
		}
	}
	return median;
}

/**Median der Komponenten eines double-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Median der Komponenten eines double-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double median_double_array(const double array[], int laenge)
{
	double median = 0.0;

	if (laenge < 1)
		median = 0.0;
	else
	{
		if (laenge % 2)
		{
			median = array[(laenge - 1) / 2];
		}
		else
		{
			median = (array[(laenge / 2) - 1] + array[(laenge / 2)]) / 2.0;
		}
	}
	return median;
}

/**Stichprobenvarianz der Komponenten eines int-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Stichprobenvarianz der Komponenten eines int-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double stichprobenvarianz_int_array(const int array[], int laenge)
{
	double stichprobenvarianz = 0.0;
	double durchschnitt = durchschnitt_int_array(array, laenge);

	if (laenge < 1)
		stichprobenvarianz = 0.0;
	else
	{
		for (int i = 0; i < laenge; i++)
		{
			stichprobenvarianz = stichprobenvarianz + (pow((array[i] - durchschnitt), 2));
		}

	}
	return stichprobenvarianz / (laenge - 1.0);
}

/**Stichprobenvarianz der Komponenten eines double-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Stichprobenvarianz der Komponenten eines double-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double stichprobenvarianz_double_array(const double array[], int laenge)
{
	double stichprobenvarianz = 0.0;
	double durchschnitt = durchschnitt_double_array(array, laenge);

	if (laenge < 1)
		stichprobenvarianz = 0.0;
	else
	{
		for (int i = 0; i < laenge; i++)
		{
			stichprobenvarianz = stichprobenvarianz + (pow((array[i] - durchschnitt), 2));
		}

	}
	return stichprobenvarianz / (laenge - 1.0);
}

/**Standardabweichung der Komponenten eines int-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Standardabweichung der Komponenten eines int-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double standardabweichung_int_array(const int array[], int laenge)
{
	double standardabweichung = 0.0;
	double durchschnitt = durchschnitt_int_array(array, laenge);

	if (laenge < 1)
		standardabweichung = 0.0;
	else
	{
		for (int i = 0; i < laenge; i++)
		{
			standardabweichung = standardabweichung + (pow((array[i] - durchschnitt), 2));
		}

	}
	return pow((standardabweichung / (laenge - 1.0)), 0.5);
}

/**Standardabweichung der Komponenten eines double-Arrays.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten durchsucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten durchsucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return Standardabweichung der Komponenten eines double-Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double standardabweichung_double_array(const double array[], int laenge)
{
	double standardabweichung = 0.0;
	double durchschnitt = durchschnitt_double_array(array, laenge);

	if (laenge < 1)
		standardabweichung = 0.0;
	else
	{
		for (int i = 0; i < laenge; i++)
		{
			standardabweichung = standardabweichung + (pow((array[i] - durchschnitt), 2));
		}

	}
	return pow((standardabweichung / (laenge - 1.0)), 0.5);
}

/**Erstellt und gibt aus eine Statistik zum int-Arrays.
 * Es werden folgende Statistische-Groessen ausgegeben:
 * <br>Laenge des Arreay, Minimum-Wert, Maximum-Wert,
 * <br>Summe, Durchschnitt, Median, Stichprobenvarianz und Standardabweichung  aller Komponente,
 * <br>kleinster Abstand, groesste Abstand und deren Indizes.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten untersucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten untersucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_int_array_statistik(int array[], int laenge)
{
	printf("\nDies ist das Array:\n\n");
	putchar('[');
	schreibe_int_array(array, laenge, 0, ", ", 0);
	putchar(']');

	int minimum = 0;
	int maximum = 0;
	int summe = 0;
	double durchschnitt = 0.0;
	unsigned int min_abstand = 0;
	unsigned int min_abstand_index = 0;
	unsigned int max_abstand = 0;
	unsigned int max_abstand_index = 0;
	liefere_int_array_statistik(array, laenge, &minimum, &maximum, &summe, &durchschnitt);
	liefere_int_array_statistik_2(array, laenge, &min_abstand, &min_abstand_index, &max_abstand, &max_abstand_index);

	qsort(array, laenge, sizeof(array[0]), vergleiche);
	double median = median_int_array(array, laenge);
	double stichprobenvarianz = stichprobenvarianz_int_array(array, laenge);
	double standardabweichung = standardabweichung_int_array(array, laenge);

	printf("\n\n%-25s %10d", 	"Laenge", 						laenge);
	printf("\n%-25s %10d", 		"Minimum", 						minimum);
	printf("\n%-25s %10d", 		"Maximum", 						maximum);
	printf("\n%-25s %10d", 		"Summe", 							summe);
	printf("\n%-25s %10lf", 	"Durchschnitt", 			durchschnitt);
	printf("\n%-25s %10lf", 	"Median", 						median);
	printf("\n%-25s %10lf", 	"Stichprobenvarianz", stichprobenvarianz);
	printf("\n%-25s %10lf", 	"Standardabweichung", standardabweichung);
	printf("\n%-25s %10u\t 	an Stelle %u", 		"kleinster Abstand", min_abstand, min_abstand_index);
	printf("\n%-25s %10u\t 	an Stelle %u\n", 	"groesster Abstand", max_abstand, max_abstand_index);
}

/**Erstellt und gibt aus eine Statistik zum double-Arrays.
 * Es werden folgende Statistische-Groessen ausgegeben:
 * <br>Laenge des Arreay, Minimum-Wert, Maximum-Wert,
 * <br>Summe, Durchschnitt, Median, Stichprobenvarianz und Standardabweichung  aller Komponente,
 * <br>kleinster Abstand, groesste Abstand und deren Indizes.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten untersucht sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten untersucht wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_double_array_statistik(double array[], int laenge)
{
	printf("\nDies ist das Array:\n\n");
	putchar('[');
	schreibe_double_array(array, laenge, 0, ", ", 0);
	putchar(']');

	double minimum = 0;
	double maximum = 0;
	double summe = 0;
	double durchschnitt = 0.0;
	double min_abstand = 0;
	unsigned int min_abstand_index = 0;
	double max_abstand = 0;
	unsigned int max_abstand_index = 0;
	liefere_double_array_statistik(array, laenge, &minimum, &maximum, &summe, &durchschnitt);
	liefere_double_array_statistik_2(array, laenge, &min_abstand, &min_abstand_index, &max_abstand, &max_abstand_index);

	qsort(array, laenge, sizeof(array[0]), vergleiche);
	double median = median_double_array(array, laenge);
	double stichprobenvarianz = stichprobenvarianz_double_array(array, laenge);
	double standardabweichung = standardabweichung_double_array(array, laenge);

	printf("\n\n%-22s %10d", 		"Laenge", 						laenge);
	printf("\n%-25s %10.2lf", 		"Minimum", 						minimum);
	printf("\n%-25s %10.2lf", 		"Maximum", 						maximum);
	printf("\n%-25s %10.2lf", 		"Summe", 							summe);
	printf("\n%-25s %10.2lf", 		"Durchschnitt", 			durchschnitt);
	printf("\n%-25s %10.2lf", 		"Median", 						median);
	printf("\n%-25s %10.2lf", 		"Stichprobenvarianz", stichprobenvarianz);
	printf("\n%-25s %10.2lf", 		"Standardabweichung", standardabweichung);
	printf("\n%-25s %10.2lf\t 	an Stelle %u", 		"kleinster Abstand", min_abstand, min_abstand_index);
	printf("\n%-25s %10.2lf\t 	an Stelle %u\n", 	"groesster Abstand", max_abstand, max_abstand_index);
}
