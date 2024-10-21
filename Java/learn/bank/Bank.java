import java.util.ArrayList;

/**
 * Klasa reprezentująca bank z listą kont.
 */
public class Bank {
    private ArrayList<Konto> konta;

    public Bank() {
        this.konta = new ArrayList<>();
    }

    public void utworzKonto(String numerKonta) {
        konta.add(new Konto(numerKonta, new Kwota(0, 0)));
    }

    public void wplataNaKonto(String numerKonta, Kwota kwota) {
        Konto konto = znajdzKonto(numerKonta);
        if (konto != null) {
            Kwota nowyStan = Kwota.dodaj(konto.getStan(), kwota);
            konto.setStan(nowyStan);
        }
    }

    public void wyplataZKonta(String numerKonta, Kwota kwota) {
        Konto konto = znajdzKonto(numerKonta);
        if (konto != null) {
            Kwota nowyStan = Kwota.odejmij(konto.getStan(), kwota);
            konto.setStan(nowyStan);
        }
    }

    public Kwota stanKonta(String numerKonta) {
        Konto konto = znajdzKonto(numerKonta);
        if (konto != null) {
            return konto.getStan();
        }
        return null;
    }

    private Konto znajdzKonto(String numerKonta) {
        for (Konto k : konta) {
            if (k.toString().contains(numerKonta)) {
                return k;
            }
        }
        return null;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Konto konto : konta) {
            sb.append(konto).append(" ; ");
        }
        return sb.toString();
    }
}
