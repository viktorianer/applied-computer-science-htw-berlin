#ifndef DATEIMANAGER_H
#define DATEIMANAGER_H
// include(s) oder
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// weitere Angaben
using namespace std;

class Dateimanager
{
  private:
    // Attribute
    /** Der Inhalt einer Datei. Wobei jede Zeile der Datei in einem String gespeichert wird. */
    vector<string> datei_inhalt;
  public:
    // Konstruktoren
    Dateimanager();
    Dateimanager(string dateiname);
    virtual ~Dateimanager();
    Dateimanager(const Dateimanager& original);
    Dateimanager & operator=(const Dateimanager& ein_dateimanager);
    // Methoden
    int lese_dateiinhalt(string dateiname);
    vector<string> liefere_dateiinhalt() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* DATEIMANAGER_H */
