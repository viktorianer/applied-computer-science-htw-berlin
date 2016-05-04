#include "semester.h"
#include "student.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt */
Semester::Semester()
{
}
/**
 * Erzeugt einen Semester mit bestimmten Lehrvernstaltungen, Studenten und einer Semesterbezeichnung.
 * @param die_lehrveranstaltungen Die Lehrveranstaltungen, die in diesem Semester angeboten werden.
 * @param studenten               Die Studenten, die sich fuer die Lehrveranstaltungen in diesem Semester einschreiben wollen.
 * @param semester_bezeichnung  Die Bezeichnung des Semesters. Zum Beispiel "Wintersemester 2010/2011".
 */
Semester::Semester(const vector<string> die_lehrveranstaltungen, vector<Student*> studenten, const string semester_bezeichnung)
{
  lehrveranstaltungen.clear(); // lösche alte Werte
  lehrveranstaltungen.reserve(die_lehrveranstaltungen.size()); // speichere neue Werte
  for (unsigned int i = 0; i < die_lehrveranstaltungen.size(); i++)
    lehrveranstaltungen.push_back(Fach(studenten, die_lehrveranstaltungen[i],
      Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(4, 5)));
  bezeichnung = semester_bezeichnung;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Semester::~Semester()
{
  lehrveranstaltungen.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Semester::Semester(const Semester& original)
{
  lehrveranstaltungen.clear(); // lösche alte Werte
  lehrveranstaltungen.reserve(original.lehrveranstaltungen.size()); // speichere neue Werte
  for (unsigned int i = 0; i < original.lehrveranstaltungen.size(); i++)
    lehrveranstaltungen.push_back(original.lehrveranstaltungen[i]);
  bezeichnung = original.bezeichnung;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_semester  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Semester& Semester::operator=(const Semester& ein_semester)
{
  if (this != &ein_semester) // nur, wenn verschieden
  {
    lehrveranstaltungen.clear(); // lösche alte Werte
    lehrveranstaltungen.reserve(ein_semester.lehrveranstaltungen.size()); // speichere neue Werte
    for (unsigned int i = 0; i < ein_semester.lehrveranstaltungen.size(); i++)
      lehrveranstaltungen.push_back(ein_semester.lehrveranstaltungen[i]);
    bezeichnung = ein_semester.bezeichnung;
  }
  return *this;
}
// Code der Methoden
/**
 * Liefert die Bezichnung der Lehrveranstaltungen.
 * @return Die Bezichnung der Lehrveranstaltungen.
 */
string Semester::liefere_bezeichnung() const
{
  return bezeichnung;
}
/**
 * Für jeden Studierenden wird auf Wunsch eine ansprechend gestaltete Semesterbescheinigung auf dem Bildschirm ausgegeben,
 * die alle Daten des Studierenden enthält (Fachbereich, Studiengang, Matrikelnummer, Anschrift, etc.) sowie für jedes Fach des 1. und 2. Semesters die Note.
 * @param student Der Student, fuer dem eine Semesterbescheinigung geschrieben wird.
 */
void Semester::schreibe_semesterbescheinigung(Student* student) const
{
  int breite = 40;
  cout << endl << left << setw(breite) << "Studienfaecher/Module"
    << setw(breite / 4) << "LP"
    << setw(breite / 4) << "Status"
    << setw(breite / 4) << "Versuch"
    << setw(breite / 4) << "Leistungsbeurteilung" << endl;
  for (unsigned int i = 0; i < lehrveranstaltungen.size(); i++)
  {
    cout << left << setw(breite) << lehrveranstaltungen[i].liefere_bezeichnung()
    << setw(breite / 4) << lehrveranstaltungen[i].liefere_sws()
    << setw(breite / 4) << ((lehrveranstaltungen[i].liefere_note(student) < 4.5) ? "BE" : "NB")
    << setw(breite / 4) << 1
    << setw(breite / 4) << setprecision(1) << fixed << lehrveranstaltungen[i].liefere_note(student) << endl;
  }
}
/**
 * Für jede Lehrveranstaltung des 1. und 2. Semesters werden auf Wunsch ansprechend gestaltete
 * Teilnehmerlisten auf dem Bildschirm ausgegeben, sowohl alphabetisch sortiert nach dem Nachnamen als auch aufsteigend sortiert nach der Note
 * (bei gleicher Note nach dem Namen).
 */
void Semester::schreibe_teilnehmerliste()
{
  string *menuepunkte = new string[lehrveranstaltungen.size()];
  for (unsigned int i = 0; i < lehrveranstaltungen.size(); i++)
      menuepunkte[i] = lehrveranstaltungen[i].liefere_bezeichnung();
  Menue fachmenue(lehrveranstaltungen.size(), menuepunkte);
  int fachwahl = fachmenue.waehle_aus_menue();
  delete [] menuepunkte;
  menuepunkte = 0;
  cout << endl << "Die Teilnehmerliste fuer die Lehrveranstaltung "
    << lehrveranstaltungen[fachwahl - 1].liefere_bezeichnung() << " im "
    << bezeichnung << ":" << endl;
  lehrveranstaltungen[fachwahl - 1].schreibe_teilnehmerliste();
}
/**
 * Liefert die Durchschnittsnote des Studenten im diesem Semester.
 * @param student Der Student, fuer dem die Durchschnittsnote berechnet wird.
 * @return Die Durchschnittsnote des Studenten im diesem Semester.
 */
double Semester::liefere_durchschnittsnote(Student* student) const
{
  double durchschnittsnote = 0.0;
  for (unsigned int i = 0; i < lehrveranstaltungen.size(); i++)
  {
    durchschnittsnote += lehrveranstaltungen[i].liefere_note(student);
  }
  return durchschnittsnote = durchschnittsnote / lehrveranstaltungen.size();
}
// eventuell Code
// weiterer Funktionen
