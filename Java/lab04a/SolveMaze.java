import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class SolveMaze {
    private int[][] maze;
    private int startX, startY, endX, endY;
    private ArrayList<int[]> path = new ArrayList<>();

    public SolveMaze() {
        LoadTSVToArray loader = new LoadTSVToArray();
        String[][] loadedMaze = loader.getDataArray();
        maze = convertToIntArray(loadedMaze);
        locateStartEnd();
    }

    // Konwersja z tablicy String na tablicę int zgodnie z założeniami
    private int[][] convertToIntArray(String[][] loadedMaze) {
        int[][] mazeArray = new int[loadedMaze.length][loadedMaze[0].length];
        for (int i = 0; i < loadedMaze.length; i++) {
            for (int j = 0; j < loadedMaze[i].length; j++) {
                switch (loadedMaze[i][j]) {
                    case "W":
                        mazeArray[i][j] = -1;
                        break;
                    case "C":
                        mazeArray[i][j] = 0;
                        break;
                    case "S":
                        mazeArray[i][j] = 1;
                        break;
                    case "F":
                        mazeArray[i][j] = -2;
                        break;
                    default:
                        mazeArray[i][j] = 0;
                }
            }
        }
        return mazeArray;
    }

    // Znajdź pozycję startową i końcową
    private void locateStartEnd() {
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                if (maze[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (maze[i][j] == -2) {
                    endX = i;
                    endY = j;
                }
            }
        }
    }

    // Numerowanie sąsiadów węzła n jako n + 1
    private void numberAdjacent(int num) {
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                if (maze[i][j] == num) {
                    if (i > 0 && maze[i - 1][j] == 0) maze[i - 1][j] = num + 1;
                    if (i < maze.length - 1 && maze[i + 1][j] == 0) maze[i + 1][j] = num + 1;
                    if (j > 0 && maze[i][j - 1] == 0) maze[i][j - 1] = num + 1;
                    if (j < maze[i].length - 1 && maze[i][j + 1] == 0) maze[i][j + 1] = num + 1;
                }
            }
        }
    }

    // Eksploruj labirynt w poszukiwaniu ścieżki
    public void makePaths() {
        int currentStep = 2;
        maze[startX][startY] = currentStep;

        while (maze[endX][endY] == -2) {
            numberAdjacent(currentStep);
            currentStep++;
            if (currentStep > maze.length * maze[0].length) {
                return;
            }
        }
    }

    // Wycofaj się od punktu końcowego do startowego, aby znaleźć najkrótszą ścieżkę
    public void backtrack() {
        int x = endX;
        int y = endY;
        int step = maze[x][y];

        while (step > 1) {
            path.add(0, new int[]{x, y});
            if (x > 0 && maze[x - 1][y] == step - 1) x--;
            else if (x < maze.length - 1 && maze[x + 1][y] == step - 1) x++;
            else if (y > 0 && maze[x][y - 1] == step - 1) y--;
            else if (y < maze[x].length - 1 && maze[x][y + 1] == step - 1) y++;
            step--;
        }
        path.add(0, new int[]{startX, startY});
    }

    // Zapisz labirynt ze ścieżką do pliku
    public void saveMazeWithPath(String outputPath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputPath))) {
            for (int i = 0; i < maze.length; i++) {
                for (int j = 0; j < maze[i].length; j++) {
                    if (containsInPath(i, j)) writer.write("% ");
                    else switch (maze[i][j]) {
                        case -1 -> writer.write("W ");
                        case 0 -> writer.write("C ");
                        case 1 -> writer.write("S ");
                        case -2 -> writer.write("F ");
                        default -> writer.write(". ");
                    }
                }
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private boolean containsInPath(int x, int y) {
        for (int[] coord : path) {
            if (coord[0] == x && coord[1] == y) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        SolveMaze solver = new SolveMaze();
        solver.makePaths();
        solver.backtrack();
        solver.saveMazeWithPath("solved_maze.txt");
        System.out.println("Labirynt ze ścieżką został zapisany do pliku: solved_maze.txt");
    }
}
