#include "person.h"
#include "datum.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt Person, mit dem Namen Max Mustermann, aktuellen Datum und zufaelligen Geschlecht. */
Person::Person()
: name(), geburtstag(), geburtsort(), wohnanschrift()
{
  geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
  nationalitaet = "deutsch";
  telefonnummer = "";
}
/**Erzeugt eine Person mit einem bestimmten Namen und Geburtstag. Das Geschlecht ist zufaellig, die Nationalitaet ist deutsch und die Person hat keine Telefonnummer.
 *
 * @param der_name        Der Name, dem die Person haben soll.
 * @param der_geburtstag  Der Geburtstag, dem die Person haben soll.
 */
Person::Person(const Name& der_name, const Datum& der_geburtstag)
  : name(der_name), geburtstag(der_geburtstag), geburtsort(), wohnanschrift()
{
  geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
  nationalitaet = "deutsch";
  telefonnummer = "";
}
/**Erzeugt eine Person mit einem bestimmten Namen und Geburtstag. Die Nationalitaet ist deutsch und die Person hat keine Telefonnummer.
 *
 * @param der_name        Der Name, dem die Person haben soll.
 * @param der_geburtstag  Der Geburtstag, dem die Person haben soll.
 * @param das_geschlecht  Das Geschlecht der Person.
 */
Person::Person(const Name& der_name, const Datum& der_geburtstag, const char das_geschlecht)
  : name(der_name), geburtstag(der_geburtstag), geburtsort(), wohnanschrift()
{
  geschlecht = das_geschlecht;
  nationalitaet = "deutsch";
  telefonnummer = "";
}
/**Erzeugt eine Person mit einem bestimmten Namen und Geburtstag. Das Geschlecht ist zufaellig, die Nationalitaet ist deutsch und die Person hat keine Telefonnummer.
 *
 * @param der_name  Der Name, dem die Person haben soll.
 * @param der_tag   Der Tag des Geburtstages.
 * @param der_monat Der Monat des Geburtstages.
 * @param das_jahr  Das Jahr des Geburtstages.
 */
Person::Person(const Name& der_name, int der_tag, int der_monat, int das_jahr)
  : name(der_name), geburtstag(der_tag, der_monat, das_jahr), geburtsort(), wohnanschrift()
{
  geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
  nationalitaet = "deutsch";
  telefonnummer = "";
}
/**Erzeugt eine Person mit einem bestimmten Namen, Geburtstag, Geschlecht, Geburtsort, Nationalitaet, Wohnanschrift und Telefonnummer.
 *
 * @param der_name          Der Name, dem die Person haben soll.
 * @param der_geburtstag    Der Geburtstag, dem die Person haben soll.
 * @param das_geschlecht    Das Geschlecht der Person.
 * @param der_geburtsort    Der Geburtsort der Person.
 * @param die_nationalitaet Die Nationalitaet der Person.
 * @param die_wohnanschrift Die Wohnanschrift der Person.
 * @param die_telefonnummer Die Telefonnummer der Person.
 */
Person::Person(Name der_name, Datum der_geburtstag, const char das_geschlecht, Ort der_geburtsort,
            const string die_nationalitaet, Postanschrift die_wohnanschrift, const string die_telefonnummer)
