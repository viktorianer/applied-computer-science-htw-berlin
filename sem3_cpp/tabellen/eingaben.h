#ifndef EINGABEN_H
#define	EINGABEN_H

#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cfloat>

#include "sortierung.h"

using namespace std;

long erfasse_long(long min, long max);
long erfasse_long();
long erfasse_long(string text);
long erfasse_long(string text, long min, long max);

int erfasse_int(int min, int max);
int erfasse_int();
int erfasse_int(string text);
int erfasse_int(string text, int min, int max);

long double erfasse_long_double(long double min, long double max);
long double erfasse_long_double();
long double erfasse_long_double(string text);
long double erfasse_long_double(string text, long double min, long double max);

double erfasse_double(double min, double max);
double erfasse_double();
double erfasse_double(string text);
double erfasse_double(string text, double min, double max);

bool erfasse_bool();

void erfasse_zeichenkette(char eingabe[], streamsize anzahl);

#endif	/* EINGABEN_H */