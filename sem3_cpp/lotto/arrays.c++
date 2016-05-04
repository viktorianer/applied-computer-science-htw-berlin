#include "arrays.h"
/**Versieht alle int-Komponenten eines Speicherbereiches mit ein und demselben Wert.
 *
 * @param von			\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 * @param bis			\c Input:  \n Die Adresse, an der der Speicherbereich endet.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich endet.\n
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::initialisiere_int_bereich(int *von, int *bis, int initialwert)
{
  for (int *p = von; p <= bis; p++)
    *p = initialwert;
}

/**Versieht alle Komponenten eines int-Arrays mit ein und demselben Wert.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::initialisiere_int_array(int *array, int laenge, int initialwert)
{
  for (int i = 0; i < laenge; i++)
    array[i] = initialwert;
}

/**Versieht alle int-Komponenten eines Speicherbereiches mit zufaelligen Wert.
 *
 * @param von			\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 * @param bis			\c Input:  \n Die Adresse, an der der Speicherbereich endet.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich endet.\n
 * @param min           minimale Größe der ganzen Zufallszahl.
 * @param max           maximale Größe der ganzen Zufallszahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::initialisiere_int_bereich_zufaellig(int *von, int *bis, int min,  int max)
{
  for (int *p = von; p <= bis; p++)
    *p = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(min, max);
}

/**Schreibt ein zweidim. int-Array auf dem Bildschirm.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 * @param zeilen            Die Anzahl Zeilen des Arrays.
 * @param spalten           Die Anzahl Splaten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::schreibe_2dim_int_array(int *array, int zeilen, int spalten)
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
 * @param laenge            Die Laenge des Arrays.
 * @param spaltenbreite     Die gewuenschte Spaltenbreite fuer die Ausgabe.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::schreibe_long_double_array(long double *array, int laenge, int spaltenbreite)
{
  for (long double *q = array; q < array + laenge; q++)
    cout << setw(spaltenbreite) << *q;
}
/**Schreibt ein long double-Array auf dem Bildschirm.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 * @param laenge            Die Laenge des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Arrays::schreibe_long_double_array(long double *array, int laenge)
{
  schreibe_long_double_array(array, laenge, 0);
}
/**Schreibt ein zweidim. long double-Array auf dem Bildschirm mit einer vorgegebenen Spaltenbreite.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
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