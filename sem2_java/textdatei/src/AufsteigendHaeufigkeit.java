import java.util.Comparator;

/**
 * Sortiert Woerter aufsteigend nach der Haeufigkeit.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
class AufsteigendHaeufigkeit implements Comparator<Wort> {
    /**
     * Sortiert Woerter aufsteigend nach Haeufigkeit. Bei gleicheit werden diese zusaetzlich nach dem Wert,
     * der durch toString() geliefert wird, sortiert.
     *
     * @param erstesWort  Das erste Wort, das verglichen wird.
     * @param zweitesWort Das zweite Wort, das verglichen wird.
     * @return Liefert beim Vergleich der Worte 1 wenn das zweite großer, -1 wenn das erste großer und 0
     * wenn beide gleich haeufig vorkommen.
     */
    public int compare(Wort erstesWort, Wort zweitesWort) {
        int rueckgabe = 0;
        try {
            if (erstesWort.liefereAnzahl() > zweitesWort.liefereAnzahl())
                rueckgabe = 1;
            else if (erstesWort.liefereAnzahl() < zweitesWort.liefereAnzahl())
                rueckgabe = -1;
            else
                rueckgabe = erstesWort.toString().compareTo(zweitesWort.toString());
        } catch (ClassCastException cce) {
            System.out.println("Zu vergleichende Objekte sind invalid.");
        }
        return rueckgabe;
    }
}