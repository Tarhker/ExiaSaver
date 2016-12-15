#include <stdio.h>
#include <stdlib.h>
#include "interactif.h"
#include "statique.h"

int initialiserImage(FILE* fichierImage){
    int choixImageAleatoire;
    int imageChoisie = 0;
    srand(time(NULL));
    choixImageAleatoire = rand_a_b(1, 4);
    choixImageAleatoire = 2;

    switch(choixImageAleatoire){
        case 1 :

            imageChoisie = 1;
            fichierImage = fopen("Pbm/Statique/image1.pbm", "r");
            break;

        case 2 :

            imageChoisie = 2;
            fichierImage = fopen("Pbm/Statique/image2.pbm", "r");
            break;

        case 3 :

            imageChoisie = 3;
            fichierImage = fopen("Pbm/Statique/image3.pbm", "r");
            break;

        case 4 :

            imageChoisie = 4;
            fichierImage = fopen("Pbm/Statique/image4.pbm", "r");
            break;
    }
    if(fichierImage != NULL){
        lireFichierImage(fichierImage);
        fclose(fichierImage);
    }
    else {
        printf("Impossible d'afficher l'image .\n");
    }
    return imageChoisie;
}

void lireFichierImage(FILE* fichierImage){

    char mapImage[NB_COLONNES][NB_LIGNES];
    int i = 0;
    int j = -1;
    int hauteurImage = 5;
    int largeurImage = 5;

    /*if(initialiserImage(fichierImage) == 1){
        hauteurImage = 9;
        largeurImage = 9;
    }
    else if(initialiserImage(fichierImage) == 2){
        hauteurImage = 5;
        largeurImage = 5;
    }
    else if(initialiserImage(fichierImage) == 3){
        hauteurImage = 7;
        largeurImage = 7;
    }
    else if(initialiserImage(fichierImage) == 4){
        hauteurImage = 23;
        largeurImage = 22;
    }*/

    char bufferImage[hauteurImage][largeurImage]; // Tableau de l'image
    char caractereLu; // Caractere lu du fichier pbm ouvert

    while((caractereLu = fgetc(fichierImage)) != EOF){
        if(caractereLu == 'P'){
            do{
                caractereLu = fgetc(fichierImage);
            } while(caractereLu != '\n');
        }
        else if(caractereLu == '#'){
            do{
                caractereLu = fgetc(fichierImage);
            } while(caractereLu != '\n');
        }
        else if (caractereLu == '\n'){
            j++;
            i = 0;
            //printf("%c", '\n');
        }
        else if (caractereLu == '0'){
            bufferImage[j][i] = ' ';
            i++;
            //printf("%c", ' ');
        }
        else if (caractereLu == '1'){
            bufferImage[j][i] = '#';
            i++;
            //printf("%c", '#');
        }
    }

    int g = 0;
    int h = 0;
    int tempX, tempY;
    tempY = (NB_LIGNES - hauteurImage) / 2;         //récupère position
    tempX = (NB_COLONNES - largeurImage) / 2;

    for (int i = 0; i < tempY; i++)     //saute les premières lignes pour centrer
        printf("\n");


    for(int g = 0; g < largeurImage ; g++){

        for (int h = 0; h < tempX; h++) // affiche les espaces pour centrer
            printf(" ");

        for(; h < hauteurImage; h++){           //affiche l'image centrée
            printf("%c", bufferImage[h][g]);
        }
        h = 0;
        printf("\n");
    }

    for (i = hauteurImage + tempY; i < NB_LIGNES; i++)
            printf("\n");               //permet de revenir a la ligne

}
