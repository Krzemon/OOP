import java.util.Random;
public class MultiThreadSum {

    static class PartialSumRunnable implements Runnable {
        private final double[] array;
        private final int start;
        private final int end;
        private double partialSum;

        public PartialSumRunnable(double[] array, int start, int end) {
            this.array = array;
            this.start = start;
            this.end = end;
        }

        @Override
        public void run() {
            for (int i = start; i < end; i++) {
                partialSum += array[i];
            }
        }

        public double getPartialSum() {
            return partialSum;
        }
    }

    static class PartialSumThread extends Thread {
        private final double[] array;
        private final int start;
        private final int end;
        private double partialSum;

        public PartialSumThread(double[] array, int start, int end) {
            this.array = array;
            this.start = start;
            this.end = end;
        }

        @Override
        public void run() {
            for (int i = start; i < end; i++) {
                partialSum += array[i];
            }
        }

        public double getPartialSum() {
            return partialSum;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int N = 10000;
        int K = 30;
        int NK = N / K;
        double[] array = new double[N];

        Random randGenerator = new Random();
        for (int i=0; i < N; i++) {
            array[i] = randGenerator.nextDouble();
        }

        System.out.println("Runnable method");

        long startTime = System.nanoTime();
        PartialSumRunnable[] runnables = new PartialSumRunnable[K];
        Thread[] threadsRunnable = new Thread[K];

        for (int i = 0; i < K; i++) {
            int start = i * NK;
            int end;
            if (i == K - 1)
                end = N;
            else
                end = start + NK;
            runnables[i] = new PartialSumRunnable(array, start, end);
            threadsRunnable[i] = new Thread(runnables[i]);
            threadsRunnable[i].start();
        }

        double totalSumRunnable = 0;
        for (int i = 0; i < K; i++) {
            threadsRunnable[i].join();
            totalSumRunnable += runnables[i].getPartialSum();
        }
        long endTime = System.nanoTime();
        System.out.println("Sum: " + totalSumRunnable);
        System.out.println("Time: " + (endTime - startTime) / 1e6 + " ms");

        System.out.println("");
        System.out.println("Thread method");

        startTime = System.nanoTime();
        PartialSumThread[] threadsThread = new PartialSumThread[K];

        for (int i = 0; i < K; i++) {
            int start = i * NK;
            int end;
            if (i == K - 1)
                end = N;
            else
                end = start + NK;
            threadsThread[i] = new PartialSumThread(array, start, end);
            threadsThread[i].start();
        }

        double totalSumThread = 0;
        for (int i = 0; i < K; i++) {
            threadsThread[i].join();
            totalSumThread += threadsThread[i].getPartialSum();
        }
        endTime = System.nanoTime();
        System.out.println("Sum: " + totalSumThread);
        System.out.println("Time: " + (endTime - startTime) / 1e6 + " ms");

        System.out.println("");
        System.out.println("Normal method");
 
        startTime = System.nanoTime();
        double totalSumConventional = 0;
        for (double v : array) {
            totalSumConventional += v;
        }
        endTime = System.nanoTime();
        System.out.println("Sum: " + totalSumConventional);
        System.out.println("Time: " + (endTime - startTime) / 1e6 + " ms");
    }
}
