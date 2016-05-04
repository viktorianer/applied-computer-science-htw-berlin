#include <iostream>
#include <string>
#include <vector>

#include "person.h"
#include "utilities.h"
#include "personengenerator.h"
#include "semestersimulator.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
bool vergleiche_parameter_studenten(const string der_parameter);
bool vergleiche_parameter_simulator(const string der_parameter);
void program_starten(char **argv);
void schreibe_anleitung();
void erzeuge_personen_beispiel(int anzahl);
void schreibe_name_vornamen_geburtstag(const Person& person);
void schreibe_namen_und_geburtstag(const Person& person);

/**Ein Programm zur Verwaltung von Daten über die Beschäftigten und Studierenden einer Fachhochschule. Die Daten werden zufaellig aus mehreren Dateien generiert.<br>
 * <br>
 * Für jede Person sind folgende Daten vorhanden:<br>
 * <br>Vorname(n)
 * <br>Nachname (aktueller, Geburtsname)
 * <br>Ein Kennzeichen für das Geschlecht (m, w)
 * <br>Geburtsdatum (TT, MM, JJJJ)
 * <br>Geburtsort (Ort, Land)
 * <br>Nationalitaet
 * <br>Wohnanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>private Telefonnummer(n) (Vorwahl, Anschluss)
 * <br>
 * <br>Für Studierende sind zusaetzlich folgende Daten vorhanden:<br>
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Matrikelnummer
 * <br>Datum der Immatrikulation (TT, MM, JJJJ)
 * <br>Heimatanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>E-Mail-Adresse(n)
 * <br>
 * <br>Fuerr Beschäftigte sind zusaetzlich folgende Daten vorhanden:<br>
 * <br>Ort des Dienstzimmers (Gebäude, Raum)
 * <br>dienstliche Telefonnummer (Vorwahl, Anschluss)
 * <br>Fax-Nummer
 * <br>E-Mail-Adresse(n)
 * <br>Funktion (Schreibkraft, Verwaltungsangestellte(r), Laboringenieur(in), Professor(in))
 * <br>
 * <br>Fuer Professoren sind zusaetzlich folgende Daten vorhanden:
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Sprechstunde (Wochentag, Uhrzeit)
 * <br>
 * <br>Auf Wunsch werden n Personen (gemischt Studierende, Beschaftigte, Professoren) per Zufallszahlengenerator erzeugt, wobei n gewahlt werden kann (1 <= n <= 1000).
 * <br>Es ist moglich, die Informationen uber die Personen auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm auszugeben.
 * <br>Es werden mehrere Arten der Sortierung angeboten:<br>
 * <br>alphabetische Sortierung nach Nachnamen, bei gleichem Nachnamen nach Vornamen, bei gleichem Vornamen nach Geburtsdatum
 * <br>nach dem Geburtsdatum, bei gleichem Geburtsdatum nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen
 * <br>nach dem Jahrgang (Geburtsjahr), bei gleichem Jahrgang nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Es ist auch moglich, nur n Studierende zu erzeugen (1 <= n <= 500). Diese mussen dann zusatzlich auch so sortiert und ausgegeben werden konnen:
 * <br>nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Es ist auch moglich, mit den n Studierende einen Studienverlauf wie folgt zu simulieren:<br>
 * <br>Für jedes Fach des 1. und 2. Semesters und für jeden Studierenden wird per Zufallszahlengenerator
 * eine (laut Prüfungsordnung zulässige) Prüfungsnote erzeugt.
 * <br>Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * <br>Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).
 * <br>
 * <br>Auf Wunsch ist es moglich, n neue Personen oder n neue Studenten zu erzeugen und sortiert auszugeben.
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
 * Prueft die Parameter auf richtigkeit. Es darf nur ein oder zwei Parameter (n, -sim n oder -s n) ubergeben werden.
 * <br>
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 1000).
 * <br>Der Parameter -s gibt an, dass die erzeugten Personen nur Studenten sein duerfen.
 * Im diesem Falle ist n die Anzahl der Studenten (1 <= n <= 1000).
 * <br>Der Parameter -sim gibt an, dass man mit den n Studierende einen Studienverlauf simulieren will.
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
  if (argc == 3)
	{
    int anzahl_personen = atoi(argv[2]);
    if (vergleiche_parameter_studenten(argv[1]))
      parameter_ok = (1 <= anzahl_personen && anzahl_personen <= 500);
    else
      parameter_ok = vergleiche_parameter_simulator(argv[1]) && (1 <= anzahl_personen && anzahl_personen <= 500);
  }
  else if (argc == 2)
	{
		int anzahl_personen = atoi(argv[1]);
    parameter_ok = 1 <= anzahl_personen && anzahl_personen <= 1000;
  }
	return parameter_ok;
}
/**Prueft die Eingabe auf richtigen Parameter (-s) fuer die erzeugen von (nur) Studenten.
 * @param der_parameter  Der Parameter, der ueberprueft werden soll.
 * @return Liefert true wenn der Parameter i.O. ist und false wenn nicht.
 */
bool vergleiche_parameter_studenten(const string der_parameter)
{
  return (!(der_parameter.compare("-s")));
}
/**Prueft die Eingabe auf richtigen Parameter (-sim) fuer die erzeugen von (nur) Studenten und simulieren des Studienverlaufs.
 * @param der_parameter  Der Parameter, der ueberprueft werden soll.
 * @return Liefert true wenn der Parameter i.O. ist und false wenn nicht.
 */
