package examples.chapter03.item12;

import java.util.Collections;
import java.util.Set;
import java.util.TreeSet;

public class WordList
{
  public static void main(String[] args)
  {
    String[] args2 = {"An", "Unordered", "String", "!"};
    Set<String> s = new TreeSet<String>();
    Collections.addAll(s, args2);
    System.out.println(s);
  }
}
