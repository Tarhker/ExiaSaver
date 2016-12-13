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
    nombreAleatoireAvion = 3; // TODO A enlver
    switch(nombreAleatoireAvion){
        case 1 :
            fichierPbm = fopen("Pbm/avionHaut.pbm", "r");
        break;

        case 2 :
            fichierPbm = fopen("Pbm/avionDroite.pbm", "r");
        break;

        case 3 :
            fichierPbm = fopen("Pbm/avionBas.pbm", "r");
        break;

        case 4 :
            fichierPbm = fopen("Pbm/avionGauche.pbm", "r");
        break;
    }
    if(fichierPbm != NULL){
        afficherAvion();
        //printf("\nAvion droite affiché.");
        fclose(fichierPbm);
    }
    else {
        printf("Impossible d'afficher l'avion !!!\n");
    }
}

void deplacerAvionBas(){
    char caractereEcrit;
    scanf("%c", caractereEcrit);

    if(caractereEcrit == 'S'){

    }
}

/*
void afficherTableau(int *tableau[][999]) {
    int x = sizeof(tableau);
    int y = sizeof(tableau[0]);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c", tableau[j][i]);
        }
    }
    printf("\n");
}*/


void afficherAvion(){

    char mapAvion[NB_COLONNES][NB_LIGNES];
    //int x = rand_a_b(1, 71); //ALEATOIRE COLONNE
    //int y = rand_a_b(1, 15); //ALEATOIRE LIGNE
    int x = 5;
    int y = 5;
    printf("Placement à partir de la gauche = %d", x);
    printf("\nPlacement à partir du haut = %d\n", y);
    int i = 0; // COLONNE OU ON EST DANS LE TABLEAU 0-80 / J = Y
    int j = 0; // LIGNE OU ON EST DANS LE TABLEAU 0-23 / I = X
    int hauteurPbm = 6;
    int largeurPbm = 5;

    ////////////// --------------------- Lecture du fichier PBM

    char bufferPbm[hauteurPbm][largeurPbm];
    char caractereLu;

    while((caractereLu = fgetc(fichierPbm)) != EOF){
        if(caractereLu == 'P'){
            do{
                caractereLu = fgetc(fichierPbm);
            } while(caractereLu != '\n');
        } else if(caractereLu == '#'){
            do{
                caractereLu = fgetc(fichierPbm);
            } while(caractereLu != '\n');
        } else if (caractereLu == '\n'){
            j++;
            i = 0;
            printf("\n");
        } else if (caractereLu == '0'){
            //printf("%d;%d = %d\n", j, i, 0);
            printf("%d", 0);
            bufferPbm[j][i] = '0';
            i++;
        } else if (caractereLu == '1'){
            //printf("%d;%d = %d\n", j, i, 1);
            printf("%d", 1);
            bufferPbm[j][i] = '1';
            i++;
        }
    }

    ////////////// --------------------- Affichage du machin

    i = j = 0;

    for(j ; j < NB_LIGNES; j++){
        for(i = 0 ; i < NB_COLONNES ; i++){
            if(j <= y){
                mapAvion[i][j] = ' ';
            }
            else if(j > y+hauteurPbm){
                mapAvion[i][j] = ' ';
            }
            else if(i <= x){
                mapAvion[i][j] = ' ';
            }
            else if(i > x+largeurPbm){
                mapAvion[i][j] = ' ';
            }
            else {
                int g = i-1-x;
                int h = j-y;
                mapAvion[i][j] = bufferPbm[h][g];
                //mapAvion[i][j] = '8';
            }
            printf("%c", mapAvion[i][j]);
        }
        printf("\n");
    }

   /* for(i = 0 ; i < y ; i++){
        for(j ; j < x+6 ; j++){
            mapAvion[i][j] = 'z';
            printf("%c", mapAvion[i][j]);
        }
    }

    char caractereLu;
    if(fichierPbm){
        while((caractereLu = fgetc(fichierPbm)) != EOF){
            if(caractereLu == 'P'){
                do{
                    caractereLu = fgetc(fichierPbm);
                } while(caractereLu != '\n');
            } else if(caractereLu == '#'){
                do{
                    caractereLu = fgetc(fichierPbm);
                } while(caractereLu != '\n');
            } else if (caractereLu == '\n'){
                mapAvion[x][y] = '\n';
                printf("%c", mapAvion[x][y]);
            } else if (caractereLu == '0'){
                mapAvion[x][y] = ' ';
                printf("%c", mapAvion[x][y]);
            } else if (caractereLu == '1'){
                mapAvion[x][y] = '#';
                printf("%c", mapAvion[x][y]);
            }
        }
    }
    for(j ; j < NB_LIGNES-6 ; j++){
        for(i = 0 ; i < NB_COLONNES ; i++){
            mapAvion[i][j] = 'a';
            printf("%c", mapAvion[i][j]);
        }
    }*/
}
