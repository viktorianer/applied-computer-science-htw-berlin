#include "sortierung.h"

/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:  \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:  \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Sortierung::vertausche(long& x, long& y)
{
  long ablage = x;
  x = y;
  y = ablage;
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:  \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:  \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Sortierung::vertausche(int& x, int& y)
{
  vertausche(x, y);
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:  \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:  \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                      \c Output: \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Sortierung::vertausche(long double& x, long double& y)
{
  double ablage = x;
  x = y;
  y = ablage;
}
/**Vertauschfunktion fuer Selectionsort. Vertauscht Zahl 1 mit der Zahl 2.
 *
 * @param x   		\c Input:  \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *                \c Output: \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 * @param y   		\c Input:  \n Die Adresse, an der die zweite zu tauschende Zahl gespeichert ist.\n
 *                \c Output: \n Die Adresse, an der die erste zu tauschende Zahl gespeichert ist.\n
 *
 * @author	Viktor Schmidt, s0529652
 * @version	1.0
 */
void Sortierung::vertausche(double& x, double& y)
{
  vertausche(x, y);
}