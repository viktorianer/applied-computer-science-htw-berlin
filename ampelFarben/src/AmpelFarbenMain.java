/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @author viktor
 */
public class AmpelFarbenMain {
    public static void main(String[] args) {
        schreibeBelehrung(AmpelFarbe.ROT);
        schreibeBelehrung(AmpelFarbe.GRUEN);
        schreibeBelehrungSwitch(AmpelFarbe.GELB);
    }

    private static void schreibeBelehrung(AmpelFarbe farbe) {
        String info = "Bei ";
        if (farbe == AmpelFarbe.GRUEN)
            info += (AmpelFarbe.GRUEN + " kannst Du fahren.");
        else if (farbe == AmpelFarbe.ROT)
            info += (AmpelFarbe.ROT + " musst Du warten.");
        else
            info += (AmpelFarbe.GELB + " darfst Du nur fahren, " +
                    "wenn Du nicht rechtzeitig bremsen kannst.");
        System.out.println(info);
    }

    private static void schreibeBelehrungSwitch(AmpelFarbe farbe) {
        String info = "Bei ";
        switch (farbe) {
            case ROT:
                info += (AmpelFarbe.ROT + " musst Du warten.");
                break;
            case GELB:
                info += (AmpelFarbe.GELB + " darfst Du nur fahren, " +
                        "wenn Du nicht rechtzeitig bremsen kannst.");
                break;
            case GRUEN:
                info += (AmpelFarbe.GRUEN + " kannst Du fahren.");
                break;
            default:
                break;
        }
        System.out.println(info);
    }
}
