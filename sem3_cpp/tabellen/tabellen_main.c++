#include <cmath>
#include <cstdlib>

#include "ausgaben.h"
#include "eingaben.h"
#include "rechner.h"
#include "menue.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
void program_starten(int argc, char **argv);
void program_ohne_menue(int argc, char **argv);
void program_mit_menue();
void schreibe_anleitung();

/**
 * Der einstigespunkt des Programs.
 * Das Programm gibt die Wertetabellen für die
 * Funktionen cos, sin, tan, acos, asin, atan, exp, log, log10, pow und sqrt aus
 * cmath auf dem Bildschirm aus. Es kann Folgendes leisten:
 *<br>
 * <br>Wird das Programm in der Form
 *<br>
 * <br>tabelle
 * <br>
 * <br>aufgerufen, erscheint ein Menü, aus dem gewählt werden kann, für welche der oben genannten
 * Funktionen die Wertetabelle erzeugt werden soll.
 * <br>
 * <br>Nach Wahl der Funktion werden durch Eingabe über die Tastatur alle Werte erfasst, die
 * notwendig sind, um für diese Funktion die Wertetabelle erstellen und ausgeben zu können
 * (Anfangswert, Endwert, gewünschte Anzahl der Nachkommastellen, etc.).
 * <br>
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
 * <br>
 * <br>Das Programm kann auch in der Form
 * <br>
 * <br>tabelle arg1 arg2 ... argn
 * <br>
 * <br>aufgerufen werden. Hierbei sind arg1 der Name der Funktion und arg2, ... argn die
 * <br>benötigten zusätzlichen Informationen (Anfangswert, Endwert, gewünschte Anzahl der Nachkommastellen, etc.).
 * <br>
 * <br>Wird das Programm falsch aufgerufen, wird ein Hilfetext erscheinen.
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Gibt 0 fuer richtige ausfuerung und andere Werte fuer abbruch/fehler.
 */
int main(int argc, char **argv)
{
  if (parameter_ok(argc, argv))
  {
    program_starten(argc, argv);
  }
  else
    schreibe_anleitung();
}
/**
 * Prueft die Parameter auf richtigkeit.
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Ob die Parameter richtig eingegeben wurden oder nicht.
 */
bool parameter_ok(int argc, char *argv[])
{
	bool parameter_ok = false;
	if (argc == 6)
	{
		string name = argv[1];
		if (name == "cos")
			parameter_ok = true;
		else if (name == "sin")
			parameter_ok = true;
		else if (name == "tan")
			parameter_ok = true;
		else if (name == "acos")
			parameter_ok = true;
		else if (name == "asin")
			parameter_ok = true;
		else if (name == "atan")
			parameter_ok = true;
		else if (name == "exp")
			parameter_ok = true;
		else if (name == "log")
			parameter_ok = true;
		else if (name == "log10")
			parameter_ok = true;
		else if (name == "sqrt")
                    if (atof(argv[2]) > 0)
			parameter_ok = true;

	} else if (argc == 7)
	{
		string name = argv[1];
		if (name == "pow")
			parameter_ok = true;
	} else if (argc == 1)
		parameter_ok = true;
	return parameter_ok;
}
/**
 * Startet das Program ohne Benutzerinteraktionen und nur mit uebergebenen Parameter oder mit Benutzerinteraktionen wenn keine Parameter uebergeben wurden.
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 */
void program_starten(int argc, char **argv)
{
  if (argc == 1)
    program_mit_menue();
  else
    program_ohne_menue(argc, argv);
}
/**
 * Startet das Program ohne Benutzerinteraktionen und nur mit uebergebenen Parameter.
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 */
void program_ohne_menue(int argc, char **argv)
{
  string name = argv[1];
  long double (*stdfuncmath1[])(long double)= {cos, sin, tan, acos, asin, atan, exp, log, log10, sqrt};
  long double (*stdfuncmath2[])(long double, long double)= {pow};
  if (argc == 6)
	{
		if (name == "cos")
			rechner(stdfuncmath1[0], argv);
		else if (name == "sin")
			rechner(stdfuncmath1[1], argv);
		else if (name == "tan")
			rechner(stdfuncmath1[2], argv);
		else if (name == "acos")
			rechner(stdfuncmath1[3], argv);
		else if (name == "asin")
			rechner(stdfuncmath1[4], argv);
		else if (name == "atan")
			rechner(stdfuncmath1[5], argv);
		else if (name == "exp")
			rechner(stdfuncmath1[6], argv);
		else if (name == "log")
			rechner(stdfuncmath1[7], argv);
		else if (name == "log10")
			rechner(stdfuncmath1[8], argv);
		else if (name == "sqrt")
			rechner(stdfuncmath1[9], argv);
	}
  else if(argc == 7)
	{
		if (name == "pow")
			rechner(stdfuncmath2[0], argv);
	}
  //delete [] stdfuncmath1;
  //stdfuncmath1 = 0;
  //delete [] stdfuncmath2;
  //stdfuncmath2 = 0;
}
/**
 * Startet das Program mit Benutzerinteraktionen.
 */
