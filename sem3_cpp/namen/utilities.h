#ifndef UTILITIES_H
#define	UTILITIES_H

#include <vector>
#include <algorithm>

using namespace std;

/**Liefert den kleiner-gleich Wert von zwei Werten. Die beiden Werte muessen den Operator <= sinnvoll ueberschrieben haben.
 * <br>Beispiel 1: Der Name einer Person Peter kommt vor dem Namen Viktor im Alphabet. Deshalb der Peter ist kleiner als Viktor.
 * <br>Beispiel 2: Die Zahl 10 kommt nicht vor der 10, die sind gleich. Die Zahl 5 ist aber kleiner als 10, d.h. sie ist kleiner als 10.
 *
 * @param wert1 Ein Wert T.
 * @param wert2 Eine zum Vergleich herangezogener zweiter Wert T.
 * @return Ist der Wert1 kleiner-gleich als der Wert2 wird Wert1 zurueckgegeben und wenn Wert2 kleiner als Wert1 ist der Wert2 zurueckgegeben.
 */
template <typename T>
T liefere_min(T wert1, T wert2)
{
  return wert1 <= wert2 ? wert1 : wert2;
}
template <typename T>
/**Schreibt das Verhaeltnis kleiner-gleich von zwei Werten. Die beiden Werte muessen den Operator <= sinnvoll ueberschrieben haben.
 * <br>Beispiel 1: Der Name einer Person Peter kommt vor dem Namen Viktor im Alphabet. Deshalb der Peter ist kleiner als Viktor.
 * D.h. wird ausgegeben Peter <= Viktor.
 * <br>Beispiel 2: Die Zahl 10 kommt nicht vor der 10, die sind gleich. Die Zahl 5 ist aber kleiner als 10, d.h. sie ist kleiner als 10.
 * D.h. wird ausgegeben 10 <= 10 oder 5 <= 10.
 *
 * @param wert1 Ein Wert T.
 * @param wert2 Eine zum Vergleich herangezogener zweiter Wert T.
 */
void schreibe_min(std::ostream& ausgabe, T wert1, T wert2)
{
  ausgabe << "min{" << wert1
          << ", " << wert2 <<  "} = "
          << liefere_min(wert1, wert2) << std::endl;
}
/**Liefert den groesseren Wert aus dem T-Array. Die Werte T im Array muessen den Operator > sinnvoll ueberschrieben haben.
 * <br>Beispiel 1: Der Name einer Person Peter kommt vor dem Namen Viktor im Alphabet. Deshalb der Viktor ist groesser als Peter.
 * <br>Beispiel 2: Die 10 ist groeser Zahl 5 , d.h. sie ist kleiner als 10.
 *
 * @param array   \c Input:  \n Das T-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das T-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 * @return Den Zeiger auf das max. T-Wert im T-Array.
 */
template <typename T, typename Indextyp>
T *liefere_max(T array[], Indextyp laenge)
{
  T *max = &array[0];
  for (Indextyp i = 0; i < laenge; i++)
    if (array[i] > *max)
      max = &array[i];
  return max;
}
/**Liefert den groesseren Wert aus dem T-Array. Die Werte T im Array werden nach der Vorschrift der Vergleichsfunktion verglichen.
 * Diese muss immer den max- T-Wert der zwei zum Vergleich herangezogener Werte finden und
 * wenn Wert1 kleiner als Wert2 ist (d.h. vor dem Wert2 kommt) fals und sonst true liefern.
 *
 * @param array   \c Input:  \n Das T-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das T-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 * @param vergleiche  Vergleichsfunktion. Diese muss immer den max Wert der zwei zum Vergleich herangezogener Werte finden und
 * wenn Wert1 kleiner als Wert2 ist (d.h. vor dem Wert2 kommt) false und sonst true liefern.
 * @return Den Zeiger auf das max. T-Wert im T-Array.
 */
template <typename T, typename Indextyp, typename Vergleichstyp>
T *liefere_max(T array[], Indextyp laenge, Vergleichstyp& vergleiche)
{
  T* max = &array[0];
  for (Indextyp i = 0; i < laenge; i++)
    if (vergleiche(&array[i], max) > 0)
      max = &array[i];
  return max;
}

//template <typename T, typename Indextyp, typename Vergleichstyp>
//T *liefere_max(vector<T*> array, Indextyp laenge, Vergleichstyp& vergleiche)
//{
//  T* max = array[0];
//  for (Indextyp i = 0; i < laenge; i++)
//    if (vergleiche(array[i], max) > 0)
//      max = array[i];
//  return max;
//}
/**Liefert einen Zeiger auf dem Speicherbereich, der fuer ein T-Array bestimmter Laenge reserviert wurde.
 *
 * @param laenge  Laenge des T-Arrays, fuer das der Speicher reserviert werden soll.
 * @return Einen Zeiger auf dem Speicherbereich, der fuer ein T-Array bestimmter Laenge reserviert wurde.
 */
