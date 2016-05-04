/* 
 * File:   simulator.h
 * Created on 18. Mai 2011, 08:16
 */
#ifndef SIMULATOR_H
#define SIMULATOR_H
// include(s) oder
#include <iostream>
#include <sstream>
#include <iomanip>

#include "konto.h"
#include "ueberweisung.h"
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;

class Geldueberweisungensimulator
{
  // Attribute
  private:
    /** n Konten mit zufälligem Kontostand und Überziehungskredit erzeugt */
    Konto *konten;
    /** Die Anzahl der Konten (n) */
    int kontenanzahl;
    /** Die Anzahl der Ueberweisungen (m) */
    int ueberweisungenanzahl;
    /** m Überweisungen, wobei m jeweils aus dem Bereich von 7 * n bis 12 * n zufällig gewählt wird.*/
    Ueberweisung *ueberweisungen;
    /** Die Anzahl der simulierten Tage */
    int anzahl_sim_tage;
  // Konstruktoren
  public:
    Geldueberweisungensimulator(int anzahl_konten);
  // Methoden
    void simuliere_ueberweisungen_fuer_ein_tag();
    double liefere_gesamtbestand() const;
    int liefere_anzahl_ueberweisungen() const;
    double liefere_gesamtvolumen() const;
    double liefere_ueberweisungen_durchschnitt() const;
  private:
    void simuliere_ueberweisungen();
    Konto *liefere_hoechsten_kontostand() const;
    Konto *liefere_niedrigsten_kontostand() const;
    Ueberweisung *liefere_groesste_ueberweisung() const;
    Ueberweisung *liefere_kleinste_ueberweisung() const;
    void schreibe_kontenuebersicht() const;
    void schreibe_ueberweisungenuebersicht() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* SIMULATOR_H */
