#include "preis.h"
// weitere Angaben
const double Preis::MWST_SATZ = 0.19;
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt */
Preis::Preis()
{
  brutto_preis = 0.0;
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Preis::~Preis()
{
}
Preis::Preis(double preis)
{
  brutto_preis = preis < 0 ? -1 * preis : preis;
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Preis::Preis(const Preis& original)
{
  brutto_preis = original.brutto_preis;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_preis  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Preis& Preis::operator=(const Preis& ein_preis)
{
  if (this != &ein_preis) // nur, wenn verschieden
  {
    brutto_preis = ein_preis.brutto_preis;
  }
  return *this;
}
// Code der Methoden
double Preis::liefere_mwst_anteil() const
{
  return MWST_SATZ * brutto_preis;
}
double Preis::liefere_brutto_preis() const
{
  return brutto_preis;
}
double Preis::liefere_netto_preis() const
{
  return brutto_preis - MWST_SATZ * brutto_preis;
}
// eventuell Code
// weiterer Funktionen
