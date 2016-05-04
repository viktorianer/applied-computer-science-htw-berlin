/* 
 * File:   name.h
 * Created on 30. Mai 2011, 13:27
 */
#ifndef NAME_H
#define NAME_H
// include(s) oder
#include <iostream>
#include <string>
// weitere Angaben
using namespace std;

class Name
{
  private:
    // Attribute
    /** Anzahl der Vornamen*/
    int anz_vornamen;
    /** Die Vornamen. */
    string *vorname;
    /** Anzahl der Nachnamen */
    int anz_nachnamen;
    /** Die Nachnamen. */
    string *nachname;
  // Konstruktoren
  public:
    Name();
    Name(const string& der_vorname, const string& der_nachname);
    Name(const string& der_vorname,  const string& der_mittelname, const string& der_nachname);
    Name(const string *die_vornamen, int anzahl_vornamen, const string& der_nachname);
    Name(const string& der_vorname, const string *die_nachnamen, int anzahl_nachnamen);
    Name(const string *die_vornamen,  int anzahl_vornamen, const string *die_nachnamen, int anzahl_nachnamen);
    virtual ~Name();
    Name(const Name& original);
    Name& operator=(const Name& ein_name);
  // Methoden
    string liefere_vornamen() const;
    string liefere_rufnamen() const;
    string liefere_nachnamen() const;
    string liefere_namen() const;
    int liefere_anzahl_vornamen() const;
    int liefere_anzahl_nachnamen() const;
    void ersetze_nachnamen(const string& der_neue_nachname);
    void ersetze_nachnamen(const string *die_nachnamen, int anzahl_nachnamen);
  private:
    void initialisiere_namen(const string& der_vorname  = "Max", const string& der_nachname = "Mustermann");
    void initialisiere_namen(const string *die_vornamen, const string *die_nachnamen);
};
// eventuell Deklaration
// weiterer Funktionen
ostream& operator<<(ostream& ausgabe, const Name& name);
bool operator==(const Name& links, const Name& rechts);
bool operator!=(const Name& links, const Name& rechts);
bool operator<(const Name& links, const Name& rechts);
bool operator<=(const Name& links, const Name& rechts);
bool operator>(const Name& links, const Name& rechts);
bool operator>=(const Name& links, const Name& rechts);
void sortiere(Name array[], int laenge);

#endif  /* NAME_H */
