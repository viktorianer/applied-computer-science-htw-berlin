#include <iomanip>
#include <iostream>

#include "datum.h"
#include "zufallsgenerator.h"

using namespace std;

void teste_praefix_inkrement();
void teste_postfix_inkrement();

int main()
{
  Datum heute;
  cout << endl;
  cout << "Das heutige Datum nach DIN:  " << heute.liefere_din_datum() << endl;
  Datum start(9, 4, 2010);
  cout << "Die erste Vorlesung ist am " << start.liefere_tag() << "." << start.liefere_monat() << "."
       << start.liefere_jahr() << "." << endl;
  cout << "Datum in der Standardform " << start.liefere_standarddatum() << endl;
  cout << "Datum in der Textform " << start.liefere_textdatum() << endl;
  cout << endl;

  Datum termin[] = {Datum(13, 6, 2010), Datum(18, 6, 2010),
                    Datum(23, 6, 2010), Datum(11, 6, 2010),
                    Datum(11, 7, 2010)};
  string spiel[] = {"Deutschland - Australien", "Deutschland - Serbien", "Ghana - Deutschland"};
  cout << "Das erste Spiel der Fussball-WM findet am " << termin[3].liefere_standarddatum() << " statt." << endl;
  cout << "Das ist ein " << termin[3].liefere_wochentag() << "." << " (Schlecht fuer die Vorlesung.)" << endl;
  cout << endl << "Die Vorrundenspiele der deutschen Mannschaft:" << endl << endl;
  for (int i = 0; i < 3; i++)
    cout << setw(30) << left << spiel[i] << termin[i].liefere_wochentagdatum() << endl;
  cout << endl << "Das Endspiel ist am " << termin[4].liefere_wochentagdatum() << "." << endl;
  cout << endl;

  cout << "Heute haben wir " << heute.liefere_wochentagdatum() << "." << endl;
  cout << "Vor 10.000 Tagen war " << (heute + -10000).liefere_wochentagdatum() << "." << endl;
  cout << "In 10.000 Tagen ist " << (heute + 10000).liefere_wochentagdatum() << "." << endl;
  Datum morgen = heute + 1;
  cout << "Morgen ist uebrigens " << morgen.liefere_wochentagdatum() << "." << endl;
  cout << endl;

  Datum vorlesungsbeginn_ss(6, 4, 2010);
  Datum vorlesungsende_ss(24, 7, 2010);
  int breite = 30;
  cout << setw(breite) << left << "SS 2010 Vorlesungsbeginn:" << vorlesungsbeginn_ss.liefere_standarddatum() << endl;
  cout << setw(breite) << left << "SS 2010 Vorlesungsende:" << vorlesungsende_ss.liefere_standarddatum() << endl;
  cout << setw(breite) << left << "Tage im Semester:"  << vorlesungsende_ss - vorlesungsbeginn_ss << endl;
  cout << endl;
  Datum vorlesungsbeginn_ws(1, 10, 2010);
  Datum vorlesungsende_ws(12, 2, 2011);
  cout << setw(breite) << left << "WS 2010 Vorlesungsbeginn:" << vorlesungsbeginn_ws << endl;
  cout << setw(breite) << left << "WS 2010 Vorlesungsende:" << vorlesungsende_ws << endl;
  cout <<  setw(breite) << left << "Tage im Semester:" << vorlesungsende_ws - vorlesungsbeginn_ws << endl;
  cout << endl;

  Datum geburtstag(18, 8, 1980);
  cout << "Bitte geben Sie Ihren Geburtstag ein:\n\n";
  //cin >> geburtstag;
  cout << "\nHeute ist der " << heute << ".\n"
       << "Sie leben bereits " << heute - geburtstag << " Tage.\n"
       << "Am " << geburtstag + 20000 << " werden Sie " << "20.000 Tage gelebt haben.\n";
  cout << endl;

  cout << "\nDatumsangaben\n" << "\nzufaellig:\n\n";
  const int ANZAHL = 10;
  Datum tag[ANZAHL];
  for (int i = 0; i < ANZAHL; i++)
    tag[i] = liefere_zufalls_datum(1960, 1990);
  for (int i = 0; i < ANZAHL; i++)
    cout << tag[i] << endl;
  cout << "\nsortiert:\n\n";
  sortiere(tag, ANZAHL);
  for (int i = 0; i < ANZAHL; i++)
    cout << tag[i] << endl;

  teste_praefix_inkrement();
  teste_postfix_inkrement();
}

void teste_praefix_inkrement()
{
  Datum datum;
  cout << endl << "datum:     " << datum;
  cout << endl << "++datum:   " << ++datum;
  cout << endl << "datum:     " << datum
       << endl << endl;
  for (int i = 0; i < 5; i++)
    cout << ++datum << endl;
}
void teste_postfix_inkrement()
{
  Datum datum;
  cout << endl << "datum:     " << datum;
  cout << endl << "datum++:   " << datum++;
  cout << endl << "datum:     " << datum
       << endl << endl;
  for (int i = 0; i < 5; i++)
    cout << datum++ << endl;
}