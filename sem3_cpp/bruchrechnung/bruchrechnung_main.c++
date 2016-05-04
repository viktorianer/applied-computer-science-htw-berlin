#include <climits>
#include <string>
#include <cstdlib>

#include "bruchrechner.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
bool bruch_ok(int zaehler, int nenner);
bool operator_ok(const string der_operator);
bool vergleichsoperator_ok(const string der_vergleichsoperator);
bool sortieroperator_ok(const string der_sortieroperator);
void program_starten(int argc, char **argv);
void schreibe_anleitung();

/**Ein Programm, das Rechnen mit ganzzahligen Bruechen ermoeglicht.
 * <br>Die Benutzer und Benutzerinnen können ueber die Parameter zwei ganzzahlige Brueche in exakt der Form
 * a/b op c/d eingeben. Dabei ist darauf zu achten, dass der Nenner nie 0 sein darf.
 * <br>Auf dem Bildschirm wird danch ausgegeben:
 * <br>a/b op c/d = e/f
 * <br>Hierbei steht op für einen der Operatoren +, -, *, /.
 * <br>Die Buchstaben a-d stehen fuer eine beliebige ganze Zahl. Der Nenner darf nicht den Wert 0 haben!<br>
 * <br>Weitere Beispiele:
 * <br>bruch a op c d fuert zu der Ausgabe: a op c/d = e/f
 * <br>bruch a b op c fuert zu der Ausgabe: a/b op c = e/f
 * <br>
 * <br>Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
 * aber immer im folgenden Sinn normiert:
 * <br>- e und f sollen teilerfremd sein.
 * <br>- ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
 * <br>- wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
 * <br>- wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
 * <br>
 * <br>Wird das Programm in der Form
 * <br>bruchrechner a b -v c d"
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>a/b < c/d oder
 * <br>a/b = c/d oder
 * <br>a/b > c/d<br>"
 * <br>Wird das Programm in der Form
 * <br>bruchrechner n [ a b c d ] +
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>n zufaellig gewaehlte Brueche aus dem Bereich von a/b bis c/d
 * <br>+ steht fuer aufsteigend sortiert
 * <br>- steht fuer absteigend sortiert
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * 
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
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
 * Prueft die Parameter auf richtigkeit. Der Benutzer darf nur folgende Formen von Parameter uebergeben.
 * <br>
 * <br>Die Benutzer und Benutzerinnen können ueber die Parameter zwei ganzzahlige Brueche in exakt der Form
 * a/b op c/d eingeben. Dabei ist darauf zu achten, dass der Nenner nie 0 sein darf.
 * <br>Auf dem Bildschirm wird danch ausgegeben:
 * <br>a/b op c/d = e/f
 * <br>Hierbei steht op für einen der Operatoren +, -, *, /.
 * <br>Die Buchstaben a-d stehen fuer eine beliebige ganze Zahl. Der Nenner darf nicht den Wert 0 haben!<br>
 * <br>Weitere Beispiele:
 * <br>bruch a op c d fuert zu der Ausgabe: a op c/d = e/f
 * <br>bruch a b op c fuert zu der Ausgabe: a/b op c = e/f
 * <br>
 * <br>Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
 * aber immer im folgenden Sinn normiert:
 * <br>- e und f sollen teilerfremd sein.
 * <br>- ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
 * <br>- wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
 * <br>- wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
 * <br>
 * <br>Wird das Programm in der Form
 * <br>bruchrechner a b -v c d"
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>a/b < c/d oder
 * <br>a/b = c/d oder
 * <br>a/b > c/d<br>"
 * <br>Wird das Programm in der Form
 * <br>bruchrechner n [ a b c d ] +
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>n zufaellig gewaehlte Brueche aus dem Bereich von a/b bis c/d
 * <br>+ steht fuer aufsteigend sortiert
 * <br>- steht fuer absteigend sortiert";
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Ob die Parameter richtig eingegeben wurden (true) oder nicht (false).
 */
