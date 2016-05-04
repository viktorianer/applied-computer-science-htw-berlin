#include <algorithm>

#include "kispieler.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt */
KISpieler::KISpieler()
{
}
/**Erzeugt einen KI-Spieler, der MauMau spielen kann.
 *
 * @param die_karten    Die Karten, die der KI-Spieler erhaelt.
 * @param ein_nickname  Ein Nickname fuer diesen Spieler.
 * @param ein_mensch    Ist Mensch- (true) oder KI-Spieler (false).
 */
KISpieler::KISpieler(const Kartenstapel& die_karten, const string ein_nickname, bool ein_mensch)
:Spieler(die_karten, ein_nickname, ein_mensch)
{
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
KISpieler::~KISpieler()
{
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
KISpieler::KISpieler(const KISpieler& original)
:Spieler(original)
{
}
// Code der Methoden
/**Steuert das Spielen einer passenden Karte zu der Ablage durch die KI.
 *
 * @param karte_auf_ablage  Die Karte, die auf der Ablage liegt.
 * @return Die Karte, die durch KI-Spieler gespielt wurde.
 */
Karte KISpieler::spiele_karte(const Karte& karte_auf_ablage)
{
  Karte gespielt;
  cout << liefere_nickname() << " hat ";
  if (karte_auf_ablage.liefere_kartenwert() == "Bube")
  {
    gespielt = spiele_wunsch_karte(karte_auf_ablage);
    cout << "folgende Karte mit der Wunschfarbe " << karte_auf_ablage.liefere_kartenfarbe()
      << " gespielt: " << gespielt.liefere_karten_info() << endl;
  }
  else if (hat_sieben() && karte_auf_ablage.liefere_kartenwert() == "Sieben")
  {
    gespielt = spiele_sieben();
    cout << "folgende Sieben-Karte gespielt: " << gespielt.liefere_karten_info() << endl;
  }
  else if (hat_ass() && karte_auf_ablage.liefere_kartenwert() == "Ass")
  {
    gespielt = spiele_ass();
    cout << "folgende Ass-Karte gespielt: " << gespielt.liefere_karten_info() << endl;
  }
  else
  {
    gespielt = spiele_passende_karte(karte_auf_ablage);
    cout << "folgende Karte gespielt: " << gespielt.liefere_karten_info() << endl;
  }
  return gespielt;
}
/**Liefert die erste Karte, die im Kartenwert oder Kartenfarbe mit der uebergebenen Karte uebereinstimmt.
 *
 * @param eine_karte  Die Karte, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die erste Karte, die mit der uebergeben Karte uebereinstimmt.
 */
Karte KISpieler::spiele_passende_karte(const Karte& eine_karte)
{
  return liefere_karten()->liefere_passende_karte(eine_karte);
}
/**Liefert die erste Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 * Die Bube-Karten werden ausgeschlossen ("Bube auf Bube stinkt").
 *
 * @param eine_wunsch_karte Die Karte mit dem passenden Kartenfarbe, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die erste Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 */
Karte KISpieler::spiele_wunsch_karte(const Karte& eine_wunsch_karte)
{
  return liefere_karten()->liefere_wunsch_karte(eine_wunsch_karte);
}
/**Liefert die erste Sieben-Karte im Kartenstapel.
 *
 * @return Die erste Sieben-Karte im Kartenstapel.
 */
Karte KISpieler::spiele_sieben()
{
  return liefere_karten()->liefere_sieben();
}
/**Liefert die erste Ass-Karte im Kartenstapel.
 *
 * @return Die erste Ass-Karte im Kartenstapel.
 */
Karte KISpieler::spiele_ass()
{
  return liefere_karten()->liefere_ass();
}
/**Berechnet die Anzahl der Kartenfarben, die die KI-Spieler hat und entscheidet dadurch, welche Wunschfarbe die KI-Spieler sich wuenschen.
 *
 * @return Die Wunschfarbe, die sich die KI-Spieler gewuenscht haben.
 */
string KISpieler::liefere_wunschfarbe() const
{
  string kartenfarben[4] = {"Herz", "Karo", "Pik", "Kreuz"};
  int farben[4] = {0, 0, 0, 0};
  for (int i = 0; i < liefere_karten()->liefere_anzahl_karten(); i++)
  {
    string die_farbe = liefere_karten()->liefere_karten_farbe(i);
    for (int j = 0; j < 4; j++)
    {
      if (die_farbe == kartenfarben[j])
        farben[j] += 1;
    }
  }
  int max = 0;
  string wunschfarbe = "";
  for (int j = 0; j < 4; j++)
  {
    if (farben[j] > max)
    {
      max = farben[j];
      wunschfarbe = kartenfarben[j];
    }
  }
  cout << "Er hat die Farbe <" << wunschfarbe << "> gewuenscht." << endl;
  return wunschfarbe;
}
// eventuell Code
// weiterer Funktionen
