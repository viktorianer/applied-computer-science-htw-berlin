#include <stdio.h>

#include "kalender.h"

/**Stellt zu gegebenem Monat und Jahr fest, in welcher Spalte des Kalenders der erste Tag des Monats einzutragen ist.
 *
 * @param monat        der Monat
 * @param jahr         das Jahr
 *
 * @return  die Spalte des Kalenders, in die der erste Tag des Monats einzutragen ist.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int ermittle_die_startspalte (int monat, int jahr)
{
  int wievielter_tag = berechne_wievielter_tag_seit_beginn(1, monat, jahr);
  int startspalte = ((wievielter_tag % 7) + 6) % 7;

  return startspalte;
}

/**Ermittelt zu gegebenem Monat und Jahr, wie viele Tage der Monat hat.
 *
 * @param monat        der Monat
 * @param jahr         das Jahr
 *
 * @return  die Anzahl Tage, die der Monat hat.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int ermittle_wieviel_tage_im_monat (int monat, int jahr)
{
  int anzahl_tage = 0;

  if (monat == 4 || monat == 6 || monat == 9 || monat == 11)
  {
    anzahl_tage = 30;
  }
  else if(monat == 1 || monat == 3 || monat == 5 || monat == 7 || monat == 8 || monat == 10 || monat == 12)
  {
    anzahl_tage = 31;
  }
  else
  {
    int schaltjahr = ist_schaltjahr(jahr);
    if (schaltjahr == 1)
    {
      anzahl_tage = 29;
    }
    else
    {
      anzahl_tage = 28;
    }
  }

  return anzahl_tage;
}


/**Gibt den Kalender auf dem Bildschirm aus.
 *
 * @param startspalte  die Spalte des Kalenders, in die der erste Tag des Monats einzutragen ist
 * @param anzahl_tage  die Anzahl Tage, die der Monat hat
 * @param monat        der Monat
 * @param jahr         das Jahr
 *
 * @return  die Anzahl Tage, die der Monat hat.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
void schreibe_den_kalender (int startspalte, int anzahl_tage, int monat, int jahr)
{
  switch (monat)
  {
    case 1:
      printf("\nJanuar");
      break;
    case 2:
      printf("\nFebruar");
      break;
    case 3:
      printf("\nMärz");
      break;
    case 4:
      printf("\nApril");
      break;
    case 5:
      printf("\nMai");
      break;
    case 6:
      printf("\nJuni");
      break;
    case 7:
      printf("\nJuli");
      break;
    case 8:
      printf("\nAugust");
      break;
    case 9:
      printf("\nSeptember");
      break;
    case 10:
      printf("\nOktober");
      break;
    case 11:
      printf("\nNovember");
      break;
    case 12:
      printf("\nDezember");
      break;
    default:
      break;
  }
  printf(" %d\n", jahr);

  for (int i = 0; i < 7; i++)
  {
    switch (i)
    {
      case 0:
        printf("%4s", "So");
        break;
      case 1:
        printf("%4s", "Mo");
        break;
      case 2:
        printf("%4s", "Di");
        break;
      case 3:
        printf("%4s", "Mi");
        break;
      case 4:
        printf("%4s", "Do");
        break;
      case 5:
        printf("%4s", "Fr");
        break;
      case 6:
        printf("%4s", "Sa\n");
        break;
      default:
        break;
    }
  }

  char *zeichen = "=";
  schreibe_linie(zeichen, 30);
  schreibe_die_tage(startspalte, anzahl_tage);
  schreibe_linie(zeichen, 30);
}

/**Berechnet zu einem gegebenem Datum, um den wievielten Tag nach dem 1.1.1583 es sich handelt.
 *
 * @param tag          der Tag des Datums
 * @param monat        der Monat des Datums
 * @param jahr         das Jahr des Datums
 *
 * @return  die Anzahl Tage seit dem 1.1.1583 bis zum Datum.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int berechne_wievielter_tag_seit_beginn (int tag, int monat, int jahr)
{
  int anzahl = 0;
  for (int i = 1583; i < jahr; i++)
  {
    anzahl = anzahl + 365;
    if (ist_schaltjahr(i) == 1)
    {
      anzahl = anzahl + 1;
    }
  }
  if (monat != 1)
  {
    for (int j = 1; j < monat; j++)
    {
      int tage_im_monat = ermittle_wieviel_tage_im_monat(j, jahr);
      anzahl = anzahl + tage_im_monat;
    }
  }
  anzahl = anzahl + (tag - 1);

  return anzahl;
}

/**Stellt fest, ob ein Jahr ein Schaltjahr ist.
 *
 * @param jahr         das Jahr
 *
 * @return  hat den Wert 'wahr', wenn das Jahr ein Schaltjahr ist, ansonsten den Wert 'falsch'.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
char ist_schaltjahr (int jahr)
{
  char ergebnis = 0;

  if ((jahr % 4) == 0)
  {
    if ((jahr % 400) == 0)
    {
      ergebnis = 1;
    }
    else
    {
      if ((jahr % 100) == 0)
      {
        ergebnis = 0;
      }
      else
      {
        ergebnis = 1;
      }
    }
  }
  else
  {
    ergebnis = 0;
  }

  return ergebnis;
}

/**Schreibt eine waagerechte Linie auf dem Bildschirm.
 *
 * @param zeichen         das Zeichen, aus dem die Linie gebildet wird
 * @param anzahl_zeichen  legt fest, wie lang die Linie ist
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
void schreibe_linie (char *zeichen, int anzahl_zeichen)
{
  for (int i = anzahl_zeichen; i > 0; --i)
  {
    printf("%s", zeichen);
  }
  printf("\n");
}

/**Schreibt die Tage des Monats in den Kalender.
 *
 * @param startspalte  die Spalte des Kalenders, in die der erste Tag des Monats einzutragen ist.
 * @param anzahl_tage  die Anzahl Tage, die der Monat hat
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
void schreibe_die_tage (int startspalte, int anzahl_tage)
{
  int spalte;
  for (spalte = 0; spalte < startspalte; spalte++)
  {
    printf("%4c", ' ');
  }
  for (int tag = 1; tag <= anzahl_tage; tag++)
  {
    printf("%4d", tag);
    spalte = spalte + 1;
    if (spalte == 7)
    {
      spalte = 0;
      if (tag != anzahl_tage)
      {
        printf("\n");
      }
    }
  }
  printf("\n");
}
