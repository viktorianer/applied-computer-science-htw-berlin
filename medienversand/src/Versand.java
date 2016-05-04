
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Random;

/**
 * Repraesentiert einen Versandhaus, der bestimmte Anzahl an Medien im Angebot hat und ueber seinen Tagesumsatz Statistik fuert.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Versand implements Serializable {
    /**
     * Die Medien, die zum Verkauf angeboten werden.
     */
    private ArrayList<Medium> medien;
    /**
     * Die Taegliche Tagesstatistik ueber Verkauf der angebotenen Medien.
     */
    private ArrayList<Tagesverkauf> tagesverkauf;

    /**
     * Erzeugt eine Versand aus zwei Dateien in dem zuvor die ArrayListen Medien und Tagesverkauf gespreichert wurden.
     * In der Datei "Medien.dat" ist eine ArrayList an Medien gespreichert.
     * In der Datei "Verkauf.dat" ist eine ArrayList an Tasgesverkaeufen gespeichert.
     * Die Daten muessen serialesiert, ObjectInputStream->BufferedInputStream->FileInputStream, vorliegen.
     */
    public Versand() {
        medien = (ArrayList<Medium>) Dateienbehandlung.laden("Medien.dat");
        tagesverkauf = (ArrayList<Tagesverkauf>) Dateienbehandlung.laden("Verkauf.dat");
    }

    /**
     * Erzeugt eine Versand mit bestimmten Anzahl an zufaelligen Medien und einer zufaelligen Verkaufsstatistik (pro Tag).
     * Die erzeugten Listen werden danach in zwei Dateien gespeichert.
     * In der Datei "Medien.dat" ist eine ArrayList an Medien gespreichert.
     * In der Datei "Verkauf.dat" ist eine ArrayList an Tasgesverkaeufen gespeichert.
     * Die Daten werden serialesiert, ObjectOutputStream->BufferedOutputStream->FileOutputStream, gespeichert.
     *
     * @param dieAnzahlMedien Die Anzahl der Medien, die erzeugt werden sollen.
     */
    public Versand(int dieAnzahlMedien) {
        medien = new ArrayList<>(0);
        for (int i = 0; i < dieAnzahlMedien; i++) {
            try {
                medien.add(liefereZufallMedium());
            } catch (IllegalArgumentException iae) {
                System.out.print(iae);
            }
        }
        tagesverkauf = new ArrayList<>(0);
        for (int i = 0; i < 365; i++) {
            tagesverkauf.add(new Tagesverkauf(medien));
        }
        Dateienbehandlung.speichern(medien, "Medien.dat");
        Dateienbehandlung.speichern(tagesverkauf, "Verkauf.dat");
    }

    /**
     * Schreibt die im Angebot befindliche Medien.
     */
    public void schreibVerkaufteMedien() {
        System.out.printf("\nUnser Angebot an Medien (Buecher, CDs, DVDs):\n");
        for (int i = 0; i < medien.size(); i++) {
            System.out.printf("\n%d) %-70s", i + 1, medien.get(i).toString());
        }
        System.out.println();
    }

    /**
     * Schreibt eine Verkaufsuebersicht fuer einen bestimmten Tag des Jahres (1-365).
     *
     * @param derTag Der Tag, zu dem eine Verkaufsuebersicht ausgegeben werden soll.
     */
    public void schreibVerkaufsuebersucht(int derTag) {
        System.out.printf("\nVerkaufsuebersicht fuer den %d. Tag.\n", derTag);
        tagesverkauf.get(derTag - 1).schreibVerkaufsstatistik();
    }

    /**
     * Liefert ein zufaelliges Medium.
     *
     * @return Ein zufaelliges Medium.
     */
    private Medium liefereZufallMedium() {
        Random random = new Random();
        Medium zufallsMedium;
        switch (random.nextInt(3)) {
            case 0:
                zufallsMedium = new Buch();
                break;
            case 1:
                zufallsMedium = new CD();
                break;
            default:
                zufallsMedium = new DVD();
        }
        return zufallsMedium;
    }
}
