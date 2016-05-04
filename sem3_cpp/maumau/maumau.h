/* 
 * File:   maumau.h
 * Created on 15. Juni 2011, 13:55
 */
#ifndef MAUMAU_H
#define MAUMAU_H
// include(s) oder
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "spieler.h"
#include "kispieler.h"
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;

class Maumau
{
  // Attribute
  private:
    /**Initialisiert den Kartenstapel mit Skatblatt aus 32 Karten.
     * Das franzoesische Blatt besteht aus den vier Farben Kreuz, Pik, Herz und Karo, jeweils mit den Karten Sieben, Acht, Neun, Zehn, Bube, Dame, Koenig und Ass.
     */
    Kartenstapel talon;
    /** Die Karten, die gespielt wurden (Ueblig ist zu Beginn die erste Karte vom Talon). */
    Kartenstapel ablage;
    /** Die KI-Spieler oder menschlicher Spieler, die das Spiel spielen sollen. */
    vector<Spieler *> spieler;
    /** Anzahl der Spielrunden, die gespielt wurden. */
    int anzahl_durchlaeufe;
    /** Anzahl der hintereinander gespielten Sieben-Karten. */
    int anzahl_gespielter_sieben;
    /** Anzahl der hintereinander gespielten Ass-Karten. */
    int anzahl_gespielter_asse;
    /** Die gewuenschte Farbe, die durch eine Bube-Karte mit der entsprechenden Kartenfarbe dargestellt wird. */
    Karte wunschkarte;
    /** Wurde eine neue Farbe gewuenscht oder nicht. */
    bool wunsch;
    // Konstruktoren
  public:
    Maumau();
    Maumau(int anzahl_mensch_spieler);
    ~Maumau();
    Maumau(const Maumau& original);
    Maumau & operator=(const Maumau& ein_maumau_spiel);
    // Methoden
    void starte_spiel();
  private:
    void mische_talon();
    void initialisiere_ablage();
    void initialisiere_spieler(int anzahl_mensch_spieler, int anzahl_kispieler, int anzahl_karten);
    void initialisiere_kispieler(int anzahl_kispieler, int anzahl_karten);
    void keine_passende_karte(int der_spieler);
    bool spieler_spielt_karte(unsigned int der_spieler);
    void spieler_nimmt_karten(unsigned int der_spieler);
    void neuen_talon_mischen();
    void schreibe_spielsituation() const;
    void schreibe_situation_spieler() const;
    void schreibe_situation_ablage_talon() const;
    void schreibe_situation_ende() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* MAUMAU_H */
