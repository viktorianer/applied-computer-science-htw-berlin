/*
 * File:   kartenstapel.h
 * Created on 15. Juni 2011, 14:12
 */
#ifndef KARTENSTAPEL_H
#define KARTENSTAPEL_H
// include(s) oder
#include <string>
#include <vector>
#include <iostream>

#include "karte.h"
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;
typedef std::vector<Karte>::iterator stapeliterator;

class Kartenstapel
{
  // Attribute
  private:
    /** Ein Kartenstapel, z.B. mit Skatblatt aus 32 Karten.
     * Das franzoesische Blatt besteht aus den vier Farben Kreuz, Pik, Herz und Karo, jeweils mit den Karten Sieben, Acht, Neun, Zehn, Bube, Dame, Koenig und Ass.
     */
    vector<Karte> stapel;
    // Konstruktoren
  public:
    Kartenstapel();
    Kartenstapel(const Karte& eine_karte);
    Kartenstapel(const vector<Karte>& ein_kartenstapel);
    ~Kartenstapel();
    Kartenstapel(const Kartenstapel& original);
    Kartenstapel& operator=(const Kartenstapel& ein_kartenstapel);
    // Methoden
    int liefere_anzahl_karten() const;
    int liefere_anzahl_augen() const;
    void schreibe_karten() const;
    string liefere_karten_info(unsigned int index) const;
    string liefere_karten_farbe(unsigned int index) const;
    void fuege_karte_hinzu(const Karte& eine_karte);
    const Karte& obere_karte_ist() const;
    Karte liefere_obere_karte();
    const Karte& untere_karte_ist() const;
    Karte liefere_untere_karte();
    int hat_passende_karten(const Karte& eine_karte) const;
    Karte liefere_passende_karte(const Karte& eine_karte);
    vector<Karte> liefere_alle_passende_karte(const Karte& eine_karte) const;
    int hat_passende_wunsch_karten(const Karte& eine_wunsch_karte) const;
    Karte liefere_wunsch_karte(const Karte& eine_wunsch_karte);
    vector<Karte> liefere_wunsch_karten(const Karte& eine_wunsch_karte) const;
    Karte liefere_bestimmte_karte(const Karte& die_karte);
    int hat_sieben() const;
    Karte liefere_sieben();
    vector<Karte> liefere_alle_sieben() const;
    int hat_ass() const;
    Karte liefere_ass();
    vector<Karte> liefere_alle_asse() const;
    void mische_kartenstapel();
  private:
    void initialisiere_karten();
    void initialisiere_karten(const vector<Karte>& neue_karten);
};
// eventuell Deklaration
// weiterer Funktionen
Kartenstapel& operator<<(Kartenstapel& zielstapel, Kartenstapel& quellestapel);
#endif  /* KARTENSTAPEL_H */
