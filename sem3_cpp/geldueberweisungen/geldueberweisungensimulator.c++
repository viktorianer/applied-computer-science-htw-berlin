#include "geldueberweisungensimulator.h"
// weitere Angaben
// Code der Konstruktoren
/**
 * Erzeugt einen Simulator der Geldüberweisungen wie folgt simuliert:
 * <br>
 * <br>Es werden Geldüberweisungen zwischen n Konten simuliert.
 * <br>Die Zahl n kann dem Programm beim Start als Parameter übergeben werden (1 <= n <= 1000).
 * <br>
 * <br>Wenn der Parameter beim Aufruf des Programms nicht die gewünschte Gestalt hat (Wertebereich
 * falsch, Parameter falsch, Parameter fehlt, etc.), gibt das Programm einen Hinweis auf die
 * korrekte Benutzung aus.
 * <br>
 * <br>Jedes Konto hat (der Einfachheit halber nur) eine eindeutige Kontonummer, die aus sechs Ziffern
 * besteht, einen Kontostand und einen Überziehungskredit, der von Konto zu Konto unterschiedlich
 * sein sollte.
 * <br>
 * <br>Zu Beginn der Simulation werden die n Konten mit zufälligem Kontostand und Überziehungskredit erzeugt.
 * <br>
 * <br>Der Kontostand liegt im Bereich von 0,01 Euro bis 100000,00 Euro.
 * <br>Der Überziehungskredit liegt im Bereich von 100,00 Euro bis 5000,00 Euro.
 * <br>
 * <br>Danach werden die Überweisungen eines Tages wie folgt simuliert.
 * <br>Es finden m Überweisungen statt, wobei m jeweils aus dem Bereich von 7 * n bis 12 * n
 * zufällig gewählt wird. Der Einfachheit halber nehmen wir an, dass die Überweisungen nacheinander erfolgen.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- beide betroffenen Konten gehören zu den n erzeugten Konten
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 * wird (Überziehungskredit berücksichtigen)
 * <br>- der überwiesene Betrag wird vom Startkonto abgebucht und dem Zielkonto gutgeschrieben.
 * <br>
 * <br>Als Ergebnis der Simulation eines Tages werden auf der Konsole folgende Informationen ausgegeben:
 * <br>Tag, Gesamtbestand, hoechster Kontostand, niedrigster Kontostand.
 * <br>Ueberweisungen:  Anzahl, Gesamtvolumen, groesste Ueberweisung, kleinste Ueberweisung, Durchschnitt aller.
 *
 * @param anzahl_konten Die Anzahl der Konten, die fuer die Simulation erzeugt werden sollen.
 */
Geldueberweisungensimulator::Geldueberweisungensimulator(int anzahl_konten)
{
  int kontonummer = 100000;
  if (2 <= anzahl_konten && anzahl_konten <= 1000)
  {
    konten = new Konto[anzahl_konten];
    for (int i = 0; i < anzahl_konten; i++, kontonummer++)
      konten[i] = Konto(kontonummer);
    kontenanzahl = anzahl_konten;
  }
  ueberweisungenanzahl = 0;
  ueberweisungen = new Ueberweisung[ueberweisungenanzahl];
  anzahl_sim_tage = 0;
}
// Code der Methoden
/**
 * Die Überweisungen eines Tages werden wie folgt simuliert.
 * <br>Es finden m Überweisungen statt, wobei m jeweils aus dem Bereich von 7 * n bis 12 * n
 * zufällig gewählt wird. Der Einfachheit halber nehmen wir an, dass die Überweisungen nacheinander erfolgen.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- beide betroffenen Konten gehören zu den n erzeugten Konten
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 * wird (Überziehungskredit berücksichtigen)
 * <br>- der überwiesene Betrag wird vom Startkonto abgebucht und dem Zielkonto gutgeschrieben.
 * <br>
 * <br>Als Ergebnis der Simulation eines Tages werden auf der Konsole folgende Informationen ausgegeben:
 * <br>Tag, Gesamtbestand, hoechster Kontostand, niedrigster Kontostand.
 * <br>Ueberweisungen:  Anzahl, Gesamtvolumen, groesste Ueberweisung, kleinste Ueberweisung, Durchschnitt aller.
 * <br>
 * <br>Danach ist es möglich, einen weiteren Tag zu simulieren oder das Programm zu beenden.
 */
