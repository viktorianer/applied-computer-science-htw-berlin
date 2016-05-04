#include <stdio.h>

#include "interaktionen.h"
#include "zinsgeschaeft.h"

/**Das Programm erstellt einen Tilgungsplan für ein Annuitätendarlehen.
 * Dazu gibt der Benutzer die Höhe des Kredites in Euro, dem Zinssatz und die Tulgung in Prozenten an.
 * Das Programm berechnet danach die Laufzeit, die jährliche Annuität und Abzahlung bis zu einer Abschlusszahlung.
 * Zusäzlich wird der Gesamtaufwand für diesen Kredit berechnet und ausgeben.
 *
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  printf("\nDas Programm erstellt einen Tilgungsplan für ein Annuitätendarlehen.\n");
  char antwort = 'n';
  do
  {
    char *ausgabetext = "\nBitte geben Sie die Höhe des Kredits ein: \t";
    double kredit = erfasse_gleitkomma_zahl(ausgabetext, 1.0, 100000000);
    ausgabetext = "Bitte geben Sie die Höhe des Zinssatzes in Prozent ein: \t";
    double zinssatz_in_prozent = erfasse_gleitkomma_zahl(ausgabetext, 0.1, 20.0);
    ausgabetext = "Bitte geben Sie die anfängliche Tilgungsrate in Prozent ein: \t";
    double tilgungsrate_in_prozent = erfasse_gleitkomma_zahl(ausgabetext, 0.1, 10.0);

    schreibe_tilgungsplan_fuer_ein_annuitaetendarlehen(kredit, zinssatz_in_prozent, tilgungsrate_in_prozent);

    ausgabetext = "\nMöchten Sie einen weiteren Tilgungsplan erstellen? (j/n)\t";
    antwort = antwort_ja_oder_nein(ausgabetext, 'j', 'n');
  } while (antwort != 'n');
}
