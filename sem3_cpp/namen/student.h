#ifndef STUDENT_H
#define STUDENT_H
// include(s) oder
#include <string>

#include "zufallsgenerator.h"
#include "person.h"
#include "beschreibbar.h"
// weitere Angaben
using namespace std;

class Student : public Person
{
private:
  // Attribute
  /** Fachbereich, dem der Studen angehoert. */
  string fachbereich;
  /** Studiengang, dem der Studen angehoert. */
  string studiengang;
  /** die Matrikelnummer des Studenten. */
  string matrikelnummer;
  /** Immatrikulationsdatum des Studenten. */
  Datum immatrikulation;
  /** Die Heimatanschrift des Studenten. */
  Postanschrift heimatanschrift;
  /** E-Mail-Adresse des Studenten. */
  string email;
public:
  // Konstruktoren
  Student();
  Student(Name der_name, Datum der_geburtstag, const char das_geschlecht, Ort der_geburtsort,
            const string die_nationalitaet, Postanschrift die_wohnanschrift, const string die_telefonnummer,
            Datum die_immatrikulation, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang, const string die_matrikelnummer, const string die_email);
  Student(Person die_person, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang);
  Student(Person die_person, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang, Datum die_immatrikulation);
  virtual ~Student();
  Student(const Student& original);
  Student& operator=(const Student& ein_student);
  // Methoden
  string liefere_fachbereich() const;
  string liefere_studiengang() const;
  string liefere_matrikelnummer() const;
  string liefere_immatrikulations_datum() const;
  virtual void schreibe_informationen() const;
};
// eventuell Deklaration
// weiterer Funktionen
bool vergleiche_matrikelnummer(Student* links, Student* rechts);
bool vergleiche_fachbereich(Student* links, Student* rechts);
bool vergleiche_fachbereich_und_namen(Student* links, Student* rechts);
#endif  /* STUDENT_H */
