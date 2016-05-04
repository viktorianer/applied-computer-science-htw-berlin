#include "name.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultnamen "Max Mustermann". */
Name::Name()
{
  anz_vornamen = 1;
  anz_nachnamen = 1;
  initialisiere_namen();
}
/** Erzeugt einen Namen mit genau einem Vor- und genau einem Nachnamen.
 *
 *  @param   der_vorname        Der Vorname.
 *  @param   der_nachname       Der Nachname.
 */
Name::Name(const string& der_vorname, const string& der_nachname)
{
  anz_vornamen = 1;
  anz_nachnamen = 1;
  initialisiere_namen();
  string *ein_vorname = new string[anz_vornamen];
  ein_vorname[0] = der_vorname;
  string *ein_nachname = new string[anz_vornamen];
  ein_nachname[0] = der_nachname;
  initialisiere_namen(ein_vorname, ein_nachname);
  delete [] ein_vorname;
  delete [] ein_nachname;
}
/** Erzeugt einen Namen mit zwei Vor- und genau einem Nachnamen.
 *
 *  @param   der_vorname        Der erste Vorname.
 *  @param   der_mittelname     Der zweite Vorname.
 *  @param   der_nachname       Der Nachname.
 */
Name::Name(const string& der_vorname,  const string& der_mittelname, const string& der_nachname)
{
  anz_vornamen = 2;
  anz_nachnamen = 1;
  string *die_vornamen = new string[anz_vornamen];
  die_vornamen[0] = der_vorname;
  die_vornamen[1] = der_mittelname;
  string *ein_nachname = new string[anz_vornamen];
  ein_nachname[0] = der_nachname;
  initialisiere_namen(die_vornamen, ein_nachname);
  delete [] die_vornamen;
  delete [] ein_nachname;
}
/** Erzeugt einen Namen mit mehreren Vor- und genau einem Nachnamen.
 *
 *  @param   die_vornamen       Ein Array mit Vornamen.
 *  @param   anzahl_vornamen    Die Anzahl der Vornamen.
 *  @param   der_nachname       Der Nachname.
 */
Name::Name(const string *die_vornamen, int anzahl_vornamen, const string& der_nachname)
{
  if (die_vornamen != 0 && anzahl_vornamen > 0)
  {
    anz_vornamen = anzahl_vornamen;
    anz_nachnamen = 1;
    string *ein_nachname = new string[anz_nachnamen];
    ein_nachname[0] = der_nachname;
    initialisiere_namen(die_vornamen, ein_nachname);
    delete [] ein_nachname;
  }
}
/** Erzeugt einen Namen mit genau einem Vor- und mehreren Nachnamen.
 *
 *  @param   der_vorname        Der Vorname.
 *  @param   die_nachnamen      Ein Array mit Nachnamen.
 *  @param   anzahl_nachnamen   Die Anzahl der Nachnamen.
 */
Name::Name(const string& der_vorname, const string *die_nachnamen, int anzahl_nachnamen)
{
  if (die_nachnamen != 0 && anzahl_nachnamen > 0)
  {
    anz_vornamen = 1;
    anz_nachnamen = anzahl_nachnamen;
    string *ein_vorname = new string[anz_vornamen];
    ein_vorname[0] = der_vorname;
    initialisiere_namen(ein_vorname, die_nachnamen);
    delete [] ein_vorname;
  }
}
/** Erzeugt einen Namen mit mehreren Vor- und mehreren Nachnamen.
 *
 *  @param   die_vornamen       Ein Array mit Vornamen.
 *  @param   anzahl_vornamen    Die Anzahl der Vornamen.
 *  @param   die_nachnamen      Ein Array mit Nachnamen.
 *  @param   anzahl_nachnamen   Die Anzahl der Nachnamen.
 */
