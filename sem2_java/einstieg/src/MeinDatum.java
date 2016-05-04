import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 * Repraesentiert ein Datum, das aus Tag (1 - 31),
 * Monat (1  12) und Jahr besteht (ganze Zahl).
 *
 * @author Viktor Schmidt, s0529652
 */
public class MeinDatum {
    /**
     * Der Tag des Datums.
     */
    private int tag;
    /**
     * Der Monat des Datums.
     */
    private int monat;
    /**
     * Das Jahr des Datums.
     */
    private int jahr;

    /**
     * Erzeugt das aktuelle Datum, d.h. das aktuell im
     * Rechner vorhandene Datum.
     */
    public MeinDatum() {
        GregorianCalendar kalender = new GregorianCalendar();
        tag = kalender.get(Calendar.DAY_OF_MONTH);
        monat = kalender.get(Calendar.MONTH) + 1;
        jahr = kalender.get(Calendar.YEAR);
    }

    /**
     * Liefert das Datum in der Form <code>tt.mm.jjjj</code>.
     *
     * @return Das Datum in der Form <code>tt.mm.jjjj</code>.
     */
    public String liefereDatum() {
        return tag + ". " + monat + ". " + jahr;
    }
}