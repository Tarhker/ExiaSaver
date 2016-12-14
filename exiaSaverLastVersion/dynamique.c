#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "interactif.h"

FILE* fichierPbm = NULL;

void choixFormatAleatoire(){
    int indiceChoix;
    indiceChoix = rand()%3;
}


void afficherHeure()
{

    //fichierPbm = fopen("Pbm/5x3/", "r");
    struct tm instant;
    int heure1;                                                            // Variables
    int heure2;
    int minute1;
    int minute2;
    int seconde1;
    int seconde2;

    char mapDynamique [NB_COLONNES][NB_LIGNES];             // création du tableau pour placer l'affichage

    heure1 = instant.tm_hour/10;                              // place chaque nombres dans une variable
    heure2 = instant.tm_hour%10;
    minute1 = instant.tm_min/10;
    minute2 = instant.tm_min%10;
    seconde1 = instant.tm_sec/10;
    seconde2 = instant.tm_sec%10;

    choixImage(heure1);                                     // choix de l'image pour les chiffres
    choixImage(heure2);
    choixImage(minute1);
    choixImage(minute2);
    choixImage(seconde1);
    choixImage(seconde2);


}


void actualisationHeure(int n){
    int i;
    printf("\n Cet ecran sera actualise dans quelques secondes");
    for (i; i<n; i++){
        printf(".");
        sleep (1000);
    }
    afficherHeure();
}

void lireFichierPbmDynamique(){

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
                printf("%c", 88);
            }
        }
    }
}

void choixImage (int uniteTemps){

    switch (uniteTemps)                                          // lire l image correspondante
    {
        case 0:
            fichierPbm = fopen("/Pbm/5x3/0.pbm", "r");
            break;
        case 1:
            fichierPbm = fopen("/Pbm/5x3/1.pbm", "r");
            break;
        case 2:
            fichierPbm = fopen("/Pbm/5x3/2.pbm", "r");
            break;
        case 3:
            fichierPbm = fopen("/Pbm/5x3/3.pbm", "r");
            break;
        case 4:
            fichierPbm = fopen("/Pbm/5x3/4.pbm", "r");
            break;
        case 5:
            fichierPbm = fopen("/Pbm/5x3/5.pbm", "r");
            break;
        case 6:
            fichierPbm = fopen("/Pbm/5x3/6.pbm", "r");
            break;
        case 7:
            fichierPbm = fopen("/Pbm/5x3/7.pbm", "r");
            break;
        case 8:
            fichierPbm = fopen("/Pbm/5x3/8.pbm", "r");
            break;
        case 9:
            fichierPbm = fopen("/Pbm/5x3/9.pbm", "r");
            break;
    }
    if (fichierPbm != NULL){
        lireFichierPbmDynamique();
        fclose(fichierPbm);
    }
    else {
        printf ("Impossible d'ouvrir le fichier");
    }
}

