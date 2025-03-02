class LangDictionary {
    private static final int MAX_HAMMING_DISTANCE = 3;
    private String[][] dict;
    private int size;

    public LangDictionary() {
        LoadTSVToArray dictObj = new LoadTSVToArray();
        this.dict = dictObj.getDataArray();
        this.size = LoadTSVToArray.size;
    }

    // metoda sprawdzajaca ktora kolumna zawiera jezyk
    private int whichCol(String lng) {
        switch (lng) {
            case "ANG":
                return 0;
            case "GER":
                return 1;
            case "ESP":
                return 2;
            default:
                throw new IllegalArgumentException("Nie znaleziono języka");
        }
    }

    // metoda która oblicza różnicę między dwoma słowami.
    private int hammingDistance(String s1, String s2) {
        int lengthDiff = Math.abs(s1.length() - s2.length());
        int minLength = Math.min(s1.length(), s2.length());
        int distance = lengthDiff;

        for (int i = 0; i < minLength; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                distance++;
            }
        }
        return distance;
    }

    // metoda tlumaczaca slowo
    public String translate(String before, String lng) {
        int col = whichCol(lng);
        String closestMatch = null;
        int minDistance = Integer.MAX_VALUE;

        for (int i = 0; i < size; i++) {
            int distance = hammingDistance(before, dict[i][col]);
            if (distance < minDistance) {
                minDistance = distance;
                closestMatch = dict[i][col];
            }

            if (distance == 0) {
                return dict[i][col];
            }
        }

        if (minDistance <= MAX_HAMMING_DISTANCE) {
            return "Czy chodziło Ci o słowo " + closestMatch + "?";
        } else {
            return "Nie znaleziono podobnego słowa w słowniku.";
        }
    }
}