void Geldueberweisungensimulator::simuliere_ueberweisungen_fuer_ein_tag()
{
  anzahl_sim_tage++;
  cout << endl << "Tag " << anzahl_sim_tage << endl;
  schreibe_kontenuebersicht();
  simuliere_ueberweisungen();
  schreibe_ueberweisungenuebersicht();
  schreibe_kontenuebersicht();
}
/**
 * Liefert die Information zum Gesamtbestand (Euro) aller Konten.
 * @return Die Information zum Gesamtbestand (Euro) aller Konten.
 */
double Geldueberweisungensimulator::liefere_gesamtbestand() const
{
  double gesamtsumme = 0;
  for (int i = 0; i < kontenanzahl; i++)
   gesamtsumme += konten[i].liefere_kontostand();
  return gesamtsumme;
}
/**
 * Liefert die Information zur Anzahl der Ueberweisungen.
 * @return Die Information zur Anzahl der Ueberweisungen.
 */
int Geldueberweisungensimulator::liefere_anzahl_ueberweisungen() const
{
  return ueberweisungenanzahl;
}
/**
 * Liefert die Information zum Gesamtvolumen (Euro) aller Ueberweisungen.
 * @return Die Information zum Gesamtvolumen (Euro) aller Ueberweisungen.
 */
double Geldueberweisungensimulator::liefere_gesamtvolumen() const
{
  double gesamtsumme = 0;
  for (int i = 0; i < ueberweisungenanzahl; i++)
    gesamtsumme += ueberweisungen[i].liefere_ueberweisungsvolumen();
  return gesamtsumme;
}
/**
 * Liefert die Information zum Durchschnitt (Euro) aller Ueberweisungen.
 * @return Die Information zum Durchschnitt (Euro) aller Ueberweisungen.
 */
double Geldueberweisungensimulator::liefere_ueberweisungen_durchschnitt() const
{
  return liefere_gesamtvolumen() / ueberweisungenanzahl;
}

/**
 * Die Überweisungen eines Tages werden wie folgt simuliert.
 * <br>Es finden m Überweisungen statt, wobei m jeweils aus dem Bereich von 7 * n bis 12 * n
 * zufällig gewählt wird. Der Einfachheit halber nehmen wir an, dass die Überweisungen nacheinander erfolgen.
 * <br>
 * <br>Jede Überweisung wird zufällig generiert, wobei Folgendes zu beachten ist:
 * <br>- beide betroffenen Konten gehören zu den n erzeugten Konten
 * <br>- eine Überweisung ist von einem Konto nur dann möglich, wenn es dadurch nicht überzogen
 */
void Geldueberweisungensimulator::simuliere_ueberweisungen()
{
  ueberweisungenanzahl = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(7 * kontenanzahl, 12 * kontenanzahl);
  delete [] ueberweisungen;
  ueberweisungen = new Ueberweisung[ueberweisungenanzahl];
  for (int i = 0; i < ueberweisungenanzahl; i++)
  {
    int quellkonto = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, kontenanzahl);
    int zielkonto = 0;
    do
    {
      zielkonto = Zufallsgenerator::liefere_zufallsgenerator().liefere_ganze_zufallszahl(1, kontenanzahl);
    } while (quellkonto == zielkonto);
    if (0.02 < konten[quellkonto - 1].liefere_kontostand() + konten[quellkonto - 1].liefere_ueberweisungskredit())
      ueberweisungen[i] = Ueberweisung(&konten[quellkonto - 1], &konten[zielkonto - 1]);
    else
      i--;
  }
}

/**
 * Liefert das Konto mit den hoechstem Kontostand.
 * @return  Das Konto mit den hoechstem Kontostand.
 */
Konto *Geldueberweisungensimulator::liefere_hoechsten_kontostand() const
{
  Konto *konto_mit_dem_hoechsten_kontostand = &konten[0];
  for (int i = 0; i < kontenanzahl; i++)
    if (konten[i].liefere_kontostand() > konto_mit_dem_hoechsten_kontostand->liefere_kontostand())
      konto_mit_dem_hoechsten_kontostand = &konten[i];
  return konto_mit_dem_hoechsten_kontostand;
}
/**
 * Liefert das Konto mit den niedrigstem Kontostand.
 * @return  Das Konto mit den niedrigstem Kontostand.
 */
Konto *Geldueberweisungensimulator::liefere_niedrigsten_kontostand() const
{
  Konto *konto_mit_dem_niedrigsten_kontostand = &konten[0];
  for (int i = 0; i < kontenanzahl; i++)
    if (konten[i].liefere_kontostand() < konto_mit_dem_niedrigsten_kontostand->liefere_kontostand())
      konto_mit_dem_niedrigsten_kontostand = &konten[i];
  return konto_mit_dem_niedrigsten_kontostand;
}
/**
 * Liefert die Ueberweisung mit den groesstem Volumen.
 * @return  Die Ueberweisung mit den groesstem Volumen.
 */
