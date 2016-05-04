
import java.util.Random;

/**
 * Repraesentiert eine DVD.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class DVD extends Medium {
    /**
     * Der Regisseur der DVD.
     */
    private String regisseur;
    /**
     * Die Altersfreigabe der DVD nach FSK (Deutschland).
     */
    private FSK fsk;

    /**
     * Erzeugt eine DVD, die einen Titel, Preis, Regisseur und FSK hat.
     */
    public DVD() {
        super("Filmtitel");
        Random random = new Random();
        regisseur = "Regisseur " + random.nextInt(500);
        fsk = FSK.values()[random.nextInt(FSK.values().length)];
    }

    /**
     * Erzeugt eine Kopie der DVD.
     *
     * @param eineDVD Die DVD, die kopiert werden soll.
     */
    public DVD(DVD eineDVD) {
        super(eineDVD);
        regisseur = eineDVD.regisseur;
        fsk = eineDVD.fsk;
    }

    /**
     * Gibt Informationen, Titel, Regisseur und FSK, zur DVD als formatierter String aus.
     *
     * @return Wareninformationen zur DVD.
     */
    @Override
    public String toString() {
        return "DVD '" + super.toString() + String.format("' von '%s' (frei ab %d)", regisseur, fsk.liefereAltersfreigabe());
    }
}
