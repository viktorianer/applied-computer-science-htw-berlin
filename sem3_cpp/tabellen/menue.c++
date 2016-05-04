#include "menue.h"

/**Schreibt ein Menue und erfasst eine Anwort mit einer ganzen Zahl und vergleicht diese
 * mit dem Wertebereich zwischen 1 und menuelaenge.
 * Trifft die Eingabe auf keinen der beiden Werte (min, max) zu oder einen Wert dazwischen wird eine Fehlermeldung
 * ausgeben, die noch ein mal den gewünschten Wertebereich, also 1 bis menuelaenge, anzeigt.
 *
 * @param menuelaenge        Die Anzahl der Zeilen des Menues und gleichzeitig die max. Groesse des Menues.
 * @param menue   \c Input:  \n Das Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *
 * @return	Die erfasste Eingabe, ganze Zahl wird zurückgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int waehle_aus_menue(int menuelaenge, const string *menue)
{
  schreibe_menue(menuelaenge, menue);
  return erfasse_int("\n\nIhre Wahl:  ", 1, menuelaenge);
}

/**Schreibt ein Menue mit menuelaenge Zeilen und mit dem uebergebenen Text.
 *
 * @param menuelaenge        Die Anzahl der Zeilen des Menues und gleichzeitig die max. Groesse des Menues.
 * @param menue   \c Input:  \n Das Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten die Groesse des Menues und Menuetext enthalten.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_menue(int menuelaenge, const string *menue)
{
  for (int i = 0; i < menuelaenge; i++)
  {
    int menuepunkt = (i + 1);
    cout << "\n(" << menuepunkt << ")\t" << menue[i];
  }
}
