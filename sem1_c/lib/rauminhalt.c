//Deklarationen
#include <stdio.h>

#include "rauminhalt.h"

//Funktionen

/**Umrechnung von Litern in amerikanische Gallone.
 *
 * @param	  liter						übergabe der Liter.
 *
 * @return	Die umgerechnete Anzahl an amerikanischer Gallonen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_l_in_us_gal (double liter)
{
	const double umrechnungsfaktor = 0.264172;
	double us_gal = liter * umrechnungsfaktor;

	return us_gal;

}


/**Umrechnung von amerikanische Gallone in Litern.
 *
 * @param   us_gallone           übergabe der US-Gallone
 *
 * @return  Die umgerechnete Anzahl an Litern.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double umrechnung_us_gal_in_l (double us_gallone)
{
  const double umrechnungsfaktor = 3.785411784;
  double liter = us_gallone * umrechnungsfaktor;

  return liter;

}
