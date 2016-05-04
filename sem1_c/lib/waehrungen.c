//Deklarationen
#include <stdio.h>

#include "waehrungen.h"

//Funktionen

/**Umrechnung von Euro in US-Dollar.
 *
 * @param	betrag_in_euro					Betrag in Euro.
 * @param	umrechnungsfaktor				Umrechnungsfaktor für die Umrechnung von Euro in US-Dollar.
 *
 * @return	Der Betrag in US-Dollar wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_euro_in_us_dollar (double betrag_in_euro, double umrechnungsfaktor)
{
  double betrag_in_us_dollar = umrechnungsfaktor * betrag_in_euro;

	return betrag_in_us_dollar;
}


/**Umrechnung von US-Dollar in Euro.
 *
 * @param	betrag_in_us_dollar			Betrag in amerikanischen Dollar.
 * @param	umrechnungsfaktor				Umrechnungsfaktor für die Umrechnung von US-Dollar in Euro.
 *
 * @return	Der Betrag in Euro wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_us_dollar_in_euro (double betrag_in_us_dollar, double umrechnungsfaktor)
{
	double betrag_in_euro = umrechnungsfaktor * betrag_in_us_dollar;

	return betrag_in_euro;
}
