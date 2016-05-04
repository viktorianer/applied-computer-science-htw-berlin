public class Kuh extends Tier {
    public Kuh() {
        super("Kuh");
    }

    public void sprich() {
        System.out.print("Muuuh!");
    }

    public String liefereInfo() {
        return "Ich bin eine " + super.liefereInfo();
    }
}