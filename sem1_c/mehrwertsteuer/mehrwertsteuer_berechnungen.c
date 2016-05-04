/**  Berechnet zu gegebenem Preis und Mehrwertsteuersatz, wie
 *	 groß der Mehrwertsteuerbetrag ist.
 * 
 *   @param   preis     		der Preis
 *   @param   mwst_satz     	der Mehrwertsteuersatz in Prozent
 *
 *   @return  mehrwertsteuer   	der Mehrwertsteuerbetrag oder -1, wenn
 *								die Mehrwertsteuer nicht berechnet
 *								werden konnte
 *
 *   @author   Viktor Schmidt, s0529652
 *   @version  1.0
 */

//Deklarationen
#include <stdio.h>

#include "mehrwertsteuer_berechnungen.h"

//Funktionen
float berechne_nettopreis(float bruttopreis, float mwst)
{
   float nettopreis;
   if ((bruttopreis >= 0) && (0 <= mwst) && (mwst <= 100))
     nettopreis = bruttopreis / (1 + mwst / 100 );
   else
   {
     printf("Nettopreis kann nicht berechnet werden.\n");
     nettopreis = -1;
   }
   return nettopreis;
}

float berechne_mehrwertsteuer(float preis, float mwst_satz)
{
  float mehrwertsteuer;
  if ((preis >= 0) && (0 <= mwst_satz) && (mwst_satz <= 100))
    mehrwertsteuer = (preis / 100) * mwst_satz;
  else
  {
    printf("Mehrwertsteuer kann nicht berechnet werden.\n");
    mehrwertsteuer = -1;
  }
  return mehrwertsteuer;
}
