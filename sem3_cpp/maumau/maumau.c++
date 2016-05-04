 #include <cmath>
#include <algorithm>

#include "maumau.h"
// weitere Angaben
// Code der Konstruktoren
/** Erzeugt den Defaultobjekt, Kartenspiel MauMau und initialisiert das Spiel mit vier KI-Spieler. */
Maumau::Maumau()
{
  talon = Kartenstapel();
  mische_talon();
  initialisiere_ablage();
  initialisiere_kispieler(4, 5);
  anzahl_durchlaeufe = 0;
  if ((ablage.obere_karte_ist().liefere_kartenwert() == "Sieben"))
    anzahl_gespielter_sieben = 1;
  else
    anzahl_gespielter_sieben = 0;
  if ((ablage.obere_karte_ist().liefere_kartenwert() == "Ass"))
    anzahl_gespielter_asse = 1;
  else
    anzahl_gespielter_asse = 0;
  wunschkarte =  Karte("Bube", "Herz");
  wunsch = false;
}
/**Erzeugt das Kartenspiel MauMau und initialisiert das Spiel mit anzahl_mensch_spieler (max. vier) menschlichen Spieler und (4 - anzahl_mensch_spieler) KI-Spieler.
 * Jeder Spieler bekommt fuenf Karten als Startkarten.
 *
 * @param anzahl_mensch_spieler Die Anzahl der menschlichen Spieler.
 */
Maumau::Maumau(int anzahl_mensch_spieler)
{
  if (0 < anzahl_mensch_spieler && anzahl_mensch_spieler <= 4)
  {
    talon = Kartenstapel();
    mische_talon();
    initialisiere_ablage();
    initialisiere_spieler(anzahl_mensch_spieler, 4 - anzahl_mensch_spieler, 5);
    anzahl_durchlaeufe = 0;
    wunschkarte =  Karte("Bube", "Herz");
    wunsch = false;
  }
}
/**Ueberschreibt den Destruktor der einen Objekt richtig zerstoert.
 * Gibt auf dem Heap allokierten Speicherplatz beim Zerstoeren der Objekte wieder frei 
 */
Maumau::~Maumau()
{
  for (unsigned int i = 0; i < spieler.size(); i++)
    delete spieler[i];
  spieler.clear();
}
/**Erzeugt eine Kopie des Originals (tiefe Kopie (deep copy)).
 *
 * @param original  Das original Obejkt, das kopiert werden soll.
 */
Maumau::Maumau(const Maumau& original)
{
  for (unsigned int i = 0; i < spieler.size(); i++)
    delete spieler[i];
  spieler.clear();
  talon = original.talon;
  ablage = original.ablage;
  spieler = original.spieler;
  anzahl_durchlaeufe = original.anzahl_durchlaeufe;
  anzahl_gespielter_sieben = original.anzahl_gespielter_sieben;
  anzahl_gespielter_asse = original.anzahl_gespielter_asse;
  wunschkarte = original.wunschkarte;
  wunsch = original.wunsch;
}
/**Ueberladen des Zuweisungsoperators um eine Zuweisung richtig duchfueren zu koennen.
 *
 * @param ein_maumau_spiel  Das Obejekt, welches zugewiesen werden soll.
 * @return  Referenz auf das Obejkt, welches nach der Zuweisung die gleiche Werte hat wie das uebergebende Objekt.
 */
Maumau& Maumau::operator=(const Maumau& ein_maumau_spiel)
{
  if (this != &ein_maumau_spiel) // nur, wenn verschieden
  {
    for (unsigned int i = 0; i < spieler.size(); i++)
      delete spieler[i];
    spieler.clear(); // lösche alte Werte
    talon = ein_maumau_spiel.talon; // speichere neue Werte
    ablage = ein_maumau_spiel.ablage;
    spieler = ein_maumau_spiel.spieler;
    anzahl_durchlaeufe = ein_maumau_spiel.anzahl_durchlaeufe;
    anzahl_gespielter_sieben = ein_maumau_spiel.anzahl_gespielter_sieben;
    anzahl_gespielter_asse = ein_maumau_spiel.anzahl_gespielter_asse;
    wunschkarte = ein_maumau_spiel.wunschkarte;
    wunsch = ein_maumau_spiel.wunsch;
  }
  return *this;
}
// Code der Methoden
/**Startet das Spiel mit MauMau Regeln.<br>
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
 */
