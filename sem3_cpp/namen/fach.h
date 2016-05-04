/* 
 * File:   fach.h
 * Created on 14. Juli 2011, 15:49
 */
#ifndef FACH_H
#define FACH_H
// include(s) oder
#include <vector>
#include <iostream>

#include "student.h"
#include "einschreibung.h"
// weitere Angaben
using namespace std;

class Fach
{
private:
  // Attribute
  /** Die fuer die Lehrveranstaltung eingeschriebene Studenten. */
  vector<Einschreibung*> teilnehmer;
  /** Die Bezeichnung der Lehrveranstaltung. */
  string bezeichnung;
  /** Die Anzahl der Semester-Leistungspunkte der Lehrveranstaltung. */
  int sws;
public:
  // Konstruktoren
  Fach();
  Fach(vector<Student*> studenten, const string bezeichnung_fach, int die_anzahl_sws);
  virtual ~Fach();
  Fach(const Fach& original);
  Fach & operator=(const Fach& ein_fach);
  // Methoden
  string liefere_bezeichnung() const;
  int liefere_sws() const;
  double liefere_note(Student* student) const;
  void schreibe_teilnehmerliste();
  void sortiere_einschreibungen(bool (*funktion)(Einschreibung*, Einschreibung*));
private:
};
// eventuell Deklaration
// weiterer Funktionen

#endif  /* FACH_H */
