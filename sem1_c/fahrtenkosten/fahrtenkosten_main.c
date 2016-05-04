//Deklarationen
#include <stdio.h>

#include "verbrauch.h"
#include "zahlensystem.h"
#include "kosten.h"
#include "rauminhalt.h"
#include "waehrungen.h"
#include "laengeneinheiten.h"
#include "interaktionen.h"

//Funktionen

/**Dieses Programm berechnet die Kosten für eine Fahrt, rechnet diese in angloamerikanische Kennzahlen um und
 * gibt Übersicht über die Durchschnitskosten für bestimmte Fahrleistungen pro Jahr.
 *
 * Zuerst muss der Benutzer folgende Fragen benantworten und dazu Angaben machen:
 * Wie viel Kilometer sind Sie mit Ihrem PKW gefahren?
 * Wie viel Liter Benzin haben Sie dabei verbraucht?
 * Wie viel Euro kostet ein Liter Benzin?
 * Wie viel Dollar kostet eine Gallone Benzin in den USA?
 * Was ist der aktuelle Wechselkurs von Euro zu Dollar?
 *
 * Der Benutzer wird zu jeden der Fragen einzeln aufgefordert Eingaben zu machen, die einzel eingelesen werden.
 * Der Benutzer wird, nach einer Fehleingabe, über die Gewünschte Form und gegebenen Falls über die
 * max. und min. Größe der Zahlen informiert.
 *
 * Mit diesen Eingaben werden folgende Daten berechnet:
 * Der Verbrauch in Liter pro Kilometer und die angloamerikanische Kennzahl - gefahrene Meilen pro Gallone.
 * Nun werden die Fahrtkosten in Euro und die Fahrtkosten in US-Dollar berechnet.
 * Das Program rechnet die Fahrtkosten in US-Dollar um in Euro und berechnet die Differenz zu den Kosten in Euro.
 * Nun folgt die Berechnung der Kosten pro km in Deutschland und USA und die Differenz in Prozent.
 *
 * Zum Schluss wird die Berechnung der Werte für eine bestimmte durchschnittliche Fahrleistung durchgeführt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
//Funktion main
int main(void)
{
	printf("\nDieses Programm berechnet die Kosten für eine Fahrt, "
	    "rechnet diese in angloamerikanische Kennzahlen um und\n"
	    "gibt Übersicht über die Durchschnitskosten für bestimmte Fahrleistungen pro Jahr.\n");

	char *ausgabe_text;

  ausgabe_text = "\nWie viel Kilometer sind Sie mit Ihrem PKW gefahren?\t";
  double strecke_in_km = erfasse_gleitkomma_zahl(ausgabe_text, 0, 1000000);
  ausgabe_text = "Wie viel Liter Benzin haben Sie dabei verbraucht?\t";
  double verbrauch_in_l = erfasse_gleitkomma_zahl(ausgabe_text, 0, 100000);

  double wechselkurs_euro_us_dollar = 1.2372;
  ausgabe_text = "Wie viel Euro kostet ein Liter Benzin?\t\t\t";
  double kosten_liter_in_euro = erfasse_gleitkomma_zahl(ausgabe_text, 0, 20);
  ausgabe_text = "\nWie viel Dollar kostet eine Gallone Benzin in den USA?\t";
  double kosten_gallone_in_us_dollar = erfasse_gleitkomma_zahl(ausgabe_text, 0, 20);
  ausgabe_text = "Was ist der aktuelle Wechselkurs von Euro zu Dollar?\t";
  wechselkurs_euro_us_dollar = erfasse_gleitkomma_zahl(ausgabe_text, -100000, 100000);

  printf("\n\nAufgrund Ihrer Eingaben habe ich folgende Daten berechnet:\n");

  double verbrauch_liter_pro_km = berechne_verbrauch_liter_pro_km(strecke_in_km, verbrauch_in_l);
  double durchschnittsverbrauch_l_pro_100km = berechne_durchschnittsverbrauch_l_pro_100km(strecke_in_km, verbrauch_in_l);
  double durchschnittsverbrauch_us_mi_pro_gal = umrechnung_durchschnittsverbrauch(durchschnittsverbrauch_l_pro_100km);
  printf("\nSie haben %.2lf Liter Benzin pro Kilometer verbraucht.", verbrauch_liter_pro_km);
  printf("\nDem entsprechen %.2lf gefahrene Meilen pro Gallone Benzin.", durchschnittsverbrauch_us_mi_pro_gal);

  double kosten_fahrt_in_euro = berechne_kosten_gesamt(verbrauch_in_l, kosten_liter_in_euro);
  double verbrauch_in_us_gal = umrechnung_l_in_us_gal(verbrauch_in_l);
  double kosten_fahrt_in_us_dollar = berechne_kosten_gesamt(verbrauch_in_us_gal, kosten_gallone_in_us_dollar);
  printf("\nBei einem Literpreis von %.2lf Euro hat Sie die Fahrt %.2lf Euro gekostet.\n",
      kosten_liter_in_euro, kosten_fahrt_in_euro);
  printf("\nBeim Preis von %.2lf Dollar pro Gallone haette Sie die Fahrt in den USA %.2lf Dollar gekostet.",
      kosten_gallone_in_us_dollar, kosten_fahrt_in_us_dollar);

  double  wechselkurs_us_dollar_euro = 0.8141;
  double kosten_fahrt_in_euro_usa = umrechnung_us_dollar_in_euro(kosten_fahrt_in_us_dollar, wechselkurs_us_dollar_euro);
  double kosten_differenz = kosten_fahrt_in_euro - kosten_fahrt_in_euro_usa;
  printf("\nBeim Wechselkurs von %.2lf Euro pro Dollar entspricht das %.2lf Euro.",
      wechselkurs_us_dollar_euro, kosten_fahrt_in_euro_usa);
  printf("\nDie Differenz der Kosten fuer die Fahrt in Deutschland und in den USA betraegt somit %.2lf Euro.\n",
      kosten_differenz);

  double kosten_km_ger_in_euro = berechne_kosten_pro_einheit(strecke_in_km, kosten_fahrt_in_euro);
  double kosten_km_usa_in_euro = berechne_kosten_pro_einheit(strecke_in_km, kosten_fahrt_in_euro_usa);
  double kosten_differenz_in_prozent = berechne_differenz_in_prozent(kosten_km_ger_in_euro, kosten_km_usa_in_euro);
  printf("\nEin Kilometer Ihrer Fahrt hat in Deutschland %.2lf Euro gekostet.", kosten_km_ger_in_euro);
  printf("\nEin Kilometer Ihrer Fahrt haette in den USA %.2lf Euro gekostet.\n", kosten_km_usa_in_euro);
  printf("\nIn den USA sind die Kosten fuer die Fahrt somit um %.2lf Prozent geringer.\n", kosten_differenz_in_prozent);

  double jahres_fahrleistung = 15000;
  printf("\nUmgerechnet auf eine durchschnittliche Fahrleistung pro Jahr ergeben sich daraus folgende Werte:\n");
  double jahreskosten_km_ger_euro = berechne_kosten_gesamt(jahres_fahrleistung, kosten_km_ger_in_euro);
  double jahreskosten_km_usa_euro = berechne_kosten_gesamt(jahres_fahrleistung, kosten_km_usa_in_euro);
  double jahreskosten_km_usa_dollar = umrechnung_euro_in_us_dollar(jahreskosten_km_usa_euro, wechselkurs_euro_us_dollar);
  printf("\nGesamtkosten fuer 15000 Kilometer in Deutschland:\t %12.2lf Euro", jahreskosten_km_ger_euro);
  printf("\nGesamtkosten fuer 15000 Kilometer in den USA:\t\t %12.2lf Euro", jahreskosten_km_usa_euro);
  printf("\nGesamtkosten fuer 15000 Kilometer in den USA:\t\t %12.2lf Dollar\n", jahreskosten_km_usa_dollar);

  double strecke_in_us_mi = umrechnung_km_in_land_mi(strecke_in_km);
  double kosten_mi_usa_in_dollar = berechne_kosten_pro_einheit(strecke_in_us_mi, kosten_fahrt_in_us_dollar);
  double jahreskosten_mi_usa_dollar = berechne_kosten_gesamt(jahres_fahrleistung, kosten_mi_usa_in_dollar);
  double jahreskosten_mi_usa_euro = umrechnung_us_dollar_in_euro(jahreskosten_mi_usa_dollar, wechselkurs_us_dollar_euro);
  strecke_in_km = umrechnung_land_mi_in_km(jahres_fahrleistung);
  double jahreskosten_mi_ger_euro = berechne_kosten_gesamt(strecke_in_km, kosten_km_ger_in_euro);
  printf("\nGesamtkosten fuer 15000 Meilen in den USA:\t\t %12.2lf Dollar", jahreskosten_mi_usa_dollar);
  printf("\nGesamtkosten fuer 15000 Meilen in den USA:\t\t %12.2lf Euro", jahreskosten_mi_usa_euro);
  printf("\nGesamtkosten fuer 15000 Meilen in Deutschland:\t\t %12.2lf Euro\n", jahreskosten_mi_ger_euro);
}
