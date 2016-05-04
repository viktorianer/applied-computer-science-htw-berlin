#ifndef LAND_H
#define LAND_H
// include(s) oder
#include <string>
// weitere Angaben
using namespace std;

class Land
{
private:
  // Attribute
  /** Der Name des Landes */
  string landesname;
public:
  // Konstruktoren
  Land();
  Land(const string ein_landesname);
  virtual ~Land();
  Land(const Land& original);
  Land & operator=(const Land& ein_land);
  // Methoden
  string liefere_landesname() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* LAND_H */