Name::Name(const string *die_vornamen,  int anzahl_vornamen, const string *die_nachnamen, int anzahl_nachnamen)
{  
  if (die_vornamen != 0 && anzahl_vornamen > 0 && die_nachnamen != 0 && anzahl_nachnamen > 0)
  {
    anz_vornamen = anzahl_vornamen;
    anz_nachnamen = anzahl_nachnamen;
    initialisiere_namen(die_vornamen, die_nachnamen);
  }
  else
  {
    anz_vornamen = 1;
    anz_nachnamen = 1;
    initialisiere_namen();
  }
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
Name::~Name()
{
  delete [] vorname;
  delete [] nachname;
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Name::Name(const Name& original)
{
  anz_vornamen = original.anz_vornamen;
  anz_nachnamen = original.anz_nachnamen;
  initialisiere_namen(original.vorname, original.nachname);
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_name  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Name& Name::operator=(const Name& ein_name)
{
  if (this != &ein_name)                 // nur, wenn verschieden
  {
    delete [] vorname;                       // lösche alte Werte
    delete [] nachname;
    anz_vornamen = ein_name.anz_vornamen; // speichere neue Werte
    anz_nachnamen = ein_name.anz_nachnamen;
    initialisiere_namen(ein_name.vorname, ein_name.nachname);
  }
  return *this;
}
// Code der Methoden
/** Liefert alle Vornamen.
 *
 *  @return    Alle Vornamen, durch genau ein Leerzeichen getrennt.
 */
string Name::liefere_vornamen() const
{
  string alle_vornamen;
  for (int i = 0; i < anz_vornamen; i++)
    if (i == 0)
      alle_vornamen += vorname[0];
    else
      alle_vornamen += (" " + vorname[i]);
  return alle_vornamen;
}
/** Liefert den ersten Vornamen.
 *
 *  @return    Den ersten Vornamen.
 */
string Name::liefere_rufnamen() const
{
  return vorname[0];
}
/** Liefert alle Nachnamen.
 *
 *  @return    Alle Nachnamen, durch genau ein Leerzeichen
 *             getrennt.
 */
string Name::liefere_nachnamen() const
{
  string alle_nachnamen;
  for (int i = 0; i < anz_nachnamen; i++)
    if (i == 0)
      alle_nachnamen += nachname[0];
    else
      alle_nachnamen += (" " + nachname[i]);
  return alle_nachnamen;
}
/** Liefert alle Vor- und alle Nachnamen.
 *
 *  @return    Alle Vor- und Nachnamen, durch genau ein
 *             Leerzeichen getrennt.
 */
string Name::liefere_namen() const
{
  return liefere_vornamen() + " " + liefere_nachnamen();
}
/** Liefert die Anzahl der Vornamen.
 *
 *  @return    Die Anzahl der Vornamen.
 */
int Name::liefere_anzahl_vornamen() const
{
  return anz_vornamen;
}
/** Liefert die Anzahl der Nachnamen.
 *
 *  @return    Die Anzahl der Nachnamen.
 */
int Name::liefere_anzahl_nachnamen() const
{
  return anz_nachnamen;
}
/**Ersetzt den Nachnamen mit einem neuen Nachnamen.
 *
 * @param der_neue_nachname Neuer Nachname.
 */
void Name::ersetze_nachnamen(const string& der_neue_nachname)
{
  nachname[0] = der_neue_nachname;
}
/**Ersetzt die Nachname mit den neuen Nachnamen.
 *
 * @param die_nachnamen Die neuen Nachnamen.
 * @param anzahl_nachnamen  Die Anzahl der Nachnamen.
 */
void Name::ersetze_nachnamen(const string *die_nachnamen, int anzahl_nachnamen)
{
  anz_nachnamen = anzahl_nachnamen;
  nachname = new string[anz_nachnamen];
  for (int i = 0; i < anz_nachnamen; i++)
    nachname[i] = die_nachnamen[i];
}

/** Allokiert auf dem Heap Speicherplatz für genau einen
 *  Vornamen und genau einen Nachnamen und speichert dort den Vor- bzw. den Nachnamen.
 *
 *  @param   der_vorname        Der Vorname.
 *  @param   der_nachname       Der Nachname.
 */
void Name::initialisiere_namen(const string& der_vorname, const string& der_nachname)
{
  vorname = new string[anz_vornamen];
  vorname[0] = der_vorname;
  nachname = new string[anz_nachnamen];
  nachname[0] = der_nachname;
}
/** Allokiert auf dem Heap Speicherplatz für anz_vornamen viele
 *  Vornamen und für anz_nachnamen viele Nachnamen und speichert dort die Vor- bzw. Nachnamen.
 *
 *  @param   die_vornamen        Ein Array mit Vornamen.
 *  @param   die_nachnamen       Ein Array mit Nachnamen.
 */
void Name::initialisiere_namen(const string *die_vornamen, const string *die_nachnamen)
{
  vorname = new string[anz_vornamen];
  for (int i = 0; i < anz_vornamen; i++)
    vorname[i] = die_vornamen[i];
  nachname = new string[anz_nachnamen];
  for (int i = 0; i < anz_nachnamen; i++)
    nachname[i] = die_nachnamen[i];
}
// eventuell Code
// weiterer Funktionen
/**Gibt den Namen in der in den Ausgabestream aus.
 *
 * @param ausgabe Der Ausgabestream, ueber welches die Ausgabe rausgeht.
 * @param name Der Name, welches ausgegeben werden soll.
 * @return Die Ausgabe des Namens.
 */
ostream& operator<<(ostream& ausgabe, const Name& name)
{
  ausgabe << name.liefere_namen();
  return ausgabe;
}
/**Vergleicht zwei Namen mit einander auf gleichhei.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Sind die Namen gleich (true) oder nicht (false).
 */
bool operator==(const Name& links, const Name& rechts)
{
  return links.liefere_nachnamen() == rechts.liefere_nachnamen()   &&
         links.liefere_vornamen() == rechts.liefere_vornamen();
}
/**Vergleicht zwei Namen mit einander auf ungleichheit.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Sind die Namen ungleich (true) oder nicht (false).
 */
bool operator!=(const Name& links, const Name& rechts)
{
  return !(links == rechts);
}
/**Vergleicht ob dieser Name kleiner als ein anderer Name ist, d.h. der linke Name kommt vor dem rechten Namen im Alphabet.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Ist der linke Name kleiner (true) oder nicht (false).
 */
bool operator<(const Name& links, const Name& rechts)
{
  bool nachname_kleiner  = (links.liefere_nachnamen().compare(rechts.liefere_nachnamen()) < 0);
  bool nachname_gleich  = (links.liefere_nachnamen().compare(rechts.liefere_nachnamen()) == 0);
  bool vorname_kleiner  = (links.liefere_nachnamen().compare(rechts.liefere_nachnamen()) < 0);
  return nachname_kleiner || (nachname_gleich && vorname_kleiner) ;
}
/**Vergleicht ob dieser Name kleiner-gleich als ein anderer Name ist, d.h. der linke Name kommt vor dem rechten Namen oder an gleicher position im Alphabet.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Ist der linke Name kleiner-gleich (true) oder nicht (false).
 */
bool operator<=(const Name& links, const Name& rechts)
{
  return links < rechts || links == rechts;
}
/**Vergleicht ob dieser Name groesser als ein anderer Name ist, d.h. der linke Name kommt hinter dem rechten Namen im Alphabet.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Ist der linke Name kleiner (true) oder nicht (false).
 */
bool operator>(const Name& links, const Name& rechts)
{
  return !(links <= rechts);
}
/**Vergleicht ob dieser Name groesser als ein anderer Name ist, d.h. der linke Name kommt hinter dem rechten Namen oder an gleicher position im Alphabet.
 *
 * @param links   Ein Name.
 * @param rechts  Ein zum Vergleich herangezogener Name.
 * @return Ist der linke Name kleiner (true) oder nicht (false).
 */
bool operator>=(const Name& links, const Name& rechts)
{
  return links > rechts || links == rechts;
}
/**Sortiert das Array von Namen alphabetisch aufsteigend.
 *
 * @param array   \c Input:  \n Das Namen-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das Namen-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 */
void sortiere(Name array[], int laenge)
{
  int index_max = 0;
  Name ablage;
  for (int i = laenge - 1; i > 0; i--)
  {
    index_max = 0;
    for (int j = 0; j <= i; j++)
      if (array[j] > array[index_max])
        index_max = j;
    if (array[index_max] > array[i])
    {
      ablage = array[i];
      array[i] = array[index_max];
      array[index_max] = ablage;
    }
  }
}
