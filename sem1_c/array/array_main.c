#include <stdio.h>
#include <stdlib.h>

#include "interaktionen.h"
#include "zahlensystem.h"
#include "arrays.h"
#include "statistik.h"

void erzeuge_zufall_int_array(void);
void erzeuge_zufall_double_array(void);

/**Das Prorgramm erzeuge ein Array mit zufaelligen Zahlen aus dem Bereich von a bis b und werte es aus.
 * Es werden umfangreiche Statistiken zum Array ausgegeben.
 *
 * <br>Hierbei ist:
 * <br>Laenge - die Länge des Arrays
 * <br>Minimum - die kleinste der im Array gespeicherten Zahlen
 * <br>Maximum - die größte der im Array gespeicherten Zahlen
 * <br>Summe - die Summe der im Array gespeicherten Zahlen
 * <br>Durchschnitt - das arithmetische Mittel der im Array gespeicherten Zahlen
 * <br>Median - der Median der im Array gespeicherten Zahlen
 * <br>Varianz - die Stichprobenvarianz der im Array gespeicherten Zahlen
 * <br>Standardabweichung - die Standardabweichung der im Array gespeicherten Zahlen
 * <br>kleinster Abstand - der kleinste Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt
 * <br>groesster Abstand - der größte Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  printf("\nDas Prorgramm erzeuge ein Array mit zufaelligen Zahlen aus dem Bereich von a bis b und werte es aus.\n");

  char menue[][20] = {"int-Array", "double-Array", "Programm beenden"};
  switch(waehle_aus_menue(3, 20, menue))
  {
    case 1:
    	erzeuge_zufall_int_array();
    	break;
    case 2:
    	erzeuge_zufall_double_array();
      break;
    default:
      puts("\nDas Programm wird beendet. See You!\n");
      break;
  }
}

/**Erzeuge ein Array mit ganze Zufallszahl aus dem Bereich von a bis b und werte es aus.
 * Es werden umfangreiche Statistiken zum Array ausgegeben.
 *
 * <br>Hierbei ist:
 * <br>Laenge - die Länge des Arrays
 * <br>Minimum - die kleinste der im Array gespeicherten Zahlen
 * <br>Maximum - die größte der im Array gespeicherten Zahlen
 * <br>Summe - die Summe der im Array gespeicherten Zahlen
 * <br>Durchschnitt - das arithmetische Mittel der im Array gespeicherten Zahlen
 * <br>Median - der Median der im Array gespeicherten Zahlen
 * <br>Varianz - die Stichprobenvarianz der im Array gespeicherten Zahlen
 * <br>Standardabweichung - die Standardabweichung der im Array gespeicherten Zahlen
 * <br>kleinster Abstand - der kleinste Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt
 * <br>groesster Abstand - der größte Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void erzeuge_zufall_int_array(void)
{
  puts("\nEs soll ein int-Array erzeugt werden:\n");
  char *ausgabetext = "\nBitte geben Sie die Laenge des Arrays ein [2 - 1000]: \t";
  int laenge = erfasse_ganze_zahl(ausgabetext, 2, 1000);
  ausgabetext = "Bitte geben Sie den Wert fuer a ein [-10000 - +10000]: \t";
  int int_a = erfasse_ganze_zahl(ausgabetext, -10000, 10000);
  ausgabetext = "Bitte geben Sie den Wert fuer b ein [a - 50000]: \t";
  int int_b = erfasse_ganze_zahl(ausgabetext, int_a, 50000);

  int int_array[laenge];
  initialisiere_zufallszahlengenerator();
  initialisiere_int_array_zufaellig(int_array, laenge, int_a, int_b);
  schreibe_int_array_statistik(int_array, laenge);
}

/**Erzeuge ein Array mit Gleitkommazufallszahl aus dem Bereich von a bis b und werte es aus.
 * Es werden umfangreiche Statistiken zum Array ausgegeben.
 *
 * <br>Hierbei ist:
 * <br>Laenge - die Länge des Arrays
 * <br>Minimum - die kleinste der im Array gespeicherten Zahlen
 * <br>Maximum - die größte der im Array gespeicherten Zahlen
 * <br>Summe - die Summe der im Array gespeicherten Zahlen
 * <br>Durchschnitt - das arithmetische Mittel der im Array gespeicherten Zahlen
 * <br>Median - der Median der im Array gespeicherten Zahlen
 * <br>Varianz - die Stichprobenvarianz der im Array gespeicherten Zahlen
 * <br>Standardabweichung - die Standardabweichung der im Array gespeicherten Zahlen
 * <br>kleinster Abstand - der kleinste Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt
 * <br>groesster Abstand - der größte Abstand zweier unmittelbar aufeinanderfolgender Zahlen im Array,
 * und Stelle der erste Index von links, an dem er auftritt.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void erzeuge_zufall_double_array(void)
{
  puts("\nEs soll ein double-Array erzeugt werden:\n");
  char *ausgabetext = "Bitte geben Sie die Laenge des Arrays ein [2 - 1000]: \t";
  int laenge = erfasse_ganze_zahl(ausgabetext, 2, 1000);
  ausgabetext = "Bitte geben Sie den Wert fuer a ein [-10000 - +10000]: \t";
  double double_a = erfasse_gleitkomma_zahl(ausgabetext, -10000, 10000);
  ausgabetext = "Bitte geben Sie den Wert fuer b ein [a - 50000]: \t";
  double double_b = erfasse_gleitkomma_zahl(ausgabetext, double_a, 1000000);

  double double_array[laenge];
  initialisiere_zufallszahlengenerator();
  initialisiere_double_array_zufaellig(double_array, laenge, double_a, double_b);
  schreibe_double_array_statistik(double_array, laenge);
}
