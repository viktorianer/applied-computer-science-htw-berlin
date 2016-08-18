// Set obeserver callback interface - Page 266
package examples.chapter10.item67;

public interface SetObserver<E>
{
  // Invoked when an element is added to the observable set
  void added(ObservableSet<E> set, E element);
}
