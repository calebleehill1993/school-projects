import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException, IEvilHangmanGame.GuessAlreadyMadeException {
        String dictionaryFileName = args[0];
        int wordLength = Integer.parseInt(args[1]);
        int guesses = Integer.parseInt(args[2]);
        EvilHangmanGame evilHangmanGame = new EvilHangmanGame();
        evilHangmanGame.startGame(new File(dictionaryFileName), wordLength);
        String guess = "GUESS";
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        for(int guessesLeft = guesses; guessesLeft > 0; guessesLeft--) {
            System.out.println("You have " + guessesLeft + " guesses left");
            System.out.print("Used letters:");
            for (char letter : evilHangmanGame.usedLetters) {
                System.out.print(" ");
                System.out.print(letter);
            }
            System.out.print("\nWord: " + evilHangmanGame.theWord);
            boolean error;
            do {
                error = false;
                System.out.print("\nEnter guess: ");
                guess = input.readLine();
                if (guess.length() != 1 || Character.toLowerCase(guess.charAt(0)) < 'a' || Character.toLowerCase(guess.charAt(0)) > 'z') {
                    System.out.print("\nInvalid input");
                    error = true;
                }
                else if (evilHangmanGame.usedLetters.contains(guess.charAt(0))) {
                    System.out.print("\nYou already used that letter");
                    error = true;
                }
            } while (error);

            Set<String> thing = evilHangmanGame.makeGuess(Character.toLowerCase(guess.charAt(0)));
        }
    }
}
