#include <iostream>
#include <cstdlib>
#include <vector>

#include "karte.h"
#include "kartenstapel.h"
#include "spieler.h"
#include "maumau.h"

using namespace std;

bool parameter_ok(int argc, char **argv);
bool vergleiche_parameter(const string der_parameter);
void program_starten(char **argv);
void schreibe_anleitung();

/**Ein Programm zur Simulation des Kartenspiels MauMau, das Folgendes leistet:<br>
 * <br>
 * Das Spiel MauMau kann mit vier KI-Spieler oder mit einem menschlichen Spieler gestartet werden.<br>
 * Wird als Uebergabeparameter -a angegeben, startet das Spiel mit vier KI-Spieler.<br>
 * Wird Parameter -m angegeben, startet das Spiel mit einem menschlichen Spieler und drei KI-Spieler.<br>
 * <br>
 * Regeln, die im diesen Programm beruecksichtigt wurden (Quelle: http://de.wikipedia.org/wiki/Mau-Mau_(Kartenspiel)):<br>
 * Mau-Mau ist ein Auslegespiel. Gewonnen hat, wer zuerst alle seine Karten abspielen konnte. Der Gewinn wird mit einem Ausruf „Mau-Mau!“ kund getan.
 * Zu Beginn erhaelt jeder Spieler fuenf Karten, die er auf seine Hand nimmt.
 * Die restlichen Karten werden als Talon (Stapel) abgelegt. Die oberste Karte des Talons wird offen, auf Ablagestapel daneben gelegt.
 * Reihum legt nun jeder Spieler eine seiner Karten offen auf die nebenliegende Karte - wenn dies moeglich ist.
 * Moeglich ist dies, wenn die abzulegende Karte in Kartenwert oder Kartenfarbe mit der obersten offen liegenden Karte uebereinstimmt.
 * Auf die Pik 10 darf also entweder eine andere Pik-Karte oder eine andere 10 gelegt werden.<br>
 * <br>
 * Kann ein Spieler keine Karte ablegen, so muss er eine Karte vom Talon ziehen.
 * Er darf anschließend diese Karte, wenn sie den angegebenen Bedingungen genuegt, ablegen, oder muss warten, bis er erneut an der Reihe ist.
 * Ist der Talon irgendwann aufgebraucht, so werden die abgelegten Karten, ausser der obersten sichtbaren, erneut als Talon ausgelegt. Sie vorher noch gemischt.<br>
 * <br>
 * Weitere Regeln:<br>
 * Auf den Grundregeln aufbauend wird Mau-Mau immer mit weiteren Regeln gespielt.
 * In Mau-Mau gibt es Kartenwerte von besonderer Bedeutung fuer den Spielverlauf.<br>
 * <br>
 * Wird eine Sieben abgelegt, muss der naechste Spieler 2 Karten ziehen oder Selber eine Sieben legen.
 * Wird eine weitere Sieben gelegt, muss der naechste Spieler dann 4 Karten aufnehmen der übernaechste 6 etc.<br>
 * <br>
 * Wird ein Ass gelegt, muss der naechste Spieler aussetzen. Anstatt auszusetzen darf eine weitere Ass-Karte gelegt werden ("Gegenstechen")
 * und der naechste Spieler setzt aus, wenn er nicht auch eine Ass-Karte legen kann usw.<br>
 * <br>
 * Wird ein	Bube-Karte gelegt, kann der Spieler eine Kartenfarbe wuenschen. Kann nicht auf einen anderen Buben gelegt werden ("Bube auf Bube stinkt").<br>
 * <br>
 * Zu Beginn und nach jedem Ablegen wird auf dem Bildschirm ausgegeben: Jeder Spieler und seine Karten, Ablagestapel und Talon mit seinen Karten.<br>
 * <br>
 * Sobald ein Spieler keine Karten mehr hat, endet das Spiel.<br>
 * Auf dem Bildschirm soll danach für die anderen Spieler die Summe der Augen der Karten ausgegeben werden, die sie zu diesem Zeitpunkt haben.<br>
 * Wie viel Augen welche Karte hat, finden Sie hier: http://de.wikipedia.org/wiki/Skat.
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Gibt 0 fuer richtige ausfuerung und andere Werte fuer abbruch/fehler.
 */
int main(int argc, char **argv)
{
  if (parameter_ok(argc, argv))
  {
    program_starten(argv);
  }
  else
    schreibe_anleitung();
}
/**
 * Prueft die Parameter auf richtigkeit. Es darf nur ein Parameter ubergeben werden.
 * <br>
 * Wird als Uebergabeparameter -a angegeben, startet das Spiel mit vier KI-Spieler.<br>
 * Wird Parameter -m angegeben, startet das Spiel mit einem menschlichen Spieler und drei KI-Spieler.<br>
 *
 * @param argc  Anzahl der Parameter.
 * @param argv  Die Parameter.
 * @return Ob die Parameter richtig eingegeben wurden (true) oder nicht (false).
 */
bool parameter_ok(int argc, char *argv[])
{
	bool parameter_ok = false;
	if (argc == 2)
	{
    parameter_ok = vergleiche_parameter(argv[1]);
  }
	return parameter_ok;
}
/**Prueft die Eingabe auf richtigen Parameter (-a) oder (-m).
 * @param der_parameter  Der Parameter, der ueberprueft werden soll.
 * @return Liefert true wenn der Parameter i.O. ist und false wenn nicht.
 */
bool vergleiche_parameter(const string der_parameter)
{
  return (!(der_parameter.compare("-a")) || !(der_parameter.compare("-m")));
}
/**
 * Startet das Program ohne (-a) oder mit (-m) Benutzerinteraktionen.
 *
 * @param argv  Die Parameter.
 */
void program_starten(char **argv)
{
  cout << "\n\nDieses Programm spielt das Auslegespiel Mau-Mau.\n\n";
  string der_parameter = argv[1];
  if (der_parameter == "-a")
  {
    Maumau maumau = Maumau();
    maumau.starte_spiel();
  }
  else
  {
    Maumau maumau = Maumau(1);
    maumau.starte_spiel();
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
          << "\nDas Spiel MauMau kann mit vier KI-Spieler oder mit einem menschlichen Spieler und drei KI-Spieler gestartet werden.\n"
          << "\nWird als Uebergabeparameter -a angegeben, startet das Spiel mit vier KI-Spieler."
          << "\nWird Parameter -m angegeben, startet das Spiel mit einem menschlichen Spieler und drei KI-Spieler.\n";
}