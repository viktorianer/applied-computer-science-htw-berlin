//Deklarationen
#include <stdio.h>

#include "berechne_verbrauch_benzin.h"
#include "erfasse_zahlen.h"
#include "interaktionen.h"

//Funktionen

/**Dieses Programm berechnet den Benzinverbrauch und gibt diesen aus.
 * Dabei wird  berücksichtigt, dass es in amerikanischen Raum üblicher
 * weise Meilen pro Gallone und im z.B. europeischen Raum Liter pro 100
 * Kilometer als Kennzahl bevorzugt wird.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
//Funktion main
int main(void)
{
	//Variablen für die Programmsteuerung
	signed char auswahl_der_eingabeart = 1;
	signed char berechnung_neustarten = 110;

	//Variablen für die Ergebnisse der Berechnung
	float durchschnittsverbrauch_l_pro_100km = 0.0;
	float durchschnittsverbrauch_us_mi_pro_gal = 0.0;

	printf("Dieses Programm berechnet den durchschnitt Benzinverbrauch und gibt diesen aus. "
			"Dabei wird die gefahrene Entfernung (in Kilometer oder amerikanischen Mailen) und "
			"der erzielter Verbrauch (in Liter oder amerikanischen Gallonen) auf dieser Strecke "
			"durch Benutzer eingegebenen.\n");

	//Das Programm soll (wiederholt) so lange benutzt werden können,
	//wie es die Benutzer und Benutzerinnen	wünschen.
	do {
		//Wahl der eingabe Art nach Kennzahlen.
		printf("\nWie möchten Sie die Eingabe tätigen?\n"
				"1) in l/100km\n"
				"2) in mi/gal\n"
				"\nIhre Wahl bitte:");
		auswahl_der_eingabeart = erfasse_ganze_zahl(1,2);

		//eingabeart=1=>l/100km, sonst mi/gal
		if (auswahl_der_eingabeart==1) {
			durchschnittsverbrauch_l_pro_100km = gib_durchschnittsverbrauch_l_pro_100km();
			durchschnittsverbrauch_us_mi_pro_gal =
					umrechnung_durchschnittsverbrauch(durchschnittsverbrauch_l_pro_100km);
		} else {
			durchschnittsverbrauch_us_mi_pro_gal = gib_durchschnittsverbrauch_us_mi_pro_gal();
			durchschnittsverbrauch_l_pro_100km =
					umrechnung_durchschnittsverbrauch(durchschnittsverbrauch_us_mi_pro_gal);
		}

		printf("\nAufgrund Ihrer Eingaben habe ich folgende Daten berechnet:\n");
		printf("\nSie haben %5.2f Liter Benzin pro 100 Kilometer verbraucht.\n",
				durchschnittsverbrauch_l_pro_100km);
		printf("Dem entsprechen %5.2f gefahrene Meilen pro Gallone Benzin.\n",
				durchschnittsverbrauch_us_mi_pro_gal);

		//Wahl einer Neueingabe oder Beenden
		printf("\nMöchten Sie eine neue Berechnung durchführen (j/n)?");
		berechnung_neustarten = antwort_ja_oder_nein(106,110);
	}
	//106 ist der Wert für j und 110 ist der wert für n
	while(berechnung_neustarten == 106);

	printf("\nDanke, dass Sie dieses Tool genutzt haben!\n"
			"Bis zum nächsten mal!\n");
}
