#include <stdio.h>
#include <stdlib.h>
#include "interactif.h"
#include "statique.h"

FILE* fichierImage = NULL;

void initialiserImage(){
    int choixImageAleatoire;
    srand(time(NULL));
    choixImageAleatoire = rand_a_b(1, 4);
    switch(choixImageAleatoire){
        case 1 :
            fichierImage = fopen("Pbm/Statique/ex1.pbm", "r");
            break;
        case 2 :
            fichierImage = fopen("Pbm/Statique/ex2.pbm", "r");
            break;
        case 3 :
            fichierImage = fopen("Pbm/Statique/ex3.pbm", "r");
            break;
    }
    if(fichierImage != NULL){
        lireFichierImage();
        fclose(fichierImage);
    }
    else {
        printf("Impossible d'afficher l'image .\n");
    }
}

void lireFichierImage(){
    char caractereLu;

    if(fichierImage){
        while((caractereLu = fgetc(fichierImage)) != EOF){
            if(caractereLu == 'P'){
                do{
                    caractereLu = fgetc(fichierImage);
                } while(caractereLu != '\n');
            } else if(caractereLu == '#'){
                do{
                    caractereLu = fgetc(fichierImage);
                } while(caractereLu != '\n');
            } else if (caractereLu == '\n'){
                printf("%c", caractereLu);
            } else if (caractereLu == '0'){
                printf("%c", ' ');
            } else if (caractereLu == '1'){
                printf("%c", '#');

            }
        }
    }
}
