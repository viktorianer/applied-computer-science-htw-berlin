#ifndef AUSGABEN_H
#define	AUSGABEN_H

#include <sys/ioctl.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>

#include "arrays.h"

using namespace std;

void schreibe(char zeichen);
void schreibe(int anzahl, char zeichen);
void schreibe(int anzahl, char zeichen, FILE *datei);

void schreibe(const char *text);
void schreibe(const char *text, int feldbreite);
void schreibe(const char *text, int feldbreite, FILE *datei);
void schreibe(const char *text, int feldbreite, bool zentriert);
void schreibe(const char *text, int feldbreite, bool zentriert, FILE *datei);

void schreibe(int zahl);
void schreibe(int zahl, int feldbreite);
void schreibe(int zahl, int feldbreite, FILE *datei);

void schreibe(const int array[], int laenge);
void schreibe(const int array[], int laenge, int feldbreite);
void schreibe(const int array[], int laenge, int feldbreite, const char *trenner);
void schreibe(const int array[], int laenge, int feldbreite, const char *trenner, bool am_ende);
void schreibe(const int array[], int laenge, int feldbreite, const char *trenner, bool am_ende, FILE *datei);

int liefere_max_anzahl_spalten(int breite_einer_zahl);

int liefere_feldbreite(long double *gleitzahlen, int anzahl);

#endif	/* AUSGABEN_H */