void Maumau::starte_spiel()
{
  bool maumau = false;
  do
  {
    for (unsigned int der_spieler = 0; der_spieler < spieler.size() && maumau == false; der_spieler++)
    {
      if (anzahl_durchlaeufe == 0)
      {
        der_spieler = static_cast<unsigned int>(Zufallsgenerator::liefere_zufallsgenerator()
                .liefere_ganze_zufallszahl(0, spieler.size() - 1));
        cout << "Der " << spieler[der_spieler]->liefere_nickname() << " darf als erster beginnen." << endl << endl;
      }
      schreibe_spielsituation();
      Karte karte_auf_der_ablage = ablage.obere_karte_ist();
      if ((spieler[der_spieler]->hat_sieben() > 0 && anzahl_gespielter_sieben > 0 && anzahl_gespielter_asse == 0) ||
        (spieler[der_spieler]->hat_ass() > 0 && anzahl_gespielter_asse > 0 && anzahl_gespielter_sieben == 0) ||
        (wunsch == true && spieler[der_spieler]->hat_passende_wunsch_karten(wunschkarte) > 0) ||
        ((spieler[der_spieler]->hat_passende_karten(karte_auf_der_ablage) > 0) &&
          anzahl_gespielter_sieben == 0 && anzahl_gespielter_asse == 0 && wunsch == false))
        maumau = spieler_spielt_karte(der_spieler);
      else
        keine_passende_karte(der_spieler);
      anzahl_durchlaeufe++;
    }
  } while (maumau == false);
  schreibe_situation_ende();
}

/** Mischt Talon-Stapel durch. */
void Maumau::mische_talon()
{
  talon.mische_kartenstapel();
}
/**Initialisiert die Ablage mit einer Karte.<br>
 * <br>
 * Wird eine Sieben abgelegt, muss der naechste Spieler 2 Karten ziehen oder Selber eine Sieben legen.<br>
 * <br>
 * Wird ein Ass gelegt, muss der naechste Spieler aussetzen, wenn er nicht auch eine Ass-Karte legen kann.
 */
void Maumau::initialisiere_ablage()
{
  ablage = Kartenstapel(talon.liefere_obere_karte());
  if ((ablage.obere_karte_ist().liefere_kartenwert() == "Sieben"))
    anzahl_gespielter_sieben = 1;
  else
    anzahl_gespielter_sieben = 0;
  if ((ablage.obere_karte_ist().liefere_kartenwert() == "Ass"))
    anzahl_gespielter_asse = 1;
  else
    anzahl_gespielter_asse = 0;
}
/**Initialisiert das Spiel mit anzahl_mensch_spieler (max. vier) menschlichen Spieler und (4 - anzahl_mensch_spieler) KI-Spieler.
 * Jeder Spieler bekommt anzahl_karten Karten als Startkarten.
 *
 * @param anzahl_mensch_spieler Die Anzahl menschlicher Spieler.
 * @param anzahl_kispieler      Die Anzahl der KI-Spieler.
 * @param anzahl_karten         Die Anzahl der Karten, die jeder Spieler bekommen soll.
 */
void Maumau::initialisiere_spieler(int anzahl_mensch_spieler, int anzahl_kispieler, int anzahl_karten)
{
  spieler.reserve(spieler.size() * anzahl_mensch_spieler);
  stringstream s;
  for (int i = 0; i < anzahl_mensch_spieler; i++)
  {
    vector<Karte> karten;
    for (int j = 0; j < anzahl_karten; j++)
    {
      karten.push_back(talon.liefere_obere_karte());
    }
    s << i + 1;
    spieler.push_back(new Spieler(karten, "Mensch Spieler " + s.str(), true));
    s.str("");
  }
  initialisiere_kispieler(anzahl_kispieler, anzahl_karten);
}
/**Initialisiert das Spiel mit anzahl_kispieler KI-Spieler.
 * Jeder Spieler bekommt anzahl_karten Karten als Startkarten.
 *
 * @param anzahl_kispieler
 * @param anzahl_karten
 */
void Maumau::initialisiere_kispieler(int anzahl_kispieler, int anzahl_karten)
{
  spieler.reserve(spieler.size() * anzahl_kispieler);
  stringstream s;
  for (int i = 0; i < anzahl_kispieler; i++)
  {
    vector<Karte> karten;
    for (int j = 0; j < anzahl_karten; j++)
    {
      karten.push_back(talon.liefere_obere_karte());
    }
    s << i + 1;
    spieler.push_back(new KISpieler(karten, "Spieler " + s.str(), false));
    s.str("");
  }
}
/**Steuert die Regeln, wenn der Spieler keine passende Karten hat.
 *
 * @param der_spieler Der Spieler,der keine passende Karte hat.
 */
