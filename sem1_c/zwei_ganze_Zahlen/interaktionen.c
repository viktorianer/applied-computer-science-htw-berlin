//Deklarationen
#include <stdio.h>

#include "interaktionen.h"

/**Erfasst eine Anwort mit einer ganzen Zahl und vergleicht diese mit dem Wertebereich zwischen min und max.
 * Trifft die Eingabe auf keinen der beiden Werte (min, max) zu oder einen Wert dazwischen wird eine Fehlermeldung
 * ausgeben, die noch ein mal den gewünschten Wertebereich, also min-Wert bis max-Wert, anzeigt.
 * Für die Beschreibung der Eingabe muss ein Text übergeben werden der vor der Eingabe ausgegeben wird.
 *
 * @param	ausgabetext			Text für die Frage/Beschreibung der Ausgabe
 * @param	min							minimale Größe der ganzen Zahl die von Benutzer erwartet wird.
 * @param	max							maximale Größe der ganzen Zahl die von Benutzer erwartet wird.
 *
 * @return	Die erfasste Eingabe, ganze Zahl wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int erfasse_ganze_zahl (char *ausgabetext, int min, int max)
{
	int eingabe = 0;
  int funde = 0;

	do {
		printf("%s", ausgabetext);
		funde = scanf("%d%*[^\n]", &eingabe);


		if (funde == 1) {
			if (eingabe < min || eingabe > max) {
				printf("Sie müssen eine ganze Zahl zwischen %d und %d eingeben!\n", min, max);
				funde = 0;
			}
		}
		else {
			scanf("%*[^\n]");
			printf("Sie müssen eine ganze Zahl zwischen %d und %d eingeben!\n", min, max);
			funde = 0;
		}
	} while (funde != 1);

	return eingabe;
}


/**Erfasst eine Anwort mit einer Gleitkommazahl und vergleicht diese mit dem Wertebereich zwischen min und max.
 * Trifft die Eingabe auf keinen der beiden Werte (min, max) zu oder einen Wert dazwischen wird eine Fehlermeldung
 * ausgeben, die noch ein mal den gewünschten Wertebereich, also min-Wert bis max-Wert, anzeigt.
 * Für die Beschreibung der Eingabe muss ein Text übergeben werden der vor der Eingabe ausgegeben wird.
 *
 * @param	ausgabetext			Text für die Frage/Beschreibung der Ausgabe
 * @param	min							minimale Größe der Gleitkommazahl die von Benutzer erwartet wird.
 * @param	max							maximale Größe der Gleitkommazahl die von Benutzer erwartet wird.
 *
 * @return	Die erfasste Eingabe, Gleitkommazahl wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double erfasse_gleitkomma_zahl (char *ausgabetext, double min, double max)
{
	double eingabe = 0;
  int funde = 0;

	do {
		printf("%s", ausgabetext);
		funde = scanf("%lf%*[^\n]", &eingabe);

		if (funde == 1) {
			if (eingabe < min || eingabe > max) {
				printf("Sie müssen eine Gleitkommazahl zwischen %lf und %lf eingeben!\n", min, max);
				funde = 0;
			}
		}
		else {
			scanf("%*[^\n]");
			printf("Sie müssen eine Gleitkommazahl zwischen %lf und %lf eingeben!\n", min, max);
			funde = 0;
		}
	} while (funde != 1);

	return eingabe;
}


/**Erfasst Anwort des Benutzers und vergleicht diese mit den beiden Werten für Wahr und Falsch.
 * Trifft die Eingabe auf keinen der beiden Werte (wahr, falsch) zu wird eine Fehlermeldung
 * ausgeben, die noch ein mal die gewünschten Werte, also für wahr oder falsch, anzeigt.
 * Für die Beschreibung der Eingabe muss ein Text übergeben werden der vor der Eingabe ausgegeben wird.
 *
 * @param	ausgabetext					Text für die Frage/Beschreibung der Ausgabe
 * @param	wahrheitswert				die positive Antwort die von Benutzer erwartet wird.
 * @param	unwahrheitswert			die negative Antwort die von Benutzer erwartet wird.
 *
 * @return	Die erfasste Antwort/Eingabe wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
signed char antwort_ja_oder_nein (char *ausgabetext, char wahrheitswert, char unwahrheitswert)
{
  char eingabe = 0;

	do {
		printf("%s", ausgabetext);
		scanf("%c%*[^\n]", &eingabe);
		if (eingabe != wahrheitswert && eingabe != unwahrheitswert) {
			printf("\nBitte eine Antwort in der Form %c oder %c eingeben!\n",
					wahrheitswert, unwahrheitswert);
		}
	} while (eingabe != wahrheitswert && eingabe != unwahrheitswert);

	return eingabe;
}
