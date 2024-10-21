import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class LinearSystem {
    private double a, b, c, d, e, f;

    // Konstruktor przyjmujacy wspolczynniki rownan
    public LinearSystem(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }

    // Metoda wypisujaca uklad rownan
    public void printSystem() {
        System.out.println(a + "x + " + b + "y = " + c);
        System.out.println(d + "x + " + e + "y = " + f);
    }

    // Metoda zwracajaca wyznacznik glowny W
    public double getDeterminant() {
        return a * e - b * d;
    }

    // Metoda zwracajaca wyznacznik Wx
    public double getDeterminantX() {
        return c * e - b * f;
    }

    // Metoda zwracajaca wyznacznik Wy
    public double getDeterminantY() {
        return a * f - c * d;
    }

    // Metoda rozwiazujaca uklad rownan
    public double[] solve() {
        double W = getDeterminant();
        if (W == 0) {
            return null; // Uklad sprzeczny lub nieoznaczony
        }
        double Wx = getDeterminantX();
        double Wy = getDeterminantY();
        return new double[]{Wx / W, Wy / W};
    }

    // Metoda do rysowania prostych i zapisu jako PNG
    public void createGraph(String fileName, int width, int height) throws IOException {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = (Graphics2D) image.getGraphics();

        // Rysowanie osi
        g.setColor(Color.LIGHT_GRAY);
        g.drawLine(0, height / 2, width, height / 2); // os X
        g.drawLine(width / 2, 0, width / 2, height); // os Y

        // Ustawienia dla prostych
        g.setColor(Color.BLUE);
        g.setStroke(new BasicStroke(2));

        // Rysowanie pierwszej prostej a * x + b * y = c
        drawLine(g, a, b, c, width, height);

        // Rysowanie drugiej prostej d * x + e * y = f
        g.setColor(Color.RED);
        drawLine(g, d, e, f, width, height);

        // Zaznaczenie rozwiazania (jeśli istnieje)
        double[] solution = solve();
        if (solution != null) {
            g.setColor(Color.GREEN);
            int solutionX = (int) (solution[0] * 20 + width / 2);
            int solutionY = (int) (-solution[1] * 20 + height / 2);
            g.fillOval(solutionX - 5, solutionY - 5, 10, 10);
        }

        // Zapis do pliku PNG
        ImageIO.write(image, "png", new File(fileName));
        g.dispose();
    }

    // Metoda pomocnicza do rysowania prostych
    private void drawLine(Graphics2D g, double a, double b, double c, int width, int height) {
        int x1 = -width / 2, x2 = width / 2;
        int y1 = (int) ((c - a * x1) / b);
        int y2 = (int) ((c - a * x2) / b);

        // Konwersja do wspolrzednych okna
        x1 = x1 * 20 + width / 2;
        x2 = x2 * 20 + width / 2;
        y1 = -y1 * 20 + height / 2;
        y2 = -y2 * 20 + height / 2;

        // Rysowanie prostej
        g.drawLine(x1, y1, x2, y2);
    }

    public static void main(String[] args) throws IOException {
        // Tworzenie przykladowego ukladu rownan
        LinearSystem system = new LinearSystem(2, 3, 5, 4, -1, 2);

        // Wypisanie ukladu
        system.printSystem();

        // Rozwiazanie
        double[] solution = system.solve();
        if (solution != null) {
            System.out.println("Rozwiazanie: x = " + solution[0] + ", y = "
+ solution[1]);
        } else {
            System.out.println("Uklad jest sprzeczny lub nieoznaczony.");
        }

        // Generowanie pliku PNG
        system.createGraph("equation_system.png", 400, 400);
        System.out.println("Wygenerowano plik PNG.");
    }
}
