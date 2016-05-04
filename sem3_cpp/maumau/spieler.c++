#include <algorithm>

#include "spieler.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt mit einem Spieler und 32 Skat Karten. */
Spieler::Spieler()
{
  karten = new Kartenstapel();
  nickname = "anonymous";
  ist_mensch = true;
}
/**Erzeugt einen Spieler, der die Karten und einen Nicknamen bekommt.
 *
 * @param die_karten    Die Karten, die der Spieler erhaelt.
 * @param ein_nickname  Ein Nickname fuer diesen Spieler.
 * @param ein_mensch    Ist Mensch- (true) oder KI-Spieler (false).
 */
Spieler::Spieler(const Kartenstapel& die_karten, const string ein_nickname, bool ein_mensch)
{
  karten = new Kartenstapel(die_karten);
  nickname = ein_nickname;
  ist_mensch = ein_mensch;
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Spieler::~Spieler()
{
  delete karten;
  karten = 0;
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Spieler::Spieler(const Spieler& original)
{
  karten = new Kartenstapel(*original.karten);
  nickname = original.nickname;
  ist_mensch = original.ist_mensch;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_spieler  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Spieler& Spieler::operator=(const Spieler& ein_spieler)
{
  if (this != &ein_spieler) // nur, wenn verschieden
  {
    karten = new Kartenstapel(*ein_spieler.karten); // speichere neue Werte
    nickname = ein_spieler.nickname;
    ist_mensch = ein_spieler.ist_mensch;
  }
  return *this;
}
// Code der Methoden
/**Liefert Nichname des Spielers.
 *
 * @return Der Nichname des Spielers.
 */
string Spieler::liefere_nickname() const
{
  return nickname;
}
/**Liefert ob der Spieler ein Mensch- (true) oder KI-Spieler (false) ist.
 *
 * @return Mensch- (true) oder KI-Spieler (false).
 */
bool Spieler::liefere_ob_mensch() const
{
  return ist_mensch;
}
/**Liefert die Anzahl der Karten auf der Hand.
 *
 * @return Die Anzahl der Karten auf der Hand.
 */
int Spieler::liefere_anzahl_karten() const
{
  return karten->liefere_anzahl_karten();
}
/**Liefert die Anzahl augen, die alle Karten auf der Hand haben.
 * 
 * @return Die Anzahl augen, die alle Karten auf der Hand haben.
 */
int Spieler::liefere_anzahl_augen() const
{
  return karten->liefere_anzahl_augen();
}
/**Liefert die Information zu einer bestimmten Karte im Kartenstapel des Spielers. Es wird die Farbe gefolgt von Kartenwert zurueckgegeben.
 *
 * @param index Der Index der Karte im Kartenstapel (0...n).
 * @return Die Information zu einer bestimmten Karte im Kartenstapel des Spielers. Es wird die Farbe gefolgt von Kartenwert zurueckgegeben.
 */
string Spieler::liefere_karten_info(unsigned int index) const
{
  return karten->liefere_karten_info(index);
}
/**Liefert alle Karten des Spielers.
 *
 * @return Alle Karten des Spielers.
 */
Kartenstapel *Spieler::liefere_karten() const
{
  return karten;
}
/**Steuert das Spielen einer passenden Karte zu der Ablage.
 *
 * @param karte_auf_ablage  Die Karte, die auf der Ablage liegt.
 * @return Die Karte, die gespielt wurde.
 */
Karte Spieler::spiele_karte(const Karte& karte_auf_ablage)
{
  Karte gespielt;
  if (karte_auf_ablage.liefere_kartenwert() == "Bube")
    gespielt = spiele_wunsch_karte(karte_auf_ablage);
  else if (hat_sieben() && karte_auf_ablage.liefere_kartenwert() == "Sieben" &&
    Eingaben::erfasse_antwort("Moechten Sie ihre Sieben-Karte spielen?", "jn"))
    gespielt = spiele_sieben();
  else if (hat_ass() && karte_auf_ablage.liefere_kartenwert() == "Ass" &&
    Eingaben::erfasse_antwort("Moechten Sie ihre Ass-Karte spielen?", "jn"))
    gespielt = spiele_ass();
  else
    gespielt = spiele_passende_karte(karte_auf_ablage);
  return gespielt;
}
/**Prueft wie viele Karten der Spieler hat, die im Kartenwert oder Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 *
 * @param eine_karte Die Karte, mit der die Karten im Kartenstapel des Spielers verglichen werden.
 * @return Die Anzahl der Karten, die mit der uebergeben Karte uebereinstimmen.
 */
int Spieler::hat_passende_karten(const Karte& eine_karte) const
{
  return karten->hat_passende_karten(eine_karte);
}
/**Prueft wie viele Karten im Kartenstapel des Spielers in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 * Die Bube-Karten werden ausgeschlossen ("Bube auf Bube stinkt").
 *
 * @param eine_wunsch_karte Die Karte mit dem passenden Kartenfarbe, mit der die Karten im Kartenstapel des Spielers verglichen werden.
 * @return Wie viele Karten im Kartenstapel des Spielers in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 */
int Spieler::hat_passende_wunsch_karten(const Karte& eine_wunsch_karte) const
{
  return karten->hat_passende_wunsch_karten(eine_wunsch_karte);
}
/**Liefert die Anzahl der Sieben-Karten, die der Kartenstapel des Spielers hat.
 *
 * @return Die Anzahl der Sieben-Karten, die der Kartenstapel des Spielers hat.
 */
int Spieler::hat_sieben() const
{
  return karten->hat_sieben();
}
/**Liefert die Anzahl der Ass-Karten, die der Kartenstapel des Spielers hat.
 *
 * @return Die Anzahl der Ass-Karten, die der Kartenstapel des Spielers hat.
 */
int Spieler::hat_ass() const
{
  return karten->hat_ass();
}
/**Fuegt eine Karte zum Kartenstapel des Spielers hinzu.
 *
 * @param eine_karte Die Karte, die hinzugefuegt werden.
 */
void Spieler::nimm_karte(const Karte& eine_karte)
{
  karten->fuege_karte_hinzu(eine_karte);
}
/**Fragt den Spieler, welche Kartenfarbe er sich wuenscht.
 *
 * @return Die Kartenfarbe, die durch Spieler gewuenscht wurde.
 */
string Spieler::liefere_wunschfarbe() const
{
  string kartenfarben[4] = {"Herz", "Karo", "Pik", "Kreuz"};
  Menue menue(4, kartenfarben);
  int wahl = menue.waehle_aus_menue();
  cout << "Er hat die Farbe <" << kartenfarben[wahl - 1] << "> gewuenscht." << endl;
  return kartenfarben[wahl - 1];
}

/**Fragt den Spieler, welche Karte, die passend zur der uebergebenen Karte ist, er spielen will.
 *
 * @param eine_karte  Die Karte, zu der passend eine Karte gespielt werden soll.
 * @return Die Karte, die passend gespielt wurde.
 */
Karte Spieler::spiele_passende_karte(const Karte& eine_karte)
{
  vector<Karte> passende_karten = karten->liefere_alle_passende_karte(eine_karte);
  int wahl = 1;
  if (passende_karten.size() > 1)
    wahl = waehle_karte(passende_karten);
  cout << liefere_nickname() << " hat folgende Karte gespielt: "
      << passende_karten[wahl - 1].liefere_karten_info() << endl;
  return karten->liefere_bestimmte_karte(passende_karten[wahl - 1]);;
}
/**Fragt den Spieler, welche Karte, die passend zur der Wunschfarbe der uebergeben Karte ist, er spielen will.
 *
 * @param eine_wunsch_karte Die Karte mit der Wunschfarbe, zu der passend eine Karte gespielt werden soll.
 * @return Die Karte, die passend der Wunschfarbe gespielt wurde.
 */
Karte Spieler::spiele_wunsch_karte(const Karte& eine_wunsch_karte)
{
  vector<Karte> passende_karten = karten->liefere_wunsch_karten(eine_wunsch_karte);
  int wahl = 1;
  if (passende_karten.size() > 1)
    wahl = waehle_karte(passende_karten);
  cout << liefere_nickname() << " hat folgende Karte mit der Wunschfarbe "
      << eine_wunsch_karte.liefere_kartenfarbe()
      << " gespielt: " << passende_karten[wahl - 1].liefere_karten_info() << endl;
  return karten->liefere_bestimmte_karte(passende_karten[wahl - 1]);
}
/**Fragt den Spieler, welche Sieben-Karte er spielen will.
 *
 * @return Die Sieben-Karte, die gespielt wurde.
 */
Karte Spieler::spiele_sieben()
{
  vector<Karte> passende_karten = karten->liefere_alle_sieben();
  int wahl = 1;
  if (passende_karten.size() > 1)
    wahl = waehle_karte(passende_karten);
  cout << liefere_nickname() << " hat folgende Sieben-Karte gespielt: "
      << passende_karten[wahl - 1].liefere_karten_info() << endl;
  return karten->liefere_bestimmte_karte(passende_karten[wahl - 1]);
}
/**Fragt den Spieler, welche Ass-Karte er spielen will.
 *
 * @return Die Ass-Karte, die gespielt wurde.
 */
Karte Spieler::spiele_ass()
{
  vector<Karte> passende_karten = karten->liefere_alle_asse();
  int wahl = 1;
  if (passende_karten.size() > 1)
    wahl = waehle_karte(passende_karten);
  cout << liefere_nickname() << " hat folgende Ass-Karte gespielt: "
      << passende_karten[wahl - 1].liefere_karten_info() << endl;
  return karten->liefere_bestimmte_karte(passende_karten[wahl - 1]);
}
/**Erzeugt ein Menue aus den passenden_karten, die nach der Wahl gespielt werden sollen.
 *
 * @param passende_karten Die Karten, die gespielt werden können.
 * @return Der Index der Karte, die gespielt werden soll.
 */
int Spieler::waehle_karte(const vector<Karte>& passende_karten) const
{
  int wahl = 1;
  cout << "Bitte geben Sie an, welche Karte sie spielen wollen...";
  string *menuepunkte = new string[passende_karten.size()];
  for (unsigned int i = 0; i < passende_karten.size(); i++)
      menuepunkte[i] = passende_karten[i].liefere_karten_info();
  Menue menue(passende_karten.size(), menuepunkte);
  wahl = menue.waehle_aus_menue();
  delete [] menuepunkte;
  menuepunkte = 0;
  return wahl;
}
// eventuell Code
// weiterer Funktionen
