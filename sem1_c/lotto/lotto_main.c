#include <stdio.h>
#include <stdlib.h>

#include "lotto.h"
#include "interaktionen.h"
#include "arrays.h"
#include "zahlensystem.h"
#include "statistik.h"

/**Ein Programm zur Simulation des Lottos 6 aus 49, das Folgendes leistet:
 * <br>
 * Per Zufallszahlengenerator werden n Lottoziehungen erzeugt und im Hauptspeicher gehalten.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommen.<br>
 * <br>
 * Danach wird folgendes Auswahlmenü angeboten:<br>
 * <br>
 * (1) Information<br>
 * (2) Haeufigkeitsverteilung<br>
 * (3) Verteilung der Minima<br>
 * (4) Verteilung der Maxima<br>
 * (5) Verteilung der Ziehungslaengen<br>
 * (6) Anzahl Ziehungen, die die Laenge enthalten<br>
 * (7) Anzahl gerade Ziehungen<br>
 * (8) Anzahl ungerade Ziehungen<br>
 * (9) Verteilung der k-Ziehungen<br>
 * (10) Tippen<br>
 * (11) Automatisch Tippen<br>
 * (12) Neue Ziehungen<br>
 * (13) Beenden<br>
 * <br>
 * Bei Wahl von (1) wird auf dem Bildschirm ausgegeben, wie viel Jahre und Monate Lottospielens<br>
 * die erzeugten Lottoziehungen entsprechen. Dabei wird der Einfachheit davon ausgegangen,<br>
 * dass jedes Jahr 52 Wochen hat und pro Woche eine Ziehung erfolgt.<br>
 * <br>
 * Bei Wahl von (2) wird eine tabellarische Aufstellung gezeigt, der entnommen werden kann,<br>
 * wie oft jede der Zahlen 1 bis 49 gezogen wurde (Häufigkeitsverteilung). Außerdem werden<br>
 * die beiden Zahlen ausgegeben werden, die am häufigsten bzw. am wenigsten gezogen wurden,<br>
 * sowie die Differenz ihrer Häufigkeiten.<br>
 * <br>
 * Das Minimum einer Lottoziehung ist die kleinste der gezogenen Zahlen. Bei Wahl von (3) wird<br>
 * eine tabellarische Aufstellung gezeigt, in der für jede der Zahlen 1 bis 49 angegeben wird,<br>
 * wie oft sie als Minimum einer der erzeugten Lottoziehungen vorkommt.<br>
 * <br>
 * Eine analoge Aufstellung für die Maxima der erzeugten Lottoziehungen wird bei Wahl von (4) ausgegeben.<br>
 * <br>
 * Unter der Länge einer Lottoziehung wir die Differenz zwischen der größten und der<br>
 * kleinsten gezogenen Zahl verstanden. Bei Wahl von (5) wird eine tabellarische Aufstellung gezeigt,<br>
 * in der für jede der möglichen Längen (5 bis 48) angegeben wird, wie häufig sie<br>
 * unter den erzeugten Lottoziehungen vorkommt (sowohl absolut als auch prozentual).<br>
 * <br>
 * Die Länge einer Ziehung (5 bis 48) kann in der Ziehung selbst als gezogene Zahl auftreten oder<br>
 * nicht. Bei Wahl von (6) wird ausgegeben, bei wie vielen Ziehungen die Länge der Ziehung<br>
 * in der Ziehung vorkommt (sowohl absolut als auch prozentual).<br>
 * <br>
 * Eine Ziehung ist gerade, wenn alle gezogenen Zahlen gerade sind. Wie viele der erzeugten<br>
 * Ziehungen sind gerade (absolut und prozentual) wird bei Wahl von (7) ausgegeben.<br>
 * <br>
 * Analog heißt eine Ziehung ungerade, wenn alle gezogenen Zahlen ungerade sind. Bei Wahl von (8) wird<br>
 * mitgeteilt, wie viele der Ziehungen ungerade sind (absolut und prozentual).<br>
 * <br>
 * Zwei direkt aufeinander folgende ganze Zahlen sind ein Zwilling (zum Beispiel [7, 8]<br>
 * oder [13, 14]), drei direkt aufeinander folgende ganze Zahlen sind Drilling (zum Beispiel [3, 4,5] oder [29, 30, 31]).<br>
 * Allgemein heißt für k >= 1 eine Folge k direkt aufeinander folgender ganzer Zahlen ein k-ling.<br>
 * Eine Lottoziehung heißt eine k-Ziehung, wenn sie einen k-ling enthält, aber keinen (k+1)-ling.<br>
 * Bei Wahl von (9) wird für jeden der möglichen Werte von k (1 bis 6) mitgeteilt,<br>
 * wie viele der Ziehungen eine k-Ziehung sind (absolut und prozentual).<br>
 * <br>
 * Bei Wahl von (10) kann die Benutzerinnen und Benutzer des Programms einen Lottotipp eingeben,<br>
 * wobei sicher gestellt wird, dass keine Zahlen doppelt vorkommen.<br>
 * Dieser Tipp wird mit allen gespeicherten Ziehungen verglichen. Anschließend wird ausgegeben,<br>
 * wie viel Ziehungen in 1, 2, 3, 4, 5 oder 6 Zahlen mit dem Tipp übereinstimmen (absolut und prozentual).<br>
 * <br>
 * Bei Wahl von (11) werden per Zufallszahlengenerator so lange Lottotipps erzeugt und<br>
 * mit den gespeicherten Lottoziehungen verglichen, bis es zu einem "Sechser" kommt,<br>
 * d.h. zu einem Tipp, der mit einer der gespeicherten Lottoziehungen in allen sechs Zahlen übereinstimmt.<br>
 * Es wird ausgegeben, der wievielte Lottotipp der Sechser war.<br>
 * <br>
 * Im Fall von (12) werden m neue Lottoziehungen per Zufallszahlengenerator erzeugt.
 */
