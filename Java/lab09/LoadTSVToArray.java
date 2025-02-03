import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class LoadTSVToArray {

    private int size;
    private ArrayList<String[]> data;

    public LoadTSVToArray(String filePath) {
        this.data = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] values = line.split("\t");
                data.add(values);
            }
        } catch (IOException e) {
            System.out.println("Error opening the file: " + e.getMessage());
            return;
        }

        size = data.size();
    }

    public String[][] getDataArray() {
        String[][] dataArray = new String[size][];
        data.toArray(dataArray);

        return dataArray;
    }

    public int getSize() {
        return size;
    }
    public ArrayList<String[]> getData() {
        return data;
    }
}
