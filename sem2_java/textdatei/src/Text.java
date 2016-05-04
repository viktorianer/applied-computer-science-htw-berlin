import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * Repraesentiert ein Text.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Text {
    /**
     * Der Text, der aus der Datei gelesen wurde und untersucht wird.
     */
    private String text;
    /**
     * Die Wortliste, die im Text vorkommenden Worte.
     */
    private StringTokenizer wortliste;
    /**
     * Die Wortstatistik zum Text.
     */
    private Wortstatistik wortstatistik;

    /**
     * Erzeugt einen Text aus einer TXT-Datei (Plain text).
     *
     * @param derDateiname Der Name der Textdatei.
     */
    public Text(String derDateiname) {
        text = Dateienbehandlung.textDateiLaden(derDateiname);
        wortliste = new StringTokenizer(text, "\n\r\" +,&%$§.:;?!(){}[]");
        wortstatistik = new Wortstatistik(wortliste);
    }

    /**
     * Liefert die Anzahl der Woerter im Text.
     *
     * @return Die Anzahl der Woerter im Text.
     */
    public int anzahlWoerter() {
        return wortstatistik.anzahlWoerter();
    }

    /**
     * Liefert die Anzahl der Woerter in der aktuellen Liste.
     *
     * @return Die Anzahl der Woerter in der aktuellen Liste.
     */
    public String anzahlWoerterInListe() {
        return "\n" + "Die Wortliste enthaelt " + wortstatistik.anzahlUnterschiedlicherWoerter()
                + " unterschiedliche Woerter.\n";
    }

    /**
     * Liefert alle Woerter, die im Text vorkommen in einer Tabellenform.
     *
     * @return Eine Formatierte Tabelle der Woerter, die im Text vorkommen.
     */
    public String liefereWoerter() {
        return wortstatistik.liefereWoerter();
    }

    /**
     * Schreibt alle Woerter, die im Text vorkommen auf dem Bildschirm in einer Tabellenform.
     *
     * @param ueberschrift Die Ueberschrift der Tabelle.
     * @param comparator   Der Comparator, der die Sortierung der Woerter vornimmt.
     */
    public void schreibeWoerter(String ueberschrift, Comparator comparator) {
        System.out.println(ueberschrift);
        wortstatistik.schreibeWoerterSortiert(comparator);
    }

    /**
     * Schreibt alle Woerter mit einer min - max Haeufigkeit, die im Text vorkommen auf dem Bildschirm in einer Tabellenform.
     *
     * @param ueberschrift Die Ueberschrift der Tabelle.
     * @param comparator   Der Comparator, der die Sortierung der Woerter vornimmt.
     * @param min          Die minimale gewuenschte Haeufigkeit.
     * @param max          Die maximale gewuenschte Haeufigkeit.
     */
    public void schreibeWoerterMinMax(String ueberschrift, Comparator comparator, int min, int max) {
        System.out.println(ueberschrift);
        wortstatistik.schreibeWoerterMinMaxSortiert(comparator, min, max);
    }
}