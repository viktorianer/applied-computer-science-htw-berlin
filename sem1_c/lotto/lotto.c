#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "lotto.h"
#include "zahlensystem.h"
#include "arrays.h"
#include "statistik.h"
#include "interaktionen.h"

/**Per Zufallszahlengenerator werden n Lottoziehungen erzeugt.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommen.
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen die erzeugt werden sollen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert werden.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert wurden.\n
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_lottoziehungen_zufaellig(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																			char **lottoziehungen, char min, char max)
{
  for (int lottoziehung = 0; lottoziehung < anzahl_lottoziehungen; lottoziehung++)
  {
  	liefere_lottoziehung_zufaellig(lottoziehungen[lottoziehung], anzahl_lottozahlen, min, max);
  }
}

/**Per Zufallszahlengenerator wird eine Lottoziehung erzeugt.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommen.
 *
 * @param lottoziehung	   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert werden.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert wurden.\n
 * @param anzahl_lottozahlen    Die Anzahl der Zahlen pro Lottoziehung.
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void liefere_lottoziehung_zufaellig(char *lottoziehung, int anzahl_lottozahlen, char min, char max)
{
	_Bool zahl_ungueltig = 0;
  for (int lottozahl = 0; lottozahl < anzahl_lottozahlen; lottozahl++)
  {
  	lottoziehung[lottozahl] = (char)liefere_ganze_zufallszahl((int)min, (int)max);
  	if (lottozahl != 0 && zahl_ungueltig == 0)
  	{
  		zahl_ungueltig = ist_zahl_im_char_array(lottoziehung, lottozahl, lottoziehung[lottozahl]);
  		if (zahl_ungueltig == 1)
  		{
  			lottozahl = lottozahl - 1;
  	  	zahl_ungueltig = 0;
  		}
  	}
  }
}

/**Vergleicht zwei Lottoziehungen auf Uebereinstimmungen.
 *
 * @param lottoziehung_1   			\c Input:  \n Die Adresse, an der die erste Lottoziehung gespeichert ist.\n
 *                							\c Output: \n Die selbe Adresse, an der die erste Lottozahlen gespeichert ist.\n
 * @param lottoziehung_2   			\c Input:  \n Die Adresse, an der die zweite Lottoziehung gespeichert ist.\n
 *                							\c Output: \n Die selbe Adresse, an der die zweite Lottozahlen gespeichert ist.\n
 * @param anzahl_lottozahlen		Die Anzahl der Zahlen pro Lottoziehung.
 *
 * @return Anzahl der Uebereinstimmungen der beiden Lottoziehungen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int vergleiche_lottoziehung(char *lottoziehung_1, char *lottoziehung_2, int anzahl_lottozahlen)
{
	int uebereinstimmungen = 0;
	for (int i = 0; i < anzahl_lottozahlen; i++)
	{
		if (ist_zahl_im_char_array(lottoziehung_1, anzahl_lottozahlen, lottoziehung_2[i]))
		{
			uebereinstimmungen = uebereinstimmungen + 1;
		}
	}
	return uebereinstimmungen;
}

/**Berechnet wie viel Jahre und Monate Lottospielens<br>
 * die erzeugten Lottoziehungen entsprechen. Dabei wird der Einfachheit davon ausgegangen,<br>
 * dass jedes Jahr 52 Wochen hat und pro Woche eine Ziehung erfolgt.<br>
 *
 * @param anzahl_lottoziehungen		Die Anzahl der Lottoziehungen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void wieviele_jahre_und_monate(int anzahl_lottoziehungen)
{
	int jahre = anzahl_lottoziehungen / 52;
	int monate = (anzahl_lottoziehungen % 52) / 4;
	if (monate == 12)
	{
		jahre = jahre + 1;
		monate = 0;
	}
	printf("\nDie erzeugten Lottoziehungen entsprechen in etwa %d Jahre und %d Monate Lottospielens.\n", jahre, monate);
}

/**Erstellt eine tabellarische Aufstellung, der entnommen werden kann,<br>
 * wie oft jede der Zahlen 1 bis max gezogen wurde (Häufigkeitsverteilung). Außerdem werden<br>
 * die beiden Zahlen ausgegeben werden, die am häufigsten bzw. am wenigsten gezogen wurden,<br>
 * sowie die Differenz ihrer Häufigkeiten.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param haeufigkeitsverteilung   			\c Input:  \n Die Adresse, an der die Häufigkeitsverteilung gespeichert wird.\n
 *                											\c Output: \n Die selbe Adresse, an der die Häufigkeitsverteilung gespeichert wurden.\n
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_haeufigkeitsverteilung(int anzahl_lottoziehungen, int anzahl_lottozahlen,
														char **lottoziehungen, int *haeufigkeitsverteilung, char max)
{
	haeufigkeitsverteilung_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, haeufigkeitsverteilung);
	int *min_zahl = liefere_min_int_array(haeufigkeitsverteilung, max);
	int min_haeufigkeit = 0;
	int *max_zahl = liefere_max_int_array(haeufigkeitsverteilung, max);
	int max_haeufigkeit = 0;
	int diffirenz_haeufigkeit = abs((*min_zahl) - (*max_zahl));
	printf("\n%-5s   %5s\n", "Zahl", "Haeufigkeitsverteilung");
	for (int i = 0; i < max; i++)
	{
		printf("\n%-5d : %5d",
						i + 1, haeufigkeitsverteilung[i]);
		if (haeufigkeitsverteilung[i] == *min_zahl)
		{
			min_haeufigkeit = i + 1;
		}
		if (haeufigkeitsverteilung[i] == *max_zahl)
		{
			max_haeufigkeit = i + 1;
		}
	}
	printf("\n\n");
	printf("Die Zahl %d kommt am wenigsten und die Zahl %d am häufigsten vor.\n"
			"Die Differenz der beiden Haeufigkeiten beträgt %d.\n", min_haeufigkeit, max_haeufigkeit, diffirenz_haeufigkeit);
}

/**Das Minimum einer Lottoziehung ist die kleinste der gezogenen Zahlen.<br>
 * Erstellt eine tabellarische Aufstellung, in der für jede der Zahlen 1 bis 49 angegeben wird,<br>
 * wie oft sie als Minimum einer der erzeugten Lottoziehungen vorkommt.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottozahlen_minima   			\c Input:  \n Die Adresse, an der die Häufigkeitsverteilung der Minima gespeichert wird.\n
 *                									\c Output: \n Die selbe Adresse, an der die Häufigkeitsverteilung der Minima gespeichert wurden.\n
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_minima(int anzahl_lottoziehungen, int anzahl_lottozahlen,
											char **lottoziehungen, int *lottozahlen_minima, char max)
{
	haeufigkeitsverteilung_minima_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahlen_minima);
	printf("\n%-5s   %5s\n", "Zahl", "Haeufigkeitsverteilung Minima");
	for (int i = 0; i < max; i++)
	{
		printf("\n%-5d : %10d",
						i + 1, lottozahlen_minima[i]);
	}
	printf("\n\n");
}

/**Das Maximum einer Lottoziehung ist die grosste der gezogenen Zahlen.<br>
 * Erstellt eine tabellarische Aufstellung, in der für jede der Zahlen 1 bis 49 angegeben wird,<br>
 * wie oft sie als Maximum einer der erzeugten Lottoziehungen vorkommt.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottozahlen_maxima   			\c Input:  \n Die Adresse, an der die Häufigkeitsverteilung der Maxima gespeichert wird.\n
 *                									\c Output: \n Die selbe Adresse, an der die Häufigkeitsverteilung der Maxima gespeichert wurden.\n
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_maxima(int anzahl_lottoziehungen, int anzahl_lottozahlen,
											char **lottoziehungen, int *lottozahlen_maxima, char max)
{
	haeufigkeitsverteilung_maxima_2dim_char_array(anzahl_lottoziehungen, anzahl_lottozahlen, lottoziehungen, lottozahlen_maxima);
	printf("\n%-5s   %5s\n", "Zahl", "Haeufigkeitsverteilung Maxima");
	for (int i = 0; i < max; i++)
	{
		printf("\n%-5d : %10d",
						i + 1, lottozahlen_maxima[i]);
	}
	printf("\n\n");
}


/**Unter der Länge einer Lottoziehung wir die Differenz zwischen der größten und der<br>
 * kleinsten gezogenen Zahl verstanden. Gibt die Laenge einer Lottoziehung zurueck.
 *
 * @param lottoziehung   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                						\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param anzahl_lottozahlen  Die Anzahl der Zahlen pro Lottoziehung.
 *
 * @return	Die Laenge einer Lottoziehung.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
char laenge_lottoziehung(char *lottoziehung, int anzahl_lottozahlen)
{
	char laenge = 0;
	char *minima = liefere_min_char_array(lottoziehung, anzahl_lottozahlen);
	char *maxima = liefere_max_char_array(lottoziehung, anzahl_lottozahlen);
	laenge = (char) abs(*minima - *maxima);
	return laenge;
}

/**Unter der Länge einer Lottoziehung wir die Differenz zwischen der größten und der<br>
 * kleinsten gezogenen Zahl verstanden. Erzeugt eine tabellarische Aufstellung,<br>
 * in der für jede der möglichen Längen (5 bis 48) angegeben wird, wie häufig sie<br>
 * unter den erzeugten Lottoziehungen vorkommt (sowohl absolut als auch prozentual).<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottozahlen_laengen  			\c Input:  \n Die Adresse, an der die Laengen gespeichert werden.\n
 *                									\c Output: \n Die selbe Adresse, an der Verteilung der Laengen gespeichert wurden.\n
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_laengen_lottoziehungen(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																			char **lottoziehungen, int *lottozahlen_laengen, char max)
{
	int min_laenge =  (int) anzahl_lottozahlen - 1;
	int max_laenge = (int ) max - 1;
	int laenge = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		laenge = (int) laenge_lottoziehung(lottoziehungen[i], anzahl_lottozahlen);
		lottozahlen_laengen[laenge - min_laenge] = lottozahlen_laengen[laenge - min_laenge] + 1;
	}
	printf("\n%-5s   %5s\n", "Laenge", "Haeufigkeitsverteilung Laengen");
	for (int i = min_laenge; i < max_laenge + 1; i++)
	{
		printf("\n%-5d : %10d \t %2.2lf%%",
						i, lottozahlen_laengen[i - min_laenge], lottozahlen_laengen[i - min_laenge] / (anzahl_lottoziehungen / 100.00));
	}
	printf("\n\n");
}

/**Die Länge einer Ziehung (5 bis 48) kann in der Ziehung selbst als gezogene Zahl auftreten oder<br>
 * nicht. Gibt aus, bei wie vielen Ziehungen die Länge der Ziehung<br>
 * in der Ziehung vorkommt (sowohl absolut als auch prozentual).<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottozahl_gleich_laengen	\c Input:  \n Die Adresse, an der die Haeufigkeitsverteilung Länge der Ziehung
 * 																	die in der Ziehung selbst vorkommt gespeichert werden.\n
 *                									\c Output: \n Die selbe Adresse, an der die Haeufigkeitsverteilung Länge der Ziehung
 *                									die in der Ziehung selbst vorkommt gespeichert wurden.\n
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_laenge_ist_gezogene_zahl(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																				char **lottoziehungen, int *lottozahl_gleich_laengen, char max)
{
	int min_laenge =  (int) anzahl_lottozahlen - 1;
	int max_laenge = (int ) max - 1;
	int laenge = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		laenge = (int) laenge_lottoziehung(lottoziehungen[i], anzahl_lottozahlen);
		lottozahl_gleich_laengen[laenge - min_laenge] = lottozahl_gleich_laengen[laenge - min_laenge] +
				ist_zahl_im_char_array(lottoziehungen[i], anzahl_lottozahlen, (char) laenge);
	}
	printf("\n%-5s   %5s\n", "Laenge", "Haeufigkeitsverteilung Länge der Ziehung die in der Ziehung selbst vorkommt");
	for (int i = min_laenge; i < max_laenge + 1; i++)
	{
		printf("\n%-5d : %10d \t %2.2lf%%",
						i, lottozahl_gleich_laengen[i - min_laenge], lottozahl_gleich_laengen[i - min_laenge] / (anzahl_lottoziehungen / 100.00));
	}
	printf("\n\n");
}

/**Eine Ziehung ist gerade, wenn alle gezogenen Zahlen gerade sind. Wie viele der erzeugten<br>
 * Ziehungen sind gerade (absolut und prozentual) wird mit dieser Funktion ausgegeben.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_lottoziehungen_sind_gerade(int anzahl_lottoziehungen, int anzahl_lottozahlen, char **lottoziehungen)
{
	int anzahl = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		if (sind_alle_zahlen_gerade_char_array(lottoziehungen[i], anzahl_lottozahlen) == 1)
		{
			anzahl = anzahl + 1;
		}
	}
	printf("\n%d (%2.2lf%%) der erzeugten Ziehungen sind gerade.\n", anzahl, anzahl / (anzahl_lottoziehungen / 100.00));
}

/**Eine Ziehung ist ungerade, wenn alle gezogenen Zahlen ungerade sind. Wie viele der erzeugten<br>
 * Ziehungen sind ungerade (absolut und prozentual) wird mit dieser Funktion ausgegeben.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_lottoziehungen_sind_ungerade(int anzahl_lottoziehungen, int anzahl_lottozahlen, char **lottoziehungen)
{
	int anzahl = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		if (sind_alle_zahlen_ungerade_char_array(lottoziehungen[i], anzahl_lottozahlen) == 1)
		{
			anzahl = anzahl + 1;
		}
	}
	printf("\n%d (%2.2lf%%) der erzeugten Ziehungen sind ungerade.\n", anzahl, anzahl / (anzahl_lottoziehungen / 100.00));
}

/**Zwei direkt aufeinander folgende ganze Zahlen sind ein Zwilling (zum Beispiel [7, 8]<br>
 * oder [13, 14]), drei direkt aufeinander folgende ganze Zahlen sind Drilling (zum Beispiel [3, 4,5] oder [29, 30, 31]).<br>
 * Allgemein heißt für k >= 1 eine Folge k direkt aufeinander folgender ganzer Zahlen ein k-ling.<br>
 * Eine Lottoziehung heißt eine k-Ziehung, wenn sie einen k-ling enthält, aber keinen (k+1)-ling.<br>
 * Mit dieser Funktion wird für jeden der möglichen Werte von k (1 bis 6) mitgeteilt,<br>
 * wie viele der Ziehungen eine k-Ziehung sind (absolut und prozentual).<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param zahlenpaare						\c Input:  \n Die Adresse, an der die Haeufigkeitsverteilung Zahlenpaare gespeichert werden.\n
 *                							\c Output: \n Die selbe Adresse, an der die Haeufigkeitsverteilung Zahlenpaare gespeichert wurden.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_lottoziehungen_zahlenpaare(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																					char **lottoziehungen, int *zahlenpaare)
{
	int paar = 0;
	unsigned int anzahl_paare = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
			paar = zahlenpaar(lottoziehungen[i], anzahl_lottozahlen);
			zahlenpaare[paar] = zahlenpaare[paar] + 1;
			if (paar > 0)
				anzahl_paare = anzahl_paare + 1;
			paar = 0;
	}
	printf("\n%2.2f%% der Tippreihen enthalten ein oder mehrere Zahlenpaare.\n\n", anzahl_paare / (anzahl_lottoziehungen / 100.00));
	printf("Zwillinge	%10d\t %2.4f%%.\n", zahlenpaare[1], zahlenpaare[1] / (anzahl_lottoziehungen / 100.00));
	printf("Drillinge	%10d\t %2.4f%%.\n", zahlenpaare[2], zahlenpaare[2] / (anzahl_lottoziehungen / 100.00));
	printf("Vierlinge	%10d\t %2.4f%%.\n", zahlenpaare[3], zahlenpaare[3] / (anzahl_lottoziehungen / 100.00));
	printf("Fuenflinge	%10d\t %2.4f%%.\n", zahlenpaare[4], zahlenpaare[4] / (anzahl_lottoziehungen / 100.00));
	printf("Sechslinge	%10d\t %2.4f%%.\n", zahlenpaare[5], zahlenpaare[5] / (anzahl_lottoziehungen / 100.00));
}

/**Zwei direkt aufeinander folgende ganze Zahlen sind ein Zwilling (zum Beispiel [7, 8]<br>
 * oder [13, 14]), drei direkt aufeinander folgende ganze Zahlen sind Drilling (zum Beispiel [3, 4,5] oder [29, 30, 31]).<br>
 * Allgemein heißt für k >= 1 eine Folge k direkt aufeinander folgender ganzer Zahlen ein k-ling.<br>
 * Eine Lottoziehung heißt eine k-Ziehung, wenn sie einen k-ling enthält, aber keinen (k+1)-ling.<br>
 * Die Funktion sucht in der Lottoziehung nach k-ling und gibt deren Laenge zurueck.
 *
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottoziehung gespeichert ist.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottoziehung gespeichert ist.\n
 * @param anzahl_lottozahlen    Die Anzahl der Zahlen in der Lottoziehung.
 *
 * @return Die Laenge des k-lings.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int zahlenpaar(char *lottoziehungen, int anzahl_lottozahlen)
{
	int zahlenpaar = 0;
	int folge = 0;
	qsort(lottoziehungen, anzahl_lottozahlen, sizeof(char), vergleiche_char);
	for (int i = 0; i < anzahl_lottozahlen; i++)
	{
		if ((lottoziehungen[i] + 1) == lottoziehungen[i + 1])
		{
			folge = folge + 1;
		}
		else
		{
			if (folge > zahlenpaar)
			zahlenpaar = folge;
			folge = 0;
		}
	}
	return zahlenpaar;
}

/**Die Funktion liest durch die Benutzerinnen und Benutzer des Programms eingegebenen Lottotipp ein,<br>
 * wobei sicher gestellt wird, dass keine Zahlen doppelt vorkommen.<br>
 *
 * @param lottotipp_eingabe			\c Input:  \n Die Adresse, an der der Lottotipp gespeichert wurde.\n
 *                							\c Output: \n Die selbe Adresse, an der der Lottotipp gespeichert ist.\n
 * @param anzahl_lottozahlen    Die Anzahl der Zahlen pro Lottoziehung.
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void lottotipp_durch_benutzer(char *lottotipp_eingabe, int anzahl_lottozahlen, char min, char max)
{
	_Bool zahl_ungueltig = 0;
	printf("\nBitte geben Sie die Lottozahlen einzeln ein!\n\n");
	char zahl[][10] = {"erste", "zweite", "dritte", "vierte", "fünfte", "sechste"};
  for (int lottozahl = 0; lottozahl < anzahl_lottozahlen; lottozahl++)
  {
  	printf("Bitte geben Sie ihre ");
  	printf("%s ", zahl[lottozahl]);
  	printf("Lottozahl ein: ");
  	lottotipp_eingabe[lottozahl] = (char)erfasse_ganze_zahl("", (int) min, (int) max);
  	if (lottozahl != 0 && zahl_ungueltig == 0)
  	{
  		zahl_ungueltig = ist_zahl_im_char_array(lottotipp_eingabe, lottozahl, lottotipp_eingabe[lottozahl]);
  		if (zahl_ungueltig == 1)
  		{
  			lottozahl = lottozahl - 1;
  	  	zahl_ungueltig = 0;
  	  	printf("Die Zahl ist schon vorhanden. Bitte eine neue Zahl eingeben.\n");
			}
		}
  }
}

/**Die Funktion vergleicht einen Lottotipp durch Benutzer mit allen gespeicherten Ziehungen. Anschließend wird ausgegeben,<br>
 * wie viel Ziehungen in 1, 2, 3, 4, 5 oder 6 Zahlen mit dem Tipp übereinstimmen (absolut und prozentual).<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottotipp_eingabe			\c Input:  \n Die Adresse, an der der Lottotipp gespeichert wurde.\n
 *                							\c Output: \n Die selbe Adresse, an der der Lottotipp gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void statistik_lottotipp_eingabe(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																	char **lottoziehungen, char *lottotipp_eingabe)
{
	int uebereinstimmungen[anzahl_lottozahlen];
	initialisiere_int_array(uebereinstimmungen, anzahl_lottozahlen, 0);
  for (int lottoziehung = 0; lottoziehung < anzahl_lottoziehungen; lottoziehung++)
  {
  	int uebereinstimmungen_lottotipp = vergleiche_lottoziehung(lottoziehungen[lottoziehung], lottotipp_eingabe, anzahl_lottozahlen);
  	if (uebereinstimmungen_lottotipp != 0)
  		uebereinstimmungen[uebereinstimmungen_lottotipp - 1] = uebereinstimmungen[uebereinstimmungen_lottotipp - 1] + 1;

  }
	printf("\nIch habe folgenden Lottotipp entgegengenommen: [");
	schreibe_char_array(lottotipp_eingabe, anzahl_lottozahlen, 0, ", ", 0);
	printf("]\n");
	printf("\nDer Lottotipp hatte in folgenden Anzahl der Zahlen übereinstimmigkeiten gehabt:\n\n");
	printf("Eine Zahl:	%10d\t %2.3f%%.\n", uebereinstimmungen[0], uebereinstimmungen[0] / (anzahl_lottoziehungen / 100.00));
	printf("Zwei Zahlen:	%10d\t %2.3f%%.\n", uebereinstimmungen[1], uebereinstimmungen[1] / (anzahl_lottoziehungen / 100.00));
	printf("Drei Zahlen:	%10d\t %2.3f%%.\n", uebereinstimmungen[2], uebereinstimmungen[2] / (anzahl_lottoziehungen / 100.00));
	printf("Vier Zahlen:	%10d\t %2.3f%%.\n", uebereinstimmungen[3], uebereinstimmungen[3] / (anzahl_lottoziehungen / 100.00));
	printf("Fünf Zahlen:	%10d\t %2.3f%%.\n", uebereinstimmungen[4], uebereinstimmungen[4] / (anzahl_lottoziehungen / 100.00));
	printf("Sech Zahlen:	%10d\t %2.3f%%.\n", uebereinstimmungen[5], uebereinstimmungen[5] / (anzahl_lottoziehungen / 100.00));
}

/**Die Funktion erzeugt per Zufallszahlengenerator so lange Lottotipps und<br>
 * vergleicht diesen mit den gespeicherten Lottoziehungen, bis es zu einem "Sechser" kommt,<br>
 * d.h. zu einem Tipp, der mit einer der gespeicherten Lottoziehungen in allen sechs Zahlen übereinstimmt.<br>
 * Es wird ausgegeben, der wievielte Lottotipp der Sechser war.<br>
 *
 * @param anzahl_lottoziehungen        	Die Anzahl der Lottoziehungen.
 * @param anzahl_lottozahlen       			Die Anzahl der Zahlen pro Lottoziehung.
 * @param lottoziehungen   			\c Input:  \n Die Adresse, an der die Lottozahlen gespeichert sind.\n
 *                							\c Output: \n Die selbe Adresse, an der die Lottozahlen gespeichert sind.\n
 * @param lottotipp_ai					\c Input:  \n Die Adresse, an der der Lottotipp gespeichert wird.\n
 *                							\c Output: \n Die selbe Adresse, an der der Lottotipp gespeichert wurde.\n
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void lottotipp_durch_ai(int anzahl_lottoziehungen, int anzahl_lottozahlen,
												char **lottoziehungen, char *lottotipp_ai, char min, char max)
{
	unsigned long long tipp;
	int uebereinstimmungen = 0;
	if (uebereinstimmungen != 6)
	{
		liefere_lottoziehung_zufaellig(lottotipp_ai, anzahl_lottozahlen, min, max);
		printf("\nIch habe folgenden Lottotipp zufaellig erzeugt: [");
		schreibe_char_array(lottotipp_ai, anzahl_lottozahlen, 0, ", ", 0);
		printf("]\n");
		for (int lottoziehung = 0; lottoziehung < anzahl_lottoziehungen; lottoziehung++)
		{
			tipp = tipp + 1;
			uebereinstimmungen = vergleiche_lottoziehung(lottoziehungen[lottoziehung], lottotipp_ai, anzahl_lottozahlen);
			if (uebereinstimmungen == 6)
			{
				printf("\nDer %llu. Versuch war der Sechser!\n", tipp);
				lottoziehung = anzahl_lottoziehungen;
			}

		}
	}
}
