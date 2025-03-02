import java.util.regex.Matcher;
import java.util.regex.Pattern;

class SyntaxErrorException extends Exception {
    public SyntaxErrorException(String message) {
        super(message);
    }
}

class IllegalCharacterException extends Exception {
    public IllegalCharacterException(String message) {
        super(message);
    }
}

public class MathEvaluator {

    public static void evaluateExpression(String expression) {
        try {
            if (!expression.matches("[0-9+\\-*/()=\\s]+")) {
                throw new IllegalCharacterException("illegal characters");
            }

            if (expression.contains("=")) {
                String[] parts = expression.split("=");
                if (parts.length != 2) {
                    throw new SyntaxErrorException("syntax error: = expected");
                }
            }

            System.out.println("Processing expression: " + expression);

        } catch (SyntaxErrorException | IllegalCharacterException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        }
    }
}
