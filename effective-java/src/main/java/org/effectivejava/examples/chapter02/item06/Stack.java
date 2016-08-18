// Can you spot the "memory leak"?
package examples.chapter02.item06;

import java.util.Arrays;
import examples.chapter02.item02.builder.NutritionFacts;

public class Stack
{
  private Object[] elements;
  private int size = 0;
  private static final int DEFAULT_INITIAL_CAPACITY = 16;

  public Stack()
  {
    elements = new Object[DEFAULT_INITIAL_CAPACITY];
  }

  public void push(Object e)
  {
    ensureCapacity();
    elements[size++] = e;
  }

  public Object pop()
  {
    if (size == 0)
    {
      throw new EmptyStackException();
    }
//    Object result = elements[--size];
//    elements[size] = null;
    return elements[--size];
  }

  /**
   * Ensure space for at least one more element, roughly doubling the capacity
   * each time the array needs to grow.
   */
  private void ensureCapacity()
  {
    if (elements.length == size)
    {
      elements = Arrays.copyOf(elements, 2 * size + 1);
    }
  }

  public static void main(String[] args)
  {

    Stack stack = new Stack();
    stack.push(new NutritionFacts.Builder(240, 8)
            .calories(100)
            .sodium(35)
            .carbohydrate(27)
            .build());
    stack.push(new NutritionFacts.Builder(240, 8)
            .calories(200)
            .sodium(35)
            .carbohydrate(27)
            .build());
    stack.push(new NutritionFacts.Builder(240, 8)
            .calories(300)
            .sodium(35)
            .carbohydrate(27)
            .build());

    NutritionFacts oldNF = (NutritionFacts)stack.pop();

    stack.pop();

    stack.push(new NutritionFacts.Builder(240, 8)
            .calories(400)
            .sodium(35)
            .carbohydrate(27)
            .build());

    stack.push(oldNF);

  }
}
