/* 
 * File:   karte.h
 * Created on 15. Juni 2011, 13:53
 */
#ifndef KARTE_H
#define KARTE_H
// include(s) oder
#include <string>
#include <iostream>
// weitere Angaben
using namespace std;

class Karte
{
  // Attribute
private:
  /** Franzoesisches Blatt, Skat: 32 Blatt, Kartenwerte 7...10, Bube, Dame, Koenig, Ass. */
  string kartenwert;
  /** Franzoesisches Blatt. Es hat die Farbwerte Kreuz, Pik, Herz, Karo */
  string kartenfarbe;
  /** Beim Farbspiel und Grand sind fuer das Spielergebnis die Augen der Karten massgeblich.
   * Jede Partei zaehlt nach dem Spiel die Augen zusammen. Das As zaehlt elf Augen, die 10 zÃ¤hlt zehn Augen, der Koenig vier, die Dame drei und der Bube zwei Augen.
   * Die uebrigen (9, 8, 7), die auch Luschen genannt werden, zaehlen nichts.
   */
  int augen;
  // Konstruktoren
public:
  Karte();
  Karte(const string der_kartenwert, const string die_kartenfarbe);
  ~Karte();
  Karte(const Karte& original);
  Karte & operator=(const Karte& eine_karte);
  // Methoden
  string liefere_kartenwert() const;
  string liefere_kartenfarbe() const;
  int liefere_augen() const;
  string liefere_karten_info() const;
  bool operator==(const Karte& eine_karte) const;
private:
  void initialisiere_augen();
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* KARTE_H */
