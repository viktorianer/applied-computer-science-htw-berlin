public class Ameise extends Tier {
    public Ameise() {
        super("Ameise");
    }

    public String liefereInfo() {
        return "Ich bin eine " + super.liefereInfo();
    }
}