#ifndef RECHNER_H
#define	RECHNER_H

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

#include "ausgaben.h"
#include "eingaben.h"
#include "arrays.h"

using namespace std;

void rechner(long double (*func)(long double), char **argv);
void rechner(long double (*func)(long double, long double), char **argv);
void rechner(long double (*func)(long double), string funcname);
void rechner(long double (*func)(long double, long double), string funcname);

void rechner_rechne(long double (*func)(long double), string funcname, long double anfangwert,
  int folgewerte, long double abstand, int praezision);
void rechner_rechne(long double (*func)(long double, long double), string funcname, long double anfangwert,
  long double exponent, int folgewerte, long double abstand, int praezision);

void erfasse_parameter(string funcname, long double& anfangwert, int& folgewerte, long double& abstand, int& praezision);
void erfasse_parameter(long double& anfangwert, long double& exponent, int& folgewerte, long double& abstand, int& praezision);

void rechner_ausgabe(long double *folge, long double (*werte)[10], int folgewerte, string funcname, int praezision);
void tabellen_kopf(int erste_spalte, int letzte_spalte, int spaltenbreite);

#endif	/* RECHNER_H */

