#include "ort.h"
// weitere Angaben
// Code der Konstruktoren

/**Erzeugt den Defaultobjekt, einen Ort mit dem Namen Berlin. */
Ort::Ort()
: land()
{
  ortsname = "Berlin";
}
/**Erzeugt einen Ort mit einem bestimmten Namen.
 *
 * @param ein_ortsname  Der Name des Ortes.
 */
Ort::Ort(const string ein_ortsname)
: land()
{
  ortsname = ein_ortsname;
}
/**Erzeugt einen Ort mit bestimmten Namen in einem bestimmten Land.
 *
 * @param ein_landesname  Der Name des Landes.
 * @param ein_ortsname    Der name des Ortes.
 */
Ort::Ort(const string ein_landesname, const string ein_ortsname)
: land(ein_landesname)
{
  ortsname = ein_ortsname;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Ort::~Ort()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Ort::Ort(const Ort& original)
{
  ortsname = original.ortsname;
  land = original.land;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_ort  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Ort& Ort::operator=(const Ort& ein_ort)
{
  if (this != &ein_ort) // nur, wenn verschieden
  {
    ortsname = ein_ort.ortsname;  // speichere neue Werte
    land = ein_ort.land;
  }
  return *this;
}
// Code der Methoden
/**Liefert den Namen des Ortes.
 *
 * @return Der Namen des Ortes.
 */
string Ort::liefere_ortsname() const
{
  return ortsname;
}
/**Liefert die Ortsbeschreibung, d.h. Ortsname, und wenn vorhanden, Name des Landes.
 *
 * @return  Die Ortsbeschreibung, d.h. Ortsname, und wenn vorhanden, Name des Landes.
 */
string Ort::liefere_ortsbeschreibung() const
{
  string beschreibung = ortsname;
  if (beschreibung != "" && land.liefere_landesname() != "")
    beschreibung += (", " + land.liefere_landesname());
  return beschreibung;
}
// eventuell Code
// weiterer Funktionen
