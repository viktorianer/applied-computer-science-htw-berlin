#include "student.h"
// weitere Angaben
// Code der Konstruktoren

/**Erzeugt den Defaultobjekt Student, der dem Fachbereich FB 4 und dem Studiengang AI angehoert. 
 * Er hat die Matrikelnummer s0529652 und E-Mail viktorianer4life@googlemail.com. */
Student::Student()
: Person(), immatrikulation(), heimatanschrift()
{
  fachbereich = "FB 4";
  studiengang = "Angewandte Informatik";
  matrikelnummer = "s0529652";
  email = "viktorianer4life@googlemail.com";
}
/**Erzeugt einen Studenten mit folgenden bestimmten Angaben:
 * <br>Vorname(n)
 * <br>Nachname (aktueller, Geburtsname)
 * <br>Ein Kennzeichen für das Geschlecht (m, w)
 * <br>Geburtsdatum (TT, MM, JJJJ)
 * <br>Geburtsort (Ort, Land)
 * <br>Nationalitaet
 * <br>Wohnanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>private Telefonnummer(n) (Vorwahl, Anschluss)
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Matrikelnummer
 * <br>Datum der Immatrikulation (TT, MM, JJJJ)
 * <br>Heimatanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>E-Mail-Adresse(n)
 *
 * @param der_name            Der Name des Studenten.
 * @param der_geburtstag      Der Geburtstag des Studenten.
 * @param das_geschlecht      Geschlecht des Studenten.
 * @param der_geburtsort      Geburtsort des Studenten.
 * @param die_nationalitaet   Nationalitaet des Studenten.
 * @param die_wohnanschrift   Wohnanschrift des Studenten.
 * @param die_telefonnummer   Telefonnummer des Studenten.
 * @param die_immatrikulation Immatrikulation des Studenten.
 * @param die_heimatanschrift Heimatanschrift des Studenten.
 * @param der_fachbereich     Fachbereich des Studenten.
 * @param der_studiengang     Der Studiengang des Studenten.
 * @param die_matrikelnummer  Die Matrikelnummer des Studenten.
 * @param die_email           Die E-Mail-Adresse des Studenten.
 */
Student::Student(Name der_name, Datum der_geburtstag, const char das_geschlecht, Ort der_geburtsort,
            const string die_nationalitaet, Postanschrift die_wohnanschrift, const string die_telefonnummer,
            Datum die_immatrikulation, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang, const string die_matrikelnummer, const string die_email)
: Person(der_name, der_geburtstag, das_geschlecht, der_geburtsort,
            die_nationalitaet, die_wohnanschrift, die_telefonnummer),
  immatrikulation(die_immatrikulation), heimatanschrift(die_heimatanschrift)
{
  fachbereich = der_fachbereich;
  studiengang = der_studiengang;
  matrikelnummer = die_matrikelnummer;
  email = die_email;
}
/**Erzeugt aus einer Person einen Studenten mit folgenden bestimmten Angaben:
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Matrikelnummer
 * <br>Datum der Immatrikulation (TT, MM, JJJJ)
 * <br>Heimatanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>E-Mail-Adresse(n)
 * <br>Der Rest wird zufaellig erzeugt.
 *
 * @param die_person          Die Person die Student wird.
 * @param die_heimatanschrift Heimatanschrift des Studenten.
 * @param der_fachbereich     Fachbereich des Studenten.
 * @param der_studiengang     Der Studiengang des Studenten.
 */
Student::Student(Person die_person, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang)
: Person(die_person), heimatanschrift(die_heimatanschrift)
{
  fachbereich = der_fachbereich;
  studiengang = der_studiengang;
  stringstream eine_matrikelnummer;
  eine_matrikelnummer << "s052";
  eine_matrikelnummer << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1000, 9999);
  matrikelnummer = eine_matrikelnummer.str();
  immatrikulation = liefere_zufalls_datum(liefere_jahrgang() + 18, liefere_jahrgang() + 30);
  stringstream eine_email;
  eine_email << liefere_vornamen() << "." << liefere_nachnamen() << "@googlemail.com";
  email = eine_email.str();
}
/**Erzeugt aus einer Person einen Studenten mit folgenden bestimmten Angaben:
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Matrikelnummer
 * <br>Datum der Immatrikulation (TT, MM, JJJJ)
 * <br>Heimatanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>E-Mail-Adresse(n)
 * <br>Der Rest wird zufaellig erzeugt.
 *
 * @param die_person          Die Person die Student wird.
 * @param die_heimatanschrift Heimatanschrift des Studenten.
 * @param der_fachbereich     Fachbereich des Studenten.
 * @param der_studiengang     Der Studiengang des Studenten.
 * @param die_immatrikulation Immatrikulation des Studenten.
 */
Student::Student(Person die_person, Postanschrift die_heimatanschrift,
            const string der_fachbereich, const string der_studiengang, Datum die_immatrikulation)
