
import java.util.Random;

/**
 * Repraesentiert ein Buch mit einem Hardcover oder ohne.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Buch extends Medium {
    /**
     * Der Autor des Buches.
     */
    private String autor;
    /**
     * Bestimmt, ob ein Buch Hardcover hat (true) oder nicht (false).
     */
    private boolean cover;

    /**
     * Erzeugt ein Buch, das einen Titel, Preis, Autor und (Hardcover) hat.
     */
    public Buch() {
        super("Titel");
        Random random = new Random();
        autor = "Autor " + random.nextInt(500);
        cover = random.nextBoolean();
    }

    /**
     * Erzeugt eine Kopie des Buches.
     *
     * @param einBuch Das Buch, das kopiert werden soll.
     */
    public Buch(Buch einBuch) {
        super(einBuch);
        autor = einBuch.autor;
        cover = einBuch.cover;
    }

    /**
     * Gibt Informationen, Titel, Autot und Hardcover, zum Buch als formatierter String aus.
     *
     * @return Wareninformationen zum Buch.
     */
    @Override
    public String toString() {
        return "Buch '" + super.toString() + String.format("' von '%s'", autor) + ((cover) ? " [HARDCOVER]" : "");
    }
}
