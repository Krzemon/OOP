import java.util.Random;

public class Main {
    public static void main(String[] args) {
        // Tworzenie książek
        Ksiazka k1 = new Ksiazka(1, "Rok 1984");
        Ksiazka k2 = new Ksiazka(2, "Heart of Darkness");
        Ksiazka k3 = new Ksiazka(3, "Proces");
        Ksiazka k4 = new Ksiazka(4, "Dżuma");
        Ksiazka k5 = new Ksiazka(5, "Imię róży");

        // Tworzenie biblioteki i dodawanie książek
        Biblioteka biblioteka = new Biblioteka();
        biblioteka.dodaj(k1);
        biblioteka.dodaj(k2);
        biblioteka.dodaj(k3);
        biblioteka.dodaj(k4);
        biblioteka.dodaj(k5);

        // Wypisanie drzewa
        System.out.println("Biblioteka w postaci drzewa binarnego:");
        biblioteka.wypiszDrzewo();

        // Wyszukiwanie po tytule
        System.out.println("\nWyszukiwanie książki po tytule 'Proces':");
        Ksiazka znalezionyTytul = biblioteka.wyszukajTytul("Proces");
        if (znalezionyTytul != null) {
            znalezionyTytul.wypisz();
        } else {
            System.out.println("Książka nie znaleziona.");
        }

        // Wyszukiwanie po ID
        System.out.println("\nWyszukiwanie książki po ID 3:");
        Ksiazka znalezionyID = biblioteka.wyszukajID(3);
        if (znalezionyID != null) {
            znalezionyID.wypisz();
        } else {
            System.out.println("Książka nie znaleziona.");
        }

        // Wypisanie liczby książek
        System.out.println("\nLiczba książek w systemie: " + Ksiazka.getLiczbaKsiazek());
    }
}