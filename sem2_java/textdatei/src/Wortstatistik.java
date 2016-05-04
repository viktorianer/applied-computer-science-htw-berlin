import java.util.*;

/**
 * Repraesentiert ein Wortstatistik zum bestimmten Text.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Wortstatistik {
    /**
     * Die Zuweisungstabelle mit allen Woerter im Text und deren Schluessel.
     */
    private HashMap<String, Wort> wortTabelle;
    /**
     * Die Zusammenstellung der Woerter, die aktuell bearbeitet der ausgegeben wird.
     */
    private TreeSet<Wort> wortSet;

    /**
     * Erzeugt Wortstatistik ueber Menge einer Wortliste.
     *
     * @param wortliste Die Wortliste, fuer die eine Wortstatistik erstellt werden soll.
     */
    public Wortstatistik(StringTokenizer wortliste) {
        wortTabelle = new HashMap<>(0);
        wortTabelle = worthaeufigkeit(wortliste);
        wortSet = new TreeSet<>();
    }

    /**
     * Prueft die Worthaeufigkeit der Woerter in der Wortliste und erstellt dazu eine Zuweisungstabelle.
     *
     * @param wortliste Die Wortliste, fuer die die Worthaeufigkeit bestimmt wird.
     * @return Die Worthaeufigkeit der Woerter in der Wortliste
     */
    private HashMap<String, Wort> worthaeufigkeit(StringTokenizer wortliste) {
        while (wortliste.hasMoreTokens()) {
            String wort = wortliste.nextToken();
            if (!wortTabelle.containsKey(wort)) {
                wortTabelle.put(wort, new Wort(wort));
            } else {
                wortTabelle.get(wort).erhoeheAnzahl();
            }
        }
        return wortTabelle;
    }

    /**
     * Liefert die Anzahl der Woerter im Text.
     *
     * @return Die Anzahl der Woerter im Text.
     */
    public int anzahlWoerter() {
        return wortTabelle.size();
    }

    /**
     * Liefert die Anzahl der Woerter in der aktuellen Liste.
     *
     * @return Die Anzahl der Woerter in der aktuellen Liste.
     */
    public int anzahlUnterschiedlicherWoerter() {
        return wortSet.size();
    }

    /**
     * Liefert alle Woerter, die im Text vorkommen in einer Tabellenform.
     *
     * @return Eine Formatierte Tabelle der Woerter, die im Text vorkommen.
     */
    public String liefereWoerter() {
        String ausgabe = "";
        for (Wort wort : wortSet) {
            ausgabe += String.format("%-30s%d", wort.toString(), wort.liefereAnzahl()) + "\n";
        }
        return ausgabe;
    }

    /**
     * Liefert alle Woerter, die im Text vorkommen in einer sortierten Tabellenform. Das Sortierverfahren wird durch
     * einen externen Comparator gesteuert.
     *
     * @param comparator Der Comparator, der den Vergleich durchfuert.
     */
    public void schreibeWoerterSortiert(Comparator comparator) {
        wortSet = new TreeSet<>(comparator);
        for (String s : wortTabelle.keySet()) wortSet.add(wortTabelle.get(s));

        ausgabeWoerter();
    }

    /**
     * Liefert alle Woerter, die im Text vorkommen in einer sortierten Tabellenform. Das Sortierverfahren wird durch
     * einen externen Comparator gesteuert. Zusaetzlich wird die Liste auf bestimmte Haeifigkeuten ueberprueft.
     *
     * @param comparator Der Comparator, der den Vergleich durchfuert.
     * @param min        Die minimale gewuenschte Haeufigkeit.
     * @param max        Die maximale gewuenschte Haeufigkeit.
     */
    public void schreibeWoerterMinMaxSortiert(Comparator comparator, int min, int max) {
        wortSet = new TreeSet<>(comparator);
        Iterator<String> tabellenIterator = wortTabelle.keySet().iterator();
        Wort wort;
        while (tabellenIterator.hasNext()) {
            wort = wortTabelle.get(tabellenIterator.next());
            if (min <= wort.liefereAnzahl() && wort.liefereAnzahl() <= max)
                wortSet.add(wort);
        }
        ausgabeWoerter();
    }

    /**
     * Gibt die Woerter einer Wortliste auf dem Bildschirm aus.
     */
    private void ausgabeWoerter() {
        for (Wort wort : wortSet) {
            System.out.printf("%-30s%d\n", wort.toString(), wort.liefereAnzahl());
        }
    }
}