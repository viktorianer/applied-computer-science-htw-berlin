#include "zufallsgenerator.h"

// weitere Angaben
// Code der Konstruktoren
/**Erzeugt einen Zufallsgenerator.
 * Der Generator initialisiert einmalig den Zufallsgenerator mit der Systemzeit.
 * Weitere initialisierungen werden unterbunden.
 * Damit der Zufallsgenerator nicht immer die gleichen Zahlen ermittelt,
 * muss zunächst der Zufallsgenerator mit der Systemzeit initialisiert werden.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
Zufallsgenerator::Zufallsgenerator()
{
  srand((unsigned) time(NULL));
}
// Code der Methoden
/**Erzeugt einen Zufallsgenerator.
 * Der Generator initialisiert einmalig den Zufallsgenerator mit der Systemzeit. 
 * Weitere initialisierungen werden unterbunden.
 * Damit der Zufallsgenerator nicht immer die gleichen Zahlen ermittelt, 
 * muss zunächst der Zufallsgenerator mit der Systemzeit initialisiert werden.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
Zufallsgenerator& Zufallsgenerator::liefere_zufallsgenerator()
{
  static Zufallsgenerator instance;
  return instance;
}
/**Liefert eine ganze Zufallszahl aus einen angegebenen Bereich. Zufor muss der Zufallsgenerator initialisiert werden.
 *
 * Bitte beachten Sie, dass rand() in der Regel keine sehr gute Streuung liefert.
 * Für statistische Zwecke sollten Sie deshalb nicht auf die Standardbibliothek zurückgreifen.
 * (Die Funktion rand() liefert einen Wert zwischen 0 und RAND_MAX.)
 *
 * @param min             minimale Größe der ganzen Zufallszahl.
 * @param max             maximale Größe der ganzen Zufallszahl.
 *
 * @return  Die ganze Zufallszahl wird zurückgegeben.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int Zufallsgenerator::liefere_ganze_zufallszahl(int min, int max) const
{
  if (min > max)
  {
    int ablage = min;
    min = max;
    max = ablage;
  }
  bool input_ok = (0 < max) && (max <= RAND_MAX);
  int zufallszahl = input_ok ? rand() % (max - min + 1) : -1;
  return zufallszahl + min;

}
/**Liefert eine Gleitkommazufallszahl aus einen angegebenen Bereich. Zufor muss der Zufallsgenerator initialisiert werden.
 *
 * Bitte beachten Sie, dass rand() in der Regel keine sehr gute Streuung liefert.
 * Für statistische Zwecke sollten Sie deshalb nicht auf die Standardbibliothek zurückgreifen.
 * (Die Funktion rand() liefert einen Wert zwischen 0 und RAND_MAX.)
 *
 * @param min             minimale Größe der ganzen Zufallszahl.
 * @param max             maximale Größe der ganzen Zufallszahl.
 *
 * @return  Die Gleitkommazufallszahl wird zurückgegeben.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double Zufallsgenerator::liefere_gleitkomma_zufallszahl(double min, double max) const
{
  if (min > max)
  {
    double ablage = min;
    min = max;
    max = ablage;
  }
  bool input_ok = (0 < max) && (max <= RAND_MAX);
  double zufallszahl = input_ok ? (rand() / ((double)(RAND_MAX) + 1)) * (max - min) + min : -1;
	return zufallszahl;
}
// eventuell Code
// weiterer Funktionen