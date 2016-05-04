void liefere_lottoziehungen_zufaellig(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																			char **lottoziehungen, char min, char max);
void liefere_lottoziehung_zufaellig(char *lottoziehung, int anzahl_lottozahlen, char min, char max);
_Bool ist_lottoziehung_gueltig(char *lottoziehungen, char *lottoziehung, int anzahl_lottozahlen);
int vergleiche_lottoziehung(char *lottoziehung_1, char *lottoziehung_2, int anzahl_lottozahlen);
void wieviele_jahre_und_monate(int anzahl_lottoziehungen);
void statistik_haeufigkeitsverteilung(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																			char **lottoziehungen, int *haeufigkeitsverteilung, char max);
void statistik_minima(int anzahl_lottoziehungen, int anzahl_lottozahlen,
											char **lottoziehungen, int *lottozahlen_minima, char max);
void statistik_maxima(int anzahl_lottoziehungen, int anzahl_lottozahlen,
											char **lottoziehungen, int *lottozahlen_maxima, char max);
char laenge_lottoziehung(char *lottoziehung, int anzahl_lottozahlen);
void statistik_laengen_lottoziehungen(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																			char **lottoziehungen, int *lottozahlen_laengen, char max);
void statistik_laenge_ist_gezogene_zahl(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																				char **lottoziehungen, int *lottozahl_gleich_laengen, char max);
void statistik_lottoziehungen_sind_gerade(int anzahl_lottoziehungen, int anzahl_lottozahlen, char **lottoziehungen);
void statistik_lottoziehungen_sind_ungerade(int anzahl_lottoziehungen, int anzahl_lottozahlen, char **lottoziehungen);
void statistik_lottoziehungen_zahlenpaare(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																					char **lottoziehungen, int *zahlenpaare);
int zahlenpaar(char *lottoziehungen, int anzahl_lottozahlen);
void lottotipp_durch_benutzer(char *lottotipp_eingabe, int anzahl_lottozahlen, char min, char max);
void statistik_lottotipp_eingabe(int anzahl_lottoziehungen, int anzahl_lottozahlen,
																	char **lottoziehungen, char *lottotipp_eingabe);
void lottotipp_durch_ai(int anzahl_lottoziehungen, int anzahl_lottozahlen,
												char **lottoziehungen, char *lottotipp_ai, char min, char max);
