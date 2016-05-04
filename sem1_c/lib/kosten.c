//Deklarationen
#include <stdio.h>

#include "kosten.h"

//Funktionen

/**Berechnet aus den Gesamtkosten und Gesamtmenge einer Sache die Kosten pro Einheit.
 *
 * @param	gesamtmenge					der Wert für eine Menge, z.B. 200 Äpfel.
 * @param	gesamtkosten				die Gesamtkosten für eine Menge, z.B. 100 Euro für 200 Äpfel.
 *
 * @return	Die Kosten pro Einheit, also z.B. 0.50 Euro pro Apfel.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_kosten_pro_einheit (double gesamtmenge, double gesamtkosten)
{
	double kosten_pro_einheit = gesamtkosten / gesamtmenge;

	return kosten_pro_einheit;
}

/**Berechnet aus dem Wert für Gesamtmenge einer bestimmten Sache und die Kosten pro Einheit dieser Menge
 * die Gesamtkosten.
 *
 * @param	gesamtmenge   					der Wert für eine Menge, z.B. 200 Äpfel.
 * @param	kosten_pro_einheit			die Kosten pro Einheit, z.B. 0.50 Euro pro Apfel
 *
 * @return	Die Gesamtkosten für eine Menge, also z.B. 100 Euro für 200 Äpfel.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_kosten_gesamt (double gesamtmenge, double kosten_pro_einheit)
{
  double gesamtkosten = gesamtmenge * kosten_pro_einheit;

	return gesamtkosten;
}
