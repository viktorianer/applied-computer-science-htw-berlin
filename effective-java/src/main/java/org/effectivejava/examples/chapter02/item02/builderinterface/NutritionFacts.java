// NutritionFactsBuilder Pattern - Pages 14-15
package examples.chapter02.item02.builderinterface;

public class NutritionFacts
{
  private final int servingSize;
  private final int servings;
  private final int calories;
  private final int fat;
  private final int carbohydrate;
  private final int sodium;

  public static class NutritionFactsBuilder implements Builder<NutritionFacts>
  {
    // Required parameters
    private final int servingSize;
    private final int servings;
    // Optional parameters - initialized to default values
    private int calories = 0;
    private int fat = 0;
    private int carbohydrate = 0;
    private int sodium = 0;

    public NutritionFactsBuilder(int servingSize, int servings)
    {
      this.servingSize = servingSize;
      this.servings = servings;
    }

    public NutritionFactsBuilder calories(int val)
    {
      calories = val;
      return this;
    }

    public NutritionFactsBuilder fat(int val)
    {
      fat = val;
      return this;
    }

    public NutritionFactsBuilder carbohydrate(int val)
    {
      carbohydrate = val;
      return this;
    }

    public NutritionFactsBuilder sodium(int val)
    {
      sodium = val;
      return this;
    }

    public NutritionFacts build()
    {
      return new NutritionFacts(this);
    }
  }

  private NutritionFacts(NutritionFactsBuilder builder)
  {
    servingSize = builder.servingSize;
    servings = builder.servings;
    calories = builder.calories;
    fat = builder.fat;
    sodium = builder.sodium;
    carbohydrate = builder.carbohydrate;
  }

  public static NutritionFacts newInstance(Builder<? extends NutritionFacts> builder)
  {
    return builder.build();
  }

  @Override
  public String toString()
  {
    return "NutritionFacts{" + "servingSize=" + servingSize + ", servings=" + servings + ", calories=" + calories + ", fat=" + fat + ", carbohydrate=" + carbohydrate + ", sodium=" + sodium + '}';
  }

  public static void main(String[] args)
  {
    Builder builder = new NutritionFacts.NutritionFactsBuilder(240, 8)
            .calories(100)
            .sodium(35)
            .carbohydrate(27);

    NutritionFacts cocaCola = NutritionFacts.newInstance(builder);

    System.out.println(cocaCola.toString());

    NutritionFacts cocaColaZiro = new NutritionFacts.NutritionFactsBuilder(240, 8)
            .calories(0)
            .sodium(35)
            .carbohydrate(27)
            .build();

    System.out.println(cocaColaZiro);

    CocaColaBox box = new CocaColaBox();
    System.out.println(box);
  }
}
