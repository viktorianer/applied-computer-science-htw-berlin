#include "lottoziehung.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt Lottoziehung mit 6 zufaelligen Lottozahlen 
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 */
Lottoziehung::Lottoziehung()
{
  anzahl_lottozahlen = 6;
  initialisiere_lottozahlen(1, 49);
}
/**Erzeugt eine zufaellige Lottoziehung mit 6 zufaelligen Lottozahlen zwischen min und max.
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von min bis max,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 * 
 * @param min           minimale Groessee der Lottozahl.
 * @param max           maximale Groessee der Lottozahl.
 */
Lottoziehung::Lottoziehung(int min, int max)
{
  anzahl_lottozahlen = 6;
  if (min > 0 && max > min)
    initialisiere_lottozahlen(min, max);
}
/**Erzeugt eine Lottoziehung aus 6 uebergebenen Lottozahlen.
 * Die uebergebene Lottoziehung muss aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49 bestehen,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 *
 * @param eine_ziehung           ein Array aus 6 Zahlen das die Lottozahlen einer Lottoziehung repraesentiert.
 */
Lottoziehung::Lottoziehung(const int *eine_ziehung)
{
  anzahl_lottozahlen = 6;
  if (pruefe_lottozahlen(eine_ziehung))
    initialisiere_lottozahlen(eine_ziehung);
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Lottoziehung::~Lottoziehung()
{
  delete [] lottoziehung;
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Lottoziehung::Lottoziehung(const Lottoziehung& original)
{
  anzahl_lottozahlen = original.anzahl_lottozahlen;
  initialisiere_lottozahlen(original.lottoziehung);
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param eine_lottoziehung  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Lottoziehung& Lottoziehung::operator=(const Lottoziehung& eine_lottoziehung)
{
  if (this != &eine_lottoziehung) // nur, wenn verschieden
  {
    delete [] lottoziehung; // lösche alte Werte
    anzahl_lottozahlen = eine_lottoziehung.anzahl_lottozahlen; // speichere neue Werte
    initialisiere_lottozahlen(eine_lottoziehung.lottoziehung);
  }
  return *this;
}
// Code der Methoden
/** Schreibt die Lottozahlen dieser Ziehung auf den Bildschirm. */
void Lottoziehung::schreibe_lottozahlen() const
{
  cout << "[ ";
  for (int i = 0; i < anzahl_lottozahlen; i++)
    cout << lottoziehung[i] << " ";
  cout << "]" << endl;
}

/**Liefert die Haeufigkeitsverteilung der Werte eines zweidimensionale int-Arrays.
 *
 * @param haeufigkeitsverteilung   	\c Input:   Die Adresse, an der die Haeufigkeitsverteilung gespeichert wird.\n
 *			                      			\c Output:  Die Adresse, an der die Haeufigkeitsverteilung gespeichert ist.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottoziehung::haeufigkeitsverteilung(int *haeufigkeitsverteilung) const
{
  Statistik::haeufigkeitsverteilung(lottoziehung, anzahl_lottozahlen, haeufigkeitsverteilung);
}
/**Liefert die Haeufigkeitsverteilung der Minima eines zweidimensionale char-Arrays.
 *
 * @param minima   			\c Input:   Die Adresse, an der die Haeufigkeitsverteilung der Minima gespeichert wird.\n
 *			                \c Output:  Die Adresse, an der die Haeufigkeitsverteilung der Minima gespeichert ist.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottoziehung::haeufigkeitsverteilung_minima(int *minima) const
{
	Statistik::haeufigkeitsverteilung_minima(lottoziehung, anzahl_lottozahlen, minima);
}
/**Liefert die Haeufigkeitsverteilung der Maxima eines zweidimensionale char-Arrays.
 *
 * @param maxima		   	\c Input:   Die Adresse, an der die Haeufigkeitsverteilung der Maxima gespeichert wird.\n
 *			            		\c Output:  Die Adresse, an der die Haeufigkeitsverteilung der Maxima gespeichert wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottoziehung::haeufigkeitsverteilung_maxima(int *maxima) const
{
	Statistik::haeufigkeitsverteilung_maxima(lottoziehung, anzahl_lottozahlen, maxima);
}
/**Sucht die Lottoziehung nach einem bestimmten int-Wert durch und gibt aus ob dieser vorhanden ist.
 *
 * @param gesuchte_zahl   Der int-Wert nach dem in der Lottoziehung gesucht werden soll.
 * @return	Gibt an ob ein bestimmter int-Wert in der Lottoziehung enthalten ist (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Lottoziehung::zahl_in_lottoziehung(int gesuchte_zahl) const
{
  return Statistik::ist_zahl_im_array(lottoziehung, anzahl_lottozahlen, gesuchte_zahl);
}
/**Gibt an ob in der Lottoziehung alle Zahlen gerade sind.
 *
 * @return	Gibt an ob alle Werte in der Lottoziehung gerade sind (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Lottoziehung::sind_alle_zahlen_gerade() const
{
  return Statistik::sind_alle_zahlen_gerade(lottoziehung, anzahl_lottozahlen);
}
/**Gibt an ob in der Lottoziehung alle Zahlen ungerade sind.
 *
 * @return	Gibt an ob alle Werte in der Lottoziehung ungerade sind (true) oder nicht (false).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
bool Lottoziehung::sind_alle_zahlen_ungerade() const
{
  return Statistik::sind_alle_zahlen_ungerade(lottoziehung, anzahl_lottozahlen);
}
/**Unter der Länge einer Lottoziehung wir die Differenz zwischen der größten und der<br>
 * kleinsten gezogenen Zahl verstanden. Gibt die Laenge einer Lottoziehung zurueck.
 *
 * @return	Die Laenge einer Lottoziehung.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int Lottoziehung::laenge_lottoziehung() const
{
	int laenge = 0;
	const int *minima = Statistik::liefere_min(lottoziehung, anzahl_lottozahlen);
	const int *maxima = Statistik::liefere_max(lottoziehung, anzahl_lottozahlen);
	laenge = abs(*minima - *maxima);
	return laenge;
}
/**Zwei direkt aufeinander folgende ganze Zahlen sind ein Zwilling (zum Beispiel [7, 8]<br>
 * oder [13, 14]), drei direkt aufeinander folgende ganze Zahlen sind Drilling (zum Beispiel [3, 4,5] oder [29, 30, 31]).<br>
 * Allgemein heißt für k >= 1 eine Folge k direkt aufeinander folgender ganzer Zahlen ein k-ling.<br>
 * Eine Lottoziehung heißt eine k-Ziehung, wenn sie einen k-ling enthält, aber keinen (k+1)-ling.<br>
 * Die Funktion sucht in der Lottoziehung nach k-ling und gibt deren Laenge zurueck.
 *
 * @return Die Laenge des k-lings.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int Lottoziehung::zahlenpaar()
{
	int zahlenpaar = 0;
	int folge = 0;
	qsort(lottoziehung, anzahl_lottozahlen, sizeof(int), Utilities::vergleiche);
	for (int i = 0; i < anzahl_lottozahlen; i++)
	{
		if ((lottoziehung[i] + 1) == lottoziehung[i + 1])
			folge = folge + 1;
		else
		{
			if (folge > zahlenpaar)
			zahlenpaar = folge;
			folge = 0;
		}
	}
	return zahlenpaar;
}
/**Vergleicht die Lottoziehung auf die Anzahl der Uebereinstimmungen mit der uebergebenen Lottoziehung.
 *
 * @param eine_lottoziehung   			Die Lottoziehung, mit der verglichen werden soll.
 * @return Anzahl der Uebereinstimmungen der beiden Lottoziehungen.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int Lottoziehung::vergleiche_lottoziehung(const Lottoziehung& eine_lottoziehung) const
{
	int uebereinstimmungen = 0;
	for (int i = 0; i < anzahl_lottozahlen; i++)
	{
		if (Statistik::ist_zahl_im_array(lottoziehung, anzahl_lottozahlen, eine_lottoziehung.lottoziehung[i]))
		{
			uebereinstimmungen = uebereinstimmungen + 1;
		}
	}
	return uebereinstimmungen;
}

/**Per Zufallszahlengenerator wird eine Lottoziehung erzeugt.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.
 *
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottoziehung::initialisiere_lottozahlen(int min, int max)
{
  lottoziehung = new int[anzahl_lottozahlen];
  bool zahl_ungueltig = false;
  for (int lottozahl = 0; lottozahl < anzahl_lottozahlen; lottozahl++)
  {
  	lottoziehung[lottozahl] = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(min, max);
  	if (lottozahl != 0 && zahl_ungueltig == false)
  	{
  		zahl_ungueltig = Statistik::ist_zahl_im_array(lottoziehung, lottozahl, lottoziehung[lottozahl]);
  		if (zahl_ungueltig == true)
  		{
  			lottozahl = lottozahl - 1;
  	  	zahl_ungueltig = false;
  		}
  	}
  }
}
/**Initialisiert die Lottoziehung mit dem im Array uebergebenen Lottoziehungen.
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottoziehung::initialisiere_lottozahlen(const int *die_lottozahlen)
{
  lottoziehung = new int[anzahl_lottozahlen];
  for (int i = 0; i < anzahl_lottozahlen; i++)
    lottoziehung[i] = die_lottozahlen[i];
}
/**Prueft das Array von Zahlen, ob diese eine richtige Lottoziehung entsprechen.
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 *
 * @param min           minimale Größe der Lottozahl.
 * @param max           maximale Größe der Lottozahl.
 */
bool Lottoziehung::pruefe_lottozahlen(const int *lottozahlen) const
{
  int *eine_lottoziehung = new int[anzahl_lottozahlen];
  Arrays::initialisiere_int_array(eine_lottoziehung, anzahl_lottozahlen, 0);
  int lottozahl = 0;
  bool lottozahlen_gueltig = false;
  do
  {
    lottozahlen_gueltig = Statistik::ist_zahl_im_array(eine_lottoziehung, lottozahl, lottozahlen[lottozahl]);
    if (lottozahlen_gueltig == false)
      eine_lottoziehung[lottozahl] = lottozahlen[lottozahl];
    lottozahl++;
  } while(lottozahlen_gueltig == false && lottozahl < anzahl_lottozahlen);
  if (lottozahlen_gueltig == true)
    cout << "Die Lottozahlen sind ungueltig! Lottoziehung wurde nicht erzeugt." << endl;
  delete [] eine_lottoziehung;
  return !lottozahlen_gueltig;
}
// eventuell Code
// weiterer Funktionen