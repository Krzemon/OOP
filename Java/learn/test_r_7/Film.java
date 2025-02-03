public class Film extends LibraryItem {
    private final String director;
    private final int runtime;
    private final String rating;

    public Film(String title, String director, int runtime, String rating) {
        super(title);
        this.director = director;
        this.runtime = runtime;
        this.rating = rating;
    }

    @Override
    public int getLoanPeriod() {
        return 2; // 2 dni
    }

    @Override
    public double getFineRate() {
        return 5.0; // 5 PLN za dzień
    }

    @Override
    public String getDetails() {
        return "Film: " + getTitle() + ", Director: " + director + ", Runtime: " + runtime +
                " mins, Rating: " + rating;
    }
}
