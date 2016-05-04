#include "lottogenerator.h"
#include "arrays.h"
#include "eingaben.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt einen Defaultobjekt mit einer zufaelligen Lottoziehung. */
Lottogenerator::Lottogenerator()
{
  anzahl_lottoziehungen = 1;
  min = 1;
  max = 49;
  anzahl_lottozahlen = 6;
  initialisiere_lottoziehungen();
}
/**Erzeugt Lottogenerator mit n Lottoziehungen, wobei n (1 <= n <= 70000000) die Anzahl der Lottoziehungen ist.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 *
 * @param die_anzahl_lottoziehungen Die Anzahl der Lottoziehungen, die erzeugt werden soll.
 */
Lottogenerator::Lottogenerator(int die_anzahl_lottoziehungen)
{
  if (die_anzahl_lottoziehungen > 0 && die_anzahl_lottoziehungen <= 70000000)
    anzahl_lottoziehungen = die_anzahl_lottoziehungen;
  min = 1;
  max = 49;
  anzahl_lottozahlen = 6;
  initialisiere_lottoziehungen();
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Lottogenerator::~Lottogenerator()
{
  lottoziehungen.clear();
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Lottogenerator::Lottogenerator(const Lottogenerator& original)
{
  anzahl_lottoziehungen = original.anzahl_lottoziehungen;
  min = original.min;
  max = original.max;
  anzahl_lottozahlen = original.anzahl_lottozahlen;
  initialisiere_lottoziehungen(original.lottoziehungen);
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_lottogenerator  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Lottogenerator& Lottogenerator::operator=(const Lottogenerator& ein_lottogenerator)
{
  if (this != &ein_lottogenerator) // nur, wenn verschieden
  {
    lottoziehungen.clear(); // lösche alte Werte
    anzahl_lottoziehungen = ein_lottogenerator.anzahl_lottoziehungen; // speichere neue Werte
    min = ein_lottogenerator.min;
    max = ein_lottogenerator.max;
    anzahl_lottozahlen = ein_lottogenerator.anzahl_lottozahlen;
    initialisiere_lottoziehungen(ein_lottogenerator.lottoziehungen);
  }
  return *this;
}
// Code der Methoden
/**Liefert die Anzahl der Lottoziehungen.
 *
 * @return Die Anzahl der Lottoziehungen.
 */
int Lottogenerator::liefere_anzahl_lottoziehungen() const
{
  return lottoziehungen.size();
}
/** Schreibt alle erzeugten Lottoziehungen auf den Bildschirm. */
void Lottogenerator::schreibe_lottoziehungen() const
{
  for (int i = 0; i < anzahl_lottoziehungen; i++)
  {
    lottoziehungen[i].schreibe_lottozahlen();
  }
}
/**Berechnet wie viel Jahre und Monate Lottospielens<br>
 * die erzeugten Lottoziehungen entsprechen. Dabei wird der Einfachheit davon ausgegangen,<br>
 * dass jedes Jahr 52 Wochen hat und pro Woche eine Ziehung erfolgt.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::wieviele_jahre_und_monate() const
{
	int jahre = anzahl_lottoziehungen / 52;
	int monate = (anzahl_lottoziehungen % 52) / 4;
	if (monate == 12)
	{
		jahre = jahre + 1;
		monate = 0;
	}
	cout << "\nDie erzeugten Lottoziehungen entsprechen in etwa " <<  jahre
    << " Jahre und " << monate << " Monate Lottospielens.\n";
}
/**Erstellt eine tabellarische Aufstellung, der entnommen werden kann,<br>
 * wie oft jede der Zahlen 1 bis max gezogen wurde (Häufigkeitsverteilung). Außerdem werden<br>
 * die beiden Zahlen ausgegeben werden, die am häufigsten bzw. am wenigsten gezogen wurden,<br>
 * sowie die Differenz ihrer Häufigkeiten.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_haeufigkeitsverteilung() const
{
  int *haeufigkeitsverteilung = new int[max];
  Arrays::initialisiere_int_array(haeufigkeitsverteilung, max, 0);
  for (int i = 0; i < anzahl_lottoziehungen; i++)
    lottoziehungen[i].haeufigkeitsverteilung(haeufigkeitsverteilung);
	const int *min_zahl = Statistik::liefere_min(haeufigkeitsverteilung, max);
	int min_haeufigkeit = 0;
	const int *max_zahl = Statistik::liefere_max(haeufigkeitsverteilung, max);
	int max_haeufigkeit = 0;
	int diffirenz_haeufigkeit = abs((*min_zahl) - (*max_zahl));
	cout << endl << left << setw(15) << "Zahl" << right << setw(10) << "Haeufigkeitsverteilung" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << endl << left << setw(15) << i + 1 << right << setw(10) << haeufigkeitsverteilung[i];
		if (haeufigkeitsverteilung[i] == *min_zahl)
			min_haeufigkeit = i + 1;
		if (haeufigkeitsverteilung[i] == *max_zahl)
			max_haeufigkeit = i + 1;
	}
	cout << endl << endl;
	cout << "Die Zahl " << min_haeufigkeit << " kommt am wenigsten und die Zahl "
    << max_haeufigkeit << " am häufigsten vor.\n";
  cout <<  "Die Differenz der beiden Haeufigkeiten beträgt " << diffirenz_haeufigkeit << ".\n";
  delete [] haeufigkeitsverteilung;
  haeufigkeitsverteilung = 0;
}
/**Das Minimum einer Lottoziehung ist die kleinste der gezogenen Zahlen.<br>
 * Erstellt eine tabellarische Aufstellung, in der für jede der Zahlen 1 bis 49 angegeben wird,<br>
 * wie oft sie als Minimum einer der erzeugten Lottoziehungen vorkommt.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_minima() const
{
  int *minima = new int[max];
  Arrays::initialisiere_int_array(minima, max, 0);
  for (int i = 0; i < anzahl_lottoziehungen; i++)
    lottoziehungen[i].haeufigkeitsverteilung_minima(minima);
  cout << endl << left << setw(15) << "Zahl" << right << setw(10) << "Haeufigkeitsverteilung Minima" << endl;
	for (int i = 0; i < max; i++)
    cout << endl << left << setw(15) << i + 1 << right << setw(10) << minima[i];
	cout << endl << endl;
  delete [] minima;
  minima = 0;
}
/**Das Maximum einer Lottoziehung ist die grosste der gezogenen Zahlen.<br>
 * Erstellt eine tabellarische Aufstellung, in der für jede der Zahlen 1 bis 49 angegeben wird,<br>
 * wie oft sie als Maximum einer der erzeugten Lottoziehungen vorkommt.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_maxima() const
{
  int *maxima = new int[max];
  Arrays::initialisiere_int_array(maxima, max, 0);
  for (int i = 0; i < anzahl_lottoziehungen; i++)
    lottoziehungen[i].haeufigkeitsverteilung_maxima(maxima);
  cout << endl << left << setw(15) << "Zahl" << right << setw(10) << "Haeufigkeitsverteilung Maxima" << endl;
	for (int i = 0; i < max; i++)
    cout << endl << left << setw(15) << i + 1 << right << setw(10) << maxima[i];
	cout << endl << endl;
  delete [] maxima;
  maxima = 0;
}
/**Unter der Länge einer Lottoziehung wir die Differenz zwischen der größten und der<br>
 * kleinsten gezogenen Zahl verstanden. Erzeugt eine tabellarische Aufstellung,<br>
 * in der für jede der möglichen Längen (5 bis 48) angegeben wird, wie häufig sie<br>
 * unter den erzeugten Lottoziehungen vorkommt (sowohl absolut als auch prozentual).<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_laengen() const
{
  int *laengen = new int[max - anzahl_lottozahlen + 1];
  Arrays::initialisiere_int_array(laengen, max - anzahl_lottozahlen + 1, 0);
	int min_laenge =  anzahl_lottozahlen - 1;
	int max_laenge = max - 1;
	int laenge = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		laenge = lottoziehungen[i].laenge_lottoziehung();
		laengen[laenge - min_laenge] = laengen[laenge - min_laenge] + 1;
	}
  cout << endl << left << setw(10) << "Laenge"
    << right << setw(10) << "Haeufigkeitsverteilung Laengen" << endl;
	for (int i = min_laenge; i < max_laenge + 1; i++)
    cout << endl << left << setw(7) << i << " : "
      << right << setw(10) << laengen[i - min_laenge] << "\t"
      << right << setw(10) << setprecision(2) << showpoint << fixed << (laengen[i - min_laenge] / (anzahl_lottoziehungen / 100.00)) << "%";
	cout << endl << endl;
  delete [] laengen;
  laengen = 0;
}
/**Die Länge einer Ziehung (5 bis 48) kann in der Ziehung selbst als gezogene Zahl auftreten oder<br>
 * nicht. Gibt aus, bei wie vielen Ziehungen die Länge der Ziehung<br>
 * in der Ziehung vorkommt (sowohl absolut als auch prozentual).<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_laenge_ist_gezogene_zahl() const
{
  int *lottozahl_gleich_laengen = new int[max - anzahl_lottozahlen + 1];
  Arrays::initialisiere_int_array(lottozahl_gleich_laengen, max - anzahl_lottozahlen + 1, 0);
	int min_laenge = anzahl_lottozahlen - 1;
	int max_laenge = max - 1;
	int laenge = 0;
  for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		laenge = lottoziehungen[i].laenge_lottoziehung();
		lottozahl_gleich_laengen[laenge - min_laenge] = lottozahl_gleich_laengen[laenge - min_laenge] + 
      lottoziehungen[i].zahl_in_lottoziehung(laenge);
	}
  cout << endl << left << setw(10) << "Laenge"
    << right << setw(10) << "Haeufigkeitsverteilung Länge der Ziehung die in der Ziehung selbst vorkommt" << endl;
	for (int i = min_laenge; i < max_laenge + 1; i++)
    cout << endl << left << setw(7) << i << " : "
      << right << setw(10) << lottozahl_gleich_laengen[i - min_laenge] << "\t"
      << right << setw(10) << setprecision(2) << showpoint << fixed << (lottozahl_gleich_laengen[i - min_laenge] / (anzahl_lottoziehungen / 100.00)) << "%";
	cout << endl << endl;
  delete [] lottozahl_gleich_laengen;
  lottozahl_gleich_laengen = 0;
}
/**Eine Ziehung ist gerade, wenn alle gezogenen Zahlen gerade sind. Wie viele der erzeugten<br>
 * Ziehungen sind gerade (absolut und prozentual) wird hier ausgegeben.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_lottoziehungen_sind_gerade() const
{
	int anzahl = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		if (lottoziehungen[i].sind_alle_zahlen_gerade())
			anzahl = anzahl + 1;
	}
  cout << endl << anzahl << " ("
    << setprecision(2) << showpoint << fixed << (anzahl / (anzahl_lottoziehungen / 100.00)) << "%) "
    << "der erzeugten Ziehungen sind gerade.\n";
}
/**Eine Ziehung ist ungerade, wenn alle gezogenen Zahlen ungerade sind. Wie viele der erzeugten<br>
 * Ziehungen sind ungerade (absolut und prozentual) wird hier ausgegeben.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_lottoziehungen_sind_ungerade() const
{
	int anzahl = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
		if (lottoziehungen[i].sind_alle_zahlen_ungerade())
			anzahl = anzahl + 1;
	}
  cout << endl << anzahl << " ("
    << setprecision(2) << showpoint << fixed << (anzahl / (anzahl_lottoziehungen / 100.00)) << "%) "
    << "der erzeugten Ziehungen sind ungerade.\n";
}
/**Zwei direkt aufeinander folgende ganze Zahlen sind ein Zwilling (zum Beispiel [7, 8]<br>
 * oder [13, 14]), drei direkt aufeinander folgende ganze Zahlen sind Drilling (zum Beispiel [3, 4,5] oder [29, 30, 31]).<br>
 * Allgemein heißt für k >= 1 eine Folge k direkt aufeinander folgender ganzer Zahlen ein k-ling.<br>
 * Eine Lottoziehung heißt eine k-Ziehung, wenn sie einen k-ling enthält, aber keinen (k+1)-ling.<br>
 * Hier wird für jeden der möglichen Werte von k (1 bis 6) mitgeteilt,<br>
 * wie viele der Ziehungen eine k-Ziehung sind (absolut und prozentual).<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::statistik_lottoziehungen_zahlenpaare()
{
  int *zahlenpaare = new int[anzahl_lottozahlen];
  Arrays::initialisiere_int_array(zahlenpaare, anzahl_lottozahlen, 0);
	int paar = 0;
	unsigned int anzahl_paare = 0;
	for (int i = 0; i < anzahl_lottoziehungen; i++)
	{
			paar = lottoziehungen[i].zahlenpaar();
			zahlenpaare[paar] = zahlenpaare[paar] + 1;
			if (paar > 0)
				anzahl_paare = anzahl_paare + 1;
			paar = 0;
	}
	cout << endl << setprecision(2) << showpoint << fixed << (anzahl_paare / (anzahl_lottoziehungen / 100.00))
    << "% der Tippreihen enthalten ein oder mehrere Zahlenpaare.\n\n";
  cout << left << setw(15) << "Zwillinge " << right << setw(10) << zahlenpaare[1] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (zahlenpaare[1] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Drillinge " << right << setw(10) << zahlenpaare[2] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (zahlenpaare[2] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Vierlinge " << right << setw(10) << zahlenpaare[3] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (zahlenpaare[3] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Fuenflinge " << right << setw(10) << zahlenpaare[4] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (zahlenpaare[4] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Sechslinge " << right << setw(10) << zahlenpaare[5] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (zahlenpaare[5] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  delete [] zahlenpaare;
  zahlenpaare = 0;
}
/**Liest durch die Benutzerinnen und Benutzer des Programms eingegebenen Lottotipp ein,<br>
 * wobei sicher gestellt wird, dass keine Zahlen doppelt vorkommt.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::lottotipp_eingabe() const
{
  int *lottotipp_eingabe = new int[anzahl_lottozahlen];
  Arrays::initialisiere_int_array(lottotipp_eingabe, anzahl_lottozahlen, 0);
	bool zahl_ungueltig = false;
	cout << "\nBitte geben Sie die Lottozahlen einzeln ein!\n\n";
  string beschriftung[6] = {"erste", "zweite", "dritte", "vierte", "fünfte", "sechste"};
  for (int lottozahl = 0; lottozahl < anzahl_lottozahlen; lottozahl++)
  {
  	cout << "Bitte geben Sie ihre " << beschriftung[lottozahl] << " Lottozahl ein: ";
  	lottotipp_eingabe[lottozahl] = Eingaben::erfasse_int("", min, max);
  	if (lottozahl != 0 && zahl_ungueltig == false)
  	{
  		zahl_ungueltig = Statistik::ist_zahl_im_array(lottotipp_eingabe, lottozahl, lottotipp_eingabe[lottozahl]);
  		if (zahl_ungueltig == true)
  		{
  			lottozahl = lottozahl - 1;
  	  	zahl_ungueltig = false;
  	  	cout << "Die Zahl ist schon vorhanden. Bitte eine neue Zahl eingeben.\n";
			}
		}
  }
  Lottoziehung lottotipp(lottotipp_eingabe);
  schreibe_statistik_lottotipp_eingabe(lottotipp);
  delete [] lottotipp_eingabe;
  lottotipp_eingabe = 0;
}
/**Die erzeugt per Zufallszahlengenerator so lange Lottotipps und<br>
 * vergleicht diesen mit den gespeicherten Lottoziehungen, bis es zu einem "Sechser" kommt,<br>
 * d.h. zu einem Tipp, der mit einer der gespeicherten Lottoziehungen in allen sechs Zahlen übereinstimmt.<br>
 * Es wird ausgegeben, der wievielte Lottotipp der Sechser war.<br>
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::lottotipp_durch_ai() const
{
	unsigned long tipp = 0;
	int uebereinstimmungen = 0;
	if (uebereinstimmungen != 6)
	{
    Lottoziehung lottotipp_ai(min, max);
		cout << "\nIch habe folgenden Lottotipp zufaellig erzeugt: \n";
    lottotipp_ai.schreibe_lottozahlen();
		for (int lottoziehung = 0; lottoziehung < anzahl_lottoziehungen; lottoziehung++)
		{
			tipp = tipp + 1;
			uebereinstimmungen = lottoziehungen[lottoziehung].vergleiche_lottoziehung(lottotipp_ai);
			if (uebereinstimmungen == 6)
			{
				cout << "\nDer " << tipp << ". Versuch war der Sechser!\n";
				lottoziehung = anzahl_lottoziehungen;
			}
      else if (lottoziehung == anzahl_lottoziehungen - 1 && uebereinstimmungen != 6)
      {
        lottotipp_ai = Lottoziehung(min, max);
        cout << "\nIch hatte leider keinen Sechser mit diesem Tipp :(. "
          "Ich habe daher folgenden neuen Lottotipp zufaellig erzeugt: \n";
        lottotipp_ai.schreibe_lottozahlen();
        lottoziehung = 0;
      }
		}
	}
}
/**Erzeugt neue Lottoziehungen und fuegt diese zu den alten an.
 *
 * @param anzahl  Die Anzahl der neuen Ziehungen die erzeugt werden sollen.
 */
void Lottogenerator::erzeueg_neu_lottoziehungen(int anzahl)
{
  if (anzahl_lottoziehungen == 70000000)
    cout << "Die maximal moegliche Anzahl der Lottoziehungen die ich erzeugen kann ist 70000000." << endl;
  else if (anzahl + anzahl_lottoziehungen <= 70000000)
  {
    cout << "Erzeuge " << anzahl << " neu Lottoziehungen...\n";
    lottoziehungen.resize(anzahl + anzahl_lottoziehungen, Lottoziehung(min, max));
    anzahl_lottoziehungen = anzahl + anzahl_lottoziehungen;
    cout << "... Lottoziehungen erzeugt. Nun habe ich " << lottoziehungen.size() << " Lottoziehungen\n";
  }
else
    cout << "Sorry. Die Anzahl der zu erzeugenden  Lottoziehungen (" << anzahl << ")  ist fuer mich zu groß...\n";
  
}

/**Vergleicht einen Lottotipp durch Benutzer mit allen gespeicherten Ziehungen. Anschließend wird ausgegeben,<br>
 * wie viel Ziehungen in 1, 2, 3, 4, 5 oder 6 Zahlen mit dem Tipp übereinstimmen (absolut und prozentual).<br>
 *
 * @param   lottotipp_eingabe   Eine Lottoziehung, der mit allen gespeicherten Ziehungen verglichen werden soll.
 * 
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Lottogenerator::schreibe_statistik_lottotipp_eingabe(const Lottoziehung lottotipp_eingabe) const
{
	int *uebereinstimmungen = new int[anzahl_lottozahlen];
  Arrays::initialisiere_int_array(uebereinstimmungen, anzahl_lottozahlen, 0);
  for (int lottoziehung = 0; lottoziehung < anzahl_lottoziehungen; lottoziehung++)
  {
  	int treffer = lottoziehungen[lottoziehung].vergleiche_lottoziehung(lottotipp_eingabe);
  	if (treffer != 0)
  		uebereinstimmungen[treffer - 1] = uebereinstimmungen[treffer - 1] + 1;
  }
	cout << "\nIch habe folgenden Lottotipp entgegengenommen: \n";
  lottotipp_eingabe.schreibe_lottozahlen();
  cout << "\nDer Lottotipp hatte in folgenden Anzahl der Zahlen uebereinstimmigkeiten gehabt:\n\n";
  cout << left << setw(15) << "Eine Zahl: " << right << setw(10) << uebereinstimmungen[0] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[0] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Zwei Zahlen: " << right << setw(10) << uebereinstimmungen[1] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[1] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Drei Zahlen: " << right << setw(10) << uebereinstimmungen[2] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[2] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Vier Zahlen: " << right << setw(10) << uebereinstimmungen[3] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[3] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Fuenf Zahlen: " << right << setw(10) << uebereinstimmungen[4] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[4] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  cout << left << setw(15) << "Sech Zahlen: " << right << setw(10) << uebereinstimmungen[5] << "\t"
    << right << setw(10) << setprecision(4) << showpoint << fixed << (uebereinstimmungen[5] / (anzahl_lottoziehungen / 100.00))<< "%\n";
  delete [] uebereinstimmungen;
  uebereinstimmungen = 0;
}
/**Initialisiert die Lottoziehungen mit zufaelligen Lottoziehungen.<br>
 * Jede Lottoziehung besteht aus sechs ganzen Zahlen aus dem Bereich von 1 bis 49,<br>
 * wobei keine Zahl doppelt vorkommt.<br>
 *
 */
void Lottogenerator::initialisiere_lottoziehungen()
{
  lottoziehungen.clear();
  lottoziehungen.resize(anzahl_lottoziehungen);
  for (int i = 0; i < anzahl_lottoziehungen; i++)
  {
    lottoziehungen[i] = Lottoziehung(min, max);
  }
}
/**Initialisiert die Lottoziehungen mit dem im Vektor uebergebenen Lottoziehungen.
 *
 * @param die_lottoziehungen  Vektor von Lottoziehungen, mit denen das Objekt initialisiert werden soll.
 */
void Lottogenerator::initialisiere_lottoziehungen(const vector<Lottoziehung> die_lottoziehungen)
{
  lottoziehungen.clear();
  lottoziehungen.resize(anzahl_lottoziehungen);
  for (int i = 0; i < anzahl_lottoziehungen; i++)
    lottoziehungen[i] = die_lottoziehungen[i];
}
// eventuell Code
// weiterer Funktionen
