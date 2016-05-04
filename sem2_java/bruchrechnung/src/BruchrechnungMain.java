/**
 * Ein Programm, das Rechnen mit ganzzahligen Bruechen ermoeglicht.
 * Die Benutzer und Benutzerinnen können (nach geeigneter Benutzerführung) zwei ganzzahlige Brueche in exakt der Form
 * a/b bzw. c/d eingeben. Dabei ist darauf zu achten, dass der Nenner nie 0 sein darf.
 * <p>
 * Anschließend wird (nach geeigneter Benutzerfuehrung) auf dem Bildschirm ausgegeben:
 * a/b + c/d = ??/??
 * a/b - c/d = ??/??
 * a/b * c/d = ??/??
 * a/b / c/d = ??/??
 * <p>
 * Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
 * aber immer im folgenden Sinn normiert:
 * - e und f sollen teilerfremd sein.
 * - ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
 * - wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
 * - wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class BruchrechnungMain {
    /**
     * Einstiegspunkt des Programms.
     * <p>
     * main ist (zunächst) die einzige Methode der Klasse.
     * Java schreibt vor, das main immer public und static ist.
     * stellt sich heraus, dass die Aufgaben von main komplex sind, setzen wir zusätzlich geeignete Hilfsmethoden ein
     * die dann stets private und static sind.
     * Dadurch wird Main zu einer aus objektorientierter Sicht völlig untypischen Klasse,
     * die natürlich die genannten Gütekriterien nicht erfüllt.
     * Diese Häßlichkeit nehmen wir in Kauf.
     */
    private BruchrechnungMain() {
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * Die Benutzer und Benutzerinnen können (nach geeigneter Benutzerführung) zwei ganzzahlige Brueche in exakt der Form
     * a/b bzw. c/d eingeben. Dabei ist darauf zu achten, dass der Nenner nie 0 sein darf.
     * <p>
     * Anschließend wird (nach geeigneter Benutzerfuehrung) auf dem Bildschirm ausgegeben:
     * a/b + c/d = ??/??
     * a/b - c/d = ??/??
     * a/b * c/d = ??/??
     * a/b / c/d = ??/??
     * <p>
     * Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
     * aber immer im folgenden Sinn normiert:
     * - e und f sollen teilerfremd sein.
     * - ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
     * - wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
     * - wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
     *
     * @param args Wird nicht genutzt.
     */
    public static void main(String[] args) {
        boolean antwort = false;
        String programmMenue[] = {"Bruchrechnung", "Programm beenden"};
        do {
            Menue menue = new Menue(programmMenue);
            switch (menue.waehleAusMenue()) {
                case 1:
                    benutzerFuerung();
                    break;
                default:
                    System.out.printf("\nDas Programm wird beendet. See You!\n");
                    antwort = true;
                    break;
            }
        } while (!antwort);
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     */
    private static void benutzerFuerung() {
        System.out.printf("\nDas Programm rechnet mit zwei ganzzahligen Bruechen. Es wird das Ergebnis der Addition, "
                + "der Subtraktion, der Multiplikation und der Division ausgegeben.\n");
        Bruch derErsteBruch = new Bruch(Eingaben.erfasseText("Bitte geben Sie den ersten, ganzzahligen Bruch ein (a/b):  "));
        Bruch derZweiteBruch = new Bruch(Eingaben.erfasseText("Bitte geben Sie den zweiten, ganzzahligen Bruch ein (c/d):  "));
        schreibeBerechnung(derErsteBruch, derZweiteBruch);

    }

    /**
     * Gibt auf dem Bildschirm das Ergebnis aus:
     * a/b + c/d = ??/??
     * a/b - c/d = ??/??
     * a/b * c/d = ??/??
     * a/b / c/d = ??/??
     * <p>
     * Die Brüche a/b und c/d werden stets unveraendert ausgegeben, das Ergebnis e/f
     * aber immer im folgenden Sinn normiert:
     * - e und f sollen teilerfremd sein.
     * - ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zähler steht.
     * - wenn f den Wert 1 hat, wird statt e/f nur e ausgegeben.
     * - wenn e und f denselben Wert haben, wird statt e/f der Wert 1 ausgegeben.
     *
     * @param ersterBruch  Der erste Bruch.
     * @param zweiterBruch Der zweite Bruch.
     */
    private static void schreibeBerechnung(Bruch ersterBruch, Bruch zweiterBruch) {
        Bruch ergebnisBruch;
        ergebnisBruch = ersterBruch.plus(zweiterBruch);
        ergebnisBruch.kuerzeBruch();
        System.out.printf("\n%s + %s = %s", ersterBruch.gibBruchAlsText(), zweiterBruch.gibBruchAlsText(),
                ergebnisBruch.gibBruchAlsText());
        ergebnisBruch = ersterBruch.minus(zweiterBruch);
        ergebnisBruch.kuerzeBruch();
        System.out.printf("\n%s - %s = %s", ersterBruch.gibBruchAlsText(), zweiterBruch.gibBruchAlsText(),
                ergebnisBruch.gibBruchAlsText());
        ergebnisBruch = ersterBruch.mal(zweiterBruch);
        ergebnisBruch.kuerzeBruch();
        System.out.printf("\n%s * %s = %s", ersterBruch.gibBruchAlsText(), zweiterBruch.gibBruchAlsText(),
                ergebnisBruch.gibBruchAlsText());
        ergebnisBruch = ersterBruch.geteiltDurch(zweiterBruch);
        ergebnisBruch.kuerzeBruch();
        System.out.printf("\n%s / %s = %s\n", ersterBruch.gibBruchAlsText(), zweiterBruch.gibBruchAlsText(),
                ergebnisBruch.gibBruchAlsText());
    }
}
