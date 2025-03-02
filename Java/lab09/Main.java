import java.io.File;

public class Main {

    public static void main(String[] args) {
        String filePath = "some_math.txt";
        LoadTSVToArray loader = new LoadTSVToArray(filePath);

        if (loader.data.isEmpty()) {
            System.out.println("No data found in the file.");
            return;
        }

        String[][] dataArray = loader.getDataArray();

        for (String[] line : dataArray) {
            for (String expression : line) {
                MathEvaluator.evaluateExpression(expression);
            }
        }
    }
}
