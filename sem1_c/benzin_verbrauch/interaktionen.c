//Deklarationen
#include <stdio.h>

#include "interaktionen.h"


//Funktionen

/**erfasst Anwort des Benutzers
 *
 * @param	wahrheitswert				die positive Antwort
 * @param	unwahrheitswert				die negative Antwort
 *
 * return	eingabe						die erfasste Antwort
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
signed char antwort_ja_oder_nein (signed char wahrheitswert, signed char unwahrheitswert)
{
	signed char eingabe;

	do {
		//Antwort einlesen
		scanf("\n%c", &eingabe);

		//prüfe ob die Anwort gewünschten Format hat
		if (eingabe != wahrheitswert && eingabe != unwahrheitswert) {
			printf("\nBitte eine Antwort in der Form %c oder %c eingeben!\n",
					wahrheitswert, unwahrheitswert);
		} else {

		}

	} while (eingabe != wahrheitswert && eingabe != unwahrheitswert);

	return eingabe;
}
