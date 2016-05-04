/* 
 * File:   semestersimulator.h
 * Created on 14. Juli 2011, 13:54
 */
#ifndef SEMESTERSIMULATOR_H
#define SEMESTERSIMULATOR_H
// include(s) oder
#include <vector>
#include <iomanip>

#include "dateimanager.h"
#include "student.h"
#include "personengenerator.h"
#include "semester.h"
#include "datum.h"
// weitere Angaben
using namespace std;

class Semestersimulator
{
private:
  // Attribute
  /** Die zufaellige Studenten, die erzeugt wurden. */
  vector<Student*> studenten;
  /** Die Semester, die simuliert wurden. */
  vector<Semester> semester;
  /** Personengenerator, der zufaellige Personen erzeugen kann. */
  Personengenerator generator;
public:
  // Konstruktoren
  Semestersimulator();
  Semestersimulator(int anzahl_studenten);
  virtual ~Semestersimulator();
  Semestersimulator(const Semestersimulator& original);
  Semestersimulator & operator=(const Semestersimulator& ein_semestersimulator);
  // Methoden
  void simuliere_semester(const string datei_lehrveranstaltungen, const string semester_bezeichnung);
  void informationen_zu_studenten();
  void schreibe_studenteninfos() const;
  void semesterbescheinigung() const;
private:
  void schreibe_semesterbescheinigung(int student, int ein_semester) const;
  void schreibe_teilnehmerliste();
  void initialisiere_studenten(int anzahl_studenten);
  Student liefere_zufalls_student(const char geschlecht, int min_jahr, int max_jahr) const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* SEMESTERSIMULATOR_H */
