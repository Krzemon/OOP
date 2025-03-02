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
            final File initialFile = new File("./sendThisFile.txt");
            // final InputStream targetStream =...
            final FileInputStream fileInputStream = new FileInputStream(initialFile);
            this.dataSendStream = new DataInputStream(fileInputStream);
        } catch (IOException e) {
            System.out.println("Failed with load data" + e.toString());
        }
    }

    // metoda do wysylania pliku
    public static void sendFile(String filePath){
        try {
            byte[] buffer = new byte[4096];
            FileInputStream fileInputStream = new FileInputStream(filePath);
            int bytes = fileInputStream.read(buffer,0,buffer.length);
            dataOutputStream.write(buffer,0,bytes);
        } catch (IOException e) {
            System.out.println("Failed with send data" + e.toString());
        }
    }

    public static void main(String[] args) throws Exception {
        try(ServerSocket serverSocket = new ServerSocket(12345)){
            System.out.println("listening to port: 12345");
            Socket clientSocket = serverSocket.accept();
            System.out.println(clientSocket + " connected\n");
            dataInputStream = new DataInputStream(clientSocket.getInputStream());
            dataOutputStream = new DataOutputStream(clientSocket.getOutputStream());

            String message;
            while (true) {
                message = dataInputStream.readUTF();
                System.out.println(message);
                

                if(message.equalsIgnoreCase("exit()"))
                    break;
            }

            clientSocket.close();

        } catch (Exception e){
            System.out.println("Failed with sockets" + e.toString());
        }
        finally{
            sendFile("./sendThisFile.txt");
        }
    }

}