
import java.util.Random;

/**
 * Repraesentiert eine Tagesstatistik (Anzahl der Verkaefe).
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Tagesstatistik {
    /**
     * Anzahl der Verkaefe am Tag.
     */
    private int anzahlVerkaefe;

    /**
     * Erzeugt eine Tagesstatistik mit einer zufaelligen Anzahl an Verkaefen.
     *
     * @param maxVerkaefe Die maximale Anzahl der Verkaefe.
     */
    public Tagesstatistik(int maxVerkaefe) {
        anzahlVerkaefe = erzeugeTagesstatistik(maxVerkaefe);
    }

    /**
     * Liefert die Anzahl der Verkaefe.
     *
     * @return Die Anzahl der Verkaefe.
     */
    public int liefereTagesstatistik() {
        return anzahlVerkaefe;
    }

    /**
     * Erzeugt einen zufaelligen Wert fuer die Tagesstatistik.
     *
     * @param maxVerkaefe Die maximale Anzahl der Verkaefe.
     * @return Die zufaellige Anzahl der Verkaefe.
     */
    private int erzeugeTagesstatistik(int maxVerkaefe) {
        Random random = new Random();
        int foo = random.nextInt();
        return random.nextInt(maxVerkaefe); // 0 <= return < 100
    }
}