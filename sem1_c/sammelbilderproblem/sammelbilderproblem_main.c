#include <stdio.h>

#include "sammelbilderproblem.h"
#include "arrays.h"
#include "interaktionen.h"

/**Das Prorgramm simuliert die folgende Situation wie folgt:
 *
 * <br>Ein Hersteller legt seinem Produkt jeweils ein Sammelbild bei (z.B. das Bild eines Spielers der
 * deutschen Nationalmannschaft bei der Fußball-WM). Dabei ist er fair, d.h. die verschiedenen Sammelbilder
 * werden gleich häufig beigelegt.
 *
 * <br>Es gibt s verschiedene Sammelbilder. Folgende Fragestellungen drängen sich auf:
 *
 * <br>1. Wie viele Exemplare des Produkts muß ein Kunde kaufen, bis er über eine vollständige Kollektion
 * aller Sammelbilder verfügt? (Sammelbilderproblem)
 *
 * <br>2. Eine Anzahl von k Kunden kaufen jeweils genau s Exemplare des Produktes. Wie viele
 * verschiedene Sammelbilder wird jeder dieser Kunden haben?
 *
 * <br>Für die erste Fragestellung wird eine Statistik zum Sammelbilderproblem erstellt und in einer Tabelle ausgeben.
 *
 * <br>Hierbei ist:
 * <br>KNR die laufende Nummer der Kunden
 * <br>KK die Anzahl Käufe des Kunden, die nötig waren, um eine vollständige Kollektion der Sammelbilder zu erhalten
 * <br>AE die Abweichung vom Erwartungswert, d.h. der Betrag der Differenz der Werte KK und E
 * <br>E der Erwartungswert, der in diesem Fall n * Hn ist, wobei Hn die n-te harmonische Zahl ist, d.h. Hn =
 * <br>1 + 1/2 + 1/3 + … + 1/n ; (siehe z.B. Wikipedia)
 * <br>M das arithmetische Mittel der Anzahl Käufe der Kunden 1, 2, … , aktueller Kunde
 * <br>AM die Abweichung des Mittelwerts der Käufe vom Erwartungswert, d.h. der Betrag der Differenz der Werte M und E.
 *
 * <br>Zusätzlich werden die Indizes der Werte AM < x für x = 1.0, 0.8, 0.6, 0.4, 0.2 ausgegeben,
 * aber nur dann, wenn es derartige Indizes gibt.
 *
 * <br>Für die zweite Fragestellung wird eine Statistik ausgeben.
 *
 * <br>Hierbei ist:
 * <br>AVS die Anzahl verschiedenen Sammelbilder
 * <br>H die Häufigkeit, mit der die Anzahl vorkommt, d.h. die Anzahl Kunden, die genau AVS viele Sammelbilder haben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  printf("\nDas Prorgramm simuliert die folgende Situation wie folgt:\n");

  printf("\nEin Hersteller legt seinem Produkt jeweils ein Sammelbild bei (z.B. das Bild eines Spielers der\n"
  		"deutschen Nationalmannschaft bei der Fußball-WM). Dabei ist er fair, d.h. die verschiedenen Sammelbilder\n"
  		"werden gleich häufig beigelegt.\n\n"
  		"Es gibt s verschiedene Sammelbilder. Folgende Fragestellungen drängen sich auf:\n\n"

  		"1. Wie viele Exemplare des Produkts muß ein Kunde kaufen, bis er über eine vollständige Kollektion\n"
  		"aller Sammelbilder verfügt? (Sammelbilderproblem)\n\n"
  		"2. Eine Anzahl von k Kunden kaufen jeweils genau s Exemplare des Produktes. Wie viele\n"
  		"verschiedene Sammelbilder wird jeder dieser Kunden haben?\n\n");

  char *ausgabetext = "";
  int sammelbilder = 0;
  int kunden = 0;

  char menue[][30] = {"Sammelbilderproblem", "Statistik der Treffer", "Programm beenden"};
  switch(waehle_aus_menue(3, 30, menue))
  {
    case 1:
      puts("\n\nEs soll ein Sammelbilderproblem-Statistik erzeugt werden:\n");
      ausgabetext = "Wie viele verschiedene Sammelbilder gibt es [1 – 1000] ?\t";
      sammelbilder = erfasse_ganze_zahl(ausgabetext, 1, 1000);
      ausgabetext = "Wie viele Kunden kaufen [1 – 100000] ?\t";
      kunden = erfasse_ganze_zahl(ausgabetext, 1, 100000);

      schreibe_statistik_sammelbilderproblem(sammelbilder, kunden);
    	break;
    case 2:
    	puts("\n\nEs soll die Häufigkeit, mit der die Anzahl vorkommt, "
    			"d.h. die Anzahl Kunden, die genau AVS viele Sammelbilder haben, ausgegeben werden.\n");
    	ausgabetext = "Wie viele verschiedene Sammelbilder gibt es [1 – 1000] ?\t";
    	sammelbilder = erfasse_ganze_zahl(ausgabetext, 1, 1000);
    	ausgabetext = "Wie viele Kunden kaufen genau 23 Sammelbilder [1 – 100000] ?\t";
    	kunden = erfasse_ganze_zahl(ausgabetext, 1, 100000);

    	schreibe_statistik_der_treffer(sammelbilder, kunden);
      break;
    default:
      puts("\nDas Programm wird beendet. See You!\n");
      break;
  }
}
