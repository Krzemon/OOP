
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Type;

public class Main {
    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException, InstantiationException {
        Library library = new Library();
        Book book1 = new Book("Java Programming", "John Doe", "Tech", "Tech Publisher");
        Film film1 = new Film("Inception", "Christopher Nolan", "Sci-Fi");
        Journal journal1 = new Journal("Science Today", "Science Publisher");

        library.addItem(book1);
        library.addItem(film1);
        library.addItem(journal1);

        library.displayAllItems();
        library.displayStatistics(library);
        
        try {
            Class c1 = Class.forName("Book");
        } catch (Exception e) {
            System.out.println("Class.forName() error" + e);
        }
        
        try {
            Class c2 = (book1).getClass();
            Class<? extends Book> c3 = Book.class;
            Class<? extends Book> bookClass = book1.getClass();
            
            System.out.println("\n!!! Wypisujemy pola klasy Book\n");
            Field[] fields = bookClass.getDeclaredFields();
            for(Field field : fields){
                System.out.println(field);
            }

            System.out.println("\n!!! Wypisujemy pola i wartosci klasy Book\n");

            for(Field field : fields){
                field.setAccessible(true); // dostęp do metod prywatnych 
                System.out.println(field.getName() + " -> " + field.get(book1));
            }

            System.out.println("\n!!! Wywolanie metody computeFine klasy Book\n");

            // System.out.println("\n!!! Wywolanie metody computeFine klasy Book\n");

            Method[] metodaComputeFine = bookClass.getDeclaredMethods();
 
            for (int i = 0; i < metodaComputeFine.length; ++i) {
                String mn = metodaComputeFine[i].getName();
                System.out.println(metodaComputeFine[i].getName());

                Type[] tt = metodaComputeFine[i].getGenericParameterTypes();
                if( mn.startsWith("test") && (tt.length == 0) ) {
                // System.out.println(mn +"␣zwraca␣"+ metodaComputeFine[i].invoke(book1,"Student"));
                }
            }
                System.out.println(metodaComputeFine[0].getName() +"␣zwraca␣"+ metodaComputeFine[0].invoke(book1,"Student"));
                System.out.println(metodaComputeFine[1].getName() +"␣zwraca␣"+ metodaComputeFine[1].invoke(book1,10, "Student"));


            System.out.println("\n!!! Klasa rodzic \n");



            System.out.println("\nsuperClass:\n");
            Class<?> superClass = bookClass.getSuperclass();

            Field[] fieldsSuper = superClass.getDeclaredFields();
            for (Field i : fieldsSuper) {
                System.out.println("Nazwa: " + i.getName());
                System.out.println("");
            }


            System.out.println("\n!!! Refleksie a konstruktory \n");


            Constructor<?>[] constructors = bookClass.getDeclaredConstructors();
            for (Constructor<?> i : constructors) {
                System.out.println("nazwa: " + i.getName());
                System.out.println("liczba parametrow: " + i.getParameterCount());
                for (Class<?> j : i.getParameterTypes()) {
                    System.out.println("typ parametru: " + j.getName());
                }
                System.out.println("");
            }


            System.out.println("\n!!! Zmiana wartosci pola prywatnego\n");

            Field privateField = Book.class.getDeclaredField("pagesNr");
            privateField.setAccessible(true);
            Integer priv_val = (Integer)privateField.get(book1);
            System.out.println("private variable pagesNr is equal: " + priv_val); 

        } catch (Exception e) {
            System.out.println("({MyClass}).getClass() error" + e);
        }

    }
}
