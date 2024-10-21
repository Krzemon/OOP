/**
 * Klasa reprezentująca kwotę pieniędzy.
 */
public class Kwota {
    private int grosze;

    public Kwota(int zlote, int grosze) {
        set(zlote, grosze);
    }

    public void set(int zlote, int grosze) {
        this.grosze = zlote * 100 + grosze;
    }

    public static Kwota dodaj(Kwota k1, Kwota k2) {
        return new Kwota(0, k1.grosze + k2.grosze);
    }

    public static Kwota odejmij(Kwota k1, Kwota k2) {
        return new Kwota(0, k1.grosze - k2.grosze);
    }

    @Override
    public String toString() {
        int zlote = grosze / 100;
        int gr = Math.abs(grosze % 100);
        return String.format("%dzl %02dgr", zlote, gr);
    }
}
