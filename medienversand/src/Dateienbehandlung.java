import java.io.*;

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
}
