package examples.chapter02.item02.builderinterface;

/**
 *
 *
 * @author Viktor Schmidt, (vschmidt)
 * @version	1.0
 */
public class CocaColaBox implements Comparable<CocaColaBox>
{
  NutritionFacts[] cocaCola = new NutritionFacts[6];

  /**
   * Creates a default object of CocaColaBox with default attributes.
   */
  public CocaColaBox()
  {
    Builder builder = new NutritionFacts.NutritionFactsBuilder(240, 8)
            .calories(100)
            .sodium(35)
            .carbohydrate(27);
    for (int i = 0; i < cocaCola.length; i++)
    {
      cocaCola[i] = NutritionFacts.newInstance(builder);

    }
  }

  /**
   * Creates a copy of the original object. The general intent is that, for
   * any object x, the expression:
   * <p/>
   * CocaColaBox(x) != x
   * <p/>
   * will be true, and that the expression:
   * <p/>
   * CocaColaBox(x).getClass() == x.getClass()
   * <p/>
   * will be true, but these are not absolute requirements. While it is
   * typically the case that:
   * <p/>
   * CocaColaBox(x).equals(x)
   * <p/>
   * will be true, this is not an absolute requirement.
   * <p/>
   * @param original the reference object with which to copy.
   */
  public CocaColaBox(CocaColaBox original)
  {
    //TODO write a copy constructor.
    throw new UnsupportedOperationException("Not supported yet.");
  }

  /**
   * Indicates whether some other object is "equal to" this one.
   * <p/>
   * The equals method implements an equivalence relation on non-null object
   * references:
   * It is reflexive: for any non-null reference value x, x.equals(x)
   * return true.
   * It is symmetric: for any non-null reference values x and y, x.equals(y)
   * return true if and only if y.equals(x) returns true.
   * It is transitive: for any non-null reference values x, y, and z, if
   * x.equals(y) returns true and y.equals(z) returns true, then x.equals(z)
   * return true.
   * It is consistent: for any non-null reference values x and y, multiple
   * invocations of x.equals(y) consistently return true or consistently return
   * false, provided no information used in equals comparisons on the objects is
   * modified.
   * For any non-null reference value x, x.equals(null) return false.
   * <p/>
   * Note that it is generally necessary to override the hashCode method
   * whenever this method is overridden, so as to maintain the general contract
   * for the hashCode method, which states that equal objects must have equal
   * hash codes.
   * <p/>
   * @param o the reference object with which to compare.
   * <p/>
   * @return true if this object is the same as the obj argument; false
   *         otherwise.
   */
  @Override
  public boolean equals(Object o)
  {
    if (this == o)
    {
      return true;
    }
    if (!(o instanceof CocaColaBox))
    {
      return false;
    }
    CocaColaBox other = (CocaColaBox)o;
    /**
     * For each "significant", not immutable field, check if that fiel
     * corresponding.
     * For primitiv fiels whose type is not float or double, use the ==
     * operator.
     * For object reference fields, invoke the equals method recursively.
     * For float, use Float.compare and double Double.compare .
     * For array fields, apply these guidelines to each element.
     * If every element is significant, you can use Arrays.equals.
     * <p/>
     * Idom for reference fields:
     * (field == null ? o.field == null : field.equals(o.field))
     * ...
     * <p/>
     * fast:
     * (field == o.field
     * || (field != null && field.equals(o.field)))
     * ...
     */
    //TODO write a equals method.
    throw new UnsupportedOperationException("Not supported yet.");
  }

  /**
   * Returns a hash code value for the object. This method is supported for the
   * benefit of hashtables such as those provided by java.util.Hashtable.
   * <p/>
   * Equal objects must have equal hash codes.
   * <p/>
   * @return a hash code value for this object.
   */
  @Override
  public int hashCode()
  {
    int hash = 17;
    /**
     * For each "significant" field f:
     * a. compute an int hash code c
     * boolean: f ? 1 : 0;
     * byte, char, short, int: (int)f;
     * long: (int)(f ^ (f >>> 32));
     * float: Float.floatToIntBits(f)
     * double: long dF = Double.doubleToLongBits(f);
     * (int)(dF ^ (dF >>> 32));
     * reference fields:
     * recursively equals: recursively hash;
     * more complex: canonical representation;
     * Idom:
     * (field == null ? o : field.hashCode())
     * <p/>
     * if the value is null: return 0;
     * array: each element separate;
     * or Arras.hashCode();
     * b. combine the hash code:
     * hash = 31 * hash + c;
     * return hash;
     * verify: equal instances have equal hash code!
     */
    /**
     * If computing hash code is significat, cash it in object
     * when the instance is created!
     * int hash = hashCode;
     * if (hash == 0)
     * {
     * hash == 17;
     * ...
     * hashCode = hash;
     * }
     */
    //TODO write hash method.
    throw new UnsupportedOperationException("Not supported yet.");
  }

  /**
   * Returns a string representation of the object.
   * <p/>
   * The exact details of the representation are unspecified and subject to
   * change, but the following may be regarded as typical:
   * <p/>
   * TODO ...
   * <p/>
   * @return Returns a brief description of this object.
   */
  @Override
  public String toString()
  {
    StringBuilder sb = new StringBuilder();
    sb.append("CocaColaBox{");
    for (NutritionFacts nf : cocaCola)
    {
      sb.append("\ncocaCola=");
      sb.append(nf);
    }
    sb.append('}');
    return sb.toString();
  }

  public int compareTo(CocaColaBox o)
  {
    /**
     * Compare integral primitive fields using the relational operators < and >.
     * For floating-point fields, use Double.compare or Float.compare.
     * For array fields, apply these guidelines to each element.
     * <p/>
     * You must start with the most significant field. If a comparison results
     * in anything other than zero, you're done - just return the result.
     * <p/>
     * If all fields are equal, return zero.
     */
    int relation = 0;
    if (relation == 0)
    {
      //TODO write next comparison.
    }
    //TODO write a compareTo method.
    throw new UnsupportedOperationException("Not supported yet.");
  }
}
