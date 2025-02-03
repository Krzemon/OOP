import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Użycie: java Main <plik1.txt> <plik2.txt>");
            return;
        }

        String file1Path = args[0];
        String file2Path = args[1];

        try {
            CheckPlagiarism.CompareFiles(file1Path, file2Path);
        } catch (IOException e) {
            System.out.println("Błąd przy odczycie pliku: " + e.getMessage());
        }
    }
}
