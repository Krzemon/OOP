package library;

public abstract sealed class LibraryItem permits Book, Film, Journal {

// public abstract class LibraryItem {
    private final int id;
    private boolean isBorrowed;
    private int userId;
    private int borrowedDate;

    private static int id_counter = 1;

    public LibraryItem() {
        this.id = id_counter++;
        this.isBorrowed = false;
        this.userId = -1;
        this.borrowedDate = -1;
    }
    
    /**
     * gettery
     */
    public int getId(){
        return id;
    }
    public boolean isBorrowed(){
        return isBorrowed;
    }
    public int getUserId(){
        return userId;
    }
    public int getBorrowedDate(){
        return borrowedDate;
    }
    /**
     * Metoda odpowiedzialna za wypożyczenie
     */
    public void borrow(int userId, int date){
        this.isBorrowed = true;
        this.userId = userId;
        this.borrowedDate = date;
    }
    /**
     * Metoda odpowiedzialna za zwrot
     */
    public void returnItem(){
        this.isBorrowed = false;
        this.userId = -1;
        this.borrowedDate = -1;
    }
    /**
     * Metoda zwracająca limit wypożyczenia dla danego typu użytkownika
     */
    public abstract int getLoanPeriod(String userType);
    
    /**
     * Metoda zwracająca ilość dni przetrzymania
     */
    public int daysOverdue(int currentDate, String userType) {
        if (!isBorrowed) return 0;
        int dueDate = borrowedDate + getLoanPeriod(userType);
        return currentDate - dueDate;
    }
    
    /**
     * Metoda sprawdzająca czy element jest przetrzymany
     */
    public boolean isOverdue(int currentDate, String userType) {
        return daysOverdue(currentDate, userType) > 0;
    }
    
    /**
     * Metoda zwracająca karę za przetrzymanie elementu
     */
    public abstract double computeFine(int currentDate, String userType);
}
