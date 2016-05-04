/**
 * Repraesentiert eine Zeitung die in einem Verlag produziert und verkauft wird.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Zeitung extends ProduzierteWare {
    /**
     * Der Lohnanteil an der Zeitung fuer einen Verkaefer.
     */
    private double lohnAnteil;

    /**
     * Erzeugt eine Zeitung, die eine Ware ist, bestimmten Hersteller gehoert und einen Lohnanteil hat.
     *
     * @param dieWare       Die Ware, die eine Zeitung ist.
     * @param derHersteller Der Verlag, der diese Zeitung produzieren und verkaufen soll.
     * @param derLohnAnteil Der Lohnanteil fuer den Verkaefer.
     */
    public Zeitung(Ware dieWare, String derHersteller, double derLohnAnteil) {
        super(dieWare, derHersteller);
        if (derLohnAnteil >= 0.0 && derLohnAnteil <= 1)
            lohnAnteil = derLohnAnteil;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Zeitung, die eine ProduzierteWare ist und einen Lohnanteil hat.
     *
     * @param dieWare       Die Ware, die eine Zeitung ist.
     * @param derLohnAnteil Der Lohnanteil fuer den Verkaefer.
     */
    public Zeitung(ProduzierteWare dieWare, double derLohnAnteil) {
        super(dieWare);
        if (derLohnAnteil >= 0.0 && derLohnAnteil <= 1)
            lohnAnteil = derLohnAnteil;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Zeitung.
     *
     * @param dieWarenNummer Die Warennummer.
     * @param derWarenName   Der Zeitungsname.
     * @param derPreis       Der Preis der Zeitung.
     * @param derHersteller  Der Verlag.
     * @param derLohnAnteil  Der Lohnanteil.
     */
    public Zeitung(int dieWarenNummer, String derWarenName, double derPreis, String derHersteller, double derLohnAnteil) {
        super(dieWarenNummer, derWarenName, derPreis, derHersteller);
        if (derLohnAnteil >= 0.0 && derLohnAnteil <= 1)
            lohnAnteil = derLohnAnteil;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Kopie einer Zeitung.
     *
     * @param dieZeitung Die Zeitung, die kopiert werden soll.
     */
    public Zeitung(Zeitung dieZeitung) {
        super(dieZeitung);
        lohnAnteil = dieZeitung.lohnAnteil;
    }

    /**
     * Liefert den Lohnanteil an der Zeitung.
     *
     * @return Lohnanteil an der Zeitung.
     */
    public double liefereLohnAnteil() {
        return lohnAnteil;
    }

    /**
     * Liefert eine tabellarische Ueberuscht der Wareninfo,
     * deshalb die Warennummer, den Warenname, den Preis der Ware, den Herstellername der Ware und den Lohnanteil der Ware.
     *
     * @param feldbreite Die Spaltenbreite der Tabelle.
     * @return Eine Formatierte Ausgabe fuer die Ausgabe auf der Konsole.
     */
    @Override
    public String liefereWarenInfo(int feldbreite) {
        return super.liefereWarenInfo(feldbreite) + String.format("%-10s%2s%" + feldbreite + ".2f%%\n",
                "Lohnanteil", ":", lohnAnteil * 100);
    }

    /**
     * Liefert die laenge des laengsten Attributes der Zeitung.
     *
     * @return Die maximale Laenge der Attribute.
     */
    @Override
    public int liefereAttributTextLaenge() {
        return Math.max(super.liefereAttributTextLaenge(), ("" + lohnAnteil).length());
    }
}