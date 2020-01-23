package spell;
import spell.INode;

public class Node implements INode{
  int frequency;
  String substr;
  Node[] nodeArray = new Node[26];
  public int getValue() {
    return frequency;
  }
}

