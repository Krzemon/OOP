import java.util.List;

public class Main {
    public static void main(String[] args) {

        Library library = new Library();

        Book.read_csv("books.csv");
        Film.read_csv("movies.csv");
        Journal.read_csv("jlist.csv");
        

        for(LibraryItem i : Book.getBooks()){
            library.addItem(i);
        }
        for(LibraryItem i : Film.getFilms()){
            library.addItem(i);
        }
        for(LibraryItem i : Journal.getJournals()){
            library.addItem(i);
        }

        for (int i=1; i<10; ++i) {
            library.registerUser(i, "Student");
        }

        library.borrowItem(45, 3, 1);
        library.borrowItem(47, 2, 2);

        library.returnItem(45, 4);
        library.returnItem(47, 7);
        // zwrocil przemioty, nie jest notowany

        library.borrowItem(1, 1, 2);
        library.borrowItem(2, 1, 3);
        library.borrowItem(3, 1, 5);
        System.out.println("Dodajemy nadmiarowa ksiazke: ");
        library.borrowItem(3, 1, 33); // error: max 3 ksiazki        

        library.borrowItem(3 + Book.getBookCount() , 1, 10);
        System.out.println("Dodajemy nadmiarowy film: "); 
        library.borrowItem(3 + Book.getBookCount() , 1, 23); // error: max 1 film

        library.borrowItem(3 + Book.getBookCount() + Film.getFilmCount(), 1, 15);
        library.borrowItem(3 + Book.getBookCount() + Film.getFilmCount(), 1, 18);
        library.borrowItem(3 + Book.getBookCount() + Film.getFilmCount(), 1, 19);
        System.out.println("Dodajemy nadmiarowe czasopismo: "); 
        library.borrowItem(3 + Book.getBookCount() + Film.getFilmCount(), 1, 23); // error: max 3 czasopisma
        
        library.returnItem(3, 45); // Student returns Book1 late

        System.out.println("Kto zadluzony: ");

        List<Integer> whoOverdue = library.getUsersWithOverdueItems(45);  
        for(var i : whoOverdue) 
            System.out.println("uzytkownik o id = " + i);
    }
}
