/* 
 * File:   spieler.h
 * Created on 15. Juni 2011, 14:07
 */
#ifndef SPIELER_H
#define SPIELER_H

#include "kartenstapel.h"
#include "eingaben.h"
#include "menue.h"

// include(s) oder

// weitere Angaben
using namespace std;

class Spieler
{
  // Attribute
  private:
    /** Die Karten des Spielers, die er spielen kann. */
    Kartenstapel *karten;
    /** Der Nickname des Spielers. */
    string nickname;
    /** Ist Mensch- (true) oder KI-Spieler (false). */
    bool ist_mensch;
    // Konstruktoren
  public:
    Spieler();
    Spieler(const Kartenstapel& die_karten, const string ein_nickname, bool ein_mensch);
    ~Spieler();
    Spieler(const Spieler& original);
    Spieler& operator=(const Spieler& ein_spieler);
    // Methoden
    string liefere_nickname() const;
    bool liefere_ob_mensch() const;
    int liefere_anzahl_karten() const;
    int liefere_anzahl_augen() const;
    string liefere_karten_info(unsigned int index) const;
    Kartenstapel *liefere_karten() const;
    virtual Karte spiele_karte(const Karte& karte_auf_ablage);
    int hat_passende_karten(const Karte& eine_karte) const;
    int hat_passende_wunsch_karten(const Karte& eine_wunsch_karte) const;
    int hat_sieben() const;
    int hat_ass() const;
    void nimm_karte(const Karte& eine_karte);
    
    
    virtual string liefere_wunschfarbe() const;
  private:
    virtual Karte spiele_passende_karte(const Karte& eine_karte);
    virtual Karte spiele_wunsch_karte(const Karte& eine_wunsch_karte);
    virtual Karte spiele_sieben();
    virtual Karte spiele_ass();
    int waehle_karte(const vector<Karte>& passende_karten) const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* SPIELER_H */
