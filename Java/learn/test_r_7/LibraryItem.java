import java.time.LocalDate;

public abstract class LibraryItem {
    private final int id;
    private final String title;
    private boolean borrowed;
    private String borrower;
    private LocalDate borrowDate;

    private static int idCounter = 1;

    public LibraryItem(String title) {
        this.id = idCounter++;
        this.title = title;
        this.borrowed = false;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public boolean isBorrowed() {
        return borrowed;
    }

    public void borrow(String borrower, LocalDate borrowDate) {
        this.borrowed = true;
        this.borrower = borrower;
        this.borrowDate = borrowDate;
    }

    public void returnItem() {
        this.borrowed = false;
        this.borrower = null;
        this.borrowDate = null;
    }

    public String getBorrower() {
        return borrower;
    }

    public LocalDate getBorrowDate() {
        return borrowDate;
    }

    public boolean isOverdue(LocalDate currentDate) {
        int allowedDays = getLoanPeriod();
        if (borrowDate == null) {
            return false;
        }
        return borrowDate.plusDays(allowedDays).isBefore(currentDate);
    }

    public double computeFine(LocalDate currentDate) {
        if (!isOverdue(currentDate)) {
            return 0.0;
        }
        long overdueDays = java.time.temporal.ChronoUnit.DAYS.between(borrowDate.plusDays(getLoanPeriod()), currentDate);
        return overdueDays * getFineRate();
    }

    public abstract int getLoanPeriod(); // Dni dozwolone na wypożyczenie
    public abstract double getFineRate(); // Stawka kary za dzień
    public abstract String getDetails(); // Szczegóły pozycji
}
