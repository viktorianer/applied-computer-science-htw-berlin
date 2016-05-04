void kopiere_int_array(const int original[], int kopie[], int laenge);

void initialisiere_int_array(int array[], int laenge, int initialwert);
void initialisiere_double_array(double array[], int laenge, double initialwert);
void initialisiere_int_array_zufaellig(int array[], int laenge, int min, int max);
void initialisiere_double_array_zufaellig(double array[], int laenge, double min, double max);
void initialisiere_2dim_int_array(int zeilen, int spalten, int array[zeilen][spalten], int initialwert);
void initialisiere_2dim_int_array_zufaellig(int zeilen, int spalten, int array[zeilen][spalten], int min, int max);

void schreibe_int_array(const int array[], int laenge, int breite, char *trenner, _Bool am_ende);
void schreibe_double_array(const double array[], int laenge, int breite, char *trenner, _Bool am_ende);
void schreibe_2dim_int_array(int zeilen, int spalten, int array[zeilen][spalten], int breite, char *trenner, _Bool am_ende);

void int_bubble_sort_1(int array[], int laenge);
void int_bubble_sort_2(int array[], int laenge);
void int_selection_sort_1(int array[], int laenge);
void int_selection_sort_2(int array[], int laenge);
void vertausche(int *x, int *y);
int vergleiche(const void *i, const void *j);

double messe_int_bubble_sort_1(int array[], int laenge);
double messe_int_bubble_sort_2(int array[], int laenge);

void schreibe_zeichenkette(char zeichenkette[]);
int waehle_aus_menue(int menuelaenge, int textlaenge, char menue[menuelaenge][textlaenge]);
void schreibe_menue(int menuelaenge, int textlaenge, char menue[menuelaenge][textlaenge]);

/** Berechnung der Laenge eines Arrays
	int laenge = sizeof(array) / sizeof(array[0]);
*/
