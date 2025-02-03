public class Journal extends LibraryItem {
    private final String issn;
    private final String publisher;
    private final String latestIssue;
    private final String url;

    public Journal(String title, String issn, String publisher, String latestIssue, String url) {
        super(title);
        this.issn = issn;
        this.publisher = publisher;
        this.latestIssue = latestIssue;
        this.url = url;
    }

    @Override
    public int getLoanPeriod() {
        return 7; // 1 tydzień
    }

    @Override
    public double getFineRate() {
        return 2.0; // 2 PLN za dzień
    }

    @Override
    public String getDetails() {
        return "Journal: " + getTitle() + ", ISSN: " + issn + ", Publisher: " + publisher +
                ", Latest Issue: " + latestIssue + ", URL: " + url;
    }
}
