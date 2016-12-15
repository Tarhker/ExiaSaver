#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void initialiserProgramme(){
    FILE* fichierAffichage = NULL;
    FILE* fichierHistorique = NULL;
    int choixProgramme;
    srand(time(NULL));
    choixProgramme = rand_a_b(1, 3);
    choixProgramme = 2;

    switch(choixProgramme){
        case 1 :
            initialiserImage();
            break;

        case 2 :
            //initialiserAvion(rand_a_b(1, 71), rand_a_b(1,15), fichierAffichage);
            initialiserHistorique(fichierHistorique, choixProgramme);
            break;
    }
}