bool vergleiche_parameter_simulator(const string der_parameter)
{
  return (!(der_parameter.compare("-sim")));
}
/**Startet das Program mit n zufaelligen Personen oder mit n zufaelligen Studenten (-s).<br>
 * <br>
 * <br>Auf Wunsch werden n Personen (gemischt Studierende, Beschaftigte, Professoren) per Zufallszahlengenerator erzeugt, wobei n gewahlt werden kann (1 <= n <= 1000).
 * <br>Es ist moglich, die Informationen uber die Personen auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm auszugeben.
 * <br>Es werden mehrere Arten der Sortierung angeboten:<br>
 * <br>alphabetische Sortierung nach Nachnamen, bei gleichem Nachnamen nach Vornamen, bei gleichem Vornamen nach Geburtsdatum
 * <br>nach dem Geburtsdatum, bei gleichem Geburtsdatum nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen
 * <br>nach dem Jahrgang (Geburtsjahr), bei gleichem Jahrgang nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Es ist auch moglich, nur n Studierende zu erzeugen (1 <= n <= 500). Diese mussen dann zusatzlich auch so sortiert und ausgegeben werden konnen:
 * <br>nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Es ist auch moglich, mit den n Studierende einen Studienverlauf wie folgt zu simulieren:<br>
 * <br>Für jedes Fach des 1. und 2. Semesters und für jeden Studierenden wird per Zufallszahlengenerator
 * eine (laut Prüfungsordnung zulässige) Prüfungsnote erzeugt.
 * <br>Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * <br>Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).
 * <br>
 * <br>Auf Wunsch ist es moglich, n neue Personen oder n neue Studenten zu erzeugen und sortiert auszugeben.
 *
 * @param argv  Die Parameter.
 */
void program_starten(char **argv)
{
  cout << "\n\nDieses Programm erzeugt zufaellig Personen.\n\n";
  string der_parameter = argv[1];
  if (der_parameter == "-s")
  {
    Personengenerator generator;
    generator.erzeuge_zufalls_studenten(atoi(argv[2]));
    generator.informationen_zu_studenten();
    //generator.schreibe_personeninfos();
  }
  else if (der_parameter == "-sim")
  {
    Semestersimulator generator(atoi(argv[2]));
    generator.informationen_zu_studenten();
  }
  else
  {
    Personengenerator generator;
    generator.erzeuge_zufalls_personen(atoi(argv[1]));
    generator.informationen_zu_personen();
    //generator.schreibe_personeninfos();
    //erzeuge_personen_beispiel(atoi(argv[1]));
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
          << "\nDas Program kann mit n zufaelligen Personen oder mit n zufaelligen Studenten gestartet werden.\n"
          << "\nWird als erster Uebergabeparameter -s angegeben, startet das Program mit n zufaelligen Studenten."
          << "\nWird Parameter nur mit n angegeben, startet das Program mit n zufaelligen Personen.\n";
}
/**Erzeugt ein Beispiel mit zufaelligen Personen und gibt diese unterschiedlich sortiert aus.
 *
 * @param anzahl  Die Anzahl der Personen, die erzeugt werden soll.
 */
void erzeuge_personen_beispiel(int anzahl)
{
  Person* menschen = liefere_array<Person>(anzahl);
  Personengenerator pers_generator;
  char geschlecht = '\0';
  for (int i = 0; i < anzahl; i++)
  {
    geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
    menschen[i] = pers_generator.liefere_zufalls_student(geschlecht, 1982, 1990);
  }

  cout << "\nunsortiert:\n\n";
  for (int i = 0; i < anzahl; i++)
  {
    schreibe_namen_und_geburtstag(menschen[i]);
    cout << endl;
  }

  selection_sort(menschen, anzahl, vergleiche_personen);
  cout << "\nalphabetisch sortiert:\n\n";
  for (int i = 0; i < anzahl; i++)
  {
    schreibe_name_vornamen_geburtstag(menschen[i]);
    cout << endl;
  }

  selection_sort(menschen, anzahl, vergleiche_nach_alter);
  cout << "\nnach Alter sortiert:\n\n";
  for (int i = 0; i < anzahl; i++)
  {
    schreibe_namen_und_geburtstag(menschen[i]);
    cout << endl;
  }
  selection_sort(menschen, anzahl, vergleiche_nach_jahrgang);
  cout << "\nnach Jahrgang sortiert:\n\n";
  for (int i = 0; i < anzahl; i++)
  {
    schreibe_namen_und_geburtstag(menschen[i]);
    cout << endl;
  }
}
/**Schreibt Informationen zur Person (Name, Vorname und Geburtstag)
 *
 * @param person  Die Person, zu der Informationen ausgegeben werden sollen.
 */
void schreibe_namen_und_geburtstag(const Person& person)
{
  cout << setw(30) << left;
  cout << person.liefere_namen();
  cout << setw(12) << right;
  cout << person.liefere_geburtstag();
}
/**Schreibt Informationen zur Person (Name (groß geschrieben), Vorname und Geburtstag)
 *
 * @param person  Die Person, zu der Informationen ausgegeben werden sollen.
 */
void schreibe_name_vornamen_geburtstag(const Person& person)
{
  string nachname = person.liefere_nachnamen();
  ostringstream wandler(ios::out);
  for (int i = 0; nachname.c_str()[i]; i++)
    wandler << static_cast<char>(toupper(nachname.c_str()[i]));
  cout << setw(30) << left;
  cout << wandler.str() + ", " +
          person.liefere_vornamen();
  cout << setw(12) << right;
  cout << person.liefere_geburtstag();
}