#include <stdio.h>

#include "interaktionen.h"
#include "kalender.h"

/**Das Programm gibt nach Eingabe des Monats und eines Jahres den Kalender des Monats aus.
 *
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  char antwort = 'n';
  printf("\nDas Programm gibt nach Eingabe des Monats und eines Jahres den Kalender des Monats aus.\n");
  do
  {
    char *ausgabetext = "\nBitte geben Sie den Monat ein: \t";
    int monat = erfasse_ganze_zahl(ausgabetext, 1, 12);

    ausgabetext = "Bitte geben Sie das Jahr ein: \t";
    int jahr = erfasse_ganze_zahl(ausgabetext, 1583, 10000);

    int startspalte = ermittle_die_startspalte(monat, jahr);
    int anzahl_tage = ermittle_wieviel_tage_im_monat(monat, jahr);
    schreibe_den_kalender(startspalte, anzahl_tage, monat, jahr);

    ausgabetext = "\nMöchten Sie einen weiteren Kalender anschauen? (j/n)\t";
    antwort = antwort_ja_oder_nein(ausgabetext, 'j', 'n');
  } while (antwort != 'n');
}
