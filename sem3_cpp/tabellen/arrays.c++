#include "arrays.h"
/**Schreibt ein zweidim. int-Array auf dem Bildschirm.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param zeilen            Die Anzahl Zeilen des Arrays.
 * @param spalten           Die Anzahl Splaten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_2dim_int_array(int *array, int zeilen, int spalten)
{
  for (int *p = array; p < array + zeilen * spalten; p += spalten)
    for (int *q = p; q < p + spalten; q++)
      if (q < p + spalten - 1)
        cout << *q;
      else
        cout << *q << endl;
}
/**Schreibt ein long double-Array auf dem Bildschirm mit einer vorgegebenen Spaltenbreite.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 * @param spaltenbreite     Die gewuenschte Spaltenbreite fuer die Ausgabe.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_long_double_array(long double *array, int laenge, int spaltenbreite)
{
  for (long double *q = array; q < array + laenge; q++)
    cout << setw(spaltenbreite) << *q;
}
/**Schreibt ein long double-Array auf dem Bildschirm.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_long_double_array(long double *array, int laenge)
{
  schreibe_long_double_array(array, laenge, 0);
}
/**Schreibt ein zweidim. long double-Array auf dem Bildschirm mit einer vorgegebenen Spaltenbreite.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param zeilen            Die Anzahl Zeilen des Arrays.
 * @param spalten           Die Anzahl Splaten des Arrays.
 * @param spaltenbreite     Die gewuenschte Spaltenbreite fuer die Ausgabe.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten, int spaltenbreite)
{
  for (long double *p = array; p < array + zeilen * spalten; p += spalten)
    for (long double *q = p; q < p + spalten; q++)
      if (q < p + spalten - 1)
        cout << setw(spaltenbreite) << *q;
      else
        cout << setw(spaltenbreite) << *q << endl;
}
/**Schreibt ein zweidim. long double-Array auf dem Bildschirm.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param zeilen            Die Anzahl Zeilen des Arrays.
 * @param spalten           Die Anzahl Splaten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_2dim_long_double_array(long double *array, int zeilen, int spalten)
{
  schreibe_2dim_long_double_array(array, zeilen, spalten, 0);
}

/**Liefert die groesste Gleitkommazahl in einem long double-Array.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return	Die Adresse auf die groesste Gleitkommazahl in einem long double-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
long double *liefere_max_long_double_array(long double array[], int laenge)
{
	long double *max = &array[0];
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