/* 
 * File:   menue.h
 * Author: viktorianer
 *
 * Created on 9. Mai 2011, 14:35
 */

#ifndef MENUE_H
#define	MENUE_H

#include <iostream>

#include "eingaben.h"
#include "ausgaben.h"

using namespace std;

int waehle_aus_menue(int menuelaenge, const string *menue);
void schreibe_menue(int menuelaenge, const string *menue);

#endif	/* MENUE_H */

