import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;

public class ReadImage {
    private String filename = "";
    BufferedImage img;
    int height;
    int width;
    int[][] imgBin;

    /**
     * obsluguje metody
     */
    public ReadImage(String filename) {
        this.filename = filename;
        img = LoadImage(filename);
        if (img != null) {
            this.height = img.getHeight();
            this.width = img.getWidth();
            this.imgBin = ImageToArray();
        }
    }

    
    /**
     * Laduje obraz z pliku 
     */ 
    final BufferedImage LoadImage(String filename){
        try {
            img = ImageIO.read(new File(filename));
            if (img == null) {
                System.out.println("Nie udalo sie zaladowac obrazu: " + filename);
            }
        } catch (Exception e) {
            System.out.println("Blad podczas ladowania obrazu: " + filename);
            e.printStackTrace();
        }
        return img;
    }

    /**
     *   Konwertuje img na tablice binarna (0 - czarny, 1 - bialy)
     */ 
    private int[][] ImageToArray(){
        int image[][] = new int[height][width];

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int p = img.getRGB(x, y);
                int r = (p >> 16) & 0xff;
                int g = (p >> 8) & 0xff;
                int b = p & 0xff;

                if (r == 0 && g == 0 && b == 0)
                    image[y][x] = 0;
                else
                    image[y][x] = 1;
            }
        }
        return image;
    }

    /**
        Zapisuje obraz z tablicy binarnej do pliku
     */ 
    public static void saveBinaryImage(ReadImage imgObj, String outputPath){
        BufferedImage image = new BufferedImage(imgObj.width, imgObj.height, BufferedImage.TYPE_BYTE_GRAY);

        Color white = new Color(255, 255, 255);
        int rgbWhite = white.getRGB();

        for (int y = 0; y < imgObj.height; y++) {
            for (int x = 0; x < imgObj.width; x++) {
                if (imgObj.imgBin[y][x] == 1) {
                    image.setRGB(x, y, rgbWhite);
                }
            }
        }
        
        File outputFile = new File(outputPath);

        try {
            ImageIO.write(image, "tif", outputFile);
            System.out.println("Zapisano obraz do: " + outputPath);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

