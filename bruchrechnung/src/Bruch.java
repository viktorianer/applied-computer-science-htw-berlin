/**
 * Repraesentiert ein Bruch, das aus einem Zaehler und Nenner besteht.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Bruch {
    /**
     * Der Zaehler des Bruches.
     */
    private int zaehler;
    /**
     * Der Nenner des Bruches.
     */
    private int nenner;

    /**
     * Erzeugt ein Bruch, das aus einem Zaehler = 1 und Nenner = 1 besteht.
     */
    public Bruch() {
        setzeZaehler(1);
        setzeNenner(1);
    }

    /**
     * Erzeugt ein Bruch, das aus einem Zaehler und Nenner besteht.
     *
     * @param derZaehler Der Wert, der im Zaehler stehen soll.
     * @param derNenner  Der Wert, der im Nenner stehen soll.
     */
    public Bruch(int derZaehler, int derNenner) {
        setzeZaehler(derZaehler);
        setzeNenner(derNenner);
        formatiereBruch();
    }

    /**
     * Erzeugt ein Bruch aus einem uebergebenen String, das aus einem Zaehler und Nenner besteht.
     *
     * @param bruch Ein String, der bestimmten Format hat und dem Wert fuer Zaehler und Nenner hat.
     */
    public Bruch(String bruch) {
        boolean inputOk = bruch.matches("(-?[0-9]+/-?[1-9]+[0-9]*)");
        if (inputOk) {
            setzeZaehler(Integer.parseInt(bruch.substring(0, bruch.indexOf("/"))));
            setzeNenner(Integer.parseInt(bruch.substring(bruch.indexOf("/") + 1, bruch.length())));
        } else
            throw new IllegalArgumentException();
        formatiereBruch();
    }

    /**
     * Gibt den Zaehler des Bruches zurueck.
     *
     * @return Gibt den Zaehler des Bruches zurueck.
     */
    public int gibZaehler() {
        return zaehler;
    }

    /**
     * Gibt den Nenner des Bruches zurueck.
     *
     * @return Gibt den Nenner des Bruches zurueck.
     */
    public int gibNenner() {
        return nenner;
    }

    /**
     * Gibt den Bruch als String zurueck.
     *
     * @return Gibt den Zaehler und Nenner des Bruches, getrennt durch ein / als String zurueck.
     */
    public String gibBruchAlsText() {
        String bruch;
        formatiereBruch();
        if (gibNenner() == 1) {
            if (gibZaehler() == gibNenner())
                bruch = "1";
            else
                bruch = String.valueOf(gibZaehler());
        } else
            bruch = String.valueOf(gibZaehler()) + "/" + String.valueOf(gibNenner());
        return bruch;
    }

    /**
     * Kuerzt einen Bruch (teilerfremd).
     */
    public void kuerzeBruch() {
        int derGroessterGemeinsamerTeiler = groessterGemeinsamerTeiler(gibZaehler(), gibNenner());
        setzeZaehler(gibZaehler() / derGroessterGemeinsamerTeiler);
        setzeNenner(gibNenner() / derGroessterGemeinsamerTeiler);
    }

    /**
     * Addition zweier Brueche.
     *
     * @param bruch Der Bruch, der zuaddiert werden soll.
     * @return Gibt das Ergebnis der Addition zurueck.
     */
    public Bruch plus(Bruch bruch) {
        Bruch ergebnis = new Bruch();
        ergebnis.setzeZaehler(this.gibZaehler() * bruch.gibNenner() + bruch.gibZaehler() * this.gibNenner());
        ergebnis.setzeNenner(this.gibNenner() * bruch.gibNenner());
        return ergebnis;
    }

    /**
     * Subtraktion zweier Brueche.
     *
     * @param bruch Der Bruch, der abgezogen werden soll.
     * @return Gibt das Ergebnis der Subtraktion zurueck.
     */
    public Bruch minus(Bruch bruch) {
        Bruch ergebnis = new Bruch();
        ergebnis.setzeZaehler(this.gibZaehler() * bruch.gibNenner() - bruch.gibZaehler() * this.gibNenner());
        ergebnis.setzeNenner(this.gibNenner() * bruch.gibNenner());
        return ergebnis;
    }

    /**
     * Multiplikation zweier Brueche.
     *
     * @param bruch Der Bruch, mit dem multipliziert werden soll.
     * @return Gibt das Ergebnis der Multiplikation zurueck.
     */
    public Bruch mal(Bruch bruch) {
        Bruch ergebnis = new Bruch();
        ergebnis.setzeZaehler(this.gibZaehler() * bruch.gibZaehler());
        ergebnis.setzeNenner(this.gibNenner() * bruch.gibNenner());
        return ergebnis;
    }

    /**
     * Division zweier Brueche.
     *
     * @param bruch Der Bruch, mit dem dividiert werden soll.
     * @return Gibt das Ergebnis der Division zurueck.
     */
    public Bruch geteiltDurch(Bruch bruch) {
        Bruch ergebnis = new Bruch();
        ergebnis.setzeZaehler(this.gibZaehler() * bruch.gibNenner());
        ergebnis.setzeNenner(this.gibNenner() * bruch.gibZaehler());
        return ergebnis;
    }

    /**
     * Setzt die uebergebene Zahl in den Zaehler.
     *
     * @param derZaehler Die Zahl, die im Zaehler gespeichert werden soll.
     */
    private void setzeZaehler(int derZaehler) {
        zaehler = derZaehler;
    }

    /**
     * Setzt die uebergebene Zahl in den Nenner.
     *
     * @param derNenner Die Zahl, die im Nenner gespeichert werden soll.
     */
    private void setzeNenner(int derNenner) {
        boolean inputOk = (derNenner != 0);
        if (inputOk)
            nenner = derNenner;
        else
            throw new IllegalArgumentException();
    }

    /**
     * Formatiert den Bruch.
     * Der Bruch wird im folgenden Sinne normiert:
     * - Zaehler und Nenner sollen teilerfremd sein.
     * - ist das Ergebnis negativ, wird es so umgeformt, dass das Vorzeichen im Zaehler steht.
     * - wenn Nenner den Wert 1 hat, wird statt Zaehler/Nenner nur Zaehler ausgegeben.
     * - wenn Zaehler und Nenner denselben Wert haben, wird statt Zaehler/Nenner der Wert 1 ausgegeben.
     */
    private void formatiereBruch() {
        if (nenner < 0)
            if (zaehler > 0) {
                zaehler = zaehler * (-1);
                nenner = nenner * (-1);
            }
    }

    /**
     * Berechnet den Größter gemeinsamer Teiler von zwei Bruechen.
     *
     * @param zahlA Der erste Bruch.
     * @param zahlB Der zweite Bruch.
     * @return Gibt den Größter gemeinsamer Teiler zurueck.
     */
    private int groessterGemeinsamerTeiler(int zahlA, int zahlB) {
        int derGroessterGemeinsamerTeiler = 0;
        if (zahlA == zahlB || zahlB == 0)
            derGroessterGemeinsamerTeiler = zahlA;
        else
            derGroessterGemeinsamerTeiler = groessterGemeinsamerTeiler(zahlB, (zahlA % zahlB));
        return derGroessterGemeinsamerTeiler;
    }
}