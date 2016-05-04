public class Katze extends LieblingsTier {
    private String rasse;

    public Katze(String derName, String dieRasse) {
        super("Katze", derName);
        rasse = dieRasse;
    }

    public void sprich() {
        System.out.print("Miau, miau.");
    }

    public String liefereInfo() {
        return "Ich bin eine " + super.liefereInfo() +
                "Ich bin eine " + rasse + ". ";
    }
}