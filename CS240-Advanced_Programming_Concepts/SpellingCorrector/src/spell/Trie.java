package spell;

import java.util.SortedSet;
import java.util.TreeSet;

public class Trie implements ITrie{
	private Node root;
	private int nodeCount;
	private int wordCount;
	private SortedSet<String> prevWords;
	private int hash;
	private String toString;

	public Trie(){
		root = new Node();
		nodeCount = 1;
		wordCount = 0;
		prevWords = new TreeSet<String>();
		hash = 0;
		toString = "";
	}

	public void add(String word){
		prevWords.add(word);
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
		return getList(root, "");
	}

	public String getList(Node currentNode, String currentWord){
		for (int i = 0; i < 26; i++){
			if (currentNode.nodeArray[i] != null){
				if (currentNode.nodeArray[i].getValue() > 0){
					System.out.print(currentWord);
					toString += currentWord + (char)('a' + i) + "\n";
				}
				boolean empty = true;
				for (int j = 0; j < 26; j++) {
					if (currentNode.nodeArray[i].nodeArray[j] != null){
						empty = false;
						break;
					}
				}
				if (!empty){
					return getList(currentNode.nodeArray[i], currentWord + (char)('a' + i));
				}
			}
		}
		if (toString == ""){
			return "";
		}
		System.out.print(toString);
		return toString.substring(0, toString.length() - 1);
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
			return true;
		}
	}

//	public boolean equals2()

}
