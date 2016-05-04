import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;

/**
 * Repraesentiert einen Verlag, der eine bestimmte Anzahl an Zeitungen verkauft und eine bestimmte Anzahl an Verkaefer anstellt.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Verlag {
    /**
     * Die Zeitungen, die der Verlag herstellt und verkauft.
     */
    private ArrayList<Zeitung> produzierteZeitungen;
    /**
     * Die Zeitungsverkaefer, die beim Verlag angestellt sind und die Zeitung verkaufen.
     */
    private ArrayList<Zeitungsverkaefer> zeitungsVerkaefer;

    /**
     * Erzeugt einen Verlag mit bestimmten Zeitungen und bestimmten Anzahl an Zeitungsverkaefer.
     *
     * @param dieProduzierteZeitung         Die Zeitung, die produziert und verkauft werden soll.
     * @param dieAnzahlDerZeitungsVerkaefer Die Anzahl der Angestellten Zeitungsverkaefer.
     */
    public Verlag(ArrayList<Zeitung> dieProduzierteZeitung, int dieAnzahlDerZeitungsVerkaefer) {
        produzierteZeitungen = dieProduzierteZeitung;
        zeitungsVerkaefer = new ArrayList<>(0);
        if (dieAnzahlDerZeitungsVerkaefer > 0)
            for (int i = 0; i < dieAnzahlDerZeitungsVerkaefer; i++) {
                zeitungsVerkaefer.add(new Zeitungsverkaefer(produzierteZeitungen));
            }
        else
            throw new IllegalArgumentException();
    }

    /**
     * Schreibt alle Tage der Woche, fuer die eine Tagesstatistik vorliegt.
     */
    public void schreibeTagesstatistik() {
        String programmMenue[] = new String[Wochentag.values().length];
        for (int i = 0; i < Wochentag.values().length; i++) {
            programmMenue[i] = Wochentag.values()[i].liefereBezeichnung();
        }
        Menue menue = new Menue(programmMenue);
        schreibeTagesstatistikDesTages(Wochentag.values()[menue.waehleAusMenue() - 1]);

    }

    /**
     * Schreibt eine Tagesstatistik fuer einen bestimmten Tag. Die Tabelle ist alphabetisch nach Nachnamen sortiert.
     *
     * @param derTag Der Tag, fuer den die Tagestatistik ausgegeben werden soll.
     */
    private void schreibeTagesstatistikDesTages(Wochentag derTag) {
        int[] anzahlGesamt = new int[produzierteZeitungen.size()];
        double[] umsatzGesamt = new double[produzierteZeitungen.size()];
        sortiereVerkaeferAlphabetisch();
        System.out.println();
        System.out.printf("TAGESUMSATZ\n");
        System.out.printf("%-30s", derTag.liefereBezeichnung().toUpperCase());
        for (Zeitung zeitung : produzierteZeitungen) {
            System.out.printf("%-30s", zeitung.liefereNamen());
        }
        for (Zeitungsverkaefer zeitungsverkaefer : zeitungsVerkaefer) {
            System.out.printf("\n%-30s", zeitungsverkaefer.liefereNachname() + " " + zeitungsverkaefer.liefereVorname());
            for (int j = 0; j < produzierteZeitungen.size(); j++) {
                System.out.printf("%-10d", zeitungsverkaefer.liefereTagesstatistik(derTag, produzierteZeitungen.get(j)));
                System.out.printf("%-20.2f", zeitungsverkaefer.liefereTagesumsatz(derTag, produzierteZeitungen.get(j)));
                anzahlGesamt[j] += zeitungsverkaefer.liefereTagesstatistik(derTag, produzierteZeitungen.get(j));
                umsatzGesamt[j] += zeitungsverkaefer.liefereTagesumsatz(derTag, produzierteZeitungen.get(j));
            }
        }
        System.out.printf("\n%-30s", "Summe");
        for (int i = 0; i < produzierteZeitungen.size(); i++) {
            System.out.printf("%-10d%-20.2f", anzahlGesamt[i], umsatzGesamt[i]);
        }
        System.out.println();
    }

    /**
     * Sortiert die Verkaufer absteigend oder aufsteigend nach Verdienst und
     * gibt die Verkaufsstatistik (Name und Verdienst je Verkaefer) fuer die ganze Woche aus.
     *
     * @param dieSortierung Die Sortierung, aufsteigend oder absteigend nach dem Verdienst.
     */
    public void schreibeVerkaeferStatistik(String dieSortierung) {
        if (dieSortierung.equals("-")) {
            Collections.sort(zeitungsVerkaefer);
            Collections.reverse(zeitungsVerkaefer);
        } else
            Collections.sort(zeitungsVerkaefer);
        schreibeVerkaeferStatistik();

    }

    /**
     * Schreibt die Verkaufsstatistik (Name und Verdienst je Verkaefer) fuer die ganze Woche.
     */
    private void schreibeVerkaeferStatistik() {
        System.out.println();
        System.out.printf("STUDENTENSTATISTIK:\n");
        System.out.printf("%-30s%-20s", "Name", "Verdienst");
        for (Zeitungsverkaefer zeitungsverkaefer : zeitungsVerkaefer) {
            System.out.printf("\n%-30s", zeitungsverkaefer.liefereNachname() + " " + zeitungsverkaefer.liefereVorname());
            System.out.printf("%-20.2f", zeitungsverkaefer.liefereVerdienst());
        }
        System.out.println();
    }

    private int ermitteleFeldbreiteInWare(Zeitung[] dieWare) {
        int feldbreite = dieWare[0].liefereAttributTextLaenge();
        for (Zeitung ware : dieWare)
            if (ware.liefereAttributTextLaenge() > feldbreite)
                feldbreite = ware.liefereAttributTextLaenge();
        return feldbreite;
    }

    /**
     * Sortiert die Verkaufer alphabetisch nach Nachnamen.
     */
    private void sortiereVerkaeferAlphabetisch() {
        Collator collator = Collator.getInstance(Locale.GERMAN);
        int n = zeitungsVerkaefer.size();
        boolean vertauscht;
        do {
            vertauscht = false;
            for (int i = 0; i <= n - 2; i++) {
                if (collator.compare(zeitungsVerkaefer.get(i).liefereNachname(), zeitungsVerkaefer.get(i + 1).liefereNachname()) > 0) {
                    Collections.swap(zeitungsVerkaefer, i, i + 1);
                    vertauscht = true;
                }
            }
        } while (vertauscht && n > 1);
    }
}