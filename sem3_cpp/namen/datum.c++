#include "datum.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt, des aktuellen Datums. */
Datum::Datum()
{
  time_t zeit = time(0);
  struct tm *p = localtime(&zeit);
  tag = p->tm_mday;
  monat = (p->tm_mon) + 1;
  jahr = (p->tm_year) + 1900;
}
/**Erzeugt ein Datum mit bestimmten Tag, Monat und Jahr.
 *
 * @param tag   Der Tag des Datums.
 * @param monat Der Monat des Datums.
 * @param jahr  Das Jahr des Datums.
 */
Datum::Datum(int tag, int monat, int jahr)
{
  if (datum_ok(tag, monat, jahr))
    initialisiere_datum(tag, monat, jahr);
  else
    initialisiere_datum();
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
Datum::~Datum()
{

}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Datum::Datum(const Datum& original)
{
  tag = original.tag;
  monat = original.monat;
  jahr = original.jahr;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_datum  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Datum& Datum::operator=(const Datum& ein_datum)
{
  if (this != &ein_datum) // nur, wenn verschieden
  {
    tag = ein_datum.tag; // speichere neue Werte
    monat = ein_datum.monat;
    jahr = ein_datum.jahr;
  }
  return *this;
}
// Code der Methoden
/**Liefert den Tag des Datums.
 *
 * @return Der Tag des Datums.
 */
int Datum::liefere_tag() const
{
  return tag;
}
/**Liefert den Monat des Datums.
 *
 * @return Der Monat des Datums.
 */
int Datum::liefere_monat() const
{
  return monat;
}
/**Liefert das Jahr des Datums.
 *
 * @return Das Jahr des Datums.
 */
int Datum::liefere_jahr() const
{
  return jahr;
}
/**Liefert das Datum nach der deutschen DIN-Norm (JJJJ-MM-TT).
 *
 * @return Das Datum nach der deutschen DIN-Norm (JJJJ-MM-TT).
 */
string Datum::liefere_din_datum() const
{
  ostringstream wandler(ios::out);
  if (monat >= 10)
    wandler << jahr << '-' << monat << '-';
  else
    wandler << jahr << '-' << '0' << monat << '-';
  if (tag >= 10)
    wandler << tag;
  else
    wandler << '0' << tag;
  return wandler.str();
}
/**Liefert das Datum in der Standardform (TT.MM.JJJJ)
 *
 * @return Das Datum in der Standardform (TT.MM.JJJJ)
 */
string Datum::liefere_standarddatum() const
{
  ostringstream wandler(ios::out);
  if (tag >= 10)
    wandler << tag << '.';
  else
    wandler << '0' << tag << '.';
  if (monat >= 10)
    wandler << monat << '.' << jahr;
  else
    wandler << '0' << monat << '.' << jahr;
  return wandler.str();
}
/**Liefert das Datum in der Textform (TT. <Monat in Textform> JJJJ)
 *
 * @return Das Datum in der Textform (TT. <Monat in Textform> JJJJ)
 */
string Datum::liefere_textdatum() const
{
  string name[] = {"Fehler! Falscher Monat.", "Januar",
                   "Februar", "Maerz", "April", "Mai",
                   "Juni", "Juli", "August", "September",
                   "Oktober", "November", "Dezember"};
  ostringstream wandler(ios::out);
  wandler << tag << '.' << ' ' << name[monat]
          << ' ' << jahr;
  return wandler.str();
}
/**Liefert den Wochentag des Datums.
 *
 * @return Der Wochentag des Datums.
 */
string Datum::liefere_wochentag() const
{
  string name[] = {"Samstag", "Sonntag", "Montag", "Dienstag",
                   "Mittwoch", "Donnerstag", "Freitag"};
  return name[liefere_tage() % 7];
}
/**Liefert den Wochentag und das Datum in der Textform (Wochentag, TT. <Monat in Textform> JJJJ).
 *
 * @return Der Wochentag und das Datum in der Textform (Wochentag, TT. <Monat in Textform> JJJJ).
 */
string Datum::liefere_wochentagdatum() const
{
  string datumstext = liefere_wochentag();
  datumstext += ", ";
  datumstext += liefere_textdatum();
  return datumstext;
}
/**Addiert die Tage zum Datum.
 *
 * @param tage  Die Anzahl der Tage.
 * @return Das neue Datum, zu dem die Tage addiert wurden.
 */
Datum Datum::operator+(int tage) const
{
  long  anzahl_tage = liefere_tage();
  anzahl_tage += tage;
  return liefere_datum(anzahl_tage);
}
/**Liefert die Differenz zwischen zwei Tagen.
 *
 * @param ein_datum Das Datum, zu dem die Differenz gebildet werden soll.
 * @return Die Differenz als Zahl.
 */
int Datum::operator-(const Datum& ein_datum) const
{
  return liefere_tage() - ein_datum.liefere_tage();
}
/**Addiert einen Tag zum Datum (Post-Inkrement-Operator).
 *
 * @return Das neue Datum, zu dem ein Tage addiert wurden.
 */
Datum& Datum::operator++()
{
  *this = *this + 1;
  return *this;
}
/**Addiert einen Tag zum Datum (Prae-Inkrement-Operator).
 *
 * @return Das neue Datum, zu dem ein Tage addiert wurden.
 */
Datum Datum::operator++(int)
{
  Datum altes_datum = *this;
  ++*this;
  return altes_datum;
}
/**Initialisiert das Datum.
 *
 * @param tag   Der Tag des Datums.
 * @param monat Der Monat des Datums.
 * @param jahr  Das Jahr des Datums.
 */
void Datum::initialisiere_datum(int der_tag, int der_monat, int das_jahr)
{
  tag   = der_tag;
  monat = der_monat;
  jahr  = das_jahr;
}
/**Prueft, ob die Parameter zur erzeugen eines Datums ein gueltiges Datum ergeben.
 *
 * @param tag   Der Tag des Datums.
 * @param monat Der Monat des Datums.
 * @param jahr  Das Jahr des Datums.
 * @return Ob die Parameter zur erzeugen eines Datums ein gueltiges Datum ergeben (true) oder nicht (false).
 */
bool Datum::datum_ok(int tag, int monat, int jahr) const
{
  return (1583 <= jahr) &&
         (jahr <= INT_MAX) &&
         (1 <= monat) &&
         (monat <= 12) &&
         (1 <= tag) &&
         (tag <= liefere_tage_im_monat(monat, jahr));
}
/**Liefert die Anzahl der Tage eines bestimmten Monats in einem bestimmten Jahr.
 *
 * @param monat Der Monat, fuer dem die Anzahl der Tage zurueckgegeben werden soll.
 * @param jahr  Das Jahr, in dem sich der Monat befinden soll.
 * @return Die Anzahl der Tage eines bestimmten Monats in einem bestimmten Jahr.
 */
int Datum::liefere_tage_im_monat(int monat, int jahr) const
{
  int tage[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((1 <= monat) && (monat <= 12))
  {
    if (monat == 2 && ist_schaltjahr(jahr))
      return tage[monat] + 1;
    else
      return tage[monat];
  }
  else
    return tage[0];
}
/**Prueft, ob ein Jahr ein schaltjahr ist.
 *
 * @param jahr  Das Jahr, welches geprueft werden soll.
 * @return Ob ein Jahr ein schaltjahr ist (true) oder nicht (false).
 */
bool Datum::ist_schaltjahr(int jahr) const
{
  return ((jahr % 4 == 0) && ((jahr % 100 != 0) || (jahr % 400 == 0)));
}
/**Liefert die Anzahl der Tage im Jahr (Schaltjahr 366 Tage, normales Jahr 365 Tage).
 *
 * @param jahr  Das Jahr, welches geprueft werden soll.
 * @return Die Anzahl der Tage im Jahr (Schaltjahr 366 Tage, normales Jahr 365 Tage).
 */
int Datum::liefere_tage_im_jahr(int jahr) const
{
  return ist_schaltjahr(jahr) ? 366 : 365;
}
/**Liefere die Anzahl der Tage, die seit der einfuerung des Gregorianischen Kalenders bis zu diesem Datum abgelaufen sind.
 *
 * @return Die Anzahl der Tage, die seit der einfuerung des Gregorianischen Kalenders bis zu diesem Datum abgelaufen sind.
 */
long Datum::liefere_tage() const
{
  long anzahl_tage = 0;
  for (long i = 1583; i < jahr; i++)
    anzahl_tage += liefere_tage_im_jahr(i);
  if (monat != 1)
    for (long i = 1; i < monat; i++)
      anzahl_tage += liefere_tage_im_monat(i, jahr);
  return (anzahl_tage + tag - 1);
}
/**Liefert das Datum, welches die Anzahl der Tage seit der einfuerung des Gregorianischen Kalenders repraesentiert.
 *
 * @param tage  Die Anzahl der Tage, seit der einfuerung des Gregorianischen Kalenders.
 * @return Das Datum, welches die Anzahl der Tage seit der einfuerung des Gregorianischen Kalenders repraesentiert.
 */
Datum Datum::liefere_datum(long tage) const
{
  long gezaehlte_tage = 0;
  int jahr = 0;
  for (jahr = 1583; gezaehlte_tage <= tage; jahr++)
    gezaehlte_tage += liefere_tage_im_jahr(jahr);
  jahr--;
  gezaehlte_tage -= liefere_tage_im_jahr(jahr);
  int monat = 0;
  for (monat = 1; gezaehlte_tage <= tage; monat++)
    gezaehlte_tage += liefere_tage_im_monat(monat, jahr);
  monat--;
  gezaehlte_tage -= liefere_tage_im_monat(monat, jahr);
  int tag = tage - gezaehlte_tage + 1;
  return Datum(tag, monat, jahr);
}
// eventuell Code
// weiterer Funktionen
/**Erfasst die Eingabe eines gueltigen Datums.
 *
 * @param eingabe Der Eingabestream, ueber welches die Eingabe eingeht.
 * @param datum Das Datum, wie die Eingabe gespeichert wurde.
 * @return Die Eingabe eines gueltigen Datums.
 */
istream& operator>>(istream& eingabe, Datum& datum)
{
  int tag = 0;
  int monat = 0;
  int jahr = 0;
  bool eingabe_ok = false;
  do
  {
    tag = Eingaben::erfasse_int("Bitte den Tag eingeben:     ", 1, 31);
    monat = Eingaben::erfasse_int("Bitte den Monat eingeben:   ", 1, 12);
    jahr = Eingaben::erfasse_int("Bitte das Jahr eingeben:    ", 1583, INT_MAX);
    eingabe_ok = datum.datum_ok(tag, monat, jahr);
    if (!eingabe_ok)
      cout << "Das Datum ist nicht korrekt." << endl;
  } while (!eingabe_ok);
  datum = Datum(tag, monat, jahr);
  return eingabe;
}
/**Gibt das Datum in der Standardform (TT.MM.JJJJ) in den Ausgabestream aus.
 *
 * @param ausgabe Der Ausgabestream, ueber welches die Ausgabe rausgeht.
 * @param datum Das Datum, welches ausgegeben werden soll.
 * @return Die Ausgabe des Datums in der Standardform (TT.MM.JJJJ).
 */
ostream& operator<<(ostream& ausgabe, const Datum& datum)
{
  ausgabe << datum.liefere_standarddatum();
  return ausgabe;
}
/**Vergleicht zwei Dateb mit einander auf gleichheit.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Sind die Daten gleich (true) oder nicht (false).
 */
bool operator==(const Datum& links, const Datum& rechts)
{
  return links.liefere_tag()   == rechts.liefere_tag()   &&
         links.liefere_monat() == rechts.liefere_monat() &&
         links.liefere_jahr()  == rechts.liefere_jahr();
}
/**Vergleicht zwei Daten mit einander auf ungleichheit.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Sind die beiden Daten ungleich (true) oder nicht (false).
 */
bool operator!=(const Datum& links, const Datum& rechts)
{
  return !(links == rechts);
}
/**Vergleicht ob dieses Datum kleiner als ein anderes Datum ist.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Ist das linke Datum kleiner (true) oder nicht (false).
 */
bool operator<(const Datum& links, const Datum& rechts)
{
  bool jahr_kleiner  = links.liefere_jahr()  <  rechts.liefere_jahr();
  bool jahr_gleich   = links.liefere_jahr()  == rechts.liefere_jahr();
  bool monat_kleiner = links.liefere_monat() <  rechts.liefere_monat();
  bool monat_gleich  = links.liefere_monat() == rechts.liefere_monat();
  bool tag_kleiner   = links.liefere_tag()   <  rechts.liefere_tag();
  return jahr_kleiner ||
         (jahr_gleich && monat_kleiner) ||
         (jahr_gleich && monat_gleich && tag_kleiner);
}
/**Vergleicht ob dieses Datum kleiner-gleich als ein anderes Datum ist.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Ist das linke Datum kleiner-gleich (true) oder nicht (false).
 */
bool operator<=(const Datum& links, const Datum& rechts)
{
  return links < rechts || links == rechts;
}
/**Vergleicht ob dieses Datum groesser als ein anderes Datum ist.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Ist das linke Datum groesser (true) oder nicht (false).
 */
bool operator>(const Datum& links, const Datum& rechts)
{
  return !(links <= rechts);
}
/**Vergleicht ob dieses Datum groesser-gleich als ein anderes Datum ist.
 *
 * @param links   Ein Datum.
 * @param rechts  Ein zum Vergleich herangezogenes Datum.
 * @return Ist das linke Datum groesser-gleich (true) oder nicht (false).
 */
bool operator>=(const Datum& links, const Datum& rechts)
{
  return links > rechts || links == rechts;
}
/**Liefert ein zufaelliges Datum aus dem Bereich von min_jahr bis max_jahr.
 *
 * @param min_jahr  Das min. Jahr des Datums.
 * @param max_jahr  Das max. Jahr des Datums.
 * @return Ein zufaelliges Datum aus dem Bereich von min_jahr bis max_jahr.
 */
Datum liefere_zufalls_datum(int min_jahr, int max_jahr)
{
  int tag = 0;
  int jahr = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(min_jahr, max_jahr);
  int monat = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 12);
  Datum vergleichsdatum(1, 1, 1583);
  Datum zufallsdatum;
  bool datum_ok = false;
  do
  {
    tag =  Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 31);
    zufallsdatum = Datum(tag, monat, jahr);
    if (tag == 1 && monat == 1 && jahr == 1583)
      datum_ok = true;
    else
      datum_ok = (zufallsdatum != vergleichsdatum);
  } while (!datum_ok);
return zufallsdatum;
}
/**Sortiert ein Datum-Array absteigen nach dem Datum.
 *
 * @param array   \c Input:  \n Das Datum-Array, welches sortiert werden soll.\n
 *                \c Output: \n Das Datum-Array, welches sortiert wurde.\n
 * @param laenge  Die Laenge des Arrays.
 */
void sortiere(Datum array[], int laenge)
{
  int index_max = 0;
  Datum ablage;
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
