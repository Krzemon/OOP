import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LangDictionary dict = new LangDictionary();

        while (true) {
            System.out.println("Wybierz język z jakiego tłumaczymy: ");
            System.out.println("[1] Angielski");
            System.out.println("[2] Niemiecki");
            System.out.println("[3] Hiszpański");

            int lang = scanner.nextInt();
            scanner.nextLine(); // Clear buffer
            String lng = null;

            switch (lang) {
                case 1:
                    System.out.println("Wybrano angielski\n");
                    lng = "ANG";
                    break;
                case 2:
                    System.out.println("Wybrano niemiecki\n");
                    lng = "GER";
                    break;
                case 3:
                    System.out.println("Wybrano hiszpański\n");
                    lng = "ESP";
                    break;
                default:
                    System.out.println("Nieprawidłowy wybór. Spróbuj ponownie.");
                    continue;
            }

            System.out.print("Podaj słowo: ");
            String word = scanner.nextLine();

            try {
                String translated = dict.translate(word, lng);
                System.out.println(word + " [" + lng + "] = " + translated);
            } catch (Exception e) {
                System.out.println("Błąd podczas tłumaczenia: " + e.getMessage());
            }

            System.out.print("Czy chcesz przetłumaczyć kolejne słowo? (tak/nie): ");
            String choice = scanner.nextLine().toLowerCase();
            if (!choice.equals("tak")) {
                // tu obsluga tlumaczenia
                break;
            }
        }

        scanner.close();
    }
}