import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Journal extends LibraryItem {
    private String eISSN, publisher, latestIssue, journalURL;

    public Journal(String eISSN, String publisher, String latestIssue, String journalURL) {
        this.eISSN = eISSN;
        this.publisher = publisher;
        this.latestIssue = latestIssue;
        this.journalURL = journalURL;
    }

    // Lista do przechowywania obiektów Film
    private static List<Journal> journals = new ArrayList<>();

    // Getter dla testów lub przyszłych zastosowań
    public static List<Journal> getJournals() {
        return journals;
    }
    
    @Override
    public int getLoanPeriod(String userType) {
        return userType.equals("Student") ? 3 : 7;
    }

    @Override
    public double computeFine(int currentDate, String userType) {
        int overdueDays = daysOverdue(currentDate, userType);
        return overdueDays > 0 ? 2.0 * overdueDays : 0;
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
                if (columns.length >= 13) {
                    String eISSN = columns[3];
                    String publisher = columns[4];
                    String latestIssue = columns[6];
                    String journalURL = columns[12];

                    journals.add(new Journal(eISSN, publisher, latestIssue, journalURL));
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
