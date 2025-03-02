import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JOptionPane;


public class User implements Serializable {

    private String name = new String();
    private String email = new String();
    private String phoneNumber = new String();
    private String birthDate = new String();

    public User (String my_name, String my_email, String my_number, String my_birth) {
        this.name = my_name;
        this.email = my_email;
        this.phoneNumber = my_number;
        this.birthDate = my_birth;
    }

    // Walidator daty
    private static boolean dateValidator(String date){
        String regex = "[0-9]{2}-[0-9]{2}-[0-9]{4}";
        Pattern pattern = null;
        Matcher matcher = null;
        try {
            pattern = Pattern.compile(regex);
            matcher = pattern.matcher(date);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex);
        }
        return matcher.matches();
    }
    
    // Walidator numeru telefonu
    private static boolean phoneValidator(String phone){
        String regex = "^\\+?[0-9]{9,15}$";
        Pattern pattern = null;
        Matcher matcher = null;
        try {
            pattern = Pattern.compile(regex);
            matcher = pattern.matcher(phone);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex);
        }
        return matcher.matches();
    }

    // Walidator emailu
    private static boolean emailValidator(String email){
        String regex = "^(.+)@(.+)$";
        Pattern pattern = null;
        Matcher matcher = null;
        try {
            pattern = Pattern.compile(regex);
            matcher = pattern.matcher(email);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex);
        }
        return matcher.matches();
    }

    // Metoda wykonująca serializacje obiektu
    public static void serialize(User user, String fileName) throws IOException {
        try (ObjectOutputStream out_stream = new ObjectOutputStream(new FileOutputStream(fileName))) {
            out_stream.writeObject(user);
        } catch(Exception e){
            System.err.println("Error: " + e);
        }
    }

    // Metoda wykonująca deserializacje obiektu
    public static User deserialize(String fileName) throws IOException, ClassNotFoundException {
        try (ObjectInputStream in_stream = new ObjectInputStream(new FileInputStream(fileName))) {
            return (User) in_stream.readObject();
        } catch(Exception e){
            System.err.println("Error: " + e);
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String my_email = null;
        String my_number = null;
        String my_birth = null;

        System.out.print("Enter name: ");
        String my_name = scan.nextLine();
        while (true) { 
            System.out.print("Enter email: ");
            my_email = scan.nextLine();
            if (emailValidator(my_email))
                break;
            JOptionPane.showMessageDialog(null, "please input correct email");
        }
        while (true) { 
            System.out.print("Enter phone number: ");
            my_number = scan.nextLine();
            if (phoneValidator(my_number))
                break;
            JOptionPane.showMessageDialog(null, "please input correct phone number");
        }
        while (true) { 
            System.out.print("Enter birth date: ");
            my_birth = scan.nextLine();
            if (dateValidator(my_birth))
                break;
            JOptionPane.showMessageDialog(null, "please input correct date (DD-MM-YYYY)");
        }
        System.out.println("-----------------\n");
        
        try {
            User user = new User(my_name, my_email, my_number, my_birth);

            String filename = "data.bin";
            serialize(user, filename);
            System.out.println("Uzytkownik zostal serializowany do pliku: " + filename);
        
            User deserializedUser = deserialize(filename);
            System.out.println("Zdeserializowany uzytkownik:  " + deserializedUser);

        } catch (Exception e) {
            System.err.println("Error: " + e);
        } finally {
            scan.close();
        }

    }  
}

