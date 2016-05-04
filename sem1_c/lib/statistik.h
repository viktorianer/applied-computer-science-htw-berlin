char *liefere_min_char_array(char array[], int laenge);
int *liefere_min_int_array(int array[], int laenge);
double *liefere_min_double_array(double array[], int laenge);
char *liefere_max_char_array(char array[], int laenge);
int *liefere_max_int_array(int array[], int laenge);
double *liefere_max_double_array(double array[], int laenge);
int summiere_int_array(const int array[], int laenge);
double durchschnitt_int_array(const int array[], int laenge);
double durchschnitt_double_array(const double array[], int laenge);

int indizes_kleiner_als_double_array(const double array[], int laenge, int indizes_array[], double max_wert);
_Bool ist_zahl_im_char_array(const char array[], int laenge, char gesuchte_zahl);
_Bool sind_alle_zahlen_gerade_char_array(const char array[], int laenge);
_Bool sind_alle_zahlen_ungerade_char_array(const char array[], int laenge);

double median_int_array(const int array[], int laenge);
double median_double_array(const double array[], int laenge);
double stichprobenvarianz_int_array(const int array[], int laenge);
double stichprobenvarianz_double_array(const double array[], int laenge);
double standardabweichung_int_array(const int array[], int laenge);
double standardabweichung_double_array(const double array[], int laenge);
void haeufigkeitsverteilung_char_array(const char *array, int laenge, int *haeufigkeitsverteilung);
void haeufigkeitsverteilung_2dim_char_array(int zeilen, int spalten, char **array, int *haeufigkeitsverteilung);
void haeufigkeitsverteilung_minima_char_array(char *array, int laenge, int *minima);
void haeufigkeitsverteilung_minima_2dim_char_array(int zeilen, int spalten, char **array, int *minima);
void haeufigkeitsverteilung_maxima_char_array(char *array, int laenge, int *maxima);
void haeufigkeitsverteilung_maxima_2dim_char_array(int zeilen, int spalten, char **array, int *maxima);

void liefere_int_array_statistik(const int array[], int laenge, int *min, int *max, int *summe, double *durchschnitt);
void liefere_double_array_statistik(const double array[], int laenge,
		double *min, double *max, double *summe, double *durchschnitt);
void liefere_int_array_statistik_2(const int array[], int laenge,
		unsigned int *min_abstand, unsigned int *min_abstand_index,
		unsigned int *max_abstand, unsigned int *max_abstand_index);
void liefere_double_array_statistik_2(const double array[], int laenge,
		double *min_abstand, unsigned int *min_abstand_index,
		double *max_abstand, unsigned int *max_abstand_index);

void schreibe_int_array_statistik(int array[], int laenge);
void schreibe_double_array_statistik(double array[], int laenge);
