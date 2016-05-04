#include "land.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt, mit dem Landname Deutschland */
Land::Land()
{
  landesname = "Deutschland";
}
Land::Land(const string ein_landesname)
{
  landesname = ein_landesname;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Land::~Land()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Land::Land(const Land& original)
{
  landesname = original.landesname;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_land  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Land& Land::operator=(const Land& ein_land)
{
  if (this != &ein_land) // nur, wenn verschieden
  {
    landesname = ein_land.landesname; // speichere neue Werte
  }
  return *this;
}
// Code der Methoden
/**Liefer den Namen des Landes.
 *
 * @return Name des Landes.
 */
string Land::liefere_landesname() const
{
  return landesname;
}
// eventuell Code
// weiterer Funktionen
