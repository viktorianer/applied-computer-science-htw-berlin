public enum PapierFormat {
    DINA0(841, 1189, "Doppelbogen"), DINA1(594, 841, "Bogen"),
    DINA2(420, 594, "Halbbogen"), DINA3(297, 420, "Viertelbogen"),
    DINA4(210, 297, "Blatt"), DINA5(148, 210, "Halbblatt"),
    DINA6(105, 148, "Viertelblatt"), DINA7(74, 105, "Achtelblatt"),
    DINA8(52, 74, "Sechzehntelblatt"), DINA9(37, 52), DINA10(26, 37);
    private int breite;
    private int hoehe;
    private String bezeichnung;

    PapierFormat(int dieBreite, int dieHoehe) {
        breite = dieBreite;
        hoehe = dieHoehe;
        bezeichnung = "";
    }

    PapierFormat(int dieBreite, int dieHoehe, String dieBezeichnung) {
        breite = dieBreite;
        hoehe = dieHoehe;
        bezeichnung = dieBezeichnung;
    }

    public int liefereBreite() {
        return breite;
    }

    public int liefereHoehe() {
        return hoehe;
    }

    public int liefereFlaeche() {
        return breite * hoehe;
    }

    public String liefereBezeichnung() {
        return bezeichnung;
    }

    public String liefereFormatBezeichnung() {
        return toString().replace("DINA", "Din A");
    }
}