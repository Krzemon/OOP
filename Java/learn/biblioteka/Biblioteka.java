public class Biblioteka {
    private class Wezel {
        Ksiazka ksiazka;
        Wezel lewy, prawy;

        Wezel(Ksiazka ksiazka) {
            this.ksiazka = ksiazka;
            lewy = prawy = null;
        }
    }

    private Wezel korzen;

    // Konstruktor domyślny
    public Biblioteka() {
        korzen = null;
    }

    // Metoda dodająca książkę do drzewa
    public void dodaj(Ksiazka k) {
        korzen = dodajRekurencyjnie(korzen, k);
    }

    private Wezel dodajRekurencyjnie(Wezel aktualny, Ksiazka k) {
        if (aktualny == null) {
            return new Wezel(k);
        }
        if (k.getId() < aktualny.ksiazka.getId()) {
            aktualny.lewy = dodajRekurencyjnie(aktualny.lewy, k);
        } else if (k.getId() > aktualny.ksiazka.getId()) {
            aktualny.prawy = dodajRekurencyjnie(aktualny.prawy, k);
        } else {
            System.out.println("Książka z ID " + k.getId() + " już istnieje.");
        }
        return aktualny;
    }

    // Metoda do wypisania drzewa binarnego
    public void wypiszDrzewo() {
        wypiszRekurencyjnie(korzen, 0);
    }

    private void wypiszRekurencyjnie(Wezel wezel, int poziom) {
        if (wezel != null) {
            wypiszRekurencyjnie(wezel.prawy, poziom + 1);
            for (int i = 0; i < poziom; i++) {
                System.out.print("    ");
            }
            wezel.ksiazka.wypisz();
            wypiszRekurencyjnie(wezel.lewy, poziom + 1);
        }
    }

    // Metoda wyszukująca książkę po tytule
    public Ksiazka wyszukajTytul(String tytul) {
        long startTime = System.nanoTime();
        Ksiazka wynik = wyszukajTytulRekurencyjnie(korzen, tytul);
        long endTime = System.nanoTime();
        System.out.println("Czas wyszukiwania tytułu: " + (endTime - startTime) + " ns");
        return wynik;
    }

    private Ksiazka wyszukajTytulRekurencyjnie(Wezel aktualny, String tytul) {
        if (aktualny == null) {
            return null;
        }
        if (aktualny.ksiazka.getTytul().equalsIgnoreCase(tytul)) {
            return aktualny.ksiazka;
        }
        Ksiazka lewyWynik = wyszukajTytulRekurencyjnie(aktualny.lewy, tytul);
        if (lewyWynik != null) {
            return lewyWynik;
        }
        return wyszukajTytulRekurencyjnie(aktualny.prawy, tytul);
    }

    // Metoda wyszukująca książkę po ID
    public Ksiazka wyszukajID(int id) {
        long startTime = System.nanoTime();
        Ksiazka wynik = wyszukajIDRekurencyjnie(korzen, id);
        long endTime = System.nanoTime();
        System.out.println("Czas wyszukiwania ID: " + (endTime - startTime) + " ns");
        return wynik;
    }

    private Ksiazka wyszukajIDRekurencyjnie(Wezel aktualny, int id) {
        if (aktualny == null) {
            return null;
        }
        if (id == aktualny.ksiazka.getId()) {
            return aktualny.ksiazka;
        }
        if (id < aktualny.ksiazka.getId()) {
            return wyszukajIDRekurencyjnie(aktualny.lewy, id);
        } else {
            return wyszukajIDRekurencyjnie(aktualny.prawy, id);
        }
    }
}
