/* 
 * File:   utilities.h
 * Author: viktorianer
 *
 * Created on 9. Mai 2011, 11:14
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <climits>

class Utilities
{
  public:
    static void vertausche(long& x, long& y);
    static void vertausche(int& x, int& y);

    static void vertausche(long double& x, long double& y);
    static void vertausche(double& x, double& y);

    static int vergleiche(const void *i, const void *j);
};

#endif	/* UTILITIES_H */

