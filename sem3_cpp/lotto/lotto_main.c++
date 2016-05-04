#include <iostream>
#include <cstdlib>

#include "eingaben.h"
#include "menue.h"
#include "lottogenerator.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
void program_starten(char **argv);
void schreibe_anleitung();

/**Ein Programm zur Simulation des Lottos 6 aus 49, das Folgendes leistet:
 * <br>
 * Per Zufallszahlengenerator werden n Lottoziehungen (1 <= n <= 70000000) erzeugt und im Hauptspeicher gehalten.<br>
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
 * 
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Gibt 0 fuer richtige ausfuerung und andere Werte fuer abbruch/fehler.
 */
int main(int argc, char **argv)
{
  if (parameter_ok(argc, argv))
  {
    program_starten(argv);
  }
  else
    schreibe_anleitung();
}
/**
 * Prueft die Parameter auf richtigkeit. Es darf nur ein Parameter n ubergeben werden.
 * <br>
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 70000000).
 * <br>
 * <br>Wenn der Parameter beim Aufruf des Programms nicht die gewünschte Gestalt hat (Wertebereich
 * falsch, Parameter falsch, Parameter fehlt, etc.), gibt das Programm einen Hinweis auf die
 * korrekte Benutzung aus.
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Ob die Parameter richtig eingegeben wurden (true) oder nicht (false).
 */
bool parameter_ok(int argc, char *argv[])
{
	bool parameter_ok = false;
	if (argc == 2)
	{
		int anzahl_lottoziehungen = atoi(argv[1]);
    parameter_ok = 2 <= anzahl_lottoziehungen && anzahl_lottoziehungen <= 70000000;
  }
	return parameter_ok;
}
/**
 * Startet das Program ohne Benutzerinteraktionen und nur mit uebergebenen Parameter n.
 * <br>Per Zufallszahlengenerator werden n Lottoziehungen erzeugt.
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 70000000).
 * 
 * @param argv  Die Parameter.
 */
void program_starten(char **argv)
{
  cout << "\n\nDieses Programm erzeugt per Zufallszahlengenerator n Lottoziehungen und haelt diese im Hauptspeicher.\n"
  		"Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,\n"
  		"wobei darauf geachten wird, dass keine Zahlen doppelt vorkommen.\n\n";

	bool antwort = false;
  int anzahl_lottoziehungen = atoi(argv[1]); //6 aus 49	 Möglichkeiten: 70.000.000 ist max. machbar
  //int anzahl_lottozahlen = 6;
  //int min = 1;
  //int max = 49;
  cout << "\nErzeuge " << anzahl_lottoziehungen << " Lottoziehungen...\n" << endl;
  Lottogenerator lottoziehungen(anzahl_lottoziehungen);
	cout << "Lottoziehungen erzeugt.\n" << endl;
	do
	{
		string menuepunkte[13] = {"Information", "Haeufigkeitsverteilung", "Verteilung der Minima", "Verteilung der Maxima",
				"Verteilung der Ziehungslaengen", "Anzahl Ziehungen, die die Laenge enthalten",
				"Anzahl gerade Ziehungen", "Anzahl ungerade Ziehungen", "Verteilung der k-Ziehungen",
				"Tippen", "Automatisch Tippen", "Neue Ziehungen", "Programm beenden"};
    Menue menue(13, menuepunkte);
		switch(menue.waehle_aus_menue())
		{
			case 1:
				lottoziehungen.wieviele_jahre_und_monate();
				break;
			case 2:
				lottoziehungen.statistik_haeufigkeitsverteilung();
				break;
			case 3:
				lottoziehungen.statistik_minima();
				break;
			case 4:
				lottoziehungen.statistik_maxima();
				break;
			case 5:
				lottoziehungen.statistik_laengen();
				break;
			case 6:
				lottoziehungen.statistik_laenge_ist_gezogene_zahl();
				break;
			case 7:
				lottoziehungen.statistik_lottoziehungen_sind_gerade();
				break;
			case 8:
				lottoziehungen.statistik_lottoziehungen_sind_ungerade();
				break;
			case 9:
				lottoziehungen.statistik_lottoziehungen_zahlenpaare();
				break;
			case 10:
				lottoziehungen.lottotipp_eingabe();
				break;
			case 11:
				lottoziehungen.lottotipp_durch_ai();
				break;
			case 12:
        cout << "\nZur Zeit habe ich " << lottoziehungen.liefere_anzahl_lottoziehungen() << " Lottoziehungen.\n";
        if (lottoziehungen.liefere_anzahl_lottoziehungen() < 70000000)
        lottoziehungen.erzeueg_neu_lottoziehungen(
        Eingaben::erfasse_int("Bitte geben Sie ein, wie viel neue Lottoziehungen erzeugt werden sollen: ",
          1, (70000000 - lottoziehungen.liefere_anzahl_lottoziehungen())));
        else
          cout << "Die maximal moegliche Anzahl der Lottoziehungen die ich erzeugen kann ist 70000000." << endl;
				break;
			default:
				cout << "\nDas Programm wird beendet. See You!\n" << endl;
				antwort = true;
				break;
		}
	} while (antwort == false);
}

/**
 * Wenn der Parameter beim Aufruf des Programms nicht die gewünschte Gestalt hat (Wertebereich
 * falsch, Parameter falsch, Parameter fehlt, etc.), gibt das Programm einen Hinweis auf die
 * korrekte Benutzung aus.
 */
void schreibe_anleitung()
{
  cout << "\nDas Program wurde mit falschen oder nicht genuegenden Parameter aufgerufen.\n"
          << "\nAnleitung:\n"
          << "Das Programm muss mit einem Parameter gestartet werden:\n"
          << "\nWird das Programm in der Form\n"
          << "\nlotto n"
          << "\n"
          << "\naufgerufen, werden per Zufallszahlengenerator n Lottoziehungen erzeugt."
          << "\nJede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49, "
          << "wobei keine Zahl doppelt vorkommt. "
          << "Hierbei ist n zwischen 1 und 70000000 Lottoziehungen.\n"
          << "Beispiele:\n"
          << "\nlotto 1000\n";
}