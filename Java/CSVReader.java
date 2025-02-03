import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class CSVReader {
    public static void main(String[] args) {
        String filePath = "path/to/your/file.csv"; // Ścieżka do pliku CSV
        
        // Listy do przechowywania danych z CSV
        List<String[]> data = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean isFirstLine = true; // Flaga do pominięcia pierwszej linii

            while ((line = br.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;  // Pomiń pierwszą linię
                    continue;  // Przechodzi do następnej iteracji
                }
                
                // Podziel linie na kolumny na podstawie przecinka
                String[] columns = line.split(",");
                data.add(columns);
                
                // Możesz teraz odwoływać się do danych w poszczególnych kolumnach
                // Przykład: wypisanie wartości z drugiej kolumny
                System.out.println("Wartość w drugiej kolumnie: " + columns[1]);
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}