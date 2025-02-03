import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static DataOutputStream dataOutputStream;
    private static DataInputStream dataInputStream;
    private DataInputStream dataSendStream; // data stream

    public Server(){
        loadFile();
    }

    // metoda dla ładowania pliku
    public void loadFile(){
        try {
            final File initialFile = new File("./sendThisFile.txt"); // sprawdź, czy ten plik istnieje
            final FileInputStream fileInputStream = new FileInputStream(initialFile);
            this.dataSendStream = new DataInputStream(fileInputStream);
        } catch (IOException e) {
            System.out.println("Failed with loading data: " + e.toString());
        }
    }

    // metoda do wysyłania pliku
    public static void sendFile(String filePath) {
        try {
            byte[] buffer = new byte[4096];
            FileInputStream fileInputStream = new FileInputStream(filePath);
            int bytes;
            while ((bytes = fileInputStream.read(buffer)) != -1) {
                dataOutputStream.write(buffer, 0, bytes); // wysyłanie pliku w porcjach
            }
            fileInputStream.close();
        } catch (IOException e) {
            System.out.println("Failed with sending data: " + e.toString());
        }
    }

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Listening on port: 12345");
            Socket clientSocket = serverSocket.accept(); // oczekiwanie na połączenie od klienta
            System.out.println(clientSocket + " connected\n");
            
            dataInputStream = new DataInputStream(clientSocket.getInputStream());
            dataOutputStream = new DataOutputStream(clientSocket.getOutputStream());

            String message;
            while (true) {
                message = dataInputStream.readUTF();
                System.out.println("Received message: " + message);

                if (message.equalsIgnoreCase("exit()")) {
                    break;
                }
            }

            clientSocket.close();
        } catch (Exception e) {
            System.out.println("Error with sockets: " + e.toString());
        } finally {
            sendFile("./sendThisFile.txt"); // wysyłanie pliku
        }
    }
}
