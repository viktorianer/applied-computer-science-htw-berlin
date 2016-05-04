/*
 * File:   eingaben.h
 * Created on 21. Mai 2011, 16:58
 */
#ifndef EINGABEN_H
#define EINGABEN_H
// include(s) oder
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <stdexcept>

#include "utilities.h"
// weitere Angaben
using namespace std;

class Eingaben
{
  public:
    static long erfasse_long(long min, long max);
    static long erfasse_long();
    static long erfasse_long(const string text);
    static long erfasse_long(const string text, long min, long max);

    static int erfasse_int(int min, int max);
    static int erfasse_int();
    static int erfasse_int(const string text);
    static int erfasse_int(const string text, int min, int max);

    static long double erfasse_long_double(long double min, long double max);
    static long double erfasse_long_double();
    static long double erfasse_long_double(const string text);
    static long double erfasse_long_double(const string text, long double min, long double max);

    static double erfasse_double(double min, double max);
    static double erfasse_double();
    static double erfasse_double(const string text);
    static double erfasse_double(const string text, double min, double max);

    static bool erfasse_bool();

    static bool erfasse_antwort(const string ausgabetext, const string eingabeformat);
    static void erfasse_zeichenkette(const char *ausgabetext, char *eingabe, streamsize laenge);
    static void erfasse_zeichenkette(char *eingabe, streamsize anzahl);
};
#endif	/* EINGABEN_H */