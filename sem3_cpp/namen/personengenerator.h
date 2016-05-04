#ifndef PERSONENGENERATOR_H
#define PERSONENGENERATOR_H
// include(s) oder
#include "eingaben.h"
#include "menue.h"
#include "zufallsgenerator.h"
#include "utilities.h"
#include "dateimanager.h"
#include "name.h"
#include "datum.h"
#include "person.h"
#include "student.h"
#include "beschaeftigter.h"
#include "professor.h"
#include "ortsliste.h"
#include "namensliste.h"
// weitere Angaben
using namespace std;

class Personengenerator
{
private:
  // Attribute
  /** Die Namenslite mit weiblichen und maennlichen Vornamen und Nachnamen */
  Namensliste namensliste;
  /** Ortsliste mit Landes-, Orts- und Strassennamen */
  Ortsliste ortsliste;
  /** Nationalitaeten-Liste. */
  vector<string> nationalitaeten;
  /** Studiengaenge-Liste. */
  vector<string> studiengaenge;
  /** Die zufaellige Personen, die erzeugt wurden */
  vector<Person*> menschen;
  /** Die zufaellige Studenten, die erzeugt wurden */
  vector<Student*> studenten;

public:
  // Konstruktoren
  Personengenerator();
  virtual ~Personengenerator();
  Personengenerator(const Personengenerator& original);
  Personengenerator& operator=(const Personengenerator& ein_personengenerator);
  // Methoden
  Person liefere_zufalls_person(const char geschlecht, int min_jahr, int max_jahr) const;
  Student liefere_zufalls_student(const char geschlecht, int min_jahr, int max_jahr) const;
  Beschaeftigter liefere_zufalls_beschaeftigter(const char geschlecht, int min_jahr, int max_jahr) const;
  Professor liefere_zufalls_professor(const char geschlecht, int min_jahr, int max_jahr) const;
  void erzeuge_zufalls_personen(int anzahl);
  void informationen_zu_personen();
  void sortiere_personen(bool(*funktion)(Person*, Person*));
  void schreibe_personeninfos() const;
  void erzeuge_zufalls_studenten(int anzahl);
  void informationen_zu_studenten();
  void sortiere_studenten(bool (*funktion)(Student*, Student*));
  void schreibe_studenteninfos() const;
  Postanschrift liefere_zufalls_postanschrift(const string landesname) const;
  string liefere_zufalls_nationalitaet() const;
  string liefere_zufalls_fachbereich() const;
  string liefere_zufalls_studiengang() const;
  string liefere_zufalls_funktion(const char geschlecht) const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* PERSONENGENERATOR_H */
