#ifndef ORT_H
#define ORT_H
// include(s) oder
#include <string>
#include <iostream>

#include "land.h"
// weitere Angaben
using namespace std;

class Ort
{
private:
  // Attribute
  /** Der Name des Ortes. */
  string ortsname;
  /** Das Land, in dem der Ort liegt. */
  Land land;
public:
  // Konstruktoren
  Ort();
  Ort(const string ein_ortsname);
  Ort(const string ein_landesname, const string ein_ortsname);
  virtual ~Ort();
  Ort(const Ort& original);
  Ort& operator=(const Ort& ein_ort);
  // Methoden
  string liefere_ortsname() const;
  virtual string liefere_ortsbeschreibung() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* ORT_H */
