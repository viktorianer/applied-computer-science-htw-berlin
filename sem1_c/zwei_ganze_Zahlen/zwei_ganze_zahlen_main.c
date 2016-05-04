#include <stdio.h>

#include "interaktionen.h"
#include "zahlensystem.h"

/**Das Prorgramm ezeugt zwei zufällige, ganze Zahlen x und y zwischen 1 und 20.
 * Der Benutzer bekommt danach einige Informationen zu diesen Zahlen. Die ausgegebenen Informationen sind:
 * es ist x + y = ...,
 * es ist x * y = ...,
 * es ist x > y oder x < y,
 * es ist x != y oder x = y.
 *
 * Der Benutzer muss nun diese Zahlen erraten und diese einzeln eingeben. Das Programm prüft die Eingabe auf richtigkeit
 * und gibt aus, ob der Benutzer die beiden Zahlen richtig erraten hat oder nicht.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  printf("\nDas Prorgramm ezeugt zwei zufällige, ganze Zahlen x und y zwischen 1 und 20.\n"
      "Der Benutzer bekommt danach einige Informationen zu diesen Zahlen und muss diese Zahlen erraten.\n");

  initialisiere_zufallszahlengenerator();
  int erste_zufallszahl = liefere_ganze_zufallszahl(1,20);
  int zweite_zufallszahl;
  do {
    zweite_zufallszahl = liefere_ganze_zufallszahl(1,20);
  } while (zweite_zufallszahl == erste_zufallszahl);

  printf("\nIch habe zwei ganze Zahlen x und y zwischen 1 und 20 erzeugt!\n");

  printf("\nEs ist x + y = %d.\n", erste_zufallszahl + zweite_zufallszahl);
  printf("Es ist x * y = %d.\n", erste_zufallszahl * zweite_zufallszahl);

  if (erste_zufallszahl > zweite_zufallszahl)
  {
    printf("Es ist x > y.\n");
  }
  else
  {
    printf("Es ist x < y.\n");
  }

  printf("Es ist x != y.\n");


  char *ausgabetext = "\nWelchen Wert hat x?\t";
  int eingabe_zahl_x = erfasse_ganze_zahl(ausgabetext, 1, 20);
  ausgabetext = "Welchen Wert hat y?\t";
  int eingabe_zahl_y = erfasse_ganze_zahl(ausgabetext, 1, 20);

  if (eingabe_zahl_x == erste_zufallszahl || eingabe_zahl_x == zweite_zufallszahl)
  {
    if (eingabe_zahl_y == erste_zufallszahl || eingabe_zahl_y == zweite_zufallszahl)
    {
      printf(" \nSehr gut! Sie haben die Zahlen erraten!\n");
    }
  }
  else
  {
    printf(" \nIhre Antwort ist leider falsch! Hier ist die richtige Antwort: (%d,%d)\n",
        erste_zufallszahl, zweite_zufallszahl);
  }
}
