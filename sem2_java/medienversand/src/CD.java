
import java.util.Random;

/**
 * Repraesentiert eine CD.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class CD extends Medium {
    /**
     * Der Interpret der CD.
     */
    private String interpret;
    /**
     * Der Genre der CD.
     */
    private Genre genre;

    /**
     * Erzeugt eine CD, die einen Titel, Preis, Interpret und Genre hat.
     */
    public CD() {
        super("CD Titel");
        Random random = new Random();
        interpret = "Interpret " + random.nextInt(500);
        genre = Genre.values()[random.nextInt(Genre.values().length)];
    }

    /**
     * Erzeugt eine Kopie der CD.
     *
     * @param eineCD Die CD, die kopiert werden soll.
     */
    public CD(CD eineCD) {
        super(eineCD);
        interpret = eineCD.interpret;
        genre = eineCD.genre;
    }

    /**
     * Gibt Informationen, Titel, Interpret und Genre, zur CD als formatierter String aus.
     *
     * @return Wareninformationen zur CD.
     */
    @Override
    public String toString() {
        return "CD '" + super.toString() + String.format("' von '%s'", interpret) + " [" + genre.name() + "]";
    }
}
