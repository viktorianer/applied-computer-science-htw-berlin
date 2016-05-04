#ifndef BESCHAEFTIGTER_H
#define BESCHAEFTIGTER_H
// include(s) oder
#include "person.h"
#include "beschreibbar.h"
// weitere Angaben
using namespace std;

class Beschaeftigter : public Person
{
  private:
    // Attribute
    /** Das Dienstimmer des Beschaeftigten */
    string dienstzimmer;
    /** Die dienstliche Telefonnummer des Beschaeftigten */
    string dienst_telefonnummer;
    /** Die Fax-Nummer des Beschaeftigten */
    string faxnummer;
    /** Die E-Mail-Adresse des Beschaeftigten */
    string email;
    /** Die Funktion an der Hochschule des Beschaeftigten */
    string funktion;
  public:
    // Konstruktoren
    Beschaeftigter();
    Beschaeftigter(Person die_person, const string die_funktion);
    virtual ~Beschaeftigter();
    Beschaeftigter(const Beschaeftigter& original);
    Beschaeftigter & operator=(const Beschaeftigter& ein_beschaeftigter);
    // Methoden
    virtual void schreibe_informationen() const;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* BESCHAEFTIGTER_H */
