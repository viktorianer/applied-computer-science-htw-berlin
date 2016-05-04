//Deklarationen
#include <stdio.h>

#include "verbrauch.h"

//Funktionen

/**Berechnet den Verbrauch in l/km.
 *
 * @param	strecke					Entfernung/Streckenlänge in Kilometer
 * @param	verbrauch				Erzielter Verbrauch in Liter
 *
 * @return	Der berechneter Verbrauch in einer metrischen Einheit l/km.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_verbrauch_liter_pro_km (double strecke, double verbrauch)
{
	double verbrauch_liter_pro_km = verbrauch / strecke;

	return verbrauch_liter_pro_km;
}


/**Berechnet den Durchschnittsverbrauch in l/100km.
 *
 * @param	strecke					Entfernung/Streckenlänge in Kilometer
 * @param	verbrauch				Erzielter Verbrauch in Liter
 *
 * @return	Der berechneter Durchschnittsverbrauch in einer metrischen Einheit l/100km.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_durchschnittsverbrauch_l_pro_100km(double strecke, double verbrauch)
{
	double durchschnittsverbrauch = verbrauch / (strecke / 100);

	return durchschnittsverbrauch;
}


/**Berechnet den Durchschnittsverbrauch in us mi/gal.
 *
 * @param	strecke					Entfernung/Streckenlänge in Meilen.
 * @param	verbrauch				Erzielter Verbrauch in amerikanischen Gallone.
 *
 * @return	Der berechneter Durchschnittsverbrauch in einer angloamerikanischen Einheit us mi/gal.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_durchschnittsverbrauch_us_mi_pro_gal(double strecke, double verbrauch)
{
	double durchschnittsverbrauch = strecke / verbrauch;

	return durchschnittsverbrauch;
}


/**Umrechnung von Durchschnittsverbrauch zwischen den beiden Kennzahlen l/100km und amerikanische mi/gal.
 * Die Umrechnung erfolgt mit einer Formel die in beide Richtungen angewendet wird.
 *
 * Wird ein Wert in l/100km an die Funktion übergeben, berechnet die Funktion den Wert für us mi/gal.
 * Wird ein Wert in us mi/gal an die Funktion übergeben, berechnet die Funktion den Wert für l/100km.
 *
 * @param	durchschnittsverbrauch	Durchschnittsverbrauch in l/100km oder us mi/gal
 *
 * @return	Der umgerechneter Durchschnittsverbrauch in l/100km oder us mi/gal.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double umrechnung_durchschnittsverbrauch(double durchschnittsverbrauch)
{
	//Umrechnungsfaktor cl-mi/km-gal (Konstante)
	const double umrechnungsfaktor = 235.2146;
	double umgerechneter_durchschnittsverbrauch = umrechnungsfaktor / durchschnittsverbrauch;

	return umgerechneter_durchschnittsverbrauch;
}


/**Berechnet Jahresdurchschnittskosten für eine angegebene Fahrleistung.
 *
 * @param	jahres_fahrleistung			Jahresfahrleistung in Einheiten.
 * @param	kosten_pro_einheit			Kosten einer Einheit, angegeben in der gleichen Größe wie Jahresfahrleistung.
 *
 * @return	Die Jahresdurchschnittskosten für gegebene Fahrleistung.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_jahres_durchschnittskosten (double jahres_fahrleistung, double kosten_pro_einheit)
{
  double jahres_durchschnittskosten = jahres_fahrleistung * kosten_pro_einheit;

	return jahres_durchschnittskosten;
}
