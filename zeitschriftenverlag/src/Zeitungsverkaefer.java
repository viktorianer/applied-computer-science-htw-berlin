import java.util.ArrayList;

/**
 * Repraesentiert einen Zeitungsverkaefer, der eine bestimmte Anzahl an Zeitungen in der Woche verkauft und
 * zur jeder Zeitung eine Wochenstatistik fuert.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Zeitungsverkaefer extends Angestellter implements Comparable<Zeitungsverkaefer> {
    /**
     * Die Zeitungen, die der Zeitungsverkaefer verkauft.
     */
    private ArrayList<Zeitung> zeitungen;
    /**
     * Die Wochenstatistiken zu jeder Zeitungen.
     */
    private ArrayList<Wochenstatistik> wochenstatistik;

    /**
     * Erzeugt einen Zeitungsverkaefer, der eine bestimmte Anzahl an Zeitungen in der Woche verkauft und
     * zur jeder Zeitung eine Wochenstatistik fuert.
     *
     * @param dieZeitungen Die Zeitungen, die der Zeitungsverkaefer verkaufen soll.
     */
    public Zeitungsverkaefer(ArrayList<Zeitung> dieZeitungen) {
        super(0.0);
        zeitungen = new ArrayList<>(0);
        wochenstatistik = new ArrayList<>(0);
        for (Zeitung zeitung : dieZeitungen) {
            zeitungen.add(new Zeitung(zeitung));
            wochenstatistik.add(new Wochenstatistik(zeitung));
        }
        ermitteleVerdienst();
    }

    /**
     * Liefert eine Tagesstatistik (Anzahl der verkauften Exemplare) zum bestimmten Tag und zur bestimmten Zeitung.
     *
     * @param derTag     Der Tag, fuer dem eine Tagesstatistik zurueckgegeben werden soll.
     * @param dieZeitung Die Zeitung, fuer die die Tagesstatistik zurueckgegeben werden soll.
     * @return Die Tagesstatistik (Anzahl der verkauften Exemplare).
     */
    public int liefereTagesstatistik(Wochentag derTag, Zeitung dieZeitung) {
        return wochenstatistik.get(dieZeitung.liefereNummer() - 1).liefereTagesstatistik(derTag);
    }

    /**
     * Liefert eineen Tagesumsatz (Anzahl der verkauften Exemplare * Preis) zum bestimmten Tag und zur bestimmten Zeitung.
     *
     * @param derTag     Der Tag, fuer dem der Tagesumsatz zurueckgegeben werden soll.
     * @param dieZeitung Die Zeitung, fuer die der Tagesumsatz zurueckgegeben werden soll.
     * @return Der Tagesumsatz (Anzahl der verkauften Exemplare * Preis).
     */
    public double liefereTagesumsatz(Wochentag derTag, Zeitung dieZeitung) {
        return wochenstatistik.get(dieZeitung.liefereNummer() - 1).liefereTagesumsatz(derTag);
    }

    /**
     * Standard Methode, um zwei Zeitungsverkaefer nach ihren Verdienst zu vergleichen.
     *
     * @param derZeitungsverkaefer Der Zeitungsverkaefer, der mit diesen (this) verglichen wird.
     * @return Liefert 0 (Verdienst ist gleich), -1 (Verdienst ist kleiner) oder 1 (Verdienst ist grosser).
     */
    public int compareTo(Zeitungsverkaefer derZeitungsverkaefer) {
        return Double.compare(derZeitungsverkaefer.liefereVerdienst(), this.liefereVerdienst());
    }

    /**
     * Ermittelt den Verdienst des Zeitungsverkaefers.
     */
    private void ermitteleVerdienst() {
        for (Wochenstatistik wochenstatistik : this.wochenstatistik) {
            this.setzeVerdienst(this.liefereVerdienst() + wochenstatistik.liefereWochenverdienst());
        }
    }
}