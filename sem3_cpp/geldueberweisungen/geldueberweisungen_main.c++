#include "eingaben.h"
#include "geldueberweisungensimulator.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
void program_starten(char **argv);
void schreibe_anleitung();

/**
 * Der einstigespunkt des Programs.
 *
 * <br>Das Programm simuliert Geldüberweisungen wie folgt:
 * <br>
 * <br>Es werden Geldüberweisungen zwischen n Konten simuliert.
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 1000).
 * <br>
 * <br>Wenn der Parameter beim Aufruf des Programms nicht die gewünschte Gestalt hat (Wertebereich
 * falsch, Parameter falsch, Parameter fehlt, etc.), gibt das Programm einen Hinweis auf die
 * korrekte Benutzung aus.
 * <br>
 * <br>Jedes Konto hat (der Einfachheit halber nur) eine eindeutige Kontonummer, die aus sechs Ziffern
 * besteht, einen Kontostand und einen Überziehungskredit, der von Konto zu Konto unterschiedlich
 * sein sollte.
 * <br>
 * <br>Zu Beginn der Simulation werden die n Konten mit zufälligem Kontostand und Überziehungskredit erzeugt.
 * <br>
 * <br>Der Kontostand liegt im Bereich von 0,01 Euro bis 100000,00 Euro.
 * <br>Der Überziehungskredit liegt im Bereich von 100,00 Euro bis 5000,00 Euro.
 * <br>
 * <br>Danach werden die Überweisungen eines Tages wie folgt simuliert.
 * <br>Es finden m Überweisungen statt, wobei m jeweils aus dem Bereich von 7 * n bis 12 * n
 * zufällig gewählt wird. Der Einfachheit halber nehmen wir an, dass die Überweisungen nacheinander erfolgen.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- beide betroffenen Konten gehören zu den n erzeugten Konten
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 * wird (Überziehungskredit berücksichtigen)
 * <br>- der überwiesene Betrag wird vom Startkonto abgebucht und dem Zielkonto gutgeschrieben.
 * <br>
 * <br>Als Ergebnis der Simulation eines Tages werden auf der Konsole folgende Informationen ausgegeben:
 * <br>Tag, Gesamtbestand, hoechster Kontostand, niedrigster Kontostand.
 * <br>Ueberweisungen:  Anzahl, Gesamtvolumen, groesste Ueberweisung, kleinste Ueberweisung, Durchschnitt aller.
 * <br>
 * <br>Danach ist es möglich, einen weiteren Tag zu simulieren oder das Programm zu beenden.
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
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 1000).
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
		int anzahl_konten = atoi(argv[1]);
    parameter_ok = 2 <= anzahl_konten && anzahl_konten <= 1000;
  }
	return parameter_ok;
}
/**
 * Startet das Program ohne Benutzerinteraktionen und nur mit uebergebenen Parameter n.
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 1000).
 * 
 * @param argv  Die Parameter.
 */
void program_starten(char **argv)
{
  int anzahl_konten = atoi(argv[1]);
  cout << "\nDas Program simuliert Geldueberweisungen zwischen " << anzahl_konten
    << " Konten und gibt das Ergebnis aus." << endl;
  Geldueberweisungensimulator ueberweisungssimulator(anzahl_konten);
  string antwort = "j";
  while (antwort.at(0) == 'j')
  {
    ueberweisungssimulator.simuliere_ueberweisungen_fuer_ein_tag();
    antwort = Eingaben::erfasse_antwort("Moechten Sie einen weiteren Tag simulieren?", "jn");
  }
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
          << "\ngeldueberweisungen n"
          << "\n"
          << "\naufgerufen, werden Geldueberweisungen zwischen n Konten simuliert und das Ergebnis ausgegeben.\n"
          << "Hierbei ist n zwischen 2 und 1000 Konten.\n"
          << "Beispiele:\n"
          << "\ngeldueberweisungen 1000\n";
}