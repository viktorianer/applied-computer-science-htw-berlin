#include <iomanip>

#include "rechner.h"
/**
 * Berechnent die Werte ohne Benutzerinteraktionen und nur mit uebergebenen Parameter.
 * @param func      Die Funktion, mit der die Werte berechnet werden.
 * @param argv  Die Parameter.
 */
void rechner(long double (*func)(long double), char **argv)
{
  string funcname = argv[1];
  long double anfangwert = atof(argv[2]);
  int folgewerte = atoi(argv[3]);
  long double abstand = atof(argv[4]);
  int praezision = atof(argv[5]);
  rechner_rechne(func, funcname, anfangwert, folgewerte, abstand, praezision);
}
/**
 * Berechnent die Werte ohne Benutzerinteraktionen und nur mit uebergebenen Parameter.
 * @param func      Die Funktion, mit der die Werte berechnet werden.
 * @param argv  Die Parameter.
 */
void rechner(long double (*func)(long double, long double), char **argv)
{
  string funcname = argv[1];
  long double anfangwert = atof(argv[2]);
  long double exponent = atof(argv[3]);
  int folgewerte = atoi(argv[4]);
  long double abstand = atof(argv[5]);
  int praezision = atof(argv[6]);
  rechner_rechne(func, funcname, anfangwert, exponent, folgewerte, abstand, praezision);
}
/**
 * Berechnent die Werte mit Benutzerinteraktionen.
 * @param func      Die Funktion, mit der die Werte berechnet werden.
 * @param funcname  Der Funktionname.
 */
void rechner(long double (*func)(long double), string funcname)
{
  long double anfangwert = 0;
  int folgewerte = 0;
  long double abstand = 0;
  int praezision = 0;
  erfasse_parameter(funcname, anfangwert, folgewerte, abstand, praezision);
  rechner_rechne(func, funcname, anfangwert, folgewerte, abstand, praezision);
}
/**
 * Berechnent die Werte mit Benutzerinteraktionen.
 * @param func      Die Funktion, mit der die Werte berechnet werden.
 * @param funcname  Der Funktionname.
 */
void rechner(long double (*func)(long double, long double), string funcname)
{
  long double anfangwert = 0;
  long double exponent = 0;
  int folgewerte = 0;
  long double abstand = 0;
  int praezision = 0;
  erfasse_parameter(anfangwert, exponent, folgewerte, abstand, praezision);
  rechner_rechne(func, funcname, anfangwert, exponent, folgewerte, abstand, praezision);
}
/**
 * Berechnent mit einer bestimmten Funktion und Parameter die Werte im angegeben Zahlenbereich.
 * @param func          Die Funktion, mit der die Werte berechnet werden.
 * @param funcname      Der Funktionname.
 * @param anfangwert    Der Startwert.
 * @param folgewerte    Die Anzahl der Folgewerte.
 * @param abstand       Der Abstand zwischen den Werten.
 * @param praezision    Die Praezision, mit der die Ausgabe gemacht werden soll.
 */
void rechner_rechne(long double (*func)(long double), string funcname, long double anfangwert,
  int folgewerte, long double abstand, int praezision)
{
  long double (*werte)[10] = new long double[folgewerte + 1][10];
  long double *folge = new long double[folgewerte + 1];
  int k = 0;
  for (long double i = anfangwert; i < anfangwert + folgewerte * abstand; i += abstand)
  {
    folge[k] = i;
    for (int j = 0; j < 10; j++)
    {
      werte[k][j] = func(i + j * abstand * 0.1);
    }
    k++;
  }
  rechner_ausgabe(folge, werte, folgewerte, funcname, praezision);
  delete [] werte;
  werte = 0;
  delete [] folge;
  folge = 0;
}
/**
 * Berechnent mit einer bestimmten Funktion und Parameter die Werte im angegeben Zahlenbereich.
 * @param func          Die Funktion, mit der die Werte berechnet werden.
 * @param funcname      Der Funktionname.
 * @param anfangwert    Der Startwert.
 * @param exponent      Der Exponent.
 * @param folgewerte    Die Anzahl der Folgewerte.
 * @param abstand       Der Abstand zwischen den Werten.
 * @param praezision    Die Praezision, mit der die Ausgabe gemacht werden soll.
 */
void rechner_rechne(long double (*func)(long double, long double), string funcname, long double anfangwert,
  long double exponent, int folgewerte, long double abstand, int praezision)
{
  long double (*werte)[10] = new long double[folgewerte + 1][10];
  long double *folge = new long double[folgewerte + 1];
  int k = 0;
  for (long double i = anfangwert; i < anfangwert + folgewerte * abstand; i += abstand)
  {
    folge[k] = i;
    for (int j = 0; j < 10; j++)
    {
      werte[k][j] = func(i + j * abstand * 0.1, exponent);
    }
    k++;
  }
  rechner_ausgabe(folge, werte, folgewerte, funcname, praezision);
  delete [] werte;
  werte = 0;
  delete [] folge;
  folge = 0;
}
/**
 * Erfasst die benoetigten Werte fuer die Berechnung.
 * @param funcname      Der Funktionname.
 * @param anfangwert    Der Startwert.
 * @param folgewerte    Die Anzahl der Folgewerte.
 * @param abstand       Der Abstand zwischen den Werten.
 * @param praezision    Die Praezision, mit der die Ausgabe gemacht werden soll.
 */
