/* 
 * File:   statistik.h
 * Created on 2. Juni 2011, 13:49
 */
#ifndef STATISTIK_H
#define STATISTIK_H
// include(s) oder

// weitere Angaben
using namespace std;

class Statistik
{
  // Attribute
public:
  static bool ist_zahl_im_array(const int *array, int laenge, int gesuchte_zahl);
  static const int *liefere_min(const int *array, int laenge);
  static const int *liefere_max(const int *array, int laenge);
  static const long double *liefere_max(const long double *array, int laenge);
  static const double *liefere_max(const double *array, int laenge);
  static void haeufigkeitsverteilung(const int *array, int laenge, int *haeufigkeitsverteilung);
  static void haeufigkeitsverteilung_minima(const int *array, int laenge, int *minima);
  static void haeufigkeitsverteilung_maxima(const int *array, int laenge, int *maxima);
  static bool sind_alle_zahlen_gerade(const int *array, int laenge);
  static bool sind_alle_zahlen_ungerade(const int *array, int laenge);
  // Methoden
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* STATISTIK_H */
