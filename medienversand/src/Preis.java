
import java.io.Serializable;

/**
 * Repraesentiert einen Preis fuer bestimmte Objekte, die aus dem Bruttopreis und Mehrwertsteuersatz bestehen.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Preis implements Serializable {
    /**
     * Der Mehrwertsteuersatz.
     */
    public static final double MEHRWERT_STEUER_SATZ = 0.19;
    /**
     * Die Hoehe des Bruttopreises.
     */
    private double bruttoPreis;

    /**
     * Erzeugt einen Preis (Bruttopreis).
     *
     * @param derBruttoPreis Die Hoehe des Bruttopreises.
     */
    public Preis(double derBruttoPreis) {
        if (derBruttoPreis >= 0.0) {
            bruttoPreis = derBruttoPreis;
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Setzt den Bruttopreis auf einen bestimmten Wert.
     *
     * @param derBruttoPreis Der Wert des Bruttopreis.
     */
    public void setzeBruttoPreis(double derBruttoPreis) {
        if (derBruttoPreis >= 0.0) {
            bruttoPreis = derBruttoPreis;
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert Bruttopreis.
     *
     * @return Der Bruttopreis.
     */
    public double liefereBruttoPreis() {
        return bruttoPreis;
    }

    /**
     * Liefert den Mehrwertsteuersatzanteil des Bruttopreises.
     *
     * @return Mehrwertsteuersatzanteil des Bruttopreises.
     */
    public double liefereMehrwertSteuerAnteil() {
        return MEHRWERT_STEUER_SATZ * bruttoPreis;
    }

    /**
     * Liefert Nettopreis.
     *
     * @return Nettopreis.
     */
    public double liefereNettoPreis() {
        return bruttoPreis - MEHRWERT_STEUER_SATZ * bruttoPreis;
    }
}