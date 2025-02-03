import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

// klasa generyczna dodajaca rozne typy
class Add<T extends Number, U extends Number>{

    public double add(T d1, U d2){
        return d1.doubleValue() + d2.doubleValue();
    } 

    public int add(T d1, U d2, int a){
        return d1.intValue() + d2.intValue();
    } 
    public long add(T d1, U d2, int a, int b){
        return d1.longValue() + d2.longValue();
    } 
}
// klasa generyczna sortujaca bombelkowo
class BubbleSort<T extends Comparable<T>> {
    public T[] sort(T[] array) {
        int n = array.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n-i - 1; j++) {
                if (array[j].compareTo(array[j+1])>0){
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        return array;
    }
}

class CustomComparator {
    public <T> int compare(T a, T b) {
        if (a instanceof String s1 && b instanceof String s2) {
            return s1.length() - s2.length();
        } else if (a instanceof Integer i1 && b instanceof Integer i2) {
            return (int) (String.valueOf(Math.abs(i1)).chars().filter(ch -> ch != '0').count()
                    - String.valueOf(Math.abs(i2)).chars().filter(ch -> ch != '0').count());
        } else if (a instanceof Double d1 && b instanceof Double d2) {
            return (int) (Math.abs(d1) / Math.pow(10, Math.floor(Math.log10(Math.abs(d1))))
                    - Math.abs(d2) / Math.pow(10, Math.floor(Math.log10(Math.abs(d2)))));
        } else
            return 0;

    }
}

// klasa generyczna sortujaca bombelkowo
class CustomBubbleSort<T extends Comparable<T>> {
    public T[] sort(T[] array, Comparator<T> my_comparator) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (my_comparator.compare(array[j], array[j + 1]) > 0) {
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        return array;
    }
}

// klasa sumujaca rozne typy
class SumList {
    public static double sumList(List<? extends Number> lista) {
        double sum = 0.0;
        for (Number num : lista) {
            sum += num.doubleValue();}
        return sum;
    }
}

public class Main {
    public static void main(String[] args){
        

        System.out.println("zadanie 1\n");

        Add add_1 = new Add<Double, Double>();
        Add add_2 = new Add<Integer, Double>();
        Add add_3 = new Add<Long, Double>();

        System.out.println("dodawanie double: "+ add_1.add(5,5));
        System.out.println("dodawanie int: "+ add_2.add(5.5, 3.5));
        System.out.println("dodawanie long: "+ add_3.add(400L, 50));


        System.out.println("---\nzadanie 2\n");

        Integer[] tablica_int = {4,6,11,9,3,10,12};
        BubbleSort<Integer> bubble_sort_1 = new BubbleSort<>();
        Integer[] tablica_int_sorted = bubble_sort_1.sort(tablica_int);
        int n1 = tablica_int.length;
        System.out.println("Tablica Integer po posortowaniu:");
        for(int i=0; i<n1; ++i){
            System.out.print(tablica_int_sorted[i]+" ");
        }

        Double[] tablica_double = {4.1, 6.6, 9.9, 5.2, 10.1, 12.3};
        BubbleSort<Double> bubble_sort_2 = new BubbleSort<>();
        Double[] tablica_double_sorted = bubble_sort_2.sort(tablica_double);
        int n2 = tablica_double.length;
        System.out.println("\nTablica Double po posortowaniu:");
        for(int i=0; i<n2; ++i){
            System.out.print(tablica_double_sorted[i]+" ");
        }

        System.out.println("");
        String[] tablica_string = {"4.1", "6.6", "5.2", "10.1", "12.3"};
        BubbleSort<String> bubble_sort_3 = new BubbleSort<>();
        String[] tablica_string_sorted = bubble_sort_3.sort(tablica_string);
        int n3 = tablica_string.length;
        System.out.println("\nTablica Double po posortowaniu:");
        for(int i=0; i<n3; ++i){
            System.out.print(tablica_string_sorted[i]+", ");
        }


        System.out.println("---\nzadanie 3\n");

        CustomComparator c = new CustomComparator();

        CustomBubbleSort<Integer> customBubbleSortInt = new CustomBubbleSort<>();
        System.out.println(Arrays.toString(customBubbleSortInt.sort(new Integer[] { 13, 41, 2000, 302 }, c::compare)));

        CustomBubbleSort<Double> customBubbleSortDouble = new CustomBubbleSort<>();
        System.out.println(
                Arrays.toString(customBubbleSortDouble.sort(new Double[] { 123.45, 0.056, 78.9, 5.5 }, c::compare)));

        CustomBubbleSort<String> customBubbleSortString = new CustomBubbleSort<>();
        System.out.println(
                Arrays.toString(customBubbleSortString.sort(new String[] { "aaa", "b", "cccc", "dd" }, c::compare)));


        System.out.println("---\nzadanie 4\n");

        List<Number> lista = Arrays.asList(12,5, 2, 3.7, -0.5 , 2, 4.2, 6);
        System.out.println("\nsuma liczb wynosi:");
        System.out.println(SumList.sumList(lista));

    }
}