: name(der_name), geburtstag(der_geburtstag), geburtsort(der_geburtsort), wohnanschrift(die_wohnanschrift)
{
  geschlecht = das_geschlecht;
  nationalitaet = die_nationalitaet;
  telefonnummer = die_telefonnummer;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Person::~Person()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Person::Person(const Person& original)
{
  name = original.name; // speichere neue Werte
  geburtstag = original.geburtstag;
  geschlecht = original.geschlecht;
  geburtsort = original.geburtsort;
  nationalitaet = original.nationalitaet;
  wohnanschrift = original.wohnanschrift;
  telefonnummer = original.telefonnummer;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_person  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Person& Person::operator=(const Person& eine_person)
{
  if (this != &eine_person) // nur, wenn verschieden
  {
    name = eine_person.name; // speichere neue Werte
    geburtstag = eine_person.geburtstag;
    geschlecht = eine_person.geschlecht;
    geburtsort = eine_person.geburtsort;
    nationalitaet = eine_person.nationalitaet;
    wohnanschrift = eine_person.wohnanschrift;
    telefonnummer = eine_person.telefonnummer;
  }
  return *this;
}
// Code der Methoden
/**Liefere den Namen der Person.
 *
 * @return Den Namen der Person.
 */
Name Person::liefere_den_namen() const
{
  return name;
}
/**Liefert den Rufnamen der Person.
 *
 * @return Den Rufnamen der Person.
 */
string Person::liefere_rufnamen() const
{
  return name.liefere_rufnamen();
}
/**Liefert den Vornamen der Person.
 *
 * @return Den Vornamen der Person.
 */
string Person::liefere_vornamen() const
{
  return name.liefere_vornamen();
}
/**Liefert den Nachnamen der Person.
 *
 * @return Den Nachnamen der Person.
 */
string Person::liefere_nachnamen() const
{
  return name.liefere_nachnamen();
}
/**Liefere den Namen der Person als String.
 *
 * @return Den Namen der Person als String.
 */
string Person::liefere_namen() const
{
  return name.liefere_namen();
}
/**Liefert die Anzahl der Vornamen.
 *
 * @return Die Anzahl der Vornamen.
 */
int Person::liefere_anzahl_vornamen() const
{
  return name.liefere_anzahl_vornamen();
}
/**Liefert die Anzahl der Nachnamen.
 *
 * @return Die Anzahl der Nachnamen.
 */
int Person::liefere_anzahl_nachnamen() const
{
  return name.liefere_anzahl_nachnamen();
}
/**Liefert das Geburtstag der Person.
 *
 * @return Das Geburtstag der Person.
 */
Datum Person::liefere_den_geburtstag() const
{
  return geburtstag;
}
/**Liefert das Geburtstag der Person als String.
 *
 * @return Das Geburtstag der Person als String.
 */
string Person::liefere_geburtstag() const
{
  return geburtstag.liefere_standarddatum();
}
/**Liefert den Jahrgan der Person, d.h. im welchem Jahr die Person geboren wurde.
 *
 * @return Den Jahrgan der Person, d.h. im welchem Jahr die Person geboren wurde.
 */
int Person::liefere_jahrgang() const
{
  return geburtstag.liefere_jahr();
}
string Person::liefere_geburtsort() const
{
  return geburtsort.liefere_ortsname();
}
/**Aendert den Nachnamen der Person.
 *
 * @param der_neue_nachname Der neue Nachname der Person.
 */
void Person::aendere_nachnamen(const string& der_neue_nachname)
{
  name.ersetze_nachnamen(der_neue_nachname);
}
/**Aendert die Nachnamen der Person.
 *
 * @param die_nachnamen Die neuen Nachnamen der Person.
 * @param anzahl_nachnamen  Die Anzahl der neuen Nachnamen.
 */
void Person::aendere_nachnamen(const string *die_nachnamen, int anzahl_nachnamen)
{
  name.ersetze_nachnamen(die_nachnamen, anzahl_nachnamen);
}
/**Aendert das Gebertstag der Person.
 *
 * @param der_tag   Der Tag des Geburtstages.
 * @param der_monat Der Monat des Geburtstages.
 * @param das_jahr  Das Jahr des Geburtstages.
 */
void Person::setze_geburtstag(int der_tag, int der_monat, int das_jahr)
{
  geburtstag = Datum(der_tag, der_monat, das_jahr);
}
/**Aendert das Gebertstag der Person.
 *
 * @param der_geburtstag Der neue Geburtstag der Person.
 */
void Person::setze_geburtstag(const Datum& der_geburtstag)
{
  geburtstag = Datum(der_geburtstag);
}
/**Schreibt Information zur Person auf die Konsole.
 *
 */
void Person::schreibe_informationen() const
{
  cout << "----------------------------------------------------------------------" << endl;
  cout << "Ich bin " << name.liefere_namen() << " (" << geschlecht << ")." << endl;
  cout << "Ich wurde am " << geburtstag.liefere_textdatum() << " in " 
    << geburtsort.liefere_ortsbeschreibung() << " geboren." << endl;
  cout << "Ich wohne in " << wohnanschrift.liefere_ortsbeschreibung() <<
    " und bin von der Nationalitaet " << nationalitaet << "." << endl;
  cout << "Meine Telefonnr.: " << telefonnummer << endl;
}
// eventuell Code
// weiterer Funktionen
/**Vergleicht zwei Personen mit einander auf gleichheit, d.h. wenn der Nachname und Vorname gleich sind.
 *
 * @param links   Eine Person.
 * @param rechts  Ein zum Vergleich herangezogene Personen.
 * @return Sind die Personen gleich (true) oder nicht (false).
 */
bool operator==(const Person& links, const Person& rechts)
{
  return links.liefere_den_namen() == rechts.liefere_den_namen()   &&
         links.liefere_den_geburtstag() == rechts.liefere_den_geburtstag();

}
/**Vergleicht zwei Personen mit einander auf ungleichheit, d.h. wenn der Nachname und Vorname ungleich sind.
 *
 * @param links   Eine Person.
 * @param rechts  Ein zum Vergleich herangezogene Personen.
 * @return Sind die Personen ungleich (true) oder nicht (false).
 */
bool operator!=(const Person& links, const Person& rechts)
{
  return !(links == rechts);
}
/**Vergleicht ob diese Person kleiner als ein andere Person ist,
 * d.h. die linke Person kommt im Alphabet vor der rechten Person oder bei gleichheit die linke Person ist aelter.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person kleiner (true) oder nicht (false).
 */
bool operator<(const Person& links, const Person& rechts)
{
  bool nachname_kleiner  = links.liefere_den_namen()  <  rechts.liefere_den_namen();
  bool nachname_gleich   = links.liefere_den_namen()  == rechts.liefere_den_namen();
  bool geburtstag_kleiner = links.liefere_den_geburtstag() <  rechts.liefere_den_geburtstag();
  return nachname_kleiner || (nachname_gleich && geburtstag_kleiner);
}
/**Vergleicht ob diese Person kleiner-gleich als ein andere Person ist,
 * d.h. die linke Person kommt im Alphabet vor der rechten Person oder bei gleichheit die linke Person ist aelter. Oder die beide sind gleich.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person kleiner-gleich (true) oder nicht (false).
 */
bool operator<=(const Person& links, const Person& rechts)
{
  return links < rechts || links == rechts;
}
/**Vergleicht ob diese Person groesser als ein andere Person ist,
 * d.h. die linke Person kommt im Alphabet nach der rechten Person oder bei gleichheit die linke Person ist juenger.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person groesser (true) oder nicht (false).
 */
bool operator>(const Person& links, const Person& rechts)
{
  return !(links <= rechts);
}
/**Vergleicht ob diese Person groesser-gleich als ein andere Person ist,
 * d.h. die linke Person kommt im Alphabet nach der rechten Person oder bei gleichheit die linke Person ist juenger. Oder die beide sind gleich.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person groesser-gleich (true) oder nicht (false).
 */
bool operator>=(const Person& links, const Person& rechts)
{
  return links > rechts || links == rechts;
}
/**Sortiert ein Person-Array aufsteigen nach den Namen, bei gleicheit nach dem Alter.
 *
 * @param array   \c Input:  \n Das Person-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das Person-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 */
void sortiere(Person array[], int laenge)
{
  int index_max = 0;
  Person ablage;
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
/**Sortiert ein Person-Array, nach der Vorschrift die in der Vergleichsfunktion festgelegt wurde.
 *
 * @param array   \c Input:  \n Das Person-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das Person-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 * @param vergleiche  Die Vergleichsfunktion, die bestimmt wie die Personen sortiert werden.
 */
void sortiere(Person array[], int laenge, int (*vergleiche)(const Person&, const Person&))
{
  int index_max = 0;
  Person ablage;
  for (int i = laenge - 1; i > 0; i--)
  {
    index_max = 0;
    for (int j = 0; j <= i; j++)
      if (vergleiche(array[j], array[index_max]) > 0)
        index_max = j;
    if (vergleiche(array[index_max], array[i]) > 0)
    {
      ablage = array[i];
      array[i] = array[index_max];
      array[index_max] = ablage;
    }
  }
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Namen, bei gleichheit nach dem Geburtstag vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Kommt der Name der linken Person vor der rechten Person im Alphabet oder wenn beide Namen gleich sind aber die linke Person ist aelter, so wird -1 zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Geburtstag wird 0 zurueckgegeben.
 * in allen anderen Faellen wird 1 zurueckgeben.
 */
int vergleiche_personen_comp(const Person* links, const Person* rechts)
{
  if (*links == *rechts)
    return 0;
  else
    return (*links < *rechts) ? -1 : 1;
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Geburtstag, bei gleichheit nach dem Namen vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person aelter oder beim gleichen Alter kommt der Name der linken Person vor der rechten Person im Alphabet, so wird -1 zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Geburtstag wird 0 zurueckgegeben.
 * in allen anderen Faellen wird 1 zurueckgeben.
 */
int vergleiche_nach_alter_comp(const Person* links, const Person* rechts)
{
  bool kleiner = (links->liefere_den_geburtstag() < rechts->liefere_den_geburtstag()) ||
                 ((links->liefere_den_geburtstag() == rechts->liefere_den_geburtstag()) &&
                  (links->liefere_den_namen() < rechts->liefere_den_namen()));
  if (*links == *rechts)
    return 0;
  else
    return kleiner ? -1 : 1;
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Jahrgang, bei gleichheit nach dem Namen vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person des aelteren Jahrgangs oder beim gleichen Jahrgang kommt der Name der linken Person vor der rechten Person im Alphabet, so wird -1 zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Jahrgang wird 0 zurueckgegeben.
 * in allen anderen Faellen wird 1 zurueckgeben.
 */
int vergleiche_nach_jahrgang_comp(const Person* links, const Person* rechts)
{
  bool kleiner = (links->liefere_jahrgang() < rechts->liefere_jahrgang()) ||
                 ((links->liefere_jahrgang() == rechts->liefere_jahrgang()) &&
                  (links->liefere_den_namen() < rechts->liefere_den_namen()));
  if (*links == *rechts)
    return 0;
  else
    return kleiner ? -1 : 1;
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Namen, bei gleichheit nach dem Geburtstag vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Kommt der Name der linken Person vor der rechten Person im Alphabet oder wenn beide Namen gleich sind aber die linke Person ist aelter, so wird true zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Geburtstag wird true zurueckgegeben.
 * in allen anderen Faellen wird fals zurueckgeben.
 */
bool vergleiche_personen(Person* links, Person* rechts)
{
  if (*links == *rechts)
    return true;
  else
    return (*links < *rechts) ? true : false;
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Geburtstag, bei gleichheit nach dem Namen vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person aelter oder beim gleichen Alter kommt der Name der linken Person vor der rechten Person im Alphabet, so wird true zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Geburtstag wird true zurueckgegeben.
 * in allen anderen Faellen wird false zurueckgeben.
 */
bool vergleiche_nach_alter(Person* links, Person* rechts)
{
  bool kleiner = (links->liefere_den_geburtstag() < rechts->liefere_den_geburtstag()) ||
                 ((links->liefere_den_geburtstag() == rechts->liefere_den_geburtstag()) &&
                  (links->liefere_den_namen() < rechts->liefere_den_namen()));
  if (*links == *rechts)
    return true;
  else
    return kleiner ? true : false;
}
/**Eine Vergleichsfunktion, die die beiden Personen nach dem Jahrgang, bei gleichheit nach dem Namen vergleicht.
 *
 * @param links   Eine Person.
 * @param rechts  Eine zum Vergleich herangezogene Person.
 * @return Ist die linke Person des aelteren Jahrgangs oder beim gleichen Jahrgang kommt der Name der linken Person vor der rechten Person im Alphabet, so wird true zurueckgegebn.
 * Haben die Personen gleichen Namen und gleichen Jahrgang wird true zurueckgegeben.
 * in allen anderen Faellen wird false zurueckgeben.
 */
bool vergleiche_nach_jahrgang(Person* links, Person* rechts)
{
  bool kleiner = (links->liefere_jahrgang() < rechts->liefere_jahrgang()) ||
                 ((links->liefere_jahrgang() == rechts->liefere_jahrgang()) &&
                  (links->liefere_den_namen() < rechts->liefere_den_namen()));
  if (*links == *rechts)
    return true;
  else
    return kleiner ? true : false;
}