void erfasse_parameter(string funcname, long double& anfangwert, int& folgewerte, long double& abstand, int& praezision)
{
  schreibe("Bitte den Anfangswert eingeben! ");
  if (funcname == "sqrt")
      anfangwert = erfasse_long_double(0, LDBL_MAX);
  else
      anfangwert = erfasse_long_double();
  schreibe("Bitte die Anzahl nachfolgender Werte eingeben! ");
  folgewerte = erfasse_int(1, INT_MAX);
  schreibe("Bitte den Abstand eingeben! ");
  abstand = erfasse_long_double();
  schreibe("Bitte eine Praezision eingeben! ");
  praezision = erfasse_int(1, 19);
}
/**
 * Erfasst die benoetigten Werte fuer die Berechnung.
 * @param anfangwert    Der Startwert.
 * @param exponent      Der Exponent.
 * @param folgewerte    Die Anzahl der Folgewerte.
 * @param abstand       Der Abstand zwischen den Werten.
 * @param praezision    Die Praezision, mit der die Ausgabe gemacht werden soll.
 */
void erfasse_parameter(long double& anfangwert, long double& exponent, int& folgewerte, long double& abstand, int& praezision)
{
  schreibe("Bitte den Exponenten eingeben! ");
  exponent = erfasse_long_double();
  erfasse_parameter("pow", anfangwert, folgewerte, abstand, praezision);
}
/**
 * Gibt die berechneten Werte auf dem Bildschirm aus.
 * <br>Die Darstellung der Wertetabelle ist einerseits übersichtlich (Beschriftung, Anordnung in Spalten,
 * eventuell Trennlinien), andererseits kompakt.
 * <br>
 * <br>Die Form der Wertetabelle, insbesondere die Breite der Spalten, ist von den erfassten Daten
 * (und der Funktion) abhängen. Wann immer auf dem Bildschirm darstellbar, wird sie so aussehen (Grundform):
 * <br>
 * <br>Funktion: cos x
 * <br>x \c 0 \c 1 \c 2 \c 3 \c 4 \c 5 \c 6 \c 7 \c 8 \c 9
 * <br>5.0 \c 0.284 \c 0.293 \c 0.303 \c 0.312 \c 0.322 \c 0.331 \c 0.341 \c 0.350 \c 0.359 \c 0.369
 * <br>5.1 \c 0.378 \c 0.887 \c 0.397 \c 0.410 \c 0.415 \c 0.424 \c 0.433 \c 0.442 \c 0.451 \c 0.460
 * <br>...
 * <br>...
 * <br>...
 * <br>5.8 \c 0.886 \c 0.890 \c 0.894 \c 0.899 \c 0.903 \c 0.910 \c 0.912 \c 0.916 \c 0.920 \c 0.924
 * <br>
 * <br>Ob die Wertetabelle so darstellbar ist, hängt von den Werten und der gewünschten Präzision ab.
 * Das Programm erkennt, ob es (bei einem Fenster maximaler Größe) möglich ist, und wählt gegebenenfalls eine andere Darstellung.
 * @param folge         Die Folge der Zahlen.
 * @param werte         Die berechneten Werte.
 * @param folgewerte    Die Anzahl der Folgewerte.
 * @param funcname      Der Funktionsname.
 * @param praezision    Die gewuenschte Praezision.
 */
void rechner_ausgabe(long double *folge, long double (*werte)[10], int folgewerte, string funcname, int praezision)
{
  int spaltenbreite = liefere_feldbreite(*werte, 10 * (folgewerte + 1)) + praezision;
  int anzahl_spalten_in_zeile = liefere_max_anzahl_spalten(spaltenbreite + 2) - 1;
  cout << "anzahl spalten " << anzahl_spalten_in_zeile << " und splatenbreite " << spaltenbreite << endl;
  cout << "Funktion: " << funcname << " x" << endl;
  for (int k = 0; k < 10;)
  {
    tabellen_kopf(k, k + anzahl_spalten_in_zeile, spaltenbreite);
    for (int i = 0; i < (folgewerte + 1); i++)
    {
      cout << setw(spaltenbreite) << left << setprecision(praezision) << fixed << folge[i];
      for (int j = k; j < k + anzahl_spalten_in_zeile && j < 10; j++)
      {
        cout << setw(2) << " " << setw(spaltenbreite) << right << setfill('.') << showpos << internal
          << setprecision(praezision + 1) << showpoint << fixed << werte[i][j]
          << setfill(' ') << noshowpos;
      }
      cout << endl;
    }
    k += anzahl_spalten_in_zeile;
    cout << endl;
  }
}
/**
 * Gibt den Tabellenkopf aus.
 * @param erste_spalte  Anfangswert, der im Tabellenkopf stehen soll.
 * @param letzte_spalte Endwert, der im Tabellenkopf stehen soll.
 * @param spaltenbreite Die gewuenschte Spaltenbreite.
 */
void tabellen_kopf(int erste_spalte, int letzte_spalte, int spaltenbreite)
{
  cout << setw(spaltenbreite) << left << "x";
  for (int j = erste_spalte; j < letzte_spalte && j < 10; j++)
  {
    cout  << setw(2) << " " << setw(spaltenbreite) << right << j;
  }
  cout << endl;
}