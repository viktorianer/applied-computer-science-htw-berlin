/* 
 * File:   preis.h
 * Created on 15. Juni 2011, 09:51
 */
#ifndef PREIS_H
#define PREIS_H
// include(s) oder
#include <iomanip>
// weitere Angaben
using namespace std;

class Preis
{
  // Attribute
  public:
    const static double MWST_SATZ;
  private:
    double brutto_preis;
  public:
    Preis();
    Preis(double preis);
    ~Preis();
    Preis(const Preis& original);
    Preis & operator=(const Preis& ein_preis);
    // Methoden
    double liefere_mwst_anteil() const;
    double liefere_brutto_preis() const;
    double liefere_netto_preis() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* PREIS_H */
