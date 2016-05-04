/* 
 * File:   bruch.h
 * Created on 22. Mai 2011, 15:14
 */
#ifndef BRUCH_H
#define BRUCH_H
// include(s) oder
#include <iostream>
#include <cmath>
#include <sstream>

#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;

class Bruch
{
  // Attribute
  private:
    /** Der Zaehler des Bruches. */
    int zaehler;
    /** Der Nenner des Bruches. */
    int nenner;
  // Konstruktoren
  public:
    Bruch();
    Bruch(int der_zaehler, int der_nenner);
    Bruch(const Bruch& ein_bruch);
    Bruch(const Bruch& die_linke_grenze, const Bruch& die_rechte_grenze);
  // Methoden
    int liefere_zaehler() const;
    int liefere_nenner() const;
    string liefere_bruch_als_text();
    void kuerze_bruch();
    Bruch operator+(const Bruch& bruch) const;
    Bruch operator-(const Bruch& bruch) const;
    Bruch operator*(const Bruch& bruch) const;
    Bruch operator/(const Bruch& bruch) const;
    bool operator==(const Bruch& bruch) const;
    bool operator<(const Bruch& bruch) const;
    bool operator>(const Bruch& bruch) const;
  private:
    void setze_zaehler(int der_zaehler);
    void setze_nenner(int der_nenner);
    void formatiere_bruch();
    int kleinstes_gemeinsames_vielfaches(int zahl_a, int zahl_b) const;
    int groesster_gemeinsamer_teiler(int zahl_a, int zahl_b) const;
    void liefere_zufallsbruch(const Bruch& min, const Bruch& max);
};
// eventuell Deklaration
// weiterer Funktionen
void sortiere_aufsteigend(Bruch array[], int laenge);
void sortiere_absteigend(Bruch array[], int laenge);

#endif  /* BRUCH_H */
