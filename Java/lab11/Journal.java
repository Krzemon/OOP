public final class Journal extends LibraryItem {
    private final String title, publisher;
    private static int count = 0;

    public Journal(String title, String publisher) {
        this.title = title;
        this.publisher = publisher;
        count++;
    }

    @Override
    public int getLoanPeriod(String userType) {
        return 5;
    }

    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        if (overdueDays > 0) {
            return overdueDays * 0.30; // Fine for overdue days
        }
        return 0;
    }
}
