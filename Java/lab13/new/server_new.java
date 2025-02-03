import java.io.*;
import java.net.*;
import java.nio.file.*;
import java.util.*;

public class Server {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Serwer nasłuchuje na porcie 12345...");
            
            while (true) {
                try (Socket clientSocket = serverSocket.accept()) {
                    InetAddress clientAddress = clientSocket.getInetAddress();
                    System.out.println("Połączenie od klienta: " + clientAddress.getHostAddress());

                    DataInputStream inputStream = new DataInputStream(clientSocket.getInputStream());
                    DataOutputStream outputStream = new DataOutputStream(clientSocket.getOutputStream());

                    // Oczekiwanie na nazwę pliku od klienta
                    String fileName = inputStream.readUTF();
                    System.out.println("Żądany plik: " + fileName);

                    File file = new File(fileName);
                    if (file.exists()) {
                        // Wysłanie rozmiaru pliku
                        long fileSize = file.length();
                        outputStream.writeLong(fileSize);

                        // Wysłanie nazwy pliku
                        outputStream.writeUTF(file.getName());

                        // Wysłanie zawartości pliku
                        try (FileInputStream fileInputStream = new FileInputStream(file)) {
                            byte[] buffer = new byte[4096];
                            int bytesRead;
                            while ((bytesRead = fileInputStream.read(buffer)) != -1) {
                                outputStream.write(buffer, 0, bytesRead);
                            }
                        }

                        System.out.println("Plik " + fileName + " został wysłany do klienta.");
                    } else {
                        // Jeśli plik nie istnieje, wysyłamy odpowiedni komunikat
                        outputStream.writeLong(-1); // Wysyłamy -1, by wskazać, że plik nie istnieje
                        outputStream.writeUTF("Plik nie istnieje na serwerze.");
                        System.out.println("Plik " + fileName + " nie istnieje.");
                    }
                } catch (IOException e) {
                    System.out.println("Błąd podczas obsługi klienta: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Błąd serwera: " + e.getMessage());
        }
    }
}
