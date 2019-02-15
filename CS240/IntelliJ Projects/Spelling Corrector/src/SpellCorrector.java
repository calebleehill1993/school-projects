import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class SpellCorrector implements ISpellCorrector {
    Trie trie = new Trie();

    @Override
    public void useDictionary(String dictionaryFileName) throws IOException {
        File wordsFile = new File(dictionaryFileName);
        try (Scanner words = new Scanner(wordsFile)) {
            while (words.hasNext()) {
                trie.add(words.next());
            }
        }
    }

    @Override
    public String suggestSimilarWord(String inputWord) {
        ITrie.INode findings = trie.find(inputWord);
        if (findings != null && findings.getValue() > 0) {
            return inputWord;
        }
        else {
            Set<String> deletionDistanceWords = deletionWords(inputWord);
            Set<String> transpositionDistanceWords = transpositionWords(inputWord);
            Set<String> alterationDistanceWords = alterationWords(inputWord);
            Set<String> insertionDistanceWords = insertionWords(inputWord);
            Set<String> allDistanceOne = new TreeSet<>();
            allDistanceOne.addAll(deletionDistanceWords);
            allDistanceOne.addAll(transpositionDistanceWords);
            allDistanceOne.addAll(alterationDistanceWords);
            allDistanceOne.addAll(insertionDistanceWords);
            while (!oneInDictionary(allDistanceOne)) {
                allDistanceOne = nextDistanceWords(allDistanceOne);
            }
            int maxCount = 0;
            Set<String> closestWords = new TreeSet<>();
            for (String word : allDistanceOne) {
                if (trie.find(word) != null) {
                    if (trie.find(word).getValue() > maxCount) {
                        closestWords.clear();
                        closestWords.add(word);
                        maxCount = trie.find(word).getValue();
                    }
                    else if (trie.find(word).getValue() == maxCount) {
                        closestWords.add(word);
                    }
                }
            }
            return ((TreeSet<String>) closestWords).first();
        }
    }

    public Set<String> deletionWords(String word) {
        Set<String> deletionWords = new TreeSet<>();
        for (int i = 0; i < word.length(); i++) {
            deletionWords.add(removeLetter(word, i));
        }
        return deletionWords;
    }

    public Set<String> transpositionWords(String word) {
        Set<String> transpositionWords = new TreeSet<>();
        for (int i = 0; i < word.length() - 1; i++) {
            transpositionWords.add(transposeLetters(word, i));
        }
        return transpositionWords;
    }

    public Set<String> alterationWords(String word) {
        Set<String> alterationWords = new TreeSet<>();
        for (int i = 0; i < word.length(); i++) {
            alterationWords.addAll(alterLetters(word, i));
        }
        return alterationWords;
    }

    public Set<String> insertionWords(String word) {
        Set<String> insertionWords = new TreeSet<>();
        for (int i = 0; i <= word.length(); i++) {
            insertionWords.addAll(insertLetters(word, i));
        }
        return insertionWords;
    }

    public String removeLetter(String str, int i) {
        return str.substring(0, i) + str.substring(i + 1, str.length());
    }

    public String transposeLetters(String str, int i) {
        String transposed = new String(new StringBuilder(str.substring(0, i) + str.charAt(i + 1) + str.charAt(i) + str.substring(i + 2, str.length())));
        return transposed;
    }

    public Set<String> alterLetters(String str, int i) {
        char letter = str.charAt(i);
        Set<String> newWords = new TreeSet<>();
        char[] strChar = str.toCharArray();
        for (int j = 0; j < 26; j++) {
            if ('a' + j != letter) {
                strChar[i] = (char)('a' + j);
                newWords.add(new String(strChar));
            }
        }
        return newWords;
    }

    public  Set<String> insertLetters(String str, int i) {
        Set<String> newWords = new TreeSet<>();
        for (int j = 0; j < 26; j++) {
            newWords.add(str.substring(0, i) + (char)('a' + j) + str.substring(i, str.length()));
        }
        return newWords;
    }

    public Set<String> nextDistanceWords(Set<String> currentWords) {
        Set<String> nextDistanceWords = new TreeSet<>();
        for (String word : currentWords) {
            Set<String> deletionDistanceWords = deletionWords(word);
            Set<String> transpositionDistanceWords = transpositionWords(word);
            Set<String> alterationDistanceWords = alterationWords(word);
            Set<String> insertionDistanceWords = insertionWords(word);
            nextDistanceWords.addAll(deletionDistanceWords);
            nextDistanceWords.addAll(transpositionDistanceWords);
            nextDistanceWords.addAll(alterationDistanceWords);
            nextDistanceWords.addAll(insertionDistanceWords);
        }
        return nextDistanceWords;
    }

    public boolean oneInDictionary(Set<String> currentWords) {
        for (String word : currentWords) {
            if (trie.find(word) != null && trie.find(word).getValue() > 0) {
                return true;
            }
        }
        return false;
    }
}
