import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Film extends LibraryItem {
    private String title, genre, director;
    private int year, runtime;
    private double rating;

    public Film(String title, String genre, String director, int year, int runtime, double rating) {
        this.title = title;
        this.genre = genre;
        this.director = director;
        this.year = year;
        this.runtime = runtime;
        this.rating = rating;
    }

    // Lista do przechowywania obiektów Film
    private static List<Film> films = new ArrayList<>();

    // Getter dla testów lub przyszłych zastosowań
    public static List<Film> getFilms() {
        return films;
    }
    
    @Override
    public int getLoanPeriod(String userType) {
        return 2;
    }

    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        return overdueDays > 0 ? 5.0 * overdueDays : 0;
    }

    /**
     * Wczytuje dane z pliku CSV
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
                if (columns.length >= 12) {
                    String title = columns[1];
                    String genre = columns[2];
                    String director = columns[4];
                    int year = Integer.parseInt(columns[6]);
                    int runtime = Integer.parseInt(columns[7]);
                    double rating = Double.parseDouble(columns[8]);

                    films.add(new Film(title, genre, director, year, runtime, rating));
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
