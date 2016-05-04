/* 
 * File:   lotto_generator.h
 * Created on 2. Juni 2011, 10:40
 */
#ifndef LOTTOGENERATOR_H
#define LOTTOGENERATOR_H
// include(s) oder
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "lottoziehung.h"
#include "statistik.h"
#include "utilities.h"
#include "arrays.h"
// weitere Angaben
using namespace std;

class Lottogenerator
{
  // Attribute
private:
  /** Die Anzahl n der Lottoziehungen. */
  int anzahl_lottoziehungen;
  /** Ein Vektor von n Lottoziehungen, die generiert wurden. */
  vector<Lottoziehung> lottoziehungen;
  /** Die kleinste Zahl in der Lottoziehung. */
  int min;
  /** Die groesste Zahl in der Lottoziehung. */
  int max;
  /** Die Anzahl der Lottozahlen in einer Lottoziehung. */
  int anzahl_lottozahlen;
  // Konstruktoren
public:
  Lottogenerator();
  Lottogenerator(int die_anzahl_lottoziehungen);
  ~Lottogenerator();
  Lottogenerator(const Lottogenerator& original);
  Lottogenerator& operator=(const Lottogenerator& ein_lottogenerator);
  // Methoden
  int liefere_anzahl_lottoziehungen() const;
  void schreibe_lottoziehungen() const;
  void wieviele_jahre_und_monate() const;
  void statistik_haeufigkeitsverteilung() const;
  void statistik_minima() const;
  void statistik_maxima() const;
  void statistik_laengen() const;
  void statistik_laenge_ist_gezogene_zahl() const;
  void statistik_lottoziehungen_sind_gerade() const;
  void statistik_lottoziehungen_sind_ungerade() const ;
  void statistik_lottoziehungen_zahlenpaare();
  void lottotipp_eingabe() const;
  void lottotipp_durch_ai() const;
  void erzeueg_neu_lottoziehungen(int anzahl);
private:
  void schreibe_statistik_lottotipp_eingabe(const Lottoziehung lottotipp_eingabe) const;
  void initialisiere_lottoziehungen();
  void initialisiere_lottoziehungen(const vector<Lottoziehung> die_lottoziehungen);
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* LOTTOGENERATOR_H */
