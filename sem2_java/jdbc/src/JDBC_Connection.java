/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.*;

/**
 * @author hendrik gaertner
 */
public class JDBC_Connection {
    // private variables to encapsulate database tier
    private Connection dbcon;
    private Statement stmt;

    public JDBC_Connection(String db_url, String username, String password) {
    /*  Just for orlder java versions -- before java 1.6
    try
    {
      Class.forName("org.postgresql.Driver");
    }
    catch (Exception e)
    {
      System.out.println("Driver not found: "+e.toString());
      System.exit(0);
    } */

        // create database connection and a statement object to sent queries
        try {
            dbcon = DriverManager.getConnection(db_url, username, password);
            stmt = dbcon.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
        } catch (Exception e) {
            System.out.println("Can't get a connection: " + e.toString());
            System.exit(0);
        }
    }

    // Method to send queries to DB-Server
    // Returns ResultSet if query successfull
    // null otherwise
    public ResultSet executeQuery(String query) {
        try {
            return stmt.executeQuery(query);
        } catch (Exception e) {
            System.out.println("Can't execute Query!" + e.toString());
        }
        return null;
    }

    // get Metadata (Schema) of the query result
    // create ResultSetMetaData-Object which contains all information
    public void metadataMitarbeiter(ResultSet result) {
        ResultSetMetaData meda;
        int num_columns = 0;
        if (result != null) {
            try {
                meda = result.getMetaData();
                // for example the number of columns
                num_columns = meda.getColumnCount();
            } catch (Exception e) {
                System.out.println("Error: " + e.toString());
            }
            System.out.println("Die Tabelle Mitarbeiter hat " + num_columns + " Spalten.");
            // get all Data of the result by using the getString(int i) function
            try {
                while (result.next()) {
                    for (int i = 1; i <= num_columns; i++) {
                        System.out.println(result.getString(i));
                    }
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.toString());
            }
        }
    }

    // sinnlose Methode für ein Beispiel wie man die Rückgabe (ResultSet) formatieren kann
    public void beispielAusgabe(ResultSet result) {
        if (result != null) {
            try {
                //get all data by using the column names for access
                while (result.next()) {
                    System.out.println("Der Mitarbeiter mit der ID " + result.getInt("mitarbeiterid"));
                    System.out.println("und dem Namen " + result.getString("name"));
                    System.out.println("hat vom " + result.getDate("von") + " einen " +
                            result.getString("hersteller") + " " +
                            result.getString("Modell") + " bestellt.");
                    System.out.println();
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.toString());
            }
        }
    }

    // Methode zum ausgeben der Anzahl der Zeilen einer bestimmten Tabelle
    // Dazu wird Query select * from ... und die Methode next() benutzt
    public int getRowNums1(String tabName) {
        int anuahlZeilen = 0;
        ResultSet result = this.executeQuery("select * from " + tabName + ";");
        try {
            while (result.next()) {
                anuahlZeilen++;
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.toString());
        }
        return anuahlZeilen;
    }

    // Methode zum ausgeben der Anzahl der Zeilen einer bestimmten Tabelle
    // Dazu wird Query select count(*) und die Methode getInt() benutzt
    public int getRowNums2(String tabName) {
        int anuahlZeilen = 0;
        ResultSet result = this.executeQuery("select count(*) from " + tabName + ";");
        try {
            result.next();
            anuahlZeilen = result.getInt(1);
        } catch (Exception e) {
            System.out.println("Error: " + e.toString());
        }
        return anuahlZeilen;
    }

    // Methode zum ausgeben der Anzahl der Zeilen einer bestimmten Tabelle
    // Dazu wird Query select count(*) und die Methode getInt() benutzt
    public int getRowNums3(String tabName) {
        int anuahlZeilen = 0;
        ResultSet result = this.executeQuery("select * from " + tabName + ";");
        try {
            result.absolute(-1);
            anuahlZeilen = result.getRow();
        } catch (Exception e) {
            System.out.println("Error: " + e.toString());
        }
        return anuahlZeilen;
    }

    // Method to close the database
    public void closeDatabase() {
        try {
            stmt.close();
            dbcon.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.toString());
        }
        System.out.println("Database closed");
    }
}

