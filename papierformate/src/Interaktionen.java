import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Repraesentiert ein Datum, das aus Tag (1 - 31),
 * Monat (1  12) und Jahr besteht (ganze Zahl).
 *
 * @author H. Brandenburg
 */
public class Interaktionen {
    /**
     * Der Tag des Datums.
     */
    private static BufferedReader eingabe =
            new BufferedReader(new InputStreamReader(System.in));

    /**
     * Erzeugt das aktuelle Datum, d.h. das aktuell im
     * Rechner vorhandene Datum.
     */
    private Interaktionen() {

    }

    /**
     * Liefert das Datum in der Form <code>tt.mm.jjjj</code>.
     *
     * @return Das Datum in der Form <code>tt.mm.jjjj</code>.
     */
    public static String erfasseText(String eingabeAufforderung, String eingabeFormat) {
        String text = "";
        boolean eingabeOk = false;
        while (!eingabeOk) {
            text = erfasseText(eingabeAufforderung);
            eingabeOk = text.matches(eingabeFormat);
        }
        return text;
    }

    public static String erfasseText() {
        return erfasseText("");
    }

    public static String erfasseText(String eingabeAufforderung) {
        System.out.print(eingabeAufforderung);
        String text = "";
        boolean eingabeOk = false;
        while (!eingabeOk)
            try {
                text = eingabe.readLine();
                eingabeOk = true;
            } catch (IOException ioe) {
                System.out.print(ioe);
            }
        return text;
    }

    public static int erfasseInt() {
        return erfasseInt("");
    }

    public static int erfasseInt(String eingabeAufforderung) {
        int wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk)
            try {
                wert = Integer.parseInt(erfasseText(eingabeAufforderung));
                eingabeOk = true;
            } catch (NumberFormatException nfe) {
                System.out.print(nfe);
            }
        return wert;
    }

    public static int erfasseInt(String eingabeAufforderung,
                                 int min,
                                 int max) {
        int wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk) {
            wert = erfasseInt(eingabeAufforderung);
            eingabeOk = (min <= wert && wert <= max);
        }
        return wert;
    }

    /**
     * die entsprechenden Methoden zur Eingabe von double-Werten sollten Sie zur Übung selbst schreiben.
     */
    public static double erfasseDouble() {
        return erfasseDouble("");
    }

    public static double erfasseDouble(String eingabeAufforderung) {
        double wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk)
            try {
                wert = Double.parseDouble(erfasseText(eingabeAufforderung));
                eingabeOk = true;
            } catch (NumberFormatException nfe) {
                System.out.print(nfe);
            }
        return wert;
    }

    public static double erfasseDouble(String eingabeAufforderung, double min, double max) {
        double wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk) {
            wert = erfasseDouble(eingabeAufforderung);
            eingabeOk = (min <= wert && wert <= max);
        }
        return wert;
    }
}