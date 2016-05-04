/**
 * Repraesentiert ein Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
 * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public class TemperaturenUmrechner {
    /**
     * Die Höhe der Temperatur.
     */
    private double temperatur;
    /**
     * Die Einheit in der die Temperatur angegeben wurde.
     * Dabei steht die 1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit.
     */
    private int einheit;
    /**
     * Der Einheitname in der die Temperatur angegeben wurde:
     * Kelvin, Grad Celsius, Grad Reaumur oder Grad Fahrenheit.
     */
    private String einheitName;

    /**
     * Erzeugt einen  Umrechner fuer bestimmte Temperatur, die aus der Hohe der Temperatur (-459.67 - 10000)
     * und Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit) besteht.
     *
     * @param dieTemperatur Die Hohe der Temperatur (-459.67 bis 10000).
     * @param dieEinheit    Die Einheit (1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit).
     */
    public TemperaturenUmrechner(double dieTemperatur, int dieEinheit) {
        boolean inputOk = (-459.67 <= dieTemperatur && dieTemperatur <= 10000.0) &&
                (1 <= dieEinheit && dieEinheit <= 4);
        if (inputOk) {
            temperatur = dieTemperatur;
            einheit = dieEinheit;
            switch (einheit) {
                case 1:
                    einheitName = "Kelvin";
                    break;
                case 2:
                    einheitName = "Grad Celsius";
                    break;
                case 3:
                    einheitName = "Grad Reaumur";
                    break;
                default:
                    einheitName = "Grad Fahrenheit";
                    break;
            }
        } else
            throw new IllegalArgumentException();
    }

    /**
     * Liefert die Temperatur in Kelvin.
     *
     * @return Die Höhe der Temperatur in Kelvin.
     */
    public double liefereTemperaturInKelvin() {
        double temperaturInKelvin;
        switch (einheit) {
            case 1:
                temperaturInKelvin = temperatur;
                break;
            case 2:
                temperaturInKelvin = temperatur + 273.15;
                break;
            case 3:
                temperaturInKelvin = temperatur * 1.25 + 273.15;
                break;
            default:
                temperaturInKelvin = (temperatur + 459.67) * (5 / 9.0);
                break;
        }
        return temperaturInKelvin;
    }

    /**
     * Liefert die Temperatur in Grad Celsius.
     *
     * @return Die Höhe der Temperatur in Grad Celsius.
     */
    public double liefereTemperaturInCelsius() {
        double temperaturInCelsius;
        switch (einheit) {
            case 1:
                temperaturInCelsius = temperatur - 273.15;
                break;
            case 2:
                temperaturInCelsius = temperatur;
                break;
            case 3:
                temperaturInCelsius = temperatur * 1.25;
                break;
            default:
                temperaturInCelsius = (temperatur - 32) * (5 / 9.0);
                break;
        }
        return temperaturInCelsius;
    }

    /**
     * Liefert die Temperatur in Grad Réaumur.
     *
     * @return Die Höhe der Temperatur in Grad Reaumur.
     */
    public double liefereTemperaturInReaumur() {
        double temperaturInReaumur;
        switch (einheit) {
            case 1:
                temperaturInReaumur = (temperatur - 273.15) * 0.8;
                break;
            case 2:
                temperaturInReaumur = temperatur * 0.8;
                break;
            case 3:
                temperaturInReaumur = temperatur;
                break;
            default:
                temperaturInReaumur = (temperatur - 32) * (4 / 9.0);
                break;
        }
        return temperaturInReaumur;
    }

    /**
     * Liefert die Temperatur in Grad Fahrenheit.
     *
     * @return Die Höhe der Temperatur in Grad Fahrenheit.
     */
    public double liefereTemperaturInFahrenheit() {
        double temperaturInFahrenheit;
        switch (einheit) {
            case 1:
                temperaturInFahrenheit = temperatur * 1.8 - 459.67;
                break;
            case 2:
                temperaturInFahrenheit = temperatur * 1.8 + 32;
                break;
            case 3:
                temperaturInFahrenheit = temperatur * 2.25 + 32;
                break;
            default:
                temperaturInFahrenheit = temperatur;
                break;
        }
        return temperaturInFahrenheit;
    }

    /**
     * Liefert die Einheit der Temperatur.
     * Die Einheit wurd durch eine ganze Zahl repraesentiert:\n
     * 1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit.
     *
     * @return Die Einheit der Temperatur: 1 fuer Kelvin, 2 fuer Grad Celsius, 3 fuer Grad Reaumur und 4 fuer Grad Fahrenheit.
     */
    public int liefereEinheit() {
        return einheit;
    }

    /**
     * Liefert dem Einheitnamen der Temperatur.
     * (Kelvin, Grad Celsius, Grad Reaumur oder Grad Fahrenheit).
     *
     * @return Der Einheitenname der Temperatur, also Kelvin, Grad Celsius, Grad Reaumur oder Grad Fahrenheit.
     */
    public String liefereEinheitName() {
        return einheitName;
    }
}