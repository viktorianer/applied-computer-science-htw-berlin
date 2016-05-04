#ifndef PERSON_H
#define PERSON_H
// include(s) oder
#include <iostream>
#include <iomanip>

#include "name.h"
#include "datum.h"
#include "ort.h"
#include "postanschrift.h"
#include "beschreibbar.h"
// weitere Angaben
using namespace std;

class Person : public Beschreibbar
{
private:
  // Attribute
  /** Der Name einer Person, bestehend aus Vornamen und Nachnamen. */
  Name name;
  /** Der Geburtstag, d.h. ein Datum, der Person. */
  Datum geburtstag;
  /** Der Geschlecht der Person (w fuer weiblich oder m fuer maennlich) */
  char geschlecht;
  /** Der Geburtsort, d.h. Ort und Land. */
  Ort geburtsort;
  /** Die Nationalitaet der Person. */
  string nationalitaet;
  /** Die Wohnanschrift, d.h. Strasse, Nummer, PLZ, Ort und Land. */
  Postanschrift wohnanschrift;
  /** Die Telefonnummer der Person. */
  string telefonnummer;
  // Konstruktoren
public:
  Person();
  Person(const Name& der_name, const Datum& der_geburtstag);
  Person(const Name& der_name, const Datum& der_geburtstag, const char das_geschlecht);
//  Person(const Name& der_name);
//  Person(const string& der_vorname, const string& der_nachname);
//  Person(const string& der_vorname, const string& der_mittelname, const string& der_nachname);
  Person(const Name& der_name, int der_tag, int der_monat, int das_jahr);
//  Person(const string& der_vorname, const string& der_nachname, int der_tag, int der_monat, int das_jahr);
//  Person(const string& der_vorname, const string& der_mittelname, const string& der_nachname,
//          int der_tag, int der_monat, int das_jahr);
  Person(Name der_name, Datum der_geburtstag, const char das_geschlecht, Ort der_geburtsort,
            const string die_nationalitaet, Postanschrift die_wohnanschrift, const string die_telefonnummer);
  virtual ~Person();
  Person(const Person& original);
  Person& operator=(const Person& eine_person);
  // Methoden
  Name liefere_den_namen() const;
  string liefere_rufnamen() const;
  string liefere_vornamen() const;
  string liefere_nachnamen() const;
  string liefere_namen() const;
  int liefere_anzahl_vornamen() const;
  int liefere_anzahl_nachnamen() const;
  Datum liefere_den_geburtstag() const;
  string liefere_geburtstag() const;
  int liefere_jahrgang() const;
  string liefere_geburtsort() const;
  void aendere_nachnamen(const string& der_neue_nachname);
  void aendere_nachnamen(const string *die_nachnamen, int anzahl_nachnamen);
  void setze_geburtstag(int der_tag, int der_monat, int das_jahr);
  void setze_geburtstag(const Datum& der_geburtstag);
  virtual void schreibe_informationen() const;
};
// eventuell Deklaration
// weiterer Funktionen
bool operator==(const Person& links, const Person& rechts);
bool operator!=(const Person& links, const Person& rechts);
bool operator<(const Person& links, const Person& rechts);
bool operator<=(const Person& links, const Person& rechts);
bool operator>(const Person& links, const Person& rechts);
bool operator>=(const Person& links, const Person& rechts);
void sortiere(Person array[], int laenge);
void sortiere(Person array[], int laenge, int (*vergleiche)(const Person&, const Person&));
int vergleiche_personen_comp(const Person* links, const Person* rechts);
int vergleiche_nach_alter_comp(const Person* links, const Person* rechts);
int vergleiche_nach_jahrgang_comp(const Person* links, const Person* rechts);
bool vergleiche_personen(Person* links, Person* rechts);
bool vergleiche_nach_alter(Person* links, Person* rechts);
bool vergleiche_nach_jahrgang(Person* links, Person* rechts);

#endif  /* PERSON_H */
