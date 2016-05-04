/*
 * File:   spieler.h
 * Created on 15. Juni 2011, 14:07
 */
#ifndef KISPIELER_H
#define KISPIELER_H

#include "kartenstapel.h"
#include "spieler.h"

// include(s) oder

// weitere Angaben
using namespace std;

class KISpieler: public Spieler
{
  // Attribute
  private:
    // Konstruktoren
  public:
    KISpieler();
    KISpieler(const Kartenstapel& die_karten, const string ein_nickname, bool eine_mensch);
    ~KISpieler();
    KISpieler(const KISpieler& original);
    KISpieler & operator=(const KISpieler& ein_spieler);
    // Methoden
    virtual Karte spiele_karte(const Karte& karte_auf_ablage);
    virtual string liefere_wunschfarbe() const;
  private:
    virtual Karte spiele_passende_karte(const Karte& eine_karte);
    virtual Karte spiele_wunsch_karte(const Karte& eine_wunsch_karte);
    virtual Karte spiele_sieben();
    virtual Karte spiele_ass();
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* KISPIELER_H */
