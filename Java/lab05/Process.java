import java.util.ArrayList;

public class Process {
    
    int count;
    int[][] refBin;
    int[][] testBin;
    ArrayList<int[]> magpieCoordinates;

    ReadImage testImageObj;
    ReadImage refImageObj;
    
    public Process(ReadImage testImageObj, ReadImage refImageObj){
        this.magpieCoordinates = new ArrayList<>();
        this.testImageObj = testImageObj;
        this.refImageObj = refImageObj;
        
        this.testBin = testImageObj.imgBin;
        this.refBin = refImageObj.imgBin;
        this.count = GetMagpies();
    }
    
    /**
     * zlicza ile obiektow
     */
    public int GetMagpies(){
            if (testBin == null || refBin == null) {
                System.out.println("Obrazy nie zostały poprawnie załadowane.");
                return 0;
            }
    
            int count = 0;
            for (int y = 0; y < testImageObj.height - refImageObj.height; y++) {
                for (int x = 0; x < testImageObj.width - refImageObj.width; x++) {
                    if (isMagpieAt(x, y)) {
                        magpieCoordinates.add(new int[]{x, y});
                        count++;
                    }
                }
            }
            return count;
        }
    
        /**
         * Sprawdza, czy obiekt znajduje sie na podanych wspolrzednych
         */
        private boolean isMagpieAt(int xStart, int yStart) {
            for (int y = 0; y < refImageObj.height; y++) {
                for (int x = 0; x < refImageObj.width; x++) {
                    if (refBin[y][x] == 1 && testBin[yStart + y][xStart + x] != 1) {
                        return false;
                    }
                }
            }
            return true;
        }
}
