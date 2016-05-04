//Deklarationen
#include <stdio.h>

#include "erfasse_zahlen.h"

//Funktionen

/**erfasst ganze Zahl
 *
 * @param	min							minimale Größe der Zahl
 * @param	max							maximale Größe der Zahl
 *
 * return	eingabe						die erfasste ganze Zahl
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int erfasse_ganze_zahl (int min, int max)
{
	int eingabe = 0;

	do {
		//Antwort einlesen
		scanf("\n%i", &eingabe);

		//prüfe ob die Anwort gewünschten Format hat und es sich um eine ganze Zahl handelt
		if (eingabe < min && eingabe > max) {
			printf("\nBitte eine Zahl zwischen %i und %i eingeben!\n",
					min, max);
		} else {

		}

	} while (eingabe < min && eingabe > max);

	return eingabe;
}


/**erfasst gleitkomma Zahl
 *
 * @param	min							minimale Größe der Zahl
 * @param	max							maximale Größe der Zahl
 *
 * return	eingabe						die erfasste gleitkomma Zahl
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float erfasse_gleitkomma_zahl (float min, float max)
{
	float eingabe = 0.0;

	do {
		//Antwort einlesen
		scanf("\n%f", &eingabe);

		//prüfe ob die Anwort gewünschten Format hat und es sich um eine gleitkomma Zahl handelt
		if (eingabe < min && eingabe > max) {
			printf("\nBitte eine Zahl zwischen %f und %f eingeben!\n",
					min, max);
		} else {

		}

	} while (eingabe < min && eingabe > max);

	return eingabe;
}
