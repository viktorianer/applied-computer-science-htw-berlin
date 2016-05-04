
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 * Repraesentiert einen Tagesverkauf eines Versandhauses.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Tagesverkauf implements Serializable {
    /**
     * Die Medien, die an einem Tag verkauft wurden.
     */
    private ArrayList<Medium> verkaufteMedien;

    /**
     * Erzeugt eine zufaellige Liste an Medien, die an einem Tag verkauft wurden.
     * Dabei kann keiner der Medien mehr als 10 mal nach einander verkauft werden.
     *
     * @param dieAngeboteneMedien Die Medien, die durch Versandhaus (etc.) angeboten werden und zu den eine zufaellige Verkaufsstatistik erzeugt werden soll.
     */
    public Tagesverkauf(ArrayList<Medium> dieAngeboteneMedien) {
        verkaufteMedien = new ArrayList<>(0);
        Random random = new Random();
        Medium medium;
        int zufallAnzahlVerkaefe = (50 + random.nextInt(250));
        for (int j = 0; j < zufallAnzahlVerkaefe; j++) {
            medium = dieAngeboteneMedien.get(random.nextInt(dieAngeboteneMedien.size()));
            int zufallAnzahlKaefe = random.nextInt(9) + 1;
            for (int i = 0; i < zufallAnzahlKaefe; i++) {
                verkaufteMedien.add(medium);
            }
        }
    }

    /**
     * Liefert die Medien, die an diesem Tag verkauft wurden.
     *
     * @return Die verkauften Medien.
     */
    public ArrayList<Medium> verkaufsUebersicht() {
        return verkaufteMedien;
    }

    /**
     * Schreibt eine Verkaufsstatistik auf dem Bildschirm.
     */
    public void schreibVerkaufsstatistik() {
        ArrayList<MedienVerkaufsStatistik> statistik = new ArrayList<>(0);
        ArrayList<Medium> schwarzeListe = new ArrayList<>(0);
        for (int i = 0; i < verkaufteMedien.size(); i++) {
            if (!schwarzeListe.contains(verkaufteMedien.get(i))) {
                statistik.add(new MedienVerkaufsStatistik(verkaufteMedien.get(i),
                        Collections.frequency(verkaufteMedien, verkaufteMedien.get(i))));
            }
            schwarzeListe.add(verkaufteMedien.get(i));
        }
        Collections.sort(statistik);
        for (int i = 0; i < statistik.size(); i++) {
            System.out.printf("\n%3d) %s", i + 1, statistik.get(i).toString());
        }
        System.out.printf("\n");
    }
}
