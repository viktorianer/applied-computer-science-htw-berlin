/* 
 * File:   bruchrechner.h
 * Created on 23. Mai 2011, 14:29
 */
#ifndef BRUCHRECHNER_H
#define BRUCHRECHNER_H
// include(s) oder
#include <iostream>
#include <iomanip>

#include "bruch.h"
#include "sortierung.h"
// weitere Angaben
using namespace std;

class Bruchrechner
{
  // Attribute
  private:
    Bruch erster_bruch;
    Bruch zweiter_bruch;
    string op;
    Bruch ergebnis;
  // Konstruktoren
  public:
    Bruchrechner();
    Bruchrechner(const Bruch& der_erster_bruch, const Bruch& der_zweiter_bruch, const string der_operator);
  // Methoden
    void schreibe_ergebnis();
  private:
    void rechne();
};
// eventuell Deklaration
// weiterer Funktionen
void vergleiche_zwei_brueche(const Bruch& der_erster_bruch, const Bruch& der_zweiter_bruch);
void liefere_zufaellige_brueche(const Bruch& min, const Bruch& max, Bruch zufallsbrueche[], int anzahl);
void schreibe_zufaellige_brueche_aufsteigend(Bruch zufallsbrueche[], int anzahl);
void schreibe_zufaellige_brueche_absteigend(Bruch zufallsbrueche[], int anzahl);

#endif  /* BRUCHRECHNER_H */
