/**
 * Repraesentiert ein Wort.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Wort {
    /**
     * Das Wort als String.
     */
    private String wort;
    /**
     * Die Haeufigkeit, mit dieses Wort im Text vorkommt.
     */
    private int anzahl;

    /**
     * Erzeugt ein Wort.
     *
     * @param dasWort
     */
    public Wort(String dasWort) {
        if (dasWort != null || !dasWort.isEmpty()) {
            wort = dasWort;
            anzahl = 1;
        } else
            throw new IllegalArgumentException();

    }

    /**
     * Erhoeht die Haeufigkeit des Wortes.
     */
    public void erhoeheAnzahl() {
        anzahl += 1;
    }

    /**
     * Liefert die Haeufigkeit des Wortes mit dem es im Text vorkommt.
     *
     * @return Die Haeufigkeit des Wortes mit dem es im Text vorkommt.
     */
    public int liefereAnzahl() {
        return anzahl;
    }

    /**
     * Gibt das Wort als String aus.
     *
     * @return Das Wort.
     */
    @Override
    public String toString() {
        return wort;
    }
}