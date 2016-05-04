#include "bruch.h"
// weitere Angaben
// Code der Konstruktoren
/**Erzeugt ein Bruch, der aus einem Zaehler = 1 und Nenner = 1 besteht.
 */
Bruch::Bruch()
{
  setze_zaehler(1);
  setze_nenner(1);
}
/**Erzeugt ein Bruch, der aus einem Zaehler und Nenner besteht.
 *
 * @param der_zaehler  Der Wert, der im Zaehler stehen soll.
 * @param der_nenner   Der Wert, der im Nenner stehen soll.
 */
Bruch::Bruch(int der_zaehler, int der_nenner)
{
  setze_zaehler(der_zaehler);
  setze_nenner(der_nenner);
  formatiere_bruch();
}
/**Erzeugt ein Bruch, der eine Kopie des uebergebenen Bruches ist.
 *
 * @param ein_bruch Der zu kopierende Bruch.
 */
Bruch::Bruch(const Bruch& ein_bruch)
{
  zaehler = ein_bruch.liefere_zaehler();
  nenner = ein_bruch.liefere_nenner();
}
/**
 * Erzeugt einen zufaelligen Bruch, der zwischen den beiden uebergebenen Bruechen liegt.
 *
 * @param die_linke_grenze   Ein Bruch, der den min. Wert fuer zufaelligen Bruch angibt.
 * @param die_rechte_grenze  Ein Bruch, der den max. Wert fuer zufaelligen Bruch angibt.
 */
Bruch::Bruch(const Bruch& die_linke_grenze, const Bruch& die_rechte_grenze)
{
  Bruch linke_grenze = die_linke_grenze;
  Bruch rechte_grenze = die_rechte_grenze;
  liefere_zufallsbruch(linke_grenze, rechte_grenze);
}
// Code der Methoden
 /**Gibt den Zaehler des Bruches zurueck.
 *
 * @return  Gibt den Zaehler des Bruches zurueck.
 */
int Bruch::liefere_zaehler() const
{
  return zaehler;
}
/**Gibt den Nenner des Bruches zurueck.
 *
 * @return  Gibt den Nenner des Bruches zurueck.
 */
int Bruch::liefere_nenner() const
{
  return nenner;
}
/**Gibt den Bruch als string zurueck.
 *
 * @return  Gibt den Zaehler und Nenner des Bruches, getrennt durch ein / als string zurueck.
 */
string Bruch::liefere_bruch_als_text()
{
  stringstream streampuffer;
  string bruch = "";
  streampuffer.str("");
  formatiere_bruch();
  if (liefere_nenner() == 1)
  {
   if (liefere_zaehler() == liefere_nenner())
    bruch = "1";
   else
   {
     streampuffer << liefere_zaehler();
     bruch = streampuffer.str();
   }
  }
  else
  {
    streampuffer << liefere_zaehler() << "/" << liefere_nenner();
    bruch = streampuffer.str();
  }
  return bruch;
}
/**Kuerzt einen Bruch (teilerfremd).
 */
void Bruch::kuerze_bruch()
{
  int der_groesster_gemeinsamer_teiler = groesster_gemeinsamer_teiler(liefere_zaehler(), liefere_nenner());
  setze_zaehler(liefere_zaehler() / der_groesster_gemeinsamer_teiler);
  setze_nenner(liefere_nenner() / der_groesster_gemeinsamer_teiler);
}
/**Addition zweier Brueche.
 *
 * @param bruch     Der Bruch, der zuaddiert werden soll.
 * @return  Gibt das Ergebnis der Addition zurueck.
 */
Bruch Bruch::operator+(const Bruch& bruch) const
{
  Bruch ergebnis = Bruch();
  int kgv = kleinstes_gemeinsames_vielfaches(liefere_nenner(), bruch.liefere_nenner());
  ergebnis.setze_zaehler(liefere_zaehler() * kgv / liefere_nenner() + bruch.liefere_zaehler() * kgv / bruch.liefere_nenner());
  ergebnis.setze_nenner(kgv);
  return ergebnis;
}
/**Subtraktion zweier Brueche.
 *
 * @param bruch     Der Bruch, der abgezogen werden soll.
 * @return  Gibt das Ergebnis der Subtraktion zurueck.
 */
Bruch Bruch::operator-(const Bruch& bruch) const
{
  Bruch ergebnis = Bruch();
  int kgv = kleinstes_gemeinsames_vielfaches(liefere_nenner(), bruch.liefere_nenner());
  ergebnis.setze_zaehler(liefere_zaehler() * kgv / liefere_nenner() - bruch.liefere_zaehler() * kgv / bruch.liefere_nenner());
  ergebnis.setze_nenner(kgv);
  return ergebnis;
}
/**Multiplikation zweier Brueche.
 *
 * @param bruch     Der Bruch, mit dem multipliziert werden soll.
 * @return  Gibt das Ergebnis der Multiplikation zurueck.
 */
