/* 
 * File:   semester.h
 * Created on 14. Juli 2011, 15:25
 */
#ifndef SEMESTER_H
#define SEMESTER_H
// include(s) oder
#include <vector>

#include "fach.h"
#include "zufallsgenerator.h"
#include "menue.h"
// weitere Angaben
using namespace std;

class Semester
{
private:
  // Attribute
  /** Die Bezeichnung des Semesters. Zum Beispiel "Wintersemester 2010/2011". */
  string bezeichnung;
  /** Die Lehrveranstaltungen, die in diesem Semester angeboten werden. */
  vector<Fach> lehrveranstaltungen;
public:
  // Konstruktoren
  Semester();
  Semester(const vector<string> die_lehrveranstaltungen, vector<Student*> studenten, const string semester_bezeichnung);
  virtual ~Semester();
  Semester(const Semester& original);
  Semester & operator=(const Semester& ein_semester);
  // Methoden
  string liefere_bezeichnung() const;
  void schreibe_semesterbescheinigung(Student* student) const;
  void schreibe_teilnehmerliste();
  double liefere_durchschnittsnote(Student* student) const;
};
// eventuell Deklaration
// weiterer Funktionen

#endif  /* SEMESTER_H */