void Maumau::keine_passende_karte(int der_spieler)
{
  cout << spieler[der_spieler]->liefere_nickname() << " hat keine passenden Karten...";
  if (anzahl_gespielter_sieben > 0 && anzahl_gespielter_asse == 0)
    spieler_nimmt_karten(der_spieler);
  else if (anzahl_gespielter_asse > 0 && anzahl_gespielter_sieben == 0)
  {
    cout << " und muss aussetzen..." << endl;
    anzahl_gespielter_asse = 0;
  }
  else
  {
    if (talon.liefere_anzahl_karten() <= 0)
      neuen_talon_mischen();
    Karte obere_karte = talon.liefere_obere_karte();
    cout << "und nimmt die obere Karte auf dem Talon..." << endl;
    spieler[der_spieler]->nimm_karte(obere_karte);
    if ((obere_karte == ablage.obere_karte_ist() && wunsch == false) ||
      (wunsch == true && wunschkarte.liefere_kartenfarbe() == obere_karte.liefere_kartenfarbe()))
      spieler_spielt_karte(der_spieler);
  }
}
/**Steurt die Regeln, wenn der Spieler passende Karten hat.
 *
 * @param der_spieler Der Spieler,der passende Karte hat.
 * @return Liefert true wenn der Spieler gewonnen hat oder false wenn nicht.
 */
bool Maumau::spieler_spielt_karte(unsigned int der_spieler)
{
  bool maumau = false;
  if (wunsch == true && spieler[der_spieler]->hat_passende_wunsch_karten(wunschkarte) > 0)
  {
    ablage.fuege_karte_hinzu(spieler[der_spieler]->spiele_karte(wunschkarte));
    wunsch = false;
  }
  else
    ablage.fuege_karte_hinzu(spieler[der_spieler]->spiele_karte(ablage.obere_karte_ist()));

  if (spieler[der_spieler]->liefere_anzahl_karten() == 1)
    cout << "MAU!" << endl;
  if (spieler[der_spieler]->liefere_anzahl_karten() == 0)
  {
    maumau = true;
    cout << "MAUMAU!" << endl;
  }
  if (ablage.obere_karte_ist().liefere_kartenwert() == "Bube" && maumau == false)
  {
    wunsch = true;
    wunschkarte = Karte("Bube", spieler[der_spieler]->liefere_wunschfarbe());
  }
  else if (ablage.obere_karte_ist().liefere_kartenwert() == "Sieben" && maumau == false)
    anzahl_gespielter_sieben++;
  else if (ablage.obere_karte_ist().liefere_kartenwert() == "Ass" && maumau == false)
    anzahl_gespielter_asse++;
  return maumau;
}
/**Steuert die Regeln, wenn der Spieler Straf-Karten nehmen muss.
 *
 * @param der_spieler Der Spieler,der Straf-Karten nehmen muss.
 */
