#include "fach.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt */
Fach::Fach()
{
}
/**Erzeugt einen Fach mit Studenten, die sich eingeschrieben haben.
 *
 * @param studenten Die Studenten, die sich eingeschrieben haben.
 * @param bezeichnung_fach Die Bezeichnung der Lehrveranstaltung.
 * @param die_anzahl_sws Die Anzahl der Semester-Leistungspunkte der Lehrveranstaltung.
 */
Fach::Fach(vector<Student*> studenten, const string bezeichnung_fach, int die_anzahl_sws)
{
  cout << "Erstelle Fach <" << bezeichnung_fach << "> mit " << studenten.size() << ". Studenten." << endl;
  teilnehmer.clear();
  teilnehmer.reserve(studenten.size()); // speichere neue Werte
  for (unsigned int i = 0; i < studenten.size(); i++)
    teilnehmer.push_back(new Einschreibung(studenten[i]));
  bezeichnung = bezeichnung_fach;
  sws = die_anzahl_sws;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Fach::~Fach()
{
//  cout << "Lösche Fach <" << bezeichnung << "> mit " << teilnehmer.size() << ". Studenten." << endl;
  for (unsigned int i = 0; i < teilnehmer.size(); i++)
    delete teilnehmer[i];
  teilnehmer.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Fach::Fach(const Fach& original)
{
  for (unsigned int i = 0; i < teilnehmer.size(); i++) // lösche alte Werte
    delete teilnehmer[i];
  teilnehmer.clear();
  teilnehmer.reserve(original.teilnehmer.size()); // speichere neue Werte
  for (unsigned int i = 0; i < original.teilnehmer.size(); i++)
    teilnehmer.push_back(new Einschreibung(*original.teilnehmer[i]));
  bezeichnung = original.bezeichnung;
  sws = original.sws;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_fach  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Fach& Fach::operator=(const Fach& ein_fach)
{
//  cout << "\nDie Anzahl eingeschriebener Studenten " << ein_fach.teilnehmer.size() << endl;
  if (this != &ein_fach) // nur, wenn verschieden
  {
//    cout << "\nKopiere mal studenten... " << endl;
    for (unsigned int i = 0; i < teilnehmer.size(); i++) // lösche alte Werte
      delete teilnehmer[i];
    teilnehmer.clear();
    teilnehmer.reserve(ein_fach.teilnehmer.size()); // speichere neue Werte
    for (unsigned int i = 0; i < ein_fach.teilnehmer.size(); i++)
      teilnehmer.push_back(new Einschreibung(*ein_fach.teilnehmer[i]));
    bezeichnung = ein_fach.bezeichnung;
    sws = ein_fach.sws;
  }
//  cout << "\nDie Anzahl eingeschriebener Studenten  wurde kopiert" << teilnehmer.size() << endl;
  return *this;
}
// Code der Methoden
/**
 * Liefert die Bezeichnung der Lehrveranstaltung.
 * @return Die Bezeichnung der Lehrveranstaltung.
 */
string Fach::liefere_bezeichnung() const
{
  return bezeichnung;
}
/**
 * Liefert die Anzahl der Semester-Leistungspunkte der Lehrveranstaltung.
 * @return Die Anzahl der Semester-Leistungspunkte der Lehrveranstaltung.
 */
int Fach::liefere_sws() const
{
  return sws;
}
/**
 * Liefert die Note fuer diese Lehrveranstaltung des Studenten.
 * @param student Der Student, der sich für diese Lehrveranstaltung sich eingeschrieben und eine Note bekommen hat.
 * @return Die Note fuer diese Lehrveranstaltung des Studenten.
 */
double Fach::liefere_note(Student* student) const
{
  double note = 0.0;
  for (unsigned int i = 0; i < teilnehmer.size(); i++)
  {
    if (teilnehmer[i]->liefere_studenten() == student)
      note = teilnehmer[i]->liefere_note();
  }
  return note;
}
/** Schreibt die Teilnehmerliste der Lehrveranstaltung auf dem Bildschirm. */
void Fach::schreibe_teilnehmerliste()
{
  sortiere_einschreibungen(vergleiche_note_name);
  int breite = 40;
  cout << "Anzahl der Einschreibungen: " << teilnehmer.size() << endl;
  cout << left << setw(breite) << "Name"  << setw(breite / 4) << "Note" << endl;
  for (unsigned int i = 0; i < teilnehmer.size(); i++)
  {
    cout << left << setw(breite) << teilnehmer[i]->liefere_den_namen()
    << setw(breite / 4) << setprecision(1) << fixed << teilnehmer[i]->liefere_note() << endl;
  }
}
/**Sortiert die Einschreibungen nach der Vorschrift die in der Vergleichsfunktion festgelegt wurde.
 *
 * @param funktion  Die Vergleichsfunktion, die bestimmt wie die Einschreibungen sortiert werden.
 */
void Fach::sortiere_einschreibungen(bool (*funktion)(Einschreibung*, Einschreibung*))
{
	sort(teilnehmer.begin(), teilnehmer.end(), funktion);
}
// eventuell Code
// weiterer Funktionen
