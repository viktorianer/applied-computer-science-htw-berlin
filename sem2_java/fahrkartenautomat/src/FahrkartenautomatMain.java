/**
 * Ein Programm, das einen Fahrkartenautomat mit bestimmten Zielen simuliert.
 * Die Benutzer und Benutzerinnen können (nach geeigneter Benutzerführung) ein Ziel waehlen und erhalten, nach der
 * Bezahlung, die Fahrkarte. Die Bezahlung erfolgt mit Eurogeld.
 * <br>
 * Dabei wird folgendes Realisiert:<br>
 * Es wird eine Aufstellung sämtlicher Fahrtziele ausgegeben (>= 10).
 * Die Auswahl des Fahrtziels erfolgt durch Eingabe einer Kennziffer (ID).
 * Bei Eingabe von -1 wird das Programm beendet. Nicht zulässige Kennziffern werden ignoriert.
 * <br>
 * Nach Wahl des Fahrtziels erscheint der Fahrpreis und die Benutzerinnen und Benutzer werden aufgefordert,
 * den Preis zu zahlen. Alle Fahrtziele haben unterschiedliche Preise.
 * <br>
 * Beim Zahlen des Preises wird nur die Eingabe von 50.00 Euro, 20.00 Euro, 10.00 Euro, 5.00 Euro, 2.00 Euro,
 * 1.00 Euro, 0.50 Euro, 0.10 Euro und 0.00 Euro akzeptiert. Andere Eingaben werden zurückgeweisen.
 * Die Preise sind so festgelegt, dass sie glatt durch die zulässigen Eingaben bezahlt werden können.
 * <br>
 * Wenn der eingegebene Betrag gleich dem angezeigten Fahrpreis ist, wird zur Entnahme der Fahrkarte aufgefordert.
 * Anschließend wird für den nächsten Kunden wieder die Aufstellung sämtlicher Fahrtziele erscheinen.
 * <br>
 * Wenn der eingegebene Betrag kleiner als der angezeigte Fahrpreis ist, wird statt des Preises der
 * noch zu zahlende Restbetrag angezeigt und es wird zur weiteren Eingabe eines Geldbetrages aufgefordert.
 * <br>
 * Die Eingabe eines Geldbetrages wird so lange fortgesetzt, bis der eingegebene Betrag
 * größer oder gleich dem Fahrpreis ist oder bis die Benutzerin oder der Benutzer als Abbruchbedingung
 * den Betrag 0.00 Euro eingibt.
 * <br>
 * Falls 0.00 Euro eingegeben wurde, erscheint auf dem Bildschirm ein Hinweis, dass der
 * schon bezahlte Betrag zurückerstattet wird. Dabei wird die Höhe des Rückerstattungsbetrages angegeben
 * und genau aufgeschlüsselt, welche Eingaben getätigt wurden (z.B. 3 ´ 1.00 Euro, 1 ´
 * 0.50 Euro, 2 ´ 0.10 Euro). Anschließend wird für den nächsten Kunden wieder die Aufstellung
 * sämtlicher Fahrtziele erscheinen.
 * <br>
 * Falls zu viel eingegeben wurde, wird zur Entnahme der Fahrkarte aufgefordert und außerdem
 * die Höhe des Rückerstattungsbetrages sowie die Form der Rückerstattung
 * angezeigt (z.B. 3 ´ 5.00 Euro, 1 ´ 1.00 Euro, 2 ´ 0.10 Euro). Dabei werden jeweils möglichst wenige
 * Zahlungseinheiten zurückgezahlt werden (d.h. z.B. statt 5 ´ 1.00 Euro nur 1 ´ 5.00 Euro).
 * Anschließend wird für den nächsten Kunden wieder die Aufstellung sämtlicher Fahrtziele erscheinen.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class FahrkartenautomatMain {
    /**
     * Einstiegspunkt des Programms.
     * <br>
     * main ist (zunächst) die einzige Methode der Klasse.
     * Java schreibt vor, das main immer public und static ist.
     * stellt sich heraus, dass die Aufgaben von main komplex sind, setzen wir zusätzlich geeignete Hilfsmethoden ein
     * die dann stets private und static sind.
     * Dadurch wird Main zu einer aus objektorientierter Sicht völlig untypischen Klasse,
     * die natürlich die genannten Gütekriterien nicht erfüllt.
     * Diese Häßlichkeit nehmen wir in Kauf.
     */
    private FahrkartenautomatMain() {
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * <br>
     * Es wird eine Aufstellung sämtlicher Fahrtziele ausgegeben (>= 10).
     * Die Auswahl des Fahrtziels erfolgt durch Eingabe einer Kennziffer (ID).
     * Bei Eingabe von -1 wird das Programm beendet. Nicht zulässige Kennziffern werden ignoriert.
     *
     * @param args Keine Uebergabe moeglich.
     */
    public static void main(String[] args) {
        fahrkartenautomat();
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * <br>
     * Es wird eine Aufstellung sämtlicher Fahrtziele ausgegeben (>= 10).
     * Die Auswahl des Fahrtziels erfolgt durch Eingabe einer Kennziffer (ID).
     * Bei Eingabe von -1 wird das Programm beendet. Nicht zulässige Kennziffern werden ignoriert.
     */
    private static void fahrkartenautomat() {
        Fahrkartenautomat fahrkartenautomat = new Fahrkartenautomat();
        int ziel;
        boolean eingabeOK = false;
        do {
            ziel = fahrkartenautomat.wahlDesZieles();
            if (ziel == -1) {
                System.out.printf("\nDas Programm wird auf Ihren Wunsch hin beendet.\n");
                eingabeOK = true;
            } else
                fahrkartenautomat.bestellvorgang(ziel);

        } while (!eingabeOK);
    }
}