/**
 * Repraesentiert die Fahrtziele, die ein Fahrkartenautomat anbieten kann.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public enum Ziel {
    MUENCHEN(165.50, 1, "Muenchen"),
    STUTTGART(180.10, 2, "Stuttgart"),
    HAMBURG(90.00, 3, "Hamburg"),
    HANNOVER(85.00, 4, "Hannover"),
    BONN(151.00, 5, "Bonn"),
    FRANKFURT_AM_MAIN(172.10, 6, "Frankfurt am Main"),
    KOELN(143.70, 7, "Koeln"),
    KIEL(97.20, 8, "Kiel"),
    OLDENBURG(111.30, 9, "Oldenburg"),
    KONSTANZ(220.20, 10, "Konstanz");
    private Preis preis;
    private int kennziffer;
    private String bezeichnung;

    /**
     * Erzeugt Ziele, die eine Kennziffer (ID), Bezeichnung und Preis haben.
     *
     * @param derPreis       Preis der Fahrt zum bestimmten Ziel.
     * @param dieKennziffer  Die Kennziffer (ID) des Zieles.
     * @param dieBezeichnung Die Bezeichnung des Zielortes.
     */
    Ziel(double derPreis, int dieKennziffer, String dieBezeichnung) {
        preis = new Preis(derPreis);
        kennziffer = dieKennziffer;
        bezeichnung = dieBezeichnung;
    }

    /**
     * Ueberprueft, ob das Ziel vorhanden ist und damit Gueltig ist.
     *
     * @param zielEingabe Der Name des Zieles.
     * @return Das Ziel oder null wenn das Ziel ungueltig ist.
     */
    public static Ziel pruefeZiel(String zielEingabe) {
        Ziel[] ziele = Ziel.values();
        Ziel dasZiel = null;
        for (int i = 0; i < ziele.length; i++) {
            if (ziele[i].liefereBezeichnung().equals(zielEingabe)) {
                dasZiel = ziele[i];
                i = ziele.length;
            }
        }
        return dasZiel;
    }

    /**
     * Liefert den Preis des Zieles.
     *
     * @return Preis des Zieles.
     */
    public double lieferePreis() {
        return preis.liefereBruttoPreis();
    }

    /**
     * Liefert die Kennziffer (ID) des Zieles.
     *
     * @return Kennziffer (ID) des Zieles.
     */
    public int liefereKennziffer() {
        return kennziffer;
    }

    /**
     * Liefert die Bezeichnung (Namen) des Zieles.
     *
     * @return Bezeichnung (Namen) des Zieles.
     */
    public String liefereBezeichnung() {
        return bezeichnung;
    }
}