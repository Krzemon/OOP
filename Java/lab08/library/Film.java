package library;

public final class Film extends LibraryItem {
    private final String title, director, genre;
    private static int count = 0;

    public Film(String title, String director, String genre) {
        this.title = title;
        this.director = director;
        this.genre = genre;
        count++;
    }

    @Override
    public int getLoanPeriod(String userType) {
        return 7;
    }

    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        if (overdueDays > 0) {
            return overdueDays * 0.50; // Fine for overdue days
        }
        return 0;
    }
}
