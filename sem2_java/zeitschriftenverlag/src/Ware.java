/**
 * Repraesentiert eine Ware.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Ware {
    /**
     * Die Warennummer der Ware
     */
    private int warenNummer;
    /**
     * Die Name der Ware
     */
    private String warenName;
    /**
     * Die Preis der Ware
     */
    private Preis preis;

    /**
     * Erzeugt eine Ware, die eine Warennummer, Namen und Preis hat.
     *
     * @param dieWarenNummer Die Warennummer.
     * @param derWarenName   Der Name der Ware.
     * @param derPreis       Der Preis der Ware.
     */
    public Ware(int dieWarenNummer, String derWarenName, Preis derPreis) {
        boolean inputOk = (0 <= dieWarenNummer && dieWarenNummer <= Integer.MAX_VALUE) &&
                (derWarenName != null) && (derPreis != null);
        if (inputOk) {
            warenNummer = dieWarenNummer;
            warenName = derWarenName;
            preis = derPreis;
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Erzeugt eine Ware, die eine Warennummer, Namen und Preis hat.
     *
     * @param dieWarenNummer Die Warennummer.
     * @param derWarenName   Der Name der Ware.
     * @param derPreis       Der Preis der Ware.
     */
    public Ware(int dieWarenNummer, String derWarenName, double derPreis) {
        this(dieWarenNummer, derWarenName, new Preis(derPreis));
    }

    /**
     * Erzeugt eine Kopie einer Ware.
     *
     * @param eineWare Die Ware, die kopiert werden soll.
     */
    public Ware(Ware eineWare) {
        if (eineWare != null) {
            warenNummer = eineWare.warenNummer;
            warenName = eineWare.warenName;
            preis = new Preis(eineWare.lieferePreis());
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert die Warennummer.
     *
     * @return Die Warennummer.
     */
    public int liefereNummer() {
        return warenNummer;
    }

    /**
     * Liefert den Namen der Ware.
     *
     * @return Der Name der Ware.
     */
    public String liefereNamen() {
        return warenName;
    }

    /**
     * Liefert den Preis der Ware.
     *
     * @return Der Preis der Ware.
     */
    public double lieferePreis() {
        return preis.liefereBruttoPreis();
    }

    /**
     * Liefert den Nettopreis der Ware.
     *
     * @return Der Nettoppreis der Ware.
     */
    public double liefereNettoPreis() {
        return preis.liefereNettoPreis();
    }

    /**
     * Liefert den Mehrwertsteueranteil.
     *
     * @return Der Mehrwertsteueranteil.
     */
    public double liefereMehrwertSteuerAnteil() {
        return preis.liefereMehrwertSteuerAnteil();
    }

    /**
     * Aendert den Preis der Ware.
     *
     * @param derNeuePreis Der neue Preis der Ware.
     */
    public void aenderePreis(double derNeuePreis) {
        if (derNeuePreis >= 0.0)
            preis = new Preis(derNeuePreis);
    }

    /**
     * Liefert eine tabellarische Ueberuscht der Wareninfo,
     * deshalb die Warennummer, den Warenname und den Preis der Ware.
     *
     * @param feldbreite Die Spaltenbreite der Tabelle.
     * @return Eine Formatierte Ausgabe fuer die Ausgabe auf der Konsole.
     */
    public String liefereWarenInfo(int feldbreite) {
        String info = String.format("%-10s%2s%" + feldbreite + "s\n", "Name", ":", warenName);
        info += String.format("%-10s%2s%" + feldbreite + "d\n", "Nummer", ":", warenNummer);
        info += String.format("%-10s%2s%" + feldbreite + ".2f\n", "Preis", ":", lieferePreis());
        return info;
    }

    /**
     * Liefert die laenge des laengsten Attributes der produzierten Ware.
     *
     * @return Die maximale Laenge der Attribute.
     */
    public int liefereAttributTextLaenge() {
        int laenge = Math.max(("" + warenNummer).length(), warenName.length());
        return Math.max(laenge, ("" + lieferePreis()).length());
    }
}