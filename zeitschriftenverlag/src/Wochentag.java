/**
 * Repraesentiert einen Wochentag.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public enum Wochentag {
    SONNTAG(1, "Sonntag"),
    MONTAG(2, "Montag"),
    DIENSTAG(3, "Dienstag"),
    MITTWOCH(4, "Mittwoch"),
    DONNERSTAG(5, "Donnerstag"),
    FREITAG(6, "Freitag"),
    SAMSTAG(7, "Samstag");
    /**
     * Die Kennziffer des Wochentages
     */
    private int id;
    /**
     * Die Bezeichnung des Wochentages
     */
    private String bezeichnung;

    /**
     * Erzeugt Objekte des Typs Wochentag.
     *
     * @param dieID          Die Kennziffer des Wochentages.
     * @param dieBezeichnung Die Bezeichnung des Wochentages
     */
    Wochentag(int dieID, String dieBezeichnung) {
        id = dieID;
        bezeichnung = dieBezeichnung;
    }

    /**
     * Prueft ob ein String (Name) einen bestimmten Wochentag entspricht und damit gueltiger Wochentag ist.
     *
     * @param dieBezeichnung Name des Tages.
     * @return Den Tag der Woche.
     */
    public static Wochentag istGueltigerWochentag(String dieBezeichnung) {
        Wochentag wochentagOK = null;
        for (int i = 0; i < Wochentag.values().length; i++) {
            if (dieBezeichnung.equals(Wochentag.values()[i].liefereBezeichnung()))
                wochentagOK = Wochentag.values()[i];
        }
        return wochentagOK;
    }

    /**
     * Liefert die Kennziffer des bestimmten Wochentages.
     *
     * @return Die Kennziffer des bestimmten Wochentages.
     */
    public int liefereID() {
        return id;
    }

    /**
     * Liefert die Bezeichnung des bestimmten Wochentages.
     *
     * @return Bezeichnung des bestimmten Wochentages.
     */
    public String liefereBezeichnung() {
        return bezeichnung;
    }
}