template <typename T>
T *liefere_array(int laenge)
{
  return new T[laenge];
}
/**Initialisiert einen Bereich im Speicher (von - bis) mit einem Initialwert T.
 *
 * @param von   Zeiger auf dem Start des Speicherbereiches.
 * @param bis   Zeiger auf das Ende des Speicherbereiches.
 * @param initialwert Ein Initialwert, mit dem der Speicherbereich initialisiert werden soll.
 */
template <typename T>
void initialisiere_bereich(T *von, T *bis, T initialwert)
{
  for (T *p = von; p <= bis; p++)
    *p = initialwert;
}
/**Initialisiert einen T-Array mit einem Initialwert T.
 *
 * @param array   \c Input:  \n Das T-Array, welches initialisiert werden soll.\n
 *                \c Output: \n Das T-Array, welches initialisiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 * @param initialwert Ein Initialwert, mit dem das T-Array initialisiert werden soll.
 */
template <typename T, typename Indextyp>
void initialisiere_array(T array[], Indextyp laenge, T initialwert)
{
  initialisiere_bereich(array, array + laenge - 1, initialwert);
}
/**Schreibt ein T-Array in den Ausgabestream. Dazu muss T den Operator << sinnvoll ueberschrieben haben.
 *
 * @param ausgabe Der Ausgabestream, ueber welches die Ausgabe rausgeht.
 * @param array   \c Input:  \n Das T-Array, welches ausgegeben werden soll.\n
 * @param laenge  Die Laenge des Arrays.
 */
template <typename T>
void schreibe_array(std::ostream& ausgabe, const T array[], int laenge)
{
  schreibe_array(ausgabe, array, laenge, " ", false);
}
/**Schreibt ein T-Array in den Ausgabestream mit einer Formatierung. Dazu muss T den Operator << sinnvoll ueberschrieben haben.
 * Die Werte werden mit einem Treffen getrennt ausgegeben. Am Ende wird der Trenner ausgegeben (true) oder nicht (false).
 *
 * @param ausgabe Der Ausgabestream, ueber welches die Ausgabe rausgeht.
 * @param array   \c Input:  \n Das T-Array, welches ausgegeben werden soll.\n
 * @param laenge  Die Laenge des Arrays.
 * @param trenner Trenner, der zwischen den T-Werten ausgegeben werden soll.
 * @param am_ende Gibt an, ob der Trenner am Ende der Ausgabe mit ausgegeben werden soll (true) oder nicht (false).
 */
template <typename T, typename Indextyp>
void schreibe_array(std::ostream& ausgabe, const T array[], Indextyp laenge, std::string trenner, bool am_ende)
{
  for (Indextyp i = 0; i < laenge - 1; i++)
    ausgabe << array[i] << trenner;
  ausgabe << array[laenge - 1];
  if (am_ende)
    ausgabe << trenner;
}
/**Sortiert ein T-Array mit dem Selection Sort. Dazu muss der Operator> sinnvoll ueberschrieben werden.
 *
 * @param array   \c Input:  \n Das T-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das T-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 */
template <typename T, typename Indextyp>
void selection_sort(T array[], Indextyp laenge)
{
  T *max = 0;
  for (Indextyp i = laenge - 1; i > 0; i--)
  {
    max = liefere_max(array, i);
    if (*max > array[i])
      vertausche(max, &array[i]);
  }
}
/**Sortiert ein T-Array mit dem Selection Sort. Die Werte T im Array werden nach der Vorschrift der Vergleichsfunktion verglichen.
 *
 * @param array   \c Input:  \n Das T-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das T-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 * @param vergleiche  Vergleichsfunktion. Diese muss immer den max Wert der zwei zum Vergleich herangezogener Werte finden und
 * wenn Wert1 kleiner als Wert2 ist (d.h. vor dem Wert2 kommt) false und sonst true liefern.
 */
template <typename T, typename Indextyp, typename Vergleichstyp>
void selection_sort(T array[], Indextyp laenge, Vergleichstyp& vergleiche)
{
  T* max = 0;
  for (Indextyp i = laenge - 1; i > 0; i--)
  {
    max = liefere_max(array, i, vergleiche);
    if (vergleiche(max, &array[i]) > 0)
      vertausche(max, &array[i]);
  }
}

//template <typename T, typename Vergleichstyp>
//void selection_sort(vector<T*> array, Vergleichstyp* vergleiche)
//{
//  sort(array.begin(), array.end(), vergleiche);
//}
/**Vertauscht zwei T-Werte mit einander.
 *
 * @param x Der T-Zeiger auf den Wert1.
 * @param y Der T-Zeiger auf den Wert2.
 */
template <typename T>
void vertausche(T* x, T* y)
{
  T ablage = *x;
  *x = *y;
  *y = ablage;
}
/**Vertauscht zwei T-Werte mit einander.
 *
 * @param x Die T-Referenz auf den Wert1.
 * @param y Die T-Referenz auf den Wert2.
 */
template <typename T>
void vertausche(T& x, T& y)
{
  T ablage = x;
  x = y;
  y = ablage;
}

#endif	/* UTILITIES_H */

