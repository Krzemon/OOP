import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class LibraryTest {
    @Test
    public void testBookOverdue() {
        Book book = new Book(1, "Book", "Author", "Genre", "Publisher");
        book.borrow(1, 30);
        assertEquals(1, book.daysOverdue(45, "Student"));
        assertEquals(0.5, book.computeFine(45, "Student"));
    }

    @Test
    public void testFilmBorrowLimit() {
        Library library = new Library();
        library.registerUser(1, "Student");
        library.addItem(new Film(2, "Film", "Genre", "Director", 2020, 120, 8.0));
        library.borrowItem(2, 1, 30);
        assertEquals(1, library.getOverdueUsers(40).size());
    }
}
