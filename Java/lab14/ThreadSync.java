import java.util.Scanner;

public class ThreadSync {

    static class SharedTable {
        private int[] array;
        private boolean isFilled = false;

        // deklaracja rozmiaru tablicy
        public SharedTable(int size) {
            this.array = new int[size];
        }

        public synchronized void fillArray() {
            while (isFilled) {
                try {
                    wait();
                } catch (Exception e) {
                    System.err.println("ERROR:" + e);
                }
            }

            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter " + array.length + " numbers:");
            for (int i = 0; i < array.length; i++) {
                array[i] = scanner.nextInt();
            }

            isFilled = true;
            notifyAll();
        }

        public synchronized void calculateSum() {
            while (!isFilled) {
                try {
                    wait();
                } catch (Exception e) {
                    System.err.println("ERROR:" + e);
                }
            }

            int sum = 0;
            for (int value : array) {
                sum += value;
            }
            System.out.println("Sum: " + sum);

            for (int i = 0; i < array.length; i++) {
                array[i] = 0;
            }

            isFilled = false;
            notifyAll();
        }
    }

    static class GetNumbers extends Thread {
        private SharedTable shared;
        public GetNumbers(SharedTable _shared) {
            this.shared = _shared;
        }
        @Override
        public void run() {
            while (true) {
                shared.fillArray();
            }
        }
    }

    static class GetSum extends Thread {
        private SharedTable shared;
        public GetSum(SharedTable _shared) {
            this.shared = _shared;
        }
        @Override
        public void run() {
            while (true) {
                shared.calculateSum();
                try {
                    Thread.sleep(1000); // 1s
                } catch (Exception e) {
                    System.err.println("ERROR:" + e);
                }
            }
        }
    }

    public static void main(String[] args) {
        int N = 5; // rozmiar dla tablicy
        SharedTable shared = new SharedTable(N);

        GetNumbers getNumbers = new GetNumbers(shared);
        GetSum getSum = new GetSum(shared);

        getNumbers.start();
        getSum.start();
    }
}
