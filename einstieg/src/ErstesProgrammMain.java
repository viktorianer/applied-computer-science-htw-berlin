public class ErstesProgrammMain {
    public static void main(String[] args) {
        schreibe("\n");
        MeinDatum datum = new MeinDatum();
        schreibe("Heute ist der " + datum.liefereDatum() + ".");
        schreibe("\n\n");
        schreibe("Mein erstes Java-Programm funktioniert!");
        schreibe("\n\n");
    }

    private static void schreibe(String text) {
        System.out.print(text);
    }
}