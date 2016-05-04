/**
 * Ein Programm, das einen Umrechner fuer bestimmte Temperatur repraesentiert.
 * Die Temperatur besteht aus der Hohe der Temperatur (-459.67 - 10000)
 * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit).
 * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
 * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class MastermindMain {
    /**
     * Einstiegspunkt des Programms.
     * main ist (zunächst) die einzige Methode der Klasse.
     * Java schreibt vor, das main immer public und static ist.
     * stellt sich heraus, dass die Aufgaben von main komplex sind, setzen wir zusätzlich geeignete Hilfsmethoden ein
     * die dann stets private und static sind.
     * Dadurch wird Main zu einer aus objektorientierter Sicht völlig untypischen Klasse,
     * die natürlich die genannten Gütekriterien nicht erfüllt.
     * Diese Häßlichkeit nehmen wir in Kauf.
     */
    private MastermindMain() {
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * Erzeugt einen  Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
     * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
     * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
     * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
     *
     * @param args Wird nicht genutzt.
     */
    public static void main(String[] args) {
        System.out.printf("\nDieses Programm spielt den Quizmaster fuer ein Mastermind-Quiz\n"
                + "\nPer Zufallszahlengenerator wird eine n-stellige (n > 4) positive ganze Zahl x erzeugt, "
                + "die folgenden Bedingungen genügt:\n"
                + "Jede der Ziffern 0, 1, ..., 9 kommt in x höchstens einmal vor."
                + "Eine führende Null ist erlaubt, d.h. 0 darf in x als erste Ziffer auftreten."
                + "\nDie Zahl soll wahlweise entweder von den Benutzern und Benutzerinnen des Programms oder "
                + "vom Computer selbst gefunden werden.\n");
        benutzerFuerung();
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * Erzeugt einen  Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
     * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
     * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
     * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
     */
    private static void benutzerFuerung() {
        boolean antwort = false;
        String programmMenue[] = {"Mastermind Spielen", "AI spielt Mastermind", "Programm beenden"};
        do {
            Menue menue = new Menue(programmMenue);
            switch (menue.waehleAusMenue()) {
                case 1:
                    derSpielerSpieltMastermind();
                    break;
                case 2:
                    dieAISpieltMastermind();
                    break;
                default:
                    System.out.printf("\nDas Programm wird beendet. See You!\n");
                    antwort = true;
                    break;
            }
        } while (!antwort);
    }

    private static void derSpielerSpieltMastermind() {
        Mastermind mastermind = new Mastermind(4);
        System.out.printf("\nDie zu erratene Zahl ist: %s\n", mastermind.gibOriginalZahl());
        mastermind.spieleMastermind(10);
    }

    private static void dieAISpieltMastermind() {
        Mastermind mastermind = new Mastermind(4);
        System.out.printf("\nDie zu erratene Zahl ist: %s\n", mastermind.gibOriginalZahl());
        mastermind.spieleMastermindAI(10);
    }
}