Ueberweisung *Geldueberweisungensimulator::liefere_groesste_ueberweisung() const
{
  Ueberweisung *hoechste_ueberweisung = &ueberweisungen[0];
  for (int i = 0; i < ueberweisungenanzahl; i++)
    if (ueberweisungen[i].liefere_ueberweisungsvolumen() > hoechste_ueberweisung->liefere_ueberweisungsvolumen())
      hoechste_ueberweisung = &ueberweisungen[i];
  return hoechste_ueberweisung;
}
/**
 * Liefert die Ueberweisung mit den kleinstem Volumen.
 * @return  Die Ueberweisung mit den kleinstem Volumen.
 */
Ueberweisung *Geldueberweisungensimulator::liefere_kleinste_ueberweisung() const
{
  Ueberweisung *kleinste_ueberweisung = &ueberweisungen[0];
  for (int i = 0; i < ueberweisungenanzahl; i++)
    if (ueberweisungen[i].liefere_ueberweisungsvolumen() < kleinste_ueberweisung->liefere_ueberweisungsvolumen())
      kleinste_ueberweisung = &ueberweisungen[i];
  return kleinste_ueberweisung;
}
/**
 * Als Ergebnis der Simulation eines Tages werden auf der Konsole folgende Informationen ausgegeben:
 * <br>Tag, Gesamtbestand, hoechster Kontostand, niedrigster Kontostand.
 */
void Geldueberweisungensimulator::schreibe_kontenuebersicht() const
{
  int spaltenbreite = 30;
  stringstream streampuffer;
  string ausgabe = "";  
  cout << endl << setw(spaltenbreite) << left << "Gesamtbestand"
    << setw(spaltenbreite) << left << ": ";
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << liefere_gesamtbestand() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;

  Konto *konto = liefere_hoechsten_kontostand();
  cout << setw(spaltenbreite) << left << "Hoechster Kontostand";
  streampuffer.str("");
  streampuffer << left << ": Nummer " << left << konto->liefere_kontonummer();
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << left << ausgabe;
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << konto->liefere_kontostand() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;

  konto = liefere_niedrigsten_kontostand();
  cout << setw(spaltenbreite) << left << "Niedrigster Kontostand";
  streampuffer.str("");
  streampuffer << left << ": Nummer " << left << konto->liefere_kontonummer();
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << left << ausgabe;
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << konto->liefere_kontostand() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;
}
/**
 * Als Ergebnis der Simulation eines Tages werden auf der Konsole folgende Informationen ausgegeben:
 * <br>Ueberweisungen:  Anzahl, Gesamtvolumen, groesste Ueberweisung, kleinste Ueberweisung, Durchschnitt aller.
 */
void Geldueberweisungensimulator::schreibe_ueberweisungenuebersicht() const
{
  int spaltenbreite = 30;
  stringstream streampuffer;
  string ausgabe = "";
  cout << endl << "Ueberweisungen:" << endl << endl;

  cout << setw(spaltenbreite) << left << "Anzahl"
    << setw(spaltenbreite) << left << ": "
    << setw(spaltenbreite) << right << ueberweisungenanzahl << endl;

  cout << setw(spaltenbreite) << left << "Gesamtvolumen"
    << setw(spaltenbreite) << left << ": ";
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << liefere_gesamtvolumen() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;

  Ueberweisung *ueberweisung = liefere_groesste_ueberweisung();
  cout << setw(spaltenbreite) << left << "Groesste Ueberweisung";
  streampuffer.str("");
  streampuffer << ": " << ueberweisung->liefere_ueberweisungsinfo();
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << left << ausgabe;
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << ueberweisung->liefere_ueberweisungsvolumen() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;

  ueberweisung = liefere_kleinste_ueberweisung();
  cout << setw(spaltenbreite) << left << "Kleinste Ueberweisung";
  streampuffer.str("");
  streampuffer << ": " << ueberweisung->liefere_ueberweisungsinfo();
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << left << ausgabe;
  streampuffer.str("");
  streampuffer << setprecision(2) << fixed << ueberweisung->liefere_ueberweisungsvolumen() << " Euro";
  ausgabe = streampuffer.str();
  cout << setw(spaltenbreite) << right << ausgabe << endl;

  cout << setw(spaltenbreite) << left << "Durchschnitt aller"
    << setw(spaltenbreite) << left << ": "
    << setw(spaltenbreite) << right << liefere_ueberweisungen_durchschnitt() << endl;
}
// eventuell Code
// weiterer Funktionen
