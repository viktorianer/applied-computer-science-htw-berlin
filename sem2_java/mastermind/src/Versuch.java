/**
 * Repraesentiert ein Datum, das aus Tag (1 - 31),
 * Monat (1  12) und Jahr besteht (ganze Zahl).
 *
 * @author H. Brandenburg
 */
public class Versuch {
    /**
     * Der Tag des Datums.
     */
    private int[] versuchZahl;
    /**
     * Die Laenge der Zahl für ein Versuch
     */
    private int anzahlDerStellen;

    /**
     * Erzeugt das aktuelle Datum, d.h. das aktuell im
     * Rechner vorhandene Datum.
     */
    public Versuch(int dieAnzahlDerStellen) {
        anzahlDerStellen = dieAnzahlDerStellen;
    }

    public Versuch(int dieAnzahlDerStellen, int versuchNr) {
        boolean inputOk = (4 <= dieAnzahlDerStellen && dieAnzahlDerStellen <= 10);
        if (inputOk) {
            anzahlDerStellen = dieAnzahlDerStellen;
            versuchZahl = liesZahl(versuchNr);
        } else
            throw new IllegalArgumentException();
    }

    public Versuch(int dieAnzahlDerStellen, int[] dieVersuchZahl) {
        boolean inputOk = (4 <= dieAnzahlDerStellen && dieAnzahlDerStellen <= 10);
        if (inputOk) {
            anzahlDerStellen = dieAnzahlDerStellen;
            versuchZahl = dieVersuchZahl;
        } else
            throw new IllegalArgumentException();
    }

    public int gibDirekteTreffer(int[] dieOriginalZahl) {
        int direkteTreffer = 0;
        for (int i = 0; i < anzahlDerStellen; i++)
            for (int j = 0; j < anzahlDerStellen; j++)
                if (dieOriginalZahl[i] == gibVersuchZahl()[j]) {
                    if (i == j)
                        direkteTreffer = direkteTreffer + 1;
                }
        return direkteTreffer;
    }

    public int gibIndirekteTreffer(int[] dieOriginalZahl) {
        int indirekteTreffer = 0;
        for (int i = 0; i < anzahlDerStellen; i++)
            for (int j = 0; j < anzahlDerStellen; j++)
                if (dieOriginalZahl[i] == gibVersuchZahl()[j]) {
                    if (i == j)
                        continue;
                    else
                        indirekteTreffer = indirekteTreffer + 1;
                }
        return indirekteTreffer;
    }

    public int[] gibVersuchZahl() {
        return versuchZahl;
    }

    /**
     * Liest eine gueltige Zahl von der Tastatur ein.
     *
     * @param versuch
     * @return
     */
    private int[] liesZahl(int versuch) {
        int[] zahlenArray;
        do {
            int zahl = Interaktionen.erfasseInt("Versuch Nr. " + versuch + ": ");
            zahlenArray = wandleGanzeZahlInArray(zahl);
            if (zahlenArray == null)
                System.out.println("Keine gueltige Zahl eingegeben!");
        } while (zahlenArray == null);
        return zahlenArray;
    }

    public void schreibeVersuchZahl(int zahl) {
        int[] zahlenArray;
        if (zahl < 0 || zahl > ((int) (Math.pow(10, anzahlDerStellen) - 1)))
            zahlenArray = null;
        else {
            zahlenArray = wandleGanzeZahlInArray(zahl);
            for (int i = 0; i < anzahlDerStellen; i++)
                for (int j = i + 1; j < anzahlDerStellen; j++)
                    if (zahlenArray[i] == zahlenArray[j]) {
                        zahlenArray = null;
                        i = anzahlDerStellen;
                        j = anzahlDerStellen;
                    }
        }
        versuchZahl = zahlenArray;
    }

    public void schreibeVersuchZahl(int[] zahlenArray) {
        versuchZahl = zahlenArray;
    }

    public int schreibeDirekteTreffer(int anzahl) {
        return anzahl;
    }

    public int schreibeIndirekteTreffer(int anzahl) {
        return anzahl;
    }

    /**
     * Wandlet die Ziffern einer Zahl in ein Int-Array um.
     *
     * @param zahl
     * @return
     */
    private int[] wandleGanzeZahlInArray(int zahl) {
        int[] zahlenArray = new int[anzahlDerStellen];
        for (int i = 0; i < anzahlDerStellen; i++) {
            zahlenArray[i] = zahl % 10;
            zahl = zahl / 10;
        }
        return zahlenArray;
    }
}