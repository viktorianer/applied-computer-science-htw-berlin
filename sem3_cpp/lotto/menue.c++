#include "menue.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt, ein leeres Menue */
Menue::Menue()
{
  anzahl_menuepunkte = 1;
  string *menuepunkt = new string("Leeres Menue");
  initialisiere_menuepunkte(menuepunkt);
}
/**Erzeugt Menue mit den uebergebenen Menuepunkten.
 *
 * @param menuelaenge Die Laenge des Menues.
 * @param menuepunkte Die gewuenschten Menuepunkte.
 */
Menue::Menue(int menuelaenge, const string *menuepunkte)
{
  if (menuelaenge > 0)
  {
    anzahl_menuepunkte = menuelaenge;
    initialisiere_menuepunkte(menuepunkte);
  }
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Menue::~Menue()
{
  delete [] menuepunkte;
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Menue::Menue(const Menue& original)
{
  anzahl_menuepunkte = 1;
  initialisiere_menuepunkte(original.menuepunkte);
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_menue  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Menue& Menue::operator=(const Menue& ein_menue)
{
  if (this != &ein_menue) // nur, wenn verschieden
  {
    delete [] menuepunkte; // lösche alte Werte
    anzahl_menuepunkte = ein_menue.anzahl_menuepunkte; // speichere neue Werte
    initialisiere_menuepunkte(ein_menue.menuepunkte);
  }
  return *this;
}
// Code der Methoden
/**Schreibt ein Menue und erfasst eine Anwort mit einer ganzen Zahl und vergleicht diese
 * mit dem Wertebereich zwischen 1 und menuelaenge.
 * Trifft die Eingabe auf keinen der beiden Werte (min, max) zu oder einen Wert dazwischen wird eine Fehlermeldung
 * ausgeben, die noch ein mal den gewünschten Wertebereich, also 1 bis menuelaenge, anzeigt.
 *
 * @return	Die erfasste Eingabe, ganze Zahl wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int Menue::waehle_aus_menue() const
{
  schreibe_menue();
  return Eingaben::erfasse_int("\n\nIhre Wahl:  ", 1, anzahl_menuepunkte);
}

/**Schreibt ein Menue mit menuelaenge Zeilen und mit dem uebergebenen Text.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Menue::schreibe_menue() const
{
  for (int i = 0; i < anzahl_menuepunkte; i++)
  {
    int menuepunkt = (i + 1);
    cout << "\n(" << menuepunkt << ")\t" << menuepunkte[i];
  }
}

/**Initialisiert die Menuepunkte mit dem uebergebenen Text.
 *
 * @param die_menuepunkte Der gewuenschte Text fuer die Menuepunkte.
 */
void Menue::initialisiere_menuepunkte(const string *die_menuepunkte)
{
  menuepunkte = new string[anzahl_menuepunkte];
  for (int i = 0; i < anzahl_menuepunkte; i++)
    menuepunkte[i] = die_menuepunkte[i];
}
// eventuell Code
// weiterer Funktionen
