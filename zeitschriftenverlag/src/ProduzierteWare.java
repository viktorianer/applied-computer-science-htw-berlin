/**
 * Repraesentiert eine Ware die in einem Unternehmen produziert und verkauft wird.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class ProduzierteWare extends Ware {
    /**
     * Der Name des Herstellers der Ware.
     */
    private String herstellerName;

    /**
     * Erzeugt eine Ware, des bestimmten Herstellers.
     *
     * @param dieWare       Die Ware, die nun durch einen bestimmten Hersteller hergestellt werden soll.
     * @param derHersteller Der Herstellername.
     */
    public ProduzierteWare(Ware dieWare, String derHersteller) {
        super(dieWare);
        if (derHersteller != null)
            herstellerName = derHersteller;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Ware, des bestimmten Herstellers.
     *
     * @param dieWarenNummer Die Warennummer.
     * @param derWarenName   Der Warenname.
     * @param derPreis       Der Preis der Ware.
     * @param derHersteller  Der Herstellername der Ware.
     */
    public ProduzierteWare(int dieWarenNummer, String derWarenName, double derPreis, String derHersteller) {
        super(dieWarenNummer, derWarenName, derPreis);
        if (derHersteller != null)
            herstellerName = derHersteller;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Kopie einer produzierten Ware.
     *
     * @param dieWare Die Ware, die kopiert werden soll.
     */
    public ProduzierteWare(ProduzierteWare dieWare) {
        super(dieWare);
        herstellerName = dieWare.herstellerName;
    }

    /**
     * Liefert den Herstellernamen.
     *
     * @return Der Herstellername.
     */
    public String liefereHersteller() {
        return herstellerName;
    }

    /**
     * Liefert eine tabellarische Ueberuscht der Wareninfo,
     * deshalb die Warennummer, den Warenname, den Preis der Ware und den Herstellername der Ware.
     *
     * @param feldbreite Die Spaltenbreite der Tabelle.
     * @return Eine Formatierte Ausgabe fuer die Ausgabe auf der Konsole.
     */
    @Override
    public String liefereWarenInfo(int feldbreite) {
        return super.liefereWarenInfo(feldbreite) + String.format("%-10s%2s%" + feldbreite + "s\n",
                "Hersteller", ":", herstellerName);
    }

    /**
     * Liefert die laenge des laengsten Attributes der produzierten Ware.
     *
     * @return Die maximale Laenge der Attribute.
     */
    @Override
    public int liefereAttributTextLaenge() {
        return Math.max(super.liefereAttributTextLaenge(), herstellerName.length());
    }
}