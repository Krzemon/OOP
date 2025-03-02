import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class LoadTSVToArray {

    public static int size;
    ArrayList<String[]> data;
    public boolean is_first = true;

    public LoadTSVToArray() {
        String filePath = "dictionary.txt";
        this.data = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                if(is_first){
                    this.is_first = false;
                    continue;
                }
                
                data.add(values);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        LoadTSVToArray.size = data.size();

    }

    public String[][] getDataArray(){
        String[][] dataArray = new String[LoadTSVToArray.size][];
        data.toArray(dataArray);

        return dataArray;
    }
}
