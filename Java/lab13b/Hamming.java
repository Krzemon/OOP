public class Hamming {

    public static int compare(String str1, String str2) throws IllegalArgumentException {
        // Sprawdzamy, czy któryś z ciągów jest pusty
        if (str1 == null || str2 == null) {
            throw new IllegalArgumentException("Ciągi nie mogą być null.");
        }

        // Usuwamy wszystkie białe znaki (spacje, tabulatory, itp.)
        str1 = str1.replaceAll("[\\s_]", "");
        str2 = str2.replaceAll("[\\s_]", "");

        // Jeśli ciągi mają różną długość, rozszerzamy krótszy do długości dłuższego
        int maxLength = Math.max(str1.length(), str2.length());
        str1 = String.format("%-" + maxLength + "s", str1);
        str2 = String.format("%-" + maxLength + "s", str2);

        // Obliczamy odległość Hamminga
        int hammingDistance = 0;
        for (int i = 0; i < maxLength; i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
}
