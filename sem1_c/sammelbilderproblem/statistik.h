int *liefere_min_int_array(int array[], int laenge);
double *liefere_min_double_array(double array[], int laenge);
int *liefere_max_int_array(int array[], int laenge);
double *liefere_max_double_array(double array[], int laenge);
int indizes_kleiner_als_double_array(const double array[], int laenge, int indizes_array[], double max_wert);
int summiere_int_array(const int array[], int laenge);
double durchschnitt_int_array(const int array[], int laenge);
double durchschnitt_double_array(const double array[], int laenge);

double median_int_array(const int array[], int laenge);
double median_double_array(const double array[], int laenge);
double stichprobenvarianz_int_array(const int array[], int laenge);
double stichprobenvarianz_double_array(const double array[], int laenge);
double standardabweichung_int_array(const int array[], int laenge);
double standardabweichung_double_array(const double array[], int laenge);

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
