//Deklarationen
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "zahlensystem.h"


/**Die Funktion berechnet die Differenz zwischen einer kleineren und größeren Zahl in Prozent.
 * Dabei ist es egal ob zu erst die größere oder die kleinere Zahl übergeben wird.
 * Die beiden übergebenen Zahlen werden zu erst verglichen und die Zahl mit dem höchsten Wert zu ermitteln um
 * die Berechnung durchzuführen.
 *
 * @param	zahl1						die erste Zahl.
 * @param	zahl2						die zweite Zahl.
 *
 * @return	Die berechnete Differenz zwischen einer kleineren und größeren Zahl in Prozent.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_differenz_in_prozent (double zahl1, double zahl2)
{
	double differenz = 0.0;

	if (zahl1 >= zahl2) {
		differenz = 100 - (zahl2 / zahl1 * 100);
	} else {
		differenz = 100 - (zahl1 / zahl2 * 100);
	}

	return differenz;
}


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
  return (rand() % (max - min + 1)) + min;
}
