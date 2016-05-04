/**
 * Repraesentiert eine Fahrkate zum bestimmten Ziel.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Fahrkarte {
    /**
     * Das Ziel, fuer das die Fahrkarte bestimmt ist.
     */
    private Ziel ziel;

    /**
     * Erzeugt eine Fahrkarte mit dem Ziel Bonn.
     */
    public Fahrkarte() {
        ziel = Ziel.pruefeZiel(Ziel.BONN.liefereBezeichnung());
    }

    /**
     * Erzeugt eine Fahrkarte mit dem bestimmten Ziel.
     *
     * @param dasZiel Gibt an, fuer Welches Ziel die Fahrkarte erzeugt werden soll.
     */
    public Fahrkarte(String dasZiel) {
        if (Ziel.pruefeZiel(dasZiel) != null) {
            ziel = Ziel.pruefeZiel(dasZiel);
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert den Preis der Fahrkarte.
     *
     * @return Preis der Fahrkarte.
     */
    public double lieferePreis() {
        return ziel.lieferePreis();
    }

    /**
     * Liefert die Kennziffer der Fahrkarte.
     *
     * @return Kennziffer der Fahrkarte.
     */
    public int liefereKennziffer() {
        return ziel.liefereKennziffer();
    }

    /**
     * Liefert die Bezeichnung/Name des Zieles.
     *
     * @return Bezeichnung/Name des Zieles
     */
    public String liefereBezeichnung() {
        return ziel.liefereBezeichnung();
    }
}