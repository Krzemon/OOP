import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Library {
    private Map<Integer, LibraryItem> items = new HashMap<>();
    private Map<Integer, String> userTypes = new HashMap<>(); 
    private Map<Integer, Double> userFines = new HashMap<>();

    /**
     * Dodaje element do biblioteki
     */
    public void addItem(LibraryItem item) {
        items.put(item.getId(), item);
    }
    /**
     * Rejestruje uzytkownika w bibliotece
     */
    public void registerUser(int userId, String userType) {
        userTypes.put(userId, userType);
        userFines.put(userId, 0.0);
    }
    /**
     * Wypozycza element
     */
    public void borrowItem(int itemId, int userId, int currentDate) {
        if (!items.containsKey(itemId) || !userTypes.containsKey(userId)) return;
    
        LibraryItem item = items.get(itemId);
        String userType = userTypes.get(userId);
        
        if (userType.equals("Student")) {
            for (LibraryItem i : items.values()) {
                if (i instanceof Film && i.getUserId() == userId) {
                    System.out.println("Student może wypożyczyć maksymalnie jeden film.");
                    return;
                }
            }
        }
        item.borrow(userId, currentDate);
    }
    /**
     * Zwraca element
     */
    public void returnItem(int itemId, int currentDate) {
        if (!items.containsKey(itemId)) return;

        LibraryItem item = items.get(itemId);
        int userId = item.getUserId();
        if (userId != -1) {
            double fine = item.computeFine(currentDate, userTypes.get(userId));
            userFines.put(userId, userFines.get(userId) + fine);
            item.returnItem();
        }
    }
    /**
     * Sprawdza kare uzytkownika
     */
    public double checkUserFine(int userId) {
        return userFines.getOrDefault(userId, 0.0);
    }
    /**
     * Zwraca liste uzytkownikow z przeterminowanymi elementami
     */
    public List<Integer> getUsersWithOverdueItems(int currentDate) {
        List<Integer> overdueUsers = new ArrayList<>();
        for (LibraryItem item : items.values()) {
            if (item.isOverdue(currentDate, userTypes.get(item.getUserId()))) {
                overdueUsers.add(item.getUserId());
            }
        }
        return overdueUsers;
    }
}