public class LieblingsTier extends Tier {
    private String name;

    public LieblingsTier(String dieArt, String derName) {
        super(dieArt);
        name = derName;
    }

    public String liefereInfo() {
        return super.liefereInfo() + "Ich heisse " + name + ". ";
    }
}