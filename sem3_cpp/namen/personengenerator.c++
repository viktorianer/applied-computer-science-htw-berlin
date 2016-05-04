#include "personengenerator.h"
// weitere Angaben
// Code der Konstruktoren

/**Erzeugt eine Instanz der Klasse Personengenerator, Der zufaellige Personen erzeugen kann.
 * Dazu werden aus mehereren Listen die Daten fuer die erzeugung von zufaelligen Personen gelesen.<br>
 * <br>
 * <br>Folgende Dateien werden benoetigt:<br>
 * <br>GivenNamesW fuer weibliche Vornamen, GivenNamesM maennliche Vornamen, FamilyNames fuer Nachnamen.
 * <br>Land fuer Landes-, Orte fuer Orts- und Strassen fuer Strassennamen.
 * Die Ortsliste muss pro Zeile eine PLZ gefolgt vom Ortsnamen enthalten.
 * <br>Nationalitaet fuer die Nationalitaetenliste.
 * <br>Studiengang fuer die Studiengangsliste.
 * Die Daten werden zufaellig aus mehreren Dateien generiert.<br>
 * <br>
 * <br>Für jede Person sind folgende Daten vorhanden:<br>
 * <br>Vorname(n)
 * <br>Nachname (aktueller, Geburtsname)
 * <br>Ein Kennzeichen für das Geschlecht (m, w)
 * <br>Geburtsdatum (TT, MM, JJJJ)
 * <br>Geburtsort (Ort, Land)
 * <br>Nationalitaet
 * <br>Wohnanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>private Telefonnummer(n) (Vorwahl, Anschluss)
 * <br>
 * <br>Für Studierende sind zusaetzlich folgende Daten vorhanden:<br>
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Matrikelnummer
 * <br>Datum der Immatrikulation (TT, MM, JJJJ)
 * <br>Heimatanschrift (Straße, Hausnummer, Postleitzahl, Ort, Land)
 * <br>E-Mail-Adresse(n)
 * <br>
 * <br>Fuerr Beschäftigte sind zusaetzlich folgende Daten vorhanden:<br>
 * <br>Ort des Dienstzimmers (Gebäude, Raum)
 * <br>dienstliche Telefonnummer (Vorwahl, Anschluss)
 * <br>Fax-Nummer
 * <br>E-Mail-Adresse(n)
 * <br>Funktion (Schreibkraft, Verwaltungsangestellte(r), Laboringenieur(in), Professor(in))
 * <br>
 * <br>Fuer Professoren sind zusaetzlich folgende Daten vorhanden:
 * <br>Fachbereich
 * <br>Studiengang
 * <br>Sprechstunde (Wochentag, Uhrzeit)
 * <br>
 * <br>Auf Wunsch werden n Personen (gemischt Studierende, Beschaftigte, Professoren) per Zufallszahlengenerator erzeugt, wobei n gewahlt werden kann (1 <= n <= 1000).
 * <br>Es ist moglich, die Informationen uber die Personen auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm auszugeben.
 * <br>Es werden mehrere Arten der Sortierung angeboten:<br>
 * <br>alphabetische Sortierung nach Nachnamen, bei gleichem Nachnamen nach Vornamen, bei gleichem Vornamen nach Geburtsdatum
 * <br>nach dem Geburtsdatum, bei gleichem Geburtsdatum nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen
 * <br>nach dem Jahrgang (Geburtsjahr), bei gleichem Jahrgang nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Es ist auch moglich, nur n Studierende zu erzeugen (1 <= n <= 500). Diese mussen dann zusatzlich auch so sortiert und ausgegeben werden konnen:
 * <br>nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 * <br>
 * <br>Auf Wunsch ist es moglich, n neue Personen zu erzeugen und sortiert auszugeben.
 */
