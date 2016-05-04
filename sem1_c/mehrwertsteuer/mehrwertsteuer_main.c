/**  Berechnet zu gegebenem Preis und Mehrwertsteuersatz, wie
 *	 groß der um den Mehrwertsteueranteil verringerte Preis
 *   ist.
 * 
 *   @param   bruttopreis   der Preis
 *   @param   mwst          der Mehrwertsteuersatz in Prozent
 *
 *   @return  nettopreis    der um den Mehrwertsteueranteil als Rückgabewert ausgegeben wird
 *   						verringerte Preis oder -1, wenn er nicht
 *							berechnet werden konnte
 *
 *   @author   Viktor Schmidt
 *   @version  1.0
 */

//Deklarationen
#include <stdio.h>

#include "mehrwertsteuer_berechnungen.h"

//Funktionen
//Funktion main
int main(void)
{
  printf("\nProgramm zum Berechnen des Mehrwertsteueranteils"
         " von Preisen.\n");
  printf("\nEingabe Bruttopreis in Euro:        ");

  float bruttopreis;
  scanf("%f", &bruttopreis);
  printf("Eingabe Mehrwertsteuersatz in %%:    ");
  float mwst_satz;
  scanf("%f", &mwst_satz);
  float nettopreis;
  nettopreis = berechne_nettopreis(bruttopreis, mwst_satz);
  float mwst_anteil;
  mwst_anteil = berechne_mehrwertsteuer(nettopreis, mwst_satz);

  if (nettopreis >= 0 && mwst_anteil >= 0)
  {
    printf("\nBruttopreis:            %10.2f Euro", bruttopreis);
    printf("\nNettopreis:             %10.2f Euro", nettopreis);
    printf("\nMehrwertsteueranteil:   %10.2f Euro\n\n", mwst_anteil);
  }
}