bool parameter_ok(int argc, char *argv[])
{
	bool parameter_ok = false;
	if (argc == 6)
	{
    if (vergleichsoperator_ok(argv[3]))
    {
      parameter_ok = bruch_ok(atoi(argv[1]), atoi(argv[2])) && bruch_ok(atoi(argv[4]), atoi(argv[5]));
    }
    else if(operator_ok(argv[3]))
    {
      parameter_ok = bruch_ok(atoi(argv[1]), atoi(argv[2])) &&
                    operator_ok(argv[3]) && bruch_ok(atoi(argv[4]), atoi(argv[5]));
    }
  }
  else if (argc == 5)
  {
    if (operator_ok(argv[2]))
    {
      parameter_ok = bruch_ok(atoi(argv[1]), 1) && bruch_ok(atoi(argv[3]), atoi(argv[4]));
    }
    else if (operator_ok(argv[3]))
    {
      parameter_ok = bruch_ok(atoi(argv[1]), atoi(argv[2])) && bruch_ok(atoi(argv[4]), 1);
    }
  }
  else if (argc == 9)
  {
    int anzahl = atoi(argv[1]);
    parameter_ok = (1 <= anzahl && anzahl <= 10000) &&
      bruch_ok(atoi(argv[3]), atoi(argv[4])) && bruch_ok(atoi(argv[5]), atoi(argv[6])) &&
      sortieroperator_ok(argv[8]);
  }
	return parameter_ok;
}
/**
 * Prueft, ob der Bruch im Nenner keine 0 enthaelt und ob die Zahlen im passenden (int) Bereich liegen.
 * @param zaehler Der Zaehler des Bruches.
 * @param nenner  Der Nenner des Bruches.
 * @return Liefert true wenn der Bruch i.O. ist und false wenn nicht.
 */
bool bruch_ok(int zaehler, int nenner)
{
  return  INT_MIN <= zaehler && zaehler <= INT_MAX &&
          nenner != 0 && (INT_MIN <= nenner && nenner <= INT_MAX) ;
}
/**
 * Prueft die Eingabe auf richtigen Operator (+, -, *, /)
 * @param der_operator  Ein uebergebene Operator, der geprueft werden soll.
 * @return  Liefert true wenn der Operator i.O. ist und fals wenn nicht.
 */
bool operator_ok(const string der_operator)
{
  return (der_operator.at(0) == '+' || der_operator.at(0) == '-' ||
                    der_operator.at(0) == '*' || der_operator.at(0) == '/');
}
/**
 * Prueft die Eingabe auf richtigen Vergleichsoperator (-v).
 * @param der_vergleichsoperator  Der Vergleichsoperator, der ueberprueft werden soll.
 * @return Liefert true wenn der Vergleichsoperator i.O. ist und fals wenn nicht.
 */
bool vergleichsoperator_ok(const string der_vergleichsoperator)
{
  return (!(der_vergleichsoperator.compare("-v")));
}
/**
 * Prueft die Eingabe auf richtigen Sortieroperator (+, -).
 * @param der_sortieroperator Der Sortieroperator, der ueberprueft werden soll.
 * @return Liefert true wenn der Sortieroperator i.O. ist und fals wenn nicht.
 */
