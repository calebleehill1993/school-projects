package spell;

import java.util.SortedSet;
import java.util.TreeSet;

public class Trie implements ITrie{

	private Node root;
	private int nodeCount;
	private int wordCount;
	private int hash;
	private String toString;
	private boolean equal;

	public Trie(){
		root = new Node();
		nodeCount = 1;
		wordCount = 0;
		hash = 0;
		toString = "";
		equal = true;
	}

	public void add(String word){
		Node n = root;
		for(int i = 0; i < word.length(); i++){
			if(n.nodeArray[word.charAt(i) - 'a'] == null){
				n.nodeArray[word.charAt(i) - 'a'] = new Node();
				n.nodeArray[word.charAt(i) - 'a'].substr = word.substring(0, i + 1);
				nodeCount++;
				if(i == word.length() - 1){
					n.nodeArray[word.charAt(i) - 'a'].substr = word.substring(0, i + 1);
					wordCount++;
					hash += word.hashCode();
					n.nodeArray[word.charAt(i) - 'a'].frequency++;
				}
				n = n.nodeArray[word.charAt(i) - 'a'];
			} else {
				if( i == word.length() -1){
					if (n.nodeArray[word.charAt(i) - 'a'].frequency == 0){
						wordCount++;
						hash += word.hashCode();
					}
					n.nodeArray[word.charAt(i) - 'a'].frequency++;
				} else
				n = n.nodeArray[word.charAt(i) - 'a'];
			}
		}
	}

	public Node find(String word){
		Node n = root;
		for(int i = 0; i < word.length(); i++){
			if(n.nodeArray[word.charAt(i) - 'a'] == null)
				return null;
			else{
				if(i == word.length() - 1)	{
					if(n.nodeArray[word.charAt(i) - 'a'].frequency > 0)
						return n.nodeArray[word.charAt(i) - 'a'];
					else
						return null;
				}
				n = n.nodeArray[word.charAt(i) - 'a'];
			}
		}
		return null;
	}

	public int getWordCount(){ return wordCount;}
	public int getNodeCount(){ return nodeCount;}


	@Override
	public String toString(){
		toString = "";
		getList(root, "");
		return toString.substring(0, toString.length() - 1);
	}

	public void getList(Node currentNode, String currentWord){
		for (int i = 0; i < 26; i++){
			if (currentNode.nodeArray[i] != null){
				if (currentNode.nodeArray[i].getValue() > 0){
					toString += currentWord + (char)('a' + i) + "\n";
				}
				getList(currentNode.nodeArray[i], currentWord + (char)('a' + i));
			}
		}
	}

	@Override
	public int hashCode() { return wordCount * 12 * nodeCount * 17 + hash;}

	@Override
	public boolean equals(Object o){
		if(o == null)
			return false;
		else if(this.getClass() != o.getClass())
			return false;
		else{
			equal = true;
			equals2(root, ((Trie) o).getRoot());
			return equal;
		}
	}

	public void equals2(Node currentNode, Node oNode){
		for (int i = 0; i < 26; i++){
			if (currentNode.nodeArray[i] != null && oNode.nodeArray[i] != null){
				if (currentNode.nodeArray[i].getValue() == oNode.nodeArray[i].getValue()){
					equals2(currentNode.nodeArray[i], oNode.nodeArray[i]);
				}
				else {
					equal = false;
					return;
				}
			}
			else if (currentNode.nodeArray[i] == null && oNode.nodeArray[i] == null) {

			}
			else {
				equal = false;
				return;
			}
		}
	}

	public Node getRoot() {
		return root;
	}

}
