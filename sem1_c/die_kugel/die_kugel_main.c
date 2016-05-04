#include <stdio.h>

#include "interaktionen.h"
#include "laengeneinheiten.h"
#include "mathe.h"

/**Das Prorgramm erfasst den Radius einer Kugel. Danach werden die Maße der Kugel berechnet und in tabellarischer
 * Form auf der Konsole ausgegeben.
 *
 * Die Maße sind:       Radius, Durchmesser, Umfang, Oberflaeche und Volumen
 *
 * Diese werden jeweils in verschiedenen Maßeinheiten ausgegeben:
 * metrische:           Millimeter, Zentimeter, Meter und Kilometer.
 * angloamerikanische:  inch, foot, yard, mile.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int main(void)
{
  printf("Das Prorgramm erfasst den Radius einer Kugel. Danach werden die Maße der Kugel berechnet und\n"
      "in tabellarischer Form auf der Konsole ausgegeben.\n");

  char *ausgabetext = "\nBitte geben Sie den Radius einer Kugel in Meter ein: \t";
  double r_meter = erfasse_gleitkomma_zahl(ausgabetext, 0, 1000000);

  printf("\nDie Kugel hat folgende Werte:\n");

  char spalte_1 = 25, spalte_2 = 30, spalte_3 = 30, spalte_4 = 30;

  printf("%-*s %*s %*s %*s\n",              spalte_1, "",           spalte_2, "Radius",      spalte_3, "Durchmesser",
      spalte_4, "Umfang");

  double r_zentimeter = r_meter * 100;
  double r_millimeter = r_zentimeter * 10;
  double r_kilometer = r_meter / 1000;

  double d_millimeter = berechne_durchmesser_kreis(r_millimeter);
  double d_zentimeter = berechne_durchmesser_kreis(r_zentimeter);
  double d_meter = berechne_durchmesser_kreis(r_meter);
  double d_kilometer = berechne_durchmesser_kreis(r_kilometer);

  double u_millimeter = berechne_umfang_kreis_mit_durchmesser(d_millimeter);
  double u_zentimeter = berechne_umfang_kreis_mit_durchmesser(d_zentimeter);
  double u_meter = berechne_umfang_kreis_mit_durchmesser(d_meter);
  double u_kilometer = berechne_umfang_kreis_mit_durchmesser(d_kilometer);

  printf("%-*s %*.2lf %*.2lf %*.2lf\n",     spalte_1, "Millimeter", spalte_2, r_millimeter,  spalte_3, d_millimeter,
      spalte_4, u_millimeter);
  printf("%-*s %*.2lf %*.2lf %*.2lf\n",     spalte_1, "Zentimeter", spalte_2, r_zentimeter,  spalte_3, d_zentimeter,
      spalte_4, u_zentimeter);
  printf("%-*s %*.5lf %*.5lf %*.5lf\n",     spalte_1, "Meter",      spalte_2, r_meter,       spalte_3, d_meter,
      spalte_4, u_meter);
  printf("%-*s %*.12lf %*.12lf %*.12lf\n",  spalte_1, "Kilometer",  spalte_2, r_kilometer,   spalte_3, d_kilometer,
      spalte_4, u_kilometer);

  double r_inch = umrechnung_mm_in_inch(r_millimeter);
  double r_foot = r_inch / 12;
  double r_yard = r_foot / 3;
  double r_mile = r_yard / 1760;

  double d_inch = berechne_durchmesser_kreis(r_inch);
  double d_foot = berechne_durchmesser_kreis(r_foot);
  double d_yard = berechne_durchmesser_kreis(r_yard);
  double d_mile = berechne_durchmesser_kreis(r_mile);

  double u_inch = berechne_umfang_kreis_mit_durchmesser(d_inch);
  double u_foot = berechne_umfang_kreis_mit_durchmesser(d_foot);
  double u_yard = berechne_umfang_kreis_mit_durchmesser(d_yard);
  double u_mile = berechne_umfang_kreis_mit_durchmesser(d_mile);

  printf("\n%-*s %*.2lf %*.2lf %*.2lf\n",   spalte_1, "inch",     spalte_2, r_inch,       spalte_3, d_inch,
      spalte_4, u_inch);
  printf("%-*s %*.2lf %*.2lf %*.2lf\n",     spalte_1, "foot",     spalte_2, r_foot,       spalte_3, d_foot,
      spalte_4, u_foot);
  printf("%-*s %*.5lf %*.5lf %*.5lf\n",     spalte_1, "yard",     spalte_2, r_yard,       spalte_3, d_yard,
      spalte_4, u_yard);
  printf("%-*s %*.12lf %*.12lf %*.12lf\n",  spalte_1, "mile",     spalte_2, r_mile,       spalte_3, d_mile,
      spalte_4, u_mile);

  printf("\n%-*s %*s %*s %*s\n",            spalte_1, "",         spalte_2, "",         spalte_3, "",
      spalte_4, "Oberflaeche");

  double a_millimeter = berechne_oberflaeche_kugel_mit_durchmesser(d_millimeter);
  double a_zentimeter = berechne_oberflaeche_kugel_mit_durchmesser(d_zentimeter);
  double a_meter = berechne_oberflaeche_kugel_mit_durchmesser(d_meter);
  double a_kilometer = berechne_oberflaeche_kugel_mit_durchmesser(d_kilometer);

  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "Quadratmillimeter", spalte_2, "",  spalte_3, "",
      spalte_4, a_millimeter);
  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "Quadratzentimeter", spalte_2, "",  spalte_3, "",
      spalte_4, a_zentimeter);
  printf("%-*s %*s %*s %*.5lf\n",           spalte_1, "Quadratmeter",      spalte_2, "",  spalte_3, "",
      spalte_4, a_meter);
  printf("%-*s %*s %*s %*.12lf\n",          spalte_1, "Quadratkilometer",  spalte_2, "",  spalte_3, "",
      spalte_4, a_kilometer);

  double a_inch = berechne_oberflaeche_kugel_mit_durchmesser(d_inch);
  double a_foot = berechne_oberflaeche_kugel_mit_durchmesser(d_foot);
  double a_yard = berechne_oberflaeche_kugel_mit_durchmesser(d_yard);
  double a_mile = berechne_oberflaeche_kugel_mit_durchmesser(d_mile);

  printf("\n%-*s %*s %*s %*.2lf\n",         spalte_1, "square inch",     spalte_2, "",       spalte_3, "",
      spalte_4, a_inch);
  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "square foot",     spalte_2, "",       spalte_3, "",
      spalte_4, a_foot);
  printf("%-*s %*s %*s %*.5lf\n",           spalte_1, "square yard",     spalte_2, "",       spalte_3, "",
      spalte_4, a_yard);
  printf("%-*s %*s %*s %*.12lf\n",          spalte_1, "square mile",     spalte_2, "",       spalte_3, "",
      spalte_4, a_mile);


  printf("\n%-*s %*s %*s %*s\n",            spalte_1, "",         spalte_2, "",         spalte_3, "",
      spalte_4, "Volumen");

  double v_millimeter = berechne_volumen_kugel_mit_durchmesser(d_millimeter);
  double v_zentimeter = berechne_volumen_kugel_mit_durchmesser(d_zentimeter);
  double v_meter = berechne_volumen_kugel_mit_durchmesser(d_meter);
  double v_kilometer = berechne_volumen_kugel_mit_durchmesser(d_kilometer);

  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "Kubikmillimeter", spalte_2, "",  spalte_3, "",
      spalte_4, v_millimeter);
  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "Kubikzentimeter", spalte_2, "",  spalte_3, "",
      spalte_4, v_zentimeter);
  printf("%-*s %*s %*s %*.5lf\n",           spalte_1, "Kubikmeter",      spalte_2, "",  spalte_3, "",
      spalte_4, v_meter);
  printf("%-*s %*s %*s %*.14lf\n",          spalte_1, "Kubikkilometer",  spalte_2, "",  spalte_3, "",
      spalte_4, v_kilometer);

  double v_inch = berechne_volumen_kugel_mit_durchmesser(d_inch);
  double v_foot = berechne_volumen_kugel_mit_durchmesser(d_foot);
  double v_yard = berechne_volumen_kugel_mit_durchmesser(d_yard);
  double v_mile = berechne_volumen_kugel_mit_durchmesser(d_mile);

  printf("\n%-*s %*s %*s %*.2lf\n",         spalte_1, "cubic inch",     spalte_2, "",       spalte_3, "",
      spalte_4, v_inch);
  printf("%-*s %*s %*s %*.2lf\n",           spalte_1, "cubic foot",     spalte_2, "",       spalte_3, "",
      spalte_4, v_foot);
  printf("%-*s %*s %*s %*.5lf\n",           spalte_1, "cubic yard",     spalte_2, "",       spalte_3, "",
      spalte_4, v_yard);
  printf("%-*s %*s %*s %*.14lf\n",          spalte_1, "cubic mile",     spalte_2, "",       spalte_3, "",
      spalte_4, v_mile);
}
