#include "semestersimulator.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt, der Semester mit 80 zufaelligen Studenten simuliert. */
Semestersimulator::Semestersimulator()
{
  initialisiere_studenten(80);
  semester.clear();
}
/**Erzeugt einen Simulator, der Semester mit bestimmter Anzahl an zufaelligen Studenten simuliert.
 * <br>
 * <br>Es ist moglich, mit den n Studierende einen Studienverlauf wie folgt zu simulieren:<br>
 * <br>Für jedes Fach des 1. und 2. Semesters und für jeden Studierenden wird per Zufallszahlengenerator
 * eine (laut Prüfungsordnung zulässige) Prüfungsnote erzeugt.
 * <br>Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * <br>Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).
 *
 * @param anzahl_studenten  Die Anzahl der Studenten, mit denen Semester simuliert werden.
 */
Semestersimulator::Semestersimulator(int anzahl_studenten)
{
  initialisiere_studenten(anzahl_studenten);
  cout << endl << "Simuliere Semester 1: " << endl;
  simuliere_semester("sem1", "Sommersemester 2010");
  cout << endl << "Simuliere Semester 2: " << endl;
  simuliere_semester("sem2", "Wintersemester 2010/2011");
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Semestersimulator::~Semestersimulator()
{
  for (unsigned int i = 0; i < studenten.size(); i++)
    delete studenten[i];
  studenten.clear();
  semester.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Semestersimulator::Semestersimulator(const Semestersimulator& original)
{
  for (unsigned int i = 0; i < studenten.size(); i++)
    delete studenten[i];
  studenten.clear();
  semester.clear();
  studenten.reserve(original.studenten.size());
  for (unsigned int i = 0; i < original.studenten.size(); i++)
    studenten.push_back(original.studenten[i]);
  for (unsigned int i = 0; i < original.semester.size(); i++)
    semester.push_back(original.semester[i]);
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_semestersimulator  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Semestersimulator& Semestersimulator::operator=(const Semestersimulator& ein_semestersimulator)
{
  if (this != &ein_semestersimulator) // nur, wenn verschieden
  {
    for (unsigned int i = 0; i < studenten.size(); i++) // lösche alte Werte
      delete studenten[i];
    studenten.clear();
    semester.clear();
    studenten.reserve(ein_semestersimulator.studenten.size()); // speichere neue Werte
    for (unsigned int i = 0; i < ein_semestersimulator.studenten.size(); i++)
      studenten.push_back(ein_semestersimulator.studenten[i]);
    for (unsigned int i = 0; i < ein_semestersimulator.semester.size(); i++)
      semester.push_back(ein_semestersimulator.semester[i]);
  }
  return *this;
}
// Code der Methoden
/**
 * <br>Es ist moglich, mit den n Studierende einen Studienverlauf wie folgt zu simulieren:<br>
 * <br>Für jedes Fach des 1. und 2. Semesters und für jeden Studierenden wird per Zufallszahlengenerator
 * eine (laut Prüfungsordnung zulässige) Prüfungsnote erzeugt.
 * <br>Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * <br>Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).
 *
 * @param datei_lehrveranstaltungen Der Name der Datei, in der die Lehrveranstaltungen fuer diesen Semester, pro Zeile eine Lehrveranstaltung, gespeichert sind.
 * @param semester_bezeichnung      Die Bezeichnung des Semesters. Zum Beispiel "Wintersemester 2010/2011".
 */
void Semestersimulator::simuliere_semester(const string datei_lehrveranstaltungen, const string semester_bezeichnung)
{
  vector<string> lehrveranstaltungen;
  Dateimanager dateimanager;
  int anzahl_zeilen = dateimanager.lese_dateiinhalt(datei_lehrveranstaltungen);
  lehrveranstaltungen = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Lehrveranstaltung: " << anzahl_zeilen << endl;
  semester.push_back(Semester(lehrveranstaltungen, studenten, semester_bezeichnung));
}
/**Gibt ein Menue aus, mit dem man die Informationen uber die Studenten auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm ausgeben kann.
 * <br>Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * <br>Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).
 * <br>
 * <br>Auf Wunsch ist es moglich, n neue Personen oder n neue Studenten zu erzeugen und sortiert auszugeben.
 */
void Semestersimulator::informationen_zu_studenten()
{
  string menuepunkte[] = { "Studierende",
                           "Semesterbescheinigung...",
                           "Teilnehmerliste einer Lehrveranstaltung...",
													 "Beenden"};
  int anzahl = sizeof(menuepunkte) / sizeof(menuepunkte[0]);
  Menue menue(anzahl, menuepunkte);
	bool antwort = false;
	do
	{
		switch (menue.waehle_aus_menue())
		{
			case 1:
        schreibe_studenteninfos();
				break;
			case 2:
        semesterbescheinigung();
				break;
			case 3:
        schreibe_teilnehmerliste();
				break;
			default:
				cout << "\nDas Programm wird beendet. See You!\n" << endl;
				antwort = true;
				break;
		}
	} while (antwort == false);
}
/**Schreibt Informationen zu den Studenten in der Studentenliste. 
 * <br>Auf Wunsch wird eine ansprechend gestaltete Liste aller Studierenden auf dem Bildschirm ausgegeben,
 * die aufsteigend sortiert ist nach dem Durchschnitt aller Noten des 1. und 2. Semesters (bei gleicher Durchschnittsnote nach dem Namen).*/
void Semestersimulator::schreibe_studenteninfos() const
{
  vector<Einschreibung*> teilnehmer;
  teilnehmer.reserve(studenten.size());
  for (unsigned int i = 0; i < studenten.size(); i++)
  {
    double durchschnittsnote = 0.0;
    for (unsigned int j = 0; j < semester.size(); j++)
      durchschnittsnote += semester[j].liefere_durchschnittsnote(studenten[i]);
    durchschnittsnote =  durchschnittsnote / semester.size();
    teilnehmer.push_back(new Einschreibung(studenten[i], durchschnittsnote));
  }
  sort(teilnehmer.begin(), teilnehmer.end(), vergleiche_note_name);
  int breite = 40;
  cout << endl << "Anzahl der Studenten: " << teilnehmer.size() << endl;
  cout << left << setw(breite) << "Name"  << setw(breite / 4) << "Durchschnittsnote" << endl;
  for (unsigned int i = 0; i < teilnehmer.size(); i++)
  {
    cout << left << setw(breite) << teilnehmer[i]->liefere_den_namen()
    << setw(breite / 4) << setprecision(1) << fixed << teilnehmer[i]->liefere_note() << endl;
  }
}
/**
 * Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 */
void Semestersimulator::semesterbescheinigung() const
{
  string* menuepunkte = new string[studenten.size()];
  for (unsigned int i = 0; i < studenten.size(); i++)
      menuepunkte[i] = studenten[i]->liefere_namen();
  Menue studentenmenue(studenten.size(), menuepunkte);
  int studentenwahl = studentenmenue.waehle_aus_menue();
  delete [] menuepunkte;

  menuepunkte = new string[semester.size()];
  for (unsigned int i = 0; i < semester.size(); i++)
      menuepunkte[i] = semester[i].liefere_bezeichnung();
  Menue semestermenue(semester.size(), menuepunkte);
  int semesterwahl = semestermenue.waehle_aus_menue();
  delete [] menuepunkte;
  menuepunkte = 0;

  schreibe_semesterbescheinigung(studentenwahl - 1, semesterwahl - 1);
}

/**
 * Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * @param student       Der Student, fuer den die Bescheinigung geschrieben werden soll.
 * @param ein_semester  Ein Semester, fuer den die Bescheinigung gilt.
 */
void Semestersimulator::schreibe_semesterbescheinigung(int student, int ein_semester) const
{
  int breite = 40;
  cout << endl << left << "Semesterbescheinigung - "
    << semester[ein_semester].liefere_bezeichnung() << endl;
  cout << endl << setw(breite) << "Name" << setw(breite) << "Fachbereich" << endl;
  cout << setw(breite) << studenten[student]->liefere_namen()
    << setw(breite) << studenten[student]->liefere_fachbereich()<< endl ;
  cout << endl << setw(breite) << "Matrikelnummer" << setw(breite) << "Studiengang" << endl;
  cout << setw(breite) << studenten[student]->liefere_matrikelnummer()
    << setw(breite) << studenten[student]->liefere_studiengang() << endl;
  cout << endl << setw(breite) << "Geburtsdatum" << setw(breite) << "Studienbeginn" << endl;
  cout << setw(breite) << studenten[student]->liefere_geburtstag()
    << setw(breite) << studenten[student]->liefere_immatrikulations_datum() << endl;
  cout << endl << setw(breite) << "Geburtsort" << setw(breite) << "Datum" << endl;
  Datum heute;
  cout << setw(breite) << studenten[student]->liefere_geburtsort()
    << setw(breite) << heute.liefere_standarddatum() << endl;
  semester[ein_semester].schreibe_semesterbescheinigung(studenten[student]);
  cout << endl << "Diese Bescheinigung traegt keine Unterschrift, da sie maschinell erstellt worden ist.\n"
    "Sie ist nicht zur Vorlage bei anderen Hochschulen bestimmt.\n"
    "Eine Leistungsuebersicht ist ggf. bei der Pruefungsverwaltung zu beantragen.\n"
    "Bitte ueberpruefen Sie die Richtigkeit dieser Bescheinigung.\n"
    "Differenzen teilen Sie umgehend Ihrer Bearbeiterin in der Pruefungsverwaltung mit." << endl;
}
/**
 * Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 */
void Semestersimulator::schreibe_teilnehmerliste()
{
  string *menuepunkte = new string[semester.size()];
  for (unsigned int i = 0; i < semester.size(); i++)
      menuepunkte[i] = semester[i].liefere_bezeichnung();
  Menue semestermenue(semester.size(), menuepunkte);
  int semesterwahl = semestermenue.waehle_aus_menue();
  delete [] menuepunkte;
  menuepunkte = 0;
  semester[semesterwahl - 1].schreibe_teilnehmerliste();
}
/**
 * Initialisiert Semestersimulator mit zufaelligen Studenten.
 * @param anzahl_studenten  Die Anzahl der Studenten.
 */
void Semestersimulator::initialisiere_studenten(int anzahl_studenten)
{
  char geschlecht = '\0';
  for (int i = 0; i < anzahl_studenten; i++)
  {
    geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
    studenten.push_back(new Student(liefere_zufalls_student(geschlecht, 1980, 1992)));
  }
}
/**Liefert einen zufaellig erzeugten Student mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 * Der Student ist im Fachbereich 4 im Fach Angewandte Informatik eingeschrieben.
 *
 * @param geschlecht  Das Geschlecht des zufaellig erzeugten Studenten.
 * @param min_jahr    Das min. Geburtstjahr des zufaellig erzeugten Studenten.
 * @param max_jahr    Das max. Geburtstjahr des zufaellig erzeugten Studenten.
 * @return Ein zufaellig erzeugte Student mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 */
Student Semestersimulator::liefere_zufalls_student(const char geschlecht, int min_jahr, int max_jahr) const
{
  return Student(generator.liefere_zufalls_person(geschlecht, min_jahr, max_jahr),
    generator.liefere_zufalls_postanschrift("Deutschland"),
    "FB 4", "Angewandte Informatik", Datum(1, 4, 2010));
}
// eventuell Code
// weiterer Funktionen