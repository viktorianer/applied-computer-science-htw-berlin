//Deklarationen
#include <stdio.h>
#include <math.h>

#include "mathe.h"

/**Die Funktion berechnet dem Durchmesser eines Kreises.
 *
 * @param radius           Radius des Kreises.
 *
 * @return  Der berechnete Durchmesser des Kreises.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_durchmesser_kreis (double radius)
{
  double durchmesser = radius * 2;

  return durchmesser;
}

/**Die Funktion berechnet dem Umfang eines Kreises anhand des Durchmessers.
 *
 * @param durchmesser      Durchmesser des Kreises.
 *
 * @return  Der berechnete Umfang des Kreises.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_umfang_kreis_mit_durchmesser (double durchmesser)
{
  const double pi = 3.141592654;
  double umfang = durchmesser * pi;

  return umfang;
}

/**Die Funktion berechnet die Oberfläche einer Kugel anhand des Durchmessers.
 *
 * @param durchmesser      Durchmesser der Kugel.
 *
 * @return  Die berechnete Oberfläche der Kugel.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_oberflaeche_kugel_mit_durchmesser (double durchmesser)
{
  const double pi = 3.141592654;
  double oberflaeche = pow(durchmesser, 2) * pi;

  return oberflaeche;
}

/**Die Funktion berechnet das Volumen einer Kugel anhand des Durchmessers.
 *
 * @param durchmesser      Durchmesser der Kugel.
 *
 * @return  Der berechnete Volumen der Kugel.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_volumen_kugel_mit_durchmesser (double durchmesser)
{
  const double pi = 3.141592654;
  double volumen = ((double)1 / 6 * pi) * pow(durchmesser, 3);

  return volumen;
}

/**Die Funktion berechnet die Differenz zwischen zwei Zahlen in Prozent.
 *
 * @param	zahl1						die erste Zahl.
 * @param	zahl2						die zweite Zahl.
 *
 * @return	Die berechnete Differenz in Prozent.
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
