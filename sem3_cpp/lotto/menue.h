/* 
 * File:   menue.h
 * Created on 1. Juni 2011, 16:14
 */
#ifndef MENUE_H
#define MENUE_H
// include(s) oder
#include <iostream>

#include "eingaben.h"
// weitere Angaben
using namespace std;

class Menue
{
  // Attribute
  private:
    /** Anzahl der Menuepunkte */
    int anzahl_menuepunkte;
    /** Die Menuepunkte.*/
    string *menuepunkte;
    // Konstruktoren
  public:
    Menue();
    Menue(int menuelaenge, const string *menuepunkte);
    ~Menue();
    Menue(const Menue& original);
    Menue & operator=(const Menue& ein_menue);
    // Methoden
    int waehle_aus_menue() const;
    void schreibe_menue() const;
  private:
    void initialisiere_menuepunkte(const string *die_menuepunkte);
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* MENUE_H */
