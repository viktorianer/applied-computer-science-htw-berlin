/**
 * Repraesentiert eine Euro-Geldeinheit, die bestimmten Wert hat.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public enum Euro {
    _50(50.0, "50.00 Euro"),
    _20(20.0, "20.00 Euro"),
    _10(10.0, "10.00 Euro"),
    _5(5.0, "5.00 Euro"),
    _2(2.0, "2.00 Euro"),
    _1(1.0, "1.00 Euro"),
    _0_50(0.5, "0.50 Euro"),
    _0_10(0.1, "0.10 Euro"),
    _0_00(00.0, "0.00 Euro");
    /**
     * Der Wert des Euros
     */
    private double wert;
    /**
     * Die Bezeichnung des Euros
     */
    private String bezeichnung;

    /**
     * Erzeugt Objekte des Typs Euro die bestimmten (Geld)-Wert haben.
     *
     * @param derWert        Wert des Euros
     * @param dieBezeichnung Die Bezeichnung des Euros
     */
    Euro(double derWert, String dieBezeichnung) {
        wert = derWert;
        bezeichnung = dieBezeichnung;
    }

    /**
     * Prueft ob eine Gleitkommazahl einen bestimmten Euro entspricht und damit gueltiger Euro-Geld ist.
     *
     * @param derWert Eine Zahl, die geprueft werden soll, ob es einen Euro-Wert entspricht.
     * @return Ist der Wert gueltiges Euro-Geld (true) oder nicht (false).
     */
    public static boolean istGueltigerEuroBetrag(double derWert) {
        boolean geldOK = false;
        for (int i = 0; i < Euro.values().length; i++) {
            if (derWert == Euro.values()[i].liefereWert())
                geldOK = true;
        }
        return geldOK;
    }

    /**
     * Prueft ob eine Bezeichnung einen bestimmten Euro entspricht und damit gueltiger Euro-Geld ist.
     *
     * @param dieBezeichnung Eine Zahl, die geprueft werden soll, ob es einen Euro-Wert entspricht.
     * @return Ist der Wert gueltiges Euro-Geld (true) oder nicht (false).
     * @throws IllegalArgumentException wenn die Bezeichnung nicht vorkommt oder falsch ist.
     */
    public static Euro istGueltigeEuroBezeichnung(String dieBezeichnung) {
        Euro geld = null;
        for (int i = 0; i < Euro.values().length; i++) {
            if (dieBezeichnung.equals(Euro.values()[i].liefereBezeichnung()))
                geld = Euro.values()[i];
        }
        if (geld == null)
            throw new IllegalArgumentException();
        return geld;
    }

    /**
     * Liefert den Wert des bestimmten Euro.
     *
     * @return Wert des bestimmten Euro.
     */
    public double liefereWert() {
        return wert;
    }

    /**
     * Liefert die Bezeichnung des bestimmten Euro.
     *
     * @return Bezeichnung des bestimmten Euro.
     */
    public String liefereBezeichnung() {
        return bezeichnung;
    }
}