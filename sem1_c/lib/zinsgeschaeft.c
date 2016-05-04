#include <stdio.h>
#include <math.h>

#include "zinsgeschaeft.h"

/**Berechnet die (anfängliche) Tilgungrate in der Höhe eines Tilgungssatzes für ein Kredit.
 *
 * @param	kredit							die Höhe des Kredits.
 * @param	tilgungssatz				Tilgungssatz, dezimal (z.B. 7% in der dezimal Form 0.07 angeben).
 *
 * @return	die (anfängliche) Tilgungsrate.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
double berechne_tilgungsrate (double kredit, double tilgungssatz)
{
  double tilgungsrate = kredit * tilgungssatz;

  return tilgungsrate;
}

/**Berechnet die anfallende Zinsen in der Höhe eines Zinssatzes für ein Kredit.
 *
 * @param kredit              die Höhe des Kredits.
 * @param zinssatz            Zinssatz, dezimal (z.B. 5% in der dezimal Form 0.05 angeben).
 *
 * @return  anfallende Zinsen.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_zinsen (double kredit, double zinssatz)
{
  double zinsen = kredit * zinssatz;

  return zinsen;
}

/**Berechnet die (jährlich) nachschüssig zu zahlende Prozentannuität für ein Annuitätendarlehen/Kredit.
 *
 * @param kredit              die Höhe des Kredits.
 * @param zinssatz            Zinssatz, dezimal (z.B. 5% in der dezimal Form 0.05 angeben).
 * @param laufzeit            die Laufzeit in Jahren für ein Annuitätendarlehen.
 *
 * @return  die (jährlich) nachschüssig zu zahlende Prozentannuität.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_annuitaet_wiki (double kredit, double zinssatz, int laufzeit)
{
  double annuitaet = kredit * ((zinssatz * pow((1 + zinssatz), laufzeit)) / (pow((1 + zinssatz), laufzeit) - 1));

  return annuitaet;
}

/**Berechnet die (jährlich) nachschüssig zu zahlende Prozentannuität für ein Annuitätendarlehen/Kredit.
 *
 * @param tilgungsrate        die (anfängliche) Tilgungsrate für ein Kredit.
 * @param zinsen              anfallende Zinsen für ein Kredit.
 *
 * @return  die (jährlich) nachschüssig zu zahlende Prozentannuität.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
double berechne_annuitaet (double tilgungsrate, double zinsen)
{
  double annuitaet = tilgungsrate + zinsen;

  return annuitaet;
}

/**Berechnet die Laufzeit in Jahren für ein Annuitätendarlehen.
 *
 * @param tilgungssatz        Tilgungssatz, dezimal (z.B. 7% in der dezimal Form 0.07 angeben).
 * @param zinssatz            Zinssatz, dezimal (z.B. 5% in der dezimal Form 0.05 angeben).
 *
 * @return  die Laufzeit in Jahren für ein Annuitätendarlehen.
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
int berechne_laufzeit_annuitaetendarlehen (double tilgungssatz, double zinssatz)
{
  int laufzeit = log(1 +  zinssatz / tilgungssatz) / log(1 + zinssatz);

  return laufzeit;
}

/**erstellt einen Tilgungsplan für ein Annuitätendarlehen und gibt diesen auf die Konsole aus.
 * Die Funktion berechnet die Laufzeit, die jährliche Annuität und Abzahlung bis zu einer Abschlusszahlung.
 * Zusäzlich wird der Gesamtaufwand für diesen Kredit berechnet und ausgeben.
 *
 * @param kredit              die Höhe des Kredits.
 * @param tilgungssatz        Tilgungssatz in Prozent (z.B. 7%).
 * @param zinssatz            Zinssatz in Prozent (z.B. 5%).
 *
 * @author  Viktor Schmidt, s0529652
 * @version 1.0
 */
void schreibe_tilgungsplan_fuer_ein_annuitaetendarlehen (double kredit, double zinssatz, double tilgungssatz)
{
  printf("\n%50s\n", "TILGUNGSPLAN");
  printf("\n%-15s %15.lf %s %15s %8.1lf %s %15s %8.1lf %s\n",
          "Kredit :", kredit, "Euro", "Zinssatz :", zinssatz, "%", "Tilgung :", tilgungssatz, "%");

  tilgungssatz = tilgungssatz / 100;
  zinssatz = zinssatz / 100;
  int laufzeit = berechne_laufzeit_annuitaetendarlehen(tilgungssatz, zinssatz);
  double tilgung = berechne_tilgungsrate(kredit, tilgungssatz);
  double zinsen = berechne_zinsen(kredit, zinssatz);
  //berechne_annuitaet (2 Wege)
  //double annuitaet = berechne_annuitaet_wiki(kredit, zinssatz, laufzeit);
  double annuitaet = berechne_annuitaet(tilgung, zinsen);
  double restkredit = 0;
  double gesamtaufwand = 0;

  printf("\n%5s %15s %15s %15s %15s %15s\n", "Jahr", "Kredit A", "Annuitaet", "Tilgung", "Zinsen", "Kredit E");
  for (int i = 0; i < laufzeit; i++)
  {
    restkredit = kredit - tilgung;
    printf("%5d %15.2lf %15.2lf %15.2lf %15.2lf %15.2lf\n",
            i, kredit, annuitaet, tilgung, zinsen, restkredit);
    kredit = restkredit;
    gesamtaufwand = gesamtaufwand + annuitaet;
    zinsen = berechne_zinsen(kredit, zinssatz);
    tilgung = annuitaet - zinsen;
  }

  gesamtaufwand = gesamtaufwand + restkredit;
  printf("\n%-20s %15.2lf Euro\n", "Abschlusszahlung:", restkredit);
  printf("%-20s %15.2lf Euro\n", "Gesamtaufwand:", gesamtaufwand);
}
