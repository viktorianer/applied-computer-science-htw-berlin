#include "professor.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt Professor mit Fachbereich FB 4, Studiengang AI und keine Sprechstunde. */
Professor::Professor()
: Beschaeftigter()
{
  fachbereich = "FB 4";
  studiengang = "Angewandte Informatik";
  sprechstunde = "";
}
/**Erzeugt einen Professor, die eine bestimmte Person ist, Fachbereich und einem Studiengang angehoert.
 *
 * @param die_person      Die Person, die Professor wird.
 * @param der_fachbereich Der Fachbereich des Professors.
 * @param der_studiengang Der Studiengang des Professors.
 */
Professor::Professor(Beschaeftigter die_person, const string der_fachbereich, const string der_studiengang)
: Beschaeftigter(die_person)
{
  fachbereich = der_fachbereich;
  studiengang = der_studiengang;
  string sprechtage[4] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag"};
  stringstream puffer;
  puffer << sprechtage[Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 3)]
    << "s, um "
    << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(9, 16)
    << ":00 Uhr";
  sprechstunde = puffer.str();
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Professor::~Professor()
{
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Professor::Professor(const Professor& original)
: Beschaeftigter(original)
{
  fachbereich = original.fachbereich;
  studiengang = original.studiengang;
  sprechstunde = original.sprechstunde;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_professor  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Professor& Professor::operator=(const Professor& ein_professor)
{
  if (this != &ein_professor) // nur, wenn verschieden
  {
    Beschaeftigter::operator =(ein_professor);
    fachbereich = ein_professor.fachbereich; // speichere neue Werte
    studiengang = ein_professor.studiengang;
    sprechstunde = ein_professor.sprechstunde;
  }
  return *this;
}
// Code der Methoden
/**Schreibt Informationen zum Professor, d.h. Fachbereich, Lehrfach und die Sprechstunde. */
void Professor::schreibe_informationen() const
{
  Beschaeftigter::schreibe_informationen();
  cout << "//////////////////////////////////////////////////////////////////////" << endl;
  cout << "Ich bin Prof im Fachbereich " << fachbereich << " an der HTW-Berlin." << endl;
  cout << "Ich halte Vorlesungen im Lehrfach " <<  studiengang << "." << endl;
  cout << "Ich bin in den Sprechstunden " << sprechstunde << " fuer alle Studenten zu erreichen." << endl;
}
// eventuell Code
// weiterer Funktionen
