import java.util.Scanner;

/**
 * Ein Programm, das einen Umrechner fuer bestimmte Temperatur repraesentiert.
 * Die Temperatur besteht aus der Hohe der Temperatur (-459.67 - 10000)
 * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit).
 * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
 * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class UmrechnungVonTemperaturenMain {
    /**
     * Einstiegspunkt des Programms.
     * main ist (zunächst) die einzige Methode der Klasse.
     * Java schreibt vor, das main immer public und static ist.
     * stellt sich heraus, dass die Aufgaben von main komplex sind, setzen wir zusätzlich geeignete Hilfsmethoden ein
     * die dann stets private und static sind.
     * Dadurch wird Main zu einer aus objektorientierter Sicht völlig untypischen Klasse,
     * die natürlich die genannten Gütekriterien nicht erfüllt.
     * Diese Häßlichkeit nehmen wir in Kauf.
     */
    private UmrechnungVonTemperaturenMain() {
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * Erzeugt einen  Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
     * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
     * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
     * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
     *
     * @param args Wird nicht genutzt.
     */
    public static void main(String[] args) {
        boolean antwort = false;
        String programmMenue[] = {"Temperaturumrechner", "Programm beenden"};
        do {
            Menue menue = new Menue(programmMenue);
            switch (menue.waehleAusMenue()) {
                case 1:
                    benutzerFuerung();
                    break;
                default:
                    System.out.printf("\nDas Programm wird beendet. See You!\n");
                    antwort = true;
                    break;
            }
        } while (!antwort);
    }

    /**
     * Erzeugt eine Benutzerfuerung durch das Programm und nimmt Eingaben entgegen.
     * Erzeugt einen  Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
     * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
     * Nach dem der Benutzer nach der Einheit und der Hohe der Temperatur befragt wurde gibt das Programm die Umrechnung,
     * in die jeweils verbleibende drei Einheiten, auf dem Bildschirm aus.
     */
    private static void benutzerFuerung() {
        System.out.printf("\nDas Programm rechnet die eingegebene Temperatur in verschiedene Temperatureinheiten um.\n");
        Scanner eingabe = new Scanner(System.in);
        System.out.println("\nBitte wählen Sie die Einheit der Temperatur die eingeben wird:  ");
        String einheiten[] = {"Kelvin", "Grad Celsius", "Grad Réaumur", "Grad Fahrenheit"};
        Menue menueEinheiten = new Menue(einheiten);
        int einheit = menueEinheiten.waehleAusMenue();
        System.out.print("Bitte geben sie die Hoehe der Temperatur ein:  ");
        double temperatur = eingabe.nextDouble();
        TemperaturenUmrechner tempUmrechner = new TemperaturenUmrechner(temperatur, einheit);
        schreibeTemperaturUmrechnung(tempUmrechner);
    }

    /**
     * Erzeugt die Ausgabe der Umrechnungen in die jeweils verbleibende drei Einheiten und gibt diese auf dem Bildschirm aus.
     *
     * @param temperaturenUmrechner Ein Objekt der Klasse TemperaturenUmrechner mit der Temperatur und deren Einheit.
     */
    private static void schreibeTemperaturUmrechnung(TemperaturenUmrechner temperaturenUmrechner) {
        System.out.printf("\n");
        switch (temperaturenUmrechner.liefereEinheit()) {
            case 1:
                System.out.printf("%10.2f%-40s", temperaturenUmrechner.liefereTemperaturInKelvin(), " Kelvin entsprechen:");
                break;
            case 2:
                System.out.printf("%10.2f%-40s", temperaturenUmrechner.liefereTemperaturInCelsius(), " Grad Celsius entsprechen:");

                break;
            case 3:
                System.out.printf("%10.2f%-40s", temperaturenUmrechner.liefereTemperaturInReaumur(), " Grad Réaumur entsprechen:");
                break;
            default:
                System.out.printf("%10.2f%-40s", temperaturenUmrechner.liefereTemperaturInFahrenheit(), " Grad Fahrenheit entsprechen:");
                break;
        }
        if (temperaturenUmrechner.liefereEinheit() != 1)
            System.out.printf("%10.2f%-10s\n%50s", temperaturenUmrechner.liefereTemperaturInKelvin(), " Kelvin", "");
        if (temperaturenUmrechner.liefereEinheit() != 2)
            System.out.printf("%10.2f%-10s\n%50s", temperaturenUmrechner.liefereTemperaturInCelsius(), " Grad Celsius", "");
        if (temperaturenUmrechner.liefereEinheit() != 3)
            System.out.printf("%10.2f%-10s\n%50s", temperaturenUmrechner.liefereTemperaturInReaumur(), " Grad Réaumur", "");
        if (temperaturenUmrechner.liefereEinheit() != 4)
            System.out.printf("%10.2f%-10s\n", temperaturenUmrechner.liefereTemperaturInFahrenheit(), " Grad Fahrenheit");
    }
}