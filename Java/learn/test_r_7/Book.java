public class Book extends LibraryItem {
    private final String author;
    private final String genre;
    private final String publisher;

    public Book(String title, String author, String genre, String publisher) {
        super(title);
        this.author = author;
        this.genre = genre;
        this.publisher = publisher;
    }
    getTitle
    @Override
    public int getLoanPeriod() {
        return 14; // 2 tygodnie
    }

    @Override
    public double getFineRate() {
        return 0.5; // 0,5 PLN za dzień
    }

    @Override
    public String getDetails() {
        return "Book: " + getTitle() + ", Author: " + author + ", Genre: " + genre + ", Publisher: " + publisher;
    }
}
