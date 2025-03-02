import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Book extends LibraryItem {
    private String title, author, genre, publisher;
    private static int count = 0;

    public Book(String title, String author, String genre, String publisher) {
        this.title = title;
        this.author = author;
        this.genre = genre;
        this.publisher = publisher;
    }

    // Lista do przechowywania obiektów Film
    private static List<Book> books = new ArrayList<>();

    // Getter dla testów lub przyszłych zastosowań
    public static List<Book> getBooks() {
        return books;
    }

    @Override
    public int getLoanPeriod(String userType) {
        return 14;
    }
    
    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        return overdueDays > 0 ? 0.5 * overdueDays : 0;
    }
    /**
     * gettery
     */
    public String getTitle(){
        return title;
    }
    public String getAuthor(){
        return author;
    }
    public String getGenre(){
        return genre;
    }
    public String getPublisher(){
        return publisher;
    }
    /**
     * Metoda odpowiedzialna za wczytanie danych z pliku CSV
     */
    public static void read_csv(String filePath) {            
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                String[] columns = line.split(";");

                if (columns.length >= 5) {
                    String title = columns[0];
                    String author = columns[1];
                    String genre = columns[2];
                    String publisher = columns[4];
                    count++;
                    books.add(new Book(title, author, genre, publisher));
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static int getBookCount(){
        return count;
    }

}


