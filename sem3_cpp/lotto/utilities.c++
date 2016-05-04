#include "utilities.h"

/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:   Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:   Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Utilities::vertausche(long& x, long& y)
{
  long ablage = x;
  x = y;
  y = ablage;
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:   Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:   Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Utilities::vertausche(int& x, int& y)
{
  vertausche(x, y);
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:   Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:   Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output:  Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Utilities::vertausche(long double& x, long double& y)
{
  double ablage = x;
  x = y;
  y = ablage;
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:   Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                \c Output:  Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:   Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                \c Output:  Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Utilities::vertausche(double& x, double& y)
{
  vertausche(x, y);
}

/**Vergleichfunktion fuer Quicksort.
 *
 * @param i   		\c Input:   Die Adresse, an der die erste zu vergleichende Zahl gespeichert ist.\n
 * @param j   		\c Input:   Die Adresse, an der die zweite zu vergleichende Zahl gespeichert ist.
 *
 * @return 	Die Funktion liefert einen negativen Wert, wenn ihr erstes Argument (der Suchschlüssel)
 * 					kleiner als ihr zweites Argument (ein Tabelleneintrag) ist, Null, wenn beide gleich sind,
 * 					und sonst einen positiven Wert.
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
int Utilities::vergleiche(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}