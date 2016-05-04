/* 
 * File:   datum.h
 * Created on 16. Mai 2011, 13:08
 */
#ifndef DATUM_H
#define DATUM_H
#include <climits>              // wegen INT_MAX
#include <ctime>                // wegen time, time_h, localtime und
                                // struct tm
#include <iostream>             // wegen ios::out
#include <sstream>              // wegen ostringstream

#include "eingaben.h"
#include "zufallsgenerator.h"

using namespace std;

class Datum
{
  private:
    /** Der Tag eines Datums. */
    int tag;
    /** Der Monat eines Datums. */
    int monat;
    /** Das Jahr eines Datums. */
    int jahr;
  public:
    Datum();
    Datum(int tag, int monat, int jahr);
    virtual ~Datum();
    Datum(const Datum& original);
    Datum& operator=(const Datum& ein_datum);
    int liefere_tag() const;
    int liefere_monat() const;
    int liefere_jahr() const;
    string liefere_din_datum() const;
    string liefere_standarddatum() const;
    string liefere_textdatum() const;
    string liefere_wochentag() const;
    string liefere_wochentagdatum() const;
    Datum operator+(int tage) const;
    int operator-(const Datum& ein_datum) const;
    friend istream& operator>>(istream& eingabe, Datum& datum);
    Datum& operator++();
    Datum operator++(int);
  private:
    void initialisiere_datum(int der_tag = 1, int der_monat = 1, int das_jahr = 1583);
    bool datum_ok(int tag, int monat, int jahr) const;
    int liefere_tage_im_monat(int monat, int jahr) const;
    int liefere_tage_im_jahr(int jahr) const;
    bool ist_schaltjahr(int jahr) const;
    long liefere_tage() const;
    Datum liefere_datum(long tage) const;
};

istream& operator>>(istream& eingabe, Datum& datum);
ostream& operator<<(ostream& ausgabe, const Datum& datum);
bool operator==(const Datum& links, const Datum& rechts);
bool operator!=(const Datum& links, const Datum& rechts);
bool operator<(const Datum& links, const Datum& rechts);
bool operator<=(const Datum& links, const Datum& rechts);
bool operator>(const Datum& links, const Datum& rechts);
bool operator>=(const Datum& links, const Datum& rechts);
Datum liefere_zufalls_datum(int min_jahr, int max_jahr);
void sortiere(Datum array[], int laenge);

#endif  /* DATUM_H */
