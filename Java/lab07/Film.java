import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Film extends LibraryItem {
    private String title, genre, director;
    private int year, runtime;
    private double rating;
    private static int count = -1;

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
            
            int year, runtime;
            double rating;
            String title, genre, director;

            while ((line = br.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                String[] columns = line.split(";");
                if (columns.length >= 12) {
                    count++;
                    try{
                        year  = Integer.parseInt(columns[6]);
                        runtime  = Integer.parseInt(columns[7]);
                        rating  = Double.parseDouble(columns[8]);
                    }catch(NumberFormatException e){
                        continue;
                    }
                    title = columns[1];
                    genre = columns[2];
                    director = columns[4];
                    
                    films.add(new Film(title, genre, director, year, runtime, rating));
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static int getFilmCount(){
        return count;
    }
}
