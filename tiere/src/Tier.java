public class Tier {
    private String art;

    public Tier(String dieArt) {
        art = dieArt;
    }

    public void sprich() {
    }

    public String liefereInfo() {
        return art + ". ";
    }
}