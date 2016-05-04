/* 
 * File:   zufallsgenerator.h
 * Created on 16. Mai 2011, 17:47
 */
#ifndef ZUFALLSGENERATOR_H
#define ZUFALLSGENERATOR_H
// include(s) oder
#include <cstdio>
#include <ctime>
#include <cstdlib>
// weitere Angaben
using namespace std;

class Zufallsgenerator
{
  private:
    // Attribute
    // Konstruktoren
    Zufallsgenerator();   // von außen keine Instanzen erzeugbar
    Zufallsgenerator(const Zufallsgenerator&) {}             // nicht kopierbar
    Zufallsgenerator& operator=(const Zufallsgenerator&) {return *this;}  // nicht zuweisbar
    virtual ~Zufallsgenerator() {}
  public:
    // Methoden
    static Zufallsgenerator& liefere_zufallsgenerator();
    int liefere_ganze_zufallszahl(int min, int max) const;
    double liefere_gleitkomma_zufallszahl(double min, double max) const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* ZUFALLSGENERATOR_H */
