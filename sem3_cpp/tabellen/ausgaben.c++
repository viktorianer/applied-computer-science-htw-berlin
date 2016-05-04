#include "ausgaben.h"
/**
 * Schreibt bestimmte Anzahl an Zeichen in eine Datei.
 * @param anzahl    Die Anzahl der Zeichen.
 * @param zeichen   Das Zeichen, welches geschrieben werden soll.
 * @param datei     Die Datei, in die geschrieben wird.
 */
void schreibe(int anzahl, char zeichen, FILE *datei)
{
  while (anzahl-- > 0)
    fputc(zeichen, datei);
}
/**
 * Schreibt bestimmte Anzahl an Zeichen in stdout.
 * @param anzahl    Die Anzahl der Zeichen.
 * @param zeichen   Das Zeichen, welches geschrieben werden soll.
 */
void schreibe(int anzahl, char zeichen)
{
  schreibe(anzahl, zeichen, stdout);
}
/**
 * Schreibt ein Zeichen in stdout.
 * @param zeichen
 */
void schreibe(char zeichen)
{
  schreibe(1, zeichen, stdout);
}
/**
 * Schreibt ein Text in eine Datei. Der Text wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * Zusätzlich kann der Text zentriert ausgegeben werden.
 * @param text          Der Text, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param zentriert     Gibt an, ob der Text zentriert ausgegeben werden soll oder nicht.
 * @param datei         Die Datei, in die geschrieben wird.
 */
void schreibe(const char *text, int feldbreite, bool zentriert, FILE *datei)
{
  if (zentriert)
  {
    if (feldbreite < 0)
      feldbreite *= -1;
    int anzahl = (feldbreite - static_cast<int>(strlen(text))) / 2;
    schreibe(anzahl, ' ', datei);
    fprintf(datei, "%s", text);
  }
  else
    schreibe(text, feldbreite, datei);
}
/**
 * Schreibt ein Text in stdout. Der Text wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param text          Der Text, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param zentriert     Gibt an, ob der Text zentriert ausgegeben werden soll oder nicht.
 */
void schreibe(const char *text, int feldbreite, bool zentriert)
{
  schreibe(text, feldbreite, zentriert, stdout);
}
/**
 * Schreibt ein Text in eine Datei. Der Text wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param text          Der Text, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param datei         Die Datei, in die geschrieben wird.
 */
void schreibe(const char *text, int feldbreite, FILE *datei)
{
  fprintf(datei, "%*s", feldbreite, text);
}
/**
 * Schreibt ein Text in stdout. Der Text wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param text          Der Text, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 */
void schreibe(const char *text, int feldbreite)
{
  schreibe(text, feldbreite, stdout);
}
/**
 * Schreibt ein Text in stdout. Der Text wird beim schreiben nicht formatiert.
 * @param text          Der Text, der ausgegeben werden soll.
 */
void schreibe(const char *text)
{
  schreibe(text, 1);
}
/**
 * Schreibt ein int-Zahl in stdout. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param zahl          Die Zahl, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 */
void schreibe(int zahl, int feldbreite)
{
  schreibe(zahl, feldbreite, stdout);
}
/**
 * Schreibt ein int-Zahl in stdout. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param zahl          Die Zahl, der ausgegeben werden soll.
 */
void schreibe(int zahl)
{
  schreibe(zahl, 0);
}
/**
 * Schreibt ein int-Zahl in eine Datei. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param zahl          Die Zahl, der ausgegeben werden soll.
 * @param feldbreite    Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param datei         Die Datei, in die geschrieben wird.
 */
void schreibe(int zahl, int feldbreite, FILE *datei)
{
  fprintf(datei, "%*d", feldbreite, zahl);
}
/**
 * Schreibt ein int-Array in eine Datei. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 * @param feldbreite        Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param trenner           Der Trenner, der nach jeder Komponente ausgegeben wird.
 * @param am_ende           Gibt an, ob der Trenner nach der letzten Komponente ausgegeben wird.
 * @param datei             Die Datei, in die geschrieben wird.
 */
void schreibe(const int array[], int laenge, int feldbreite,
              const char *trenner, bool am_ende, FILE *datei)
{
  for (int i = 0; i < laenge - 1; i++)
    fprintf(datei, "%*d%s", feldbreite, array[i], trenner);
  fprintf(datei, "%*d%s", feldbreite, array[laenge - 1],
          am_ende ? trenner : "");
}
/**
 * Schreibt ein int-Array in stdout. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 * @param feldbreite        Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param trenner           Der Trenner, der nach jeder Komponente ausgegeben wird.
 * @param am_ende           Gibt an, ob der Trenner nach der letzten Komponente ausgegeben wird.
 */
void schreibe(const int array[], int laenge, int feldbreite,
              const char *trenner, bool am_ende)
{
  schreibe(array, laenge, feldbreite, trenner, am_ende, stdout);
}
/**
 * Schreibt ein int-Array in stdout. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 * @param feldbreite        Die gewuenschte Zeilenbreite fuer die Ausgabe.
 * @param trenner           Der Trenner, der nach jeder Komponente ausgegeben wird.
 */
void schreibe(const int array[], int laenge, int feldbreite,
              const char *trenner)
{
  schreibe(array, laenge, feldbreite, trenner, false);
}
/**
 * Schreibt ein int-Array in stdout. Die Ausgabe wird beim schreiben formatiert. Dabei ist die Feldbreite die Breite einer Zeile.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 * @param feldbreite        Die gewuenschte Zeilenbreite fuer die Ausgabe.
 */
void schreibe(const int array[], int laenge, int feldbreite)
{
  schreibe(array, laenge, feldbreite, "", false);
}
/**
 * Schreibt ein int-Array in stdout.
 * @param array   \c Input:  \n Das Array, dessen Komponenten ausgegeben werden.\n
 *                \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden.\n
 * @param laenge            Die Laenge des Arrays.
 */
void schreibe(const int array[], int laenge)
{
  schreibe(array, laenge, 0, " ", false);
}
/**
 * Liefert die max. moegliche Spaltenanzahl auf der aktuell Ausgabe bei einer bestimmten Feldbreite einer Spalte.
 * @param feldbreite    Die Breite einer Spalte.
 * @return Die max. moegliche Spaltenanzahl auf der aktuell Ausgabe.
 */
int liefere_max_anzahl_spalten(int feldbreite)
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  //int windowshoehe = w.ws_row;
  int windowsbreite = w.ws_col - 10;
  int breite = static_cast<int>(floor((windowsbreite / feldbreite)));
  if (breite < 1)
    breite = 1;
  return breite;
}
/**
 * Liefert die benoetigte min. Feldbreite fuer die richtig Auszugeben der uebergebenen Zahlen.
 * @param gleitzahlen       \c Input:  \n Das Array, dessen Komponenten ausgegeben werden sollen.\n
 *                          \c Output: \n Dasselbe Array, dessen Komponenten ausgegeben wurden sollen.\n
 * @param anzahl            Die Anzahl der Zahlen im Arrays.
 * @return  Die benoetigte min. Feldbreite.
 */
int liefere_feldbreite(long double *gleitzahlen, int anzahl)
{
  long double zahl = *liefere_max_long_double_array(gleitzahlen, anzahl);
  stringstream streampuffer;
  streampuffer << zahl;
  string zahl_als_string = streampuffer.str();
  return zahl_als_string.size();
}