#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "historique.h"

void initialiserHistorique(FILE *fichierHistorique, int type){

    int jours = 0;
    int mois = 0;
    int annees = 0;
    int heures = 0;
    int minutes = 0;
    int sec = 0;

    time_t secondes;
    time(&secondes);
    date = *localtime(&secondes);

    jours = date.tm_mday+1;
    mois = date.tm_mon+1;
    annees = date.tm_year+1900;
    heures = date.tm_hour;
    minutes = date.tm_min;
    sec = date.tm_sec;

    fichierHistorique = fopen("historique.txt", "a+");

    fprintf(fichierHistorique, "%d/%d/%d %d:%d:%d;%d", jours, mois, annees, heures, minutes, sec, type);
}