Personengenerator::Personengenerator()
{
  Dateimanager dateimanager;
  int anzahl_zeilen = dateimanager.lese_dateiinhalt("Nationalitaet");
  nationalitaeten = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Nationalitaeten: " << anzahl_zeilen << endl;
  anzahl_zeilen = dateimanager.lese_dateiinhalt("Studiengang");
  studiengaenge = dateimanager.liefere_dateiinhalt();
  cout << "Die Anzahl eingelesener Studiengaenge: " << anzahl_zeilen << endl;
  menschen.clear();
  studenten.clear();
}

/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Personengenerator::~Personengenerator()
{
  nationalitaeten.clear();
  for (unsigned int i = 0; i < menschen.size(); i++)
    delete menschen[i];
  menschen.clear();
  for (unsigned int i = 0; i < studenten.size(); i++)
    delete studenten[i];
  studenten.clear();
}

/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Personengenerator::Personengenerator(const Personengenerator& original)
{
  nationalitaeten.clear();
  for (unsigned int i = 0; i < menschen.size(); i++)
    delete menschen[i];
  menschen.clear();
  for (unsigned int i = 0; i < studenten.size(); i++)
    delete studenten[i];
  studenten.clear();
  nationalitaeten = original.nationalitaeten;
  menschen.reserve(original.menschen.size());
  for (unsigned int i = 0; i < original.menschen.size(); i++)
    menschen[i] =  original.menschen[i];
  studenten.reserve(original.studenten.size());
  for (unsigned int i = 0; i < original.studenten.size(); i++)
    studenten[i] =  original.studenten[i];
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_personengenerator  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Personengenerator& Personengenerator::operator=(const Personengenerator& ein_personengenerator)
{
  if (this != &ein_personengenerator) // nur, wenn verschieden
  {
    nationalitaeten.clear(); // lösche alte Werte
    for (unsigned int i = 0; i < menschen.size(); i++)
      delete menschen[i];
    menschen.clear();
    for (unsigned int i = 0; i < studenten.size(); i++)
      delete studenten[i];
    studenten.clear();
    nationalitaeten = ein_personengenerator.nationalitaeten; // speichere neue Werte
    menschen.reserve(ein_personengenerator.menschen.size());
    for (unsigned int i = 0; i < ein_personengenerator.menschen.size(); i++)
      menschen[i] =  ein_personengenerator.menschen[i];
    studenten.reserve(ein_personengenerator.studenten.size());
    for (unsigned int i = 0; i < ein_personengenerator.studenten.size(); i++)
      studenten[i] =  ein_personengenerator.studenten[i];
  }
  return *this;
}
// Code der Methoden
/**Liefert eine zufaellig erzeugte Person mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 *
 * @param geschlecht  Das Geschlecht der zufaellig erzeugte Person.
 * @param min_jahr    Das min. Geburtstjahr der zufaellig erzeugte Person.
 * @param max_jahr    Das max. Geburtstjahr der zufaellig erzeugte Person.
 * @return Eine zufaellig erzeugte Person mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 */
Person Personengenerator::liefere_zufalls_person(const char geschlecht, int min_jahr, int max_jahr) const
{
  stringstream die_telefonnummer;
  die_telefonnummer << "0" << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(100, 999);
  die_telefonnummer << " "
    << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(10000000, 99999999);
  return Person(
    namensliste.liefere_zufalls_namen(geschlecht), liefere_zufalls_datum(min_jahr, max_jahr), geschlecht,
    ortsliste.liefere_zufalls_ort(), liefere_zufalls_nationalitaet(),
    ortsliste.liefere_zufalls_postanschrift("Deutschland"), die_telefonnummer.str());
}
/**Liefert einen zufaellig erzeugten Student mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 *
 * @param geschlecht  Das Geschlecht des zufaellig erzeugten Studenten.
 * @param min_jahr    Das min. Geburtstjahr des zufaellig erzeugten Studenten.
 * @param max_jahr    Das max. Geburtstjahr des zufaellig erzeugten Studenten.
 * @return Ein zufaellig erzeugte Student mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 */
Student Personengenerator::liefere_zufalls_student(const char geschlecht, int min_jahr, int max_jahr) const
{
  return Student(liefere_zufalls_person(geschlecht, min_jahr, max_jahr),
    ortsliste.liefere_zufalls_postanschrift("Deutschland"),
    liefere_zufalls_fachbereich(), liefere_zufalls_studiengang());
}
/**Liefert einen zufaellig erzeugten Beschaeftigten mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 *
 * @param geschlecht  Das Geschlecht des zufaellig erzeugten Beschaeftigten.
 * @param min_jahr    Das min. Geburtstjahr des zufaellig erzeugten Beschaeftigten.
 * @param max_jahr    Das max. Geburtstjahr des zufaellig erzeugten Beschaeftigten.
 * @return Ein zufaellig erzeugte Beschaeftigter mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 */
Beschaeftigter Personengenerator::liefere_zufalls_beschaeftigter(const char geschlecht, int min_jahr, int max_jahr) const
{
  return Beschaeftigter(liefere_zufalls_person(geschlecht, min_jahr, max_jahr),
    liefere_zufalls_funktion(geschlecht));
}
/**Liefert einen zufaellig erzeugten Professor mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 *
 * @param geschlecht  Das Geschlecht des zufaellig erzeugten Professors.
 * @param min_jahr    Das min. Geburtstjahr des zufaellig erzeugten Professors.
 * @param max_jahr    Das max. Geburtstjahr des zufaellig erzeugten Professors.
 * @return Ein zufaellig erzeugte Professor mit einem bestimmten Geschlecht und einen Geburtstag zwischen min_jahr bis max_jahr.
 */
Professor Personengenerator::liefere_zufalls_professor(const char geschlecht, int min_jahr, int max_jahr) const
{
  string funktion;
  if (geschlecht == 'w')
    funktion = "Proffesorin";
  else
    funktion = "Proffesor";
  return Professor((Beschaeftigter(liefere_zufalls_person(geschlecht, min_jahr, max_jahr), funktion)),
    liefere_zufalls_fachbereich(), liefere_zufalls_studiengang());
}
/**Erzeugt eine bestimmte Anzahl an zufaelligen Personen (es koennen folgende Personen sein: Person, Student, Beschaeftigter und Professor).
 * Auf Wunsch werden n Personen (gemischt Studierende, Beschaftigte, Professoren) per Zufallszahlengenerator erzeugt, wobei n gewahlt werden kann (1 <= n <= 1000).
 *
 * @param anzahl  Die Anzahl n der zur erzeugende zufaellige Personen.
 */
void Personengenerator::erzeuge_zufalls_personen(int anzahl)
{
  char geschlecht = '\0';
  for (int i = 0; i < anzahl; i++)
  {
    geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
    int zahl = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 100);
    if (0 < zahl && zahl <= 40)
      menschen.push_back(
      new Person(liefere_zufalls_person(geschlecht, 1950, 2004)));
    else if (40 < zahl && zahl <= 50)
      menschen.push_back(
      new Professor(liefere_zufalls_professor(geschlecht, 1960, 1975)));
    else if (50 < zahl && zahl <= 60)
      menschen.push_back(
      new Beschaeftigter(liefere_zufalls_beschaeftigter(geschlecht, 1970, 1985)));
    else
      menschen.push_back(
      new Student(liefere_zufalls_student(geschlecht, 1980, 1992)));
  }
}
/**Gibt ein Menue aus, mit dem man die Informationen uber die Personen auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm ausgeben kann.
 * <br>Es werden mehrere Arten der Sortierung angeboten:<br>
 * <br>alphabetische Sortierung nach Nachnamen, bei gleichem Nachnamen nach Vornamen, bei gleichem Vornamen nach Geburtsdatum
 * <br>nach dem Geburtsdatum, bei gleichem Geburtsdatum nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen
 * <br>nach dem Jahrgang (Geburtsjahr), bei gleichem Jahrgang nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 */