: Person(die_person), heimatanschrift(die_heimatanschrift)
{
  fachbereich = der_fachbereich;
  studiengang = der_studiengang;
  stringstream eine_matrikelnummer;
  eine_matrikelnummer << "s052";
  eine_matrikelnummer << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1000, 9999);
  matrikelnummer = eine_matrikelnummer.str();
  immatrikulation = die_immatrikulation;
  stringstream eine_email;
  eine_email << liefere_vornamen() << "." << liefere_nachnamen() << "@googlemail.com";
  email = eine_email.str();
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Student::~Student()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Student::Student(const Student& original)
: Person(original)
{
  fachbereich = original.fachbereich;
  studiengang = original.studiengang;
  matrikelnummer = original.matrikelnummer;
  immatrikulation = original.immatrikulation;
  heimatanschrift = original.heimatanschrift;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_student  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Student& Student::operator=(const Student& ein_student)
{
  if (this != &ein_student) // nur, wenn verschieden
  {
    Person::operator=(ein_student); // speichere neue Werte
    fachbereich = ein_student.fachbereich;
    studiengang = ein_student.studiengang;
    matrikelnummer = ein_student.matrikelnummer;
    immatrikulation = ein_student.immatrikulation;
    heimatanschrift = ein_student.heimatanschrift;
  }
  return *this;
}
// Code der Methoden
/**Liefert den Fachbereich des Studenten.
 *
 * @return Den Fachbereich des Studenten.
 */
string Student::liefere_fachbereich() const
{
  return fachbereich;
}
/**Liefert den Studiengang des Studenten.
 *
 * @return Den Studiengang des Studenten.
 */
string Student::liefere_studiengang() const
{
  return studiengang;
}
/**Liefert die Matrikelnummer des Studenten.
 *
 * @return Die Matrikelnummer des Studenten.
 */
string Student::liefere_matrikelnummer() const
{
  return matrikelnummer;
}
string Student::liefere_immatrikulations_datum() const
{
  return immatrikulation.liefere_standarddatum();
}
/**Schreibt Informationen zum Studenten, d.h. Fachbereich, Studiumfach, die Matrikelnummer, Heimatanschrift und die E-Mail-Adresse. */
void Student::schreibe_informationen() const
{
  Person::schreibe_informationen();
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Ich Studiere im Fachbereich " << fachbereich << " im Studiumfach " << studiengang << endl;
  cout << "Ich wurde am " << immatrikulation.liefere_standarddatum()
    << " mit der Matrikelnummer <" << matrikelnummer << "> immatrikuliert." << endl;
  cout << "Meine Heimatanschrift ist: " << heimatanschrift.liefere_ortsbeschreibung() << endl;
  cout << "Meine E-Mail ist: " << email << endl;
}
// eventuell Code
// weiterer Funktionen
/**Vergleichsfunktion die die beiden Studenten nach Matrikelnummer vergleicht.
 *
 * @param links   Der Student.
 * @param rechts  Eine zum Vergleich herangezogener Student.
 * @return Wenn die Matrikelnummer des linken Student vor der des rechten Studenten kommt (true) und sonst false.
 */
bool vergleiche_matrikelnummer(Student* links, Student* rechts)
{
  return (links->liefere_matrikelnummer().compare(rechts->liefere_matrikelnummer()) < 0) ? true : false;
}
/**Vergleichsfunktion die die beiden Studenten nach Fachbereich und wenn gleich nach den Matrikelnummer vergleicht.
 *
 * @param links   Der Student.
 * @param rechts  Eine zum Vergleich herangezogener Student.
 * @return Wenn der Fachbereich des linken Student im Alphabet vor der des rechten Studenten kommt oder wenn gleich
 * wenn die Matrikelnummer des linken Student vor der des rechten Studenten kommt(true) und sonst false.
 */
bool vergleiche_fachbereich(Student* links, Student* rechts)
{
  bool links_kleiner = false;
	int vergleich = links->liefere_fachbereich().compare(rechts->liefere_fachbereich());
	if (vergleich < 0)
	{
		links_kleiner = true;
	}
  else if (vergleich == 0)
	{
		links_kleiner = vergleiche_matrikelnummer(links, rechts);
	}
	return links_kleiner;
}
/**Vergleichsfunktion die die beiden Studenten nach Fachbereich und wenn gleich nach den Namen vergleicht.
 *
 * @param links   Der Student.
 * @param rechts  Eine zum Vergleich herangezogener Student.
 * @return Wenn der Fachbereich des linken Student im Alphabet vor der des rechten Studenten kommt oder wenn gleich
 * wenn der Name des linken Student im Alphabet vor der des rechten Studenten kommt(true) und sonst false.
 */
bool vergleiche_fachbereich_und_namen(Student* links, Student* rechts)
{
  bool links_kleiner = false;
	int vergleich = links->liefere_fachbereich().compare(rechts->liefere_fachbereich());
	if (vergleich < 0)
	{
		links_kleiner = true;
	}
  else if (vergleich == 0)
	{
		vergleich = links->liefere_nachnamen().compare(rechts->liefere_nachnamen());
		if (vergleich < 0)
		{
			links_kleiner = true;
		}
    else if (vergleich == 0)
		{
			vergleich = links->liefere_vornamen().compare(rechts->liefere_vornamen());
			if (vergleich < 0)
			{
				links_kleiner = true;
			}
		}
	}
	return links_kleiner;
}
