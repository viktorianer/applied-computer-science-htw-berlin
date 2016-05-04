/**
 * Ein Programm, das einen Medien-Versandhaus simuliert.
 * <br>
 * Wenn das Programm in der Form programmName generiere n aufgerufen wird,
 * wird mit Hilfe eines Zufallszahlengenerators n Medienobjekte (Bücher, CDs und DVDs) erzeugt und
 * in der Datei Medien.dat gespeichert (100 < n < 1000).
 * <br>
 * Für die 365 Tage eines Jahres Verkaufsdaten erzeugt und in der Datei Verkauf.dat gespeichert.
 * <br>
 * Dabei werden pro Tag 50 bis 300 Verkäufe stattfinden, wobei jeweils genau eines
 * der zuvor erzeugten Medien (in beliebiger Reihenfolge!) bis zu 10 Mal verkauft wird.
 * <br><br>
 * Wenn das Programm in der Form programmName zeige t aufgerufen wird,
 * werden die Verkaufsdaten für den Tag t ausgegeben.
 * <br>
 * Wenn die Parameter beim Aufruf des Programms nicht die gewünschte Gestalt haben (zu wenig
 * oder zu viele Parameter, Wertebereich falsch, Parameter falsch, etc.), gibt das Programm einen
 * Hinweis auf die korrekte Benutzung aus.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class MedienversandMain {
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
    private MedienversandMain() {

    }

    /**
     * Ueberprueft die Parameter und erzeugt neue Daten oder gibt alte Daten aus.
     *
     * @param args Erster Parameter gibt an:
     *             <br> generiere - neue Daten generiert werden sollen
     *             <br> zeige - alte Daten angezeigt werden sollen.<br>
     *             <br>Zweiter Parameter gibt an:
     *             <br> n - Wie viel Medien erzeugt werden sollen. Dabei ist die Anzahl immer 100 <= n <= 1000."
     *             <br> n - Welcher Tag angezeigt werden soll. Dabei ist ein Tag des Jahres, deshalb 1 <= n <= 365, einzugeben.<br>
     *             <br>Beispiel 1: programname generiere 120 -  erzeugt einen Versandhaus mit 120 Medien im Angebot.<br>
     *             Beispiel 2: programname zeige 150 - zeigt eine Verkaufsstatistik fuer Tag 150.
     */
    public static void main(String[] args) {
        if (parameterOK(args)) {
            if (args[0].equals("generiere")) {
                Versand versand = new Versand(Integer.parseInt(args[1]));
                versand.schreibVerkaufteMedien();
            } else {
                Versand versand = new Versand();
                versand.schreibVerkaufsuebersucht(Integer.parseInt(args[1]));
            }
        } else {
            schreibeAnleitung();
        }
    }

    private static boolean parameterOK(String[] args) {
        boolean ok = false;
        if (args.length == 2) {
            try {
                String aufruf = args[0];
                int zahl = Integer.parseInt(args[1]);
                ok = ((aufruf.equals("generiere") && (100 <= zahl || zahl >= 1000)) ||
                        (aufruf.equals("zeige") && (1 <= zahl || zahl >= 365)));
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
                + "Das Programm muss mit zwei Parameter gestartet werden:\n"
                + "\nErster Parameter gibt an:\n"
                + "\t generiere - neue Daten generiert werden sollen\n"
                + "\t zeige - alte Daten angezeigt werden sollen.\n"
                + "\n"
                + "\nZweiter Parameter gibt an:\n"
                + "\t n - Wie viel Medien erzeugt werden sollen. Dabei ist die Anzahl immer 100 <= n <= 1000."
                + "\n\t n - Welcher Tag angezeigt werden soll. Dabei ist ein Tag des Jahres, deshalb 1 <= n <= 365, einzugeben."
                + "\nBeispiel 1: programname generiere 120 -  erzeugt einen Versandhaus mit 120 Medien im Angebot.\n"
                + "Beispiel 2: programname zeige 150 - zeigt eine Verkaufsstatistik fuer Tag 150.\n");
    }
}
