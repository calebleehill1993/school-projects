import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class EvilHangmanGame implements IEvilHangmanGame{
    public Set<String> words = new TreeSet<>();
    public Set<Character> usedLetters = new TreeSet<>();
    public String theWord;
    public int wordLength;
    public TreeMap<String, Set<String>> map = new TreeMap<>();

    @Override
    public void startGame(File dictionary, int wordLength) {
        theWord = theWord = new String(new char[wordLength]).replace("\0", "-");
        this.wordLength = wordLength;
        try (Scanner scanner = new Scanner(dictionary)) {
            while (scanner.hasNext()) {
                String word = scanner.next().toLowerCase();
                if (word.length() == wordLength) {
                    words.add(word);
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public Set<String> makeGuess(char guess) throws GuessAlreadyMadeException {
        usedLetters.add(guess);
        map.clear();
        Set<Set<Character>> setOfSets = new TreeSet<>();
        Vector<String> patterns = new Vector<>();
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < wordLength; i++) {
                if (word.charAt(i) == guess) {
                    sb.append(guess);
                }
                else {
                    sb.append('-');
                }
            }
            String key = new String(sb);
            if (map.containsKey(key)) {
                map.get(key).add(word);
            }
            else {
                Set<String> value = new TreeSet<>();
                value.add(word);
                map.put(key, value);
                patterns.add(key);
            }
        }
        int size = 0;
        Vector<String> biggestSets = new Vector<>();
        for (String key : patterns) {
            if (map.get(key).size() > size) {
                size = map.get(key).size();
                biggestSets.clear();
                biggestSets.add(key);
            }
            else if (map.get(key).size() == size) {
                biggestSets.add(key);
            }
        }
        if (biggestSets.size() > 1) {
            if (biggestSets.contains(new String(new char[wordLength]).replace("\0", "-"))) {
                biggestSets.setElementAt(new String(new char[wordLength]).replace("\0", "-"), 0);
            }
            else {
                //CUTTING BIGGESTSETS INTO FEWESTLETTERS
                Vector<String> fewestLetters = new Vector<>();
                int numberOfLetters = wordLength;
                for (String key : biggestSets) {
                    int temp = 0;
                    for (int i = 0; i < wordLength; i++){
                        if (key.charAt(i) == guess) {
                            temp++;
                        }
                    }
                    if (temp < numberOfLetters) {
                        fewestLetters.clear();
                        fewestLetters.add(key);
                        numberOfLetters = temp;
                    }
                    else if (temp == numberOfLetters) {
                        fewestLetters.add(key);
                    }
                }
                if (fewestLetters.size() > 1) {
                    //TESTING FEWEST LETTERS FOR RIGHT MOST LETTER
                    Vector<String> rightMostLetter = new Vector<>();
                    int leftIterator = 0;
                    for (String key : fewestLetters) {
                        for (int i = wordLength - 1; i >= leftIterator; i--){
                            if (key.charAt(i) == guess && i > leftIterator) {
                                leftIterator = i;
                                rightMostLetter.clear();
                                rightMostLetter.add(key);
                            }
                            else if (key.charAt(i) == guess) {
                                rightMostLetter.add(key);
                            }
                        }
                    }
                    while (rightMostLetter.size() > 1) {
                        //TESTING RIGHT MOST LETTER FOR NEXT RIGHT MOST LETTER CONTINUOUSLY
                        int newLeftIterator = 0;
                        Vector<String> newRightMostLetter = new Vector<>();
                        for (String key : rightMostLetter) {
                            for (int i = leftIterator - 1; i >= 0; i--){
                                if (key.charAt(i) == guess && i > newLeftIterator) {
                                    newLeftIterator = i;
                                    newRightMostLetter.clear();
                                    newRightMostLetter.add(key);
                                }
                                else if (key.charAt(i) == guess) {
                                    newRightMostLetter.add(key);
                                }
                            }
                        }
                        leftIterator = newLeftIterator;
                        rightMostLetter = newRightMostLetter;
                    }
                    biggestSets.clear();
                    biggestSets.add(rightMostLetter.elementAt(0));

                }
                else {
                    biggestSets.clear();
                    biggestSets.add(fewestLetters.elementAt(0));
                }
            }
        }

        if (biggestSets.elementAt(0).equals(new String(new char[wordLength]).replace("\0", "-"))) {
            System.out.print("\nSorry, there are no " + guess + "'s");
        }
        else {
            int numberOf = 0;
            StringBuilder newWord = new StringBuilder();
            for (int i = 0; i < theWord.length(); i++) {
                if (guess == biggestSets.elementAt(0).charAt(i)) {
                    numberOf++;
                    newWord.append(guess);
                }
                else {
                    newWord.append(theWord.charAt(i));
                }
            }
            System.out.print("\nYes, there is " + numberOf + " " + guess);
            theWord = new String(newWord);
        }
        words = map.get(biggestSets.elementAt(0));
        return null;
    }
}
