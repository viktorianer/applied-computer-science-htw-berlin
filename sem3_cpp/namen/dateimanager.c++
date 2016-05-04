#include "dateimanager.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt */
Dateimanager::Dateimanager()
{
  datei_inhalt.clear();
}
/** Erzeugt den Defaultobjekt fuer einen Dateimanger, der die Datei zeilenweise einliest, wobei jede Zeile der Datei in einem String gespeichert wird. */
Dateimanager::Dateimanager(string dateiname)
{
  lese_dateiinhalt(dateiname);
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Dateimanager::~Dateimanager()
{
  datei_inhalt.clear();
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Dateimanager::Dateimanager(const Dateimanager& original)
{
  datei_inhalt.clear(); // lösche alte Werte
  datei_inhalt = original.datei_inhalt;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_dateimanager  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Dateimanager& Dateimanager::operator=(const Dateimanager& ein_dateimanager)
{
  if (this != &ein_dateimanager) // nur, wenn verschieden
  {
    datei_inhalt.clear(); // lösche alte Werte
    datei_inhalt = ein_dateimanager.datei_inhalt; // speichere neue Werte
  }
  return *this;
}
// Code der Methoden
/**Die Datei wird zeilenweise eingelesen, wobei jede Zeile der Datei in einem String gespeichert wird.
 *
 * @param dateiname Der Name der Datei.
 * @return Die Anzahl der gelesenen Zeilen.
 */
int Dateimanager::lese_dateiinhalt(string dateiname)
{
  string text = "";
  ifstream fs;
  datei_inhalt.clear();
  fs.open(dateiname.c_str());
  while (fs.good())
  {
    getline(fs, text);
    if (fs.good())
      datei_inhalt.push_back(text);
  }
  fs.close();
  return datei_inhalt.size() + 0;
}
/**Liefert den Dateiinhalt, wobei jede Zeile der Datei in einem String gespeichert ist.
 *
 * @return Der Dateiinhalt, wobei jede Zeile der Datei in einem String gespeichert ist.
 */
vector<string> Dateimanager::liefere_dateiinhalt() const
{
  return datei_inhalt;
}
// eventuell Code
// weiterer Funktionen
