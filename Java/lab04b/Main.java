import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        
        System.out.println("enter your name: ");
        String name = new String(scanner.nextLine());
        System.out.println("enter your street: ");
        String street = new String(scanner.nextLine());
        System.out.println("enter your address number: ");
        int num = scanner.nextInt();



        Person person_1 = new Person(name, street, num);
    
        Person person_2 = new Person(person_1);
         
        Person person_3 = new Person(person_1, 0);


        // wyswietlenie wyniku
        System.out.println("Oryginal:");
        person_1.printDetails();
        System.out.println("Plytka kopia:");
        person_2.printDetails();
        System.out.println("Gleboka kopia:");
        person_3.printDetails();

        
    }
}
