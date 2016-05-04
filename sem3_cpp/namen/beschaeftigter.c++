#include "beschaeftigter.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt, einen Beschaeftigten mit Dienstzimmer 1A, keine Telefon- oder Fax-Nummer, einer standard E-Mail-Adresse und der Funktion Schreibkraft. */
Beschaeftigter::Beschaeftigter()
: Person()
{
  dienstzimmer = "1A";
  dienst_telefonnummer = "";
  faxnummer = "";
  email = "s0529652@htw-berlin.de";
  funktion = "Schreibkraft";
}
/**Erzeugt einen Beschaeftigten, die eine Person mit einer bestimmten Funktion an der Hochschule ist. Der Rest ist zufaellig generiert.
 *
 * @param die_person  Die Person, die einen Beschaeftigten darstellen soll.
 * @param die_funktion  Die Funktion des Beschaeftigten an der Hochschule.
 */
Beschaeftigter::Beschaeftigter(Person die_person, const string die_funktion)
: Person(die_person)
{
  string gb[7] = {"A", "B", "C", "D", "E", "F", "G"};
  stringstream puffer;
  puffer << "Gebaeude " << gb[Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 6)] 
    << "2" << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(10, 60);
  dienstzimmer = puffer.str();
  puffer.str("");
  puffer << "030 210" << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(10000, 99999);
  dienst_telefonnummer = puffer.str();
  puffer << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(10, 99);
  faxnummer = puffer.str();
  puffer.str("");
  puffer << liefere_vornamen() << "." << liefere_nachnamen() << "@htw-berlin.de";
  email = puffer.str();
  funktion = die_funktion;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Beschaeftigter::~Beschaeftigter()
{
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Beschaeftigter::Beschaeftigter(const Beschaeftigter& original)
: Person(original)
{
  dienstzimmer = original.dienstzimmer;
  dienst_telefonnummer = original.dienst_telefonnummer;
  faxnummer = original.faxnummer;
  email = original.email;
  funktion = original.funktion;
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_beschaeftigter  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Beschaeftigter& Beschaeftigter::operator=(const Beschaeftigter& ein_beschaeftigter)
{
  if (this != &ein_beschaeftigter) // nur, wenn verschieden
  {
    Person::operator =(ein_beschaeftigter);
    dienstzimmer = ein_beschaeftigter.dienstzimmer; // speichere neue Werte
    dienst_telefonnummer = ein_beschaeftigter.dienst_telefonnummer;
    faxnummer = ein_beschaeftigter.faxnummer;
    email = ein_beschaeftigter.email;
    funktion = ein_beschaeftigter.funktion;
  }
  return *this;
}
// Code der Methoden
/**Schreibt Information zum Beschaeftigten:
 * <br>Ort des Dienstzimmers (Gebäude, Raum)
 * <br>dienstliche Telefonnummer (Vorwahl, Anschluss)
 * <br>Fax-Nummer
 * <br>E-Mail-Adresse(n)
 * <br>Funktion (Schreibkraft, Verwaltungsangestellte(r), Laboringenieur(in), Professor(in))
 *
 */
void Beschaeftigter::schreibe_informationen() const
{
  Person::schreibe_informationen();
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Ich bin " << funktion << " an der HTW-Berlin." << endl;
  cout << "Mein Dienstzimmer befindet sich im " <<  dienstzimmer << " und liegt auf dem Gelaende von Campus Wilhelminenhof." << endl;
  cout << "Hier bin ich unter der Tel.-Nr.: " << dienst_telefonnummer << " und unter dem Fax: "
    << faxnummer << " erreichbar." << endl;
  cout << "Meine E-Mail-Adresse lautet: " << email << endl;
}
// eventuell Code
// weiterer Funktionen
