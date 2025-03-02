public interface LibraryStatistics {
    default void displayStatistics(Library library) {
        System.out.println("Library Statistics:");
        System.out.println("Total items: " + library.getTotalItems());
        System.out.println("Total overdue fines: " + library.getTotalFines());
    }
}
