#include "bruchrechner.h"
// weitere Angaben
// Code der Konstruktoren
/**
 * Erzeugt einen leeren Bruchrechner der zwei Brueche und das Ergebnis initialesiert.
 */
Bruchrechner::Bruchrechner()
{
  erster_bruch = Bruch();
  zweiter_bruch = Bruch();
  op = '*';
  ergebnis = Bruch();
}
/**
 * Erzeugt einen Bruchrechner mit zwei Bruechen. Diese werden, abhaengig vom operator, mit einander verrechnet
 * und das Ergebnis wird normiert gespeichert.
 * <br>
 * <br>Der Bruch wird im folgenden Sinne normiert:
 * <br>- Zaehler und Nenner sollen teilerfremd sein.
 * <br>- ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zaehler steht.
 * <br>- wenn Nenner den Wert 1 hat, wird statt Zaehler/Nenner nur Zaehler ausgegeben.
 * <br>- wenn Zaehler und Nenner denselben Wert haben, wird statt Zaehler/Nenner der Wert 1 ausgegeben.
 *
 * @param der_erster_bruch    Der erste Bruch, mit dem gerechnet werden soll.
 * @param der_zweiter_bruch   Der zweite Bruch, mit dem gerechnet werden soll.
 * @param der_operator        Der Operator, der angibt ob +, -, * oder / gerechnet werden soll.
 */
Bruchrechner::Bruchrechner(const Bruch& der_erster_bruch, const Bruch& der_zweiter_bruch, string der_operator)
{
  erster_bruch = der_erster_bruch;
  zweiter_bruch = der_zweiter_bruch;
  bool op_ok = (der_operator.at(0) == '+' || der_operator.at(0) == '-' ||
  der_operator.at(0) == '*' || der_operator.at(0) == '/');
  if (op_ok)
    op = der_operator;
  rechne();
}
// Code der Methoden
/**
 * Schreibt das Ergebnis auf die Konsole (std out).
 */
void Bruchrechner::schreibe_ergebnis()
{
  cout << endl << erster_bruch.liefere_bruch_als_text() << " "
      << op << " "
      << zweiter_bruch.liefere_bruch_als_text()
      << " = " << ergebnis.liefere_bruch_als_text() << endl;
}

/**
 * Berechnet das Ergebnis, abhaengig vom Operator, der angibt ob +, -, * oder / gerechnet werden soll.
 */
void Bruchrechner::rechne()
{
  if (op.at(0) == '+')
     ergebnis = erster_bruch + zweiter_bruch;
  else if (op.at(0) == '-')
    ergebnis = erster_bruch - zweiter_bruch;
  else if (op.at(0) == '*')
    ergebnis = erster_bruch * zweiter_bruch;
  else if (op.at(0) == '/')
    ergebnis = erster_bruch / zweiter_bruch;
  ergebnis.kuerze_bruch();
}
// eventuell Code
// weiterer Funktionen
/**
 * Vergleicht zwei Brueche und gibt den zutreffenden Vergleich aus.
 * <br>Zum Beispiel:
 * <br>a/b < c/d oder
 * <br>a/b = c/d oder
 * <br>a/b > c/d
 * @param der_erster_bruch  Der erste Bruch, der zum Vergleich herangezogen wird
 * @param der_zweiter_bruch Der zweite Bruch, der zum Vergleich herangezogen wird
 */
void vergleiche_zwei_brueche(const Bruch& der_erster_bruch, const Bruch& der_zweiter_bruch)
{
  Bruch erster_bruch = der_erster_bruch;
  Bruch zweiter_bruch = der_zweiter_bruch;
  if (erster_bruch == zweiter_bruch)
  {
    cout << endl << erster_bruch.liefere_bruch_als_text() << " == "
      << zweiter_bruch.liefere_bruch_als_text() << endl;
  }
  else if (erster_bruch < zweiter_bruch)
  {
    cout << endl << erster_bruch.liefere_bruch_als_text() << " < "
      << zweiter_bruch.liefere_bruch_als_text() << endl;
  }
  else if (erster_bruch > zweiter_bruch)
  {
    cout << endl << erster_bruch.liefere_bruch_als_text() << " > "
      << zweiter_bruch.liefere_bruch_als_text() << endl;
  }
}
/**
 * Liefert n zufaellige Brueche, die zwischen einem min. und max. Bruch liegen.
 * Die Brueche werden in einem uebergebenen Array gespeichert.
 * @param min             minimale Groesse des ganzen, zufaelligen Bruches.
 * @param max             maximale Groesse des ganzen, zufaelligen Bruches.
 * @param zufallsbrueche  \c Input:  \n Ein Array, in dem n zufaellige Brueche gespeichert werden sollen.\n
 *                        \c Output: \n Ein Array mit Bruechen, in dem n zufaellige Brueche gespeichert wurden.\n
 * @param anzahl          Die gewuenschte Anzahl (n) zu erzeugende zufaellige Brueche.
 */
void liefere_zufaellige_brueche(const Bruch& min, const Bruch& max, Bruch zufallsbrueche[], int anzahl)
{
  Bruch kleinster_bruch = min;
  Bruch groesster_bruch = max;
  cout << endl << anzahl << " zufaellig gewaehlte Brueche aus dem Bereich von "
    << kleinster_bruch.liefere_bruch_als_text() << " bis " << groesster_bruch.liefere_bruch_als_text() << endl;
  for (int i = 0; i < anzahl; i++)
    zufallsbrueche[i] = Bruch(kleinster_bruch, groesster_bruch);
  cout << endl << "unsortiert:" << endl;
  for (int i = 0; i < anzahl; i++)
    cout << setw(20) << right << zufallsbrueche[i].liefere_bruch_als_text() << endl;
}
/**
 * Sortiert ein Array mit zufaellig erzeugten Bruechen aufsteigend und gibt diese auf der Konsole aus.
 * @param zufallsbrueche      \c Input:  \n Ein Array mit Bruechen, das aufsteigend sortiert und ausgegeben soll.\n
   *                          \c Output: \n Ein Array mit Bruechen, das aufsteigend sortiert und ausgegeben wurde.\n
 * @param anzahl              Die Anzahl der Bruechen.
 */
void schreibe_zufaellige_brueche_aufsteigend(Bruch zufallsbrueche[], int anzahl)
{
  sortiere_aufsteigend(zufallsbrueche, anzahl);
  cout << endl << "absteigend sortiert:" << endl;
  for (int i = 0; i < anzahl; i++)
    cout << setw(20) << right << zufallsbrueche[i].liefere_bruch_als_text() << endl;
}
/**
 * Sortiert ein Array mit zufaellig erzeugten Bruechen absteigend und gibt diese auf der Konsole aus.
 * @param zufallsbrueche      \c Input:  \n Ein Array mit Bruechen, das aufsteigend sortiert und ausgegeben soll.\n
   *                          \c Output: \n Ein Array mit Bruechen, das aufsteigend sortiert und ausgegeben wurde.\n
 * @param anzahl              Die Anzahl der Bruechen.
 */
void schreibe_zufaellige_brueche_absteigend(Bruch zufallsbrueche[], int anzahl)
{
  sortiere_absteigend(zufallsbrueche, anzahl);
  cout << endl << "aufsteigend sortiert:" << endl;
  for (int i = 0; i < anzahl; i++)
    cout << setw(20) << right << zufallsbrueche[i].liefere_bruch_als_text() << endl;
}