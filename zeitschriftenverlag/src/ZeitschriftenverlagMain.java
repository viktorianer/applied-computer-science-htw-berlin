import java.util.ArrayList;

/**
 * Ein Programm, das einen Zeitungsverlag mit bestimmten Zeitungen simuliert.
 * Der Zeitschriftenverlag beschäftigt wöchentlich n Studierende, die in den Abend- und Nachtstunden
 * die Zeitschriften Nachtmär, Tippy und Moon in Berliner Lokalen verkaufen. Ein Exemplar der Zeitschrift
 * Nachtmaer kostet 3.50 Euro, ein Tippy 4.80 Euro und ein Moon 3.90 Euro.
 * <br>
 * Jede Verkäuferin und jeder Verkäufer erhält als Lohn pro verkauftem Exemplar der Zeitschriften
 * Tippy und Moon 12.5 % des Verkaufspreises, pro verkauftem Exemplar von Nachtmär 10.25 %.
 * <br>
 * Die Personendaten werden per Zufallszahlengenerator erzeugt. Dazu werden genügend viele
 * verschiedene Vornamen mit genügend vielen verschiedenen Nachnamen kombiniert.
 * <br>
 * Für jeden der n Studierenden wird für jeden Tag der Woche (So - Sa) und für jede Zeitschrift
 * separat die Anzahl verkaufter Exemplare per Zufallszahlengenerator erzeugt.
 * <br>
 * Aus einem Menü heraus wird für jeden Wochentag eine Aufstellung mit folgenden Informationen
 * seitenweise auf dem Bildschirm ausgegeben:
 * Für jeden Studierenden und für jede Zeitung enthält die Aufstellung die Anzahl verkaufter Exemplare
 * sowie den Umsatz in Euro (anzahl * preis). Sie wird alphabetisch nach den Nachnamen
 * der Studierenden sortiert.
 * <br>
 * Es wird ferner eine Liste aller Studierenden ausgegeben, die nach dem auszuzahlenden
 * Wochenlohn sortiert ist (Name und Wochenlohn).
 * <br>
 * Wenn die Parameter beim Aufruf des Programms nicht die gewünschte Gestalt haben (zu wenig
 * oder zu viele Parameter, Wertebereich falsch, Parameter falsch, etc.), gibt das Programm einen
 * Hinweis auf die korrekte Benutzung aus.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class ZeitschriftenverlagMain {
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
    private ZeitschriftenverlagMain() {
    }

    /**
     * Ueberprueft die Parameter, erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     *
     * @param args <br>Erster Parameter: gibt an, wie viel Studenten, deshalb Angestellte beim Verlag angestellt sind.
     *             Dabei ist die Anzahl immer 1 <= n <= 200.
     *             <br>Zweiter Parameter: gibt an, ob die Sortierung aufsteigend oder absteigend erfolgt (+ oder -).
     */
    public static void main(String[] args) {
        if (parameterOk(args)) {
            int anzahlStudenten = Integer.parseInt(args[0]);
            if (args.length == 2)
                benutzerFuerung(anzahlStudenten, args[1]);
            else
                benutzerFuerung(anzahlStudenten, "+");
        } else
            schreibeAnleitung();
    }

    /**
     * Ueberprueft die Parameter.
     *
     * @param args <br>Erster Parameter: gibt an, wie viel Studenten, deshalb Angestellte beim Verlag angestellt sind.
     *             Dabei ist die Anzahl immer 1 <= n <= 200.
     *             <br>Zweiter Parameter: gibt an, ob die Sortierung aufsteigend oder absteigend erfolgt (+ oder -).
     */
    private static boolean parameterOk(String[] args) {
        boolean ok = false;
        if (args.length == 1 || args.length == 2) {
            try {
                int studierende = Integer.parseInt(args[0]);
                ok = (1 <= studierende && studierende <= 2000000);
                if (args.length == 2) {
                    String sort = args[1];
                    ok = (sort.equals("+") || sort.equals("-"));
                }
            } catch (NumberFormatException nfe) {
                System.out.print(nfe);
            }
        }
        return ok;
    }

    /**
     * Schreibt eine Bedienungsanleitung fuer die Benutzer, wenn diese das Program falsch aufrufen.
     */
    private static void schreibeAnleitung() {
        System.out.printf("\nDas Program wurde mit falschen oder nicht genuegenden Parameter aufgerufen.\n"
                + "\nAnleitung:\n"
                + "Das Programm kann mit einen oder zwei Parameter gestartet werden:\n"
                + "\nErster Parameter: gibt an, wie viel Studenten, deshalb Angestellte beim Verlag angestellt sind.\n"
                + "Dabei ist die Anzahl immer 1 <= n <= 200.\n"
                + "\nZweiter Parameter: gibt an, ob die Sortierung aufsteigend oder absteigend erfolgt (+ oder -).\n"
                + "\nBeispiel 1: programname 50 -  erzeugt einen Verlag mit 50 Studenten, die absteigend sortiert sind.\n"
                + "Beispiel 2: programname 150   erzeugt einen Verlag mit 150 Studenten, die aufsteigend sortiert sind.\n");
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     *
     * @param anzahlStudenten Anzahl der Studenten, die im Verlag arbeiten.
     * @param dieSortierung   Die gewuenschte sortierug der Listen.
     */
    private static void benutzerFuerung(int anzahlStudenten, String dieSortierung) {

        ArrayList<Zeitung> zeitungen = new ArrayList<>(0);
        zeitungen.add(new Zeitung(1, "Tippy", 4.80, "Zeitschriftenverlag", 0.125));
        zeitungen.add(new Zeitung(2, "Moon", 3.90, "Zeitschriftenverlag", 0.125));
        zeitungen.add(new Zeitung(3, "Nachtmaer", 3.50, "Zeitschriftenverlag", 0.1025));
        Verlag zeitschriftenverlag = new Verlag(zeitungen, anzahlStudenten);
        boolean antwort = false;
        String programmMenue[] = {"Tagesstatistik", "Studentenstatistik", "Programm beenden"};
        do {
            Menue menue = new Menue(programmMenue);
            switch (menue.waehleAusMenue()) {
                case 1:
                    zeitschriftenverlag.schreibeTagesstatistik();
                    break;
                case 2:
                    zeitschriftenverlag.schreibeVerkaeferStatistik(dieSortierung);
                    break;
                default:
                    System.out.printf("\nDas Programm wird beendet. See You!\n");
                    antwort = true;
                    break;
            }
        } while (!antwort);
    }
}