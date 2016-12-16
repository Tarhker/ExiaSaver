#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "interactif.h"
#include "historique.h"

void choixFormatAleatoire(){
    int indiceChoix;
    indiceChoix = rand()%3;
}


void initialiserDynamique(FILE* fichierPbm){

    int heure1;                                                            // Variables
    int heure2;
    int minute1;
    int minute2;
    int seconde1;
    int seconde2;

    char mapDynamique [NB_COLONNES][NB_LIGNES-1];             // création du tableau pour placer l'affichage

    time_t secondes;
    time(&secondes);
    date = *localtime(&secondes);

    heure1 = date.tm_hour/10;                              // place chaque nombres dans une variable
    heure2 = date.tm_hour%10;
    minute1 = date.tm_min/10;
    minute2 = date.tm_min%10;
    seconde1 = date.tm_sec/10;
    seconde2 = date.tm_sec%10;

    printf("%d", heure1);

    switch (heure1){
        case 0:
            fichierPbm = fopen("Pbm/Dynamique/0.pbm", "r");
            break;
        case 1:
            fichierPbm = fopen("Pbm/Dynamique/1.pbm", "r");
            break;
        case 2:
            fichierPbm = fopen("Pbm/Dynamique/2.pbm", "r");
            break;
        case 3:
            fichierPbm = fopen("Pbm/Dynamique/3.pbm", "r");
            break;
        case 4:
            fichierPbm = fopen("Pbm/Dynamique/4.pbm", "r");
            break;
        case 5:
            fichierPbm = fopen("Pbm/Dynamique/5.pbm", "r");
            break;
        case 6:
            fichierPbm = fopen("Pbm/Dynamique/6.pbm", "r");
            break;
        case 7:
            fichierPbm = fopen("Pbm/Dynamique/7.pbm", "r");
            break;
        case 8:
            fichierPbm = fopen("Pbm/Dynamique/8.pbm", "r");
            break;
        case 9:
            fichierPbm = fopen("Pbm/Dynamique/9.pbm", "r");
            break;
    }
    if (fichierPbm != NULL){
        lireFichierPbmDynamique(fichierPbm);
        fclose(fichierPbm);
    }
    else {
        printf ("Impossible d'ouvrir le fichier");
    }
}


void actualisationHeure(int n){
    int i;
    printf("\n Cet ecran sera actualise dans quelques secondes");
    for (i; i<n; i++){
        printf(".");
        sleep (1000);
    }
    //initialiserDynamique();
}

void lireFichierPbmDynamique(FILE* fichierPbm){

    int i = 0; // Lignes = 5
    int j = 0; // Colonnes = 3
    char chiffreLu[5][3];

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
                j++;
                i = 0;
            } else if (caractereLu == '0'){
                chiffreLu[i][j] = '0';
                i++;
            } else if (caractereLu == '1'){
                chiffreLu[i][j] = '1';
                i++;
            }
        }
    }

    j = 0;
    i = 0;

    for(i = 0; i < 3; i++){
        for(j = 0 ; j < 5 ; j++){
            printf("%c", chiffreLu[j][i]);
            }
        printf("\n");
        }
}
