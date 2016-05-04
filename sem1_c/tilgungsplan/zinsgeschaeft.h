double berechne_tilgungsrate (double kredit, double tilgungssatz);
double berechne_zinsen (double kredit, double zinssatz);
double berechne_annuitaet_wiki (double kredit, double zinssatz, int laufzeit);
double berechne_annuitaet (double tilgungsrate, double zinsen);
int berechne_laufzeit_annuitaetendarlehen (double tilgungssatz, double zinssatz);
void schreibe_tilgungsplan_fuer_ein_annuitaetendarlehen (double kredit, double zinssatz, double tilgungsrate);
