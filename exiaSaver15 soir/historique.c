#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "historique.h"

void initialiserHistoriqueStatique(FILE *fichierHistorique, int type, char imageChoisie[]){

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

    fseek(fichierHistorique, 0, SEEK_END);

    fprintf(fichierHistorique, "\n%d/%d/%d %d:%d:%d;%d;%s", jours, mois, annees, heures, minutes, sec, type, imageChoisie);

    fclose(fichierHistorique);
}

void initialiserHistoriqueInteractif(FILE *fichierHistorique, int type, int x, int y){

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

    fseek(fichierHistorique, 0, SEEK_END);

    fprintf(fichierHistorique, "\n%d/%d/%d %d:%d:%d;%d;%dx%d", jours, mois, annees, heures, minutes, sec, type, x, y);

    fclose(fichierHistorique);
}
