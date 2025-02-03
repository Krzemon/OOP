import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;

public class Library {
    private final List<LibraryItem> items;

    public Library() {
        this.items = new ArrayList<>();
    }

    public void addItem(LibraryItem item) {
        items.add(item);
    }

    public List<LibraryItem> getItems() {
        return items;
    }

    public void borrowItem(int id, String borrower, LocalDate borrowDate) {
        for (LibraryItem item : items) {
            if (item.getId() == id && !item.isBorrowed()) {
                item.borrow(borrower, borrowDate);
                return;
            }
        }
        System.out.println("Item with ID " + id + " is not available for borrowing.");
    }
}
