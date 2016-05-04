import java.util.Scanner;

/**
 * Repraesentiert ein Menue, das aus String-Array besteht.
 * Jedes Arrayfeld repraesentiert ein Menueeintrag und ist von Typ String.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Menue {
    /**
     * Das String-Array, dessen Komponenten Menuetext enthalten.
     */
    private String menue[];

    /**
     * Erzeugt ein Menue, das aus String-Array besteht.
     * Jedes Arrayfeld repraesentiert ein Menueeintrag und ist von Typ String.
     *
     * @param dasMenue Das Array, dessen Komponenten Menuetext enthalten.
     */
    public Menue(String dasMenue[]) {
        menue = dasMenue;
    }

    /**
     * Schreibt ein Menue und erfasst eine Anwort mit einer ganzen Zahl und vergleicht diese
     * mit dem Wertebereich zwischen 1 und menue.length.
     * Trifft die Eingabe auf keinen der beiden Werte zu oder einen Wert dazwischen wird eine Fehlermeldung
     * ausgeben, die noch ein mal den gewuenschten Wertebereich, also 1 bis menue.length, anzeigt.
     *
     * @return Die erfasste Eingabe, ganze Zahl wird zurueckgegeben.
     */
    public int waehleAusMenue() {
        Scanner eingabe = new Scanner(System.in);
        int eingabePuffer;
        schreibeMenue();
        do {
            System.out.printf("\nIhre Wahl:  ");
            eingabePuffer = eingabe.nextInt();
            if (eingabePuffer > menue.length || eingabePuffer <= 0) {
                System.out.printf("\nDiesen Menuepunkt gibt es nicht. Bitte versuchen Sie es noch einmal.");
            }
        } while (eingabePuffer > menue.length || eingabePuffer <= 0);
        return eingabePuffer;
    }

    /**
     * Schreibt ein nummeriertes Menue.
     */
    private void schreibeMenue() {
        for (int i = 0; i < menue.length; i++)
            System.out.printf("\n(%d) %s", i + 1, menue[i]);
        System.out.printf("\n");
    }
}