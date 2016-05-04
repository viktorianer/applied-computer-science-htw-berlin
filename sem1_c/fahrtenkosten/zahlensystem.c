//Deklarationen
#include <stdio.h>

#include "zahlensystem.h"

//Funktionen

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
