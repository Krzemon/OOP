package library;

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        Book book1 = new Book("Java Programming", "John Doe", "Tech", "Tech Publisher");
        Film film1 = new Film("Inception", "Christopher Nolan", "Sci-Fi");
        Journal journal1 = new Journal("Science Today", "Science Publisher");

        library.addItem(book1);
        library.addItem(film1);
        library.addItem(journal1);

        library.displayAllItems();
        library.displayStatistics(library); // Display statistics using interface method
    }
}
