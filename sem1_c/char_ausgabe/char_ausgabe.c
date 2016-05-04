/**  Gibt ein Zahl aus, die Ergebnis der Addition von der Zahl 127 (Typ char) und 1 ist.
 *   Dabei ist die Zahl 127 selbst von Typ char (also max. 127 groß).
 *
 *   @return  zahl    Gibt die Zahl aus, die nach der Addetion von 127 und 1 rauskommt.
 *
 *   @author   Viktor Schmidt, s0529652
 *   @version  1.0
 */

//Deklarationen
#include <stdio.h>

//Funktionen
//Funktion main
int main(void)
{
  printf("\nProgramm zum Berechnen der Addition von char 127 und 1.\n");

  char zahl=0;

  zahl=127;
  printf("\nGebe Inhalt von 'zahl' aus...");
  printf("\nInhalt von 'zahl' als char: %c\n", zahl);
  printf("\nInhalt von 'zahl' als int: %i\n", zahl);

  printf("\nAddiere 1 dazu...\n");
  zahl=zahl+1;

  printf("\nDie neue Zahl als Typ char");
  printf("\nNeu Zahl: %c\n", zahl);
  printf("\nDie neue Zahl als Typ int");
  printf("\nNeu Zahl: %i\n", zahl);
}
