#ifndef BESCHREIBBAR_H
#define BESCHREIBBAR_H
// include(s) oder
#include <string>
// weitere Angaben
using namespace std;

class Beschreibbar
{
    // Attribute
  public:
    // Konstruktoren
    virtual ~Beschreibbar();
    // Methoden
    /**
     * Eine Methode, die ueberschrieben werden muss, um das Objekt beschreibbar zu machen.
     * Die Beschreibung muss zum Objekt passen. Zum Beispiel: Ein Person hat folgende Informationen zu seiner Beschreibung:
     * <br>Vorname(n)
     * <br>Nachname (aktueller, Geburtsname)
     * <br>Ein Kennzeichen für das Geschlecht (m, w)
     * <br>Geburtsdatum (TT, MM, JJJJ)
     * <br>Geburtsort (Ort, Land)
     * <br>Nationalitaet
     * <br>Wohnanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
     * <br>private Telefonnummer(n) (Vorwahl, Anschluss)
     */
    virtual void schreibe_informationen() const = 0;
};
// eventuell Deklaration
// weiterer Funktionen
#endif  /* BESCHREIBBAR_H */