void Personengenerator::informationen_zu_personen()
{
  string menuepunkte[] = { "Liste der Personen",
                           "Personen alphabetisch nach Namen sortieren",
													 "Personen nach Geburtsdatum sortieren",
													 "Personen nach Jahrgang sortieren",
                           "Neue Personen erzeugen",
													 "Beenden"};
  int anzahl = sizeof(menuepunkte) / sizeof(menuepunkte[0]);
  Menue menue(anzahl, menuepunkte);
	bool antwort = false;
	do
	{
		switch (menue.waehle_aus_menue())
		{
			case 1:
        schreibe_personeninfos();
				break;
			case 2:
				sortiere_personen(vergleiche_personen);
        schreibe_personeninfos();
				break;
			case 3:
				sortiere_personen(vergleiche_nach_alter);
        schreibe_personeninfos();
				break;
			case 4:
        sortiere_personen(vergleiche_nach_jahrgang);
        schreibe_personeninfos();
				break;
      case 5:
        erzeuge_zufalls_personen(
          Eingaben::erfasse_int("Bitte geben Sie ein, wie viel neue Personen erzeugt werden sollen: ", 1, 1000));
				break;
			default:
				cout << "\nDas Programm wird beendet. See You!\n" << endl;
				antwort = true;
				break;
		}
	} while (antwort == false);
}
/**Sortiert die Personen nach der Vorschrift die in der Vergleichsfunktion festgelegt wurde.
 *
 * @param funktion  Die Vergleichsfunktion, die bestimmt wie die Personen sortiert werden.
 */
