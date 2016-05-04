
import java.math.BigDecimal;

/**
 * Repraesentiert einen Kassenautomat, der die Bezahlung abwickelt, das Restgeld oder das Rueckgabegeld zurueckgibt
 * und den Geldeinwurf auf das passende Euro-Geld ueberprueft.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Kasse {
    /**
     * Der Einwurf des Kassenautomates
     */
    private Preis[] einwurf = null;

    /**
     * Erzeugt einen Kassenautomaten mit einem Einwurf fuer Euro-Geld.
     */
    public Kasse() {
        einwurf = new Preis[0];
    }

    /**
     * Leitet den Bezahlvorgang ein und ueberprueft den Einwurf auf das passende Euro-Geld.
     * Wenn die Zahlung abgebrochgen(0) wird oder der eingezahlter Betrag hoeher als der zu zahlender Betrag ist, wird
     * das eingeworfene Geld oder das Restgeld zurueckerstattet.
     * <br>
     * Beim Zahlen des Preises wird nur die Eingabe von 50.00 Euro, 20.00 Euro, 10.00 Euro, 5.00 Euro, 2.00 Euro,
     * 1.00 Euro, 0.50 Euro, 0.10 Euro und 0.00 Euro akzeptiert. Andere Eingaben werden zurückgeweisen.
     * Die Preise sind so festgelegt, dass sie glatt durch die zulässigen Eingaben bezahlt werden können.
     *
     * @param zuZahlenderBetrag Der zu zahlender Betrag, der Bezahlt werden soll.
     * @return Gibt an ob der Betrag bezahlt wurde (true) oder die Zahlung abgebrochen wurde (false).
     */
    public boolean bezahlvorgang(double zuZahlenderBetrag) {
        boolean istBezahlt = false;
        boolean abbruchZahlung = false;
        int i = 0;
        double geld;
        System.out.printf("\nBezahlvorgang:");
        do {
            System.out.printf("\n%-50s %.2f Euro", "Noch zu zahlender Betrag: ", zuZahlenderBetrag - summeEinwurf());
            geld = erfasseZahlung().liefereWert();
            if (Euro.istGueltigerEuroBetrag(geld)) {
                erweitereEinwurf();
                einwurf[i] = new Preis(geld);
                if (einwurf[i].liefereBruttoPreis() == 0) {
                    if (summeEinwurf() > 0)
                        rueckgabeEinwurf();
                    abbruchZahlung = true;
                }
                if (summeEinwurf() >= zuZahlenderBetrag) {
                    if (summeEinwurf() - zuZahlenderBetrag > 0)
                        rueckgabeRestgeld(summeEinwurf() - zuZahlenderBetrag);
                    istBezahlt = true;
                }
            } else {
                System.out.printf("\nBitte geben Sie ihr Geld in einer passenden Groesse ein!");
                i--;
            }
            i++;
        } while (!istBezahlt && !abbruchZahlung);
        return istBezahlt;
    }

    /**
     * Erfasst die Zahlung durch Benutzer in Euros.
     *
     * @return Euro.
     */
    private Euro erfasseZahlung() {
        String eingabe = Eingaben.erfasseText("\nBitte werfen Sie passendes Geld ein: ",
                "([521]0.00|[521].00|0.[510]0) Euro",
                "\nSie haben falsches Geld eingeworfen. Bitte das Geld im Format 0.00 Euro eingeben.");
        return Euro.istGueltigeEuroBezeichnung(eingabe);
    }

    /**
     * Erweiter den Einwurf um eins, damit das naechste Geld eingeworfen werden kann.
     */
    private void erweitereEinwurf() {
        Preis[] copy;
        copy = new Preis[einwurf.length];
        System.arraycopy(einwurf, 0, copy, 0, einwurf.length);
        einwurf = new Preis[copy.length + 1];
        System.arraycopy(copy, 0, einwurf, 0, copy.length);
        einwurf[einwurf.length - 1] = new Preis(0.0);
    }

    /**
     * Summiert den Einwurf der Kasse.
     *
     * @return Summe des Einwurfs der Kasse.
     */
    private double summeEinwurf() {
        double summeEinwurf = 0.0;
        for (Preis preis : einwurf) {
            summeEinwurf = summeEinwurf + preis.liefereBruttoPreis();
        }
        return summeEinwurf;
    }

    /**
     * Gibt das Restgeld zurueck.
     * <br>
     * Falls zu viel eingegeben wurde, die Höhe des Rückerstattungsbetrages sowie die Form der Rückerstattung
     * angezeigt (z.B. 3 ´ 5.00 Euro, 1 ´ 1.00 Euro, 2 ´ 0.10 Euro). Dabei werden jeweils möglichst wenige
     * Zahlungseinheiten zurückgezahlt werden (d.h. z.B. statt 5 ´ 1.00 Euro nur 1 ´ 5.00 Euro).
     */
    private void rueckgabeRestgeld(double rueckgabeBetrag) {
        double geld;
        BigDecimal dec;
        int[] anzahl = new int[Euro.values().length - 1];
        System.out.printf("\nSie erhalten ihr Restgeld in Hoehe von %.2f Euro...", rueckgabeBetrag);
        System.out.printf("\n*Blink* *Rassel* *Pum* Rueckgabegeld: ");
        for (int i = 0; i < anzahl.length; i++) {
            geld = Euro.values()[i].liefereWert();
            if (rueckgabeBetrag > 0) {
                while (rueckgabeBetrag - geld >= 0) {
                    rueckgabeBetrag = rueckgabeBetrag - geld;
                    dec = BigDecimal.valueOf(rueckgabeBetrag);
                    dec = dec.setScale(1, BigDecimal.ROUND_HALF_UP);
                    rueckgabeBetrag = dec.doubleValue();
                    anzahl[i] = anzahl[i] + 1;
                }
            }
        }
        for (int i = 0; i < anzahl.length; i++) {
            if (anzahl[i] != 0)
                System.out.printf("%dx%6.2f Euro ", anzahl[i], Euro.values()[i].liefereWert());
        }
        System.out.printf("\n");
    }

    /**
     * Gibt das eingeworfene Geld zurueck.
     * <br>
     * Falls 0.00 Euro eingegeben wurde, erscheint auf dem Bildschirm ein Hinweis, dass der
     * schon bezahlte Betrag zurückerstattet wird. Dabei wird die Höhe des Rückerstattungsbetrages angegeben
     * und genau aufgeschlüsselt, welche Eingaben getätigt wurden (z.B. 3 ´ 1.00 Euro, 1 ´
     * 0.50 Euro, 2 ´ 0.10 Euro).
     */
    private void rueckgabeEinwurf() {
        double geld;
        int[] anzahl = new int[Euro.values().length - 1];
        System.out.printf("\nAuf Ihren Wunsch wurde die Zahlung abgebrochen...");
        System.out.printf("\n*Blink* *Rassel* *Pum* Rueckgabegeld in Hoehe von %.2f Euro...: ", summeEinwurf());
        for (int i = 0; einwurf[i].liefereBruttoPreis() > 0; i++) {
            for (int j = 0; j < anzahl.length; j++) {
                geld = Euro.values()[j].liefereWert();
                if (einwurf[i].liefereBruttoPreis() == geld) {
                    anzahl[j] = anzahl[j] + 1;
                }
            }
        }
        for (int i = 0; i < anzahl.length; i++) {
            if (anzahl[i] != 0)
                System.out.printf("%dx%6.2f Euro ", anzahl[i], Euro.values()[i].liefereWert());
        }
        System.out.printf("\n");
    }
}