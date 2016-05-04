import java.util.ArrayList;

/**
 * Repraesentiert eine Wochenstatistik, deshalb Verkaufszahlen einer bestimmten Zeitung fuer eine ganze Woche.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Wochenstatistik {
    /**
     * Die Zeitungen, die verkauft wird.
     */
    private Zeitung zeitung;
    /**
     * Die Tagesstatistiken fuer jeden Tag der Woche.
     */
    private ArrayList<Tagesstatistik> tagesstatistiken;

    /**
     * Erzeugt eine Wochenstatistik fuer eine bestimmte Zeitung.
     *
     * @param dieZeitung Die Zeitung, fuer die eine Wochenstatistik erzeugt werden soll.
     */
    public Wochenstatistik(Zeitung dieZeitung) {
        if (dieZeitung != null) {
            zeitung = dieZeitung;
            tagesstatistiken = new ArrayList<>(0);
            for (int i = 0; i < Wochentag.values().length; i++) {
                tagesstatistiken.add(new Tagesstatistik(55));
            }
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert die Zeitung, fuer die die Wochenstatistik gillt.
     *
     * @return Die Zeitung fuer die die Wochenstatistik gillt.
     */
    public String liefereZeitung() {
        return "" + zeitung.liefereNamen();
    }

    /**
     * Liefert eine Tagesstatistik (Anzahl der verkauften Exemplare) zum bestimmten Tag.
     *
     * @param derTag Der Tag, fuer dem eine Tagesstatistik zurueckgegeben werden soll.
     * @return Die Tagesstatistik (Anzahl der verkauften Exemplare).
     */
    public int liefereTagesstatistik(Wochentag derTag) {
        return tagesstatistiken.get(derTag.liefereID() - 1).liefereTagesstatistik();
    }

    /**
     * Liefert eineen Tagesumsatz (Anzahl der verkauften Exemplare * Preis) zum bestimmten Tag.
     *
     * @param derTag Der Tag, fuer dem eine Tagesstatistik zurueckgegeben werden soll.
     * @return Der Tagesumsatz (Anzahl der verkauften Exemplare * Preis).
     */
    public double liefereTagesumsatz(Wochentag derTag) {
        return tagesstatistiken.get(derTag.liefereID() - 1).liefereTagesstatistik() * zeitung.lieferePreis();
    }

    /**
     * Liefert den Wochenverdienst, der durch dem Verkauf der Zeitung in dieser Woche erzielt wurde.
     *
     * @return Der Wochenverdienst, der duch dem Verkauf der Zeitung in dieser Woche erzielt wurde.
     */
    public double liefereWochenverdienst() {
        double wochenverdienst = 0.0;
        for (Tagesstatistik tagesstatistik : tagesstatistiken) {
            wochenverdienst += tagesstatistik.liefereTagesstatistik() * zeitung.lieferePreis() * zeitung.liefereLohnAnteil();
        }
        return wochenverdienst;
    }
}