void Maumau::spieler_nimmt_karten(unsigned int der_spieler)
{
  if (talon.liefere_anzahl_karten() <= (anzahl_gespielter_sieben * 2) &&
    ablage.liefere_anzahl_karten() > (anzahl_gespielter_sieben * 2))
    neuen_talon_mischen();
  cout << "und muss " << (anzahl_gespielter_sieben * 2) << " Karten aufnehmen." << endl;
  if (talon.liefere_anzahl_karten() >= (anzahl_gespielter_sieben * 2))
    for (int i = 0; i < (anzahl_gespielter_sieben * 2); i++)
      spieler[der_spieler]->nimm_karte(talon.liefere_obere_karte());
  anzahl_gespielter_sieben = 0;
}
/**Mischt die Ablage in den Talon ein.*/
void Maumau::neuen_talon_mischen()
{
  Karte obere_karte = ablage.liefere_obere_karte();
  talon << ablage;
  ablage.fuege_karte_hinzu(obere_karte);
}
/**Zu Beginn und nach jedem Ablegen wird auf dem Bildschirm ausgegeben: Jeder Spieler und seine Karten, Ablagestapel und Talon mit seinen Karten.*/
void Maumau::schreibe_spielsituation() const
{
//  cout << endl << "Anzahl gesp. Sieben: " << anzahl_gespielter_sieben <<
//        "  Anzahl gesp. Asse: " << anzahl_gespielter_asse <<
//        "  Wunschkarte gespielt?: " << wunsch << endl;
  if (anzahl_durchlaeufe != 0)
    cout << endl << "Spielsituation " << anzahl_durchlaeufe << endl << endl;
  for (unsigned int i = 0; i < spieler.size(); i++)
    cout << setw(20) << left << spieler[i]->liefere_nickname();
  cout << endl;
  schreibe_situation_spieler();
  schreibe_situation_ablage_talon();
  
  int anzahl_karten = 0;
  for (unsigned int i = 0; i < spieler.size(); i++)
    anzahl_karten += spieler[i]->liefere_anzahl_karten();
  anzahl_karten += ablage.liefere_anzahl_karten();
  anzahl_karten += talon.liefere_anzahl_karten();
//  cout << "Anzahl der Karten: " << anzahl_karten << endl;
  cout << "Druecken Sie Enter um eine Runde zu spielen...";
  cin.get();
}
/**Gibt auf dem Bildschirm jeden Spieler und seine Karten aus. */
void Maumau::schreibe_situation_spieler() const
{
  int anzahl_karten = 0;
  stringstream s;
  for (unsigned int i = 0; i < spieler.size(); i++)
    if (anzahl_karten < spieler[i]->liefere_anzahl_karten())
      anzahl_karten = spieler[i]->liefere_anzahl_karten();
  for (int j = 0; j < anzahl_karten; j++)
  {
    for (unsigned int i = 0; i < spieler.size(); i++)
    {
      if (spieler[0]->liefere_ob_mensch())
      {
        if (spieler[i]->liefere_ob_mensch())
          cout << setw(20) << left << spieler[i]->liefere_karten_info(j);
        else if (j < 1)
        {
          s << spieler[i]->liefere_anzahl_karten();
          cout << setw(20) << left << "hat "  + s.str() + " Karten";
          s.str("");
        }
      }
      else
        cout << setw(20) << left << spieler[i]->liefere_karten_info(j);
        
    }
    cout << endl;
  }
}
/**Gibt auf dem Bildschirm Ablagestapel und Talon aus.*/
void Maumau::schreibe_situation_ablage_talon() const
{
  stringstream s;
  for (unsigned int i = 0; i < spieler.size(); i++)
      cout << setw(20) << setfill('_') << " ";
  cout << setfill(' ') << endl << endl;
  cout << setw(20) << left << "abgelegte Karten:" << setw(20) << left << "Talon:" << endl;
  int anzahl_karten = talon.liefere_anzahl_karten();
  if (anzahl_karten < ablage.liefere_anzahl_karten())
    anzahl_karten = ablage.liefere_anzahl_karten();
  if (spieler[0]->liefere_ob_mensch())
  {
    cout << setw(20) << left << ablage.liefere_karten_info(0);
    s << talon.liefere_anzahl_karten();
    cout << setw(20) << left << "hat "  + s.str() + " Karten" << endl;
    s.str("");
    if (ablage.liefere_anzahl_karten() - 1 > 0)
    {
      s << ablage.liefere_anzahl_karten() - 1;
      cout << setw(20) << left << "und "  + s.str() + " weitere" << endl;
      s.str("");
    }
  }
  else
    for (int j = 0; j < anzahl_karten; j++)
      cout << setw(20) << left << ablage.liefere_karten_info(j)
        << setw(20) << left << talon.liefere_karten_info(j) << endl;
  cout << endl;
}
/**Sobald ein Spieler keine Karten mehr hat, endet das Spiel.<br>
 * Auf dem Bildschirm soll danach für die anderen Spieler die Summe der Augen der Karten ausgegeben werden, die sie zu diesem Zeitpunkt haben.<br>
 * Wie viel Augen welche Karte hat, finden Sie hier: http://de.wikipedia.org/wiki/Skat.
 */
void Maumau::schreibe_situation_ende() const
{
  cout << endl << "Summe der Augen der Karten:" << endl;
  for (unsigned int i = 0; i < spieler.size(); i++)
    if (spieler[i]->liefere_anzahl_karten() > 0)
      cout << setw(20) << right << spieler[i]->liefere_nickname();
  cout << endl;
  for (unsigned int i = 0; i < spieler.size(); i++)
    if (spieler[i]->liefere_anzahl_karten() > 0)
      cout << setw(20) << right << spieler[i]->liefere_anzahl_augen();
  cout << endl;
}
// eventuell Code
// weiterer Funktionen
