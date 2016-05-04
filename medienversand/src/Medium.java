
import java.io.Serializable;
import java.util.Random;

/**
 * Repraesentiert ein Medium mit Titel und Preis.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Medium implements Serializable {
    /**
     * Der Titel des Mediums.
     */
    private String titel;
    /**
     * Der Preis des Mediums.
     */
    private Preis preis;

    /**
     * Erzeugt ein Medium, das einen Titel und Preis hat.
     *
     * @param derTitel Der Titel des Mediums.
     */
    public Medium(String derTitel) {
        Random random = new Random();
        titel = derTitel + " " + random.nextInt(500);
        preis = new Preis(random.nextDouble() * 100 + 20);
    }

    /**
     * Erzeugt ein Kopie des Mediums.
     *
     * @param einMedium Das Medium, das kopiert werden soll.
     */
    public Medium(Medium einMedium) {
        titel = einMedium.titel;
        preis = einMedium.preis;
    }

    /**
     * Gibt Informationen, Titel, zum Medium als formatierter String aus.
     *
     * @return Informationen zum Medium.
     */
    @Override
    public String toString() {
        return String.format("%s", titel);
    }

    /**
     * Liefert den Bruttopreis des Mediums.
     *
     * @return Der Bruttopreis des Mediums.
     */
    public double liefereBruttoPreis() {
        return preis.liefereBruttoPreis();
    }
}
