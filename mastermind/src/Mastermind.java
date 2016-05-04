/**
 * Repraesentiert ein Datum, das aus Tag (1 - 31),
 * Monat (1  12) und Jahr besteht (ganze Zahl).
 *
 * @author H. Brandenburg
 */
public class Mastermind {
    /**
     * Die Zahl, die es zu erraten gilt
     */
    private int[] originalZahl;
    /**
     * Die Laenge der originalZahl, die es zu erraten gilt
     */
    private int anzahlDerStellen;

    /**
     * Erzeugt das aktuelle Datum, d.h. das aktuell im
     * Rechner vorhandene Datum.
     */
    public Mastermind(int dieAnzahlDerStellen) {
        boolean inputOk = (4 <= dieAnzahlDerStellen && dieAnzahlDerStellen < 10);
        if (inputOk) {
            anzahlDerStellen = dieAnzahlDerStellen;
            originalZahl = findePassendeZahl();
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert das Datum in der Form <code>tt.mm.jjjj</code>.
     *
     * @return Das Datum in der Form <code>tt.mm.jjjj</code>.
     */
    private int[] gibOriginalZahlAlsArray() {
        return originalZahl;
    }

    public String gibOriginalZahl() {
        return wandleGanzeZahlInString(originalZahl);
    }

    public void spieleMastermind(int anzahlMaxVersuche) {
        boolean erraten = false;
        Versuch[] versuche = new Versuch[anzahlMaxVersuche];
        for (int i = 0; i < anzahlMaxVersuche; i++) {
            System.out.print("\nSie haben noch " + (anzahlMaxVersuche - i) + " Versuch(e). ");
            versuche[i] = new Versuch(anzahlDerStellen, i + 1);
            if (treffer(versuche[i].gibVersuchZahl())) {
                System.out.println("\nHervorragend! Sie haben die Zahl im " + (i + 1) + " Versuch erraten.");
                erraten = true;
                i = anzahlMaxVersuche;
            } else {
                for (int j = 0; j <= i; j++)
                    System.out.println((j + 1) + ":\t" + wandleGanzeZahlInString(versuche[j].gibVersuchZahl()) +
                            "\t" + (auswerten(versuche[j])));
            }
        }
        if (!erraten) {
            System.out.println("\nViel Glueck beim naechsten Mal!");
            System.out.println("Die richtige Zahl waere " + gibOriginalZahl());
        }
    }

    public void spieleMastermindAI(int anzahlMaxVersuche) {
        boolean erraten = false;
        boolean versuchIstGut = true;
        int versuchNR = 0;
        Versuch[] versuche = new Versuch[anzahlMaxVersuche];
        for (int versuchZahl = 123; versuchZahl < ((int) (Math.pow(10, anzahlDerStellen) - 1)) * Math.random()
                && versuchNR < anzahlMaxVersuche; versuchZahl++) {
            versuche[versuchNR] = new Versuch(anzahlDerStellen);
            if (versuchNR != 0 && bereiteAuf(versuchZahl) != null) {
                for (int i = 0; i < versuchNR; i++) {
                    versuchIstGut = versuchIstGut & aiVersuchPasst(bereiteAuf(versuchZahl), versuche[i]);
                    if (versuchIstGut) {
                        versuche[versuchNR].schreibeVersuchZahl(versuchZahl);
                        versuchNR++;
                    }
                }
            } else {
                versuche[0].schreibeVersuchZahl(123);
                versuchNR++;
            }
        }
    }

    private boolean aiVersuchPasst(int[] neuerVersuch, Versuch alterVersuch) {
        int direkteTreffer = 0;
        int indirekteTreffer = 0;
        for (int i = 0; i < anzahlDerStellen; i++)
            for (int j = 0; j < anzahlDerStellen; j++)
                if (neuerVersuch[i] == alterVersuch.gibVersuchZahl()[j]) {
                    if (i == j)
                        direkteTreffer = direkteTreffer + 1;
                    else
                        indirekteTreffer = indirekteTreffer + 1;
                }
        return (direkteTreffer == alterVersuch.gibDirekteTreffer(gibOriginalZahlAlsArray())
                && indirekteTreffer == alterVersuch.gibIndirekteTreffer(gibOriginalZahlAlsArray()));
    }

    /**
     * Finde eine Zahl zwischen 0 und Max, die die Voraussetzungen fuer das Spiel erfuellt.
     */
    private int[] findePassendeZahl() {
        int[] zahlenArray;
        int zufallszahl;
        do {
            zufallszahl = (int) (((int) (Math.pow(10, anzahlDerStellen) - 1)) * Math.random());
            zahlenArray = bereiteAuf(zufallszahl);
        } while (zahlenArray == null);
        return zahlenArray;
    }

    /**
     * Findet heraus, wie viele direkte und inderekte Treffer es gibt.
     *
     * @param derVersuch Ein Versuch, der ausgewertet werden soll.
     * @return
     */
    public String auswerten(Versuch derVersuch) {
        int direkteTreffer = 0;
        int indirekteTreffer = 0;
        for (int i = 0; i < anzahlDerStellen; i++)
            for (int j = 0; j < anzahlDerStellen; j++)
                if (originalZahl[i] == derVersuch.gibVersuchZahl()[j]) {
                    if (i == j)
                        direkteTreffer = direkteTreffer + 1;
                    else
                        indirekteTreffer = indirekteTreffer + 1;
                }
        derVersuch.schreibeDirekteTreffer(direkteTreffer);
        derVersuch.schreibeIndirekteTreffer(indirekteTreffer);
        return "an richtiger Stelle: " + direkteTreffer + "\t" + "an falscher Stelle: " + indirekteTreffer;
    }

    /**
     * Findet heraus, ob alle Ziffern uebereinstimmen
     *
     * @param versuchZahl Die Zahlen, die verglichen werden sollen.
     * @return
     */
    private boolean treffer(int[] versuchZahl) {
        boolean treffer = true;
        for (int i = 0; i < anzahlDerStellen; i++)
            if (originalZahl[i] != versuchZahl[i])
                treffer = false;
        return treffer;
    }

    /**
     * Wandlet die Ziffern eines Zahlen-Arrays in ein String um.
     *
     * @param zahlenArray Die Zahlen, die zu Strings umgewandelt werden sollen.
     * @return
     */
    private String wandleGanzeZahlInString(int[] zahlenArray) {
        String zahlAlsString = "";
        for (int i = 0; i < anzahlDerStellen; i++)
            zahlAlsString = zahlenArray[i] + zahlAlsString;
        return zahlAlsString;
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

    /**
     * Zerteilt eine ganze positive Zahl in Ziffern und prueft gueltigen Wertebereich (0 < zahl < Max).
     * Wenn die Zahl die Voraussetzungen fuer die Mastermind-Spielregeln nicht erfuellt, wird null zurueckgegeben.
     *
     * @param zahl Die Zahl, die nach erfuellung der Voraussetzung fuer die Mastermind-Spielregeln untersucht wird.
     * @return Wenn die Zahl die Voraussetzungen fuer die Mastermind-Spielregeln erfuellt, wird Int-Array zurueckgegeben.
     */
    private int[] bereiteAuf(int zahl) {
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
        return zahlenArray;
    }
}