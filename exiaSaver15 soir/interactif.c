#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "interactif.h"

int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void initialiserAvion(FILE *fichierPbm, int x, int y){

    int nombreAleatoireAvion = 0;
    srand(time(NULL));
    nombreAleatoireAvion = rand_a_b(1, 5);
    switch(nombreAleatoireAvion){
        case 1 :
            fichierPbm = fopen("Pbm/Interactif/avionHaut.pbm", "r");
        break;

        case 2 :
            fichierPbm = fopen("Pbm/Interactif/avionDroite.pbm", "r");
        break;

        case 3 :
            fichierPbm = fopen("Pbm/Interactif/avionBas.pbm", "r");
        break;

        case 4 :
            fichierPbm = fopen("Pbm/Interactif/avionGauche.pbm", "r");
        break;
    }
    if(fichierPbm != NULL){
        afficherAvion(x, y, fichierPbm);
        deplacerAvion(x, y, fichierPbm);
        fclose(fichierPbm);
    }
    else {
        printf("Impossible d'afficher l'avion .\n");
    }
}

void afficherAvion(int x, int y, FILE *fichierPbm){

    ////////////// --------------------- Déclaration des variables

    char mapAvion[NB_COLONNES][NB_LIGNES];
    int i = 0; // COLONNE OU ON EST DANS LE TABLEAU 0-80 / J = Y
    int j = 0; // LIGNE OU ON EST DANS LE TABLEAU 0-23 / I = X
    int hauteurPbm = 6; // Hauteur fichier Pbm
    int largeurPbm = 6; // Largeur fichier Pbm

    ////////////// --------------------- Lecture du fichier PBM

    char bufferPbm[hauteurPbm][largeurPbm]; // Tableau de l'avion
    char caractereLu; // Caractere lu du fichier pbm ouvert

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
        } else if (caractereLu == '0'){
            bufferPbm[j][i] = ' ';
            i++;
        } else if (caractereLu == '1'){
            bufferPbm[j][i] = '#';
            i++;
        }
    }

    ////////////// --------------------- Affichage de la carte avec l'avion

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

            }
            printf("%c", mapAvion[i][j]);
        }
        printf("\n");
    }
}

void deplacerAvion(int x, int y, FILE *fichierPbm){
    char caractereEcrit;

    while(caractereEcrit != 'm'){
        caractereEcrit = getchar();

        if(caractereEcrit == 'z'){
            system("clear");
            fichierPbm = fopen("Pbm/Interactif/avionHaut.pbm", "r");
            y--;
            if(y < -6){
                y = NB_LIGNES-2;
            }
        } else if(caractereEcrit == 'q'){
            system("clear");
            fichierPbm = fopen("Pbm/Interactif/avionGauche.pbm", "r");
            x--;
            if(x < -6){
                x = NB_COLONNES-2;
            }
        } else if(caractereEcrit == 's'){
            system("clear");
            fichierPbm = fopen("Pbm/Interactif/avionBas.pbm", "r");
            y++;
            if(y >= NB_LIGNES-1){
                y = -6;
            }
        } else if(caractereEcrit == 'd'){
            system("clear");
            fichierPbm = fopen("Pbm/Interactif/avionDroite.pbm", "r");
            x++;
            if(x >= NB_COLONNES-1){
                x = -6;
            }
        } else {
            system("clear");
        }

        if(fichierPbm != NULL){
            afficherAvion(x, y, fichierPbm);
        }
        else {
            printf("Impossible d'afficher l'avion .\n");
        }
    }
}
