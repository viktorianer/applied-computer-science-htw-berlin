/**
 * Repraesentiert einen Angestellten, der Geld verdient.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Angestellter extends Person {
    /**
     * Der Verdienst des Verkaefers
     */
    private double verdienst;

    /**
     * Erzeugt einen Angestellten mit einem bestimmten Verdienst.
     *
     * @param derVerdienst Der Verdienst eines Angestellten.
     */
    public Angestellter(double derVerdienst) {
        super();
        verdienst = derVerdienst;
    }

    /**
     * Liefert den Verdienst des Angestellten.
     *
     * @return Der Verdienst des Angestellten.
     */
    public double liefereVerdienst() {
        return verdienst;
    }

    /**
     * Setzt Verdienst des Angestellten.
     *
     * @param derVerdienst Der neue Wert des Verdienstes.
     */
    public void setzeVerdienst(double derVerdienst) {
        verdienst = derVerdienst;
    }
}