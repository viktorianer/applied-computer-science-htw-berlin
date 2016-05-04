/**
 * Repraesentiert einen Fahrkartenautomat der Fahrkarten fuer bestimmte Ziele anbietet und die Bezahlung abwickelt.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Fahrkartenautomat {
    /**
     * Bestimmte Ziele fuer die Fahrkarten angeboten (verkauft) werden.
     */
    private Ziel[] ziele = null;
    /**
     * Die Fahrkarte, die verkauft wird.
     */
    private Fahrkarte fahrkarte = null;

    /**
     * Erzeugt einen Fahrkartenautomat der Fahrkarten fuer bestimmte Ziele anbietet und die Bezahlung abwickelt.
     */
    public Fahrkartenautomat() {
        ziele = Ziel.values();
        fahrkarte = new Fahrkarte();
    }

    /**
     * Leitet einen Bestellvorgang fuer eine Fahrkarte fuer ein bestimmtes Ziel ein und schlisst diesen mit einer Bezahlung ab.
     * Nach Wahl des Fahrtziels erscheint der Fahrpreis und die Benutzerinnen und Benutzer werden aufgefordert,
     * den Preis zu zahlen. Alle Fahrtziele haben unterschiedliche Preise.
     *
     * @param dasZiel Das Ziel, fuer das der Bestellvorgang durchgefuert werden soll.
     */
    public void bestellvorgang(int dasZiel) {
        System.out.printf("\nBestellvorgang:");
        Kasse bestellung = new Kasse();
        System.out.printf("\n%-50s %s\n", "Ihr gewaelter Zielort ist:", fahrkarte.liefereBezeichnung());
        System.out.printf("%-50s %.2f Euro\n", "Die Fahrkarte kostet: ", fahrkarte.lieferePreis());
        if (bestellung.bezahlvorgang(fahrkarte.lieferePreis()))
            System.out.printf("Bitte entnaehmen Sie ihre Fahrkarte. Vielen Dank und gute Fahrt!\n");
    }

    /**
     * Steurt die Wahl des Zieles durch Benutzer und legt eine Fahrkarte fuer das entsprechende Ziel an.
     * <br>
     * Es wird eine Aufstellung sämtlicher Fahrtziele ausgegeben (>= 10).
     * Die Auswahl des Fahrtziels erfolgt durch Eingabe einer Kennziffer (ID).
     * Nicht zulässige Kennziffern werden ignoriert.
     *
     * @return Das angebotene Ziel (> 0 bis max.) oder Abbruchbedingung (-1) wird zurueckgegeben.
     */
    public int wahlDesZieles() {
        int erfasstesZiel;
        boolean eingabeOK = false;
        schreibeAlleZiele();
        do {
            erfasstesZiel = Eingaben.erfasseInt("\nBitte waehlen Sie eins der angebotene Ziele durch eingabe der Nummer: ");
            if (erfasstesZiel > 0 && erfasstesZiel < Ziel.values().length + 1) {
                fahrkarte = new Fahrkarte(Ziel.values()[erfasstesZiel - 1].liefereBezeichnung());
                eingabeOK = true;
            } else {
                if (erfasstesZiel == -1)
                    eingabeOK = true;
                else
                    System.out.printf("\nDas von Ihnen eingebenes Ziel konnte nicht gefunden werden.");
            }
        } while (!eingabeOK);
        return erfasstesZiel;
    }

    /**
     * Schreibt, durchnummeriert alle Ziele die durch Fahrkartenautomat angeboten werden.
     */
    private void schreibeAlleZiele() {
        System.out.printf("\nAngebotene Ziele:\n");
        for (Ziel ziel : ziele) {
            System.out.printf(ziel.liefereKennziffer() + ". " + ziel.liefereBezeichnung() + "\n");
        }
    }
}