void Personengenerator::sortiere_personen(bool (*funktion)(Person*, Person*))
{
	sort(menschen.begin(), menschen.end(), funktion);
}
/**Schreibt Informationen zu den Personen in der Personenliste. */
void Personengenerator::schreibe_personeninfos() const
{
  cout << endl;
  for (unsigned int i = 0; i < menschen.size(); i++)
  {
    menschen[i]->schreibe_informationen();
  }
//  for (unsigned int i = 0; i < menschen.size(); i++)
//  {
//    cout << setw(30) << left;
//    cout << menschen[i]->liefere_namen();
//    cout << setw(12) << right;
//    cout << menschen[i]->liefere_geburtstag();
//    cout << endl;
//  }
}
/**Erzeugt eine bestimmte Anzahl an zufaelligen Studenten.
 * Auf Wunsch werden n Studenten per Zufallszahlengenerator erzeugt, wobei n gewahlt werden kann (1 <= n <= 500).
 *
 * @param anzahl  Die Anzahl n der zur erzeugende zufaellige Studenten.
 */
void Personengenerator::erzeuge_zufalls_studenten(int anzahl)
{
  char geschlecht = '\0';
  for (int i = 0; i < anzahl; i++)
  {
    geschlecht = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 1) == 0 ? 'm' : 'w';
    studenten.push_back(new Student(liefere_zufalls_student(geschlecht, 1980, 1992)));
  }
}
/**Gibt ein Menue aus, mit dem man die Informationen uber die Studenten auf Wunsch sowohl unsortiert als auch sortiert auf dem Bildschirm ausgeben kann.
 * <br>Es werden mehrere Arten der Sortierung angeboten:<br>
 * <br>nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich nach der Matrikelnummer
 * <br>nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei gleichem Nachnamen nach dem Vornamen.
 */
void Personengenerator::informationen_zu_studenten()
{
  string menuepunkte[] = { "Liste der Studierenden",
													 "Studierende nach Matrikelnummer sortieren",
													 "Studierende nach dem Fachbereich und Matriklelnummer sortieren",
													 "Studierende nach dem Fachbereich und Namen sortieren",
                           "Neue Studenten erzeugen",
													 "Beenden"};
  int anzahl = sizeof(menuepunkte) / sizeof(menuepunkte[0]);
  Menue menue(anzahl, menuepunkte);
	bool antwort = false;
	do
	{
		switch (menue.waehle_aus_menue())
		{
			case 1:
        schreibe_studenteninfos();
				break;
			case 2:
				sortiere_studenten(vergleiche_matrikelnummer);
        schreibe_studenteninfos();
				break;
			case 3:
				sortiere_studenten(vergleiche_fachbereich);
        schreibe_studenteninfos();
				break;
			case 4:
        sortiere_studenten(vergleiche_fachbereich_und_namen);
        schreibe_studenteninfos();
				break;
      case 5:
        erzeuge_zufalls_studenten(
          Eingaben::erfasse_int("Bitte geben Sie ein, wie viel neue Studenten erzeugt werden sollen: ", 1, 1000));
				break;
			default:
				cout << "\nDas Programm wird beendet. See You!\n" << endl;
				antwort = true;
				break;
		}
	} while (antwort == false);
}
/**Sortiert die Studenten nach der Vorschrift die in der Vergleichsfunktion festgelegt wurde.
 *
 * @param funktion  Die Vergleichsfunktion, die bestimmt wie die Studenten sortiert werden.
 */
