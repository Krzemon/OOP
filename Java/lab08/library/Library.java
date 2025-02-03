package library;

import java.util.ArrayList;
import java.util.List;

public class Library implements LibraryStatistics {
    private List<LibraryItem> items = new ArrayList<>();

    public void addItem(LibraryItem item) {
        items.add(item);
    }

    public void displayAllItems() {
        for (LibraryItem item : items) {
            System.out.println("ID: " + item.getId() + ", Borrowed: " + item.isBorrowed());
        }
    }

    public int getTotalItems() {
        return items.size();
    }

    public double getTotalFines() {
        double totalFines = 0;
        for (LibraryItem item : items) {
            totalFines += item.computeFine(30, "student"); // Example date and user type
        }
        return totalFines;
    }
}
