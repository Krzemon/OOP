public class Main {
    public static void main(String[] args) {
        ReadImage testImageObj = new ReadImage("testImage.tif");
        ReadImage refImageObj = new ReadImage("refImage.tif");

        if (testImageObj.img != null && refImageObj.img != null) {
            Process detector = new Process(testImageObj, refImageObj);        
            System.out.println("Znaleziono " + detector.count + " srok.");
        } else {
            System.out.println("Nie udało się załadować obrazów.");
        }
    }
}
