#include "eingaben.h"

/**
 * Erfasst eine long-Zahl. Dabei wird geprueft ob die eingegeben Zahl im Bereich von min. bis max. liegt.
 * @param min       Die kleinste erwuenschte Zahl.
 * @param max       Die groesste erwuenschte Zahl.
 * @return Die long-Zahl die erfasst wurde.
 */
long Eingaben::erfasse_long(long min, long max)
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
long Eingaben::erfasse_long()
{
  return erfasse_long(LONG_MAX * -1, LONG_MAX);
}
/**
 * Erfasst eine long-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die long-Zahl die erfasst wurde.
 */
long Eingaben::erfasse_long(const string text)
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
 * @return  Die long-Zahl die erfasst wurde.
 */
long Eingaben::erfasse_long(const string text, long min, long max)
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
int Eingaben::erfasse_int(int min, int max)
{
  return static_cast<int>(erfasse_long(min, max));
}
/**
 * Erfasst eine int-Zahl.
 * @return Die int-Zahl die erfasst wurde.
 */
int Eingaben::erfasse_int()
{
  return static_cast<int>(erfasse_long(INT_MAX * -1, INT_MAX));
}
/**
 * Erfasst eine int-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die int-Zahl die erfasst wurde.
 */
int Eingaben::erfasse_int(const string text)
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
int Eingaben::erfasse_int(const string text, int min, int max)
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
long double Eingaben::erfasse_long_double(long double min, long double max)
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
long double Eingaben::erfasse_long_double()
{
  return erfasse_long_double(LDBL_MAX * -1, LDBL_MAX);
}
/**
 * Erfasst eine long double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die long double-Zahl die erfasst wurde.
 */
long double Eingaben::erfasse_long_double(const string text)
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
long double Eingaben::erfasse_long_double(const string text, long double min, long double max)
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
double Eingaben::erfasse_double(double min, double max)
{
  return static_cast<double>(erfasse_double(min, max));
}
/**
 * Erfasst eine double-Zahl.
 * @return Die double-Zahl die erfasst wurde.
 */
double Eingaben::erfasse_double()
{
  return static_cast<double>(erfasse_double(DBL_MAX * -1, DBL_MAX));
}
/**
 * Erfasst eine double-Zahl. Vor der Ausgabe wird eine Beschreibung der Eingabe ausgegeben.
 * @param text      Beschreibung der Eingabe.
 * @return Die double-Zahl die erfasst wurde.
 */
double Eingaben::erfasse_double(const string text)
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
double Eingaben::erfasse_double(const string text, double min, double max)
{
  cout << text;
  return erfasse_double(min, max);
}
/**
 * Erfasst einen bool-Wert.
 * @return Der bool-Wert der erfasst wurde.
 */
bool Eingaben::erfasse_bool()
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
 * Erfasst ein Antwort in einem bestimmten Format und mit einer Eingabeaufforderung die das Format angibt.
 * <br>Das Format muss zwei Zeichen lang sein (z.B. "jn" wenn nach "j" und "n" geprueft werden soll).
 * <br>Bei einer falschen Eingabe wird das richtige, gewuenschte Format noch ein mal ausgegeben.
 *
 * @param ausgabetext     Text für die Frage/Beschreibung der Ausgabe.
 * @param eingabeformat   Das Eingabeformat mit zwei Zeichen, mit dem die Eingabe geprueft werden soll
 *                        (z.B. "jn" wenn nach "j" und "n" geprueft werden soll).
 * @return  Die erfasste Eingabe, Text wird zurueckgegeben.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
string Eingaben::erfasse_antwort(const string ausgabetext, const string eingabeformat)
{
  bool eingabeOK = false;
  stringstream streampuffer;
  string eingabe = "";
  char c;
  try
  {
    while (!eingabeOK)
    {
      cout << endl << ausgabetext << " (" << eingabeformat.at(0) << "/" << eingabeformat.at(1) << ") ";
      streampuffer.str("");
      eingabe = "";
      do
      {
        c = cin.get();
        streampuffer << c;
      } while (c!='\n');
      eingabe = streampuffer.str();
      eingabeformat.length();
      if (eingabe.at(0) == eingabeformat.at(0) || eingabe.at(0) == eingabeformat.at(1))
      {
        eingabeOK = true;
      }
      else
      {
        cout << "Falscher Eingabeformat. Bitte geben Sie die Antwort in der Form "
          << eingabeformat.at(0) << " oder " << eingabeformat.at(1) << " ein. ";
      }
    }
  }
  catch (const out_of_range& exception)
  {
      cerr << endl << exception.what() << " Falsche laenge des Eingabeformats!" << endl << endl;
  }
  return eingabe;
}
/**Erfasst eine Zeichenkette und speichert diese in einem Char-Array.
 * Liest nicht mehr als laenge Zeichen. Stoppt ansonsten vorher schon bei Newline (\n).
 *
 * @param ausgabetext     Text für die Frage/Beschreibung der Ausgabe.
 * @param eingabe         \c Input:  \n Das Array, in das die Zeichenkette geschrieben werden soll.\n
 *                        \c Output: \n Dasselbe Array, in das die Zeichenkette geschrieben wurde.\n
 * @param laenge     Die max. Laenge der Zeichenkette.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Eingaben::erfasse_zeichenkette(const char *ausgabetext, char *eingabe, streamsize laenge)
{
  cout << ausgabetext;
  streamsize alter_wert = cin.width();
  cin.width(laenge);
  cin.get(eingabe, laenge);
  cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
  cin.width(alter_wert);
}
/**
 * Erfasst eine Zeichenkette (Text) einer bestimmten Laenge.
 * @param eingabe   \c Input:  \n Das Array, dessen Komponenten den Text beinhalten sollen.\n
 *                  \c Output: \n Dasselbe Array, dessen Komponenten den Text beinhalten.\n
 * @param laenge    Die max. Laenge der Zeichenkette.
 */
void Eingaben::erfasse_zeichenkette(char *eingabe, streamsize laenge)
{
  erfasse_zeichenkette("", eingabe, laenge);
}