import java.util.List;

public class Main {
    public static void main(String[] args) {

        Library library = new Library();

        Book.read_csv("books.csv");
        Film.read_csv("movies.csv");
        Journal.read_csv("jlist.csv");
        
        // for (Film films : Film.getFilms()) {
        //     System.out.println(films);
        // }

        // for (Book books : Book.getBooks()) {
        //     System.out.println(books);
        // }

        // for (Journal journals : Journal.getJournals()) {
        //     System.out.println(journals);
        // }

        for (int i=1; i<10; ++i) {
            library.registerUser(i, "Student");
        }
        System.out.println("\n ------------------------------------ \n");    
        
        library.borrowItem(1, 1, 30);
        library.borrowItem(1, 1, 31);
        library.borrowItem(1, 1, 32);

        library.returnItem(1, 45); // Student returns Book1 late
        library.returnItem(3, 40); // Student returns Journal on time

        List<Integer> users = library.getUsersWithOverdueItems(45);   
        System.out.println("Fine for user 1: " + users.get(0));
    }
}
