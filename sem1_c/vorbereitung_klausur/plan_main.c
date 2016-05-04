#include <stdio.h>


double lese_gleitkommazahl(char *ausgabetext, double min, double max)
{
  double zahl;
  printf("%s", ausgabetext);
  int funde = scanf("%lf", &zahl);
  if (funde == 1)
  {
    if (min >= zahl && zahl >= max)
    {
      printf("Bitte geben Sie eine Zahl zwischen %lf und %lf an!", min, max);
    }
  }
  else
  {
    printf("Bitte geben Sie eine Zahl zwischen %lf und %lf an!", min, max);
  }
  return zahl;
}

double berechne_anfangs_tilgung(double tilgungsrate, double kredit)
{
  tilgungsrate = kredit * tilgungsrate;
  return tilgungsrate;
}

double berechne_zinsen(double zinssatz, double kredit)
{
  zinssatz = kredit * zinssatz;
  return zinssatz;
}

double berechne_annuitaet(double zinssatz, double tilgungsrate)
{
  double annuitaet = zinssatz + tilgungsrate;
  return annuitaet;
}

void schreibe_tilgungsplan(double kredit, double zinssatz, double tilgungsrate)
{
  int jahr = 1;
  double tilgung = berechne_anfangs_tilgung(tilgungsrate, kredit);
  double zinsen = berechne_zinsen(zinssatz, kredit);
  double annuitaet = berechne_annuitaet(zinsen, tilgung);
  double restkredit = kredit - tilgung;
  double gesamtaufwand = annuitaet;

  printf("\n\t\t\t\t\t\tTILGUNGSPLAN\n");
  printf("\n%-6s %20s %20s %20s %20s %20s\n", "Jahr", "Kredit A", "Annuität", "Tilgung", "Zinsen", "Kredit E");
  printf("\n%-6d %20.2lf %20.2lf %20.2lf %20.2lf %20.2lf\n", jahr, kredit, annuitaet, tilgung, zinsen, restkredit);
  do
  {
    jahr = jahr + 1;
    kredit = restkredit;
    zinsen = berechne_zinsen(zinssatz, kredit);
    tilgung = annuitaet - zinsen;
    restkredit = kredit - tilgung;
    gesamtaufwand = gesamtaufwand + annuitaet;
    printf("%-6d %20.2lf %20.2lf %20.2lf %20.2lf %20.2lf\n", jahr, kredit, annuitaet, tilgung, zinsen, restkredit);
  } while (kredit >= annuitaet);

  gesamtaufwand = gesamtaufwand + restkredit;
  printf("\n%-20s %20.2lf Euro\n", "Abschlusszahlung: ", restkredit);
  printf("%-20s %20.2lf Euro\n", "Gesamtaufwand: ", gesamtaufwand);
}

int main(void)
{
  printf("\nhallo, das hier ist meine Klausurvorbereitung\n");

  char *ausgabetext = "\nBitte geben Sie die Höhe des Kredits an: ";
  double kredit = 80000; //lese_gleitkommazahl(ausgabetext, 1, 100000000);
  ausgabetext = "Bitte geben Sie den jährlichen Zinssatz für den Kredit in Prozent an: ";
  double zinssatz = 5; //lese_gleitkommazahl(ausgabetext, 0.1, 20);
  ausgabetext = "Bitte geben Sie die die anfängliche Tilgungsrate in Prozent an: ";
  double tilgungsrate = 7; //lese_gleitkommazahl(ausgabetext, 0.1, 10);

  zinssatz = zinssatz / 100;
  tilgungsrate = tilgungsrate / 100;

  schreibe_tilgungsplan(kredit, zinssatz, tilgungsrate);
}
