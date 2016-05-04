//Deklarationen
#include <stdio.h>

#include "laengeneinheiten.h"

/**Umrechnung von Millimeter in Inch.
 *
 * @param wert         Wert in Millimetern.
 *
 * @return  Der umgerechnete Wert in Inch.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double umrechnung_mm_in_inch (double wert)
{
  double umrechnungsfaktor = 25.4000508001016;
  wert = wert / umrechnungsfaktor;

  return wert;
}

/**Umrechnung von Kilometern in Landmeilen.
 *
 * @param	strecke					Entfernung/Streckenlänge in Kilometern.
 *
 * @return	Die umgerechnete Strecke/Entfernung in Landmeilen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_km_in_land_mi (double strecke)
{
	const double umrechnungsfaktor = 0.621371;
	double strecke_in_land_mi = strecke * umrechnungsfaktor;

	return strecke_in_land_mi;
}


/**Umrechnung von Landmeilen in Kilometern.
 *
 * @param	strecke					Entfernung/Streckenlänge in Landmeilen.
 *
 * @return	Die umgerechnete Strecke/Entfernung in Kilometern.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_land_mi_in_km (double strecke)
{
	const double umrechnungsfaktor = 1.609344;
	double strecke_in_km = strecke * umrechnungsfaktor;

	return strecke_in_km;
}
