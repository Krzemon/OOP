import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.chrono.ThaiBuddhistChronology;
import java.util.Scanner;
import java.util.*;


public class Client {
    private static DataOutputStream dataOutputStream = null;
    private static DataInputStream dataInputStream = null;
    

    private static Scanner scanner = new Scanner(System.in);

    // metoda do pobierania pliku
    public static void receiveFile(){
        try{
            byte[] buffer = new byte[4096];
            int bytes = dataInputStream.read(buffer,0,buffer.length);
            FileOutputStream fileOutputStream = new FileOutputStream("saved.txt");
            fileOutputStream.write(buffer,0,bytes);
            // saveFile(fileOutputStream);
        }catch (Exception e){
            System.out.println(e.toString());
        }
    }

    public void saveFile(FileOutputStream outStream) throws IOException {
        File targetFile = new File("./saved.txt");
        outStream = new FileOutputStream(targetFile);
        // tu powinno zapisac
    }

    public static void main(String[] args) {

        try(Socket socket = new Socket("localhost",12345)){
            dataInputStream = new DataInputStream(socket.getInputStream());
            dataOutputStream = new DataOutputStream(socket.getOutputStream());

            while (true) {
                System.out.print("input data> ");
                String message = scanner.nextLine();
                dataOutputStream.writeUTF(message);
                
                if(message.equalsIgnoreCase("exit()"))
                    break;
            }
            
        }catch (Exception e){
            System.out.println(e.toString());
        }
        finally{
            receiveFile();
        }
    }



}

// public class Client {
//     public static void main(String[] args) throws Exception {
//         Socket s = new Socket( "localhost", 12345 );
//         PrintWriter out = new PrintWriter(
//         s.getOutputStream(), true );
//         BufferedReader in = new BufferedReader(
//             new InputStreamReader(s.getInputStream()));
//         BufferedReader stdin = new BufferedReader(
//             new InputStreamReader(System.in) );
//         String outs;
//         String ins;
//         while ( (outs = in.readLine()) != null ) {
//             System.out.println("Serwer:␣" + outs);
//             ins = stdin.readLine();
//             if (ins != null) {
//             System.out.println("Klient:␣" + ins);
//             out.println(ins);
//             }
//         }
//         out.close(); in.close();
//         stdin.close(); s.close();
//     }
// }