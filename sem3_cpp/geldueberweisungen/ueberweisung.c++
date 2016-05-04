#include "ueberweisung.h"
// weitere Angaben
// Code der Konstruktoren
/**
 * Erzeugt eine Ueberweisung von einem leeren Quellkonto auf ein Zielkonto mit einem Volumen von 0.0 Euro.
 */
Ueberweisung::Ueberweisung()
{
  Konto konto = Konto();
  quellkonto = &konto;
  zielkonto = &konto;
  volumen = 0.0;
}
/**
 * Erzeugt eine simulierte, zufällige Ueberweisung von einem Quellkonto auf ein Zielkonto.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 * wird (Überziehungskredit berücksichtigen).
 *
 * @param das_quellkonto  Das Konto, von dem das Geld kommt.
 * @param das_zielkonto   Das Konto, auf das das Geld ueberwiesen wird.
 */
Ueberweisung::Ueberweisung(Konto *das_quellkonto, Konto *das_zielkonto)
{
  quellkonto = das_quellkonto;
  zielkonto = das_zielkonto;
  simuliere_ueberweisung();
}
// Code der Methoden
/**
 * Liefert das Volumen der Ueberweisung (Euro).
 * @return Das Volumen der Ueberweisung (Euro).
 */
double Ueberweisung::liefere_ueberweisungsvolumen() const
{
  return volumen;
}
/**
 * Liefert die Beschreibung zur der Ueberweisung.
 * <br>Es wird die Kontonummer des Quellkontos, die Ueberweisungsrichtung und die Kontonummer des Zielkontos geliefert.
 * @return  Die Kontonummer des Quellkontos, die Ueberweisungsrichtung und die Kontonummer des Zielkontos.
 */
string Ueberweisung::liefere_ueberweisungsinfo() const
{
  stringstream streampuffer;
  string info = "";
  streampuffer << quellkonto->liefere_kontonummer() << " ---> " << zielkonto->liefere_kontonummer();
  info = streampuffer.str();
  return info;
}
/**
 * Simuliert eine zufällige Ueberweisung von einem Quellkonto auf ein Zielkonto.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 * wird (Überziehungskredit berücksichtigen).
 */
void Ueberweisung::simuliere_ueberweisung()
{
  double maximaler_ueberweisungsbetrag = quellkonto->liefere_ueberweisungskredit() + quellkonto->liefere_kontostand();
  volumen = Zufallsgenerator::liefere_zufallsgenerator().liefere_gleitkomma_zufallszahl(0.01, maximaler_ueberweisungsbetrag);
  zielkonto->einzahlung(quellkonto->auszahlung(volumen));
}
// eventuell Code
// weiterer Funktionen
