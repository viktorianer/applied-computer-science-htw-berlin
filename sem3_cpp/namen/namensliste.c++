#include "namensliste.h"
// weitere Angaben
// Code der Konstruktoren

/**Erzeugt eine Instanz der Klasse Namensliste, die aus drei bestimmten Listen die maennliche und weibliche Vornamen sowie Nachnamen enthalten, namen liefern kann.
 * Folgende Dateien werden benoetigt: GivenNamesW fuer weibliche Vornamen, GivenNamesM maennliche Vornamen, FamilyNames fuer Nachnamen.
 */
Namensliste::Namensliste()
{
  Dateimanager dateimanager;
  int anzahl_zeilen = dateimanager.lese_dateiinhalt("GivenNamesW");
  vornamen_w = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener weiblicher Vornamen: " << anzahl_zeilen << endl;
  anzahl_zeilen = dateimanager.lese_dateiinhalt("GivenNamesM");
  vornamen_m = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener maennlicher Vornamen: " << anzahl_zeilen << endl;
  anzahl_zeilen = dateimanager.lese_dateiinhalt("FamilyNames");
  nachnamen = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener maennlicher Vornamen: " << anzahl_zeilen << endl;
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Namensliste::~Namensliste()
{
  vornamen_w.clear();
  vornamen_m.clear();
  nachnamen.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Namensliste::Namensliste(const Namensliste& original)
{
  vornamen_w.clear();
  vornamen_m.clear();
  nachnamen.clear();
  vornamen_w = original.vornamen_w;
  vornamen_m = original.vornamen_m;
  nachnamen = original.nachnamen;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_namensliste  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Namensliste& Namensliste::operator=(const Namensliste& eine_namensliste)
{
  if (this != &eine_namensliste) // nur, wenn verschieden
  {
    vornamen_w.clear(); // lösche alte Werte
    vornamen_m.clear();
    nachnamen.clear();
    vornamen_w = eine_namensliste.vornamen_w;
    vornamen_m = eine_namensliste.vornamen_m; // speichere neue Werte
    nachnamen = eine_namensliste.nachnamen;
  }
  return *this;
}
// Code der Methoden
/**Liefert einen zufaelligen Namen (mit einem Vornamen und Nachnamen) aus der zuvor eingelesenen Namensliste.
 *
 * @param geschlecht  Das Geschlecht, zu dem ein zufaelliges Name geliefert werden soll.
 * @return Ein zufaelligen Namen aus der zuvor eingelesenen Namensliste.
 */
Name Namensliste::liefere_zufalls_namen(const char geschlecht) const
{
  string vorname;
  if (geschlecht == 'w')
    vorname = liefere_zufalls_vorname_w();
  else
    vorname = liefere_zufalls_vorname_m();
  return Name(vorname, liefere_zufalls_nachname());
}
/**
 * Liefert einen zufaelligen, weiblichen Vornamen aus der Vornamenliste.
 * @return  Ein zufalls Vorname aus der Vornamenliste.
 */
string Namensliste::liefere_zufalls_vorname_w() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, vornamen_w.size() - 1);
  string vorname = vornamen_w[index];
  return vorname;
}
/**
 * Liefert einen zufaelligen maennlichen Vornamen aus der Vornamenliste.
 * @return  Ein zufalls Vorname aus der Vornamenliste.
 */
string Namensliste::liefere_zufalls_vorname_m() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, vornamen_m.size() - 1);
  string vorname = vornamen_m[index];
  return vorname;
}
/**
 * Liefert einen zufaelligen Nachnamen aus der Nachnamenliste.
 * @return  Ein zufalls Nachnamen aus der Nachnamenliste.
 */
string Namensliste::liefere_zufalls_nachname() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, nachnamen.size() - 1);
  string nachname = nachnamen[index];
  return nachname;
}
// eventuell Code
// weiterer Funktionen