void Personengenerator::sortiere_studenten(bool (*funktion)(Student*, Student*))
{
	sort(studenten.begin(), studenten.end(), funktion);
}
/**Schreibt Informationen zu den Studenten in der Studentenliste. */
void Personengenerator::schreibe_studenteninfos() const
{
  cout << endl;
  for (unsigned int i = 0; i < studenten.size(); i++)
  {
    studenten[i]->schreibe_informationen();
  }
//  for (unsigned int i = 0; i < studenten.size(); i++)
//  {
//    cout << setw(30) << left;
//    cout << studenten[i]->liefere_namen();
//    cout << setw(12) << right;
//    cout << studenten[i]->liefere_geburtstag();
//    cout << setw(10) << " " << setw(10) << left;
//    cout << studenten[i]->liefere_fachbereich();
//    cout << setw(10) << right;
//    cout << studenten[i]->liefere_matrikelnummer();
//    cout << endl;
//  }
}
/**Liefert eine zufaellige Postanschrift aus einem bestimmten Land.
 * 
 * @param landesname  Der Name des Landes das gewuenscht wird.
 * @return Eine zufaellige Postanschrift aus einem bestimmten Land.
 */
Postanschrift Personengenerator::liefere_zufalls_postanschrift(const string landesname) const
{
  return ortsliste.liefere_zufalls_postanschrift(landesname);
}
/**Liefert einen zufaellige Nationalitaet aus der Nationalitaetenliste.
 *
 * @return  Ein zufalls Nationalitaet aus der Nationalitaetenliste.
 */
string Personengenerator::liefere_zufalls_nationalitaet() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, nationalitaeten.size() - 1);
  string nationalitaet = nationalitaeten[index];
  return nationalitaet;
}
/**Liefere einen zufaelligen Fachbereich.
 *
 * @return Ein zufaelligen Fachbereich.
 */
string Personengenerator::liefere_zufalls_fachbereich() const
{
  stringstream fachbereich;
  fachbereich << "FB ";
  fachbereich << Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, 4);
  return fachbereich.str();
}
/**Liefert einen zufaellige Studiengang aus der Studiengangliste.
 *
 * @return  Ein zufalls Studiengang aus der Studiengangliste.
 */
string Personengenerator::liefere_zufalls_studiengang() const
{
  int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, studiengaenge.size() - 1);
  string studiengang = studiengaenge[index];
  return studiengang;
}
/**Liefere eine zufaellige Funktion des Beschaeftigten.
 *
 * @param geschlecht Das Geschlecht, welches die Bezeichnung der Funktion anpasst (maennliche oder weibliche Form).
 * @return Eine zufaellige Funktion des Beschaeftigten.
 */
string Personengenerator::liefere_zufalls_funktion(const char geschlecht) const
{
  string funktionw[3] = {"Schreibkraft", "Verwaltungsangestellte", "Laboringenieurin"};
  string funktionm[3] = {"Schreibkraft", "Verwaltungsangestellter", "Laboringenieur"};
  stringstream puffer;
  if (geschlecht == 'w')
    puffer << funktionw[Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 2)];
  else
    puffer << funktionm[Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(0, 2)];
  
  return puffer.str();
}
// eventuell Code
// weiterer Funktionen
