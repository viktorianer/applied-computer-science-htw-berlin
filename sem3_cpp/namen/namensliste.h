#ifndef NAMENSLISTE_H
#define NAMENSLISTE_H

// include(s) oder
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "zufallsgenerator.h"
#include "dateimanager.h"
#include "name.h"
// weitere Angaben
using namespace std;

class Namensliste
{
  // Attribute
private:
  /** Vornamen-Liste mit weiblichen Vornamen. */
  vector<string> vornamen_w;
  /** Vornamen-Liste mit maennlichen Vornamen. */
  vector<string> vornamen_m;
  /** Nachnamen-Liste. */
  vector<string> nachnamen;
public:
  // Konstruktoren
  Namensliste();
  Namensliste(const Namensliste& original);
  Namensliste & operator=(const Namensliste& eine_namensliste);
  virtual ~Namensliste();
  // Methoden
  Name liefere_zufalls_namen(const char geschlecht) const;
  string liefere_zufalls_vorname_w() const;
  string liefere_zufalls_vorname_m() const;
  string liefere_zufalls_nachname() const;
};
// eventuell Deklaration
// weiterer Funktionen

#endif  /* NAMENSLISTE_H */
