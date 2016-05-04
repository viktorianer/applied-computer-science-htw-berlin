#include "datum.h"
// weitere Angaben
// Code der Konstruktoren
Datum::Datum()
{
  time_t zeit = time(0);
  struct tm *p = localtime(&zeit);
  tag = p->tm_mday;
  monat = (p->tm_mon) + 1;
  jahr = (p->tm_year) + 1900;
}
Datum::Datum(int tag, int monat, int jahr)
{
  if (datum_ok(tag, monat, jahr))
    initialisiere_datum(tag, monat, jahr);
  else
    initialisiere_datum();
}

// Code der Methoden
int Datum::liefere_tag() const
{
  return tag;
}
int Datum::liefere_monat() const
{
  return monat;
}
int Datum::liefere_jahr() const
{
  return jahr;
}

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
string Datum::liefere_wochentag() const
{
  string name[] = {"Samstag", "Sonntag", "Montag", "Dienstag",
                   "Mittwoch", "Donnerstag", "Freitag"};
  return name[liefere_tage() % 7];
}
string Datum::liefere_wochentagdatum() const
{
  string datumstext = liefere_wochentag();
  datumstext += ", ";
  datumstext += liefere_textdatum();
  return datumstext;
}
Datum Datum::operator+(int tage) const
{
  long  anzahl_tage = liefere_tage();
  anzahl_tage += tage;
  return liefere_datum(anzahl_tage);
}
int Datum::operator-(const Datum& ein_datum) const
{
  return liefere_tage() - ein_datum.liefere_tage();
}
Datum& Datum::operator++()
{
  *this = *this + 1;
  return *this;
}
Datum Datum::operator++(int)
{
  Datum altes_datum = *this;
  ++*this;
  return altes_datum;
}

void Datum::initialisiere_datum(int der_tag, int der_monat, int das_jahr)
{
  tag   = der_tag;
  monat = der_monat;
  jahr  = das_jahr;
}
bool Datum::datum_ok(int tag, int monat, int jahr) const
{
  return (1583 <= jahr) &&
         (jahr <= INT_MAX) &&
         (1 <= monat) &&
         (monat <= 12) &&
         (1 <= tag) &&
         (tag <= liefere_tage_im_monat(monat, jahr));
}
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
bool Datum::ist_schaltjahr(int jahr) const
{
  return ((jahr % 4 == 0) && ((jahr % 100 != 0) || (jahr % 400 == 0)));
}
int Datum::liefere_tage_im_jahr(int jahr) const
{
  return ist_schaltjahr(jahr) ? 366 : 365;
}
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
ostream& operator<<(ostream& ausgabe, const Datum& datum)
{
  ausgabe << datum.liefere_standarddatum();
  return ausgabe;
}
bool operator==(const Datum& links, const Datum& rechts)
{
  return links.liefere_tag()   == rechts.liefere_tag()   &&
         links.liefere_monat() == rechts.liefere_monat() &&
         links.liefere_jahr()  == rechts.liefere_jahr();
}
bool operator!=(const Datum& links, const Datum& rechts)
{
  return !(links == rechts);
}
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
bool operator<=(const Datum& links, const Datum& rechts)
{
  return links < rechts || links == rechts;
}
bool operator>(const Datum& links, const Datum& rechts)
{
  return !(links <= rechts);
}
bool operator>=(const Datum& links, const Datum& rechts)
{
  return links > rechts || links == rechts;
}
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
