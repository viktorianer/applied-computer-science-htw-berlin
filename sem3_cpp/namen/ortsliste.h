
#ifndef ORTSLISTE_H
#define ORTSLISTE_H

// include(s) oder
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "zufallsgenerator.h"
#include "dateimanager.h"
#include "ort.h"
#include "postanschrift.h"
// weitere Angaben
using namespace std;

class Ortsliste
{
  // Attribute
private:
  /** Landesnamen-Liste. */
  vector<string> landesnamen;
  /** Postleitzahlen- und Ortsnamen-Liste. */
  vector<string> ortsnamen;
  /** Strassen-Liste. */
  vector<string> strassen;
public:
  // Konstruktoren
  Ortsliste();
  Ortsliste(const Ortsliste& original);
  Ortsliste & operator=(const Ortsliste& eine_ortsliste);
  virtual ~Ortsliste();
  // Methoden
  Ort liefere_zufalls_ort() const;
  Ort liefere_zufalls_ort(const string landesname) const;
  Postanschrift liefere_zufalls_postanschrift() const;
  Postanschrift liefere_zufalls_postanschrift(const string landesname) const;
  string liefere_zufalls_landesname() const;
  string liefere_zufalls_postleitzahl() const;
  string liefere_zufalls_ortsname() const;
  string liefere_zufalls_strasse() const;
  string liefere_zufalls_strassennr() const;
};
// eventuell Deklaration
// weiterer Funktionen

#endif  /* ORTSLISTE_H */
