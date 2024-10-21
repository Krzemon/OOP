/**
 * Klasa reprezentująca konto bankowe.
 */
public class Konto {
    private String numerKonta;
    private Kwota stan;

    public Konto(String numerKonta, Kwota stan) {
        this.numerKonta = numerKonta;
        this.stan = new Kwota(0, stan.grosze); // Tworzymy nowy obiekt, aby uniknąć zmiany oryginalnej kwoty
    }

    public Kwota getStan() {
        return stan;
    }

    public void setStan(Kwota nowyStan) {
        this.stan = new Kwota(0, nowyStan.grosze);
    }

    @Override
    public String toString() {
        return "[" + numerKonta + "] " + stan;
    }
}
