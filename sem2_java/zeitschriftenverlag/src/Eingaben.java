import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Repraesentiert ein Sammelklasse fuer Ausgaben.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public final class Eingaben {
    /**
     * Die standard Ausgabe
     */
    private final static String STANDARD_EINGABE_AUFFORDERUNG = "";
    /**
     * Die Eingabe des Benutzer.
     */
    private static BufferedReader eingabe =
            new BufferedReader(new InputStreamReader(System.in));

    /**
     * Erzeugt keine Objekte sondern stellt nur die allgemeinen Eingaben-Methoden bereit.
     * Von dieser Klasse können keine Objekte Erzeugt werden!
     */
    private Eingaben() {

    }

    /**
     * Erfasst ein Text ohne eine Eingabeaufforderung.
     *
     * @return Die erfasste Eingabe, Text wird zurueckgegeben.
     */
    public static String erfasseText() {
        return erfasseText(STANDARD_EINGABE_AUFFORDERUNG);
    }

    /**
     * Erfasst ein Text mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text der als eine Eingabeaufforderung ausgegeben wird.
     * @return Die erfasste Eingabe, Text wird zurueckgegeben.
     */
    public static String erfasseText(String eingabeAufforderung) {
        System.out.print(eingabeAufforderung);
        String text = "";
        boolean eingabeOk = false;
        while (!eingabeOk) {
            try {
                text = eingabe.readLine();
                eingabeOk = true;
            } catch (IOException ioe) {
                System.out.printf("\nDie Eingabe konnte nicht gelesen werden.");
            }
        }
        return text;
    }

    /**
     * Erfasst ein Text in einem bestimmten Format und mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text, der als eine Eingabeaufforderung ausgegeben wird.
     * @param eingabeFormat       Das Eingabeformat, mit dem die Eingabe geprueft werden soll.
     * @return Die erfasste Eingabe, Text wird zurueckgegeben.
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

    /**
     * Erfasst ein Text in einem bestimmten Format und mit einer Eingabeaufforderung. Bei falschen Eingabe wird
     * eine Fehlermeldung ausgegeben.
     *
     * @param eingabeAufforderung Der Text, der als eine Eingabeaufforderung ausgegeben wird.
     * @param eingabeFormat       Das Eingabeformat, mit dem die Eingabe geprueft werden soll.
     * @param fehlerText          Der Text, der bei der falschen Eingabe als Fehlermeldung erscheint.
     * @return Die erfasste Eingabe, Text wird zurueckgegeben.
     */
    public static String erfasseText(String eingabeAufforderung, String eingabeFormat, String fehlerText) {
        String text = "";
        boolean eingabeOk = false;
        while (!eingabeOk) {
            text = erfasseText(eingabeAufforderung);
            eingabeOk = text.matches(eingabeFormat);
            if (!eingabeOk)
                System.out.printf(fehlerText);
        }
        return text;
    }

    /**
     * Erfasst eine ganze Zahl ohne einer Eingabeaufforderung.
     *
     * @return Die erfasste Eingabe, ganze Zahl wird zurueckgegeben.
     */
    public static int erfasseInt() {
        return erfasseInt(STANDARD_EINGABE_AUFFORDERUNG);
    }

    /**
     * Erfasst eine ganze Zahl mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text der als eine Eingabeaufforderung ausgegeben wird.
     * @return Die erfasste Eingabe, ganze Zahl wird zurueckgegeben.
     */
    public static int erfasseInt(String eingabeAufforderung) {
        int wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk) {
            try {
                wert = Integer.parseInt(erfasseText(eingabeAufforderung));
                eingabeOk = true;
            } catch (NumberFormatException nfe) {
                System.out.printf("\nDie Eingabe ist keine ganze Zahl.");
            }
        }
        return wert;
    }

    /**
     * Erfasst eine ganze Zahl, die im Bereich von min bis max liegt, mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text der als eine Eingabeaufforderung ausgegeben wird.
     * @param min                 Die min. ganze Zahl die eingegeben werden kann.
     * @param max                 Die max. ganze Zahl die eingegeben werden kann.
     * @return Die erfasste Eingabe, ganze Zahl wird zurueckgegeben.
     */
    public static int erfasseInt(String eingabeAufforderung, int min, int max) {
        int wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk) {
            wert = erfasseInt(eingabeAufforderung);
            eingabeOk = (min <= wert && wert <= max);
        }
        return wert;
    }

    /**
     * Erfasst eine Gleitkommazahl, die im Bereich von min bis max liegt, ohne einer Eingabeaufforderung.
     *
     * @return Die erfasste Eingabe, Gleitkommazahl wird zurueckgegeben.
     */
    public static double erfasseDouble() {
        return erfasseDouble(STANDARD_EINGABE_AUFFORDERUNG);
    }

    /**
     * Erfasst eine Gleitkommazahl, die im Bereich von min bis max liegt, mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text der als eine Eingabeaufforderung ausgegeben wird.
     * @return Die erfasste Eingabe, Gleitkommazahl wird zurueckgegeben.
     */
    public static double erfasseDouble(String eingabeAufforderung) {
        double wert = 0;
        boolean eingabeOk = false;
        while (!eingabeOk)
            try {
                wert = Double.parseDouble(erfasseText(eingabeAufforderung));
                eingabeOk = true;
            } catch (NumberFormatException nfe) {
                System.out.printf("\nDie Eingabe ist keine Gleitkommazahl (Format 0.0).");
            }
        return wert;
    }

    /**
     * Erfasst eine Gleitkommazahl, die im Bereich von min bis max liegt, mit einer Eingabeaufforderung.
     *
     * @param eingabeAufforderung Der Text der als eine Eingabeaufforderung ausgegeben wird.
     * @param min                 Die min. Gleitkommazahl die eingegeben werden kann.
     * @param max                 Die max. Gleitkommazahl die eingegeben werden kann.
     * @return Die erfasste Eingabe, Gleitkommazahl wird zurueckgegeben.
     */
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