//Deklarationen
#include <stdio.h>

#include "berechne_verbrauch_benzin.h"
#include "erfasse_zahlen.h"

//Funktionen

/**Erfasst die Strecke in Kilometer und den erzielter Verbrauch in Liter und rechnet diesen in
 * l/100km um. Danach wird der Durchschnittsverbrauch berechnet und zurückgegeben
 *
 * return	durchschnittsverbrauch				berechneter Durchschnittsverbrauch in l/100km
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float gib_durchschnittsverbrauch_l_pro_100km (void)
{
	float strecke = 0.0;
	float verbrauch = 0.0;

	float durchschnittsverbrauch = 0.0;

	//Strecke die gefahren wurde
	printf("\nWie viel Kilometer sind Sie mit Ihrem PKW gefahren?\t");
	strecke = erfasse_gleitkomma_zahl(0,1000000);
	//Erzielter Verbrauch auf dieser Strecke
	printf("Wie viel Liter Benzin haben Sie dabei verbraucht?\t");
	verbrauch = erfasse_gleitkomma_zahl(0,100000);

	durchschnittsverbrauch = berechne_durchschnittsverbrauch_l_pro_100km(strecke,verbrauch);

	return durchschnittsverbrauch;
}


/**Erfasst die Strecke in Meilen und den erzielter Verbrauch in amerikanischen Gallonen und
 * rechnet diesen in us mi/gal um. Danach wird der Durchschnittsverbrauch berechnet und
 * zurückgegeben
 *
 * return	durchschnittsverbrauch				berechneter Durchschnittsverbrauch in us mi/gal
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float gib_durchschnittsverbrauch_us_mi_pro_gal (void)
{
	float strecke = 0.0;
	float verbrauch = 0.0;

	float durchschnittsverbrauch = 0.0;

	//Strecke die gefahren wurde
	printf("\nWie viel Meilen sind Sie mit Ihrem PKW gefahren?\t");
	strecke = erfasse_gleitkomma_zahl(0,1000000);
	//Erzielter Verbrauch auf dieser Strecke
	printf("Wie viel Gallone Benzin haben Sie dabei verbraucht?\t");
	verbrauch = erfasse_gleitkomma_zahl(0,100000);

	durchschnittsverbrauch = berechne_durchschnittsverbrauch_us_mi_pro_gal(strecke,verbrauch);

	return durchschnittsverbrauch;
}


/**Berechnet den Durchschnittsverbrauch in l/100km.
 * Dabei wird die Strecke in Kilometer und der erzielter Verbrauch in
 * Liter in l/100km umgerechnet.
 *
 * @param	strecke					Strecke die gefahren wurde
 * @param	verbrauch				Erzielter Verbrauch auf dieser Strecke
 *
 * @return	durchschnittsverbrauch	Der berechneter Durchschnittsverbrauch in l/100km.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float berechne_durchschnittsverbrauch_l_pro_100km(float strecke, float verbrauch)
{
	float durchschnittsverbrauch = 0.0;

	durchschnittsverbrauch = verbrauch / (strecke / 100);

	return durchschnittsverbrauch;
}


/**Berechnet den Durchschnittsverbrauch in amerikanischen mi/gal.
 * Dabei wird die Strecke in amerikanischen Meilen und der erzielter Verbrauch in
 * amerikanischen Gallonen in mi/gal umgerechnet.
 *
 * @param	strecke					Strecke die gefahren wurde
 * @param	verbrauch				Erzielter Verbrauch auf dieser Strecke
 *
 * @return	durchschnittsverbrauch	Der berechneter Durchschnittsverbrauch in
 * 									amerikanischen mi/gal.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float berechne_durchschnittsverbrauch_us_mi_pro_gal(float strecke, float verbrauch)
{
	float durchschnittsverbrauch = 0.0;

	durchschnittsverbrauch = strecke / verbrauch;

	return durchschnittsverbrauch;
}


/**Rechnet um von l/100km in amerikanische mi/gal und umgekehrt.
 * Die Funktion benutzt dafür die Konstante mit dem Wert:
 * umrechnungsfaktor=235,2146	//Umrechnungsfaktor km-gal/cl-mi
 *
 * @param	durchschnittsverbrauch	Durchschnittsverbrauch in l/100km oder mi/gal
 *
 * @return	umgerechneter_durchschnittsverbrauch
 * 									umgerechneter Durchschnittsverbrauch
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
float umrechnung_durchschnittsverbrauch(float durchschnittsverbrauch)
{
	//Umrechnungsfaktor cl-mi/km-gal (Konstante)
	const float umrechnungsfaktor = 235.2146;
	float umgerechneter_durchschnittsverbrauch = 0.0;

	umgerechneter_durchschnittsverbrauch = umrechnungsfaktor / durchschnittsverbrauch;

	return umgerechneter_durchschnittsverbrauch;
}
