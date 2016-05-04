/**
 * Repraesentiert eine Statistik fuer Verkaufte Medien.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class MedienVerkaufsStatistik implements Comparable<MedienVerkaufsStatistik> {
    /**
     * Das Medium, zu dem eine Verkaufsstatistik gefuert wird (pro Tag).
     */
    private Medium medium;
    /**
     * Die Anzahl der Verkaufe am Tag
     */
    private int anzahlVerkaefe;
    /**
     * Der Umsatz am Tag
     */
    private double umsatz;

    /**
     * Erzeugt eine Verkaufsstatistik zu bestimmten Medien mit bestimmten Anzahl an Verkaeufen..
     *
     * @param dasMedium          Das Medium, das verkauft wurde.
     * @param dieAnzahlVerkaeufe Wie oft das Medium verkauft wurde.
     */
    public MedienVerkaufsStatistik(Medium dasMedium, int dieAnzahlVerkaeufe) {
        if (anzahlVerkaefe >= 0 && dasMedium != null) {
            medium = dasMedium;
            anzahlVerkaefe = dieAnzahlVerkaeufe;
            umsatz = medium.liefereBruttoPreis() * anzahlVerkaefe;
        } else {
            throw new IllegalArgumentException();
        }
    }

    /**
     * Liefert den Umsatz, der mit einem bestimmten Medium erzielt wurde.
     *
     * @return Umsatz des Mediums.
     */
    public double lieferUmsatz() {
        return umsatz;
    }

    /**
     * Standard Methode, die es erlaubt die Objekte dieser Klasse vergleichbar, nach Umsatz, zu machen.
     *
     * @param eineMediumVerkaufsStatistik Eine Medium-Verkaufsstatistik die mit dieser verglichen (Umsatz) werden soll.
     * @return Liefert gleich (0), kleiner (-1) oder groesser (1).
     */
    public int compareTo(MedienVerkaufsStatistik eineMediumVerkaufsStatistik) {
        return Double.compare(eineMediumVerkaufsStatistik.lieferUmsatz(), this.lieferUmsatz());
    }

    /**
     * Liefert einen formatierten String mit Verkaufsinformationen zum Medium.
     *
     * @return Verkaufsinformationen zum Medium.
     */
    @Override
    public String toString() {
        return String.format("%-60s%s%2d * %6.2f EURO = %6.2f", medium.toString(), ":", anzahlVerkaefe, medium.liefereBruttoPreis(),
                anzahlVerkaefe * medium.liefereBruttoPreis());
    }
}
