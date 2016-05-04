/* 
 * File:   konto.h *
 * Created on 16. Mai 2011, 12:59
 */
#ifndef KONTO_H
#define KONTO_H
// include(s) oder
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;

class Konto
{
  // Attribute
  private:
    /** Die sechsstellige Kontonummer. Darf nur zwischen 100.000 und 999.999 liegen. */
    int kontonummer;
    /** Der aktuelle Kontostand. Kann maximal bis zum Ueberweisungskredit ins Negative gehen. */
    double kontostand;
    /** Der Ueberweisungskredit, der bei einer Ueberweisung nicht ueberzogen werden darf. */
    double ueberweisungskredit;
  // Konstruktoren
  public:
    Konto();
    Konto(int kontonummer);
  // Methoden
    int liefere_kontonummer() const;
    double liefere_kontostand() const;
    void einzahlung(double geldsumme);
    double auszahlung(double geldsumme);
    double liefere_ueberweisungskredit() const;
    bool pruefe_kreditrahmen(double geldssumme) const;
  private:
    double liefere_zufaelligen_kontostand();
    double liefere_zufaelligen_ueberweisungskredit();
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* KONTO_H */
