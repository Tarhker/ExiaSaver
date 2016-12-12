#include <stdio.h>
#include <stdlib.h>
#include "interactif.h"

FILE* fichierPbm = NULL;
char ligneFichier[TAILLE_MAX] = "";

int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void placerAvionAleatoirement(){
    int nombreAleatoireAvion = 0;
    srand(time(NULL));
    nombreAleatoireAvion = rand_a_b(1, 5);
    switch(nombreAleatoireAvion){
        case 1 :
            fichierPbm = fopen("Pbm/avionHaut.pbm", "r");
            if(fichierPbm != NULL){

                lireFichierPbm();
                printf("\nAvion haut affiché.");
                fclose(fichierPbm);
        }else {
            printf("Impossible d'afficher l'avion Haut.\n");
        }
        break;

        case 2 :
            fichierPbm = fopen("Pbm/avionDroite.pbm", "r");
            if(fichierPbm != NULL){

                lireFichierPbm();
                printf("\nAvion droite affiché.");
                fclose(fichierPbm);
        }else {
            printf("Impossible d'afficher l'avion Droite.\n");
        }
        break;

        case 3 :
            fichierPbm = fopen("Pbm/avionBas.pbm", "r");
            if(fichierPbm != NULL){

                lireFichierPbm();
                printf("\nAvion bas affiché.");
                fclose(fichierPbm);
        }else {
            printf("Impossible d'afficher l'avion Bas.\n");
        }
        break;

        case 4 :
            fichierPbm = fopen("Pbm/avionGauche.pbm", "r");
            if(fichierPbm != NULL){

                lireFichierPbm();
                printf("\nAvion gauche affiché.");
                fclose(fichierPbm);
        }else {
            printf("Impossible d'afficher l'avion Gauche.\n");
        }
        break;
    }
}

void afficherAvionMap(){
    char mapAvion[NB_COLONNES][NB_LIGNES];
}

void deplacerAvionBas(){
    char caractereEcrit;
    scanf("%c", caractereEcrit);

    if(caractereEcrit == 'S'){

    }
}

void lireFichierPbm(){
    int i = 0;
    char caractereLu;
    if(fichierPbm){
        while((caractereLu = fgetc(fichierPbm)) != EOF){
            if(caractereLu == 'P'){
                do{
                    caractereLu = fgetc(fichierPbm);
                } while(caractereLu != 10);
            } else if(caractereLu == '#'){
                do{
                    caractereLu = fgetc(fichierPbm);
                } while(caractereLu != '\n');
            } else if (caractereLu == '\n'){
                printf("\n");
            } else if (caractereLu == '0'){
                printf(" ");
            } else if (caractereLu == '1'){
                printf("%c", 35);
            }
        }
    }
}
