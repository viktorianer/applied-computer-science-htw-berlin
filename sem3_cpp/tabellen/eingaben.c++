#include "eingaben.h"
/**
 * Erfasst eine long-Zahl. Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die long-Zahl die erfasst wurde.
 */
long erfasse_long(long min, long max)
{
  if (max < min)
    vertausche(min, max);
  long eingabe = 0;
  bool eingabe_ok = false;
  cin.clear();
  cin.unsetf(cin.skipws);
  do
  {
    cin >> eingabe;
    eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
    cin.clear();
    cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
    if (!eingabe_ok)
    {
      cout << "Bitte eine ganze Zahl eingeben [";
      cout << min << " - " << max << "]:  ";
    }
  } while (!eingabe_ok);
  cin.setf(cin.skipws);
  return eingabe;
}
/**
 * Erfasst eine long-Zahl.
 * @return Die long-Zahl die erfasst wurde.
 */
long erfasse_long()
{
  return erfasse_long(LONG_MAX * -1, LONG_MAX);
}
/**
 * Erfasst eine long-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die long-Zahl die erfasst wurde.
 */
long erfasse_long(string text)
{
  cout << text;
  return erfasse_long();
}
/**
 * Erfasst eine long-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param text      Beschreibung der Eingabe.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return
 */
long erfasse_long(string text, long min, long max)
{
  cout << text;
  return erfasse_long(min, max);
}
/**
 * Erfasst eine int-Zahl. Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die int-Zahl die erfasst wurde.
 */
int erfasse_int(int min, int max)
{
  return static_cast<int>(erfasse_long(min, max));
}
/**
 * Erfasst eine int-Zahl.
 * @return Die int-Zahl die erfasst wurde.
 */
int erfasse_int()
{
  return static_cast<int>(erfasse_long(INT_MAX * -1, INT_MAX));
}
/**
 * Erfasst eine int-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die int-Zahl die erfasst wurde.
 */
int erfasse_int(string text)
{
  cout << text;
  return erfasse_int();
}
/**
 * Erfasst eine int-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die int-Zahl die erfasst wurde.
 */
int erfasse_int(string text, int min, int max)
{
  cout << text;
  return erfasse_int(min, max);
}
/**
 * Erfasst eine long double-Zahl. Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die long double-Zahl die erfasst wurde.
 */
long double erfasse_long_double(long double min, long double max)
{
  if (max < min)
    vertausche(min, max);
  long double eingabe = 0;
  bool eingabe_ok = false;
  cin.clear();
  cin.unsetf(cin.skipws);
  do
  {
    cin >> eingabe;
    eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
    cin.clear();
    cin.ignore(static_cast<streamsize>(LDBL_MAX), '\n');
    if (!eingabe_ok)
    {
      cout << "Bitte eine ganze Zahl eingeben [";
      cout << min << " - " << max << "]:  ";
    }
  } while (!eingabe_ok);
  cin.setf(cin.skipws);
  return eingabe;
}
/**
 * Erfasst eine long double-Zahl.
 * @return Die long double-Zahl die erfasst wurde.
 */
long double erfasse_long_double()
{
  return erfasse_long_double(LDBL_MAX * -1, LDBL_MAX);
}
/**
 * Erfasst eine long double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die long double-Zahl die erfasst wurde.
 */
long double erfasse_long_double(string text)
{
  cout << text;
  return erfasse_long_double();
}
/**
 * Erfasst eine long double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die long double-Zahl die erfasst wurde.
 */
long double erfasse_long_double(string text, long double min, long double max)
{
  cout << text;
  return erfasse_long_double(min, max);
}
/**
 * Erfasst eine double-Zahl. Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die double-Zahl die erfasst wurde.
 */
double erfasse_double(double min, double max)
{
  return static_cast<double>(erfasse_double(min, max));
}
/**
 * Erfasst eine double-Zahl.
 * @return Die double-Zahl die erfasst wurde.
 */
double erfasse_double()
{
  return static_cast<double>(erfasse_double(DBL_MAX * -1, DBL_MAX));
}
/**
 * Erfasst eine double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die double-Zahl die erfasst wurde.
 */
double erfasse_double(string text)
{
  cout << text;
  return erfasse_double();
}
/**
 * Erfasst eine double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl
 * @return Die double-Zahl die erfasst wurde.
 */
double erfasse_double(string text, double min, double max)
{
  cout << text;
  return erfasse_double(min, max);
}
/**
 * Erfasst einen bool-Wert.
 * @return Der bool-Wert der erfasst wurde.
 */
bool erfasse_bool()
{
  bool eingabe = 0;
  bool eingabe_ok = false;
  cin.clear();
  cin.unsetf(cin.skipws);
  cin.setf(cin.boolalpha);
  do
  {
    cin >> eingabe;
    eingabe_ok = cin.good();
    cin.clear();
    cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
    if (!eingabe_ok)
      cout << "Bitte true oder false eingeben:  ";
  } while (!eingabe_ok);
  cin.setf(cin.skipws);
  cin.unsetf(cin.boolalpha);
  return eingabe;
}
/**
 * Erfasst eine Zeichenkette (Text) einer bestimmten Laenge.
 * @param eingabe   \c Input:  \n Das Array, dessen Komponenten den Text beinhalten sollen.\n
 *                  \c Output: \n Dasselbe Array, dessen Komponenten den Text beinhalten.\n
 * @param anzahl    Die max. Laenge der Zeichenkette.
 */
void erfasse_zeichenkette(char eingabe[], streamsize anzahl)
{
  streamsize alter_wert = cin.width();
  cin.width(anzahl);
  cin.get(eingabe, anzahl);
  cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
  cin.width(alter_wert);
}