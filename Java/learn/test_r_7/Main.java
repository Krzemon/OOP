import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        LocalDate today = LocalDate.now();

        // Dodanie książek
        library.addItem(new Book("The Great Gatsby", "F. Scott Fitzgerald", "Novel", "Scribner"));
        library.addItem(new Book("1984", "George Orwell", "Dystopian", "Secker & Warburg"));

        // Dodanie czasopism
        library.addItem(new Journal("Nature Journal", "1234-5678", "Nature Publishing Group", "Issue 48", "www.nature.com"));
        library.addItem(new Journal("Science Today", "2345-6789", "Science Press", "Issue 12", "www.sciencetoday.com"));

        // Dodanie filmów
        library.addItem(new Film("Inception", "Christopher Nolan", 148, "PG-13"));
        library.addItem(new Film("The Matrix", "The Wachowskis", 136, "R"));

        // Wypożyczanie pozycji
        library.borrowItem(library.getItems().get(0).getId(), "Student A", today.minusDays(20)); // Książka
        library.borrowItem(library.getItems().get(1).getId(), "Student B", today.minusDays(10)); // Książka
        library.borrowItem(library.getItems().get(2).getId(), "Teacher A", today.minusDays(8));  // Czasopismo
        library.borrowItem(library.getItems().get(4).getId(), "Student C", today.minusDays(3));  // Film

        // Wyświetlenie szczegółów wszystkich pozycji
        System.out.println("Wszystkie pozycje w bibliotece:");
        for (LibraryItem item : library.getItems()) {
            System.out.println(item.getDetails() +
                    ", Wypożyczone: " + (item.isBorrowed() ? "Tak" : "Nie") +
                    (item.isBorrowed() ? ", Wypożyczone przez: " + item.getBorrower() +
                            ", Data wypożyczenia: " + item.getBorrowDate() : ""));
        }

        // Wyświetlenie opóźnionych pozycji
        System.out.println("\nOpóźnione pozycje:");
        for (LibraryItem item : library.getItems()) {
            if (item.isOverdue(today)) {
                System.out.println(item.getDetails() +
                        ", Wypożyczone przez: " + item.getBorrower() +
                        ", Data wypożyczenia: " + item.getBorrowDate() +
                        ", Kara: " + item.computeFine(today) + " PLN");
            }
        }
    }
}
