#include "postanschrift.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt Postanschrift, mit der Strasse Hauptstasse 1 in 12459 Berin. */
Postanschrift::Postanschrift()
: ort()
{
  strasse = "Hauptstrasse";
  hausnummer = "1";
  postleitzahl = "12459";
}
/**Erzeugt eine Postanschrift, mit einer bestimmten Stasse, Hausnummer und PLZ.
 *
 * @param die_strasse       Die PLZ der neuen Postanschrift.
 * @param eine_hausnummer   Die Hausnummer der neuen Postanschrift.
 * @param die_postleitzahl  Die PLZ der neuen Postanschrift.
 */
Postanschrift::Postanschrift(const string die_strasse, const string eine_hausnummer,const string die_postleitzahl)
: ort()
{
  strasse = die_strasse;
  hausnummer = eine_hausnummer;
  postleitzahl = die_postleitzahl;
}
/**Erzeugt eine Postanschrift, mit einem bestimmten Ortsnamen, Stasse, Hausnummer und PLZ.
 *
 * @param ein_ortsname      Der Ortsname der neuen Postanschrift.
 * @param die_strasse       Die PLZ der neuen Postanschrift.
 * @param eine_hausnummer   Die Hausnummer der neuen Postanschrift.
 * @param die_postleitzahl  Die PLZ der neuen Postanschrift.
 */
Postanschrift::Postanschrift(const string ein_ortsname,
  const string die_strasse, const string eine_hausnummer,const string die_postleitzahl)
: ort(ein_ortsname)
{
  strasse = die_strasse;
  hausnummer = eine_hausnummer;
  postleitzahl = die_postleitzahl;
}
/**Erzeugt eine Postanschrift, mit einem bestimmten Ortsnamen, Stasse, Hausnummer und PLZ in einem bestimmten Land.
 *
 * @param ein_landesname    Das Land der neuen Postanschrift.
 * @param ein_ortsname      Der Ortsname der neuen Postanschrift.
 * @param die_strasse       Die PLZ der neuen Postanschrift.
 * @param eine_hausnummer   Die Hausnummer der neuen Postanschrift.
 * @param die_postleitzahl  Die PLZ der neuen Postanschrift.
 */
Postanschrift::Postanschrift(const string ein_landesname, const string ein_ortsname,
  const string die_strasse, const string eine_hausnummer,const string die_postleitzahl)
: ort(ein_landesname, ein_ortsname)
{
  strasse = die_strasse;
  hausnummer = eine_hausnummer;
  postleitzahl = die_postleitzahl;
}
/**Erzeugt eine Postanschrift, mit einem bestimmten Ort, Stasse, Hausnummer und PLZ.
 *
 * @param ein_ort           Der Ort der neuen Postanschrift.
 * @param die_strasse       Die PLZ der neuen Postanschrift.
 * @param eine_hausnummer   Die Hausnummer der neuen Postanschrift.
 * @param die_postleitzahl  Die PLZ der neuen Postanschrift.
 */
Postanschrift::Postanschrift(Ort ein_ort,
  const string die_strasse, const string eine_hausnummer,const string die_postleitzahl)
: ort(ein_ort)
{
  strasse = die_strasse;
  hausnummer = eine_hausnummer;
  postleitzahl = die_postleitzahl;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Postanschrift::~Postanschrift()
{
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Postanschrift::Postanschrift(const Postanschrift& original)
{
  strasse = original.strasse;
  hausnummer = original.hausnummer;
  postleitzahl = original.postleitzahl;
  ort = original.ort;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_postanschrift  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Postanschrift& Postanschrift::operator=(const Postanschrift& eine_postanschrift)
{
  if (this != &eine_postanschrift) // nur, wenn verschieden
  {
    strasse = eine_postanschrift.strasse; // speichere neue Werte
    hausnummer = eine_postanschrift.hausnummer;
    postleitzahl = eine_postanschrift.postleitzahl;
    ort = eine_postanschrift.ort;
  }
  return *this;
}
// Code der Methoden
/**Liefert den Strassennamen der Postanschrift.
 *
 * @return Den Strassennamen der Postanschrift.
 */
string Postanschrift::liefere_strasse() const
{
  return strasse;
}
/**Liefert die Hausnummer der Postanschrift.
 *
 * @return Die Hausnummer der Postanschrift.
 */
string Postanschrift::liefere_hausnummer() const
{
  return hausnummer;
}
/**Liefert die PLZ der Postanschrift.
 *
 * @return Die PLZ der Postanschrift.
 */
string Postanschrift::liefere_postleitzahl() const
{
  return postleitzahl;
}
/**Liefert die Ortstbeschreibung, d.h. Strasse, Hausnummer, PLZ, Ort und Land.
 *
 * @return Die Ortstbeschreibung, d.h. Strasse, Hausnummer, PLZ, Ort und Land.
 */
string Postanschrift::liefere_ortsbeschreibung() const
{
  string beschreibung = strasse + " " + hausnummer;
  if (beschreibung != "" && postleitzahl != "")
    beschreibung += (", " + postleitzahl);
  if (beschreibung != "" && ort.liefere_ortsbeschreibung() != "")
    beschreibung += (" " + ort.liefere_ortsbeschreibung());
  return beschreibung;
}
// eventuell Code
// weiterer Funktionen