Bruch Bruch::operator*(const Bruch& bruch) const
{
  Bruch ergebnis = Bruch();
  ergebnis.setze_zaehler(liefere_zaehler() * bruch.liefere_zaehler());
  ergebnis.setze_nenner(liefere_nenner() * bruch.liefere_nenner());
  return ergebnis;
}
/**Division zweier Brueche.
 *
 * @param bruch     Der Bruch, mit dem dividiert werden soll.
 * @return  Gibt das Ergebnis der Division zurueck.
 */
Bruch Bruch::operator/(const Bruch& bruch) const
{
  Bruch ergebnis = Bruch();
  ergebnis.setze_zaehler(liefere_zaehler() * bruch.liefere_nenner());
  ergebnis.setze_nenner(liefere_nenner() * bruch.liefere_zaehler());
  return ergebnis;
}
/**
 * Vergleicht diesen Bruch mit einem anderen auf gleichheit.
 * @param bruch Ein Bruch, mit dem dieser Bruch verglichen werden soll.
 * @return Liefert true wenn beide Bruche gleich gross sind und false wenn beide unterschiedluch gross sind.
 */
bool Bruch::operator==(const Bruch& bruch) const
{
  Bruch temp_dieser_bruch;
  Bruch temp_uebergaebener_bruch;
  int kgv = kleinstes_gemeinsames_vielfaches(liefere_nenner(), bruch.liefere_nenner());
  temp_dieser_bruch.setze_zaehler(liefere_zaehler() * kgv / liefere_nenner());
  temp_dieser_bruch.setze_nenner(kgv);
  temp_uebergaebener_bruch.setze_zaehler(bruch.liefere_zaehler() * kgv / bruch.liefere_nenner());
  temp_uebergaebener_bruch.setze_nenner(kgv);
  return temp_dieser_bruch.liefere_zaehler() == temp_uebergaebener_bruch.liefere_zaehler();
}
/**
 * Vergleicht diesen Bruch mit einem anderen auf kleiner als.
 * @param bruch Ein Bruch, mit dem dieser Bruch verglichen werden soll.
 * @return Liefert true wenn dieser Bruch kleiner ist und false wenn nicht.
 */
bool Bruch::operator<(const Bruch& bruch) const
{
  Bruch temp_dieser_bruch;
  Bruch temp_uebergaebener_bruch;
  int kgv = kleinstes_gemeinsames_vielfaches(liefere_nenner(), bruch.liefere_nenner());
  temp_dieser_bruch.setze_zaehler(liefere_zaehler() * kgv / liefere_nenner());
  temp_dieser_bruch.setze_nenner(kgv);
  temp_uebergaebener_bruch.setze_zaehler(bruch.liefere_zaehler() * kgv / bruch.liefere_nenner());
  temp_uebergaebener_bruch.setze_nenner(kgv);
  return temp_dieser_bruch.liefere_zaehler() < temp_uebergaebener_bruch.liefere_zaehler();
}
/**
 * Vergleicht diesen Bruch mit einem anderen auf groesser als.
 * @param bruch Ein Bruch, mit dem dieser Bruch verglichen werden soll.
 * @return Liefert true wenn dieser Bruch groesser ist und false wenn nicht.
 */
bool Bruch::operator>(const Bruch& bruch) const
{
  Bruch temp_dieser_bruch = Bruch(liefere_zaehler(), liefere_nenner());
  return !(temp_dieser_bruch < bruch || temp_dieser_bruch == bruch);
}

/**Setzt die uebergebene Zahl in den Zaehler.
 *
 * @param der_zaehler  Die Zahl, die im Zaehler gespeichert werden soll.
 */
void Bruch::setze_zaehler(int der_zaehler)
{
  zaehler = der_zaehler;
}
/**Setzt die uebergebene Zahl in den Nenner.
 *
 * @param der_nenner  Die Zahl, die im Nenner gespeichert werden soll.
 */
void Bruch::setze_nenner(int der_nenner)
{
  bool input_ok = (der_nenner != 0);
  if (input_ok)
    nenner = der_nenner;
  else
    cout << endl << "Der Nenner darf nicht 0 sein!" << endl;
    //throw invalid_argument;
}
/**Formatiert den Bruch.
 * Der Bruch wird im folgenden Sinne normiert:
 * - Zaehler und Nenner sollen teilerfremd sein.
 * - ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zaehler steht.
 * - wenn Nenner den Wert 1 hat, wird statt Zaehler/Nenner nur Zaehler ausgegeben.
 * - wenn Zaehler und Nenner denselben Wert haben, wird statt Zaehler/Nenner der Wert 1 ausgegeben.
 *
 */
void Bruch::formatiere_bruch()
{
  if (nenner < 0)
  {
    if (zaehler > 0)
   {
     zaehler = zaehler * (-1);
     nenner = nenner * (-1);
   }
   else
     nenner = nenner * (-1);
  }
}
/**Berechnet das kleinste gemeinsame Vielfache von zwei Bruechen.
 *
 * @param zahl_a   Der Nenner des ersten Bruches.
 * @param zahl_b   Der Nenner des zweiten Bruches.
 * @return  Gibt das kleinste gemeinsame Vielfache zurueck.
 */
