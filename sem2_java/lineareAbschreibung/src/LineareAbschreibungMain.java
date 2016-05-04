public class LineareAbschreibungMain {
    private LineareAbschreibungMain() {
    }

    public static void main(String[] args) {
        if (parameterOk(args)) {
            double startWert = Double.parseDouble(args[0]);
            double endWert = Double.parseDouble(args[1]);
            int anzahlJahre = Integer.parseInt(args[2]);
            String ueberschrift = "\n\nAbschreibungsplan bei ";
            ueberschrift += "linearer Abschreibung\n\n";
            LinearAbschreiber abschreiber = new LinearAbschreiber(startWert, endWert, anzahlJahre);
            double[] dieDaten = abschreiber.lieferePlanDaten();
            double dieAbschreibung = abschreiber.liefereAbschreibung();
            schreibeAbschreibungsplan(ueberschrift, dieDaten, dieAbschreibung);
        } else
            schreibeAnleitung();
    }

    private static boolean parameterOk(String[] args) {
        boolean ok = false;
        if (args.length == 3) {
            try {
                double startWert = Double.parseDouble(args[0]);
                double endWert = Double.parseDouble(args[1]);
                int anzahlJahre = Integer.parseInt(args[2]);
                ok = (1 <= startWert) && (0 <= endWert) && (endWert <= startWert) && (1 <= anzahlJahre);
            } catch (NumberFormatException nfe) {
                System.out.print(nfe);
            }
        }
        return ok;
    }

    private static void schreibeAnleitung() {
        System.out.printf("\nHilfe!...\n");
    }

    private static void schreibeAbschreibungsplan(String info, double[] planDaten, double abschreibung) {
        schreibeUeberschrift(info);
        for (int i = 0; i < planDaten.length; i++) {
            System.out.printf("%5d%14.2f", i + 1, planDaten[i]);
            System.out.printf("%14.2f", abschreibung);
            if (i < planDaten.length - 1)
                System.out.printf("%14.2f\n", planDaten[i + 1]);
            else
                System.out.printf("%14.2f\n", planDaten[i] - abschreibung);
        }
    }

    private static void schreibeUeberschrift(String info) {
        System.out.printf("%s", info);
        System.out.printf("%5s", "Jahr");
        System.out.printf("%14s", "Anfang");
        System.out.printf("%14s", "Abschreibung");
        System.out.printf("%14s\n\n", "Ende");
    }
}