bool sortieroperator_ok(const string der_sortieroperator)
{
  return (der_sortieroperator.at(0) == '+' || der_sortieroperator.at(0) == '-');
}
/**
 * Startet das Program ohne Benutzerinteraktionen und nur mit uebergebenen Parameter.
 * <br>Die Benutzer und Benutzerinnen können ueber die Parameter zwei ganzzahlige Brueche in exakt der Form
 * a/b op c/d eingeben. Dabei ist darauf zu achten, dass der Nenner nie 0 sein darf.
 * <br>Auf dem Bildschirm wird danch ausgegeben:
 * <br>a/b op c/d = e/f
 * <br>Hierbei steht op für einen der Operatoren +, -, *, /.
 * <br>Die Buchstaben a-d stehen fuer eine beliebige ganze Zahl. Der Nenner darf nicht den Wert 0 haben!<br>
 * <br>Weitere Beispiele:
 * <br>bruch a op c d fuert zu der Ausgabe: a op c/d = e/f
 * <br>bruch a b op c fuert zu der Ausgabe: a/b op c = e/f
 * <br>
 * <br>Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
 * aber immer im folgenden Sinn normiert:
 * <br>- e und f sollen teilerfremd sein.
 * <br>- ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
 * <br>- wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
 * <br>- wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
 * <br>
 * <br>Wird das Programm in der Form
 * <br>bruchrechner a b -v c d"
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>a/b < c/d oder
 * <br>a/b = c/d oder
 * <br>a/b > c/d<br>"
 * <br>Wird das Programm in der Form
 * <br>bruchrechner n [ a b c d ] +
 * <br>aufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):
 * <br>n zufaellig gewaehlte Brueche aus dem Bereich von a/b bis c/d
 * <br>+ steht fuer aufsteigend sortiert
 * <br>- steht fuer absteigend sortiert
 * 
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 */
void program_starten(int argc, char **argv)
{
  Bruchrechner bruchrechner;
  if (argc == 6)
  {
    if (vergleichsoperator_ok(argv[3]))
    {
      Bruch erster_bruch = Bruch(atoi(argv[1]), atoi(argv[2]));
      Bruch zweiter_bruch = Bruch(atoi(argv[4]), atoi(argv[5]));
      vergleiche_zwei_brueche(erster_bruch, zweiter_bruch);
    }
    else if (operator_ok(argv[3]))
    {
      bruchrechner = Bruchrechner(Bruch(atoi(argv[1]), atoi(argv[2])),
        Bruch(atoi(argv[4]), atoi(argv[5])), argv[3]);
      bruchrechner.schreibe_ergebnis();
    }
  }
  else if (argc == 5)
  {
    if (operator_ok(argv[2]))
    {
      bruchrechner = Bruchrechner(Bruch(atoi(argv[1]), 1),
        Bruch(atoi(argv[3]), atoi(argv[4])), argv[2]);
      bruchrechner.schreibe_ergebnis();
    }
    else if (operator_ok(argv[3]))
    {
      bruchrechner = Bruchrechner(Bruch(atoi(argv[1]), atoi(argv[2])),
        Bruch(atoi(argv[4]), 1), argv[3]);
      bruchrechner.schreibe_ergebnis();
    }
  }
  else if (argc == 9)
  {
    int anzahl = atoi(argv[1]);
    Bruch erster_bruch = Bruch(atoi(argv[3]), atoi(argv[4]));
    Bruch zweiter_bruch = Bruch(atoi(argv[5]), atoi(argv[6]));
    Bruch *zufallsbrueche = new Bruch[anzahl];
    liefere_zufaellige_brueche(erster_bruch, zweiter_bruch, zufallsbrueche, anzahl);
    string der_sortieroperator = argv[8];
    if (der_sortieroperator.at(0) == '+')
      schreibe_zufaellige_brueche_aufsteigend(zufallsbrueche, anzahl);
    else
      schreibe_zufaellige_brueche_absteigend(zufallsbrueche, anzahl);
    delete [] zufallsbrueche;
    zufallsbrueche = 0;
  }
}

/**
 * Wenn der Parameter beim Aufruf des Programms nicht die gewünschte Gestalt hat (Wertebereich
 * falsch, Parameter falsch, Parameter fehlt, etc.), gibt das Programm einen Hinweis auf die
 * korrekte Benutzung aus.
 */
void schreibe_anleitung()
{
  cout << "\nDas Program wurde mit falschen oder nicht genuegenden Parameter aufgerufen.\n"
          << "\nAnleitung:\n"
          << "Das Programm muss mit bestimmten Parameter gestartet werden:\n"
          << "Wird das Programm in der Form\n"
          << " bruchrechner a b op c d"
          << "\naufgerufen, erscheint auf dem Bildschirm:"
          << "\n a/b op c/d = e/f"
          << "\nHierbei steht op für einen der Operatoren +, -, *, /."
          << "\nDie Buchstaben a-d stehen fuer eine beliebige ganze Zahl. Der Nenner darf nicht den Wert 0 haben!\n"
          << "\nWeitere Beispiele:"
          << "\n bruch a op c d fuert zu Ausgabe: a op c/d = e/f"
          << "\n bruch a b op c fuert zu Ausgabe: a/b op c = e/f\n"
          << "\nWird das Programm in der Form"
          << "\n bruchrechner a b -v c d"
          << "\naufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):"
          << "\n a/b < c/d oder\n a/b = c/d oder\n a/b > c/d\n"
          << "\nWird das Programm in der Form"
          << "\n bruchrechner n [ a b c d ] +"
          << "\naufgerufen, erscheint auf dem Bildschirm (in Abhängigkeit davon, was zutrifft):"
          << "\n n zufaellig gewaehlte Brueche aus dem Bereich von a/b bis c/d"
          << "\n + steht fuer aufsteigend sortiert"
          << "\n - steht fuer absteigend sortiert\n\n";
}