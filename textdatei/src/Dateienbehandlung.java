import java.io.*;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Repraesentiert ein Sammelklasse fuer die Behandlung von Dateienzugriffe - Ein- und Ausgabe.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public final class Dateienbehandlung {
    /**
     * Erzeugt keine Objekte sondern stellt nur die allgemeinen Ein- und Ausgabe-Methoden,
     * fuer die Behandlung von Dateienzugriffe, bereit.
     * Von dieser Klasse können keine Objekte Erzeugt werden!
     */
    private Dateienbehandlung() {

    }

    /**
     * Speichert einen Objekt in eine Datei (serialesierung)
     *
     * @param objekt    Das Objekt, welches gespeichert werden soll.
     * @param dateiName Der Name der Datei.
     */
    public static void speichern(Object objekt, String dateiName) {
        try {
            ObjectOutputStream objektAusgabe = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(dateiName)));
            objektAusgabe.writeObject(objekt);
            objektAusgabe.close();
        } catch (FileNotFoundException fnfe) {
            System.err.printf("\nDie Datei konnte nicht erstellt werden.\n");
            fnfe.getMessage();
        } catch (IOException ioe) {
            System.out.print(ioe);
        }
    }

    /**
     * Laed einen Objekt aus einer Datei (serialesierung).
     *
     * @param dateiName Der Name der Datei.
     * @return Objekt, welches aus der Datei gelesen wurde.
     */
    public static Object laden(String dateiName) {
        Object objekt = null;
        try {
            ObjectInputStream objektEingabe = new ObjectInputStream(new BufferedInputStream(new FileInputStream(dateiName)));
            objekt = objektEingabe.readObject();
            objektEingabe.close();
        } catch (FileNotFoundException fnfe) {
            System.err.printf("\nDie Datei konnte nicht gefunden werden.\n");
            fnfe.getMessage();
        } catch (IOException ioe) {
            System.err.printf("Die Datei " + dateiName + " konnte nicht gefunden werden.");
        } catch (ClassNotFoundException cnfe) {
            System.out.print(cnfe);
        }
        return objekt;
    }

    /**
     * Laed einen Text aus einer Datei.
     *
     * @param dateiName Der Name der Datei.
     * @return Text, welches aus der Datei gelesen wurde.
     */
    public static String textDateiLaden(String dateiName) {
        String text = "";
        try {
            Scanner scanner = new Scanner(new FileReader(dateiName));
            scanner.useDelimiter("\\Z");
            text = scanner.next();
            scanner.close();
        } catch (FileNotFoundException fnfe) {
            System.err.printf("\nDie Datei konnte nicht gefunden werden.\n");
            fnfe.getMessage();
        } catch (NoSuchElementException nsee) {
            System.err.printf("\nDie Datei ist leer...\n");
            nsee.getMessage();
        } catch (IllegalStateException ise) {
            System.err.printf("\nDer Vorgang wurde aus unbekannten Gruenden beendet.\n");
            ise.getMessage();
        }
        return text;
    }

    /**
     * Speichert einen Text in eine Datei.
     *
     * @param dateiName Der Name der Datei.
     * @param text      Der zu speichernde Text.
     */
    public static void textDateiSpeichern(String dateiName, String text) {
        try {
            File datei = new File(dateiName);
            if (!datei.exists() || Eingaben.erfasseText("Die Datei existiert bereits. Falls Sie diese ueberschreiben moechten, "
                    + "geben Sie \"Ja\" ein. ").toLowerCase().charAt(0) == 'j') {
                FileWriter dateiSchreiber = new FileWriter(datei);
                dateiSchreiber.write(text);
                dateiSchreiber.close();
                System.out.printf("\nDatei wurde geschrieben\n");
            } else {
                System.out.println("Die Datei wurde nicht geschrieben.");
            }

        } catch (IOException ioe) {
            System.err.printf("\nDie Datei konnte nicht geschrieben werden.\n");
            ioe.getMessage();
        }
    }
}
