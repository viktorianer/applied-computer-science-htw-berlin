#include "konto.h"
// weitere Angaben
// Code der Konstruktoren
/**
 * Erzeugt ein Konto mit der Kontonummer 000000, dem Kontostand 0.0 Euro und Ueberweisungskredit von 0.0 Euro.
 */
Konto::Konto()
{
  kontonummer = 000000;
  kontostand = 0.0;
  ueberweisungskredit = 0.0;
}
/**
 * Erzeugt Konten mit zufälligem Kontostand und Überziehungskredit.
 * <br>
 * <br>Jedes Konto hat (der Einfachheit halber nur) eine eindeutige Kontonummer, die aus sechs Ziffern
 * besteht, einen Kontostand und einen Überziehungskredit, der von Konto zu Konto unterschiedlich
 * sein sollte.
 * <br>
 * <br>Der Kontostand liegt im Bereich von 0,01 Euro bis 100000,00 Euro.
 * <br>Der Überziehungskredit liegt im Bereich von 100,00 Euro bis 5000,00 Euro.
 *
 * @param eine_kontonummer  Eine eindeutige Kontonummer, die aus sechs Ziffern besteht.
 */
Konto::Konto(int eine_kontonummer)
{
  if (100000 <= eine_kontonummer && eine_kontonummer <= 999999)
    kontonummer = eine_kontonummer;
  kontostand = liefere_zufaelligen_kontostand();
  ueberweisungskredit = liefere_zufaelligen_ueberweisungskredit();
}
// Code der Methoden
/**
 * Liefert die Kontonummer des Kontos.
 * @return Die Kontonummer des Kontos.
 */
int Konto::liefere_kontonummer() const
{
  return kontonummer;
}
/**
 * Liefert den Kontostand (Euro) des Kontos.
 * @return Den Kontostand (Euro) des Kontos.
 */
double Konto::liefere_kontostand() const
{
  return kontostand;
}
/**
 * Zahlt eine Geldsumme auf das Konto ein.
 * @param geldsumme Die Geldsumme die auf das Konto eingezahlt werden soll.
 */
void Konto::einzahlung(double geldsumme)
{
  if (0.0 < geldsumme)
    kontostand += geldsumme;
}
/**
 * Hebt eine Geldsumme vom Konto ab.
 * <br> Die Geldsumme darf die Summe von Kontostand und Ueberweisungskredit nicht uebersteigen
 * @param geldsumme Die Geldsumme, die vom Konto abgehoben werden soll.
 * @return  Liefert die Geldsumme, die vom Konto abgehoben wurde.
 */
double Konto::auszahlung(double geldsumme)
{
  if (pruefe_kreditrahmen(geldsumme))
    kontostand -= geldsumme;
  return geldsumme;
}
/**
 * Liefert den Ueberweisungskredit, deshalb bis welche Summe das Konto ueberzogen werden darf.
 * @return Den Ueberweisungskredit fuer dieses Konto.
 */
double Konto::liefere_ueberweisungskredit() const
{
  return ueberweisungskredit;
}
/**
 * Prueft, ob die Geldsumme im Kreditrahmen (die Summe von Kontostand und Ueberweisungskredit) liegt.
 * @param geldssumme  Die Geldsumme, die geprueft werden soll.
 * @return  Ob die Geldsumme im Kreditrahmen (true) liegt oder nicht (false).
 */
bool Konto::pruefe_kreditrahmen(double geldssumme) const
{
  bool ueberweisung_moeglich = false;
  if ( geldssumme < (kontostand + ueberweisungskredit))
    ueberweisung_moeglich = true;
  return ueberweisung_moeglich;
}

/**
 * Liefert fuer das Konto einen zufaelligen Kontostand.
 * <br>Der Kontostand liegt im Bereich von 0,01 Euro bis 100000,00 Euro.
 * @return Einen Kontostand im Bereich von 0,01 Euro bis 100000,00 Euro.
 */
double Konto::liefere_zufaelligen_kontostand()
{
  return Zufallsgenerator::liefere_zufallsgenerator().liefere_gleitkomma_zufallszahl(0.01, 100000.00);
}
/**
 * Liefert fuer das Konto einen zufaelligen Ueberweisungskredit.
 * <br>Der Überziehungskredit liegt im Bereich von 100,00 Euro bis 5000,00 Euro.
 * @return Einen Überziehungskredit im Bereich von 100,00 Euro bis 5000,00 Euro.
 */
double Konto::liefere_zufaelligen_ueberweisungskredit()
{
  return Zufallsgenerator::liefere_zufallsgenerator().liefere_gleitkomma_zufallszahl(100.00, 5000.00);
}
// eventuell Code
// weiterer Funktionen
