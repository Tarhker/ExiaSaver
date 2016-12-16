#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void initialiserProgramme(){

    FILE* fichierAffichage = NULL;
    FILE* fichierHistorique = NULL;
    char imageChoisie[12];
    int choixProgramme = 0;
    int xAvion = 0;
    int yAvion = 0;
    srand(time(NULL));
    choixProgramme = rand_a_b(1, 3);

    switch(choixProgramme){

        case 1 :

            initialiserImage(fichierAffichage);

            initialiserHistoriqueStatique(fichierHistorique, choixProgramme, imageChoisie);
            break;

        case 2 :

            xAvion = rand_a_b(1,71);
            yAvion = rand_a_b(1, 15);

            initialiserAvion(fichierAffichage, xAvion, yAvion);
            initialiserHistoriqueInteractif(fichierHistorique, choixProgramme, xAvion, yAvion);
            break;
    }
}

void initialiserStats(){
    statistiques();
}
