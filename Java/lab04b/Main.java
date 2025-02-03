import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        
        System.out.println("enter your name: ");
        String name = scanner.nextLine();
        System.out.println("enter your street: ");
        String street = scanner.nextLine();
        System.out.println("enter your address number: ");
        int num = scanner.nextInt();

        Person person_1 = new Person(name, street, num);
    
        Person person_2 = new Person(person_1);
         
        Person person_3 = new Person(person_1, 0);

        // Zmiana pól street i number w płytkiej kopii
        person_2.setStreet("New Street");
        person_2.setNumber(99);

        // Zmiana pól street i number w głębokiej kopii
        person_3.setStreet("Different Street");
        person_3.setNumber(100);
        
        // Wyświetlanie wyników
        System.out.println("Original:");
        person_1.printDetails();
        System.out.println("Shallow Copy:");
        person_2.printDetails();
        System.out.println("Deep Copy:");
        person_3.printDetails();
        
    }
}
