/* 
 * File:   ueberweisung.h
 * Created on 17. Mai 2011, 09:27
 */
#ifndef UEBERWEISUNG_H
#define UEBERWEISUNG_H
// include(s) oder
#include <iostream>
#include <sstream>

#include "konto.h"
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;

class Ueberweisung
{
  // Attribute
  private:
    /** Das Konto, von dem das Geld kommt. */
    Konto *quellkonto;
    /** Das Konto, auf das das Geld ueberwiesen wird. */
    Konto *zielkonto;
    /** Das Volumen der Ueberweisung.
     * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
     * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
     * wird (Überziehungskredit berücksichtigen). */
    double volumen;
  // Konstruktoren
  public:
    Ueberweisung();
    Ueberweisung(Konto *das_quellkonto, Konto *das_zielkonto);
  // Methoden
    double liefere_ueberweisungsvolumen() const;
    string liefere_ueberweisungsinfo() const;
  private:
    void simuliere_ueberweisung();
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* UEBERWEISUNG_H */
