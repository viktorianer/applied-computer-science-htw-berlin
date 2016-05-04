#include <stdio.h>

#include "vier_gewinnt.h"
#include "interaktionen.h"

/**Simuliert das Spiel "Vier Gewinnt" mit zwei Spieler/Spielerin.
 * <br>Das Spiel \"Vier gewinnt\" wird von zwei Spielern/Spielerinnen nach folgenden Regeln gespielt:"
 * <br>Auf einem rechteckigen Spielbrett befinden sich n x m Felder, wobei n >= 7 und m >= 6 ist:
 *<br>
 *<br> |. . . . . . .| 1
 *<br> |. . . . . . .| 2
 *<br> |. . . . . . .| 3
 *<br> |X O . . . . .| .
 *<br> |X X O . . . X| .
 *<br> |X O X O . . O| m
 *<br> 1 2 3 . . . n
 *<br>
 *<br> Die Spieler/innen belegen die Felder abwechselnd mit Spielmarken ihrer “Farbe“. Dabei werden folgende Regelen beachtet:
 *<br>
 *<br> Eine Spielmarke darf nur dann auf ein Feld gesetzt werden, wenn es leer ist und alle Felder
 *<br> der entsprechenden Spalte, die sich unterhalb des Feldes befinden, bereits belegt sind.
 *<br>
 *<br> Gewonnen hat, wer zuerst vier Spielmarken der eigenen “Farbe“ horizontal, vertikal oder diagonal
 *<br> nebeneinander platziert hat.
 *<br>
 *<br> @author	Viktor Schmidt, s0529652
 *<br> @version	1.0
 */
int main(void)
{
  printf("\n\nDas Spiel \"Vier gewinnt\" wird von zwei Spielern/Spielerinnen nach folgenden Regeln gespielt:\n\n"
  		"Auf einem rechteckigen Spielbrett befinden sich n x m Felder, wobei n >= 7 und m >= 6 ist:\n\n"
  		"|. . . . . . .| 1\n"
  		"|. . . . . . .| 2\n"
  		"|. . . . . . .| 3\n"
  		"|X O . . . . .| .\n"
  		"|X X O . . . X| .\n"
  		"|X O X O . . O| m\n"
  		" 1 2 3 . . . n\n\n"
  		"Die Spieler/innen belegen die Felder abwechselnd mit Spielmarken ihrer “Farbe“. Dabei ist folgende Regel zu beachten:\n"
  		"\n"
  		"Eine Spielmarke darf nur dann auf ein Feld gesetzt werden, wenn es leer ist und alle Felder\n"
  		"der entsprechenden Spalte, die sich unterhalb des Feldes befinden, bereits belegt sind.\n"
  		"Gewonnen hat, wer zuerst vier Spielmarken der eigenen “Farbe“ horizontal, vertikal oder diagonal\n"
  		"nebeneinander platziert hat.\n\n");

  char *ausgabetext = "Bitte die Breite des Spielfeldes angeben: ";
  int zeilen = 9; //erfasse_ganze_zahl(ausgabetext, 7, 20); // Zeilen soll > 7 sein
  ausgabetext = "Bitte die Hohe des Spielfeldes angeben: ";
  int spalten = 9; // erfasse_ganze_zahl(ausgabetext, 6, 20); // Spalten soll > 6 sein
  int namen_laenge = 21;
  char spieler1[namen_laenge];
  char spieler2[namen_laenge];

  ausgabetext = "Spieler 1, bitte geben Sie ihren Namen ein: ";
  erfasse_zeichenkette(ausgabetext, spieler1, namen_laenge);
  ausgabetext = "Spieler 2, bitte geben Sie ihren Namen ein: ";
  erfasse_zeichenkette(ausgabetext, spieler2, namen_laenge);

  simuliere_vier_gewinnt(zeilen, spalten, spieler1, spieler2);
}
