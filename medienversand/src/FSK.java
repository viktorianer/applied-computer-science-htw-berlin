/**
 * Repraesentiert ein Altersfreigabe (FSK) in Deutschland.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public enum FSK {
    AB6(6, "FSK6"),
    AB12(12, "FSK12"),
    AB16(16, "FSK16"),
    AB18(18, "FSK18");
    /**
     * Die Zahl, die fuer Altersfreigabe steht
     */
    private int altersfreigabe;
    /**
     * Die Bezeichnung, die fuer Altersfreigabe steht
     */
    private String fsk;

    /**
     * Erzeugt Objekte des Typs FSK.
     *
     * @param dieAltersfreigabe Die Altersfreigabe als Zahl.
     * @param dieFSK            Die Altersfreigabe als String.
     */
    FSK(int dieAltersfreigabe, String dieFSK) {
        altersfreigabe = dieAltersfreigabe;
        fsk = dieFSK;
    }

    /**
     * Liefert die Altersfreigabe.
     *
     * @return Die Altersfreigabe.
     */
    public int liefereAltersfreigabe() {
        return altersfreigabe;
    }
}
