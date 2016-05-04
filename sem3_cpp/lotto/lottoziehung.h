/* 
 * File:   lottoziehung.h
 * Created on 2. Juni 2011, 10:58
 */
#ifndef LOTTOZIEHUNG_H
#define LOTTOZIEHUNG_H
// include(s) oder
#include <iostream>
#include <cstdlib>

#include "zufallsgenerator.h"
#include "statistik.h"
#include "utilities.h"
#include "arrays.h"
// weitere Angaben
using namespace std;

class Lottoziehung
{
  // Attribute
  private:
    /** Die Anzahl der Zahlen einer Lottoziehung. */
    int anzahl_lottozahlen;
    /** Die Lottoziehung, die die Zahlen enthaelt. */
    int *lottoziehung;
  // Konstruktoren
  public:
    Lottoziehung();
    Lottoziehung(int min, int max);
    Lottoziehung(const int *eine_ziehung);
    ~Lottoziehung();
    Lottoziehung(const Lottoziehung& original);
    Lottoziehung& operator=(const Lottoziehung& eine_lottoziehung);
  // Methoden
    void schreibe_lottozahlen() const;
    void haeufigkeitsverteilung(int *haeufigkeitsverteilung) const;
    void haeufigkeitsverteilung_minima(int *minima) const;
    void haeufigkeitsverteilung_maxima(int *maxima) const;
    bool zahl_in_lottoziehung(int gesuchte_zahl) const;
    bool sind_alle_zahlen_gerade() const;
    bool sind_alle_zahlen_ungerade() const;
    int laenge_lottoziehung() const;
    int zahlenpaar();
    int vergleiche_lottoziehung(const Lottoziehung& eine_lottoziehung) const;
  private:
    void initialisiere_lottozahlen(int min, int max);
    void initialisiere_lottozahlen(const int *lottozahlen);
    bool pruefe_lottozahlen(const int *lottozahlen) const;
};
// eventuell Deklaration
// weiterer Funktionen

#endif  /* LOTTOZIEHUNG_H */
