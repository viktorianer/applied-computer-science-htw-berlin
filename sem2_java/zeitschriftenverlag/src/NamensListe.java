
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

/**
 * Repraesentiert eine Namensliste aus Nachnamen und Vornamen.
 * Die Nachnamen werden aus der Datei "FamilyNames", die Vornamen aus der Datei
 * "GivenNames" herausgelesen.
 * <p/>
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class NamensListe {
    /**
     * Die einzige Instanz der Klasse NamensListe.
     */
    private static NamensListe instance = null;
    /**
     * Nachnamen-Liste.
     */
    private static List<String> NACHNAMEN;
    /**
     * Vornamen-Liste.
     */
    private static List<String> VORNAMEN;

    /**
     * Erzeugt eine Instanz der Klasse NamensListe, kann aber nicht von aussen
     * aufgerufen werden.
     * Zur erzeugung einer Instanz wird die Methode "erzeugeInstanzVonNamen"
     * genutzt.
     */
    private NamensListe() {
        NACHNAMEN = new ArrayList<>(0);
        VORNAMEN = new ArrayList<>(0);
        Scanner file = null;
        try {
            file = new Scanner(new File("FamilyNames"));
            while (file.hasNext()) {
                NACHNAMEN.add(file.nextLine());
            }
            file = new Scanner(new File("GivenNames"));
            while (file.hasNext()) {
                VORNAMEN.add(file.nextLine());
            }
        } catch (FileNotFoundException fnfe) {
            System.err.printf("\nFehler beim Lesen der Datei: %s\n", fnfe.getMessage());
        } finally {
            if (file != null) {
                file.close();
            }
        }
    }

    /**
     * Erzeugt eine Instanz, die einzige Instanz, der Klasse "NamesListe".
     * <p/>
     *
     * @return Die Instanz der Klasse "NamensListe".
     */
    public static NamensListe getInstance() {
        if (instance == null) {
            instance = new NamensListe();
        }
        return instance;
    }

    /**
     * Liefert einen zufaelligen Nachnamen aus der Nachnamenliste.
     * <p/>
     *
     * @return Ein zufalls Nachnamen aus der Nachnamenliste.
     */
    public String liefereZufallsNachname() {
        Random generator = new Random();
        return NACHNAMEN.get(generator.nextInt(NACHNAMEN.size()));
    }

    /**
     * Liefert einen zufaelligen Vornamen aus der Vornamenliste.
     * <p/>
     *
     * @return Ein zufalls Vorname aus der Vornamenliste.
     */
    public String liefereZufallsVorname() {
        Random generator = new Random();
        return VORNAMEN.get(generator.nextInt(VORNAMEN.size()));
    }
}