int Bruch::kleinstes_gemeinsames_vielfaches(int zahl_a, int zahl_b) const
{
  int tmp;
  for(int i = 1; ; i++)
  {  // keine Endlosschleife, es gibt naemlich immer eine Loesung
      tmp = zahl_a;
      zahl_a *= i;
      if((zahl_a % zahl_b) == 0)
      {    // Mit Hilfe der Restfunktion pruefen ob beide Zahlen ohne Rest teilbar sind
          return zahl_a;   // Gibt kleinstes gemeinsames Vielfaches zurueck
      }
      zahl_a = tmp;
  }
}
/**Berechnet den Größten gemeinsamen Teiler von zwei Bruechen.
 *
 * @param zahl_a   Der Nenner des ersten Bruches.
 * @param zahl_b   Der Nenner des zweiten Bruches.
 * @return  Gibt den Größter gemeinsamer Teiler zurueck.
 */
int Bruch::groesster_gemeinsamer_teiler(int zahl_a, int zahl_b) const
{
  int der_groesster_gemeinsamer_teiler = 0;
  if (zahl_a == zahl_b || zahl_b == 0)
    der_groesster_gemeinsamer_teiler = zahl_a;
  else
    der_groesster_gemeinsamer_teiler = groesster_gemeinsamer_teiler(zahl_b, (zahl_a % zahl_b));
  return der_groesster_gemeinsamer_teiler;
}
/**Liefert einen Zufallsbruch aus einen angegebenen Bereich. Zufor muss der Zufallsgenerator initialisiert werden.
 *
 * Bitte beachten Sie, dass rand() in der Regel keine sehr gute Streuung liefert.
 * Für statistische Zwecke sollten Sie deshalb nicht auf die Standardbibliothek zurückgreifen.
 * (Die Funktion rand() liefert einen Wert zwischen 0 und RAND_MAX.)
 *
 * @param min   minimale Größe des Bruches.
 * @param max   maximale Größe des Bruches.
 * @return  Die Zufallsbruch wird zurückgegeben.
 */
void Bruch::liefere_zufallsbruch(const Bruch& min, const Bruch& max)
{
  Bruch temp_min_bruch = min;
  temp_min_bruch.formatiere_bruch();
  Bruch temp_max_bruch = max;
  temp_max_bruch.formatiere_bruch();
  if (temp_min_bruch > temp_max_bruch)
  {
    Bruch ablage = temp_min_bruch;
    temp_min_bruch = temp_max_bruch;
    temp_max_bruch = ablage;
  }
  int max_nenner = temp_max_bruch.liefere_nenner() * 10;
  nenner = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(temp_min_bruch.liefere_nenner(), max_nenner);
  int max_zaehler = nenner * temp_max_bruch.liefere_zaehler() / temp_max_bruch.liefere_nenner() + 0.0;
  int min_zaehler = nenner * temp_min_bruch.liefere_zaehler() / temp_min_bruch.liefere_nenner() + 0.0;
  min_zaehler = static_cast<int>(ceil(min_zaehler));
  zaehler = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(min_zaehler, max_zaehler);
  kuerze_bruch();
}
// eventuell Code
// weiterer Funktionen
/**
 * Sortiert ein Array mit zufaellig erzeugten Bruechen aufsteigend.
 * @param array   \c Input:  \n Ein Array mit Bruechen, das sortiert werden soll.\n
 *                \c Output: \n Ein Array mit Bruechen, das sortiert wurde.\n
 * @param laenge  Die laenge des Arrays.
 */
void sortiere_aufsteigend(Bruch array[], int laenge)
{
  int index_max = 0;
  Bruch ablage;
  for (int i = laenge - 1; i > 0; i--)
  {
    index_max = 0;
    for (int j = 0; j <= i; j++)
      if (array[j] > array[index_max])
        index_max = j;
    if (array[index_max] > array[i])
    {
      ablage = array[i];
      array[i] = array[index_max];
      array[index_max] = ablage;
    }
  }
}
/**
 * Sortiert ein Array mit zufaellig erzeugten Bruechen absteigend.
 * @param array   \c Input:  \n Ein Array mit Bruechen, das sortiert werden soll.\n
 *                \c Output: \n Ein Array mit Bruechen, das sortiert wurde.\n
 * @param laenge  Die laenge des Arrays.
 */
void sortiere_absteigend(Bruch array[], int laenge)
{
  int index_max = 0;
  Bruch ablage;
  for (int i = laenge - 1; i > 0; i--)
  {
    index_max = 0;
    for (int j = 0; j <= i; j++)
      if (array[j] < array[index_max])
        index_max = j;
    if (array[index_max] < array[i])
    {
      ablage = array[i];
      array[i] = array[index_max];
      array[index_max] = ablage;
    }
  }
}