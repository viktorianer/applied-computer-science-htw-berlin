#ifndef PROFESSOR_H
#define PROFESSOR_H

// include(s) oder
#include "beschaeftigter.h"
#include "beschreibbar.h"
// weitere Angaben
using namespace std;

class Professor : public Beschaeftigter
{
private:
  // Attribute
  /** Der Fachbereich des Professors. */
  string fachbereich;
  /** Studiengan des Professors.*/
  string studiengang;
  /** Sprechstunde des Professors.*/
  string sprechstunde;
public:
  // Konstruktoren
  Professor();
  Professor(Beschaeftigter die_person, const string der_fachbereich, const string der_studiengang);
  virtual ~Professor();
  Professor(const Professor& original);
  Professor & operator=(const Professor& ein_professor);
  // Methoden
  virtual void schreibe_informationen() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* PROFESSOR_H */
