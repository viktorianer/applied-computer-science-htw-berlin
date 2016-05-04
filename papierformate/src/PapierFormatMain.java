public class PapierFormatMain {
    public static void main(String[] args) {
        System.out.println("\nSie erhalten Informationen zu Papierformaten.\n");
        String eingabe = erfassePapierFormat();
        schreibeFormatInfo(eingabe);
        System.out.println("\nInformationen zu Papierformaten:\n");
        PapierFormat[] papierFormate = PapierFormat.values();
        for (PapierFormat format : papierFormate)
            schreibeFormatInfo(format);
    }

    private static String erfassePapierFormat() {
        String info = "Bitte das Papierformat eingeben [Din A0 - Din A10]:   ";
        return Interaktionen.erfasseText(info, "Din A([0-9]|10)");
    }

    private static void schreibeFormatInfo(String papierFormat) {
        String ausgabe = "\n\nDas Format " + papierFormat;
        papierFormat = papierFormat.replace("in ", "IN");
        PapierFormat format = PapierFormat.valueOf(papierFormat);
        if (format == PapierFormat.DINA9 || format == PapierFormat.DINA10)
            ausgabe += " hat keine spezielle Bezeichnung.";
        else
            ausgabe += (" wird als " + format.liefereBezeichnung() + " bezeichnet.");
        ausgabe += "\n\nEs hat folgende Groesse:\n\n";
        ausgabe += formatiereZeile("Breite", format.liefereBreite(), "mm");
        ausgabe += formatiereZeile("Hoehe", format.liefereHoehe(), "mm");
        ausgabe += formatiereZeile("Flaeche", format.liefereFlaeche(), "qmm");
        System.out.println(ausgabe);
    }

    private static String formatiereZeile(String name, int wert, String einheit) {
        return String.format("%-8s:%12d%4s\n", name, wert, einheit);
    }

    private static void schreibeFormatInfo(PapierFormat format) {
        String ausgabe = String.format("%-10s", format.liefereFormatBezeichnung());
        ausgabe += String.format("%-16s", format.liefereBezeichnung());
        ausgabe += String.format("%5d mm \u00D7 ", format.liefereBreite());
        ausgabe += String.format("%4d mm   =", format.liefereHoehe());
        ausgabe += String.format("%8d qmm", format.liefereFlaeche());
        System.out.println(ausgabe);
    }
}