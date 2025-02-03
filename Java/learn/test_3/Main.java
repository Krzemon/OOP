import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

// Klasa reprezentująca projekt
class Projekt {
    private String nazwa;
    private int liczbaPracownikow;

    public Projekt(String nazwa) {
        this.nazwa = nazwa;
        this.liczbaPracownikow = 0;
    }

    public String getNazwa() {
        return nazwa;
    }

    public void dodajPracownika() {
        liczbaPracownikow++;
    }

    public int getLiczbaPracownikow() {
        return liczbaPracownikow;
    }
}

// Klasa reprezentująca pracownika
class Pracownik {
    private String imieNazwisko;
    private HashMap<Projekt, Integer> godzinyProjektow;

    public Pracownik(String imieNazwisko) {
        this.imieNazwisko = imieNazwisko;
        this.godzinyProjektow = new HashMap<>();
    }

    public String getImieNazwisko() {
        return imieNazwisko;
    }

    public void dodajProjekt(Projekt projekt, int godziny) {
        godzinyProjektow.put(projekt, godzinyProjektow.getOrDefault(projekt, 0) + godziny);
    }

    public int getLacznaLiczbaGodzin() {
        return godzinyProjektow.values().stream().mapToInt(Integer::intValue).sum();
    }

    public HashMap<Projekt, Integer> getGodzinyProjektow() {
        return godzinyProjektow;
    }
}

// Klasa główna
public class Main {

    public static List<Pracownik> czytajDaneZPliku(String fileName, List<Projekt> listaProjektow) {
        List<Pracownik> pracownicy = new ArrayList<>();
        HashMap<String, Projekt> mapaProjektow = new HashMap<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] dane = line.split(",");
                String imieNazwisko = dane[0].trim();
                String nazwaProjektu = dane[1].trim();
                int liczbaGodzin = Integer.parseInt(dane[2].trim());

                // Znajdź projekt w liście lub stwórz nowy
                Projekt projekt = mapaProjektow.computeIfAbsent(nazwaProjektu, k -> {
                    Projekt p = new Projekt(k);
                    listaProjektow.add(p);
                    return p;
                });

                // Dodaj projekt do pracownika
                Pracownik pracownik = pracownicy.stream()
                        .filter(p -> p.getImieNazwisko().equals(imieNazwisko))
                        .findFirst()
                        .orElseGet(() -> {
                            Pracownik p = new Pracownik(imieNazwisko);
                            pracownicy.add(p);
                            return p;
                        });

                pracownik.dodajProjekt(projekt, liczbaGodzin);
                projekt.dodajPracownika();
            }
        } catch (IOException e) {
            System.out.println("Błąd wczytywania pliku: " + e.getMessage());
        }

        return pracownicy;
    }

    public static void wypiszWyniki(List<Pracownik> pracownicy, List<Projekt> listaProjektow) {
        System.out.println("Zestawienie pracowników i projektów:");
        for (Pracownik pracownik : pracownicy) {
            System.out.println("Pracownik: " + pracownik.getImieNazwisko());
            System.out.println("Łączna liczba godzin: " + pracownik.getLacznaLiczbaGodzin());
            for (var entry : pracownik.getGodzinyProjektow().entrySet()) {
                System.out.println("- " + entry.getKey().getNazwa() + ", liczba godzin: " + entry.getValue());
            }
            System.out.println();
        }

        System.out.println("Średnia liczba pracowników na projekt:");
        for (Projekt projekt : listaProjektow) {
            System.out.println(projekt.getNazwa() + ": " + projekt.getLiczbaPracownikow() + " pracowników");
        }
    }

    public static void main(String[] args) {
        String fileName = "pracownicy.txt";

        List<Projekt> listaProjektow = new ArrayList<>();
        List<Pracownik> pracownicy = czytajDaneZPliku(fileName, listaProjektow);

        wypiszWyniki(pracownicy, listaProjektow);
    }
}
