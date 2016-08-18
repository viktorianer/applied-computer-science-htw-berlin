// Adds a value component without violating the equals contract - Page 40
package examples.chapter03.item08.composition;

public class ColorPoint
{
  private final Point point;
  private final Color color;

  public ColorPoint(int x, int y, Color color)
  {
    if (color == null)
    {
      throw new NullPointerException();
    }
    point = new Point(x, y);
    this.color = color;
  }

  /**
   * Returns the point-view of this color point.
   */
  public Point asPoint()
  {
    return point;
  }

  @Override
  public boolean equals(Object o)
  {
    if (!(o instanceof ColorPoint))
    {
      return false;
    }
    ColorPoint cp = (ColorPoint)o;
    return cp.point.equals(point) && cp.color.equals(color);
  }

  @Override
  public int hashCode()
  {
    return point.hashCode() * 33 + color.hashCode();
  }

  public static void main(String[] args)
  {
    // First equals function violates symmetry
    Point p = new Point(1, 2);
    ColorPoint cp = new ColorPoint(1, 2, Color.RED);
    System.out.println("Symmetric:"
            + "\np.equals(cp) " + p.equals(cp)
            + "\ncp.equals(p) " + cp.equals(p));

    // Second equals function violates transitivity
    ColorPoint p1 = new ColorPoint(1, 2, Color.RED);
    Point p2 = new Point(1, 2);
    ColorPoint p3 = new ColorPoint(1, 2, Color.BLUE);
    System.out.println("Transitive:"
            + "\np1.equals(p2) " + p1.equals(p2)
            + "\np2.equals(p3) " + p2.equals(p3)
            + "\np1.equals(p3) " + p1.equals(p3));

    ColorPoint p4 = new ColorPoint(1, 2, Color.RED);

    System.out.println("equals:"
            + "\np1.equals(cp) " + p1.equals(cp)
            + "\ncp.equals(p1) " + cp.equals(p1));

    System.out.println("Transitive:"
            + "\np1.equals(cp) " + p1.equals(cp)
            + "\ncp.equals(p4) " + cp.equals(p4)
            + "\np1.equals(p4) " + p1.equals(p4));
  }
}