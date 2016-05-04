#include <iomanip>
#include <iostream>
#include "preis.h"
void schreibe_preis_info(const Preis& preis);
void schreibe_zeile(const string info, double wert);

int main()
{
  cout << "Der Mehrwertsteuersatz betraegt "
    << static_cast<int>(100 * Preis::MWST_SATZ) << " Prozent:" << endl << endl;
  
  Preis array[] = {Preis(19990.50), Preis(13.99), Preis(455.10)};
  int anzahl = sizeof(array) / sizeof(array[0]);
  for (int i = 0; i < anzahl; i++)
  {
    schreibe_preis_info(array[i]);
    cout << endl;
  }

  return 0;
}
void schreibe_preis_info(const Preis& preis)
{
  schreibe_zeile("Preis:", preis.liefere_brutto_preis());
  schreibe_zeile("Mehrwertsteueranteil:", preis.liefere_mwst_anteil());
  schreibe_zeile("Nettopreis:", preis.liefere_netto_preis());
}
void schreibe_zeile(const string info, double wert)
{
  cout << setw(25) << left << info << setw(10) << right
       << setprecision(2) << fixed << wert << " Euro" << endl;
}