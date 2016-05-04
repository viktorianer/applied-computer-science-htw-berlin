import java.util.Comparator;

/**
 * Sortiert Objekte aufsteigend nach dem Wert, der durch toString() geliefert wird.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
class AufsteigendAlphabetisch implements Comparator {
    /**
     * Sortiert Objekte aufsteigend nach dem Wert, der durch toString() geliefert wird.
     *
     * @param erstesObjekt  Das erste Objekt, das verglichen wird.
     * @param zweitesObjekt Das zweite Objekt, das verglichen wird.
     * @return Liefert beim Vergleich der Objekte 1 wenn das erste großer, -1 wenn das zweite großer und 0 wenn beide gleich sind.
     */
    public int compare(Object erstesObjekt, Object zweitesObjekt) {
        return erstesObjekt.toString().compareTo(zweitesObjekt.toString());
    }
}