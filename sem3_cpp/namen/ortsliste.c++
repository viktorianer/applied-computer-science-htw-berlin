#include "ortsliste.h"
// weitere Angaben
// Code der Konstruktoren

/**Erzeugt eine Instanz der Klasse Ortsliste, die aus drei bestimmten Listen die Landes-, Orts- und Strassennamen liefern kann.
 * Folgende Dateien werden benoetigt: Land fuer Landes-, Orte fuer Orts- und Strassen fuer Strassennamen.
 * Die Ortsliste muss pro Zeile eine PLZ gefolgt vom Ortsnamen enthalten.
 */
Ortsliste::Ortsliste()
{
  Dateimanager dateimanager;
  int anzahl_zeilen = dateimanager.lese_dateiinhalt("Land");
  landesnamen = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Landesnamen: " << anzahl_zeilen << endl;
  anzahl_zeilen = dateimanager.lese_dateiinhalt("Orte");
  ortsnamen = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Ortsnamen: " << anzahl_zeilen << endl;
  anzahl_zeilen = dateimanager.lese_dateiinhalt("Strassen");
  strassen = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Strassennamen: " << anzahl_zeilen << endl;
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
Ortsliste::~Ortsliste()
{
  landesnamen.clear();
  ortsnamen.clear();
  strassen.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Ortsliste::Ortsliste(const Ortsliste& original)
{
  landesnamen.clear();
  ortsnamen.clear();
  strassen.clear();
  landesnamen = original.landesnamen;
  ortsnamen = original.ortsnamen;
  strassen = original.strassen;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_ortsliste  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Ortsliste& Ortsliste::operator=(const Ortsliste& eine_ortsliste)
{
  if (this != &eine_ortsliste) // nur, wenn verschieden
  {
    landesnamen.clear();  // lösche alte Werte
    ortsnamen.clear();
    strassen.clear();
    landesnamen = eine_ortsliste.landesnamen; // speichere neue Werte
    ortsnamen = eine_ortsliste.ortsnamen;
    strassen = eine_ortsliste.strassen;
  }
  return *this;
}
// Code der Methoden
/**Liefert einen zufaelligen Ort mit zufaelligen Ortsnamen im zufaelligen Land.
 *
 * @return Einen zufaelligen Ort mit zufaelligen Ortsnamen im zufaelligen Land.
 */
Ort Ortsliste::liefere_zufalls_ort() const
{
  return Ort(liefere_zufalls_landesname(), liefere_zufalls_ortsname());
}
/**Liefert einen zufaelligen Ort mit zufaelligen Ortsnamen im bestimmten Land.
 *
 * @param landesname  Der Landesname, in dem sich der Ort befinden soll.
 * @return Einen zufaelligen Ort mit zufaelligen Ortsnamen im bestimmten Land.
 */
Ort Ortsliste::liefere_zufalls_ort(const string landesname) const
{
  return Ort(landesname, liefere_zufalls_ortsname());
}
/**Liefert eine zufaelligen Postanschrift mit zufaelligen Ortsnamen, Strasse, Strassennummer, PLZ im zufaelligen Land.
 *
 * @return Eine zufaelligen Postanschrift mit zufaelligen Ortsnamen, Strasse, Strassennummer, PLZ im zufaelligen Land..
 */
Postanschrift Ortsliste::liefere_zufalls_postanschrift() const
{
  return Postanschrift(liefere_zufalls_ort(), liefere_zufalls_strasse(),
    liefere_zufalls_strassennr(), liefere_zufalls_postleitzahl());
}
/**Liefert eine zufaelligen Postanschrift mit zufaelligen Ortsnamen, Strasse, Strassennummer, PLZ im bestimmten Land.
 *
 * @param landesname  Der Landesname, in dem sich der Ort befinden soll.
 * @return Eine zufaelligen Postanschrift mit zufaelligen Ortsnamen, Strasse, Strassennummer, PLZ im bestimmten Land..
 */
Postanschrift Ortsliste::liefere_zufalls_postanschrift(const string landesname) const
{
  return Postanschrift(liefere_zufalls_ort(landesname), liefere_zufalls_strasse(),
    liefere_zufalls_strassennr(), liefere_zufalls_postleitzahl());
}
/**Liefert einen zufaelligen Landesnamen aus der Landesliste.
 *
 * @return Einen zufaelligen Landesnamen aus der Landesliste.
 */
string Ortsliste::liefere_zufalls_landesname() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, landesnamen.size() - 1);
  string landesname = landesnamen[index];
  return landesname;
}
/**Liefer eine zufaellige PLZ aus der Ortsliste.
 *
 * @return Eine zufaellige PLZ aus der Ortsliste.
 */
string Ortsliste::liefere_zufalls_postleitzahl() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, ortsnamen.size() - 1);
  string postleitzahl = ortsnamen[index].substr(0, 5);
  return postleitzahl;
}
/**Liefert einen zufaelligen Ortsnamen aus der Ortsliste.
 *
 * @return Einen zufaelligen Ortsnamen aus der Ortsliste.
 */
string Ortsliste::liefere_zufalls_ortsname() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, ortsnamen.size() - 1);
  string ortsname = ortsnamen[index].substr(6);
  return ortsname;
}
/**Liefert einen zufaelligen Strassennamen aus der Strassenliste.
 *
 * @return Einen zufaelligen Strassennamen aus der Strassenliste.
 */
string Ortsliste::liefere_zufalls_strasse() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, strassen.size() - 1);
  string strasse = strassen[index];
  return strasse;
}
/**Liefert eine zufaellige Strassennummer.
 * 
 * @return Eine zufaellige Strassennummer.
 */
string Ortsliste::liefere_zufalls_strassennr() const
{
  stringstream itos;
  itos << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 300);
  return itos.str();
}
// eventuell Code
// weiterer Funktionen
