public class Hund extends LieblingsTier {
    private String rasse;

    public Hund(String derName, String dieRasse) {
        super("Hund", derName);
        rasse = dieRasse;
    }

    public void sprich() {
        System.out.print("Wau, wau!");
    }

    public String liefereInfo() {
        return "Ich bin ein " + super.liefereInfo() +
                "Ich bin ein " + rasse + ". ";
    }
}