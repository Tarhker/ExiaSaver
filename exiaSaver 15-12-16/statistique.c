#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //Permet de créer des chaines de caracteres
//#include <fstream.h>  //Permet la manipulation des fichiers
#include "statique.h"

void triParType (){

    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("historique.txt", "r");

    FILE* fichierStatistique = NULL;                            //Ouvre statique en écriture
    fichierStatistique = fopen ("fichierStatistique.txt", "w");

    int nLignes = 0;                        //Variable
    char buffer;
    char* verifType;
    int type1 = 0;
    int type2 = 0;
    int type3 = 0;


    if (fichierHistorique != NULL){                     //Trouve le nombres de lignes
            int c;
        while((c=fgetc(fichierHistorique)) != EOF)
        {
            if(c=='\n'){
            nLignes++;
            }
        }
    }
    else{
        printf("Erreur:le fichier est vide");           //Affiche une erreur si le fichier est vide
        exit(0);
    }
    printf("%d", nLignes);


    while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
            verifType = strtok (buffer, ";");            // va jusqu'au premier point virgule et regarde le type (1,2 ou 3)
            if (verifType == "1"){
                fprintf(fichierStatistique,"%d\n",buffer);  // ecrit dans le fichier statistique
                type1++;
            }

    }
    while ((buffer = getc (fichierHistorique)) != '\n'){  //pareil qu'en haut
            verifType = strtok (buffer, ";");
            if (verifType == "2"){
                fprintf(fichierStatistique,"%d\n",buffer);
                type2++;
            }

    }
    while ((buffer = getc (fichierHistorique)) != '\n'){ // pareil qu'n haut
            verifType = strtok (buffer, ";");
            if (verifType == "3"){
                fprintf(fichierStatistique,"%d\n",buffer);
                type3++;
            }

    }

    fprintf (fichierStatistique,"\nIl y a eu %d types statiques, %d types dynamiques et %d types interractifs", type1, type2, type3); //compte les types exécutés
    fclose(fichierHistorique);
    fclose (fichierStatistique);
}





/*void triChronologique(){

    char buffer;
    char* verifType;
    int type1 = 0;
    int type2 = 0;
    int type3 = 0;


    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("historique.txt", "r");

    FILE* fichierStatistique = NULL;                            //Ouvre statique en écriture
    fichierStatistique = fopen ("fichierStatistique.txt", "w");

    while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
            fprintf(fichierStatistique,"%d\n",buffer);  // ecrit dans le fichier statistique
            verifType = strtok (buffer, ";");

            switch (verifType){

                case 1:
                    type1++;
                    break;
                case 2:
                    type2++;
                    break;
                case 3:
                    type3++;
                    break;

            }
    }

    fprintf (fichierStatistique,"\nIl y a eu %d types statiques, %d types dynamiques et %d types interractifs", type1, type2, type3);

    fclose(fichierHistorique);
    fclose (fichierStatistique);
}
*/

