#include <stdio.h>

#include "vier_gewinnt.h"
#include "interaktionen.h"
#include "arrays.h"

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
 *<br> @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 *<br> @param spalten       Die Anzahl der Spalten des Spielfeldes.
 *<br> @param spieler1   	\c Input:  \n Das Array, in dem der Name des ersten Spielers steht.\n
 *<br>                		\c Output: \n Dasselbe Array, in dem der Name des ersten Spielers steht.\n
 *<br> @param spieler2   	\c Input:  \n Das Array, in dem der Name des zweiten Spielers steht.\n
 *<br>                		\c Output: \n Dasselbe Array, in dem der Name des zweiten Spielers steht.\n
 *<br>
 *<br> @author	Viktor Schmidt, s0529652
 *<br> @version	1.0
 */
void simuliere_vier_gewinnt (int zeilen, int spalten, const char spieler1[], const char spieler2[])
{
  int spielfeld[zeilen][spalten];
  initialisiere_2dim_int_array(zeilen, spalten, spielfeld, 0);
  int max_anzahl_zuege = (zeilen * spalten) / 2;
  _Bool beenden = 0;
  int spielstein = -1; //-1 ist der Spielstein für Spieler 1

  schreibe_spielfeld(zeilen, spalten, spielfeld);
  for (int j = 0; j < max_anzahl_zuege && beenden == 0; j++)
	{
  	if (beenden == 0)
  	{
  		schreibe_zeichenkette(spieler1);
  		printf(" ist am Zug...");
    	beenden = nechster_zug(zeilen, spalten, spielfeld, spielstein);
  		spielstein = 1;
  		if (beenden != 0)
  		{
  			schreibe_zeichenkette(spieler1);
  			printf(" hat gewonnen! Glueckwunsch!\n\n");
  		}
  	}
		if (beenden == 0)
		{
			schreibe_zeichenkette(spieler2);
  		printf(" ist am Zug...");
	  	beenden = nechster_zug(zeilen, spalten, spielfeld, spielstein);
			spielstein = -1;
			if (beenden != 0)
  		{
  			schreibe_zeichenkette(spieler2);
  			printf(" hat gewonnen! Glueckwunsch!\n\n");
  		}
		}
	}
  if (beenden == 0)
	{
  	printf("Spiel ist vorbei, Unentschieden!\n\n");
	}
}

