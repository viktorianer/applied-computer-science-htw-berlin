public class TiereMain {
    private TiereMain() {
    }

    public static void main(String[] args) {
        Tier[] viecher = {new Hund("Lumpi", "Dackel"),
                new Katze("Pussy", "Siamkatze"),
                new Kuh(),
                new Ameise(),
                new Katze("Mieze", "Perserkatze"),
                new Hund("Tarzan", "Pinscher"),
                new Hund("Lu", "Wolfsspitz")
        };
        for (Tier kreatur : viecher)
            schreibeTierInfo(kreatur);

    }

    private static void schreibeTierInfo(Tier einTier) {
        System.out.print(einTier.liefereInfo());
        einTier.sprich();
        System.out.println();
    }
}