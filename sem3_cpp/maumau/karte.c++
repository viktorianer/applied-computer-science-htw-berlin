#include "karte.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt, mit Kartenwert Ass, Farbe Herz und elf Augen. */
Karte::Karte()
{
  kartenwert = "Ass";
  kartenfarbe = "Herz";
  augen = 11;
}
/**Erzeugt eine Karte mit dem uebergebenen Kartenwert und Kartenfarbe.
 * Die Augen werden nach dem Franzoesisches Blatt automatisch initialisiert.
 *
 * @param der_kartenwert  Der Kartenwert, dem die Karte erhalten soll.
 * @param die_kartenfarbe Die Kartenfarbe, die die Karte erhalten soll.
 */
Karte::Karte(const string der_kartenwert, const string die_kartenfarbe)
{
  kartenwert = der_kartenwert;
  kartenfarbe = die_kartenfarbe;
  initialisiere_augen();

}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
Karte::~Karte()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Karte::Karte(const Karte& original)
{
  kartenwert = original.kartenwert;
  kartenfarbe = original.kartenfarbe;
  augen = original.augen;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_karte  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Karte& Karte::operator=(const Karte& eine_karte)
{
  if (this != &eine_karte) // nur, wenn verschieden
  {
    kartenwert = eine_karte.kartenwert; // speichere neue Werte
    kartenfarbe = eine_karte.kartenfarbe;
    augen = eine_karte.augen;
  }
  return *this;
}
// Code der Methoden
/**Liefert den Kartenwert der Karte (Siebenâ€¦Zehn, Bube, Dame, Koenig, Ass).
 *
 * @return Der Kartenwert der Karte (Siebenâ€¦Zehn, Bube, Dame, Koenig, Ass).
 */
string Karte::liefere_kartenwert() const
{
  return kartenwert;
}
/**Liefert die Kartenfarbe der Karte (Kreuz, Pik, Herz, Karo).
 *
 * @return Die Kartenfarbe der Karte (Kreuz, Pik, Herz, Karo).
 */
string Karte::liefere_kartenfarbe() const
{
  return kartenfarbe;
}
/**Liefert die Anzahl der Augen der Karte (As elf Augen, die 10 zehn Augen, der Koenig vier, die Dame drei und der Bube zwei Augen.
 * Die uebrigen (9, 8, 7), die auch Luschen genannt werden, zaehlen nichts).
 *
 * @return Die Anzahl der Augen der Karte.
 */
int Karte::liefere_augen() const
{
  return augen;
}
/**Liefert die Information zur der Karte. Es wird die Farbe gefolgt von Kartenwert angegeben.
 *
 * @return Die Information zur der Karte
 */
string Karte::liefere_karten_info() const
{
  return liefere_kartenfarbe() + " " + liefere_kartenwert();
}
/**Vergleicht zwei Karten, ob diese in Kartenwert oder Kartenfarbe uebereinstimmen.
 *
 * @param eine_karte  Ein Karte, mit der verglichen werden soll.
 * @return Sind die Karte gleich (d.h. die beiden Karten uebereinstimmen) wird true und bei nicht gleich false zurueckgegeben.
 */
bool Karte::operator==(const Karte& eine_karte) const
{
  return (kartenwert == eine_karte.kartenwert) || (kartenfarbe == eine_karte.kartenfarbe);
}

/** Initialisiert die Augen fuer die Karte.
 * Das As zaehlt elf Augen, die 10 zÃ¤hlt zehn Augen, der Koenig vier, die Dame drei und der Bube zwei Augen.
 * Die uebrigen (9, 8, 7), die auch Luschen genannt werden, zaehlen nichts.
 */
void Karte::initialisiere_augen()
{
  if (kartenwert == "Ass")
    augen = 11;
  else if (kartenwert == "Zehn")
    augen = 10;
  else if (kartenwert == "Koenig")
    augen = 4;
  else if (kartenwert == "Dame")
    augen = 3;
  else if (kartenwert == "Bube")
    augen = 2;
  else
    augen = 0;
}
// eventuell Code
// weiterer Funktionen
