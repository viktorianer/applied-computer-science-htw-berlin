/* 
 * File:   einschreibung.h
 * Created on 14. Juli 2011, 15:53
 */
#ifndef EINSCHREIBUNG_H
#define EINSCHREIBUNG_H
// include(s) oder
#include <iostream>

#include "student.h"
#include "zufallsgenerator.h"
// weitere Angaben
using namespace std;
#include <iomanip>
class Einschreibung
{
private:
  // Attribute
  /** Der Student, der sich fuer ein Fach eingeschrieben hat. */
  Student* student;
  /** Die Note, die er fuer diesen Fach bekommen hat. */
  double note;
public:
  // Konstruktoren
  Einschreibung();
  Einschreibung(Student* ein_student);
  Einschreibung(Student* ein_student, double die_note);
  virtual ~Einschreibung();
  Einschreibung(const Einschreibung& original);
  Einschreibung & operator=(const Einschreibung& eine_einschreibung);
  // Methoden
  Student* liefere_studenten() const;
  double liefere_note() const;
  Name liefere_den_namen() const;
private:
  double liefere_zufaellige_note() const;
};
// eventuell Deklaration
// weiterer Funktionen
bool operator==(const Einschreibung& links, const Einschreibung& rechts);
bool vergleiche_note_name(Einschreibung* links, Einschreibung* rechts);

#endif  /* EINSCHREIBUNG_H */
