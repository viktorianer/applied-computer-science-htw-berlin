#include "statistik.h"
// weitere Angaben
// Code der Konstruktoren
// Code der Methoden
/**Sucht einen int-Array nach einem bestimmten int-Wert durch und gibt aus ob dieser vorhanden ist.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten durchsucht werden.\n
 * @param laenge        	Die Anzahl Komponenten des Arrays.
 * @param gesuchte_zahl   Der int-Wert nach dem im Arrays gesucht werden soll.
 * @return	Gibt an ob ein bestimmter int-Wert im Array enthalten ist (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Statistik::ist_zahl_im_array(const int *array, int laenge, int gesuchte_zahl)
{
  bool gefunden = false;
  for (int i = 0; i < laenge; i++)
		if (array[i] == gesuchte_zahl)
			gefunden = true;
	return gefunden;
}
/**Liefert die kleinste, ganze Zahl in einem int-Array.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @return	Die Adresse auf die kleinste, ganze Zahl in einem int-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
const int *Statistik::liefere_min(const int *array, int laenge)
{
  const int *min = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] < *min)
      min = &array[i];
  return min;
}
/**Liefert die groesste, ganze Zahl in einem int-Array.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten nach dem groessten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @return	Die Adresse auf die groesste, ganze Zahl in einem int-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
const int *Statistik::liefere_max(const int *array, int laenge)
{
  const int *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}
/**Liefert die groesste Gleitkommazahl in einem long double-Array.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @return	Die Adresse auf die groesste Gleitkommazahl in einem long double-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
const long double *Statistik::liefere_max(const long double *array, int laenge)
{
	const long double *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}

/**Liefert die groesste Gleitkommazahl in einem double-Array.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten nach dem kleinsten Wert durchsucht werden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @return	Die Adresse auf die groesste Gleitkommazahl in einem double-Array.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
const double *Statistik::liefere_max(const double *array, int laenge)
{
  const double *max = &array[0];
  for (int i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}
/**Liefert die Haeufigkeitsverteilung der Werte eines int-Arrays.
 *
 * @param array   			\c Input:   Die Adresse auf ein Speicherbereich mit int-Werten das untersucht wird.\n
 * @param laenge        Die Anzahl der Komponenten.
 * @param haeufigkeitsverteilung   	\c Input:   Die Adresse, an der die Haeufigkeitsverteilung gespeichert wird.\n
 *			                      			\c Output:  Die Adresse, an der die Haeufigkeitsverteilung gespeichert wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Statistik::haeufigkeitsverteilung(const int *array, int laenge, int *haeufigkeitsverteilung)
{
	int zahl = 0;
	for (int i = 0; i < laenge; i++)
	{
		zahl = array[i];
		haeufigkeitsverteilung[zahl - 1] = haeufigkeitsverteilung[zahl - 1] + 1;
	}
}
/**Liefert die Haeufigkeitsverteilung der Minima eines int-Arrays.
 *
 * @param array   			\c Input:   Die Adresse auf ein Speicherbereich mit int-Werten das untersucht wird.\n
 * @param laenge        Die Anzahl der Komponenten.
 * @param minima		   	\c Input:   Die Adresse, an der die Haeufigkeitsverteilung der Minima gespeichert wird.\n
 *			            		\c Output:  Die Adresse, an der die Haeufigkeitsverteilung der Minima gespeichert wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Statistik::haeufigkeitsverteilung_minima(const int *array, int laenge, int *minima)
{
	int zahl = array[0];
	for (int i = 0; i < laenge; i++)
		if (zahl > array[i])
			zahl = array[i];
	minima[zahl - 1] = minima[zahl - 1] + 1;
}
/**Liefert die Haeufigkeitsverteilung der Maxima eines int-Arrays.
 *
 * @param array   			\c Input:   Die Adresse auf ein Speicherbereich mit int-Werten das untersucht wird.\n
 * @param laenge        Die Anzahl der Komponenten.
 * @param maxima		   	\c Input:   Die Adresse, an der die Haeufigkeitsverteilung der Maxima gespeichert wird.\n
 *			            		\c Output:  Die Adresse, an der die Haeufigkeitsverteilung der Maxima gespeichert wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Statistik::haeufigkeitsverteilung_maxima(const int *array, int laenge, int *maxima)
{
	int zahl = array[0];
	for (int i = 0; i < laenge; i++)
		if (zahl < array[i])
			zahl = array[i];
	maxima[zahl - 1] = maxima[zahl - 1] + 1;
}
/**Gibt an ob in einen int-Array alle Zahlen gerade sind.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten durchsucht werden soll.\n
 * @param laenge        	Die Anzahl Komponenten des Arrays.
 *
 * @return	Gibt an ob alle Werte im Array gerade sind (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Statistik::sind_alle_zahlen_gerade(const int *array, int laenge)
{
  bool gerade = false;
  int funde = 0;
  for (int i = 0; i < laenge; i++)
  {
		if ((array[i] % 2) == 0)
			funde = funde + 1;
  }
  if (funde == laenge)
  	gerade = true;
	return gerade;
}
/**Gibt an ob in einen int-Array alle Zahlen ungerade sind.
 *
 * @param array   \c Input:   Das Array, dessen Komponenten durchsucht werden soll.\n
 * @param laenge        	Die Anzahl Komponenten des Arrays.
 *
 * @return	Gibt an ob alle Werte im Array ungerade sind (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Statistik::sind_alle_zahlen_ungerade(const int *array, int laenge)
{
  bool ungerade = false;
  int funde = 0;
  for (int i = 0; i < laenge; i++)
  {
		if ((array[i] % 2) != 0)
			funde = funde + 1;
  }
  if (funde == laenge)
  	ungerade = true;
	return ungerade;
}
// eventuell Code
// weiterer Funktionen