void program_mit_menue()
{
  long double (*stdfuncmath1[])(long double)= {cos, sin, tan, acos, asin, atan, exp, log, log10, sqrt};
  long double (*stdfuncmath2[])(long double, long double)= {pow};

  string menue[12] = {"cos", "sin", "tan", "acos", "asin", "atan", "exp", "log", "log10", "pow", "sqrt", "Beenden"};
  bool antwort = false;
  do
  {
    switch(waehle_aus_menue(12, menue))
    {
    case 1:
     rechner(stdfuncmath1[0], "cos");
     break;
    case 2:
     rechner(stdfuncmath1[1], "sin");
     break;
    case 3:
     rechner(stdfuncmath1[2], "tan");
     break;
    case 4:
     rechner(stdfuncmath1[3], "acos");
     break;
    case 5:
     rechner(stdfuncmath1[4], "asin");
     break;
    case 6:
     rechner(stdfuncmath1[5], "atan");
     break;
    case 7:
     rechner(stdfuncmath1[6], "exp");
     break;
    case 8:
     rechner(stdfuncmath1[7], "log");
     break;
    case 9:
     rechner(stdfuncmath1[8], "log10");
     break;
    case 10:
     rechner(stdfuncmath2[0], "pow");
     break;
    case 11:
     rechner(stdfuncmath1[9], "sqrt");
     break;
    default:
     cout << "\nDas Programm wird beendet. See You!\n";
     antwort = true;
     break;
    }
  } while (antwort == false);
  //delete [] stdfuncmath1;
  //stdfuncmath1 = 0;
  //delete [] stdfuncmath2;
  //stdfuncmath2 = 0;
  //delete [] menue;
  //menue = 0;
}
/**
 * Schreibt eine Anleitung zum Program.
 */
void schreibe_anleitung()
{
  cout << "\nDas Program wurde mit falschen oder nicht genuegenden Parameter aufgerufen.\n"
          << "\nAnleitung:\n"
          << "Das Programm muss mit 0, 5 oder 6 Parameter gestartet werden:\n"
          << "\nWird das Programm in der Form\n"
          << "\n"
          << "\ntabelle"
          << "\n"
          << "\naufgerufen, erscheint ein Menü, aus dem gewählt werden kann, für welche der oben genannten Funktionen die Wertetabelle erzeugt werden soll."
          << "\n"
          << "\nNach Wahl der Funktion werden durch Eingabe über die Tastatur alle Werte erfasst, die "
          << "notwendig sind, um für diese Funktion die Wertetabelle erstellen und ausgeben zu können "
          << "(Anfangswert, Endwert, gewünschte Anzahl der Nachkommastellen, etc.)."
          << "\n\n"
          << "\nDas Programm kann auch in der Form"
          << "\n"
          << "\ntabelle arg1 arg2 ... argn"
          << "\n"
          << "\naufgerufen werden. Hierbei sind arg1 der Name der Funktion und arg2, ... argn die "
          << "benötigten zusätzlichen Informationen (Anfangswert, Endwert, gewünschte Anzahl der Nachkommastellen, etc.).\n"
          << "\narg2: Der Startwert."
          << "\narg3: Die Anzahl der Folgewerte."
          << "\narg4: Der Abstand zwischen den Werten."
          << "\narg5: Die Praezision, mit der die Ausgabe gemacht werden soll.\n"
          << "\nBeispiele 1:\n"
          << "\n"
          << "\ntabelle 5 8 0.1 2"
          << "\n"
          << "\nFuer die Potenz-Funktion wird noch ein weiterer Argument benoetigt, der Exponent. "
          << "Dabei ist dieser als arg2 zu uebergeben (der rest rueckt nach).\n"
          << "\nBeispiele 2:\n"
          << "\n"
          << "\ntabelle 5 2 8 0.1 2"
          << "\n";
}

