#include "einschreibung.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt */
Einschreibung::Einschreibung()
{
}
/**Erzeugt eine Einschreibung mit einem Studenten und einer zufaelligen Note.
 * 
 * @param ein_student Der Student, der sich eingeschrieben hat und eine Note bekommt.
 */
Einschreibung::Einschreibung(Student* ein_student)
{
  student = ein_student;
  note = liefere_zufaellige_note();
//  cout << "eingeschriebener Student: " << student->liefere_namen() << " bekommt die Note: " << setprecision(1) << fixed << note << endl;
}
/**Erzeugt eine Einschreibung mit einem Studenten und einer Note.
 * 
 * @param ein_student Der Student, der sich eingeschrieben hat.
 * @param die_note    Die Note des Studenten.
 */
Einschreibung::Einschreibung(Student* ein_student, double die_note)
{
  student = ein_student;
  note = die_note;
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Einschreibung::~Einschreibung()
{
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Einschreibung::Einschreibung(const Einschreibung& original)
{
//  cout << "Kopierter Student: " << original.student->liefere_namen() << endl;
  student = original.student;
  note = original.note;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_einschreibung  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Einschreibung& Einschreibung::operator=(const Einschreibung& ein_einschreibung)
{
//  cout << "Student zugewiesen: " << student->liefere_namen() << endl;
  if (this != &ein_einschreibung) // nur, wenn verschieden
  {
    student = ein_einschreibung.student; // speichere neue Werte
    note = ein_einschreibung.note;
  }
  return *this;
}
// Code der Methoden
/**
 * Liefert den Zeiger auf Studenten, der sich in einem Fach eingeschrieben hat.
 * @return Den Zeiger auf Studenten, der sich in einem Fach eingeschrieben hat.
 */
Student* Einschreibung::liefere_studenten() const
{
  return student;
}
/**
 * Liefert die Note des Studenten fuer einen Fach.
 * @return Die Note des Studenten fuer einen Fach.
 */
double Einschreibung::liefere_note() const
{
  return note;
}
/**
 * Liefert den Namen des Studenten.
 * @return Den Namen des Studenten.
 */
Name Einschreibung::liefere_den_namen() const
{
  return student->liefere_den_namen();
}

/**
 * Liefert eine zufaellige (laut Prüfungsordnung zulässige) Prüfungsnote.
 * @return Eine zufaellige (laut Prüfungsordnung zulässige) Prüfungsnote.
 */
double Einschreibung::liefere_zufaellige_note() const
{
  double dezimal[] = {0.0, 0.3, 0.5, 0.7};
  double note = 1.0;
  note = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 5);
  if (1 < note && note < 5)
  {
    note = note + dezimal[Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 4) - 1];
  }
  return note;
}
// eventuell Code
// weiterer Funktionen
/**Vergleicht zwei Einschreibungen mit einander auf gleichheit, d.h. wenn die Note und der Nachname und Vorname gleich sind.
 *
 * @param links   Eine Einschreibung.
 * @param rechts  Ein zum Vergleich herangezogene Einschreibung.
 * @return Sind die Einschreibungen gleich (true) oder nicht (false).
 */
bool operator==(const Einschreibung& links, const Einschreibung& rechts)
{
  return links.liefere_den_namen() == rechts.liefere_den_namen()   &&
         links.liefere_note() == rechts.liefere_note();

}
/**Vergleicht zwei Einschreibungen mit einander auf gleichheit, d.h. wenn die Note und der Nachname und Vorname gleich sind.
 *
 * @param links   Eine Einschreibung.
 * @param rechts  Ein zum Vergleich herangezogene Einschreibung.
 * @return Sind die Einschreibungen gleich (true) oder nicht (false).
 */
bool vergleiche_note_name(Einschreibung* links, Einschreibung* rechts)
{
  bool kleiner = (links->liefere_note() < rechts->liefere_note()) ||
                 ((links->liefere_note() == rechts->liefere_note()) &&
                  (links->liefere_den_namen() < rechts->liefere_den_namen()));
  if (*links == *rechts)
    return true;
  else
    return kleiner ? true : false;
}