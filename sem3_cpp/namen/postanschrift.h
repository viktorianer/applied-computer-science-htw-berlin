#ifndef POSTANSCHRIFT_H
#define POSTANSCHRIFT_H
// include(s) oder
#include <string>

#include "ort.h"
// weitere Angaben
using namespace std;

class Postanschrift
{
private:
  // Attribute
  /** Die Strasse der Postanschrift. */
  string strasse;
  /** Die Hausnummer der Postanschrift. */
  string hausnummer;
  /** Die PLZ der Postanschrift. */
  string postleitzahl;
  /** Der Ort dieser Postanschrift. */
  Ort ort;
public:
  // Konstruktoren
  Postanschrift();
  Postanschrift(const string die_strasse, const string eine_hausnummer,const string die_postleitzahl);
  Postanschrift(const string ein_ortsname,
    const string die_strasse, const string eine_hausnummer,const string die_postleitzahl);
  Postanschrift(const string ein_landesname, const string ein_ortsname,
    const string die_strasse, const string eine_hausnummer,const string die_postleitzahl);
  Postanschrift(Ort ein_ort, const string die_strasse, const string eine_hausnummer,const string die_postleitzahl);
  virtual ~Postanschrift();
  Postanschrift(const Postanschrift& original);
  Postanschrift& operator=(const Postanschrift& eine_postanschrift);
  // Methoden
  string liefere_strasse() const;
  string liefere_hausnummer() const;
  string liefere_postleitzahl() const;
  virtual string liefere_ortsbeschreibung() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* POSTANSCHRIFT_H */
