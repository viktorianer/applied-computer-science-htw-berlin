/**
 * @author Viktor Schmidt, s0529652
 */
public class Main {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Create Object JDBC_Connection
        // During construction a database connection will be build up
        JDBC_Connection jc = new JDBC_Connection("jdbc:postgresql://db1.f4.htw-berlin.de:5432/s0529652", "s0529652", "vik");
        //send first query to database
        //ResultSet result = jc.executeQuery("select * from mitarbeiter");
        //jc.metadataMitarbeiter(result);
        // send the second query to the database
        //result = jc.executeQuery("select mitarbeiterid, name, hersteller, modell,"
        //        + " von, bis from bestellungen, Mitarbeiter, Auto where "
        //        + "mitarbeiterid = ausleiher and auto = autoid");
        //jc.beispielAusgabe(result);
        System.out.println("Die Datenbank hat " + jc.getRowNums1("mitarbeiter") + " Zeilen");
        System.out.println("Die Datenbank hat " + jc.getRowNums2("mitarbeiter") + " Zeilen");
        System.out.println("Die Datenbank hat " + jc.getRowNums3("mitarbeiter") + " Zeilen");
        jc.closeDatabase();
    }
}
