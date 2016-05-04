/**
 * Repraesentiert eine Person mit einem Nachnamen und einem Vornamen.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class Person {
    /**
     * Der Nachname der Person.
     */
    private String nachname;
    /**
     * Der Vorname der Person.
     */
    private String vorname;

    /**
     * Erzeugt eine Person mit einem zufalls Nachnamen und einem zufalls Vornamen.
     */
    public Person() {
        NamensListe namen = NamensListe.getInstance();
        nachname = namen.liefereZufallsNachname();
        vorname = namen.liefereZufallsVorname();
    }

    /**
     * Liefert den Nachnamen der Person.
     *
     * @return Der Nachname der Person.
     */
    public String liefereNachname() {
        return nachname;
    }

    /**
     * Liefert den Vornamen der Person.
     *
     * @return Der Vorname der Person.
     */
    public String liefereVorname() {
        return vorname;
    }
}