import java.util.Scanner;

public class Main{

    // metoda czyszczaca terminal
    public static void clearScreen() {  
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    } 

    // metoda glowna main
    public static void main (String [] args){
        System.out.println("Enter the number of elements");    
        Scanner scanner = new Scanner(System.in);

        // liczba przedmiotow
        int num = scanner.nextInt();
        // suma cen przedmiotow
        Double full_price = 0.0;

        for (int i = 0; i < num; ++i){
            System.out.println("Enter the item name: ");
            Scanner scan = new Scanner(System.in);
            String itemName = scan.nextLine();

            System.out.println("Enter the price: ");
            Double price = scan.nextDouble();

            System.out.println("Enter the category (1-4): ");
            System.out.println("1. Soccer");
            System.out.println("2. Basketball");
            System.out.println("3. Tennis");
            System.out.println("4. Swimming");

            int category = scan.nextInt();
            
            clearScreen();

            switch(category){
                case 1:
                System.out.println("Kicking it into gear!");
                break;
                case 2:
                System.out.println("Nothing but net!");
                break;
                case 3:
                System.out.println("Game, set, match!"); 
                break;
                case 4:
                System.out.println("Dive into excellence!");
                break;
            }

            // System.out.println("nazwa "+ name +" cena "+ price +" kategoria "+ category);
            full_price += price;
        }

        // nie bylo w poleceniu
        //System.out.println("Cena wszystkich produktow wynosi: "+ full_price);

        // cena po rabacie
        Double final_price;
        if (full_price > 200.0){
            final_price = full_price * (1 - 0.15); // 15%
            System.out.println("Ostateczna cena po naliczeniu rabatu 15% wynosi: "+ final_price);
        }
        else if (full_price > 100.0 && full_price < 200.0){
            final_price = full_price * (1 - 0.1); // 10%
            System.out.println("Ostateczna cena po naliczeniu rabatu 10% wynosi: "+ final_price);
        }
        else{
            //System.out.println("Ostateczna cena bez rabatow wynosi: "+ full_price);
        }
    }
 }
 
 