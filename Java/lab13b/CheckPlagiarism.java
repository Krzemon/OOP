import java.io.*;
import java.util.*;

public class CheckPlagiarism {
    private static final double PLAGIARISM_THRESHOLD = 2.0; // Próg wykrywania plagiatu (średnia odległość Hamminga)

    public static void CompareFiles(String filePath1, String filePath2) throws IOException {
        // Wczytujemy pliki
        List<String> file1Lines = readFile(filePath1);
        List<String> file2Lines = readFile(filePath2);

        // Liczba identycznych linii
        int identicalLinesCount = 0;
        // Suma minimalnych odległości Hamminga
        double totalHammingDistance = 0.0;

        // Dla każdej linii w pierwszym pliku
        for (String line1 : file1Lines) {
            int minHammingDistance = Integer.MAX_VALUE;

            // Szukamy linii w drugim pliku o najmniejszej odległości Hamminga
            for (String line2 : file2Lines) {
                int distance = Hamming.compare(line1, line2);
                minHammingDistance = Math.min(minHammingDistance, distance);
            }

            // Dodajemy minimalną odległość do sumy
            totalHammingDistance += minHammingDistance;

            // Sprawdzamy, czy linie są identyczne
            if (minHammingDistance == 0) {
                identicalLinesCount++;
            }
        }

        // Obliczamy średnią odległość Hamminga
        double averageHammingDistance = totalHammingDistance / file1Lines.size();

        // Drukujemy raport
        System.out.println("Raport porównania plików:");
        System.out.println("Średnia minimalna odległość Hamminga: " + averageHammingDistance);
        System.out.println("Liczba identycznych linii: " + identicalLinesCount);

        // Sprawdzamy, czy wykryto plagiat
        if (averageHammingDistance < PLAGIARISM_THRESHOLD) {
            System.out.println("Wykryto plagiat!");
        } else {
            System.out.println("Plagiat nie został wykryty.");
        }
    }

    private static List<String> readFile(String filePath) throws IOException {
        List<String> lines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        }
        return lines;
    }
}
