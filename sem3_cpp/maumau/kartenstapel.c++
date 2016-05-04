#include "kartenstapel.h"
// weitere Angaben
// Code der Konstruktoren

/** Erzeugt den Defaultobjekt mit Skatblatt aus 32 Karten.
 * Das franzoesische Blatt besteht aus den vier Farben Kreuz, Pik, Herz und Karo, jeweils mit den Karten Sieben, Acht, Neun, Zehn, Bube, Dame, Koenig und Ass.
 */
Kartenstapel::Kartenstapel()
{
  initialisiere_karten();
}
/**Erzeugt ein Kartenstapel mit einer Karte.
 *
 * @param eine_karte  Die Karte, die den Kartenstapel repraesentiert.
 */
Kartenstapel::Kartenstapel(const Karte& eine_karte)
{
  stapel.clear();
  stapel.reserve(1);
  stapel.push_back(Karte(eine_karte));
}
/**Erzeugt ein Kartenstapel aus den uebergeben Karten.
 *
 * @param ein_kartenstapel  Die Karten, aus denen der Kartenstapel bestehen soll.
 */
Kartenstapel::Kartenstapel(const vector<Karte>& ein_kartenstapel)
{
  stapel.clear();
  initialisiere_karten(ein_kartenstapel);
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei
 */
Kartenstapel::~Kartenstapel()
{
  stapel.clear();
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Kartenstapel::Kartenstapel(const Kartenstapel& original)
{
  stapel.clear();
  initialisiere_karten(original.stapel);
}

/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_kartenstapel  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Kartenstapel& Kartenstapel::operator=(const Kartenstapel& ein_kartenstapel)
{
  if (this != &ein_kartenstapel) // nur, wenn verschieden
  {
    stapel.clear(); // lösche alte Werte
    // speichere neue Werte
    initialisiere_karten(ein_kartenstapel.stapel);
  }
  return *this;
}
// Code der Methoden
/**Liefert die Anzahl der Karten im Kartenstapel.
 *
 * @return Die Anzahl der Karten im Kartenstapel.
 */
int Kartenstapel::liefere_anzahl_karten() const
{
  return stapel.size();
}
/**Liefert die Anzahl der Augen im Kartenstapel.
 *
 * @return Die Anzahl der Augen im Kartenstapel.
 */
int Kartenstapel::liefere_anzahl_augen() const
{
  int augen = 0;
  for (unsigned int i = 0; i < stapel.size(); i++)
    augen = augen + stapel[i].liefere_augen();
  return augen;
}
/** Schreibt die Information zu jeder Karte im Kartenstapel. Es wird die Farbe gefolgt von Kartenwert angegeben. */
void Kartenstapel::schreibe_karten() const
{
  for (unsigned int i = 0; i < stapel.size(); i++)
      cout << stapel[i].liefere_karten_info() << endl;
}
/**Liefert die Information zu einer bestimmten Karte im Kartenstapel. Es wird die Farbe gefolgt von Kartenwert zurueckgegeben.
 *
 * @param index Der Index der Karte im Kartenstapel (0...n).
 * @return Die Information zu einer bestimmten Karte im Kartenstapel. Es wird die Farbe gefolgt von Kartenwert zurueckgegeben.
 */
string Kartenstapel::liefere_karten_info(unsigned int index) const
{
  string karte;
  if (index < (stapel.size()))
    karte = stapel[index].liefere_karten_info();
  return karte;
}
/**Liefert die Kartenfarbe einer bestimmten Karte im Kartenstapel.
 *
 * @param index Der Index der Karte im Kartenstapel (0...n).
 * @return Die Kartenfarbe einer bestimmten Karte im Kartenstapel.
 */
string Kartenstapel::liefere_karten_farbe(unsigned int index) const
{
  string farbe;
  if (index < (stapel.size()))
    farbe = stapel[index].liefere_kartenfarbe();
  return farbe;
}
/**Fuegt eine Karte zum Kartenstapel hinzu.
 *
 * @param eine_karte Die Karte, die hinzugefuegt werden.
 */
void Kartenstapel::fuege_karte_hinzu(const Karte& eine_karte)
{
  stapel.insert(stapel.begin(), Karte(eine_karte));
}
/**Zeigt die obere Karte im dem Kartenstapel.
 *
 * @return Die obere Karte im dem Kartenstapel.
 */
const Karte& Kartenstapel::obere_karte_ist() const
{
  return stapel.front();
}
/**Liefert die obere Karte im dem Kartenstapel.
 *
 * @return Die obere Karte im dem Kartenstapel.
 */
Karte Kartenstapel::liefere_obere_karte()
{
  Karte karte = Karte(stapel.front());
  stapel.erase(stapel.begin());
  return karte;
}
/**Zeigt die untere Karte im dem Kartenstapel.
 *
 * @return Die untere Karte im dem Kartenstapel.
 */
const Karte& Kartenstapel::untere_karte_ist() const
{
  return stapel.back();
}
/**Liefert die untere Karte im dem Kartenstapel.
 *
 * @return Die untere Karte im dem Kartenstapel.
 */
Karte Kartenstapel::liefere_untere_karte()
{
  Karte karte = Karte(stapel.back());
  stapel.erase(stapel.end());
  return karte;
}
/**Prueft wie viele Karten im Kartenstapel im Kartenwert oder Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 *
 * @param eine_karte Die Karte, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die Anzahl der Karten, die mit der uebergeben Karte uebereinstimmen.
 */
int Kartenstapel::hat_passende_karten(const Karte& eine_karte) const
{
  int passende_karten = 0;
  if (liefere_anzahl_karten() > 0)
  {
    for (unsigned int i = 0; i < stapel.size(); i++)
      if (stapel[i] == eine_karte)
      {
        passende_karten++;
      }
  }
  return passende_karten;
}
/**Liefert die erste Karte, die im Kartenwert oder Kartenfarbe mit der uebergebenen Karte uebereinstimmt.
 *
 * @param eine_karte  Die Karte, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die erste Karte, die mit der uebergeben Karte uebereinstimmt.
 */
Karte Kartenstapel::liefere_passende_karte(const Karte& eine_karte)
{
  Karte passende_karten;
  for (unsigned int i = 0; i < stapel.size(); i++)
  {
    if ((stapel[i] == eine_karte))
    {
      passende_karten = stapel[i];
      if (stapel.size() > 1)
      {
        for (unsigned int j = i; j < stapel.size() - 1; j++)
          stapel[j] = stapel[j + 1];
        stapel.pop_back();
        i = stapel.size();
      }
      else
        stapel.clear();
    }
  }
  return passende_karten;
}
/**Zeigt alle Karten, die im Kartenwert oder Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 *
 * @param eine_karte  Die Karte, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die erste Karte, die mit der uebergeben Karte uebereinstimmt.
 */
vector<Karte> Kartenstapel::liefere_alle_passende_karte(const Karte& eine_karte) const
{
  vector<Karte> sieben;
  for (unsigned int i = 0; i < stapel.size(); i++)
    if (stapel[i] == eine_karte)
      sieben.push_back(stapel[i]);
  return sieben;
}
/**Prueft wie viele Karten im Kartenstapel in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 * Die Bube-Karten werden ausgeschlossen ("Bube auf Bube stinkt").
 *
 * @param eine_wunsch_karte Die Karte mit dem passenden Kartenfarbe, mit der die Karten im Kartenstapel verglichen werden.
 * @return Wie viele Karten im Kartenstapel in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 */
int Kartenstapel::hat_passende_wunsch_karten(const Karte& eine_wunsch_karte) const
{
  int passende_karten = 0;
  if (liefere_anzahl_karten() > 0)
  {
    for (unsigned int i = 0; i < stapel.size(); i++)
      if ((stapel[i].liefere_kartenwert() != "Bube") &&
        (stapel[i].liefere_kartenfarbe() == eine_wunsch_karte.liefere_kartenfarbe()))
        passende_karten++;
  }
  return passende_karten;
}
/**Liefert die erste Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 * Die Bube-Karten werden ausgeschlossen ("Bube auf Bube stinkt").
 *
 * @param eine_wunsch_karte Die Karte mit dem passenden Kartenfarbe, mit der die Karten im Kartenstapel verglichen werden.
 * @return Die erste Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 */
Karte Kartenstapel::liefere_wunsch_karte(const Karte& eine_wunsch_karte)
{
  Karte passende_karten;
  for (unsigned int i = 0; i < stapel.size(); i++)
  {
    if ((stapel[i].liefere_kartenwert() != "Bube") &&
      (stapel[i].liefere_kartenfarbe() == eine_wunsch_karte.liefere_kartenfarbe()))
    {
      passende_karten = stapel[i];
      if (stapel.size() > 1)
      {
        for (unsigned int j = i; j < stapel.size() - 1; j++)
          stapel[j] = stapel[j + 1];
        stapel.pop_back();
        i = stapel.size();
      }
      else
        stapel.clear();
    }
  }
  return passende_karten;
}
/**Liefert alle Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 * Die Bube-Karten werden ausgeschlossen ("Bube auf Bube stinkt").
 *
 * @param eine_wunsch_karte Die Karte mit dem passenden Kartenfarbe, mit der die Karten im Kartenstapel verglichen werden.
 * @return  Alle Karte im Kartenstapel, die in der Kartenfarbe mit der uebergeben Karte uebereinstimmen.
 */
vector<Karte> Kartenstapel::liefere_wunsch_karten(const Karte& eine_wunsch_karte) const
{
  vector<Karte> passende_karten;
  for (unsigned int i = 0; i < stapel.size(); i++)
    if ((stapel[i].liefere_kartenwert() != "Bube") &&
      (stapel[i].liefere_kartenfarbe() == eine_wunsch_karte.liefere_kartenfarbe()))
      passende_karten.push_back(stapel[i]);
  return passende_karten;
}
/**Liefert die Karte im Kartenstapel, die im Kartenwert und Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 *
 * @param die_karte Die Karte, die gesucht wird.
 * @return Die gesuchte Karte, die im Kartenwert und Kartenfarbe mit der uebergeben Karte uebereinstimmt.
 */
Karte Kartenstapel::liefere_bestimmte_karte(const Karte& die_karte)
{
  Karte passende_karten;
  for (unsigned int i = 0; i < stapel.size(); i++)
  {
    if ((stapel[i].liefere_kartenwert() == die_karte.liefere_kartenwert()) &&
      (stapel[i].liefere_kartenfarbe() == die_karte.liefere_kartenfarbe()))
    {
      passende_karten = stapel[i];
      if (stapel.size() > 1)
      {
        for (unsigned int j = i; j < stapel.size() - 1; j++)
          stapel[j] = stapel[j + 1];
        stapel.pop_back();
        i = stapel.size();
      }
      else
        stapel.clear();
    }
  }
  return passende_karten;
}
/**Liefert die Anzahl der Sieben-Karten, die der Kartenstapel hat.
 *
 * @return Die Anzahl der Sieben-Karten, die der Kartenstapel hat.
 */
int Kartenstapel::hat_sieben() const
{
  int hat_sieben = 0;
  if (liefere_anzahl_karten() > 0)
  {
    for (unsigned int i = 0; i < stapel.size(); i++)
      if (stapel[i].liefere_kartenwert() == "Sieben")
        hat_sieben++;
  }
  return hat_sieben;
}
/**Liefert die erste Sieben-Karte im Kartenstapel.
 *
 * @return Die erste Sieben-Karte im Kartenstapel.
 */
Karte Kartenstapel::liefere_sieben()
{
  Karte sieben;
  for (unsigned int i = 0; i < stapel.size(); i++)
  {
    if (stapel[i].liefere_kartenwert() == "Sieben")
    {
      sieben = stapel[i];
      if (stapel.size() > 1)
      {
        for (unsigned int j = i; j < stapel.size() - 1; j++)
          stapel[j] = stapel[j + 1];
        stapel.pop_back();
        i = stapel.size();
      }
    }
  }
  return sieben;
}
/**Zeigt alle Sieben-Karten, die im Kartenstapel vorkommen.
 *
 * @return  Alle Sieben-Karten, die im Kartenstapel vorkommen.
 */
vector<Karte> Kartenstapel::liefere_alle_sieben() const
{
  vector<Karte> sieben;
  for (unsigned int i = 0; i < stapel.size(); i++)
    if (stapel[i].liefere_kartenwert() == "Sieben")
      sieben.push_back(stapel[i]);
  return sieben;
}
/**Liefert die Anzahl der Ass-Karten, die der Kartenstapel hat.
 *
 * @return Die Anzahl der Ass-Karten, die der Kartenstapel hat.
 */
int Kartenstapel::hat_ass() const
{
  int hat_ass = 0;
  if (liefere_anzahl_karten() > 0)
  {
    for (unsigned int i = 0; i < stapel.size(); i++)
      if (stapel[i].liefere_kartenwert() == "Ass")
        hat_ass++;
  }
  return hat_ass;
}
/**Liefert die erste Ass-Karte im Kartenstapel.
 *
 * @return Die erste Ass-Karte im Kartenstapel.
 */
Karte Kartenstapel::liefere_ass()
{
  Karte ass;
  for (unsigned int i = 0; i < stapel.size(); i++)
  {
    if (stapel[i].liefere_kartenwert() == "Ass")
    {
      ass = stapel[i];
      if (stapel.size() > 1)
      {
        for (unsigned int j = i; j < stapel.size() - 1; j++)
          stapel[j] = stapel[j + 1];
        stapel.pop_back();
        i = stapel.size();
      }
    }
  }
  return ass;
}
/**Zeigt alle Ass-Karten, die im Kartenstapel vorkommen.
 *
 * @return Alle Ass-Karten, die im Kartenstapel vorkommen.
 */
vector<Karte> Kartenstapel::liefere_alle_asse() const
{
  vector<Karte> sieben;
  for (unsigned int i = 0; i < stapel.size(); i++)
    if (stapel[i].liefere_kartenwert() == "Ass")
      sieben.push_back(stapel[i]);
  return sieben;
}
/** Mischt den Kartenstapel durch. */
void Kartenstapel::mische_kartenstapel()
{
  vector<Karte> temp;
  temp.reserve(stapel.size());
  for ( ; stapel.size() > 0; )
  {
    int letzte =  (stapel.size() - 1);
    int index = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, static_cast<int>(stapel.size()));
    temp.push_back(stapel[index - 1]);
    stapel[index - 1] = stapel[letzte];
    stapel.pop_back();
  }
  stapel.clear();
  stapel = temp;
}

/**Initialisiert den Kartenstapel mit Skatblatt aus 32 Karten.
 * Das franzoesische Blatt besteht aus den vier Farben Kreuz, Pik, Herz und Karo, jeweils mit den Karten Sieben, Acht, Neun, Zehn, Bube, Dame, Koenig und Ass.
 */
void Kartenstapel::initialisiere_karten()
{
  string kartenwerte[8] = {"Ass", "Koenig", "Dame", "Bube", "Zehn", "Neun", "Acht", "Sieben"};
  string kartenfarben[4] = {"Herz", "Karo", "Pik", "Kreuz"};
  stapel.clear();
  stapel.reserve(32);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 4; j++)
      stapel.push_back(Karte(kartenwerte[i], kartenfarben[j]));
}
/**Initialisiert den Kartenstapel mit den uebergebenen, neuen Karten.
 *
 * @param neue_karten Die Karten, mit denen der Kartenstapel initialisiert werden soll.
 */
void Kartenstapel::initialisiere_karten(const vector<Karte>& neue_karten)
{
  stapel.clear();
  stapel.reserve(neue_karten.size());
  for (unsigned int i = 0; i < neue_karten.size(); i++)
    stapel.push_back(neue_karten[i]);
}
// eventuell Code
// weiterer Funktionen
/**Fuegt alle Karten aus dem Quellestapel zu dem Zielstapel hinzu und mischt danach den Zielstapel durch.
 * Der Quellestapel ist danach leer.
 *
 * @param zielstapel    Der Stapel, in die neuen Karten hinein sollen.
 * @param quellestapel  Der Stapel, aus denen die neuen Karten genommen werden.
 * @return Der neue Kartenstapel, der die Karten aus dem Zielstapel und Quellestapel enthaelt und gemischt wurde.
 */
Kartenstapel& operator<<(Kartenstapel& zielstapel, Kartenstapel& quellestapel)
{
  if (&zielstapel != &quellestapel) // nur, wenn verschieden
  {
    for (int i = 0; i < quellestapel.liefere_anzahl_karten();)
      zielstapel.fuege_karte_hinzu(quellestapel.liefere_obere_karte());
    zielstapel.mische_kartenstapel();
  }
  return zielstapel;
}