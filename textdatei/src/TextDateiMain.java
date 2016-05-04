import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * Mit diesem Programm kann feststgestellt werden, welche Woerter wie haeufig in einer Textdatei vorkommen. <br>
 * <br>
 * Der Name der zu untersuchenden Textdatei wird dem Programm beim Aufruf als Parameter
 * übergeben. Bei zu wenig oder zu vielen Parametern wird eine Anleitung ausgegeben.<br>
 * <br>
 * Die Textdatei wird geöffnet und gelesen. Das Programm wird sich aber auch dann vernünftig
 * verhalten, wenn die Datei nicht vorhanden ist oder nicht geöffnet werden kann.
 * Das Programm wird aus dem gelesenen Text einzelne Wörter extrahieren und deren Häufigkeit
 * zählen. Dazu wird es im Hauptspeicher eine „Liste“ aufbauen, die jedes im Text vorkommende
 * Wort mit der entsprechenden Häufigkeit enthält.<br>
 * <br>
 * Es steht danach folgendes Menü zur Auswahl:<br>
 * (1) Woerter aufsteigend alphabetisch sortiert<br>
 * (2) Woerter mit Haeufigkeit von min bis max aufsteigend alphabetisch sortiert<br>
 * (3) Woerter absteigend alphabetisch sortiert<br>
 * (4) Woerter mit Haeufigkeit von min bis max absteigend alphabetisch sortiert<br>
 * (5) Woerter absteigend nach Haeufigkeit sortiert<br>
 * (6) Woerter mit Haeufigkeit von min bis max absteigend nach Haeufigkeit sortiert<br>
 * (7) Woerter aufsteigend nach Haeufigkeit sortiert<br>
 * (8) Woerter mit Haeufigkeit von min bis max aufsteigend nach Haeufigkeit sortiert<br>
 * (9) Anzahl Woerter feststellen<br>
 * (10) Woerterliste speichern<br>
 * (11) Neue Woerterliste erzeugen<br>
 * (12) Textdatei anzeigen<br>
 * (13) Programm beenden<br>
 * <br>
 * Bei Wahl von (1) erscheint auf dem Bildschirm eine Aufstellung folgender Art, wobei
 * die Wörter aufsteigend in alphabetischer Reihenfolge ausgegeben werden:<br>
 * <br>
 * Ergebnis der Analyse der Datei dateiname.txt: <br>
 * wort1 5<br>
 * wort2 17<br>
 * wort3 1<br>
 * ...... ...<br>
 * <br>
 * Bei Wahl von (2) wird die Aufstellung nur solche Wörter enthalten, deren Häufigkeit zwischen
 * min und max liegt, wobei min und max zuvor erfasst wurden.<br>
 * <br>
 * Bei Wahl von (3) bis (8) wirden die Wörter entsprechend der gewünschten Sortierart und Häufigkeit
 * ausgegeben werden. Bei gleicher Häufigkeit wird sie zusätzlich alphabetisch sortiert.<br>
 * <br>
 * Bei Wahl von (9) wird auf dem Bildschirm ausgegeben, wie viel Wörter die Wörterliste enthhält:<br>
 * <br>
 * Die Liste enthaelt 64 Woerter.<br>
 * <br>
 * Bei Wahl von (10) wird die aktuelle Wörterliste1 in eine Textdatei geschrieben, deren
 * Name frei gewählt werden kann. Es wird dabei sichergestellt, dass keine Datei unbeabsichtigt überschrieben wird.<br>
 * <br>
 * Bei Wahl von (11) wird der Name einer Textdatei erfasst, die anschließend analysiert
 * werden kann. Das Programm wird sich auch dann vernünftig verhalten, wenn die Datei nicht
 * vorhanden ist oder nicht geöffnet werden kann.<br>
 * <br>
 * Bei Wahl von (12) wird eine beliebige Textdatei gelesen und deren Inhalt auf dem Bildschirm
 * ausgegeben. Der Name der Textdatei soll über die Tastatur erfasst werden.<br>
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class TextDateiMain {
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
    private TextDateiMain() {
    }

    /**
     * Ueberprueft die Parameter, erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     *
     * @param args <br>Parameter: gibt an, wie die Text-datei heißt bzw. wo diese sich befindet.
     */
    public static void main(String[] args) {
        if (parameterOk(args)) {
            benutzerFuerung(args[0]);
        } else
            schreibeAnleitung();
    }

    /**
     * Ueberprueft die Parameter.
     *
     * @param args <br>Parameter: gibt an, wie die Text-datei heißt bzw. wo diese sich befindet.
     */
    private static boolean parameterOk(String[] args) {
        boolean ok = false;
        if (args.length == 1) {
            try {
                String dateiname = args[0];
                FileReader datei = new FileReader(dateiname);
                ok = true;
                datei.close();
            } catch (FileNotFoundException fnfe) {
                System.err.printf("\nDie Datei konnte nicht gefunden werden.\n");
                fnfe.getMessage();
            } catch (IOException ioe) {
                System.out.print(ioe);
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
                + "Das Programm kann mit einem Parameter gestartet werden:\n"
                + "\nParameter: gibt an, wie der Dateiname, deshalb die Textdatei lautet.\n"
                + "\nBeispiel 1: programname dateiname.txt\n");
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     *
     * @param dateiname Der Dateiname der Text-Datei, die eingelesen und analysiert werden soll.
     */
    private static void benutzerFuerung(String dateiname) {
        Text text = new Text(dateiname);
        int min;
        int max;
        boolean antwort = false;
        String programmMenue[] =
                {
                        "Woerter aufsteigend alphabetisch sortiert",
                        "Woerter mit Haeufigkeit von min bis max aufsteigend alphabetish sortiert",
                        "Woerter absteigend alphabetisch sortiert",
                        "Woerter mit Haeufigkeit von min bis max absteigend alphabetish sortiert",
                        "Woerter absteigend nach Haeufigkeit sortiert",
                        "Woerter mit Haeufigkeit von min bis max absteigend nach Haeufigkeit sortiert",
                        "Woerter aufsteigend nach Haeufigkeit sortiert",
                        "Woerter mit Haeufigkeit von min bis max aufsteigend nach Haeufigkeit sortiert",
                        "Anzahl Woerter feststellen",
                        "Woerterliste speichern",
                        "Neue Woerterliste erzeugen",
                        "Textdatei anzeigen",
                        "Programm beenden"
                };
        do {
            Menue menue = new Menue(programmMenue);
            switch (menue.waehleAusMenue()) {
                case 1:
                    text.schreibeWoerter("Ergebnis der Analyse der Datei " + dateiname + ":", new AufsteigendAlphabetisch());
                    break;
                case 2:
                    min = Eingaben.erfasseInt("Bitte geben Sie die min. Anzahl der Woerter an: ");
                    max = Eingaben.erfasseInt("Bitte geben Sie die max. Anzahl der Woerter an: ", min, text.anzahlWoerter());
                    text.schreibeWoerterMinMax("Ergebnis der Analyse der Datei " + dateiname + ":",
                            new AufsteigendAlphabetisch(), min, max);
                    break;
                case 3:
                    text.schreibeWoerter("Ergebnis der Analyse der Datei " + dateiname + ":", new AbsteigendAlphabetisch());
                    break;
                case 4:
                    min = Eingaben.erfasseInt("Bitte geben Sie die min. Anzahl der Woerter an: ");
                    max = Eingaben.erfasseInt("Bitte geben Sie die max. Anzahl der Woerter an: ", min, text.anzahlWoerter());
                    text.schreibeWoerterMinMax("Ergebnis der Analyse der Datei " + dateiname + ":",
                            new AbsteigendAlphabetisch(), min, max);
                    break;
                case 5:
                    text.schreibeWoerter("Ergebnis der Analyse der Datei " + dateiname + ":", new AbsteigendHaeufigkeit());
                    break;
                case 6:
                    min = Eingaben.erfasseInt("Bitte geben Sie die min. Anzahl der Woerter an: ");
                    max = Eingaben.erfasseInt("Bitte geben Sie die max. Anzahl der Woerter an: ", min, text.anzahlWoerter());
                    text.schreibeWoerterMinMax("Ergebnis der Analyse der Datei " + dateiname + ":", new AbsteigendHaeufigkeit(), min, max);
                    break;
                case 7:
                    text.schreibeWoerter("Ergebnis der Analyse der Datei " + dateiname + ":", new AufsteigendHaeufigkeit());
                    break;
                case 8:
                    min = Eingaben.erfasseInt("Bitte geben Sie die min. Anzahl der Woerter an: ");
                    max = Eingaben.erfasseInt("Bitte geben Sie die max. Anzahl der Woerter an: ", min, text.anzahlWoerter());
                    text.schreibeWoerterMinMax("Ergebnis der Analyse der Datei " + dateiname + ":", new AufsteigendHaeufigkeit(), min, max);
                    break;
                case 9:
                    System.out.printf("%s", text.anzahlWoerterInListe());
                    break;
                case 10:
                    dateiname = Eingaben.erfasseText("Bitte geben Sie ein Dateiname ein: ");
                    Dateienbehandlung.textDateiSpeichern(dateiname, text.liefereWoerter());
                    break;
                case 11:
                    dateiname = Eingaben.erfasseText("Bitte geben Sie einen Namen für die Text-Datei ein: ");
                    String[] name = {dateiname};
                    parameterOk(name);
                    text = new Text(dateiname);
                    break;
                case 12:
                    String textAusDerDatei = Dateienbehandlung.textDateiLaden(Eingaben.erfasseText("Bitte geben Sie ein Dateiname ein: "));
                    System.out.printf("%s", textAusDerDatei);
                    break;
                default:
                    System.out.printf("\nDas Programm wird beendet. See You!\n");
                    antwort = true;
                    break;
            }
        } while (!antwort);
    }
}