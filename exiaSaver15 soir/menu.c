#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void initialiserProgramme(){

    FILE* fichierAffichage = NULL;
    FILE* fichierHistorique = NULL;
    char imageChoisie[12];
    int choixProgramme;
    int xAvion = 0;
    int yAvion = 0;
    srand(time(NULL));
    choixProgramme = rand_a_b(1, 3);
    choixProgramme = 1;

    switch(choixProgramme){

        case 1 :

            initialiserImage(fichierAffichage);

           /* if(initialiserImage == 1){
                char imageChoisie[12] = "image1.pbm";
            }
            else if(initialiserImage == 2){
                char imageChoisie[12] = "image2.pbm";
            }
            else if(initialiserImage == 3){
                char imageChoisie[12] = "image3.pbm";
            }
            else if(initialiserImage == 4){
                char imageChoisie[12] = "image4.pbm";
            }*/

            initialiserHistoriqueStatique(fichierHistorique, choixProgramme, imageChoisie);
            break;

        case 2 :
            initialiserDynamique(fichierAffichage);
            break;

        case 3 :
            xAvion = rand_a_b(1,71);
            yAvion = rand_a_b(1, 15);

            initialiserAvion(xAvion, yAvion, fichierAffichage);
            initialiserHistoriqueInteractif(fichierHistorique, choixProgramme, xAvion, yAvion);
            break;
    }
}
