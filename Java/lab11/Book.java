public final class Book extends LibraryItem {
    private final String title, author, genre, publisher;
    private static int count = 0;

    private int pagesNr = 100;

    public Book(String title, String author, String genre, String publisher) {
        this.title = title;
        this.author = author;
        this.genre = genre;
        this.publisher = publisher;
        count++;
    }

    public Book(String title, String author, String genre) {
        this.title = title;
        this.author = author;
        this.genre = genre;
        this.publisher = "AGH";
        count++;
    }

    private Book(String genre, String publisher) {
        this.title = "zastrzezony tytul";
        this.author = "zastrzezony autor";
        this.genre = genre;
        this.publisher = publisher;
        count++;
    }

    @Override
    public int getLoanPeriod(String userType) {
        return 14;
    }

    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        if (overdueDays > 0) {
            return overdueDays * 0.25; // Fine for overdue days
        }
        return 0;
    }
}
