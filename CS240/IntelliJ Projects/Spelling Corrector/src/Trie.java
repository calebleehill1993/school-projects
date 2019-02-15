import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Trie implements ITrie {
    Node root = new Node();
    private int nodeCount = 1;
    private int wordCount = 0;
    private Set<String> wordsCollection = new TreeSet<>();

    public void addWordContinued(Node nextNode, String subWord, StringBuilder subString) {
        //Only Adds to nodeCount if the Node hasn't been visited.
        if (nextNode.nodes[subWord.charAt(0) - 'a'] == null) {
            nextNode.nodes[subWord.charAt(0) - 'a'] = new Node();
            nodeCount++;
            nextNode.nodes[subWord.charAt(0) - 'a'].subString = new String(subString);
        }
        if (subWord.length() > 1) {
            subString.append(subWord.charAt(1));
            addWordContinued(nextNode.nodes[subWord.charAt(0) - 'a'], subWord.substring(1), subString);
        }
        else {
            //Only Adds to wordCount if the Word is not already found
            if (nextNode.nodes[subWord.charAt(0) - 'a'].count == 0) {
                wordCount++;
                wordsCollection.add(new String(subString));
            }
            nextNode.nodes[subWord.charAt(0) - 'a'].count++;
        }
        return;
    }

    @Override
    public void add(String word) {
        //Only Adds to nodeCount if the Node hasn't been visited.
        if (root.nodes[word.charAt(0) - 'a'] == null) {
            root.nodes[word.charAt(0) - 'a'] = new Node();
            nodeCount++;
            root.nodes[word.charAt(0) - 'a'].subString = new String(String.valueOf(word.charAt(0)));
        }
        if (word.length() > 1) {
            //Recursively adds each node
            addWordContinued(root.nodes[word.charAt(0) - 'a'], word.substring(1), new StringBuilder(word.substring(0, 2)));
        }
        else {
            //Only Adds to wordCount if the Word is not already found
            if (root.nodes[word.charAt(0) - 'a'].count == 0) {
                wordCount++;
                wordsCollection.add(word);
            }
            root.nodes[word.charAt(0) - 'a'].count++;
        }
        return;
    }

    @Override
    public INode find(String word) {
        if(!wordsCollection.contains(word)) {
            return null;
        }
        Node nextNode = root;
        for (int i = 0; i < word.length(); i++) {
            nextNode = nextNode.nodes[word.charAt(i) - 'a'];
        }
        return nextNode;
    }

    @Override
    public int getWordCount() {
        return wordCount;
    }

    @Override
    public int getNodeCount() {
        return nodeCount;
    }

    @Override
    public String toString() {
        return null;
    }

    @Override
    public int hashCode() {
        return 0;
    }

    @Override
    public boolean equals(Object o) {
        return false;
    }

    public class Node implements ITrie.INode {
        int count = 0;
        String subString = null;
        Node[] nodes = new Node[26];
        @Override
        public int getValue() {
            return count;
        }
    }
}
