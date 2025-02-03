import java.io.*;
import java.net.*;
import java.nio.file.*;
import java.util.*;

public class Client {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try (Socket socket = new Socket("localhost", 12345)) {
            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

            System.out.print("Podaj nazwę pliku do pobrania: ");
            String fileName = scanner.nextLine();
            outputStream.writeUTF(fileName); // Wysyłamy nazwę pliku do serwera

            // Odbieranie rozmiaru pliku
            long fileSize = inputStream.readLong();
            if (fileSize == -1) {
                // Plik nie istnieje
                String errorMessage = inputStream.readUTF();
                System.out.println("Błąd: " + errorMessage);
                return;
            }

            // Odbieranie nazwy pliku
            String receivedFileName = inputStream.readUTF();
            System.out.println("Otrzymano plik: " + receivedFileName);
            System.out.println("Oczekiwany rozmiar pliku: " + fileSize + " bajtów.");

            // Przygotowanie do odbioru zawartości pliku
            Path receivedFilePath = Paths.get("received_" + receivedFileName);
            try (FileOutputStream fileOutputStream = new FileOutputStream(receivedFilePath.toFile())) {
                byte[] buffer = new byte[4096];
                int bytesRead;
                long totalBytesRead = 0;

                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    totalBytesRead += bytesRead;
                    fileOutputStream.write(buffer, 0, bytesRead);
                    System.out.println("Odebrano " + totalBytesRead + "/" + fileSize + " bajtów.");
                }

                System.out.println("Plik zapisany jako: " + receivedFilePath);
                System.out.println("Cały plik został pomyślnie pobrany.");

                // Jeśli plik jest tekstowy, wyświetlamy jego zawartość na konsoli
                System.out.println("\nZawartość pliku:");
                try (BufferedReader reader = new BufferedReader(new FileReader(receivedFilePath.toFile()))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        System.out.println(line);
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Błąd klienta: " + e.getMessage());
        }
    }
}
