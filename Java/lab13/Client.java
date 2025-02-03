import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    private static DataOutputStream dataOutputStream = null;
    private static DataInputStream dataInputStream = null;
    private static Scanner scanner = new Scanner(System.in);

    // metoda do odbierania pliku
    public static void receiveFile() {
        try {
            byte[] buffer = new byte[4096];
            int bytes = dataInputStream.read(buffer, 0, buffer.length); // odbieranie danych
            FileOutputStream fileOutputStream = new FileOutputStream("received_file.txt");
            fileOutputStream.write(buffer, 0, bytes); // zapisanie pliku
            System.out.println("File received and saved as 'received_file.txt'.");
        } catch (IOException e) {
            System.out.println("Error during file reception: " + e.toString());
        }
    }

    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 12345)) { // połączenie z serwerem
            dataInputStream = new DataInputStream(socket.getInputStream());
            dataOutputStream = new DataOutputStream(socket.getOutputStream());

            System.out.print("Enter the filename to request from the server: ");
            String fileName = scanner.nextLine();
            dataOutputStream.writeUTF(fileName); // wysyłanie żądania pliku do serwera

            // Odbieranie pliku
            receiveFile();
        } catch (IOException e) {
            System.out.println("Connection error: " + e.toString());
        }
    }
}
