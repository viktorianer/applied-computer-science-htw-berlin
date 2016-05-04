#include <stdio.h>
#include <math.h>

#include "sammelbilderproblem.h"
#include "arrays.h"
#include "zahlensystem.h"
#include "statistik.h"

/**Simuliert einen Einkauf von Sammelbilder bis alle unterschiedliche Bilder gesammelt wurden (Sammelbilderproblem).
 *
 * @param anzahl_kaeufer	                        Die Anzahl der Kaeufer
 * @param anzahl_kaeufe_pro_kunde   \c Input:  \n Das Array, in dem die Anzahl der Kaeufe je Kunde gespeichert werden.\n
 *                                  \c Output: \n Dasselbe Array, in dem die Anzahl der Kaeufe je Kunde gespeichert wurden.\n
 * @param anzahl_unterschiedlicher_bilder        	Die Anzahl der unterschiedlicher Bilder.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void simulier_einkaeufe(int anzahl_kaeufer, int anzahl_kaeufe_pro_kunde[], int anzahl_unterschiedlicher_bilder)
{
	for (int kunde = 0; kunde < anzahl_kaeufer; kunde++)
	{
		anzahl_kaeufe_pro_kunde[kunde] = benoetigten_kaeufe(anzahl_unterschiedlicher_bilder);
	}
}

/**Berechnet (simuliert) die benoetigten Kaeufe um alle Sammelbilder zu bekommen.
 *
 * @param anzahl_unterschiedlicher_bilder        	Die Anzahl der unterschiedlicher Bilder.
 *
 * @return Die Anzahl der benoetigten Kaeufe um alle Sammelbilder zu bekommen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int benoetigten_kaeufe(int anzahl_unterschiedlicher_bilder)
{
	int gefunden[anzahl_unterschiedlicher_bilder];
	int zufallsbild = 0;
	int funde = 0;
	int kaeufe = 0;

	funde = 0;
	initialisiere_int_array(gefunden, anzahl_unterschiedlicher_bilder, -1);
	for (kaeufe = 0; funde < anzahl_unterschiedlicher_bilder; kaeufe++)
	{
		zufallsbild = liefere_ganze_zufallszahl(1, anzahl_unterschiedlicher_bilder) - 1;
		if (zufallsbild != gefunden[zufallsbild])
		{
			gefunden[zufallsbild] = zufallsbild;
			funde = funde + 1;
		}
	}
	return kaeufe;
}

/**Berechnet (simuliert) die Haeufigkeit mit der bestimmten Anzahl unterschiedlicher Bilder
 * bei einer bestimmten Anzahl von Kaeufen vorkommt.
 *
 * @param haeufigkeit_sammelbilder  \c Input:  \n Das Array, in dem die Haeufigkeiten gespeichert werden.\n
 *									                \c Output: \n Dasselbe Array, in dem die Haeufigkeiten gespeichert wurden.\n
 * @param anzahl_kaeufer											Die Anzahl der Kaeufer
 * @param anzahl_unterschiedlicher_bilder     Die Anzahl der unterschiedlicher Bilder.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void simulier_haeufigkeit_sammelbilder(int haeufigkeit_sammelbilder[], int anzahl_kaeufer, int anzahl_unterschiedlicher_bilder)
{
	int funde = 0;
	for (int kunde = 0; kunde < anzahl_kaeufer; kunde++)
	{
	  funde = simuliere_einkauf_bilder(anzahl_unterschiedlicher_bilder);
	  haeufigkeit_sammelbilder[funde] = haeufigkeit_sammelbilder[funde] + 1;
	}
}

/**Simuliert einen Einkauf von Sammelbilder bis zum max-Anzahl der gekaufte Bilder.
 *
 * @param anzahl_gekaufter_bilder		Die max-Anzahl der gekaufte Bilder
 *
 * @return Die Anzahl der unterschiedlicher Sammelbilder bei max-Anzahl der gekaufte Bilder.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int simuliere_einkauf_bilder(int anzahl_gekaufter_bilder)
{
	int gefunden[anzahl_gekaufter_bilder];
	int zufallsbild = 0;
	int funde = 0;
	int kaeufe = 0;

	initialisiere_int_array(gefunden, anzahl_gekaufter_bilder, -1);
	funde = 0;
	for (kaeufe = 0; kaeufe < anzahl_gekaufter_bilder; kaeufe++)
	{
		zufallsbild = liefere_ganze_zufallszahl(1, anzahl_gekaufter_bilder) - 1;
		if (zufallsbild != gefunden[zufallsbild])
		{
			gefunden[zufallsbild] = zufallsbild;
			funde = funde + 1;
		}
	}
	return funde;
}

/**Berechnet die durchschnittlich benoetigten Kaeufe um alle Sammelbilder zu bekommen.
 *
 * @param anzahl_unterschiedlicher_bilder        	Die Anzahl der unterschiedlicher Bilder.
 *
 * @return Die Anzahl der benoetigten Kaeufe um alle Sammelbilder zu bekommen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double durchschnittlich_benoetigten_kaeufe(int anzahl_unterschiedlicher_bilder)
{
	double partialsumme = 0.0;
	for (int i = 1; i < anzahl_unterschiedlicher_bilder; i++)
	{
		partialsumme = (partialsumme + (1.0 / i));
	}
	return partialsumme * anzahl_unterschiedlicher_bilder + 1;
}

/**Gibt die Statistik zum (simulierten) Sammelbilderproblem in der Form einer Tabelle aus.
 * Hierbei ist:
 *
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
 * @param sammelbilder        	Die Anzahl der unterschiedlicher Bilder.
 * @param kunden        				Die Anzahl der Kaeufer.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_statistik_sammelbilderproblem(int sammelbilder, int kunden)
{
  int anzahl_kaeufe_pro_kunde[kunden];
  initialisiere_int_array(anzahl_kaeufe_pro_kunde, kunden, 0);
  initialisiere_zufallszahlengenerator();
  simulier_einkaeufe(kunden, anzahl_kaeufe_pro_kunde, sammelbilder);
  double durchschnitt_versuche = durchschnitt_versuche = durchschnittlich_benoetigten_kaeufe(sammelbilder);
  double abweichung_versuche = 0.0;
  double durchschnitt_kaeufe = 0.0;
  double abweichung_kaeufe[kunden];

  printf("\n%5s %5s %15s %15s %15s %15s\n", "KNR", "KK", "AE", "E", "M", "AM");
  for (int i = 0; i < kunden; i++)
  {
    abweichung_versuche = fabs((double)anzahl_kaeufe_pro_kunde[i] - durchschnitt_versuche);
    durchschnitt_kaeufe = durchschnitt_int_array(anzahl_kaeufe_pro_kunde, i + 1);
    abweichung_kaeufe[i] = fabs(durchschnitt_versuche - durchschnitt_kaeufe);
    printf("\n%7d %5d %15lf %15lf %15lf %15lf",
            i + 1, anzahl_kaeufe_pro_kunde[i], abweichung_versuche, durchschnitt_versuche, durchschnitt_kaeufe, abweichung_kaeufe[i]);
  }
  printf("\n\n");

  double median_kaeufe = median_int_array(anzahl_kaeufe_pro_kunde, kunden);
	double median_am = median_double_array(abweichung_kaeufe, kunden);
	double *min = liefere_min_double_array(abweichung_kaeufe, kunden);
	double *max = liefere_max_double_array(abweichung_kaeufe, kunden);

	printf("%-25s %10lf\n", "Median der Anzahl Kaeufe: ", median_kaeufe);
	printf("%-25s %10lf\n", "Median der Werte AM: ", median_am);
	printf("%-25s %10lf\n", "groesster der Werte AM: ", *max);
	printf("%-25s %10lf\n", "kleinster der Werte AM: ", *min);

	int indizes_array[kunden];
	int anzahl_indizes = 0;
  initialisiere_int_array(indizes_array, kunden, 0);
  for (double i = 1.0; i > 0.6; i = i - 0.2)
  {
  	anzahl_indizes = indizes_kleiner_als_double_array(abweichung_kaeufe, kunden, indizes_array, i);
  	printf("\n%-s %4.1lf :\t", "Indizes der Werte AM < ", i);
		putchar('[');
		schreibe_int_array(indizes_array, anzahl_indizes, 0, ", ", 0);
		putchar(']');
	}
	putchar('\n');
}

/**Gibt die Statistik zum (simulierten) Sammelbilderproblem in der Form einer Tabelle aus.
 *
 * Hierbei ist:
 * <br>AVS die Anzahl verschiedenen Sammelbilder
 * <br>H die Häufigkeit, mit der die Anzahl vorkommt, d.h. die Anzahl Kunden, die genau AVS viele Sammelbilder haben.
 *
 * @param sammelbilder        	Die Anzahl der unterschiedlicher Bilder.
 * @param kunden        				Die Anzahl der Kaeufer.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_statistik_der_treffer(int sammelbilder, int kunden)
{
	int haeufigkeit[sammelbilder];
	initialisiere_int_array(haeufigkeit, sammelbilder, 0);
	simulier_haeufigkeit_sammelbilder(haeufigkeit, kunden, sammelbilder);
	printf("\n%-5s   %5s\n", "AVS", "H");
		for (int i = 0; i < sammelbilder; i++)
		{
			printf("\n%-5d : %5d",
							i + 1, haeufigkeit[i]);
		}
	printf("\n\n");
}