int main(void)
{
  printf("\n\nDieses Programm erzeugt per Zufallszahlengenerator n Lottoziehungen und haelt diese im Hauptspeicher.\n"
  		"Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,\n"
  		"wobei darauf geachten wird, dass keine Zahlen doppelt vorkommen.\n\n");

	_Bool antwort = 0;
  int anzahl_lottoziehungen = 100000000; //6 aus 49	 Möglichkeiten: 13.983.816 - 130.000.000 ist max. machbar
  int anzahl_lottozahlen = 6;
  char min = 1;
  char max = 49;
  char **lottoziehungen = NULL;
	int haeufigkeitsverteilung[max];
	int lottozahlen_minima[max];
	int lottozahlen_maxima[max];
	int lottozahlen_laengen[max - anzahl_lottozahlen + 1];
	int lottozahl_gleich_laengen[max - anzahl_lottozahlen + 1];
	int zahlenpaare[anzahl_lottozahlen];
	char lottotipp_eingabe[anzahl_lottozahlen];
	char lottotipp_ai[anzahl_lottozahlen];
	int neue_lottoziehungen = 13983816;

  printf("\nErzeuge %d Lottoziehungen...\n", anzahl_lottoziehungen);
  lottoziehungen = speicher_reservieren_2dim_char_array_malloc(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen);
  initialisiere_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, 0);
  initialisiere_zufallszahlengenerator();
  liefere_lottoziehungen_zufaellig(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, min, max);
	printf("Lottoziehungen erzeugt.\n");
  //schreibe_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, 0, ", ", 0);
  //printf("\n\n");
	do
	{
		char menue[][50] = {"Information", "Haeufigkeitsverteilung", "Verteilung der Minima", "Verteilung der Maxima",
				"Verteilung der Ziehungslaengen", "Anzahl Ziehungen, die die Laenge enthalten",
				"Anzahl gerade Ziehungen", "Anzahl ungerade Ziehungen", "Verteilung der k-Ziehungen",
				"Tippen", "Automatisch Tippen", "Neue Ziehungen", "Programm beenden"};
		switch(waehle_aus_menue(13, 50, menue))
		{
			case 1:
				wieviele_jahre_und_monate(anzahl_lottoziehungen);
				break;
			case 2:
				initialisiere_int_array(haeufigkeitsverteilung, max, 0);
				statistik_haeufigkeitsverteilung(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, haeufigkeitsverteilung, max);
				break;
			case 3:
				initialisiere_int_array(lottozahlen_minima, max, 0);
				statistik_minima(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahlen_minima, max);
				break;
			case 4:
				initialisiere_int_array(lottozahlen_maxima, max, 0);
				statistik_maxima(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahlen_maxima, max);
				break;
			case 5:
				initialisiere_int_array(lottozahlen_laengen, max - 5, 0);
				statistik_laengen_lottoziehungen(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahlen_laengen, max);
				break;
			case 6:
				initialisiere_int_array(lottozahl_gleich_laengen, max - 5, 0);
				statistik_laenge_ist_gezogene_zahl(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahl_gleich_laengen, max);
				break;
			case 7:
				statistik_lottoziehungen_sind_gerade(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen);
				break;
			case 8:
				statistik_lottoziehungen_sind_ungerade(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen);
				break;
			case 9:
				initialisiere_int_array(zahlenpaare, anzahl_lottozahlen, 0);
				statistik_lottoziehungen_zahlenpaare(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, zahlenpaare);
				break;
			case 10:
				initialisiere_char_array(lottotipp_eingabe, anzahl_lottozahlen, 0);
				lottotipp_durch_benutzer(lottotipp_eingabe, anzahl_lottozahlen, min, max);
				statistik_lottotipp_eingabe(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottotipp_eingabe);
				break;
			case 11:
				initialisiere_char_array(lottotipp_ai, anzahl_lottozahlen, 0);
				lottotipp_durch_ai(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottotipp_ai, min, max);
				break;
			case 12:
				printf("\nErzeuge %d neu Lottoziehungen...\n", neue_lottoziehungen);
				lottoziehungen = speicher_neu_reservieren_2dim_char_array_realloc(anzahl_lottoziehungen, neue_lottoziehungen, anzahl_lottozahlen, lottoziehungen);
				liefere_lottoziehungen_zufaellig(neue_lottoziehungen, anzahl_lottozahlen, lottoziehungen + anzahl_lottoziehungen, min, max);
				printf("Lottoziehungen erzeugt.\n");
				anzahl_lottoziehungen = anzahl_lottoziehungen + neue_lottoziehungen;
				//schreibe_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, 0, ", ", 0);
				//printf("\n\n");
				break;
			default:
				speicher_freigeben_2dim_char_array_free(anzahl_lottoziehungen, lottoziehungen);
				puts("\nDas Programm wird beendet. See You!\n");
				antwort = 1;
				break;
		}
	} while (antwort == 0);
}
