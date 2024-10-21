public class Ksiazka {
    private String tytul;
    private int id;
    private static int liczbaKsiazek = 0; // Statyczna liczba książek

    // Konstruktor przyjmujący tytuł i ID
    public Ksiazka(int id, String tytul) {
        this.id = id;
        this.tytul = tytul;
        liczbaKsiazek++;
    }

    // Metoda zwracająca ID
    public int getId() {
        return id;
    }

    // Metoda zwracająca tytuł
    public String getTytul() {
        return tytul;
    }

    // Metoda wypisująca ID i tytuł
    public void wypisz() {
        System.out.println(id + " " + tytul);
    }

    // Statyczna metoda zwracająca liczbę utworzonych instancji
    public static int getLiczbaKsiazek() {
        return liczbaKsiazek;
    }
}