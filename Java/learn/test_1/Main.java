import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Kalkulator:");
        System.out.print("Podaj pierwszą liczbę: ");
        double num1 = getDoubleInput(scanner);

        System.out.print("Podaj operator (+, -, /, x): ");
        char operator = getOperator(scanner);

        System.out.print("Podaj drugą liczbę: ");
        double num2 = getDoubleInput(scanner);

        double result = calculate(num1, num2, operator);
        System.out.println("Wynik: " + result);

        // Zadanie 2: Data
        System.out.println("\nSprawdzanie daty:");
        System.out.print("Podaj rok: ");
        int year = getIntInput(scanner);

        System.out.print("Podaj miesiąc (1-12): ");
        int month = getIntInput(scanner);

        System.out.print("Podaj dzień: ");
        int day = getIntInput(scanner);

        if (isValidDate(year, month, day)) {
            System.out.println("Data jest poprawna.");
            if (isLeapYear(year)) {
                System.out.println("Rok " + year + " jest przestępny.");
            } else {
                System.out.println("Rok " + year + " nie jest przestępny.");
            }

            String season = getSeason(month, day);
            System.out.println("Pora roku: " + season);
        } else {
            System.out.println("Podana data jest niepoprawna.");
        }

        scanner.close();
    }

    // Metody pomocnicze

    // Kalkulator
    private static double calculate(double num1, double num2, char operator) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '/':
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    System.out.println("Błąd: dzielenie przez zero!");
                    return Double.NaN;
                }
            case 'x': // Zastępuje operator mnożenia
                return num1 * num2;
            default:
                throw new IllegalArgumentException("Nieznany operator: " + operator);
        }
    }

    // Weryfikacja operatora
    private static char getOperator(Scanner scanner) {
        char operator;
        while (true) {
            String input = scanner.next();
            if (input.length() == 1 && "+-/x".contains(input)) {
                operator = input.charAt(0);
                break;
            } else {
                System.out.print("Nieprawidłowy operator. Spróbuj ponownie (+, -, /, x): ");
            }
        }
        return operator;
    }

    // Weryfikacja liczby typu double
    private static double getDoubleInput(Scanner scanner) {
        while (!scanner.hasNextDouble()) {
            System.out.print("Nieprawidłowa liczba. Spróbuj ponownie: ");
            scanner.next();
        }
        return scanner.nextDouble();
    }

    // Weryfikacja liczby typu int
    private static int getIntInput(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            System.out.print("Nieprawidłowa liczba. Spróbuj ponownie: ");
            scanner.next();
        }
        return scanner.nextInt();
    }

    // Sprawdzanie poprawności daty
    private static boolean isValidDate(int year, int month, int day) {
        if (month < 1 || month > 12) {
            return false;
        }

        int[] daysInMonth = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return day > 0 && day <= daysInMonth[month - 1];
    }

    // Sprawdzanie, czy rok jest przestępny
    private static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Określanie pory roku
    private static String getSeason(int month, int day) {
        if ((month == 12 && day >= 23) || (month <= 2) || (month == 3 && day < 23)) {
            return "Zima";
        } else if ((month == 3 && day >= 23) || (month <= 5) || (month == 6 && day < 23)) {
            return "Wiosna";
        } else if ((month == 6 && day >= 23) || (month <= 8) || (month == 9 && day < 23)) {
            return "Lato";
        } else {
            return "Jesień";
        }
    }
}
