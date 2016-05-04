#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "zahlensystem.h"

/**Initialisiert den Zufallsgenerator mit der Systemzeit.
 * Damit der Zufallsgenerator nicht immer die gleichen Zahlen ermittelt, muss zunächst der Zufallsgenerator mit der
 * Systemzeit initialisiert werden.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
void initialisiere_zufallszahlengenerator(void)
{
  srand((unsigned) time(NULL));
}

/**Liefert eine ganze Zufallszahl aus einen angegebenen Bereich. Zufor muss der Zufallsgenerator initialisiert werden.
 *
 * Bitte beachten Sie, dass rand() in der Regel keine sehr gute Streuung liefert.
 * Für statistische Zwecke sollten Sie deshalb nicht auf die Standardbibliothek zurückgreifen.
 * (Die Funktion rand() liefert einen Wert zwischen 0 und RAND_MAX.)
 *
 * @param min             minimale Größe der ganzen Zufallszahl.
 * @param max             maximale Größe der ganzen Zufallszahl.
 *
 * @return  Die ganze Zufallszahl wird zurückgegeben.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int liefere_ganze_zufallszahl(int min, int max)
{
  if (min > max)
  {
    int ablage = min;
    min = max;
    max = ablage;
  }
  _Bool input_ok = (0 < max) && (max <= RAND_MAX);
  int zufallszahl = input_ok ? rand() % (max - min + 1) : -1;
  return zufallszahl + min;

}

/**Liefert eine Gleitkommazufallszahl aus einen angegebenen Bereich. Zufor muss der Zufallsgenerator initialisiert werden.
 *
 * Bitte beachten Sie, dass rand() in der Regel keine sehr gute Streuung liefert.
 * Für statistische Zwecke sollten Sie deshalb nicht auf die Standardbibliothek zurückgreifen.
 * (Die Funktion rand() liefert einen Wert zwischen 0 und RAND_MAX.)
 *
 * @param min             minimale Größe der ganzen Zufallszahl.
 * @param max             maximale Größe der ganzen Zufallszahl.
 *
 * @return  Die Gleitkommazufallszahl wird zurückgegeben.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double liefere_gleitkomma_zufallszahl(double min, double max)
{
  if (min > max)
  {
    double ablage = min;
    min = max;
    max = ablage;
  }
  _Bool input_ok = (0 < max) && (max <= RAND_MAX);
  double zufallszahl = input_ok ? (rand() / ((double)(RAND_MAX) + 1)) * (max - min) + min : -1;
	return zufallszahl;
}

/**Die Funktion berechnet die Differenz zwischen zwei Zahlen in Prozent.
 *
 * @param zahl1           die erste Zahl.
 * @param zahl2           die zweite Zahl.
 *
 * @return  Die berechnete Differenz in Prozent.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_differenz_in_prozent (double zahl1, double zahl2)
{
  double differenz = 0.0;

  if (zahl1 >= zahl2)
  {
    differenz = 100 - (zahl2 / zahl1 * 100);
  }
  else
  {
    differenz = 100 - (zahl1 / zahl2 * 100);
  }

  return differenz;
}
