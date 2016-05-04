#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "interaktionen.h"
#include "zahlensystem.h"
#include "arrays.h"
#include "statistik.h"

/**Reserviert einen Speicherbereich für bestimmte Anzahl von char-Werten mit der Hilfe der standard C-Funktion malloc.
 *
 * @param array		\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 * @param laenge	Anzahl der char-Werte.
 *
 * @return 	liefert die Adresse, an der der reservierte Speicherbereich beginnt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char *speicher_reservieren_char_array_malloc(char *array, int laenge)
{
	array = (char *) malloc(laenge * sizeof(char));

	if (array == NULL)
	{
		printf("\nKein freier Speicher vorhanden.\n");
	}
	return array;
}

/**Reserviert einen Speicherbereich für eine zweidimensionale Matrix mit bestimmte Anzahl von char-Werten
 * mit der Hilfe der standard C-Funktion malloc.
 *
 * @param zeilen	Anzahl der Zeilen im Array.
 * @param spalten	Anzahl der char-Werte pro Zeile.
 * @param array		\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 *
 * @return 	liefert die Adresse, an der der reservierte Speicherbereich beginnt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char **speicher_reservieren_2dim_char_array_malloc(int zeilen, int spalten, char **array)
{
	array = (char **) malloc(zeilen * sizeof(char *));
	if (NULL == array)
	{
		printf("Kein Speicher fuer die Zeilen...\n");
	}
	else
	{
		for (int i = 0; i < zeilen; i++)
		{
			array[i] = speicher_reservieren_char_array_malloc(array[i], spalten);
		}
	}
	return array;
}

/**Reserviert einen zusaetzlichen Speicherbereich für eine zweidimensionale Matrix mit bestimmte Anzahl von char-Werten
 * mit der Hilfe den standard C-Funktionen malloc und realloc.
 *
 * @param alte_zeilen	Anzahl der Zeilen im Array die z.Z. genutzt werden.
 * @param neue_zeilen	Anzahl der Zeilen im Array die zusaetzlich genutzt werden sollen.
 * @param spalten			Anzahl der char-Werte pro Zeile.
 * @param array		\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 *
 * @return 	liefert die Adresse, an der der reservierte Speicherbereich beginnt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char **speicher_neu_reservieren_2dim_char_array_realloc(int alte_zeilen, int neue_zeilen, int spalten, char **array)
{
	array = (char **) realloc(array, (neue_zeilen + alte_zeilen) * sizeof(char *));
	if (NULL == array)
	{
		printf("Kein Speicher fuer die Zeilen...\n");
	}
	else
	{
		for (char **p = (array + alte_zeilen); p < array + (alte_zeilen + neue_zeilen); p++)
		{
			*p = speicher_reservieren_char_array_malloc(*p, spalten);
		}
	}
	return array;
}

/**Gibt einen Speicherbereich für eine zweidimensionale Matrix mit bestimmte Anzahl von char-Werten
 * mit der Hilfe der standard C-Funktion free frei.
 *
 * @param zeilen	Anzahl der Zeilen im Array.
 * @param array		\c Input:  \n Die Adresse, an der der Speicherbereich beginnt.\n
 *                \c Output: \n Die selbe Adresse, an der der Speicherbereich beginnt.\n
 *
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void speicher_freigeben_2dim_char_array_free(int zeilen, char **array)
{
	for (int i = 0; i < zeilen; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**Kopiert alle Komponenten eines int-Arrays in ein anderes, (neues) int-Array.
 *
 * @param original   	\c Input:  \n Das Array, dessen Komponenten kopiert werden sollen.\n
 *                		\c Output: \n Dasselbe Array, dessen Komponenten kopiert wurden.\n
 * @param kopie   		\c Input:  \n Das neu Array, dessen Komponenten kopien enthalten sollen.\n
 *                		\c Output: \n Dasselbe Array, dessen Komponenten kopien anthalten.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void kopiere_int_array(const int original[], int kopie[], int laenge)
{
	for (int i = 0; i < laenge; i++)
	{
		kopie[i] = original[i];
	}
}

/**Versieht alle Komponenten eines char-Arrays mit ein und demselben Wert.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_char_array(char *array, int laenge, char initialwert)
{
  for (int i = 0; i < laenge; i++)
    array[i] = initialwert;
}

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
void initialisiere_int_bereich(int *von, int *bis, int initialwert)
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
void initialisiere_int_array(int array[], int laenge, int initialwert)
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
void initialisiere_int_bereich_zufaellig(int *von, int *bis, int min,  int max)
{
  for (int *p = von; p <= bis; p++)
    *p = liefere_ganze_zufallszahl(min, max);
}

/**Versieht alle Komponenten eines double-Arrays mit ein und demselben Wert.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_double_array(double array[], int laenge, double initialwert)
{
  for (int i = 0; i < laenge; i++)
    array[i] = initialwert;
}

/**Versieht alle Komponenten eines int-Arrays mit zufaelligen Werten.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min           minimale Größe der ganzen Zufallszahl.
 * @param max           maximale Größe der ganzen Zufallszahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_int_array_zufaellig(int array[], int laenge, int min, int max)
{
  for (int i = 0; i < laenge; i++)
    array[i] = liefere_ganze_zufallszahl(min, max);
}

/**Versieht alle Komponenten eines double-Arrays mit Zufaelligen Werten.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 * @param min           minimale Größe der Gleitkommazufallszahl.
 * @param max           maximale Größe der Gleitkommazufallszahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_double_array_zufaellig(double array[], int laenge, double min, double max)
{
  for (int i = 0; i < laenge; i++)
    array[i] = liefere_gleitkomma_zufallszahl(min, max);
}

/**Versieht alle Komponenten eines zweidimensionale char-Arrays mit ein und demselben Wert.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_2dim_char_array(int zeilen, int spalten, char **array, char initialwert)
{
  for (int i = 0; i < zeilen; i++)
    initialisiere_char_array(array[i], spalten, initialwert);
}

/**Versieht alle Komponenten eines zweidimensionale int-Arrays mit ein und demselben Wert.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_2dim_int_array(int zeilen, int spalten, int array[zeilen][spalten], int initialwert)
{
  for (int i = 0; i < zeilen; i++)
    initialisiere_int_array(array[i], spalten, initialwert);
}

/**Versieht alle Komponenten eines zweidimensionale int-Arrays mit Zufaelligen Werten.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param min           minimale Größe der ganzen Zufallszahl.
 * @param max           maximale Größe der ganzen Zufallszahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_2dim_int_array_zufaellig(int zeilen, int spalten, int array[zeilen][spalten], int min, int max)
{
  for (int i = 0; i < zeilen; i++)
    initialisiere_int_array_zufaellig(array[i], spalten, min, max);
}

/**Versieht alle Komponenten einer bestimmten Spalte eines zweidimensionale int-Arrays mit ein und demselben Wert.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten den Wert erhalten sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten den Wert erhalten haben.\n
 * @param die_spalte	  Die Spalte, deren Komponenten initialisiert werden.
 * @param initialwert   Der Wert, den die Komponenten des Arrays erhalten.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void initialisiere_spalte_2dim_int_array(int zeilen, int spalten, int array[zeilen][spalten],
																							int die_spalte, int initialwert)
{
  for (int *p = &array[0][die_spalte];
       p < &array[zeilen - 1][spalten - 1];
       p += spalten)
    *p = initialwert;
}

/**Gibt die Komponenten eines char-Arrays auf dem Bildschirm aus.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben werden sollen.\n
 * @param laenge   Die Anzahl Komponenten des Arrays.
 * @param breite   Die Feldbreite, die zur Ausgabe jeder Komponente benutzt wird.
 * @param trenner  Eine Zeichenkette, die nach jeder Komponente ausgegeben wird.
 * @param am_ende  Ein Schalter, der festlegt, ob die Zeichenkette
 *                   auch hinter der letzten Komponente ausgegeben
 *                   wird (Input: 1) oder nicht (Input: 0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_char_array(char *array, int laenge, int breite, char *trenner, _Bool am_ende)
{
  if (laenge != 0)
  {
  	for (int i = 0; i < laenge - 1; i++)
			printf("%*d%s", breite, array[i], trenner);
		printf("%*d%s", breite, array[laenge - 1], am_ende ? trenner : "");
  }
}

/**Gibt die Komponenten eines int-Arrays auf dem Bildschirm aus.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben werden sollen.\n
 * @param laenge   Die Anzahl Komponenten des Arrays.
 * @param breite   Die Feldbreite, die zur Ausgabe jeder Komponente benutzt wird.
 * @param trenner  Eine Zeichenkette, die nach jeder Komponente ausgegeben wird.
 * @param am_ende  Ein Schalter, der festlegt, ob die Zeichenkette
 *                   auch hinter der letzten Komponente ausgegeben
 *                   wird (Input: 1) oder nicht (Input: 0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_int_array(int array[], int laenge, int breite, char *trenner, _Bool am_ende)
{
  if (laenge != 0)
  {
  	for (int i = 0; i < laenge - 1; i++)
			printf("%*d%s", breite, array[i], trenner);
		printf("%*d%s", breite, array[laenge - 1], am_ende ? trenner : "");
  }
}

/**Gibt die Komponenten eines int-Arrays auf dem Bildschirm aus.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben werden sollen.\n
 * @param laenge   Die Anzahl Komponenten des Arrays.
 * @param breite   Die Feldbreite, die zur Ausgabe jeder Komponente benutzt wird.
 * @param trenner  Eine Zeichenkette, die nach jeder Komponente ausgegeben wird.
 * @param am_ende  Ein Schalter, der festlegt, ob die Zeichenkette
 *                   auch hinter der letzten Komponente ausgegeben
 *                   wird (Input: 1) oder nicht (Input: 0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_double_array(const double array[], int laenge, int breite, char *trenner, _Bool am_ende)
{
  for (int i = 0; i < laenge - 1; i++)
  	printf("%*lf%s", breite, array[i], trenner);
  printf("%*lf%s", breite, array[laenge - 1], am_ende ? trenner : "");
}

/**Gibt die Komponenten eines zweidimensionales char-Arrays auf dem Bildschirm aus.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben werden sollen.\n
 * @param breite   Die Feldbreite, die zur Ausgabe jeder Komponente benutzt wird.
 * @param trenner  Eine Zeichenkette, die nach jeder Komponente ausgegeben wird.
 * @param am_ende  Ein Schalter, der festlegt, ob die Zeichenkette
 *                   auch hinter der letzten Komponente ausgegeben
 *                   wird (Input: 1) oder nicht (Input: 0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_2dim_char_array(int zeilen, int spalten, char **array, int breite, char *trenner, _Bool am_ende)
{
  for (int i = 0; i < zeilen; i++)
  {
    schreibe_char_array(array[i], spalten, breite, trenner, am_ende);
    putchar('\n');
  }
}

/**Gibt die Komponenten eines zweidimensionales int-Arrays auf dem Bildschirm aus.
 *
 * @param zeilen        Die Anzahl der Zeilen des Arrays.
 * @param spalten       Die Anzahl der Spalten des Arrays.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben werden sollen.\n
 * @param breite   Die Feldbreite, die zur Ausgabe jeder Komponente benutzt wird.
 * @param trenner  Eine Zeichenkette, die nach jeder Komponente ausgegeben wird.
 * @param am_ende  Ein Schalter, der festlegt, ob die Zeichenkette
 *                   auch hinter der letzten Komponente ausgegeben
 *                   wird (Input: 1) oder nicht (Input: 0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_2dim_int_array(int zeilen, int spalten, int array[zeilen][spalten], int breite, char *trenner, _Bool am_ende)
{
  for (int i = 0; i < zeilen; i++)
  {
    schreibe_int_array(array[i], spalten, breite, trenner, am_ende);
    putchar('\n');
  }
}

/**Sortiert das Array mit ganze Zahlen nach Bubble Sort (Sortieren durch Aufsteigen).
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void int_bubble_sort_1(int array[], int laenge)
{
  int ablage = 0;
  _Bool ist_sortiert = 0;
  while (!ist_sortiert)
  {
    ist_sortiert = 1;
    for (int i = 0; i < laenge - 1; i++)
    {
      if (array[i] > array[i + 1])
      {
        ist_sortiert = 0;
        ablage = array[i];
        array[i] = array[i + 1];
        array[i + 1] = ablage;
      }
    }
  }
}

/**Sortiert das Array mit ganze Zahlen nach Bubble Sort (Sortieren durch Aufsteigen).
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void int_bubble_sort_2(int array[], int laenge)
{
  int ablage;
  for (int i = 0; i < laenge - 1; i++)
    for (int j = laenge - 1; i < j; j--)
      if (array[j - 1] > array[j])
      {
        ablage = array[j - 1];
        array[j - 1] = array[j];
        array[j] = ablage;
      }
}

/**Sortiert das Array mit ganze Zahlen nach Selectionsort (Auswahl).
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void int_selection_sort_1(int array[], int laenge)
{
  int index_max;
  int ablage;
  for (int i = laenge - 1; i > 0; i--)
  {
    index_max = 0;
    for (int j = 0; j <= i; j++)        // suche groessten Wert
      if (array[j] > array[index_max])
        index_max = j;
    if (array[index_max] > array[i])  // bringe ihn nach hinten
    {
      ablage = array[i];
      array[i] = array[index_max];
      array[index_max] = ablage;
    }
  }
}

/**Sortiert das Array mit ganze Zahlen nach Selectionsort (Auswahl).
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void int_selection_sort_2(int array[], int laenge)
{
  int *max = NULL;
  for (int i = laenge - 1; i > 0; i--)
  {
    max = liefere_max_int_array(array, i);
    if (*max > array[i])
      vertausche(max, &array[i]);
  }
}

/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:  \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                \c Output: \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:  \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                \c Output: \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void vertausche(int *x, int *y)
{
  int ablage = *x;
  *x = *y;
  *y = ablage;
}

/**Vergleichfunktion fuer Quicksort.
 *
 * @param i   		\c Input:  \n Die Adresse, an der die erste zu vergleichende Zahl gespeichert ist.\n
 *                \c Output: \n Die selbe Adresse, an der die erste zu vergleichende Zahl gespeichert ist.\n
 * @param j   		\c Input:  \n Die Adresse, an der die zweite zu vergleichende Zahl gespeichert ist.
 *                \c Output: \n Die selbe Adresse, an der die zweite zu vergleichende Zahl gespeichert ist.\n
 *
 * @return 	Die Funktion liefert einen negativen Wert, wenn ihr erstes Argument (der Suchschlüssel)
 * 					kleiner als ihr zweites Argument (ein Tabelleneintrag) ist, Null, wenn beide gleich sind,
 * 					und sonst einen positiven Wert.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int vergleiche(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}

/**Vergleichfunktion fuer Quicksort.
 *
 * @param i   		\c Input:  \n Die Adresse, an der die erste zu vergleichende Zahl gespeichert ist.\n
 *                \c Output: \n Die selbe Adresse, an der die erste zu vergleichende Zahl gespeichert ist.\n
 * @param j   		\c Input:  \n Die Adresse, an der die zweite zu vergleichende Zahl gespeichert ist.
 *                \c Output: \n Die selbe Adresse, an der die zweite zu vergleichende Zahl gespeichert ist.\n
 *
 * @return 	Die Funktion liefert einen negativen Wert, wenn ihr erstes Argument (der Suchschlüssel)
 * 					kleiner als ihr zweites Argument (ein Tabelleneintrag) ist, Null, wenn beide gleich sind,
 * 					und sonst einen positiven Wert.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int vergleiche_char(const void *i, const void *j)
{
  return *(char *)i - *(char *)j;
}

/**Misst die Zeit, die für die Sortierung nach Bubble Sort 1 benötigt wird.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return 	Die Zeit, die für die Sortierung nach Bubble Sort 1 benötigt wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double messe_int_bubble_sort_1(int array[], int laenge)
{
  clock_t start = clock();
  int_bubble_sort_1(array, laenge);
  clock_t stop = clock();
  return (stop - start) / (1.0 * CLOCKS_PER_SEC);
}

/**Misst die Zeit, die für die Sortierung nach Bubble Sort 2 benötigt wird.
 *
 * @param array   \c Input:  \n Das Array, dessen Komponenten sortiert sollen.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten sortiert wurden.\n
 * @param laenge        Die Anzahl Komponenten des Arrays.
 *
 * @return 	Die Zeit, die für die Sortierung nach Bubble Sort 2 benötigt wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double messe_int_bubble_sort_2(int array[], int laenge)
{
  clock_t start = clock();
  int_bubble_sort_2(array, laenge);
  clock_t stop = clock();
  return (stop - start) / (1.0 * CLOCKS_PER_SEC);
}

/**Schreibt aus einem Char-Array die einzelne Zeichen bis das Ende erreicht wurde.
 *
 * @param zeichenkette    \c Input:  \n Das Array, dessen Komponenten des Datentyps Char ausgegeben sollen.\n
 *                        \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_zeichenkette(const char zeichenkette[])
{
  for (int i = 0; zeichenkette[i]; i++)
    putchar(zeichenkette[i]);
}

/**Schreibt ein Menue und erfasst eine Anwort mit einer ganzen Zahl und vergleicht diese
 * mit dem Wertebereich zwischen 1 und menuelaenge.
 * Trifft die Eingabe auf keinen der beiden Werte (min, max) zu oder einen Wert dazwischen wird eine Fehlermeldung
 * ausgeben, die noch ein mal den gewünschten Wertebereich, also 1 bis menuelaenge, anzeigt.
 *
 * @param menuelaenge        Die Anzahl der Zeilen des Menues und gleichzeitig die max. Groesse des Menues.
 * @param textlaenge	       Die max. Laenge des Menuetextes.
 * @param menue   \c Input:  \n Das Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *
 * @return	Die erfasste Eingabe, ganze Zahl wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int waehle_aus_menue(int menuelaenge, int textlaenge, char menue[menuelaenge][textlaenge])
{
  schreibe_menue(menuelaenge, textlaenge, menue);
  char *zeichenkette = "\n\nIhre Wahl:  ";
  return erfasse_ganze_zahl(zeichenkette, 1, menuelaenge);
}

/**Schreibt ein Menue mit menuelaenge Zeilen und mit dem uebergebenen Text.
 *
 * @param menuelaenge        Die Anzahl der Zeilen des Menues und gleichzeitig die max. Groesse des Menues.
 * @param textlaenge	       Die max. Laenge des Menuetextes.
 * @param menue   \c Input:  \n Das Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_menue(int menuelaenge, int textlaenge, char menue[menuelaenge][textlaenge])
{
  for (int i = 0; i < menuelaenge; i++)
    printf("\n(%d)\t  %s", i + 1, menue[i]);
}
