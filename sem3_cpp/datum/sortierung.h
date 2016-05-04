/* 
 * File:   sortierung.h
 * Author: viktorianer
 *
 * Created on 9. Mai 2011, 11:14
 */

#ifndef SORTIERUNG_H
#define	SORTIERUNG_H

#include <climits>

class Sortierung
{
  public:
    static void vertausche(long& x, long& y);
    static void vertausche(int& x, int& y);

    static void vertausche(long double& x, long double& y);
    static void vertausche(double& x, double& y);
};

#endif	/* SORTIERUNG_H */