/**Erfasst nechsten Zug ueber die Konsole und stellt das veraenderte Spielfeld neu dar.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente an der Stelle des Einwurfes veraendert wurden.\n
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool nechster_zug(int zeilen, int spalten, int spielfeld[zeilen][spalten], int spielstein)
{
	int i;
  _Bool beenden = 0;
	int n = erfasse_nechsten_zug(zeilen, spalten, spielfeld);
	for (i = 0; spielfeld[i][n] != 0; i++)
		;
	spielfeld[i][n] = spielstein;
	schreibe_spielfeld(zeilen, spalten, spielfeld);
	if (pruefe_siegesbedingung(zeilen, spalten, spielfeld, 4, spielstein))
	{
		beenden = 1;
	}
	return beenden;
}

/**Schreibt das Spielfeld auf die Konsole. Das Spielfeld-Array muss für Spieler 1 dem Wert -1, Spieler 2 dem Wert 1
 * und für nicht belegt dem Wert 0 enthalten.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen
 * 																	und ausgegeben werden.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente ausgegeben wurden.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void schreibe_spielfeld(int zeilen, int spalten, int spielfeld[zeilen][spalten])
{
  const char zeichensatz[] = {'O', '.', 'X',};
  int i;
  int j;

  for (int i = 0; i < zeilen; i++)
  {
  	printf(" %2d", i + 1);
	}
  printf("\n");
  for (i = zeilen - 1; i >= 0; i--)
  {
		printf("|");
		for (j = 0; j < spalten - 1; j++)
		{
			printf("%2c ", zeichensatz[spielfeld[i][j] + 1]);
		}
		printf("%2c |\n", zeichensatz[spielfeld[i][spalten - 1] + 1]);
  }
  printf("+");
  for (int i = 0; i < spalten; i++)
  {
  	printf("%3s", "---");
	}
  printf("+\n");
  printf("\n");
}

/**Erfasst nechsten Zug ueber die Konsole.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten auf uebereinstimmungen geprueft werden.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente auf uebereinstimmungen geprueft wurden.\n
 *
 * @return Gibt die Spalte aus in die ein neuer Spielstein eingeworfen wurde.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int erfasse_nechsten_zug(int zeilen, int spalten, int spielfeld[zeilen][spalten])
{
  int n;
  char *ausgabetext;
  do
  {
    ausgabetext = "Bitte geben Sie die Spalte ein: ";
    n = erfasse_ganze_zahl(ausgabetext, 1, spalten);
    if (n < 1 || n > spalten || spielfeld[zeilen - 1][n - 1] != 0)
    	printf("Falsche Eingabe, die Zeile ist schon voll. Bitte versuchen Sie es noch ein mal.\n");
	} while (n < 1 || n > spalten || spielfeld[zeilen - 1][n - 1] != 0);
	printf("\n");
  return n - 1;
}

/**Pruft Siegesbedingung fuer einen bestimmten Spieler durch. Hat ein Spieler bestimmte Anzahl der Steine
 * in der Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  _Bool gewonnen = 0;
  gewonnen = pruefe_siegesbedingung_horizontal(zeilen, spalten, spielfeld, laenge_linie, spielstein);
	if (gewonnen == 0)
		gewonnen = pruefe_siegesbedingung_vertikal(zeilen, spalten, spielfeld, laenge_linie, spielstein);
	if (gewonnen == 0)
		gewonnen = pruefe_siegesbedingung_diagonal(zeilen, spalten, spielfeld, laenge_linie, spielstein);
  return gewonnen;
}

/**Pruft Siegesbedingung in der Horizontale fuer einen bestimmten Spieler durch. Hat ein Spieler bestimmte Anzahl der Steine
 * in eine horizontale Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung_horizontal(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  int i;
  int j;
  int k;
  int zaehlen;
  _Bool gewonnen = 0;

  for (i = 0; i < zeilen; i++)
  {
    for (j = 0; j < spalten - laenge_linie + 1; j++)
    {
    	zaehlen = 0;
    	for (k = 0; k < laenge_linie; k++)
    		if (spielfeld[i][j + k] == spielstein)
    			zaehlen = zaehlen + 1;
			if (zaehlen == laenge_linie)
				gewonnen = 1;
     }
  }
  return gewonnen;
}

/**Pruft Siegesbedingung in der Vertikale fuer einen bestimmten Spieler durch. Hat ein Spieler bestimmte Anzahl der Steine
 * in eine vertikale Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung_vertikal(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  int i;
  int j;
  int k;
  int zaehlen;
  _Bool gewonnen = 0;

  for ( j = 0; j < spalten; j++)
  {
  	for (i = 0; i < zeilen - laenge_linie + 1; i++)
		{
			zaehlen = 0;
			for (k = 0; k < laenge_linie; k++)
				if (spielfeld[i + k][j] == spielstein)
					zaehlen = zaehlen + 1;
			if (zaehlen == laenge_linie)
				gewonnen = 1;
		}
  }
  return gewonnen;
}

/**Pruft Siegesbedingung in der Diagonale fuer einen bestimmten Spieler durch. Hat ein Spieler bestimmte Anzahl der Steine
 * in eine diagonale Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung_diagonal(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  _Bool gewonnen = 0;

  gewonnen = pruefe_siegesbedingung_diagonal_luro(zeilen, spalten, spielfeld, laenge_linie, spielstein);
	if (gewonnen == 0)
		gewonnen = pruefe_siegesbedingung_diagonal_loru(zeilen, spalten, spielfeld, laenge_linie, spielstein);
  return gewonnen;
}

/**Pruft Siegesbedingung in der Diagonale von links Unten nach rechts Oben fuer einen bestimmten Spieler durch.
 * Hat ein Spieler bestimmte Anzahl der Steine in eine diagonale Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung_diagonal_luro(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  int i;
  int j;
  int k;
  int zaehlen;
  _Bool gewonnen = 0;

  for (i = 0; i < spalten - laenge_linie + 1; i++)
  {
    for (j = 0; j < zeilen - laenge_linie + 1; j++)
    {
			zaehlen = 0;
			for (k = 0; k < laenge_linie; k++)
				if (spielfeld[i + k][j + k] == spielstein)
					zaehlen = zaehlen + 1;
			if (zaehlen == laenge_linie)
				gewonnen = 1;
    }
  }
  return gewonnen;
}

/**Pruft Siegesbedingung in der Diagonale von links Oben nach rechts Unten fuer einen bestimmten Spieler durch.
 * Hat ein Spieler bestimmte Anzahl der Steine in eine diagonale Reihe gelegt, gewinnt er das Spiel.
 *
 * @param zeilen        Die Anzahl der Zeilen des Spielfeldes.
 * @param spalten       Die Anzahl der Spalten des Spielfeldes.
 * @param spielfeld   \c Input:  \n Das Array, dessen Komponenten das Spielfeld und Spielsteine darstellen.\n
 *               			\c Output: \n Dasselbe Array, dessen Kommponente das Spielfeld und Spielsteine darstellen.\n
 * @param laenge_linie  Gibt die Anzahl der in der Riehe befindliche Steine die fuer einen Sieg noetig sind.
 * @param spielstein    Spielstein-Index des Spielers der gerade am Zug ist.
 *
 * @return Gibt zurueck ob die Siegesbedingung erfuelt (1) ist oder nicht (0).
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
_Bool pruefe_siegesbedingung_diagonal_loru(int zeilen, int spalten, int spielfeld[zeilen][spalten], int laenge_linie, int spielstein)
{
  int i;
  int j;
  int k;
  int zaehlen;
  _Bool gewonnen = 0;

	if (gewonnen == 0)
		for (i = laenge_linie - 1; i < zeilen; i++)
		{
			for (j = 0; j < spalten - laenge_linie + 1; j++)
			{
				zaehlen = 0;
				for (k = 0; k < laenge_linie; k++)
					if (spielfeld[i - k][j + k] == spielstein)
						zaehlen = zaehlen + 1;
				if (zaehlen == laenge_linie)
					gewonnen = 1;
			}
		}
  return gewonnen;
}
